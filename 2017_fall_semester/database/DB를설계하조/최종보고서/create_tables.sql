﻿
CREATE TABLE member ( 
 mem_id            CHAR(10),
 mem_name          VARCHAR2(20)  NOT NULL, 
 pw                VARCHAR2(10)  NOT NULL, 
 mem_addr          VARCHAR2(30)  NOT NULL,
 mem_phone         CHAR(13)  NOT NULL,
 CONSTRAINT  member_PK  PRIMARY KEY (mem_id)); 
 
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
INSERT INTO member VALUES ('1012', '신승민', 'tlstlstmda', '인천', '01045677654'); 
INSERT INTO member VALUES ('1013', '김주영', 'wndud866', '목포', '01056788765'); 
INSERT INTO member VALUES ('1014', '이유영', 'dbdud135', '전주', '01012344321');  
INSERT INTO member VALUES ('1015', '오진미', 'dhwlsal99', '광주', '01087655678'); 
INSERT INTO member VALUES ('1016', '장정호', 'wjdghwjdgh', '전주', '01064642222');  
INSERT INTO member VALUES ('1017', '김동훈', 'ehdgnsdl6', '대전', '01033337789'); 
INSERT INTO member VALUES ('1018', '김세중', 'rlatpwnd24', '대전', '01075649980'); 
INSERT INTO member VALUES ('1019', '이연서', 'dustj9999', '서울', '01024453345'); 
INSERT INTO member VALUES ('1020', '황윤식', 'dbstlrdlek', '서울', '01098472847'); 
INSERT INTO member VALUES ('1021', '김정은', 'wjddmsdl10', '천안', '01029834711'); 
INSERT INTO member VALUES ('1022', '임보린', 'qhflsqhfls', '천안', '01010182731'); 
INSERT INTO member VALUES ('1023', '이승주', 'tmdwntmd1', '서울', '01012222345'); 

commit; 
 
CREATE TABLE club ( 
 club_id           VARCHAR2(10), 
 club_name         VARCHAR2(20)  NOT NULL, 
 club_phone        VARCHAR2(13)  NOT  NULL,    
 club_addr         VARCHAR2(30),
 CONSTRAINT  club_PK   PRIMARY KEY (club_id));
 
INSERT INTO club VALUES ('guitar1', '비상', '01098766789', '천안시 신부동');
INSERT INTO club VALUES ('korchestra', '오케스트라', '01012465412', '천안시 불당동');
INSERT INTO club VALUES ('security6', '보안', '01025676955', '천안시 청수동');
INSERT INTO club VALUES ('singer00', '솔메', '01027693456', '대전시 월평동');
INSERT INTO club VALUES ('pianolove', '피아노사랑', '01013134444', '천안시 성정동');
INSERT INTO club VALUES ('book', '독서모임', '01099908888', '천안시 구성동');
INSERT INTO club VALUES ('security48', 'SECURITY', '01011113243', '대전시 둔산동');
INSERT INTO club VALUES ('soccer2017', '축구', '01043562578', '세종시 반곡동');
INSERT INTO club VALUES ('basketball', '농구천재', '01022836412', '세종시 보람동');
INSERT INTO club VALUES ('musical101', '뮤지컬', '01017334644', '세종시 대평동'); 
INSERT INTO club VALUES ('movie99', '영화감상', '01099112345', '수원시 인계동동');
INSERT INTO club VALUES ('cartoon32', '만화', '01019923333', '수원시 송산동');
INSERT INTO club VALUES ('vocal11', '보컬', '01078966543', '천안시 청수동');
INSERT INTO club VALUES ('guitar4', '기타세상', '01019473547', '천안시 성정동');
INSERT INTO club VALUES ('mybook3', '책읽는사람', '01063813739', '천안시 신부동');
INSERT INTO club VALUES ('orchestra', '수원시오케스트라', '01017193729', '수원시 신풍동');
INSERT INTO club VALUES ('soccer22', '축구사랑', '01013783928', '세종시 반곡동');
INSERT INTO club VALUES ('ilovesing', '나는가수다', '01018743920', '대전시 노은동');
INSERT INTO club VALUES ('mypiano', '나의피아노', '01019372890', '성남시 산성동');
INSERT INTO club VALUES ('travel', '여행을떠나요', '01024980123', '성남시 양지동');
commit;
 
CREATE TABLE instrument ( 
 instr_id          VARCHAR2(10),
 mdl_name          VARCHAR2(20),
 brand             VARCHAR2(10),
 color             VARCHAR2(30),
 size              NUMBER(6)  NOT NULL,
 kind              VARCHAR2(10)  NOT NULL,
 prod_date         DATE  NOT NULL,
CONSTRAINT  instrument_PK   PRIMARY KEY (instr_id));
 
INSERT INTO instrument VALUES ('100001', '기타', '영창악기', 'beige', '6', TO_DATE('03/01/2017','MM/DD/YYYY')); 
INSERT INTO instrument VALUES ('100002', '바이올린', '삼익악기', 'brown', '4', TO_DATE('03/11/2017','MM/DD/YYYY')); 
INSERT INTO instrument VALUES ('100003', '첼로', '삼익악기', 'brown', '8', TO_DATE('03/21/2017','MM/DD/YYYY')); 
INSERT INTO instrument VALUES ('100004', '호른', '영창악기', 'gold', '5', TO_DATE('03/07/2017','MM/DD/YYYY')); 
INSERT INTO instrument VALUES ('100005', '피아노', '영창악기', 'black', '10', TO_DATE('03/03/2017','MM/DD/YYYY')); 
INSERT INTO instrument VALUES ('100006', '플룻', '삼익악기', 'silver', '4', TO_DATE('03/21/2017','MM/DD/YYYY')); 
INSERT INTO instrument VALUES ('100007', '기타', '영창악기', 'beige', '6', TO_DATE('03/01/2017','MM/DD/YYYY')); 
INSERT INTO instrument VALUES ('100008', '기타', '삼익악기', 'brown', '5', TO_DATE('03/11/2017','MM/DD/YYYY')); 
INSERT INTO instrument VALUES ('100009', '호른', '영창악기', 'gold', '5', TO_DATE('03/21/2017','MM/DD/YYYY')); 
INSERT INTO instrument VALUES ('100010', '클라리넷', '삼익악기', 'black', '4', TO_DATE('03/07/2017','MM/DD/YYYY')); 
INSERT INTO instrument VALUES ('100011', '트럼펫', '영창악기', 'gold', '4', TO_DATE('03/03/2017','MM/DD/YYYY')); 
INSERT INTO instrument VALUES ('100012', '비올라', '삼익악기', 'brown', '4', TO_DATE('03/21/2017','MM/DD/YYYY')); 
INSERT INTO instrument VALUES ('100013', '트럼본', '영창악기', 'gold', '5', TO_DATE('03/21/2017','MM/DD/YYYY')); 
INSERT INTO instrument VALUES ('100014', '바이올린', '삼익악기', 'brown', '5', TO_DATE('03/07/2017','MM/DD/YYYY')); 
INSERT INTO instrument VALUES ('100015', '플룻', '영창악기', 'silver', '4', TO_DATE('03/03/2017','MM/DD/YYYY')); 
INSERT INTO instrument VALUES ('100016', '피아노', '삼익악기', 'white', '10', TO_DATE('03/21/2017','MM/DD/YYYY')); 
INSERT INTO instrument VALUES ('100017', '피아노', '영창악기', 'brown', '10', TO_DATE('03/01/2017','MM/DD/YYYY')); 
INSERT INTO instrument VALUES ('100018', '바이올린', '삼익악기', 'brown', '4', TO_DATE('03/11/2017','MM/DD/YYYY')); 
INSERT INTO instrument VALUES ('100019', '바이올린', '삼익악기', 'brown', '8', TO_DATE('03/21/2017','MM/DD/YYYY')); 
INSERT INTO instrument VALUES ('100020', '첼로', '삼익악기', 'brown', '7', TO_DATE('03/07/2017','MM/DD/YYYY')); 
INSERT INTO instrument VALUES ('100021', '기타', '영창악기', 'brown', '5', TO_DATE('03/07/2017','MM/DD/YYYY')); 
INSERT INTO instrument VALUES ('100022', '호른', '영창악기', 'gold', '5', TO_DATE('03/07/2017','MM/DD/YYYY')); 
 
