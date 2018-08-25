library ieee;
use ieee.std_logic_1164.all;
entity laundry is
	port( clk, l_start, pollution : in std_logic;
			-- 클락, 시작, 오염여부
         l_stop, wash, rinse, dewater, waterSupply, spin, drainage : out std_logic);
			-- 세탁기의 네가지 상태 (정지, 세탁, 헹굼, 탈수), 세탁기 동작의 세가지 상태(급수, 회전, 탈수)
end laundry;

architecture sample of laundry is
	Type l_states is (l0, l1, l2, l3);	-- 세탁기의 네 가지 상태 타입
	Type w_states is (w0, w1, w2, w3);	-- 세탁기 동작의 네 가지 상태 타입
  	
	signal l_state : l_states;
	signal w_state : w_states;

	begin
      p1 : process(clk, l_start, pollution)	-- 세탁기 네가지 상태 순서에 대한 process
		variable i : integer := 0;					-- 클락 네 번당 동작변화를 위한 변수
		begin
			if rising_edge(clk) then	-- 클락이 상승에지일 때
				i := i + 1;
				if (i mod 4 = 0) then
					case l_state is
						when l0 => 
							if l_start = '1' then
								l_state <= l1;
							else
								l_state <= l0;
							end if;
						when l1 =>
							if pollution = '1' then
								l_state <= l1;
							else
								l_state <= l2;
							end if;
						when l2 => l_state <= l3;
						when l3 => l_state <= l0;
						end case;
					end if;
				end if;
			end process;
			
		p2 : process(clk, w_state, l_start)	-- 세탁기 동작의 네가지 순서에 대한 process
		variable x : std_logic := '0';		-- 세탁이 시작되었는지의 여부 판별을 위한 변수
		begin
			if l_start = '1' then
				x := '1';
			end if;
			if rising_edge(clk) then	-- 클락이 상승에지일 때
				case w_state is
					when w0 => 
						if x = '0' then
							w_state <= w0;
						else
							w_state <= w1;
						end if;
					when w1 => w_state <= w2;
					when w2 => w_state <= w3;
					when w3 => w_state <= w0;
					end case;
				end if;
			end process;
		
		p3 : process(l_state, w_state)
		begin
			waterSupply <= '0';
			spin <= '0';
			drainage <= '0';
			l_stop <= '0';
			wash <= '0';
			rinse <= '0';
			dewater <= '0';
			
			case l_state is
				when l0 =>
					l_stop <= '1';
					waterSupply <= '0';
					spin <= '0';
					drainage <= '0';
				when l1 =>
					wash <= '1';
					case w_state is
						when w0 =>
							waterSupply <= '0';
							spin <= '0';
							drainage <= '0';
						when w1 =>
							waterSupply <= '1';
						when w2 =>
							spin <= '1';
						when w3 =>
							drainage <= '1';
					end case;
				when l2 =>
					rinse <= '1';
					case w_state is
						when w0 =>
							waterSupply <= '0';
							spin <= '0';
							drainage <= '0';
						when w1 =>
							waterSupply <= '1';
						when w2 =>
							spin <= '1';
						when w3 =>
							drainage <= '1';
					end case;
				when l3 =>
					dewater <= '1';
					waterSupply <= '0';
					spin <= '0';
					drainage <= '0';
				end case;
			end process;
end sample;