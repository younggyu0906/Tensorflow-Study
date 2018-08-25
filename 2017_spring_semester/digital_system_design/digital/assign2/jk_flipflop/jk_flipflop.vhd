library ieee;
use ieee.std_logic_1164.all;

entity jk_flipflop is
	port( clk, j, k, pr, clr : in std_logic;
                    y_out : buffer std_logic);
end jk_flipflop;

architecture sample of jk_flipflop is
	type states is(s0, s1, s2, s3);
	signal state : states;
begin
	process(clk,pr,clr)    	-- 감지신호 리스트에 clock과 비동기 신호 나열
     	begin
     		if(pr = '0') then
				y_out <= '1';
	   	elsif(clr = '0') then 
				y_out <= '0';
         elsif (clk'event and clk='1') then
            case state is
					when s1 =>
						if (j ='1' and k='0') then
	                	y_out  <= '1' ;
						end if;
					when s2 =>
						if(j='0' and k='1') then
	                	y_out <= '0';
						end if;
					when s3 =>
						if(j='1' and k='1') then
	                	y_out <= not(y_out);
						end if;
					when s0 =>
						if(j='0' and k='0') then
							y_out <= y_out;
						end if;
				end case;
         end if; 
    	end process;
		
--		p2 : process(state)
--		begin
--			case state is
--				when s1 =>
--					y_out  <= '1' ;
--				when s2 =>
--				 	y_out <= '0';
--				when s3 =>
--		       	y_out <= not(y_out);
end sample;