commit;
 
CREATE TABLE supplier ( 
 sup_id            VARCHAR2(10),
 sup_name          VARCHAR2(20)  NOT  NULL,
 sup_phone         VARCHAR2(13)  NOT  NULL,
 sup_addr          VARCHAR2(30)  NOT  NULL,
 sup_grade         NUMBER(1),
CONSTRAINT  supplier_PK   PRIMARY KEY (sup_id),
CONSTRAINT  sup_grade
CHECK (sup_grade BETWEEN 0 and 5));
 

INSERT INTO supplier VALUES ('898900001', '최남영', '01018726978', '대전', 3); 
INSERT INTO supplier VALUES ('898900002', '이유리', '01010998019', '대전', 4); 
INSERT INTO supplier VALUES ('898900003', '이민선', '01012312111', '서울', 1); 
INSERT INTO supplier VALUES ('898900004', '박수향', '01022227863', '천안', 2); 
INSERT INTO supplier VALUES ('898900005', '김지희', '01028739493', '인천', 1); 
INSERT INTO supplier VALUES ('898900006', '임진주', '01028974292', '세종', 5); 
INSERT INTO supplier VALUES ('898900007', '임진원', '01099912874', '여수', 5); 
INSERT INTO supplier VALUES ('898900008', '조상우', '01055671248', '광주', 3); 
INSERT INTO supplier VALUES ('898900009', '조석준', '01056534292', '김해', 4); 
INSERT INTO supplier VALUES ('898900010', '채동신', '01019872348', '목포', 1); 
INSERT INTO supplier VALUES ('898900011', '김명수', '01077676822', '천안', 4); 
INSERT INTO supplier VALUES ('898900012', '이철준', '01067465846', '천안', 5); 
INSERT INTO supplier VALUES ('898900013', '김민정', '01037988229', '인천', 1); 
INSERT INTO supplier VALUES ('898900014', '김지혜', '01099898892', '세종', 1); 
INSERT INTO supplier VALUES ('898900015', '이수진', '01012342222', '수원', 4); 
INSERT INTO supplier VALUES ('898900016', '이영구', '01034433008', '세종', 5); 
INSERT INTO supplier VALUES ('898900017', '한지선', '01099098621', '세종', 3); 
INSERT INTO supplier VALUES ('898900018', '이승지', '01012283903', '천안', 2); 
INSERT INTO supplier VALUES ('898900019', '최수진', '01044875984', '구미', 3); 
INSERT INTO supplier VALUES ('898900020', '한소진', '01057353728', '서울', 3); 
INSERT INTO supplier VALUES ('898900021', '최희라', '01067489597', '천안', 4); 
 
commit; 
   
CREATE TABLE teacher ( 
 teac_id          VARCHAR2(10),
 teac_name        VARCHAR2(20)  NOT  NULL,
 teac_phone       VARCHAR2(13)  NOT  NULL,
 teac_addr        VARCHAR2(30),
 teac_grade       VARCHAR2(6),
CONSTRAINT  teacher_PK   PRIMARY KEY (teac_id),
CONSTRAINT teac_grade CHECK lect_grade IN ('best', 'good', 'bad'));
 
INSERT INTO teacher VALUES ('2017000001', '김창민', '01012333678', '천안', 'good'); 
INSERT INTO teacher VALUES ('2017000002', '김영숙', '01025421234', '천안', 'best'); 
INSERT INTO teacher VALUES ('2017000003', '이민아', '01025234123', '수원', 'good'); 
INSERT INTO teacher VALUES ('2017000004', '박정민', '01084673425', '전주', 'good'); 
INSERT INTO teacher VALUES ('2017000005', '홍순갑', '01023098178', '서울', 'good'); 
INSERT INTO teacher VALUES ('2017000006', '박신영', '01088787459', '대전', 'best');  
INSERT INTO teacher VALUES ('2017000007', '서효숙', '01011923874', '인천', 'good'); 
INSERT INTO teacher VALUES ('2017000008', '신진만', '01050982342', '수원', 'best'); 
INSERT INTO teacher VALUES ('2017000009', '김지원', '01012938732', '수원', 'good'); 
INSERT INTO teacher VALUES ('2017000010', '최남이', '01056278912', '전주', 'good'); 
INSERT INTO teacher VALUES ('2017000011', '유영수', '01057827861', '광주', 'best');  
INSERT INTO teacher VALUES ('2017000012', '임지석', '01013234909', '대전', 'good'); 
INSERT INTO teacher VALUES ('2017000013', '송미란', '01025345263', '천안', 'best'); 
INSERT INTO teacher VALUES ('2017000014', '김중의', '01026367463', '수원', 'good'); 
INSERT INTO teacher VALUES ('2017000015', '이영우', '01034523752', '서울', 'good'); 
INSERT INTO teacher VALUES ('2017000016', '김철수', '01098008234', '서울', 'good'); 
INSERT INTO teacher VALUES ('2017000017', '민소진', '01000123789', '서울', 'best');  
INSERT INTO teacher VALUES ('2017000018', '송아린', '01024569732', '청주', 'good'); 
INSERT INTO teacher VALUES ('2017000019', '양미리', '01099248756', '청주', 'best'); 
INSERT INTO teacher VALUES ('2017000020', '김소원', '01088664725', '수원', 'good'); 
INSERT INTO teacher VALUES ('2017000021', '김창수', '01017361821', '청주', 'good'); 
INSERT INTO teacher VALUES ('2017000022', '이민주', '01045778297', '인천', 'good'); 

commit; 
  
CREATE TABLE lecture ( 
 lec_id          VARCHAR2(10),
 lec_name        VARCHAR2(20)  NOT  NULL,
 lec_time       VARCHAR2(13)  NOT  NULL,
 lec_fee        VARCHAR2(30)  NOT  NULL,
CONSTRAINT  lecture_PK   PRIMARY KEY (lec_id));
 
