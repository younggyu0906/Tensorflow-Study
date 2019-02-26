<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib uri="http://www.springframework.org/tags/form" prefix="form"%>
<html>
<head>
  <title>Form Test</title>
</head>
<body>
<form:form modelAttribute="user">
  name: <form:input path="name"/><br/>
  email: <form:input path="email"/><br/>
  password: <form:password path="password"/><br/>
  age: <form:input path="age"/><br/>
  phone: <form:input path="phone"/><br/>
  bookName: <form:input path="book.bookName"/><br/>
  issn: <form:input path="book.issn"/><br/>
  <input type="submit" value="Signup"/>
</form:form>
</body>
</html>