<%@ page import="com.al_1suyan.service.impl.UserServiceImpl" %>
<%@ page import="com.al_1suyan.utils.PageDisplay" %>
<%@ page import="com.al_1suyan.pojo.User" %>
<%@ page import="java.util.List" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<!DOCTYPE html>
<html
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1, shrink-to-fit=no"/>
    <meta name="renderer" content="webkit"/>
    <meta name="force-rendering" content="webkit"/>
    <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1"/>
    <title>用户管理</title>
    <!-- 采用绝对路径导入css文件 -->

    <!-- 采用绝对路径导入jquery文件 -->
    <script type="text/javascript" src="${pageContext.request.contextPath }/js/jquery-1.7.2.js"></script>
    <!-- MDUI CSS -->
    <link
            rel="stylesheet"
            href="${pageContext.request.contextPath }/css/mdui.css"
    />

    <!-- MDUI JavaScript -->
    <script
            src="${pageContext.request.contextPath }/js/mdui.js"
    ></script>
    <script type="text/javascript">

        $(function () {
            if (!${empty sessionScope.msg}) {
                alert(${sessionScope.msg});
            }
            //提示用户添加失败，删除失败，修改失败
            if (!${empty requestScope.msg}) {
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
                    // javascript语言提供了一个location地址栏对象
                    // 属性href,可以获取浏览器中地址栏地址
                    location.href = "${pageContext.request.contextPath }/manage/as?action=query&keyword=" + keyword;
                }

            });

            // 删除提示
            $("a.deleteClass").click(function () {
                // 在事件fuction函数中有一个this对象，即当前响应事件的dom对象

                /**
                 * confirm是确认提示框函数
                 * 参数是提示内容
                 * 两个按钮：确认和取消
                 * 返回true表示点击确认
                 */
                // return confirm("你确定要删除【"+ $(this).parent().parent().find("td:first").text()+"】?");
                return confirm("你确定要删除此用户吗?");
            });

        });
    </script>
</head>
<body class="mdui-theme-primary-blue-grey mdui-theme-accent-orange">

<%
    int uid = 0;
    String uname = null;
    uid = ((Integer) session.getAttribute("uid")).intValue();
    uname = (String) session.getAttribute("name");
    if (((Integer) session.getAttribute("isAdmin")).intValue() == 0) {
        out.print("<script>alert('您不是管理员，拒绝访问！'); window.location='/manager/homeCostServlet?action=list' </script>");
    }
%>

<div class="mdui-toolbar mdui-color-theme">
    <a href="javascript:;" class="mdui-btn mdui-btn-icon">
        <i class="mdui-icon material-icons">menu</i>
    </a>
    <span class="mdui-typo-title">家庭记账本</span>
    <div class="mdui-toolbar-spacer"></div>


    <a href="${pageContext.request.contextPath }/manage/as?action=list" class="mdui-btn">
        <i class="mdui-icon material-icons">account_circle</i>
        <% out.print(uname); %>
    </a>

    <a href="/logout.jsp" class="mdui-btn mdui-btn-icon">
        <i class="mdui-icon material-icons">exit_to_app</i>
    </a>
</div>

<div style="margin-top:30px" class="mdui-container">
    <table class="mdui-table mdui-table-hoverable">
        <tr>
            <td style="width:200px">账号</td>
            <td>密码</td>
            <td colspan="2">操作</td>
        </tr>
        <c:forEach items="${users}" var="user">
            <tr>
                <td>${user.username}</td>
                <td>${user.password}</td>
                <td>
                    <div class="mdui-btn-group">
                        <a class="mdui-btn" mdui-dialog="{target: '#passwordDialog_${user.username}'}">
                            <i class="mdui-icon material-icons">edit</i> 修改密码</a>
                        <a class="deleteClass mdui-btn"
                           href="${pageContext.request.contextPath }/manage/as?action=delete&username=${user.username}">
                            <i class="mdui-icon material-icons">delete</i> 删除</a></div>
            </tr>
            <div class="mdui-dialog" id="passwordDialog_${user.username}">
                <div class="mdui-dialog-title">修改密码</div>
                <form action="${pageContext.request.contextPath }/manage/ups" method="get">
                    <div class="mdui-dialog-content">
                        <input type="hidden" id="action" name="action" value="updatepassword">
                        <input type="hidden" id="type" name="type" value="user">
                        <input type="hidden" id="up_url" name="up_url"
                               value="${pageContext.request.getHeader("Referer")}">
                        <div class="mdui-textfield"><input class="mdui-textfield-input" id="username" name="username"
                                                           type="text" value="${user.username}"/></div>
                        <div class="mdui-textfield"><input class="mdui-textfield-input" id="password" name="password"
                                                           type="text" placeholder="请输入新密码"/></div>

                    </div>
                    <div class="mdui-dialog-actions">
                        <input class="mdui-btn mdui-ripple mdui-dialog-confirm" id="submit" type="submit" value="提交"/>
                    </div>
                </form>
            </div>
        </c:forEach>
        <tr>
            <td></td>
            <td></td>
            <td colspan="2">
                <%--                <a href="${pageContext.request.contextPath }/user_edit.jsp">新增</a>--%>
                <%--                ${pageContext.request.contextPath} 会被替换为当前请求的上下文路径，增强可移植性--%>
                <a href="${pageContext.request.contextPath }/signup.html">新增</a>
            </td>
        </tr>

    </table>
    <div class="mdui-center">
        <div class="mdui-btn-group" style="margin-top:30px">
            <a class="mdui-btn mdui-center"
               href="${pageContext.request.contextPath}/manage/as?action=list&page=1">首页</a>&nbsp;
            <a class="mdui-btn mdui-center"
               href="${pageContext.request.contextPath}/manage/aas?action=list&page=${page-1}">上一页</a>&nbsp;
            <c:forEach items="${pages}" var="page1">
                <a class="mdui-btn mdui-center"
                   href="${pageContext.request.contextPath}/manage/as?action=list&page=${page1}">${page1}</a>&nbsp
            </c:forEach>
            <a class="mdui-btn mdui-center"
               href="${pageContext.request.contextPath}/manage/as?action=list&page=${page+1}">下一页</a>&nbsp;
            <a class="mdui-btn mdui-center"
               href="${pageContext.request.contextPath}/manage/as?action=list&page=${lastpage}">尾页</a>&nbsp;
        </div>
    </div>
</div>
</body>
</html>