INSERT INTO lecture VALUES ('2017010001', '첼로야 놀자 - 초급', '1시간 30분', '100000'); 
INSERT INTO lecture VALUES ('2017010002', '기타마스터 - 초급1', '2시간 00분', '120000'); 
INSERT INTO lecture VALUES ('2017010003', '기타마스터 - 초급2', '1시간 00분', '120000'); 
INSERT INTO lecture VALUES ('2017010004', '플룻의 세계 - 초급', '1시간 00분', '100000'); 
INSERT INTO lecture VALUES ('2017010005', '첼로야 놀자 - 중급', '1시간 30분', '150000'); 
INSERT INTO lecture VALUES ('2017010006', '첼로야 놀자 - 초급', '2시간 00분', '110000'); 
INSERT INTO lecture VALUES ('2017010007', '쉬운 피아노 - 초급', '1시간 30분', '130000'); 
INSERT INTO lecture VALUES ('2017010008', '쉬운 피아노 - 중급', '2시간 00분', '130000'); 
INSERT INTO lecture VALUES ('2017010009', '첼로야 놀자 - 고급', '2시간 00분', '150000'); 
INSERT INTO lecture VALUES ('2017010010', '기타마스터 - 중급1', '1시간 00분', '120000'); 
INSERT INTO lecture VALUES ('2017010011', '기타마스터 - 중급2', '1시간 30분', '80000'); 
INSERT INTO lecture VALUES ('2017010012', '기타마스터 - 고급', '1시간 00분', '100000'); 
INSERT INTO lecture VALUES ('2017010013', '쉬운피아노 - 고급', '1시간 30분', '110000'); 
INSERT INTO lecture VALUES ('2017010014', '바이올린과 - 초급', '2시간 00분', '120000'); 
INSERT INTO lecture VALUES ('2017010015', '바이올린과 - 중급', '2시간 00분', '80000'); 
INSERT INTO lecture VALUES ('2017010016', '바이올린과 - 고급', '1시간 00분', '120000'); 
INSERT INTO lecture VALUES ('2017010017', '첼로야 놀자 - 중급', '1시간 00분', '120000'); 
INSERT INTO lecture VALUES ('2017010018', '플룻의 세계 - 중급', '1시간 30분', '100000'); 
INSERT INTO lecture VALUES ('2017010019', '플룻의 세계 - 고급', '1시간 00분', '110000'); 
INSERT INTO lecture VALUES ('2017010020', '쉬운 피아노 - 초급', '2시간 00분', '140000'); 

commit;

CREATE TABLE repaircompany( 
 rep_id            VARCHAR2(10), 
 rep_comp_name     VARCHAR2(20)  NOT  NULL,
 rep_phone         VARCHAR2(13)  NOT  NULL,
 rep_addr          VARCHAR2(40),
 kind              VARCHAR2(20),
 rep_bus_name      VARCHAR2(20)  NOT  NULL,
CONSTRAINT  repaircompany_PK   PRIMARY KEY (rep_id));
 

INSERT INTO repaircompany VALUES ('500000001', '트리오현악기공방', '0415775416' , '충청남도 천안시 동남구 충절로 109'       , '현악기'  , '한희라'); 
INSERT INTO repaircompany VALUES ('500000002', '향복한악기사'    , '01042477931', '충청남도 천안시 서북구 쌍용대로 293'     , '현악기'  , '이명수'); 
INSERT INTO repaircompany VALUES ('500000003', '색소필리아'      , '0415781742' , '충청남도 천안시 서북구 서부대로 418'     , '색소폰'  , '최석준'); 
INSERT INTO repaircompany VALUES ('500000004', '세종악기'        , '0448632225' , '세종특별자치시 보듬3로 91 2층 212호'     , '관현악기', '전성수'); 
INSERT INTO repaircompany VALUES ('500000005', '세종영창영음악기', '0448688270' , '세종특별자치시 한누리대로 249 '          , '관현악기', '장준혁'); 
INSERT INTO repaircompany VALUES ('500000006', '영통악기'        , '0312543335' , '경기도 수원시 영통구 영통로 136'         , '피아노'  , '박봉구'); 
INSERT INTO repaircompany VALUES ('500000007', '모노종합악기'    , '03180038178', '경기도 화성시 동탄지성로 86'             , '피아노'  , '이창희'); 
INSERT INTO repaircompany VALUES ('500000008', '가인악기'        , '0432625333' , '충청북도 청주시 흥덕구 예체로167번길'    , '관악기'  , '조명수'); 
INSERT INTO repaircompany VALUES ('500000009', '에셀나무악기'    , '0448628720' , '세종특별자치시 아름서길 3'               , '관현악기', '한승지'); 
INSERT INTO repaircompany VALUES ('500000010', '용인종합피아노'  , '0313212166' , '경기도 용인시 처인구 금령로 32'          , '피아노'  , '김철수'); 
INSERT INTO repaircompany VALUES ('500000011', '크라운뮤직'      , '0313721077' , '경기도 화성시 동탄면 방교리 770-3'       , '바이올린', '이민수'); 
INSERT INTO repaircompany VALUES ('500000012', '로빈악기수리'    , '01030267406', '경기도 고양시 일산동구 정발산로42번길 60', '관악기'  , '김영재'); 
INSERT INTO repaircompany VALUES ('500000013', '서부피아노백화점', '023964141'  , '서울특별시 서대문구 통일로 465'          , '피아노'  , '김영태'); 
INSERT INTO repaircompany VALUES ('500000014', '동신악기'        , '0317111808' , '경기도 성남시 분당구 돌마로 361 동신코아', '현악기'  , '박조현'); 
INSERT INTO repaircompany VALUES ('500000015', '통기타이야기'    , '027627434'  , '서울특별시 마포구 양화로 50'             , '통기타'  , '이세현'); 
INSERT INTO repaircompany VALUES ('500000016', '뮤직마스터'      , '0422236399' , '대전광역시 중구 오류로 97-2'             , '클라리넷', '선우정'); 
INSERT INTO repaircompany VALUES ('500000017', '스노우뮤직'      , '025255597'  , '서울특별시 서초구 서초중앙로 40-6 우림'  , '관악기'  , '최수진'); 
INSERT INTO repaircompany VALUES ('500000018', '원미사운드'      , '07073132024', '경기도 부천시 부일로369번길 32 1층'      , '기타'    , '박원미'); 
INSERT INTO repaircompany VALUES ('500000019', '카운티스'        , '0027449879' , '서울특별시 송파구 삼전로9길 20 2층'      , '우쿨렐레', '한대영'); 
INSERT INTO repaircompany VALUES ('500000020', '브루노뮤직'      , '0267327753' , '서울특별시 종로구 낙원동 254-3 '         , '관현악기', '황동현'); 
INSERT INTO repaircompany VALUES ('500000021', '샤인기타'        , '0518180527' , '부산광역시 동래구 명륜로 144'            , '기타'    , '서종수'); 
 
commit; 

CREATE TABLE academy ( 
 acad_id            VARCHAR2(10),
 acad_name          VARCHAR2(20)  NOT NULL, 
 acad_phone         VARCHAR2(13)  NOT NULL, 
 acad_addr          VARCHAR2(40)  NOT NULL,
 acad_ledger        VARCHAR2(20)  NOT NULL,
 CONSTRAINT  academy_PK  PRIMARY KEY (acad_id)); 
 
