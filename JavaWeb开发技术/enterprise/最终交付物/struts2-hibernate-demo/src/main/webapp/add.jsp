<%--
  Created by IntelliJ IDEA.
  User: al_1suyan
  Date: 2024/6/23
  Time: 9:51
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<h1>新增</h1>
<form action="/student_add" method="post">
    <div>用户名：<input type="text" name="username" value="${student.username}"/></div>
    <div>密码：<input type="text" name="password" value="${student.password}"/></div>
    <div>生日：<input type="date" name="birthday" value="${student.birthday}"/></div>
    <div>电话：<input type="text" name="phone" value="${student.phone}"/></div>
    <div><input type="submit" value="保存"/></div>
</form>
<c:if test="${msg != null}">
    <span style="color:red">${msg}</span>
</c:if>

</body>
</html>
