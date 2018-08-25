library ieee;
use ieee.std_logic_1164.all;

entity and2test is						-- 하드웨서 블록 이름 and2
	port(a, b : in bit;			-- port 신호 : a, b는 입력, bit형
				y : out bit);		-- y는 출력, bit형
end and2test;							-- and2의 끝

architecture sample of and2test is	-- and2의 회로 구성의 이름 : sample
	begin									-- 내용의 시작
	y <= a and b;						-- y에 a and b를 대입
end sample;								-- sample의 끝