INSERT INTO academy VALUES ('041001', '리틀프랜즈음악학원',      '0415588889',  '충청남도 천안시',   '변민주'); 
INSERT INTO academy VALUES ('041002', '칸타빌레 성인피아노', '01094041639', '충청남도 천안시',   '천조아'); 
INSERT INTO academy VALUES ('031001', '프레이즈실용음악학원',    '0316575728',  '경기도 평택시',     '박미림');  
INSERT INTO academy VALUES ('031002', '위드피아노',              '01039319374', '경기도 고양시',     '천소미'); 
INSERT INTO academy VALUES ('02001',  '서초실용음악학원',        '025375797',   '서울특별시 서초구', '한가윤'); 
INSERT INTO academy VALUES ('02002',  'SMMA아카데미',            '029794305',   '서울특별시 노원구', '지성리');  
INSERT INTO academy VALUES ('033001', '락앤비실용음악학원',      '0332622679',  '강원도 춘천시',     '채용섭'); 
INSERT INTO academy VALUES ('033002', '보컬세븐음악학원',        '0337447787',  '강원도 원주시',     '류희덕');  
INSERT INTO academy VALUES ('062001', '케이노트 뮤직',  '0629532902',  '광주광역시 광산구', '김옥자'); 
INSERT INTO academy VALUES ('062002', '라엘음악학원',            '0622677317',  '광주광역시 북구',   '채세종');  
INSERT INTO academy VALUES ('064001', 'TST뮤직아카데미',         '0647227570',  '제주특별자치도 제주시',     '윤미영'); 
INSERT INTO academy VALUES ('064002', '뮤밥실용음악학원',        '0647329876',  '제주특별자치도 서귀포시',   '탁배희');  
INSERT INTO academy VALUES ('044001', '행운음악학원',            '0448687239',  '세종특별자치시 새롬중앙로', '송희림'); 
INSERT INTO academy VALUES ('044002', '세종틴즈뮤지컬단',        '0448635671',  '세종특별자치시 달빛로',     '반재범'); 
INSERT INTO academy VALUES ('032001', '더재밌는음악학원',        '0325816633',  '인천광역시 서구',   '길흥민');  
INSERT INTO academy VALUES ('032002', '이지음악학원',            '0328659333',  '인천광역시 남구',   '함희선'); 
INSERT INTO academy VALUES ('042001', '대전중앙국악원',          '0424858760',  '대전광역시 서구',   '성대영');  
INSERT INTO academy VALUES ('042002', '숲의 음악 가야금레슨',    '01050424000', '대전광역시 유성구', '양지석'); 
INSERT INTO academy VALUES ('061001', '홍경자판소리교습소',      '612423310',   '전라남도 목포시',   '조대훈'); 
INSERT INTO academy VALUES ('061002', '그랜드뮤직아카데미',      '01046444002', '전라남도 순천시',   '심선아'); 
INSERT INTO academy VALUES ('052001', '온누리국악학원',          '0522566575',  '울산광역시 남구',   '공길호'); 
INSERT INTO academy VALUES ('052002', '우리소리우리마당',        '0522975871',  '울산광역시 중구',   '장윤희'); 


commit; 


CREATE TABLE place_of_residence( 
 place_id          VARCHAR2(10), 
 place_name        VARCHAR2(20) NOT NULL,
 place_phone       VARCHAR2(13) NOT NULL,
 place_addr        VARCHAR2(40),
CONSTRAINT place_of_residence_PK   PRIMARY KEY (place_id));
 			
INSERT INTO place_of_residence VALUES ('1002003000', '숨연습실', '01070001234', '천안'); 
INSERT INTO place_of_residence VALUES ('1022033001', '로데오연습실', '01073401234', '수원');
INSERT INTO place_of_residence VALUES ('1062053002', '할로스튜디오', '01070651334', '서울');
INSERT INTO place_of_residence VALUES ('1092073003', '라뮤직연습실', '01070001265', '대전');
INSERT INTO place_of_residence VALUES ('1022003004', '강남연습실', '01023001544', '서울');
INSERT INTO place_of_residence VALUES ('1052023005', 'SMMA', '01070001256', '안양');
INSERT INTO place_of_residence VALUES ('1012043006', '팔공산홀', '01072500124', '대구');
INSERT INTO place_of_residence VALUES ('1042073007', '아뜰리에247', '01045001453', '광주');
INSERT INTO place_of_residence VALUES ('1032003008', '너울음악연습실', '01070001234', '대구');
INSERT INTO place_of_residence VALUES ('1052043009', '사운드뮤직', '01070001289', '대전');
INSERT INTO place_of_residence VALUES ('1092033010', '아트리움', '01070001229', '청주');
INSERT INTO place_of_residence VALUES ('1072023011', '피아노앤클래식', '01070001214', '춘천');
INSERT INTO place_of_residence VALUES ('1062013012', '은하수홀', '01070001284', '강릉');
INSERT INTO place_of_residence VALUES ('1042063013', '베어스뮤직', '01070001464', '포천');
INSERT INTO place_of_residence VALUES ('1022043014', '문화와예술', '01074301344', '인천');
INSERT INTO place_of_residence VALUES ('1012023015', '기타앤보이스', '01074301134', '서울');
INSERT INTO place_of_residence VALUES ('1002003016', '글리사운드', '01070651544', '울산');
INSERT INTO place_of_residence VALUES ('1042043017', '숨고', '01070101134', '부산');
INSERT INTO place_of_residence VALUES ('1032003018', '한소리공간', '01070791544', '전주');
INSERT INTO place_of_residence VALUES ('1082093019', '무등산연습실', '01070681232', '광주'); 

commit; 



CREATE TABLE sheet_music ( 

music_id	VARCHAR2(10),
music_name	VARCHAR2(30)	NOT NULL,
play_instr	VARCHAR2(20)	NOT NULL,
music_diff	NUMBER(5),
music_genre	VARCHAR2(20)	NOT NULL,
perform_num	NUMBER(2),

CONSTRAINT sheet_music_PK   PRIMARY KEY(music_id));

INSERT INTO sheet_music VALUES ('1002007080', '쇼팽 녹턴 op.9no.2', '피아노', '5', '클래식', 3); 
INSERT INTO sheet_music VALUES ('3001007081', '우주를 줄께', '기타', '2', '가요', 1);
INSERT INTO sheet_music VALUES ('2002007080', '하울의 움직이는 성', '피아노', '3', 'OST', 3);
INSERT INTO sheet_music VALUES ('1003007084', '쇼팽 녹턴 op.9no.2', '클래식기타', '5', '클래식', 2);
INSERT INTO sheet_music VALUES ('4004007082', '라젠카', '드럼', '1', '락', 1); 
INSERT INTO sheet_music VALUES ('4001007082', '먼지가 되어', '기타', '2', '가요', 2); 
INSERT INTO sheet_music VALUES ('1004017035', '베토벤 교향곡 제 5번 c단조', '피콜로', '3', '클래식', 1); 
INSERT INTO sheet_music VALUES ('1004027435', '베토벤 교향곡 제 5번 c단조', '클라리넷', '3', '클래식', 2); 
INSERT INTO sheet_music VALUES ('1004037433', '베토벤 교향곡 제 5번 c단조', '오보에', '3', '클래식', 2); 
INSERT INTO sheet_music VALUES ('1004047031', '베토벤 교향곡 제 5번 c단조', '플룻', '3', '클래식', 2); 
INSERT INTO sheet_music VALUES ('1004057033', '베토벤 교향곡 제 5번 c단조', '파곳', '3', '클래식', 2); 
INSERT INTO sheet_music VALUES ('1004067045', '베토벤 교향곡 제 5번 c단조', '콘트라파곳', '3', '클래식', 1); 
INSERT INTO sheet_music VALUES ('1004077335', '베토벤 교향곡 제 5번 c단조', '호른', '3', '클래식', 2); 
INSERT INTO sheet_music VALUES ('4001017034', '라젠카', '일렉기타', '3', '락', 3); 
INSERT INTO sheet_music VALUES ('4004007012', '라젠카', '드럼', '4', '락', 1); 
INSERT INTO sheet_music VALUES ('8001027022', '실로암', '피아노', '1', '찬송가', 1);
INSERT INTO sheet_music VALUES ('9002007025', '땡벌', '피아노', '2', '성인가요', 1);
INSERT INTO sheet_music VALUES ('9009007021', '떙벌', '섹소폰', '3', '성인가요', 1);
INSERT INTO sheet_music VALUES ('3001012063', '좋니', '기타', '5', '가요', 4);
INSERT INTO sheet_music VALUES ('4001014973', '알루미늄', '일렉기타', '2', '락', 3);
commit; 


