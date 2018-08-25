CREATE TABLE member ( 
 mem_id            CHAR(10),
 mem_name          VARCHAR2(20)  NOT NULL, 
 pw                VARCHAR2(10)  NOT NULL, 
 mem_addr          VARCHAR2(30)  NOT NULL,
 mem_phone         CHAR(13)  NOT NULL,
 CONSTRAINT  member_PK  PRIMARY KEY (mem_id); 
 
INSERT INTO member VALUES ('1000', '김영규', 'dudrb123', '천안', '01012345678'); 
INSERT INTO member VALUES ('1001', '김진학', 'wlsgkr00', '세종', '01022223333');  
INSERT INTO member VALUES ('1002', '김하늘', 'rlagksmf25', '대전', '01033334444'); 
INSERT INTO member VALUES ('1003', '정세열', 'tpduf77', '수원', '01044445555'); 
INSERT INTO member VALUES ('1004', '김승우', 'tmddntmddn', '서울', '01055556666');  
INSERT INTO member VALUES ('1005', '박진희', 'qkrwlsgml', '세종', '01055555678'); 
INSERT INTO member VALUES ('1006', '송미현', 'algusdl', '부산', '01026345744');  
INSERT INTO member VALUES ('1007', '임소라', 'thfkdla', '서울', '01055552222'); 
INSERT INTO member VALUES ('1008', '김지환', 'kwlghks', '천안', '01076544567'); 
INSERT INTO member VALUES ('1009', '최민준', 'alswnsdlRJ', '천안', '01088009988');  
INSERT INTO member VALUES ('1010', '황승호', 'ghkdtmdgh1', '대전', '01022443355'); 
INSERT INTO member VALUES ('1011', '조승재', 'tmdwowhwh', '천안', '01065433456');  
INSERT INTO member VALUES ('1012', '신승민', 'tlstlstmdals', '인천', '01045677654'); 
INSERT INTO member VALUES ('1013', '김주영', 'wndud866', '목포', '01056788765'); 
INSERT INTO member VALUES ('1014', '이유영', 'dbdud135', '전주', '01012344321');  
INSERT INTO member VALUES ('1015', '오진미', 'dhwlsal99', '광주', '01087655678'); 
INSERT INTO member VALUES ('1016', '장정호', 'wjdghwjdgh', '전주', '01064642222');  
INSERT INTO member VALUES ('1017', '김동훈', 'ehdgnsdl6', '대전', '01033337789'); 
INSERT INTO member VALUES ('1018', '김세중', 'rlatpwnd24', '대전', '01075649980'); 
INSERT INTO member VALUES ('1019', '이연서', 'dustj9999', '서울', '01024453345'); 
INSERT INTO member VALUES ('1020', '황윤식', 'dbstlrdlek', '서울', '01098472847'); 
INSERT INTO member VALUES ('1021', '김정은', 'wjddmsdl10', '천안', '01029834711'); 
INSERT INTO member VALUES ('1022', '임보린', 'qhflsqhfls1', '천안', '01010182731'); 
INSERT INTO member VALUES ('1023', '이승주', 'tmdwntmd1', '서울', '01012222345'); 

commit;

set scan on