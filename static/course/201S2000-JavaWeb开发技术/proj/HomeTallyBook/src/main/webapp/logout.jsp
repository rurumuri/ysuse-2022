<%--<%--%>
<%--	// 使 session 立即失效--%>
<%--	session.invalidate();--%>
<%--	// 返回登陆界面--%>
<%--	response.sendRedirect("login.html");--%>
<%--%>--%>

<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<!DOCTYPE html>
<html>
<head>
    <title>Logout</title>
    <!-- 3 秒后自动跳转到 login.html 页面 -->
    <meta http-equiv="refresh" content="3;url=login.html">
</head>
<body>
<%
    // 使 session 立即失效
    session.invalidate();
%>
<p>已退出登录，3秒后将返回登陆界面...</p>
<p><a href="login.html">点击此处立即跳转</a></p>
</body>
</html>
