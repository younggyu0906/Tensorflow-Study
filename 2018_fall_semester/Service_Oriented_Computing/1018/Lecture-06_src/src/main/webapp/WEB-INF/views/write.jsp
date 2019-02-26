<%--
  Created by IntelliJ IDEA.
  User: LeeJaeYoung
  Date: 2018-10-23
  Time: 오후 12:31
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib uri="http://www.springframework.org/tags/form" prefix="form"%>
<html>
<head>
    <title>글 작성</title>
    <!-- 합쳐지고 최소화된 최신 CSS -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.2/css/bootstrap.min.css">

    <!-- 부가적인 테마 -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.2/css/bootstrap-theme.min.css">

    <!-- 합쳐지고 최소화된 최신 자바스크립트 -->
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.2/js/bootstrap.min.js"></script>
</head>
<body>
<div class="container">
    <table class="table">
        </br>
        </br>
        <form:form modelAttribute="board">
            <div class="form-group">
                <label for="subject">글 제목:</label>
                <form:input path="subject"/><br/>
            </div>
            <div class="form-group">
                <label for="contents">글 내용:</label>
                <form:input path="contents"/><br/>
            </div>

            <button type="submit" class="btn btn-default">작성하기</button>
        </form:form>
    </table>
</div>
</body>
</html>
