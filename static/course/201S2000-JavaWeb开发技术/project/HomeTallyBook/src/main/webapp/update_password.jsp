<%--修改密码信息--%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>编辑用户</title>
    <!-- 采用绝对路径导入css文件 -->
    <link rel="stylesheet" type="text/css" href="${pageContext.request.contextPath }/css/style.css"/>
    <!-- 采用绝对路径导入jquery文件 -->
    <script type="text/javascript" src="${pageContext.request.contextPath }/js/jquery-1.7.2.js"></script>
    <script type="text/javascript">
        $(function () {
            //设置username不可修改,让其只能修改密码，不能修改修改账号
            document.getElementById("username").setAttribute("disabled", "disabled");
            //提示用户添加失败，删除失败，修改失败
            if (!${ empty requestScope.msg }) {
                alert("${requestScope.msg}");
            }
            //验证输入框非空
            $("#tablesubmit").click(function () {
                //验证输入框是否为空
                document.getElementById("username").removeAttribute("disabled");
                var password = $("#password").val();
                if (password == null || password == "") {
                    alert("密码不能为空");
                    $("#password").focus();
                    return false;
                } else if (password.length < 6) {
                    alert("密码不能小于6");
                    $("#password").focus();
                    return false;
                }
            });

        });
    </script>
</head>
<body>
<div id="header">
    <span class="wel_word">修改密码</span>
    <div>
        <a href="${pageContext.request.getHeader("Referer")}">返回历史记录</a>
    </div>
</div>
<div id="main">
    <form action="${pageContext.request.contextPath }/manage/ups" method="get">
        <!-- hidden隐藏域,判断是添加请求还是修改请求：param.id取id的值,id为空是添加；id非空是修改 -->
        <input type="hidden" id="action" name="action" value="updatepassword">
        <input type="hidden" id="type" name="type" value="admin">
        <input type="hidden" id="up_url" name="up_url" value="${pageContext.request.getHeader("Referer")}">
        <table>
            <tr>
                <td>账号</td>
                <td>密码</td>
                <td colspan="2">操作</td>
            </tr>
            <tr>
                <td><input id="username" name="username" type="text" placeholder="请输入账号"
                           value="${gettype=="admin"?admin.username:user.username}"/></td>
                <td><input id="password" name="password" type="text" placeholder="请输入密码"
                           value="${gettype=="admin"?admin.password:admin.password}"/></td>
                <td><input id="tablesubmit" type="submit" value="提交"/></td>
            </tr>
        </table>
    </form>
</div>
</body>
</html>