package com.al_1suyan.web;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet("/cj")
public class CodeJudgeServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //设置回复相应的编码格式
        req.setCharacterEncoding("utf-8");
        resp.setContentType("text/html;charset=utf-8");
        PrintWriter out = resp.getWriter();
        //首先判断验证码是否正确
        HttpSession session = req.getSession();
        String succode = (String) session.getAttribute("code");
        String usercode = (String) req.getParameter("usercode");
// debug
//        out.print("<script>alert('"+ succode +"');</script>");
//        out.print("<script>alert('"+ usercode +"');</script>");
        session.setAttribute("url", req.getHeader("Referer"));

        if (!usercode.equals(succode)) {
            //跳转到验证码错误的处理页面
            out.print("<script>alert('验证码错误'); window.location='/login.html' </script>");
        } else {
            //转到判断用户登录的servlet
            req.getRequestDispatcher("/login").forward(req, resp);
        }
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }
}
