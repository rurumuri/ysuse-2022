<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1, shrink-to-fit=no"/>
    <meta name="renderer" content="webkit"/>
    <meta name="force-rendering" content="webkit"/>
    <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1"/>
    <title>消费记录管理</title>
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
                    //javascript语言提供了一个location地址栏对象
                    //它有一个属性href,可以获取浏览器中地址栏地址
                    location.href = "${pageContext.request.contextPath }/manager/homeCostServlet?action=query&keyword=" + keyword;
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
<body class="mdui-theme-primary-blue-grey mdui-theme-accent-orange">
<%
    int uid = 0;
    String uname = null;
    if (session.getAttribute("uid") != null) {
        uid = ((Integer) session.getAttribute("uid")).intValue();
        uname = (String) session.getAttribute("name");
    } else {
        //response.sendRedirect("login.html");
        out.print("<script>alert('您还没有登录，请登录...'); window.location='/login.html' </script>");
    }
%>

<div class="mdui-toolbar mdui-color-theme">
    <a href="javascript:;" class="mdui-btn mdui-btn-icon">
        <i class="mdui-icon material-icons">menu</i>
    </a>
    <span class="mdui-typo-title">家庭记账本</span>
    <div class="mdui-toolbar-spacer"></div>
    <a class="mdui-btn" mdui-dialog="{target: '#searchDialog'}">
        <i class="mdui-icon material-icons">search</i>搜索
    </a>

    <a href="${pageContext.request.contextPath }/manage/as?action=list" class="mdui-btn">
        <i class="mdui-icon material-icons">account_circle</i>
        <% out.print(uname); %>
    </a>

    <a href="/logout.jsp" class="mdui-btn mdui-btn-icon">
        <i class="mdui-icon material-icons">exit_to_app</i>
    </a>
</div>

<div class="mdui-dialog" id="searchDialog">
    <div class="mdui-dialog-title">搜索</div>
    <div class="mdui-dialog-content">
        <input class="mdui-textfield-input" id="keyword" name="keyword" type="text" placeholder="请输入关键字"
               value=""/>

    </div>
    <div class="mdui-dialog-actions">
        <input class="mdui-btn mdui-ripple mdui-dialog-confirm" id="submit" type="submit" value="查询"/>
    </div>
</div>

<div>
    <button class="mdui-fab mdui-fab-fixed mdui-color-theme-accent mdui-ripple" mdui-dialog="{target: '#addDialog'}">
        <i class="mdui-icon material-icons">add</i>
    </button>

</div>

