library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.all; 

entity KYGLJY_Robot is
port (IR1_input, IR2_input, clk, HS_Echo : in std_logic;
		STM1_output, STM2_output : out std_logic_vector(3 downto 0);
		SBM_output, HS_Trigger : out std_logic;
		ThisState : out std_logic_vector(5 downto 0)
		);
end KYGLJY_Robot;

architecture main of KYGLJY_Robot is
	type states is (S1, S2, S3, S4, S5, S6);
	signal RobotState : states;
	signal InputState : integer;
	--input signal
	signal HS_Distance : std_logic_vector(7 downto 0);
	signal IR1, IR2 : std_logic;
	--out signal
	signal SBM_Sig : std_logic := '0';
	signal STM_Sig : integer := 0;
	signal tclk : std_logic := '0';
	
--component
	--SubMotor
	component HS311 is
			port( clk, dir : in std_logic;
             	 q : out std_logic);
	end component; 	
	
	--IR_Sensor
	component IR_Sensor is
		port( clk : in std_logic; -- Clock signal
				sig : in std_logic;
				y_out : out std_logic); -- Low logic interrupt output
	end component;
	
	--US Sensor
	component HCSR04 is
     	port( clk, Echo : in std_logic;
            Triger : out std_logic;
				Di : out std_logic_vector(7 downto 0));
	end component;
	
	--Step Motor Movement
	component movement is
        port( clock : in std_logic;
              m_state : in integer;
              q1, q2 : out std_logic_vector(3 downto 0));
	end component;
	
begin

	--use sensor component
	u1 : IR_Sensor port map(clk, IR1_input, IR1);
	u2 : IR_Sensor port map(clk, IR2_input, IR2);
	u3 : HCSR04 port map(clk, HS_Echo, HS_Trigger, HS_Distance);
	
	--determine Input state--------------------------------------------------
	Sensor_input : process(clk)
		variable m : integer;
	begin
		if (rising_edge(clk)) then
					if m>= 500000 then
						m := 0;
						tclk <= not tclk;
					else
						m := m+1;
					end if;
				end if;
	end process;
	
	--------------tclk use state------------------------------------------------
	pdevicestate : process(tclk)
		variable S_out : integer;
	begin
			if((IR1 = '1') and (IR2 = '0')) then
				S_out := 4;
			elsif((IR1 = '0') and (IR2 = '1')) then
				S_out := 5;
			
			elsif(HS_Distance = "00100000" or HS_Distance = "00010000") then
				S_out := 1;
			elsif(HS_Distance = "00001000" or HS_Distance = "00000100") then
				S_out := 2;
			elsif(HS_Distance = "00000010" or HS_Distance = "00000001") then
				S_out := 3;
			
			else
				S_out := 6;
			end if;
		
			InputState <= S_out;
	
	-- HS ditance print
	-- STM_output is output for step motor state print
	-- but we did't use st_motor. so we use for HS distance print 
	STM2_output(3) <= HS_Distance(7);
	STM2_output(2) <= HS_Distance(6);
	STM2_output(1) <= HS_Distance(5);
	STM2_output(0) <= HS_Distance(4);
	STM1_output(3) <= HS_Distance(3);
	STM1_output(2) <= HS_Distance(2);
	STM1_output(1) <= HS_Distance(1);
	STM1_output(0) <= HS_Distance(0);
	end process;
	
	--determine State-----------------------------------------------------------
	What_State : process(InputState)
	begin
		if InputState = 1 then
			RobotState <= S1;
		elsif InputState = 2 then
			RobotState <= S2;
		elsif InputState = 3 then
			RobotState <= S3;
		elsif InputState = 4 then
			RobotState <= S4;
		elsif InputState = 5 then
			RobotState <= S5;
		else 
			RobotState <= S6;
		end if;
	end process;
	------------state - play-------------------------------------------------------
	State_play : process(clk,RobotState)
	variable count : integer := 0;
	begin
	
	if rising_edge(clk) then
		count := count + 1;
	end if;
	
		if RobotState = S3 then
		--StepMotor stop
			SBM_Sig <= '0';
			STM_Sig <= 5;
			ThisState <= "000111";
		count := 0;
		elsif RobotState = S1 then
		--StopMotor slowgo
			SBM_Sig <= '1';
			STM_Sig <= 0;
			ThisState <= "000001";
		elsif RobotState = S2 then
		--StopMotor go
			SBM_Sig <= '1';
			STM_Sig <= 1;
			ThisState <= "000011";
		elsif RobotState = S4 then
		--StopMotor left
			SBM_Sig <= '1';
			STM_Sig <= 3;
			ThisState <= "001111";
		elsif RobotState = S5 then
		--StopMotor right
			SBM_Sig <= '1';
			STM_Sig <= 4;
			ThisState <= "011111";
		else
		--StopMotor left (find enemy)
			SBM_Sig <= '1';
			STM_Sig <= 3;
			ThisState <= "111111";
		end if;
	end process;
	
	-- motor control
	u4 : HS311 port map(clk, SBM_Sig,SBM_output);
	--u5 : movement port map(clk, 1, STM1_output, STM2_output);
	
end main;