CREATE TABLE  수강하다 ( 
 mem_id             VARCHAR2(10), 
 lec_id             VARCHAR2(10), 
 sign_date	    DATE,
 CONSTRAINT  수강하다_PK   PRIMARY KEY (mem_id, lec_id, sign_date),
 CONSTRAINT  member_FK   FOREIGN KEY (mem_id)
                       REFERENCES  member(mem_id),
 CONSTRAINT  lecture_FK   FOREIGN KEY (lec_id)
                       REFERENCES  lecture(lec_id)); 

INSERT INTO 수강하다 VALUES ('1000', '2017010003', '20170302');
INSERT INTO 수강하다 VALUES ('1001', '2017010011', '20170608');
INSERT INTO 수강하다 VALUES ('1002', '2017010020', '20170122');
INSERT INTO 수강하다 VALUES ('1003', '2017010006', '20171002');
INSERT INTO 수강하다 VALUES ('1004', '2017010005', '20170311'); 
INSERT INTO 수강하다 VALUES ('1005', '2017010004', '20170318');
INSERT INTO 수강하다 VALUES ('1006', '2017010009', '20170402');
INSERT INTO 수강하다 VALUES ('1007', '2017010011', '20170225'); 
INSERT INTO 수강하다 VALUES ('1008', '2017010018', '20170411'); 
INSERT INTO 수강하다 VALUES ('1009', '2017010013', '20170703'); 
INSERT INTO 수강하다 VALUES ('1010', '2017010016', '20170713'); 
INSERT INTO 수강하다 VALUES ('1011', '2017010002', '20171111'); 
INSERT INTO 수강하다 VALUES ('1012', '2017010020', '20170505'); 
INSERT INTO 수강하다 VALUES ('1013', '2017010014', '20170706'); 
INSERT INTO 수강하다 VALUES ('1014', '2017010019', '20170123'); 
INSERT INTO 수강하다 VALUES ('1015', '2017010006', '20170608'); 
INSERT INTO 수강하다 VALUES ('1016', '2017010015', '20170224'); 
INSERT INTO 수강하다 VALUES ('1017', '2017010010', '20170228'); 
INSERT INTO 수강하다 VALUES ('1018', '2017010001', '20170625'); 
INSERT INTO 수강하다 VALUES ('1019', '2017010011', '20170728'); 
INSERT INTO 수강하다 VALUES ('1020', '2017010012', '20170830'); 
INSERT INTO 수강하다 VALUES ('1021', '2017010008', '20170221'); 
INSERT INTO 수강하다 VALUES ('1022', '2017010007', '20170915'); 
INSERT INTO 수강하다 VALUES ('1023', '2017010017', '20170627'); 
commit; 
 
CREATE TABLE  가입하다 ( 
 mem_id             VARCHAR2(10), 
 club_id             VARCHAR2(10), 
 joinn_date	    DATE,
 CONSTRAINT  가입하다_PK   PRIMARY KEY (mem_id, club_id),
 CONSTRAINT  member_FK   FOREIGN KEY (mem_id)
                       REFERENCES  member(mem_id),
 CONSTRAINT  club_FK   FOREIGN KEY (club_id)
                       REFERENCES  club(club_id)); 

INSERT INTO 가입하다 VALUES ('1000', 'vocal11');
INSERT INTO 가입하다 VALUES ('1001', 'singer00');
INSERT INTO 가입하다 VALUES ('1002', 'korchestra');
INSERT INTO 가입하다 VALUES ('1003', 'mypiano');
INSERT INTO 가입하다 VALUES ('1004', 'security48'); 
INSERT INTO 가입하다 VALUES ('1005', 'travel');
INSERT INTO 가입하다 VALUES ('1006', 'travel');
INSERT INTO 가입하다 VALUES ('1007', 'ilovesing'); 
INSERT INTO 가입하다 VALUES ('1008', 'orchestra'); 
INSERT INTO 가입하다 VALUES ('1009', 'basketball'); 
INSERT INTO 가입하다 VALUES ('1010', 'guitar1'); 
INSERT INTO 가입하다 VALUES ('1011', 'pianolove'); 
INSERT INTO 가입하다 VALUES ('1012', 'guitar1'); 
INSERT INTO 가입하다 VALUES ('1013', 'soccer22'); 
INSERT INTO 가입하다 VALUES ('1014', 'musical101'); 
INSERT INTO 가입하다 VALUES ('1015', 'security6'); 
INSERT INTO 가입하다 VALUES ('1016', 'vocal11'); 
INSERT INTO 가입하다 VALUES ('1017', 'security6'); 
INSERT INTO 가입하다 VALUES ('1018', 'book'); 
INSERT INTO 가입하다 VALUES ('1019', 'guitar4'); 
INSERT INTO 가입하다 VALUES ('1020', 'singer00'); 
INSERT INTO 가입하다 VALUES ('1021', 'mypiano'); 
INSERT INTO 가입하다 VALUES ('1022', 'ilovesing'); 
INSERT INTO 가입하다 VALUES ('1023', 'korchestra'); 
commit; 
 

CREATE TABLE  구입하다 ( 
 mem_id            VARCHAR2(10), 
 music_id         VARCHAR2(10),
 pur_date	DATE, 
 CONSTRAINT  구입하다_PK   PRIMARY KEY (mem_id, music_id, pur_date),
 CONSTRAINT  member_FK   FOREIGN KEY (mem_id)
                       REFERENCES  member(mem_id),
 CONSTRAINT  sheet_music_FK   	FOREIGN KEY (music_id)
                       		REFERENCES  sheet_music(music_id)); 
 
