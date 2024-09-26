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
            if (!${ empty param.username}) {
                document.getElementById("username").setAttribute("disabled", "disabled");
            }
            //提示用户添加失败，删除失败，修改失败
            if (!${ empty requestScope.msg }) {
                alert("${requestScope.msg}");
            }
            //验证非空，并提交查询请求
            $("#submit").click(function () {
                //验证输入框是否为空
                var keyword = $("#keyword").val();
                if (keyword == "") {
                    alert("请输入关键字");
                    return false;
                } else {
                    //javascript语言提供了一个location地址栏对象
                    //它有一个属性href,可以获取浏览器中地址栏地址
                    location.href = "${pageContext.request.contextPath }/manager/homeCostServlet?action=query&keyword=" + keyword;
                }
            });
            //验证输入框非空
            $("#tablesubmit").click(function () {
                //验证输入框是否为空
                document.getElementById("username").removeAttribute("disabled");
                var username = $("#username").val();
                var password = $("#password").val();
                if (username == null || username == "") {
                    alert("用户名不能为空");
                    $("#username").focus();
                    return false;
                } else if (username.length < 5) {
                    alert("用户名不能小于5");
                    $("#username").focus();
                    return false;
                }
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
    <span class="wel_word">编辑用户信息</span>
    <div>
        <a href="${pageContext.request.contextPath }/manage/as?action=list">返回历史记录</a>
        <input style="margin-left:20px" id="keyword" name="keyword" type="text" placeholder="请输入关键字" value=""/>
        <input id="submit" type="submit" value="查询"/>
    </div>
</div>
<div id="main">
    <form action="${pageContext.request.contextPath }/manage/as" method="get">
        <!-- hidden隐藏域,判断是添加请求还是修改请求：param.id取id的值,id为空是添加；id非空是修改 -->
        <input type="hidden" id="action" name="action" value="${ empty param.username ? "add":"update" }">
        <input type="hidden" id="page" name="page" value="${page}">
        <table>
            <tr>
                <td>账号</td>
                <td>密码</td>
                <td colspan="2">操作</td>
            </tr>
            <tr>
                <td><input id="username" name="username" type="text" placeholder="请输入账号"
                           value="${requestScope.user.username}"/></td>
                <td><input id="password" name="password" type="text" placeholder="请输入密码"
                           value="${requestScope.user.password}"/></td>
                <td><input id="tablesubmit" type="submit" value="提交"/></td>
            </tr>
        </table>
    </form>
</div>
</body>
</html>