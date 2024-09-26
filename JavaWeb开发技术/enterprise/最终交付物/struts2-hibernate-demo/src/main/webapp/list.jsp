<%--
  Created by IntelliJ IDEA.
  User: al_1suyan
  Date: 2024/6/23
  Time: 10:15
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <title>Title</title>
</head>
<body>

<div>
    用户名：<input type="text" id="username" value="${student.username}"/>
    <input type="button" value="查询" onclick="query()"/>
    <input type="button" value="新增" onclick="add()"/>
</div>

<table width="70%" border="1px" cellspacing="0px">

    <tr align="center">
        <td>编号</td>
        <td>用户名</td>
        <td>密码</td>
        <td>生日</td>
        <td>电话</td>
        <td>操作</td>
    </tr>
    <c:forEach items="${list}" var="student">
        <tr align="center">
            <td>${student.id}</td>
            <td>${student.username}</td>
            <td>${student.password}</td>
            <td>${student.birthday}</td>
            <td>${student.phone}</td>
            <td><a href="/student_findById?id=${student.id}">编辑</a></td>
            <td><a href="/student_del?id=${student.id}">删除</a></td>
        </tr>
    </c:forEach>
</table>
</body>
<script>
    function query(){
        var usernaemValue=document.getElementById("username").value;
        location.href="/student_list?username="+usernaemValue;
    }
    function add(){
        location.href="/add.jsp";
    }
</script>
</html>
