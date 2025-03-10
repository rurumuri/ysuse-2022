package com.al_1suyan.web;

import com.al_1suyan.utils.DBUtils;
import org.apache.commons.lang.StringEscapeUtils;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.*;

@WebServlet("/login")
public class LoginServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;

    public LoginServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

    @Override
    protected void doPost(HttpServletRequest request,
                          HttpServletResponse response) throws ServletException, IOException {
        // doGet(request, response);
        // 设置编码为utf-8
        request.setCharacterEncoding("utf-8");
        response.setCharacterEncoding("utf-8");
        PrintWriter out = response.getWriter();

        // test
//		out.print("<script>alert('"+ "TEST" +"');</script>");

        // 获取用户名和密码
        String name = StringEscapeUtils.escapeSql(request.getParameter("uname"));
        String pwd = StringEscapeUtils.escapeSql(request.getParameter("pwd"));

        // test
//		out.print("<script>alert('"+ "TEST" +"');</script>");

        try {
            Class.forName("com.mysql.jdbc.Driver");
//            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/lab", "root", "41528596");
            Connection conn = DBUtils.getConn();
            Statement stmt = conn.createStatement();

            String sqlQuery = "SELECT * FROM USER WHERE USERNAME = '" + name + "' AND PASSWORD = '" + pwd + "'";
            ResultSet result = stmt.executeQuery(sqlQuery);// SQL查询
            if (result.next()) {
                int uid = result.getInt("uid");
                int isAdmin = result.getInt("isAdmin");

                out.println("Login Sucessfully");
                HttpSession session = request.getSession();//获取session
                session.setAttribute("uid", uid);
                session.setAttribute("isAdmin", isAdmin);
                session.setAttribute("name", name);
                session.setAttribute("pwd", pwd);// 将用户信息保存在session中
                response.sendRedirect("/manager/homeCostServlet?action=list");
            } else {
                out.print("<script>alert('" + "登陆失败，请检查用户名或密码" + "'); window.location.href='/login.html';</script>");
                //response.sendRedirect("/login.html");
                //out.println("Failed");
            }

        } catch (SQLException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }


    }

//	@Override
//	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//		doPost(req,resp);
//	}
}