INSERT INTO 구입하다 VALUES ('1000', '1002007080', '20171123');
INSERT INTO 구입하다 VALUES ('1001', '3001007081', '20171122');
INSERT INTO 구입하다 VALUES ('1002', '2002007080', '20171123');
INSERT INTO 구입하다 VALUES ('1003', '1003007084', '20171126');
INSERT INTO 구입하다 VALUES ('1004', '4004007082', '20171127');
INSERT INTO 구입하다 VALUES ('1005', '4001007082', '20171123');
INSERT INTO 구입하다 VALUES ('1006', '1004017035', '20171127');
INSERT INTO 구입하다 VALUES ('1007', '1004027435', '20171129');
INSERT INTO 구입하다 VALUES ('1008', '1004037433', '20171121');
INSERT INTO 구입하다 VALUES ('1009', '1004047031', '20171122');
INSERT INTO 구입하다 VALUES ('1010', '1004057033', '20171127');
INSERT INTO 구입하다 VALUES ('1011', '1004067045', '20171126');
INSERT INTO 구입하다 VALUES ('1012', '1004077335', '20171127');
INSERT INTO 구입하다 VALUES ('1013', '4001017034', '20171127');
INSERT INTO 구입하다 VALUES ('1014', '4004007012', '20171123');
INSERT INTO 구입하다 VALUES ('1015', '8001027022', '20171127');
INSERT INTO 구입하다 VALUES ('1016', '9002007025', '20171122');
INSERT INTO 구입하다 VALUES ('1017', '9009007021', '20171127');
INSERT INTO 구입하다 VALUES ('1018', '3001012063', '20171121');
INSERT INTO 구입하다 VALUES ('1019', '4001014973', '20171127');

commit; 

CREATE TABLE  판매하다 ( 
 mem_id           VARCHAR2(10), 
 instr_id         VARCHAR2(10),
 order_date	DATE,
 order_quantity NUMBER(3),
  
 CONSTRAINT  판매하다_PK   PRIMARY KEY (mem_id, instr_id, order_date),
 CONSTRAINT  member_FK   FOREIGN KEY (mem_id)
                       REFERENCES  member(mem_id),
 CONSTRAINT  instrument_FK   FOREIGN KEY (instr_id)
                       REFERENCES  instrument(instr_id)); 
 
INSERT INTO 판매하다 VALUES ('1000', '100001', '20171121', 1);
INSERT INTO 판매하다 VALUES ('1001', '100002', '20171122', 1);
INSERT INTO 판매하다 VALUES ('1002', '100003', '20171123', 2);
INSERT INTO 판매하다 VALUES ('1003', '100004', '20171124', 1);
INSERT INTO 판매하다 VALUES ('1004', '100005', '20171121', 2);
INSERT INTO 판매하다 VALUES ('1005', '100006', '20171122', 1);
INSERT INTO 판매하다 VALUES ('1006', '100007', '20171121', 1);
INSERT INTO 판매하다 VALUES ('1007', '100008', '20171121', 3);
INSERT INTO 판매하다 VALUES ('1008', '100009', '20171121', 1);
INSERT INTO 판매하다 VALUES ('1009', '100010', '20171124', 3);
INSERT INTO 판매하다 VALUES ('1010', '100011', '20171121', 1);
INSERT INTO 판매하다 VALUES ('1011', '100012', '20171121', 1);
INSERT INTO 판매하다 VALUES ('1012', '100013', '20171126', 1);
INSERT INTO 판매하다 VALUES ('1013', '100014', '20171125', 2);
INSERT INTO 판매하다 VALUES ('1014', '100015', '20171126', 2);
INSERT INTO 판매하다 VALUES ('1015', '100016', '20171125', 1);
INSERT INTO 판매하다 VALUES ('1016', '100017', '20171121', 1);
INSERT INTO 판매하다 VALUES ('1017', '100018', '20171122', 4);
INSERT INTO 판매하다 VALUES ('1018', '100019', '20171122', 1);
INSERT INTO 판매하다 VALUES ('1019', '100020', '20171121', 9);

commit; 

CREATE TABLE  신청하다 ( 
 mem_id             VARCHAR2(10), 
 rep_id		    VARCHAR2(10), 
 apply_date         DATE,
 complete_date      DATE,
 kind               VARCHAR2(20),
 CONSTRAINT  신청하다_PK   PRIMARY KEY (mem_id, rep_id, apply_date),
 CONSTRAINT  member_FK     FOREIGN KEY (mem_id)
                           REFERENCES  member(mem_id),
 CONSTRAINT  repaircompany_FK   FOREIGN KEY (rep_id)
                                REFERENCES  repaircompany(rep_id)); 

INSERT INTO 신청하다 VALUES ('1000', '500000017', '20120217', '20120401', '플룻');
INSERT INTO 신청하다 VALUES ('1005', '500000001', '20120503', '20120823', '기타');
INSERT INTO 신청하다 VALUES ('1007', '500000021', '20120607', '20120705', '바이올린');
INSERT INTO 신청하다 VALUES ('1010', '500000015', '20121005', '20121121', '피아노');
INSERT INTO 신청하다 VALUES ('1015', '500000009', '20121230', '20130201', '피아노');
INSERT INTO 신청하다 VALUES ('1016', '500000005', '20130111', '20130501', '호른');
INSERT INTO 신청하다 VALUES ('1018', '500000007', '20130528', '20130620', '클라리넷');
INSERT INTO 신청하다 VALUES ('1020', '500000021', '20130822', '20140101', '트럼펫');
INSERT INTO 신청하다 VALUES ('1021', '500000011', '20131125', '20131222', '바이올린');
INSERT INTO 신청하다 VALUES ('1022', '500000008', '20140205', '20140328', '피아노');
INSERT INTO 신청하다 VALUES ('1000', '500000017', '20140217', '20140328', '기타');
INSERT INTO 신청하다 VALUES ('1005', '500000001', '20140505', '20140627', '트럼본');
INSERT INTO 신청하다 VALUES ('1007', '500000021', '20140623', '20140716', '첼로');
INSERT INTO 신청하다 VALUES ('1010', '500000015', '20140804', '20141010', '기타');
INSERT INTO 신청하다 VALUES ('1015', '500000009', '20150104', '20150404', '바이올린');
INSERT INTO 신청하다 VALUES ('1016', '500000005', '20150831', '20150930', '피아노');
INSERT INTO 신청하다 VALUES ('1018', '500000007', '20160119', '20160222', '비올라');
INSERT INTO 신청하다 VALUES ('1020', '500000021', '20160930', '20161111', '트럼본');
INSERT INTO 신청하다 VALUES ('1021', '500000011', '20170525', '20170702', '첼로');
INSERT INTO 신청하다 VALUES ('1022', '500000008', '20171111', '20180119', '피아노');


commit; 


CREATE TABLE  공급받다 ( 
 instr_id              VARCHAR2(10), 
 sup_id		       VARCHAR2(10), 
 supply_date           DATE,
 supply_quantity       NUMBER(3),
 CONSTRAINT  공급받다_PK     PRIMARY KEY (instr_id, sup_id, supply_date),
 CONSTRAINT  instrument_FK   FOREIGN KEY (instr_id)
                             REFERENCES  instrument(instr_id),
 CONSTRAINT  supplier_FK     FOREIGN KEY (sup_id)
                             REFERENCES  supplier(sup_id)); 

