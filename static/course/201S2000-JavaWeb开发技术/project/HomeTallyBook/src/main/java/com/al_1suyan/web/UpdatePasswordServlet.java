package com.al_1suyan.web;

import com.al_1suyan.pojo.Admin;
import com.al_1suyan.pojo.User;
import com.al_1suyan.service.AdminService;
import com.al_1suyan.service.impl.AdminServiceImpl;
import com.al_1suyan.service.impl.UserServiceImpl;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet("/manage/ups")
public class UpdatePasswordServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String username = request.getParameter("username");
        String password = request.getParameter("password");
        String type = request.getParameter("type");
        String up_url = request.getParameter("up_url");
        Admin admin = new Admin(username, password);
        User user = new User(username, password);
        UserServiceImpl userService = new UserServiceImpl();
        AdminService adminService = new AdminServiceImpl();
        HttpSession session = request.getSession();
        PrintWriter out = response.getWriter();
        int res = -1;
        if (type.equals("admin")) {
            res = adminService.update(admin);
        } else {
            res = userService.update(user);
        }
        String url = request.getParameter("up_url");
        session.setAttribute("up_url", url);
        if (res > 0) {
            if (type.equals("admin")) {
                request.setAttribute("admin", admin);
            } else {
                request.setAttribute("user", user);
            }
            response.sendRedirect("/manage/as?action=list&page=1");

            session.setAttribute("msg1", "修改密码成功!");
            ;
        } else {
            request.setAttribute("msg", "修改密码失败!");
            try {
                request.getRequestDispatcher("/update_password.jsp").forward(request, response);
            } catch (ServletException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }
}
