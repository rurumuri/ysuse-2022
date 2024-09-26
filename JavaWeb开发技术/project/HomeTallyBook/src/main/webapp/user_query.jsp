<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>查询用户</title>
    <!-- 采用绝对路径导入css文件 -->
    <link rel="stylesheet" type="text/css" href="${pageContext.request.contextPath }/css/style.css"/>
    <!-- 采用绝对路径导入jquery文件 -->
    <script type="text/javascript" src="${pageContext.request.contextPath}/js/jquery-1.7.2.js"></script>
    <script type="text/javascript">
        $(function () {
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
                    location.href = "${pageContext.request.contextPath }/manage/as?action=query&keyword=" + keyword;
                }

            });

            //删除提示
            $("a.deleteClass").click(function () {
                //在事件fuction函数中有一个this对象，即当前响应事件的dom对象

                /**
                 * confirm是确认提示框函数
                 * 参数是提示内容
                 * 两个按钮：确认和取消
                 * 返回true表示点击确认
                 */
                return confirm("你确定要删除【" + $(this).parent().parent().find("td:first").text() + "】?");
            });

        });
    </script>
</head>
<body>
<div id="header">
    <span class="wel_word">查询用户</span>
    <div>
        <a href="${pageContext.request.contextPath }/manage/as?action=list">返回历史记录</a>
        <input style="margin-left:20px" id="keyword" name="keyword" type="text" placeholder="请输入关键字" value=""/>
        <input id="submit" type="submit" value="查询"/>
    </div>
</div>

<div id="main" style="text-align: center">
    <c:if test="${sessionScope.users.size()>=0}">
        <table style="margin-top:30px;margin-left:180px">
            <tr>
                <td class="costname" style="width:200px">账号</td>
                <td>密码</td>
                <td colspan="2">操作</td>
            </tr>
            <!-- 使用el表达式注意在jsp页面(如本页面第一行)导入相应的包 -->
            <c:forEach items="${sessionScope.users}" var="user">
                <tr>
                    <td>${user.username}</td>
                    <td>${user.password}</td>
                    <td>
                        <a href="${pageContext.request.contextPath }/manage/as?action=getbyusername&username=${user.username}">修改密码</a>
                    </td>
                    <td><a class="deleteClass"
                           href="${pageContext.request.contextPath }/manage/as?action=delete&username=${user.username}">删除</a>
                    </td>
                </tr>
            </c:forEach>
            <tr>
                <td colspan="4">共有${sessionScope.users.size()}用户记录</td>
            </tr>
        </table>
    </c:if>
</div>
<div style="text-align: center">
    <a href="${pageContext.request.contextPath}/manage/as?action=query&page=1">首页</a>&nbsp;
    <a href="${pageContext.request.contextPath}/manage/as?action=query&page=${page-1}">上一页</a>&nbsp;
    <c:forEach items="${pages}" var="page1">
        <a href="${pageContext.request.contextPath}/manage/as?action=query&page=${page1}">${page1}</a>&nbsp
    </c:forEach>
    <a href="${pageContext.request.contextPath}/manage/as?action=query&page=${page+1}">下一页</a>&nbsp;
    <a href="${pageContext.request.contextPath}/manage/as?action=query&page=${lastpage}">尾页</a>&nbsp;
    <br>共有${lastpage}页，共有${UserSum}条用户记录<br>
</div>
</body>
</html>