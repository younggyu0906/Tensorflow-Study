 library ieee;
 use ieee.std_logic_1164.all;
 use ieee.std_logic_unsigned.all;
 entity stepmotor is
        port( clk, reset, dir, stop_start   : in std_logic;
               a : in integer;
              q       : out std_logic_vector( 3 downto 0 ) );
 end stepmotor;
 
 architecture sample of stepmotor is
          type states is (s0, s1, s2, s3);
          signal state : states;
          signal tc : std_logic_vector(7 downto 0);
          signal tclk : std_logic;
 begin
          clock : process(clk)
        begin
             if (clk'event and clk ='1') then
                     tc <= tc +1;
           tclk <= tc(a);
        end if;
          end process;
    step : process(tclk)
        begin
             if reset = '1' then
                    state <= s0;
                    q <= "1110";
             elsif (tclk'event and tclk ='1') then
               if stop_start = '0' then 
                     if dir = '1' then
                           case state is 
                               when s0 =>
                                      state <= s1;
                                      q <= "1101";  
                               when s1 =>
                                      state <= s2;
                                      q <= "1011";
                               when s2 =>
                                      state <= s3;
                                      q <= "0111";
                               when s3 =>
                                      state <= s0;
                                      q <= "1110";
                           end case;
                       else
                           case state is
                              when s0 =>
                                      state <= s3;
                                      q <= "0111";  
                               when s1 =>
                                      state <= s0;
                                      q <= "1110";
                               when s2 =>
                                      state <= s1;
                                      q <= "1101";
                               when s3 =>
                                      state <= s2;
                                      q <= "1011";
                           end case;
                       end if;
                 end if;
      end if;
          end process;
  end sample;