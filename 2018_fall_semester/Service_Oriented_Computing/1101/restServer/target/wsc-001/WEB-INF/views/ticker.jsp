<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="sec" uri="http://www.springframework.org/security/tags" %>
<html>
<head>
    <title>RestTest</title>
</head>
<body>
<table>
    <thead>
    <tr>
        <th>BithumbTicker</th>
        <th>UpbitTicker</th>
    </tr>
    </thead>
    <tbody>
    <tr>
        <td>"${bithumbTicker}"</td>
        <td>"${upbitTicker}"</td>
</table>
</body>
</html>
