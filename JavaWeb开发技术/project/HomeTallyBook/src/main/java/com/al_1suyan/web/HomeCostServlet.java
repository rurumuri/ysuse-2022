package com.al_1suyan.web;

import com.al_1suyan.pojo.HomeCost;
import com.al_1suyan.service.HomeCostService;
import com.al_1suyan.service.impl.HomeCostServiceImpl;
import com.al_1suyan.service.impl.PageServiceImpl;
import com.al_1suyan.utils.PageDisplay;
import com.al_1suyan.utils.WebUtils;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.List;

/**
 * url:localhost:8080/manager/homeCostServlet
 * Servlet implementation class HomeCostServlet
 */
@WebServlet("/manager/homeCostServlet")
public class HomeCostServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
    private HomeCostService homeCostService;

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doPost(request, response);
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession(true);
        response.setContentType("text/html;charset=UTF-8");
        response.setCharacterEncoding("UTF-8");
        PrintWriter out = response.getWriter();

        int uid = 0;
        String uname = null;
        if (session.getAttribute("uid") != null) {
            uid = (int) session.getAttribute("uid");
            uname = (String) session.getAttribute("name");
        } else {
            //response.sendRedirect("login.html");
            out.print("<script>alert('您还没有登录，请登录...'); window.location='/login.html' </script>");
        }
        homeCostService = new HomeCostServiceImpl(uid);
        String action = request.getParameter("action");
        if ("add".equals(action)) {
            add(request, response, uid);
        } else if ("delete".equals(action)) {
            delete(request, response);
        } else if ("update".equals(action)) {
            update(request, response);
        } else if ("list".equals(action)) {
            list(request, response, uid);
        } else if ("getHomeCostById".equals(action)) {
            getHomeCostById(request, response);
        } else if ("query".equals(action)) {
            query(request, response);
        } else if ("remarks".equals(action)) {
            remarks(request, response);
        } else if ("remarks_up".equals(action)) {
            remarks_up(request, response);
        }
    }

    protected void remarks_up(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        int id = WebUtils.parseInt(request.getParameter("id"), 0);
        HomeCost homeCost = homeCostService.getHomeCostById(id);
        //封装
        homeCost.setRemarks(request.getParameter("remarks"));
        //执行删除操作，返回1,修改成功，反之失败
        if (homeCostService.update(homeCost) == 1) {
            response.sendRedirect(request.getContextPath() + "/manager/homeCostServlet?action=list&page=" + request.getParameter("page"));
        } else {
            request.setAttribute("msg", "修改失败，联系管理员");
            request.setAttribute("homeCost", homeCost);
            request.getRequestDispatcher("/cost_edit.jsp").forward(request, response);
        }
    }


    protected void add(HttpServletRequest request, HttpServletResponse response, int uid) throws ServletException, IOException {

        String name = request.getParameter("name");
        BigDecimal money = WebUtils.bigdecimal(request.getParameter("money"), new BigDecimal(0.00));

        HomeCost homeCost = new HomeCost(name, money);
        HttpSession session = request.getSession();

        if (homeCostService.add(homeCost, (int) session.getAttribute("uid")) == 1) {
            int page = (int) session.getAttribute("lastpage");
            //页面重定向
            response.sendRedirect(request.getContextPath() + "/manager/homeCostServlet?action=list&page=" + page);
        } else {
            //请求转发
            request.setAttribute("msg", "添加失败，联系管理员");
            request.setAttribute("homeCost", homeCost);
            request.getRequestDispatcher("/remarks.jsp").forward(request, response);
        }
    }


    protected void delete(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        int id = WebUtils.parseInt(request.getParameter("id"), 0);

        if (homeCostService.delete(id) == 1) {

            response.sendRedirect(request.getContextPath() + "/manager/homeCostServlet?action=list");
        } else {

            request.setAttribute("msg", "ɾ��ʧ�ܣ���ϵ����Ա");
            request.getRequestDispatcher("/manager/homeCostServlet?action=list").forward(request, response);
        }

    }


    protected void update(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        int id = WebUtils.parseInt(request.getParameter("id"), 0);
        String name = request.getParameter("name");
        BigDecimal money = WebUtils.bigdecimal(request.getParameter("money"), new BigDecimal(0.00));
        String date = request.getParameter("date");

        HomeCost homeCost = new HomeCost(id, name, money, date);

        if (homeCostService.update(homeCost) == 1) {
            response.sendRedirect(request.getContextPath() + "/manager/homeCostServlet?action=list");
        } else {
            request.setAttribute("msg", "�޸�ʧ�ܣ���ϵ����Ա");
            request.setAttribute("homeCost", homeCost);
            request.getRequestDispatcher("/cost_edit.jsp").forward(request, response);
        }
    }


    protected void list(HttpServletRequest request, HttpServletResponse response, int uid) throws ServletException, IOException {
        HttpSession session = request.getSession();
        List<HomeCost> homeCost_r = homeCostService.list(uid);
        //request.setAttribute("homeCost", homeCost_r);
        PageDisplay<HomeCost> homeCostPageDisplay = new PageDisplay<>(homeCost_r);
        PageServiceImpl<HomeCost> homeCostPageService = new PageServiceImpl<>(homeCostPageDisplay);
        String page = request.getParameter("page");
        if (page == null) page = "1";
        int page_int = Integer.parseInt(page);
        if (page_int < 1) page_int = 1;
        if (page_int > homeCostPageDisplay.getSize()) page_int = homeCostPageDisplay.getSize();
        session.setAttribute("homeCost", homeCostPageService.getUsers(page_int));
        session.setAttribute("pages", homeCostPageService.getList(page_int));
        session.setAttribute("page", page_int);
        session.setAttribute("lastpage", homeCostPageDisplay.getSize());
        session.setAttribute("SumHomeCost", homeCost_r.size());
        request.getRequestDispatcher("/manager.jsp").forward(request, response);

    }


    private void getHomeCostById(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        int id = WebUtils.parseInt(request.getParameter("id"), 0);
        HomeCost homeCost = homeCostService.getHomeCostById(id);
        request.setAttribute("homeCost", homeCost);
        request.getRequestDispatcher("/cost_edit.jsp").forward(request, response);
    }


    protected void query(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String keyword = request.getParameter("keyword");
        List<HomeCost> homeCost = homeCostService.query(keyword);
        request.setAttribute("homeCost", homeCost);
        request.getRequestDispatcher("/query.jsp").forward(request, response);

    }

    protected void remarks(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        int id = WebUtils.parseInt(request.getParameter("id"), 0);
        HomeCost homeCost = homeCostService.getHomeCostById(id);
        request.setAttribute("homeCost", homeCost);
        request.getRequestDispatcher("/remarks.jsp").forward(request, response);
    }


}
