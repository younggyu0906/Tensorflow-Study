<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="sec" uri="http://www.springframework.org/security/tags" %>
<html>
<head>
    <title>RestTest</title>
</head>
<body>
<c:forEach var="element" items="${data}">
    ${element.type} --> ${element.price}<br/>
</c:forEach>
</body>
</html>
