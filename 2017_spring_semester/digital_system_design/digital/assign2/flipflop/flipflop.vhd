library ieee;
use ieee.std_logic_1164.all;
entity d_flip is
	port( clk, x, reset : in std_logic;
                     y : out std_logic_vector(2 downto 0) );
end moore_2p;
  
architecture sample of moore_2p is
	type states is (s0, s1, s2, s3);
  		signal state : states;  
      begin
      	p1 : process(reset, clk)  
             	begin   
                	if reset='1' then  
                  		state <= s0;
                	elsif clk'event and clk='1' then
                    	case state is
                      	when s0 => 
                         		if  x='1'  then
                           			state <= s1;
                         		end if;
y <= "000"; -- P2 대신 추가동작[H/W]
                      	when s1 => 
                         		if  x='0'  then
                           			state <= s2;
                         		end if;
	              		when s2 => 
                         		if  x='1'  then
                           			state <= s3;
                         		end if;
                      	when s3 => 
                         		if  x='0'  then
                           			state <= s0;
                         		end if;
                   	end case;
               	end if;
       	end process; 

  		p2 : process(state)  -- 출력이 클럭에 의한 비동기 상태 구성
   		begin   
          		case state is
             			when s0 => 
                			y <= "000";
            	 		when s1 => 
                			y <= "001";
             			when s2 => 
                			y <= "011";
             			when s3 => 
                			y <= "111";
          		end case;
       	end process; 
end sample;