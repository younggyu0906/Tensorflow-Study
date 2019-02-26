<%--
  Created by IntelliJ IDEA.
  User: LeeJaeYoung
  Date: 2018-10-23
  Time: 오후 12:18
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <title>게시판 리스트</title>
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
        <thead>
        <tr>
            <th>글 번호</th>
            <th>제목</th>
            <th>작성일</th>
            <th>조회수</th>
        </tr>
        </thead>
        <tbody>
        <!-- 게시글 목록 불러오기 -->
        <c:forEach var="b" items="${boards}">
            <tr>
                <td>${b.id}</td>
                <!-- 글 내용 보기 ~~ -->
                <td> <a href="/board/article?id=${b.id}">${b.subject}</a><br/></td>
                <td>${b.regdate}</td>
                <td>${b.hits}</td>
            </tr>
        </c:forEach>

        </tbody>
        <!-- 글 작성하기 버튼 -->
        <button type="button" class="btn btn-primary" onclick = "location.href='/board/write'"> 글 작성하기 </button>
    </table>
</div>

</body>
</html>
