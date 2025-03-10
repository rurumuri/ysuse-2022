<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8" %>
<%@ page import="java.sql.*" %>
<%@ page import="com.al_1suyan.utils.DBUtils" %>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>database operation</title>
</head>
<body>
<%
    String username = request.getParameter("username");
    String password = request.getParameter("password");
%>

<%
    try {
        Class.forName("com.mysql.jdbc.Driver");
        // Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/lab", "root", "41528596");
        Connection conn = DBUtils.getConn();
        Statement stmt = conn.createStatement();

        // 构造SQL语句
        String InsertSQL = "INSERT INTO user(username,password) values('" + username + "','" + password + "')";
        System.out.println(username + "\t" + password);

        // 进行更新操作的执行
        int exeResult = stmt.executeUpdate(InsertSQL);

        if (exeResult > 0) {
//            response.getWriter().write("Congratulation! Register Success!");
//            request.getRequestDispatcher("index.html").forward(request, response);
            out.print(
                    "<script type='text/javascript'>\n" +
                            "    alert('注册成功！3秒后将回到登陆页面');\n" +
                            "    setTimeout(function() {\n" +
                            "        window.location = 'index.html';\n" +
                            "    }, 3000);\n" +
                            "</script>\n"
            );
        } else {
//            response.getWriter().write("Sorry!Register Failed!\nPlease Retry it!");
            out.print(
                    "<script type='text/javascript'>\n" +
                            "    alert('注册失败！3秒后将回到登陆页面');\n" +
                            "    setTimeout(function() {\n" +
                            "        window.location = 'index.html';\n" +
                            "    }, 3000);\n" +
                            "</script>\n"
            );
        }
    } catch (SQLException e) {
        out.print("<script>alert(" + e.toString() + ")</script>");
    }
%>

</body>
</html>