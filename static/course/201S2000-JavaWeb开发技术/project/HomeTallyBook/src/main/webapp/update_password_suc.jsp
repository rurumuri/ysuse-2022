<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
</body>
<script>
    alert("修改成功！请重新登录");
    var url = "${pageContext.request.contextPath}" + "/login.html";
    window.location.href = url;
</script>
</html>
