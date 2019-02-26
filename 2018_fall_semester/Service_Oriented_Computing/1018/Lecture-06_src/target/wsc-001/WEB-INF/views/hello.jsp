<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title></title>
    <!-- 합쳐지고 최소화된 최신 CSS -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.2/css/bootstrap.min.css">

    <!-- 부가적인 테마 -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.2/css/bootstrap-theme.min.css">

    <!-- 합쳐지고 최소화된 최신 자바스크립트 -->
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.2/js/bootstrap.min.js"></script>
    <style>
        .red{
            color: red;
        }
        #green{
            color: green;
        }
    </style>
</head>
<body>
<div class="row">
    <div class="col-md-6 col-sm-12 col-lg-4">
        dfdf
    </div>
    <div class="col-md-6 col-sm-12 col-lg-4">
        1234
    </div>
</div>

<span style="color: blue">인라인1</span>
<span class="red">인라인2</span>
<div id="green">블록1</div>
<p class="red">블록2</p>
<label id="green">인라인3</label>
Hello, ${textFromController}<br/>
${name}<br/>
<img src="/resources/images/spring.png"/>

</body>
</html>
