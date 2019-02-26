<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib uri="http://www.springframework.org/tags/form" prefix="form"%>
<html>
<head>
  <title>Edit</title>
</head>
<body>
<form:form modelAttribute="user">
  <form:hidden path="id"/>

  name: <form:input path="name"/><br/>
  email: <form:input path="email"/><br/>
  password: <form:input path="password"/><br/>
  age: <form:input path="age"/><br/>
  phone: <form:input path="phone"/><br/>
  <input type="submit" value="Edit"/>
</form:form>
</body>
</html>