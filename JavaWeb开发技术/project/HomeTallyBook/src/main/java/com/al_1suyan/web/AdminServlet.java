package com.al_1suyan.web;

//import com.mysql.cj.Session;

import com.al_1suyan.pojo.User;
import com.al_1suyan.service.impl.PageServiceImpl;
import com.al_1suyan.service.impl.UserServiceImpl;
import com.al_1suyan.utils.PageDisplay;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

@WebServlet("/manage/as")
public class AdminServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.setCharacterEncoding("utf-8");
        String action = req.getParameter("action");
        if (action.equals("add")) {
            add(req, resp);
        } else if (action.equals("update")) {
            update(req, resp);
        } else if (action.equals("list")) {
            list(req, resp);
        } else if (action.equals("delete")) {
            delete(req, resp);
        } else if (action.equals("getbyusername")) {
            getByUsername(req, resp);
        } else if (action.equals("query")) {
            query(req, resp);
        }
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        super.doPost(req, resp);
    }

    protected void query(HttpServletRequest request, HttpServletResponse response) {
        String keyword = request.getParameter("keyword");
        UserServiceImpl userService = new UserServiceImpl();
        HttpSession session = request.getSession();
        if (keyword == null) {
            keyword = (String) session.getAttribute("keyword");
        }
        session.setAttribute("keyword", keyword);
        PageDisplay<User> userPageDisplay = new PageDisplay<>(userService.query(keyword));
        PageServiceImpl<User> userPageService = new PageServiceImpl<User>(userPageDisplay);
        String page = request.getParameter("page");
        if (page == null) page = "1";
        int page_int = Integer.parseInt(page);
        if (page_int < 1) page_int = 1;
        if (page_int > userPageDisplay.getSize()) page_int = userPageDisplay.getSize();
        session.setAttribute("users", userPageService.getUsers(page_int));
        session.setAttribute("pages", userPageService.getList(page_int));
        session.setAttribute("pageDisplay", userPageDisplay);
        session.setAttribute("page", page_int);
        session.setAttribute("lastpage", userPageDisplay.getSize());
        session.setAttribute("UserSum", userService.query(keyword).size());
        try {
            response.sendRedirect("http://localhost:8080/user_query.jsp");
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    protected void getByUsername(HttpServletRequest request, HttpServletResponse response) {
        String username = request.getParameter("username");
        UserServiceImpl userService = new UserServiceImpl();
        User user = userService.getUserByUsername(username);
        request.setAttribute("user", user);
        try {
            request.getRequestDispatcher("/user_edit.jsp").forward(request, response);
        } catch (ServletException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    protected void update(HttpServletRequest request, HttpServletResponse response) {
        String username = request.getParameter("username");
        String password = request.getParameter("password");
        User user = new User(username, password);
        UserServiceImpl userService = new UserServiceImpl();

        if (userService.update(user) > 0) {
            try {
                response.sendRedirect(request.getContextPath() + "/manage/as?action=list&page=" + request.getParameter("page"));
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
            request.setAttribute("msg", "修改密码失败!");
            request.setAttribute("user", user);
            try {
                request.getRequestDispatcher("/user_edit.jsp").forward(request, response);
            } catch (ServletException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    //从edit页面过来进行添加
    protected void add(HttpServletRequest request, HttpServletResponse response) {
        String username = request.getParameter("username");
        String password = request.getParameter("password");
        HttpSession session = request.getSession();
        User user = new User(username, password);
        UserServiceImpl userService = new UserServiceImpl();
        if (userService.add(user) > 0) {
            int page = (int) session.getAttribute("lastpage");
            try {
                response.sendRedirect(request.getContextPath() + "/manage/as?action=list&page=" + page);
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
            request.setAttribute("msg", "添加失败!");
            request.setAttribute("user", user);
            try {
                request.getRequestDispatcher("/user_edit.jsp").forward(request, response);
            } catch (ServletException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    protected void delete(HttpServletRequest request, HttpServletResponse response) {
        String username = request.getParameter("username");
        UserServiceImpl userService = new UserServiceImpl();

        if (userService.delete(new User(username, "")) > 0) {
            try {
                response.sendRedirect(request.getContextPath() + "/manage/as?action=list");
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
            request.setAttribute("msg", "删除失败，联系管理员");
            try {
                response.sendRedirect(request.getContextPath() + "/manage/as?action=list");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    protected void list(HttpServletRequest request, HttpServletResponse response) {
        HttpSession session = request.getSession();
        UserServiceImpl userService = new UserServiceImpl();
        PageDisplay<User> userPageDisplay = new PageDisplay<>(userService.list());
        PageServiceImpl<User> userPageService = new PageServiceImpl<User>(userPageDisplay);
        String page = request.getParameter("page");
        if (page == null) page = "1";
        int page_int = Integer.parseInt(page);
        if (page_int < 1) page_int = 1;
        if (page_int > userPageDisplay.getSize()) page_int = userPageDisplay.getSize();
        session.setAttribute("users", userPageService.getUsers(page_int));
        session.setAttribute("pages", userPageService.getList(page_int));
        session.setAttribute("pageDisplay", userPageDisplay);
        session.setAttribute("page", page_int);
        session.setAttribute("lastpage", userPageDisplay.getSize());
        session.setAttribute("UserSum", userService.list().size());
        try {
            response.sendRedirect("http://localhost:8080/admin.jsp");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