INSERT INTO 공급받다 VALUES ('100001', '898900001', '20120101', '200');
INSERT INTO 공급받다 VALUES ('100005', '898900019', '20120503', '100');
INSERT INTO 공급받다 VALUES ('100022', '898900021', '20120809', '500');
INSERT INTO 공급받다 VALUES ('100018', '898900005', '20121225', '400');
INSERT INTO 공급받다 VALUES ('100011', '898900002', '20130123', '300');
INSERT INTO 공급받다 VALUES ('100013', '898900018', '20130228', '200');
INSERT INTO 공급받다 VALUES ('100021', '898900009', '20130301', '400');
INSERT INTO 공급받다 VALUES ('100007', '898900007', '20130401', '300');
INSERT INTO 공급받다 VALUES ('100008', '898900020', '20130805', '50');
INSERT INTO 공급받다 VALUES ('100010', '898900017', '20140505', '300');
INSERT INTO 공급받다 VALUES ('100006', '898900016', '20140930', '50');
INSERT INTO 공급받다 VALUES ('100017', '898900004', '20150426', '10');
INSERT INTO 공급받다 VALUES ('100019', '898900008', '20150825', '200');
INSERT INTO 공급받다 VALUES ('100020', '898900020', '20151030', '300');
INSERT INTO 공급받다 VALUES ('100013', '898900014', '20151213', '200');
INSERT INTO 공급받다 VALUES ('100007', '898900013', '20160308', '500');
INSERT INTO 공급받다 VALUES ('100006', '898900002', '20160507', '100');
INSERT INTO 공급받다 VALUES ('100011', '898900009', '20161111', '100');
INSERT INTO 공급받다 VALUES ('100018', '898900007', '20170516', '200');
INSERT INTO 공급받다 VALUES ('100014', '898900020', '20170723', '10');

commit; 

CREATE TABLE  예약하다 ( 
 mem_id       VARCHAR2(10), 
 place_id     VARCHAR2(10),
 reserv_date  DATE,
 CONSTRAINT  예약하다_PK PRIMARY KEY (mem_id, place_id, reserv_date),
 CONSTRAINT  member_FK   FOREIGN KEY (mem_id)
                         REFERENCES  member(mem_id),
 CONSTRAINT  place_of_residence_FK   FOREIGN KEY (place_id)
                                     REFERENCES  place_of_residence(place_id)); 
 
INSERT INTO 예약하다 VALUES ('1000', '1002003000', TO_DATE('03/21/2017','MM/DD/YYYY'));
INSERT INTO 예약하다 VALUES ('1001', '1022033001', TO_DATE('04/26/2017','MM/DD/YYYY'));
INSERT INTO 예약하다 VALUES ('1002', '1062053002', TO_DATE('05/01/2017','MM/DD/YYYY'));
INSERT INTO 예약하다 VALUES ('1003', '1092073003', TO_DATE('05/11/2017','MM/DD/YYYY'));
INSERT INTO 예약하다 VALUES ('1004', '1032003018', TO_DATE('05/23/2017','MM/DD/YYYY'));
INSERT INTO 예약하다 VALUES ('1005', '1052023005', TO_DATE('06/21/2017','MM/DD/YYYY'));
INSERT INTO 예약하다 VALUES ('1006', '1032003008', TO_DATE('06/30/2017','MM/DD/YYYY'));
INSERT INTO 예약하다 VALUES ('1007', '1002003016', TO_DATE('07/11/2017','MM/DD/YYYY'));
INSERT INTO 예약하다 VALUES ('1008', '1032003008', TO_DATE('07/21/2017','MM/DD/YYYY'));
INSERT INTO 예약하다 VALUES ('1009', '1062053002', TO_DATE('07/23/2017','MM/DD/YYYY'));
INSERT INTO 예약하다 VALUES ('1010', '1092033010', TO_DATE('08/15/2017','MM/DD/YYYY'));
INSERT INTO 예약하다 VALUES ('1011', '1062053002', TO_DATE('08/13/2017','MM/DD/YYYY'));
INSERT INTO 예약하다 VALUES ('1012', '1092033010', TO_DATE('08/20/2017','MM/DD/YYYY'));
INSERT INTO 예약하다 VALUES ('1013', '1062013012', TO_DATE('08/22/2017','MM/DD/YYYY'));
INSERT INTO 예약하다 VALUES ('1014', '1062013012', TO_DATE('09/06/2017','MM/DD/YYYY'));
INSERT INTO 예약하다 VALUES ('1015', '1012023015', TO_DATE('09/10/2017','MM/DD/YYYY'));
INSERT INTO 예약하다 VALUES ('1016', '1002003016', TO_DATE('09/24/2017','MM/DD/YYYY'));
INSERT INTO 예약하다 VALUES ('1017', '1092033010', TO_DATE('10/01/2017','MM/DD/YYYY'));
INSERT INTO 예약하다 VALUES ('1018', '1012023015', TO_DATE('10/12/2017','MM/DD/YYYY'));
INSERT INTO 예약하다 VALUES ('1019', '1092033010', TO_DATE('10/21/2017','MM/DD/YYYY'));
INSERT INTO 예약하다 VALUES ('1020', '1032003018', TO_DATE('11/11/2017','MM/DD/YYYY'));
INSERT INTO 예약하다 VALUES ('1021', '1092033010', TO_DATE('11/13/2017','MM/DD/YYYY'));
INSERT INTO 예약하다 VALUES ('1022', '1082093019', TO_DATE('11/25/2017','MM/DD/YYYY'));
INSERT INTO 예약하다 VALUES ('1023', '1002003000', TO_DATE('11/27/2017','MM/DD/YYYY'));

commit; 


CREATE TABLE  개설하다 ( 
 acad_id      VARCHAR2(10), 
 lec_id       VARCHAR2(10),
 open_date    DATE,
 CONSTRAINT  개설하다_PK  PRIMARY KEY (acad_id, lec_id, open_date),
 CONSTRAINT  academy_FK   FOREIGN KEY (acad_id)
                          REFERENCES  academy(acad_id),
 CONSTRAINT  lecture_FK   FOREIGN KEY (lec_id)
                          REFERENCES  lecture(lec_id)); 
 
