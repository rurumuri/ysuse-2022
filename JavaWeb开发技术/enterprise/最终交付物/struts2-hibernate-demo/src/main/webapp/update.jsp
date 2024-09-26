<%--
  Created by IntelliJ IDEA.
  User: al_1suyan
  Date: 2024/6/23
  Time: 10:53
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<h1>编辑</h1>
<form action="/student_update" method="post">
    <input type="hidden" name="id" value="${student.id}"/>
    <div>用户名：<input type="text" name="username" value="${student.username}" readonly/></div>
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
