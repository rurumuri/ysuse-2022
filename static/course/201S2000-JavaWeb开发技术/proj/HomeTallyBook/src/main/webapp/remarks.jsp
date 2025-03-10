<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>编辑备注</title>
    <!-- 采用绝对路径导入css文件 -->
    <link rel="stylesheet" type="text/css" href="${pageContext.request.contextPath }/css/style.css"/>
    <!-- 采用绝对路径导入jquery文件 -->
    <script type="text/javascript" src="${pageContext.request.contextPath }/js/jquery-1.7.2.js"></script>
    <script type="text/javascript">
        function remark() {
            var remark = document.getElementById("remarks");
            if (remark.value.length > 200) {
                alert("字数不能超过200！");
                if (remark.value.length > 300) {
                    //太多，直接清空
                    remark.value = "";
                }
                //不多则不清空
                return false;
            }
            document.getElementById("form1").submit();
        }
    </script>
</head>
<body>
<div id="header">
    <span class="wel_word">编辑备注信息</span>
    <div>
        <a href="${pageContext.request.contextPath }/manager/homeCostServlet?action=list">返回历史记录</a>
    </div>
</div>
<div id="main" style="text-align: center">
    <p>${requestScope.homeCost.remarks}</p>
    <form id="form1" action="${pageContext.request.contextPath }/manager/homeCostServlet" method="get">
        <!-- hidden隐藏域,判断是添加请求还是修改请求：param.id取id的值,id为空是添加；id非空是修改 -->
        <input type="hidden" name="action" value="remarks_up">
        <input type="hidden" name="id" value="${requestScope.homeCost.id}">
        <input type="hidden" name="page" value="${page}">
        <textarea id="remarks" name="remarks"
                  placeholder="${requestScope.homeCost.remarks==null||requestScope.homeCost.remarks.length()==0?"请在这里写备注":""}"
                  style="width: 1000px;height: 540px">${requestScope.homeCost.remarks==null||requestScope.homeCost.remarks.length()==0?"":requestScope.homeCost.remarks}</textarea>
    </form>
</div>
<div style="text-align: center">
    <input id="button" onclick="remark()" type="button" value="保存"
           style="outline: none;width: 300px;height: 50px;border: 0;padding: 5px 7px;background: bisque;border-radius: 20px;margin: 10px 10px">
</div>
</body>
</html>