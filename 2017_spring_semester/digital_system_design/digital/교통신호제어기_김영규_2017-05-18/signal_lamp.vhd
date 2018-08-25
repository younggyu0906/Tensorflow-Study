library ieee;
use ieee.std_logic_1164.all;

entity signal_lamp is
port( reset, clk : in std_logic;
		-- 신호등의 비트는 순서대로 0번째 비트부터 빨강, 초록, 좌회전, 노랑, 횡단보도의 순이다. lamp(0)=빨강,lamp(4)=횡단보도
		xlamp0, xlamp1, xlamp2, xlamp3 : out std_logic_vector(4 downto 0);	-- 교차로 x의 신호등
		ylamp0, ylamp1, ylamp2, ylamp3 : out std_logic_vector(4 downto 0));	-- 교차로 y의 신호등
end signal_lamp;

architecture sample of signal_lamp is
	Type s_states is (s0, s1, s2, s3);	-- 교차로의 도로 0,1,2,3
	Type l_states is (l0, l1, l2);		-- 신호등의 상태 (빨강, 초록&좌회전, 노랑)
	signal s_state : s_states;
	signal l_state : l_states;
	
	begin
		p1 : process(clk, reset)			-- 사거리에서 도로의 상태 process
		variable i : integer := 0;			-- 클락 타이밍 제어를 위한 변수

		begin
			if reset='1' then
				s_state <= s1;
			elsif rising_edge(clk) then	-- 클락이 상승에지일 때
				i := i + 1;
				if (i mod 3 = 0) then		-- 클락이 세번마다
				case s_state is				-- 도로의 상태 변화
					when s0 => s_state <= s1;
					when s1 => s_state <= s2;
					when s2 => s_state <= s3;
					when s3 => s_state <= s0;
					end case;
				end if;
			end if;
			end process;
			
		p2 : process(clk, l_state)			-- 한 도로의 신호등 상태 process
		begin
				if rising_edge(clk) then	-- 클락이 상승에지일 때
					case l_state is			-- 신호등의 상태 변화
						when l0 => l_state <= l1;
						when l1 => l_state <= l2;
						when l2 => l_state <= l0;
						end case;
				end if;
			end process;
		
		p3 : process(s_state, l_state)
		begin
			xlamp0 <= "10000";
			xlamp1 <= "10000";
			xlamp2 <= "10000";
			xlamp3 <= "10000";
			ylamp0 <= "10000";
			ylamp1 <= "10000";
			ylamp2 <= "10000";
			ylamp3 <= "10000";
			
			case s_state is
				when s0 =>
					case l_state is
						when l0 =>
							xlamp0 <= "10000";
							ylamp0 <= "10000";
						when l1 =>
							xlamp0 <= "01100"; 
							xlamp1 <= "10001";
							ylamp0 <= "01100"; 
							ylamp1 <= "10001";
						when l2 => 
							xlamp0 <= "00010";
							ylamp0 <= "00010";
					end case;
				when s1 =>
					case l_state is
						when l0 => 
							xlamp1 <= "10000";
							ylamp1 <= "10000";
						when l1 =>
							xlamp1 <= "01100"; 
							xlamp2 <= "10001";
							ylamp1 <= "01100"; 
							ylamp2 <= "10001";
						when l2 => 
							xlamp1 <= "00010";
							ylamp1 <= "00010";
					end case;
				when s2 =>
					case l_state is
						when l0 =>
							xlamp2 <= "10000";
							ylamp2 <= "10000";
						when l1 =>
							xlamp2 <= "01100"; 
							xlamp3 <= "10001";
							ylamp2 <= "01100"; 
							ylamp3 <= "10001";
						when l2 => 
							xlamp2 <= "00010";
							ylamp2 <= "00010";
					end case;
				when s3 =>
					case l_state is
						when l0 =>
							xlamp3 <= "10000";
							ylamp3 <= "10000";
						when l1 =>
							xlamp3 <= "01100"; 
							xlamp0 <= "10001";
							ylamp3 <= "01100"; 
							ylamp0 <= "10001";
						when l2 => 
							xlamp3 <= "00010";
							ylamp3 <= "00010";
					end case;
				end case;
			end process;
end sample;