INSERT INTO 개설하다 VALUES ('041001', '2017010001', TO_DATE('01/21/2017','MM/DD/YYYY'));
INSERT INTO 개설하다 VALUES ('041001', '2017010002', TO_DATE('01/21/2017','MM/DD/YYYY'));
INSERT INTO 개설하다 VALUES ('041002', '2017010002', TO_DATE('01/26/2017','MM/DD/YYYY'));
INSERT INTO 개설하다 VALUES ('031001', '2017010003', TO_DATE('02/01/2017','MM/DD/YYYY'));
INSERT INTO 개설하다 VALUES ('031001', '2017010004', TO_DATE('02/01/2017','MM/DD/YYYY'));
INSERT INTO 개설하다 VALUES ('031001', '2017010005', TO_DATE('02/01/2017','MM/DD/YYYY'));
INSERT INTO 개설하다 VALUES ('031002', '2017010004', TO_DATE('02/11/2017','MM/DD/YYYY'));
INSERT INTO 개설하다 VALUES ('02001', '2017010005', TO_DATE('02/23/2017','MM/DD/YYYY'));
INSERT INTO 개설하다 VALUES ('02002', '2017010006', TO_DATE('03/21/2017','MM/DD/YYYY'));
INSERT INTO 개설하다 VALUES ('033001', '2017010007', TO_DATE('03/30/2017','MM/DD/YYYY'));
INSERT INTO 개설하다 VALUES ('033002', '2017010008', TO_DATE('04/11/2017','MM/DD/YYYY'));
INSERT INTO 개설하다 VALUES ('062001', '2017010001', TO_DATE('04/21/2017','MM/DD/YYYY'));
INSERT INTO 개설하다 VALUES ('062001', '2017010002', TO_DATE('04/21/2017','MM/DD/YYYY'));
INSERT INTO 개설하다 VALUES ('062001', '2017010003', TO_DATE('04/21/2017','MM/DD/YYYY'));
INSERT INTO 개설하다 VALUES ('062001', '2017010004', TO_DATE('04/21/2017','MM/DD/YYYY'));
INSERT INTO 개설하다 VALUES ('062001', '2017010009', TO_DATE('04/21/2017','MM/DD/YYYY'));
INSERT INTO 개설하다 VALUES ('062002', '2017010010', TO_DATE('04/23/2017','MM/DD/YYYY'));
INSERT INTO 개설하다 VALUES ('064001', '2017010011', TO_DATE('05/15/2017','MM/DD/YYYY'));
INSERT INTO 개설하다 VALUES ('064002', '2017010012', TO_DATE('05/13/2017','MM/DD/YYYY'));
INSERT INTO 개설하다 VALUES ('044001', '2017010013', TO_DATE('05/20/2017','MM/DD/YYYY'));
INSERT INTO 개설하다 VALUES ('044002', '2017010014', TO_DATE('05/22/2017','MM/DD/YYYY'));
INSERT INTO 개설하다 VALUES ('032001', '2017010015', TO_DATE('06/06/2017','MM/DD/YYYY'));
INSERT INTO 개설하다 VALUES ('032002', '2017010016', TO_DATE('06/10/2017','MM/DD/YYYY'));
INSERT INTO 개설하다 VALUES ('042001', '2017010017', TO_DATE('06/24/2017','MM/DD/YYYY'));
INSERT INTO 개설하다 VALUES ('042002', '2017010018', TO_DATE('07/01/2017','MM/DD/YYYY'));
INSERT INTO 개설하다 VALUES ('061001', '2017010019', TO_DATE('07/12/2017','MM/DD/YYYY'));
INSERT INTO 개설하다 VALUES ('061002', '2017010020', TO_DATE('07/21/2017','MM/DD/YYYY'));
INSERT INTO 개설하다 VALUES ('052001', '2017010020', TO_DATE('08/11/2017','MM/DD/YYYY'));
INSERT INTO 개설하다 VALUES ('052002', '2017010020', TO_DATE('08/13/2017','MM/DD/YYYY'));

commit;


CREATE TABLE  계약하다 ( 
 acad_id      VARCHAR2(10), 
 teac_id      VARCHAR2(10),
 cont_date    DATE,
 CONSTRAINT  계약하다_PK  PRIMARY KEY (acad_id, teac_id, cont_date),
 CONSTRAINT  academy_FK   FOREIGN KEY (acad_id)
                          REFERENCES  academy(acad_id),
 CONSTRAINT  teacher_FK   FOREIGN KEY (teac_id)
                          REFERENCES  teacher(teac_id)); 
 
INSERT INTO 계약하다 VALUES ('041001', '2017000001', TO_DATE('01/20/2017','MM/DD/YYYY'));
INSERT INTO 계약하다 VALUES ('041001', '2017000002', TO_DATE('01/20/2017','MM/DD/YYYY'));
INSERT INTO 계약하다 VALUES ('041002', '2017000002', TO_DATE('01/24/2017','MM/DD/YYYY'));
INSERT INTO 계약하다 VALUES ('031001', '2017000003', TO_DATE('02/01/2017','MM/DD/YYYY'));
INSERT INTO 계약하다 VALUES ('031001', '2017000004', TO_DATE('02/02/2017','MM/DD/YYYY'));
INSERT INTO 계약하다 VALUES ('031001', '2017000005', TO_DATE('02/05/2017','MM/DD/YYYY'));
INSERT INTO 계약하다 VALUES ('031002', '2017000004', TO_DATE('02/16/2017','MM/DD/YYYY'));
INSERT INTO 계약하다 VALUES ('02001', '2017000005', TO_DATE('02/20/2017','MM/DD/YYYY'));
INSERT INTO 계약하다 VALUES ('02002', '2017000006', TO_DATE('03/20/2017','MM/DD/YYYY'));
INSERT INTO 계약하다 VALUES ('033001', '2017000007', TO_DATE('03/25/2017','MM/DD/YYYY'));
INSERT INTO 계약하다 VALUES ('033002', '2017000008', TO_DATE('04/10/2017','MM/DD/YYYY'));
INSERT INTO 계약하다 VALUES ('062001', '2017000001', TO_DATE('04/20/2017','MM/DD/YYYY'));
INSERT INTO 계약하다 VALUES ('062001', '2017000002', TO_DATE('04/20/2017','MM/DD/YYYY'));
INSERT INTO 계약하다 VALUES ('062001', '2017000003', TO_DATE('04/20/2017','MM/DD/YYYY'));
INSERT INTO 계약하다 VALUES ('062001', '2017000004', TO_DATE('04/20/2017','MM/DD/YYYY'));
INSERT INTO 계약하다 VALUES ('062001', '2017000009', TO_DATE('04/25/2017','MM/DD/YYYY'));
INSERT INTO 계약하다 VALUES ('062002', '2017000010', TO_DATE('04/26/2017','MM/DD/YYYY'));
INSERT INTO 계약하다 VALUES ('064001', '2017000011', TO_DATE('05/10/2017','MM/DD/YYYY'));
INSERT INTO 계약하다 VALUES ('064002', '2017000012', TO_DATE('05/10/2017','MM/DD/YYYY'));
INSERT INTO 계약하다 VALUES ('044001', '2017000013', TO_DATE('05/15/2017','MM/DD/YYYY'));
INSERT INTO 계약하다 VALUES ('044002', '2017000014', TO_DATE('05/24/2017','MM/DD/YYYY'));
INSERT INTO 계약하다 VALUES ('032001', '2017000015', TO_DATE('06/05/2017','MM/DD/YYYY'));
INSERT INTO 계약하다 VALUES ('032002', '2017000016', TO_DATE('06/06/2017','MM/DD/YYYY'));
INSERT INTO 계약하다 VALUES ('042001', '2017000017', TO_DATE('06/20/2017','MM/DD/YYYY'));
INSERT INTO 계약하다 VALUES ('042002', '2017000018', TO_DATE('07/01/2017','MM/DD/YYYY'));
INSERT INTO 계약하다 VALUES ('061001', '2017000019', TO_DATE('07/10/2017','MM/DD/YYYY'));
INSERT INTO 계약하다 VALUES ('061002', '2017000020', TO_DATE('07/22/2017','MM/DD/YYYY'));
INSERT INTO 계약하다 VALUES ('052001', '2017000021', TO_DATE('08/15/2017','MM/DD/YYYY'));
INSERT INTO 계약하다 VALUES ('052002', '2017000022', TO_DATE('08/15/2017','MM/DD/YYYY'));

commit;

set scan on 