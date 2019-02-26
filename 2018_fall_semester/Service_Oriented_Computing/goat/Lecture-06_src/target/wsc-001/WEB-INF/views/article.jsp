<%--
  Created by IntelliJ IDEA.
  User: LeeJaeYoung
  Date: 2018-10-23
  Time: 오후 12:25
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <title>글 내용 보기</title>
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
        <button type="button" class="btn btn-primary" onclick = "location.href='/board/board'"> 목록으로 돌아가기 </button>
        <thead>
        <tr>
            <th>글 번호 : ${board.id}</th>
            <th>글 제목 : ${board.subject}</th>
            <th>작성일 : ${board.regdate}</th>
            <th>조회수 : ${board.hits}</th>
        </tr>
        </thead>

    </table>
    <table class="table">
        <th>글 내용 : ${board.contents}</th>
    </table>

</div>

</body>
</html>
