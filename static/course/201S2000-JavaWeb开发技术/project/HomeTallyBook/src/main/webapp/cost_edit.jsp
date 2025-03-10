<%--DEPRECATED--%>

<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>编辑消费记录</title>
    <!-- 采用绝对路径导入css文件 -->
    <link rel="stylesheet" type="text/css" href="${pageContext.request.contextPath }/css/style.css"/>
    <!-- 采用绝对路径导入jquery文件 -->
    <script type="text/javascript" src="${pageContext.request.contextPath }/js/jquery-1.7.2.js"></script>
    <script type="text/javascript">
        $(function () {
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
                var costname = $("#costname").val();
                var money = $("#money").val();
                if (costname == null || costname == "") {
                    alert("消费名称不能为空");
                    $("#costname").focus();
                    return false;
                }
                if (money == null || money == "") {
                    alert("消费金额不能为空");
                    $("#money").focus();
                    return false;
                }
            });

        });
    </script>
</head>
<body>
<div id="header">
    <span class="wel_word">编辑消费记录</span>
    <div>
        <a href="${pageContext.request.contextPath }/manager/homeCostServlet?action=list">返回历史记录</a>
        <input style="margin-left:20px" id="keyword" name="keyword" type="text" placeholder="请输入关键字" value=""/>
        <input id="submit" type="submit" value="查询"/>
    </div>
</div>

<div id="main">
    <form action="${pageContext.request.contextPath }/manager/homeCostServlet" method="get">
        <!-- hidden隐藏域,判断是添加请求还是修改请求：param.id取id的值,id为空是添加；id非空是修改 -->
        <input type="hidden" id="action" name="action" value="${ empty param.id ? "add":"update" }">
        <table>
            <tr>
                <td>消费名称</td>
                <td>消费金额</td>
                <td>登记日期</td>
                <td colspan="2">操作</td>
            </tr>
            <tr>
                <!-- 使用el表达式注意在jsp页面(如本页面第一行)导入相应的包 -->
                <input type="hidden" id="id" name="id" value="${requestScope.homeCost.id}">
                <td><input id="costname" name="name" type="text" placeholder="请输入名称"
                           value="${requestScope.homeCost.name}"/></td>
                <td><input id="money" name="money" type="text" placeholder="请输入金额"
                           value="${requestScope.homeCost.money}"/></td>
                <td><input name="date" type="text" placeholder="日期系统自动录入" value="${requestScope.homeCost.date}"
                           disabled="disabled"/></td>
                <td><input id="tablesubmit" type="submit" value="提交"/></td>
            </tr>
        </table>
    </form>
</div>
</body>
</html>