<div style="margin-top:30px" class="mdui-container">
    <div>
        <table class="mdui-table mdui-table-hoverable">
            <tr>
                <th class="costname" style="width:200px">消费名称</th>
                <th>消费金额</th>
                <th>累计消费</th>
                <th style="width:200px">登记日期</th>
                <th colspan="2">操作</th>
            </tr>
            <!-- 使用el表达式注意在jsp页面(如本页面第一行)导入相应的包 -->
            <c:forEach items="${homeCost}" var="item">
            <tr>
                <td>${item.name}</td>
                <td>${item.money}</td>
                <td>${item.sum}</td>
                <td>${item.date}</td>
                <td>
                    <div class="mdui-btn-group">
                        <a class="mdui-btn" mdui-dialog="{target: '#modifyDialog_${item.id}'}">
                            <i class="mdui-icon material-icons">edit</i> 修改</a>
                        <a class="mdui-btn" mdui-dialog="{target: '#remarkDialog_${item.id}' }">
                            <i class="mdui-icon material-icons">mode_comment</i> 备注</a>
                        <a class="deleteClass mdui-btn"
                           href="${pageContext.request.contextPath }/manager/homeCostServlet?action=delete&id=${item.id}">
                            <i class="mdui-icon material-icons">delete</i> 删除</a></div>
                </td>

            </tr>
            <div class="mdui-dialog" id="modifyDialog_${item.id}">
                <div class="mdui-dialog-title">修改</div>
                <form action="${pageContext.request.contextPath }/manager/homeCostServlet" method="get">
                    <div class="mdui-dialog-content">
                        <input type="hidden" id="action" name="action" value="update">
                        <input type="hidden" id="id" name="id" value="${item.id}">
                        <div class="mdui-textfield"><input class="mdui-textfield-input" id="costname" name="name"
                                                           type="text" placeholder="请输入名称" value="${item.name}"/>
                        </div>
                        <div class="mdui-textfield"><input class="mdui-textfield-input" id="money" name="money"
                                                           type="text" placeholder="请输入金额" value="${item.money}"/>
                        </div>
                        <input class="mdui-textfield-input" type="hidden" id="id" name="id"
                               value="${requestScope.homeCost.id}">
                        <input class="mdui-textfield-input" type="hidden" name="date" type="text"
                               placeholder="日期系统自动录入" value="${requestScope.homeCost.date}"
                               disabled="disabled"/>

                    </div>
                    <div class="mdui-dialog-actions">
                        <input class="mdui-btn mdui-ripple mdui-dialog-confirm" id="submit" type="submit" value="提交"/>
                    </div>
                </form>
            </div>

            <div class="mdui-dialog" id="remarkDialog_${item.id}">
                <div class="mdui-dialog-title">备注
                    <div class="mdui-dialog-content">
                        <p>${item.remarks}</p>
                    </div>
                    <form id="form1" action="${pageContext.request.contextPath }/manager/homeCostServlet" method="get">
                        <input type="hidden" name="action" value="remarks_up">
                        <input type="hidden" name="id" value="${item.id}">
                        <input type="hidden" name="page" value="${page}">
                        <div class="mdui-textfield">
                            <input class="mdui-textfield-input" id="remarks" name="remarks" placeholder="请在此修改…">
                        </div>
                        <div class="mdui-dialog-actions">
                            <button class="mdui-btn mdui-ripple mdui-dialog-close">关闭</button>
                            <input class="mdui-btn mdui-ripple mdui-dialog-confirm" id="submit" type="submit"
                                   value="提交"/>
                        </div>
                    </form>
                </div>
            </div>
            </c:forEach>
    </div>
    <div class="mdui-center">
        <div class="mdui-btn-group" style="margin-top:30px">
            <a class="mdui-btn mdui-center"
               href="${pageContext.request.contextPath}/manager/homeCostServlet?action=list&page=1">首页</a>&nbsp;
            <a class="mdui-btn mdui-center"
               href="${pageContext.request.contextPath}/manager/homeCostServlet?action=list&page=${page-1}">上一页</a>&nbsp;
            <c:forEach items="${pages}" var="page1">
                <a class="mdui-btn mdui-center"
                   href="${pageContext.request.contextPath}/manager/homeCostServlet?action=list&page=${page1}">${page1}</a>&nbsp
            </c:forEach>
            <a class="mdui-btn mdui-center"
               href="${pageContext.request.contextPath}/manager/homeCostServlet?action=list&page=${page+1}">下一页</a>&nbsp;
            <a class="mdui-btn mdui-center"
               href="${pageContext.request.contextPath}/manager/homeCostServlet?action=list&page=${lastpage}">尾页</a>&nbsp;

        </div>

    </div>


</div>

<div class="mdui-dialog" id="addDialog">
    <div class="mdui-dialog-title">添加</div>
    <form action="${pageContext.request.contextPath }/manager/homeCostServlet" method="get">
        <div class="mdui-dialog-content">
            <input type="hidden" id="action" name="action" value="${ empty param.id ? "add":"update" }">
            <div class="mdui-textfield"><input class="mdui-textfield-input" id="costname" name="name" type="text"
                                               placeholder="请输入名称" value="${requestScope.homeCost.name}"/></div>
            <div class="mdui-textfield"><input class="mdui-textfield-input" id="money" name="money" type="text"
                                               placeholder="请输入金额" value="${requestScope.homeCost.money}"/></div>
            <input class="mdui-textfield-input" type="hidden" id="id" name="id" value="${requestScope.homeCost.id}">
            <input class="mdui-textfield-input" type="hidden" name="date" type="text" placeholder="日期系统自动录入"
                   value="${requestScope.homeCost.date}" disabled="disabled"/>

        </div>
        <div class="mdui-dialog-actions">
            <input class="mdui-btn mdui-ripple mdui-dialog-confirm" id="submit" type="submit" value="提交"/>
        </div>
    </form>
</div>

</body>
</html>