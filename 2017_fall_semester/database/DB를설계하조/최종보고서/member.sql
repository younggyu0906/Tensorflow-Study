CREATE TABLE member ( 
 mem_id            CHAR(10),
 mem_name          VARCHAR2(20)  NOT NULL, 
 pw                VARCHAR2(10)  NOT NULL, 
 mem_addr          VARCHAR2(30)  NOT NULL,
 mem_phone         CHAR(13)  NOT NULL,
 CONSTRAINT  member_PK  PRIMARY KEY (mem_id); 
 
INSERT INTO member VALUES ('1000', '�迵��', 'dudrb123', 'õ��', '01012345678'); 
INSERT INTO member VALUES ('1001', '������', 'wlsgkr00', '����', '01022223333');  
INSERT INTO member VALUES ('1002', '���ϴ�', 'rlagksmf25', '����', '01033334444'); 
INSERT INTO member VALUES ('1003', '������', 'tpduf77', '����', '01044445555'); 
INSERT INTO member VALUES ('1004', '��¿�', 'tmddntmddn', '����', '01055556666');  
INSERT INTO member VALUES ('1005', '������', 'qkrwlsgml', '����', '01055555678'); 
INSERT INTO member VALUES ('1006', '�۹���', 'algusdl', '�λ�', '01026345744');  
INSERT INTO member VALUES ('1007', '�ӼҶ�', 'thfkdla', '����', '01055552222'); 
INSERT INTO member VALUES ('1008', '����ȯ', 'kwlghks', 'õ��', '01076544567'); 
INSERT INTO member VALUES ('1009', '�ֹ���', 'alswnsdlRJ', 'õ��', '01088009988');  
INSERT INTO member VALUES ('1010', 'Ȳ��ȣ', 'ghkdtmdgh1', '����', '01022443355'); 
INSERT INTO member VALUES ('1011', '������', 'tmdwowhwh', 'õ��', '01065433456');  
INSERT INTO member VALUES ('1012', '�Ž¹�', 'tlstlstmdals', '��õ', '01045677654'); 
INSERT INTO member VALUES ('1013', '���ֿ�', 'wndud866', '����', '01056788765'); 
INSERT INTO member VALUES ('1014', '������', 'dbdud135', '����', '01012344321');  
INSERT INTO member VALUES ('1015', '������', 'dhwlsal99', '����', '01087655678'); 
INSERT INTO member VALUES ('1016', '����ȣ', 'wjdghwjdgh', '����', '01064642222');  
INSERT INTO member VALUES ('1017', '�赿��', 'ehdgnsdl6', '����', '01033337789'); 
INSERT INTO member VALUES ('1018', '�輼��', 'rlatpwnd24', '����', '01075649980'); 
INSERT INTO member VALUES ('1019', '�̿���', 'dustj9999', '����', '01024453345'); 
INSERT INTO member VALUES ('1020', 'Ȳ����', 'dbstlrdlek', '����', '01098472847'); 
INSERT INTO member VALUES ('1021', '������', 'wjddmsdl10', 'õ��', '01029834711'); 
INSERT INTO member VALUES ('1022', '�Ӻ���', 'qhflsqhfls1', 'õ��', '01010182731'); 
INSERT INTO member VALUES ('1023', '�̽���', 'tmdwntmd1', '����', '01012222345'); 

commit;

set scan on