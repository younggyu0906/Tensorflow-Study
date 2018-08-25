-- Copyright (C) 1991-2013 Altera Corporation
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, Altera MegaCore Function License 
-- Agreement, or other applicable license agreement, including, 
-- without limitation, that your use is for the sole purpose of 
-- programming logic devices manufactured by Altera and sold by 
-- Altera or its authorized distributors.  Please refer to the 
-- applicable agreement for further details.

-- VENDOR "Altera"
-- PROGRAM "Quartus II 64-Bit"
-- VERSION "Version 13.0.1 Build 232 06/12/2013 Service Pack 1 SJ Web Edition"

-- DATE "06/17/2017 14:40:05"

-- 
-- Device: Altera EP4CE6F17C8 Package FBGA256
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY ALTERA;
LIBRARY CYCLONEIVE;
LIBRARY IEEE;
USE ALTERA.ALTERA_PRIMITIVES_COMPONENTS.ALL;
USE CYCLONEIVE.CYCLONEIVE_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	KYGLJY_Robot IS
    PORT (
	IR1_input : IN std_logic;
	IR2_input : IN std_logic;
	clk : IN std_logic;
	HS_Echo : IN std_logic;
	STM1_output : OUT std_logic_vector(3 DOWNTO 0);
	STM2_output : OUT std_logic_vector(3 DOWNTO 0);
	SBM_output : OUT std_logic;
	HS_Trigger : OUT std_logic
	);
END KYGLJY_Robot;

-- Design Ports Information
-- STM1_output[0]	=>  Location: PIN_F11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- STM1_output[1]	=>  Location: PIN_A15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- STM1_output[2]	=>  Location: PIN_A10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- STM1_output[3]	=>  Location: PIN_B10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- STM2_output[0]	=>  Location: PIN_C9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- STM2_output[1]	=>  Location: PIN_D9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- STM2_output[2]	=>  Location: PIN_E9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- STM2_output[3]	=>  Location: PIN_A9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- SBM_output	=>  Location: PIN_J15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- HS_Trigger	=>  Location: PIN_L14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- HS_Echo	=>  Location: PIN_J11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- IR2_input	=>  Location: PIN_R16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- IR1_input	=>  Location: PIN_K12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- clk	=>  Location: PIN_E15,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF KYGLJY_Robot IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_IR1_input : std_logic;
SIGNAL ww_IR2_input : std_logic;
SIGNAL ww_clk : std_logic;
SIGNAL ww_HS_Echo : std_logic;
SIGNAL ww_STM1_output : std_logic_vector(3 DOWNTO 0);
SIGNAL ww_STM2_output : std_logic_vector(3 DOWNTO 0);
SIGNAL ww_SBM_output : std_logic;
SIGNAL ww_HS_Trigger : std_logic;
SIGNAL \u5|u1|tclk~clkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \u5|u2|tclk~clkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \clk~inputclkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \u4|clock:m[31]~q\ : std_logic;
SIGNAL \u4|clock:m[3]~q\ : std_logic;
SIGNAL \u4|clock:m[13]~q\ : std_logic;
SIGNAL \u4|clock:m[19]~q\ : std_logic;
SIGNAL \u4|clock:m[21]~q\ : std_logic;
SIGNAL \u4|clock:m[30]~q\ : std_logic;
SIGNAL \u3|TrigerOut:m[31]~q\ : std_logic;
SIGNAL \u3|TrigerOut:m[3]~q\ : std_logic;
SIGNAL \u3|TrigerOut:m[15]~q\ : std_logic;
SIGNAL \u3|TrigerOut:m[21]~q\ : std_logic;
SIGNAL \u3|TrigerOut:m[27]~q\ : std_logic;
SIGNAL \u4|clock:m[3]~1_combout\ : std_logic;
SIGNAL \u4|clock:m[13]~1_combout\ : std_logic;
SIGNAL \u4|clock:m[19]~1_combout\ : std_logic;
SIGNAL \u4|clock:m[21]~1_combout\ : std_logic;
SIGNAL \u4|clock:m[29]~2\ : std_logic;
SIGNAL \u4|clock:m[30]~1_combout\ : std_logic;
SIGNAL \u4|clock:m[30]~2\ : std_logic;
SIGNAL \u4|clock:m[31]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[3]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[15]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[21]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[27]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[30]~2\ : std_logic;
SIGNAL \u3|TrigerOut:m[31]~1_combout\ : std_logic;
SIGNAL \u5|u1|tc[1]~4_combout\ : std_logic;
SIGNAL \u5|u1|tc[3]~8_combout\ : std_logic;
SIGNAL \u4|LessThan0~0_combout\ : std_logic;
SIGNAL \u4|LessThan0~4_combout\ : std_logic;
SIGNAL \u3|LessThan0~7_combout\ : std_logic;
SIGNAL \HS_Echo~input_o\ : std_logic;
SIGNAL \IR2_input~input_o\ : std_logic;
SIGNAL \IR1_input~input_o\ : std_logic;
SIGNAL \STM1_output[0]~output_o\ : std_logic;
SIGNAL \STM1_output[1]~output_o\ : std_logic;
SIGNAL \STM1_output[2]~output_o\ : std_logic;
SIGNAL \STM1_output[3]~output_o\ : std_logic;
SIGNAL \STM2_output[0]~output_o\ : std_logic;
SIGNAL \STM2_output[1]~output_o\ : std_logic;
SIGNAL \STM2_output[2]~output_o\ : std_logic;
SIGNAL \STM2_output[3]~output_o\ : std_logic;
SIGNAL \SBM_output~output_o\ : std_logic;
SIGNAL \HS_Trigger~output_o\ : std_logic;
SIGNAL \u5|u1|tc[0]~12_combout\ : std_logic;
SIGNAL \u5|u1|tc[1]~5\ : std_logic;
SIGNAL \u5|u1|tc[2]~6_combout\ : std_logic;
SIGNAL \u5|u1|tc[2]~7\ : std_logic;
SIGNAL \u5|u1|tc[3]~9\ : std_logic;
SIGNAL \u5|u1|tc[4]~10_combout\ : std_logic;
SIGNAL \u5|u1|tclk~feeder_combout\ : std_logic;
SIGNAL \u5|u1|tclk~q\ : std_logic;
SIGNAL \u5|u1|tclk~clkctrl_outclk\ : std_logic;
SIGNAL \u5|u1|state.s0~0_combout\ : std_logic;
SIGNAL \u5|u1|state.s0~q\ : std_logic;
SIGNAL \u5|u1|state.s1~0_combout\ : std_logic;
SIGNAL \u5|u1|state.s1~q\ : std_logic;
SIGNAL \u5|u1|state.s2~feeder_combout\ : std_logic;
SIGNAL \u5|u1|state.s2~q\ : std_logic;
SIGNAL \u5|u1|state.s3~feeder_combout\ : std_logic;
SIGNAL \u5|u1|state.s3~q\ : std_logic;
SIGNAL \u5|u1|q[0]~0_combout\ : std_logic;
SIGNAL \u5|u1|q[1]~feeder_combout\ : std_logic;
SIGNAL \u5|u1|q[2]~1_combout\ : std_logic;
SIGNAL \u5|u1|q[3]~2_combout\ : std_logic;
SIGNAL \u5|u2|tclk~feeder_combout\ : std_logic;
SIGNAL \u5|u2|tclk~q\ : std_logic;
SIGNAL \u5|u2|tclk~clkctrl_outclk\ : std_logic;
SIGNAL \u5|u2|state.s0~0_combout\ : std_logic;
SIGNAL \u5|u2|state.s0~q\ : std_logic;
SIGNAL \u5|u2|state.s1~0_combout\ : std_logic;
SIGNAL \u5|u2|state.s1~q\ : std_logic;
SIGNAL \u5|u2|state.s2~feeder_combout\ : std_logic;
SIGNAL \u5|u2|state.s2~q\ : std_logic;
SIGNAL \u5|u2|state.s3~feeder_combout\ : std_logic;
SIGNAL \u5|u2|state.s3~q\ : std_logic;
SIGNAL \u5|u2|q[0]~0_combout\ : std_logic;
SIGNAL \u5|u2|q[1]~feeder_combout\ : std_logic;
SIGNAL \u5|u2|q[2]~1_combout\ : std_logic;
SIGNAL \u5|u2|q[3]~2_combout\ : std_logic;
SIGNAL \clk~input_o\ : std_logic;
SIGNAL \clk~inputclkctrl_outclk\ : std_logic;
SIGNAL \u4|clock:m[0]~1_combout\ : std_logic;
SIGNAL \u4|clock:m[0]~q\ : std_logic;
SIGNAL \u4|clock:m[0]~2\ : std_logic;
SIGNAL \u4|clock:m[1]~1_combout\ : std_logic;
SIGNAL \u4|clock:m[1]~q\ : std_logic;
SIGNAL \u4|clock:m[1]~2\ : std_logic;
SIGNAL \u4|clock:m[2]~1_combout\ : std_logic;
SIGNAL \u4|clock:m[2]~q\ : std_logic;
SIGNAL \u4|clock:m[2]~2\ : std_logic;
SIGNAL \u4|clock:m[3]~2\ : std_logic;
SIGNAL \u4|clock:m[4]~1_combout\ : std_logic;
SIGNAL \u4|clock:m[4]~q\ : std_logic;
SIGNAL \u4|clock:m[4]~2\ : std_logic;
SIGNAL \u4|clock:m[5]~2\ : std_logic;
SIGNAL \u4|clock:m[6]~2\ : std_logic;
SIGNAL \u4|clock:m[7]~1_combout\ : std_logic;
SIGNAL \u4|clock:m[7]~q\ : std_logic;
SIGNAL \u4|clock:m[5]~1_combout\ : std_logic;
SIGNAL \u4|clock:m[5]~q\ : std_logic;
SIGNAL \u4|clock:m[6]~1_combout\ : std_logic;
SIGNAL \u4|clock:m[6]~q\ : std_logic;
SIGNAL \u4|LessThan0~1_combout\ : std_logic;
SIGNAL \u4|clock:m[7]~2\ : std_logic;
SIGNAL \u4|clock:m[8]~1_combout\ : std_logic;
SIGNAL \u4|clock:m[8]~q\ : std_logic;
SIGNAL \u4|clock:m[8]~2\ : std_logic;
SIGNAL \u4|clock:m[9]~1_combout\ : std_logic;
SIGNAL \u4|clock:m[9]~q\ : std_logic;
SIGNAL \u4|clock:m[9]~2\ : std_logic;
SIGNAL \u4|clock:m[10]~1_combout\ : std_logic;
SIGNAL \u4|clock:m[10]~q\ : std_logic;
SIGNAL \u4|clock:m[10]~2\ : std_logic;
SIGNAL \u4|clock:m[11]~1_combout\ : std_logic;
SIGNAL \u4|clock:m[11]~q\ : std_logic;
SIGNAL \u4|LessThan0~2_combout\ : std_logic;
SIGNAL \u4|clock:m[11]~2\ : std_logic;
SIGNAL \u4|clock:m[12]~1_combout\ : std_logic;
SIGNAL \u4|clock:m[12]~q\ : std_logic;
SIGNAL \u4|clock:m[12]~2\ : std_logic;
SIGNAL \u4|clock:m[13]~2\ : std_logic;
SIGNAL \u4|clock:m[14]~1_combout\ : std_logic;
SIGNAL \u4|clock:m[14]~q\ : std_logic;
SIGNAL \u4|clock:m[14]~2\ : std_logic;
SIGNAL \u4|clock:m[15]~2\ : std_logic;
SIGNAL \u4|clock:m[16]~1_combout\ : std_logic;
SIGNAL \u4|clock:m[16]~q\ : std_logic;
SIGNAL \u4|clock:m[16]~2\ : std_logic;
SIGNAL \u4|clock:m[17]~1_combout\ : std_logic;
SIGNAL \u4|clock:m[17]~q\ : std_logic;
SIGNAL \u4|clock:m[17]~2\ : std_logic;
SIGNAL \u4|clock:m[18]~1_combout\ : std_logic;
SIGNAL \u4|clock:m[18]~q\ : std_logic;
SIGNAL \u4|clock:m[18]~2\ : std_logic;
SIGNAL \u4|clock:m[19]~2\ : std_logic;
SIGNAL \u4|clock:m[20]~1_combout\ : std_logic;
SIGNAL \u4|clock:m[20]~q\ : std_logic;
SIGNAL \u4|clock:m[20]~2\ : std_logic;
SIGNAL \u4|clock:m[21]~2\ : std_logic;
SIGNAL \u4|clock:m[22]~2\ : std_logic;
SIGNAL \u4|clock:m[23]~1_combout\ : std_logic;
SIGNAL \u4|clock:m[23]~q\ : std_logic;
SIGNAL \u4|clock:m[23]~2\ : std_logic;
SIGNAL \u4|clock:m[24]~1_combout\ : std_logic;
SIGNAL \u4|clock:m[24]~q\ : std_logic;
SIGNAL \u4|clock:m[24]~2\ : std_logic;
SIGNAL \u4|clock:m[25]~1_combout\ : std_logic;
SIGNAL \u4|clock:m[25]~q\ : std_logic;
SIGNAL \u4|clock:m[25]~2\ : std_logic;
SIGNAL \u4|clock:m[26]~1_combout\ : std_logic;
SIGNAL \u4|clock:m[26]~q\ : std_logic;
SIGNAL \u4|clock:m[26]~2\ : std_logic;
SIGNAL \u4|clock:m[27]~2\ : std_logic;
SIGNAL \u4|clock:m[28]~1_combout\ : std_logic;
SIGNAL \u4|clock:m[28]~q\ : std_logic;
SIGNAL \u4|clock:m[28]~2\ : std_logic;
SIGNAL \u4|clock:m[29]~1_combout\ : std_logic;
SIGNAL \u4|clock:m[29]~q\ : std_logic;
SIGNAL \u4|clock:m[22]~1_combout\ : std_logic;
SIGNAL \u4|clock:m[22]~q\ : std_logic;
SIGNAL \u4|LessThan0~5_combout\ : std_logic;
SIGNAL \u4|clock:m[27]~1_combout\ : std_logic;
SIGNAL \u4|clock:m[27]~q\ : std_logic;
SIGNAL \u4|LessThan0~6_combout\ : std_logic;
SIGNAL \u4|clock:m[15]~1_combout\ : std_logic;
SIGNAL \u4|clock:m[15]~q\ : std_logic;
SIGNAL \u4|LessThan0~3_combout\ : std_logic;
SIGNAL \u4|LessThan0~7_combout\ : std_logic;
SIGNAL \u4|LessThan0~8_combout\ : std_logic;
SIGNAL \u4|LessThan0~9_combout\ : std_logic;
SIGNAL \u4|tclk~0_combout\ : std_logic;
SIGNAL \u4|tclk~q\ : std_logic;
SIGNAL \u3|TrigerOut:m[0]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[0]~q\ : std_logic;
SIGNAL \u3|TrigerOut:m[0]~2\ : std_logic;
SIGNAL \u3|TrigerOut:m[1]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[1]~q\ : std_logic;
SIGNAL \u3|TrigerOut:m[1]~2\ : std_logic;
SIGNAL \u3|TrigerOut:m[2]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[2]~q\ : std_logic;
SIGNAL \u3|TrigerOut:m[2]~2\ : std_logic;
SIGNAL \u3|TrigerOut:m[3]~2\ : std_logic;
SIGNAL \u3|TrigerOut:m[4]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[4]~q\ : std_logic;
SIGNAL \u3|TrigerOut:m[4]~2\ : std_logic;
SIGNAL \u3|TrigerOut:m[5]~2\ : std_logic;
SIGNAL \u3|TrigerOut:m[6]~2\ : std_logic;
SIGNAL \u3|TrigerOut:m[7]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[7]~q\ : std_logic;
SIGNAL \u3|TrigerOut:m[7]~2\ : std_logic;
SIGNAL \u3|TrigerOut:m[8]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[8]~q\ : std_logic;
SIGNAL \u3|TrigerOut:m[8]~2\ : std_logic;
SIGNAL \u3|TrigerOut:m[9]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[9]~q\ : std_logic;
SIGNAL \u3|TrigerOut:m[9]~2\ : std_logic;
SIGNAL \u3|TrigerOut:m[10]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[10]~q\ : std_logic;
SIGNAL \u3|TrigerOut:m[10]~2\ : std_logic;
SIGNAL \u3|TrigerOut:m[11]~2\ : std_logic;
SIGNAL \u3|TrigerOut:m[12]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[12]~q\ : std_logic;
SIGNAL \u3|TrigerOut:m[12]~2\ : std_logic;
SIGNAL \u3|TrigerOut:m[13]~2\ : std_logic;
SIGNAL \u3|TrigerOut:m[14]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[14]~q\ : std_logic;
SIGNAL \u3|TrigerOut:m[14]~2\ : std_logic;
SIGNAL \u3|TrigerOut:m[15]~2\ : std_logic;
SIGNAL \u3|TrigerOut:m[16]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[16]~q\ : std_logic;
SIGNAL \u3|TrigerOut:m[16]~2\ : std_logic;
SIGNAL \u3|TrigerOut:m[17]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[17]~q\ : std_logic;
SIGNAL \u3|TrigerOut:m[17]~2\ : std_logic;
SIGNAL \u3|TrigerOut:m[18]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[18]~q\ : std_logic;
SIGNAL \u3|TrigerOut:m[18]~2\ : std_logic;
SIGNAL \u3|TrigerOut:m[19]~2\ : std_logic;
SIGNAL \u3|TrigerOut:m[20]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[20]~q\ : std_logic;
SIGNAL \u3|TrigerOut:m[20]~2\ : std_logic;
SIGNAL \u3|TrigerOut:m[21]~2\ : std_logic;
SIGNAL \u3|TrigerOut:m[22]~2\ : std_logic;
SIGNAL \u3|TrigerOut:m[23]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[23]~q\ : std_logic;
SIGNAL \u3|TrigerOut:m[23]~2\ : std_logic;
SIGNAL \u3|TrigerOut:m[24]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[24]~q\ : std_logic;
SIGNAL \u3|TrigerOut:m[24]~2\ : std_logic;
SIGNAL \u3|TrigerOut:m[25]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[25]~q\ : std_logic;
SIGNAL \u3|TrigerOut:m[25]~2\ : std_logic;
SIGNAL \u3|TrigerOut:m[26]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[26]~q\ : std_logic;
SIGNAL \u3|TrigerOut:m[26]~2\ : std_logic;
SIGNAL \u3|TrigerOut:m[27]~2\ : std_logic;
SIGNAL \u3|TrigerOut:m[28]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[28]~q\ : std_logic;
SIGNAL \u3|TrigerOut:m[28]~2\ : std_logic;
SIGNAL \u3|TrigerOut:m[29]~2\ : std_logic;
SIGNAL \u3|TrigerOut:m[30]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[30]~q\ : std_logic;
SIGNAL \u3|TrigerOut:m[29]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[29]~q\ : std_logic;
SIGNAL \u3|LessThan0~3_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[19]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[19]~q\ : std_logic;
SIGNAL \u3|LessThan0~5_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[22]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[22]~q\ : std_logic;
SIGNAL \u3|LessThan0~6_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[13]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[13]~q\ : std_logic;
SIGNAL \u3|LessThan0~4_combout\ : std_logic;
SIGNAL \u3|LessThan0~8_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[11]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[11]~q\ : std_logic;
SIGNAL \u3|TrigerOut:m[6]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[6]~q\ : std_logic;
SIGNAL \u3|TrigerOut:m[5]~1_combout\ : std_logic;
SIGNAL \u3|TrigerOut:m[5]~q\ : std_logic;
SIGNAL \u3|LessThan0~0_combout\ : std_logic;
SIGNAL \u3|LessThan0~1_combout\ : std_logic;
SIGNAL \u3|LessThan0~2_combout\ : std_logic;
SIGNAL \u3|LessThan0~9_combout\ : std_logic;
SIGNAL \u3|tclk~0_combout\ : std_logic;
SIGNAL \u3|tclk~q\ : std_logic;
SIGNAL \u5|u1|tc\ : std_logic_vector(7 DOWNTO 0);
SIGNAL \u5|u1|q\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \u5|u2|q\ : std_logic_vector(3 DOWNTO 0);

BEGIN

ww_IR1_input <= IR1_input;
ww_IR2_input <= IR2_input;
ww_clk <= clk;
ww_HS_Echo <= HS_Echo;
STM1_output <= ww_STM1_output;
STM2_output <= ww_STM2_output;
SBM_output <= ww_SBM_output;
HS_Trigger <= ww_HS_Trigger;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

\u5|u1|tclk~clkctrl_INCLK_bus\ <= (vcc & vcc & vcc & \u5|u1|tclk~q\);

\u5|u2|tclk~clkctrl_INCLK_bus\ <= (vcc & vcc & vcc & \u5|u2|tclk~q\);

\clk~inputclkctrl_INCLK_bus\ <= (vcc & vcc & vcc & \clk~input_o\);

-- Location: FF_X13_Y12_N31
\u4|clock:m[31]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[31]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[31]~q\);

-- Location: FF_X13_Y13_N7
\u4|clock:m[3]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[3]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[3]~q\);

-- Location: FF_X13_Y13_N27
\u4|clock:m[13]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[13]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[13]~q\);

-- Location: FF_X13_Y12_N7
\u4|clock:m[19]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[19]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[19]~q\);

-- Location: FF_X13_Y12_N11
\u4|clock:m[21]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[21]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[21]~q\);

-- Location: FF_X13_Y12_N29
\u4|clock:m[30]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[30]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[30]~q\);

-- Location: FF_X19_Y20_N31
\u3|TrigerOut:m[31]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[31]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[31]~q\);

-- Location: FF_X19_Y21_N7
\u3|TrigerOut:m[3]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[3]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[3]~q\);

-- Location: FF_X19_Y21_N31
\u3|TrigerOut:m[15]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[15]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[15]~q\);

-- Location: FF_X19_Y20_N11
\u3|TrigerOut:m[21]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[21]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[21]~q\);

-- Location: FF_X19_Y20_N23
\u3|TrigerOut:m[27]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[27]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[27]~q\);

-- Location: LCCOMB_X13_Y13_N6
\u4|clock:m[3]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[3]~1_combout\ = (\u4|clock:m[3]~q\ & (!\u4|clock:m[2]~2\)) # (!\u4|clock:m[3]~q\ & ((\u4|clock:m[2]~2\) # (GND)))
-- \u4|clock:m[3]~2\ = CARRY((!\u4|clock:m[2]~2\) # (!\u4|clock:m[3]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u4|clock:m[3]~q\,
	datad => VCC,
	cin => \u4|clock:m[2]~2\,
	combout => \u4|clock:m[3]~1_combout\,
	cout => \u4|clock:m[3]~2\);

-- Location: LCCOMB_X13_Y13_N26
\u4|clock:m[13]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[13]~1_combout\ = (\u4|clock:m[13]~q\ & (!\u4|clock:m[12]~2\)) # (!\u4|clock:m[13]~q\ & ((\u4|clock:m[12]~2\) # (GND)))
-- \u4|clock:m[13]~2\ = CARRY((!\u4|clock:m[12]~2\) # (!\u4|clock:m[13]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u4|clock:m[13]~q\,
	datad => VCC,
	cin => \u4|clock:m[12]~2\,
	combout => \u4|clock:m[13]~1_combout\,
	cout => \u4|clock:m[13]~2\);

-- Location: LCCOMB_X13_Y12_N6
\u4|clock:m[19]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[19]~1_combout\ = (\u4|clock:m[19]~q\ & (!\u4|clock:m[18]~2\)) # (!\u4|clock:m[19]~q\ & ((\u4|clock:m[18]~2\) # (GND)))
-- \u4|clock:m[19]~2\ = CARRY((!\u4|clock:m[18]~2\) # (!\u4|clock:m[19]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u4|clock:m[19]~q\,
	datad => VCC,
	cin => \u4|clock:m[18]~2\,
	combout => \u4|clock:m[19]~1_combout\,
	cout => \u4|clock:m[19]~2\);

-- Location: LCCOMB_X13_Y12_N10
\u4|clock:m[21]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[21]~1_combout\ = (\u4|clock:m[21]~q\ & (!\u4|clock:m[20]~2\)) # (!\u4|clock:m[21]~q\ & ((\u4|clock:m[20]~2\) # (GND)))
-- \u4|clock:m[21]~2\ = CARRY((!\u4|clock:m[20]~2\) # (!\u4|clock:m[21]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u4|clock:m[21]~q\,
	datad => VCC,
	cin => \u4|clock:m[20]~2\,
	combout => \u4|clock:m[21]~1_combout\,
	cout => \u4|clock:m[21]~2\);

-- Location: LCCOMB_X13_Y12_N26
\u4|clock:m[29]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[29]~1_combout\ = (\u4|clock:m[29]~q\ & (!\u4|clock:m[28]~2\)) # (!\u4|clock:m[29]~q\ & ((\u4|clock:m[28]~2\) # (GND)))
-- \u4|clock:m[29]~2\ = CARRY((!\u4|clock:m[28]~2\) # (!\u4|clock:m[29]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u4|clock:m[29]~q\,
	datad => VCC,
	cin => \u4|clock:m[28]~2\,
	combout => \u4|clock:m[29]~1_combout\,
	cout => \u4|clock:m[29]~2\);

-- Location: LCCOMB_X13_Y12_N28
\u4|clock:m[30]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[30]~1_combout\ = (\u4|clock:m[30]~q\ & (\u4|clock:m[29]~2\ $ (GND))) # (!\u4|clock:m[30]~q\ & (!\u4|clock:m[29]~2\ & VCC))
-- \u4|clock:m[30]~2\ = CARRY((\u4|clock:m[30]~q\ & !\u4|clock:m[29]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u4|clock:m[30]~q\,
	datad => VCC,
	cin => \u4|clock:m[29]~2\,
	combout => \u4|clock:m[30]~1_combout\,
	cout => \u4|clock:m[30]~2\);

-- Location: LCCOMB_X13_Y12_N30
\u4|clock:m[31]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[31]~1_combout\ = \u4|clock:m[31]~q\ $ (\u4|clock:m[30]~2\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u4|clock:m[31]~q\,
	cin => \u4|clock:m[30]~2\,
	combout => \u4|clock:m[31]~1_combout\);

-- Location: LCCOMB_X19_Y21_N6
\u3|TrigerOut:m[3]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[3]~1_combout\ = (\u3|TrigerOut:m[3]~q\ & (!\u3|TrigerOut:m[2]~2\)) # (!\u3|TrigerOut:m[3]~q\ & ((\u3|TrigerOut:m[2]~2\) # (GND)))
-- \u3|TrigerOut:m[3]~2\ = CARRY((!\u3|TrigerOut:m[2]~2\) # (!\u3|TrigerOut:m[3]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u3|TrigerOut:m[3]~q\,
	datad => VCC,
	cin => \u3|TrigerOut:m[2]~2\,
	combout => \u3|TrigerOut:m[3]~1_combout\,
	cout => \u3|TrigerOut:m[3]~2\);

-- Location: LCCOMB_X19_Y21_N30
\u3|TrigerOut:m[15]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[15]~1_combout\ = (\u3|TrigerOut:m[15]~q\ & (!\u3|TrigerOut:m[14]~2\)) # (!\u3|TrigerOut:m[15]~q\ & ((\u3|TrigerOut:m[14]~2\) # (GND)))
-- \u3|TrigerOut:m[15]~2\ = CARRY((!\u3|TrigerOut:m[14]~2\) # (!\u3|TrigerOut:m[15]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u3|TrigerOut:m[15]~q\,
	datad => VCC,
	cin => \u3|TrigerOut:m[14]~2\,
	combout => \u3|TrigerOut:m[15]~1_combout\,
	cout => \u3|TrigerOut:m[15]~2\);

-- Location: LCCOMB_X19_Y20_N10
\u3|TrigerOut:m[21]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[21]~1_combout\ = (\u3|TrigerOut:m[21]~q\ & (!\u3|TrigerOut:m[20]~2\)) # (!\u3|TrigerOut:m[21]~q\ & ((\u3|TrigerOut:m[20]~2\) # (GND)))
-- \u3|TrigerOut:m[21]~2\ = CARRY((!\u3|TrigerOut:m[20]~2\) # (!\u3|TrigerOut:m[21]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u3|TrigerOut:m[21]~q\,
	datad => VCC,
	cin => \u3|TrigerOut:m[20]~2\,
	combout => \u3|TrigerOut:m[21]~1_combout\,
	cout => \u3|TrigerOut:m[21]~2\);

-- Location: LCCOMB_X19_Y20_N22
\u3|TrigerOut:m[27]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[27]~1_combout\ = (\u3|TrigerOut:m[27]~q\ & (!\u3|TrigerOut:m[26]~2\)) # (!\u3|TrigerOut:m[27]~q\ & ((\u3|TrigerOut:m[26]~2\) # (GND)))
-- \u3|TrigerOut:m[27]~2\ = CARRY((!\u3|TrigerOut:m[26]~2\) # (!\u3|TrigerOut:m[27]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u3|TrigerOut:m[27]~q\,
	datad => VCC,
	cin => \u3|TrigerOut:m[26]~2\,
	combout => \u3|TrigerOut:m[27]~1_combout\,
	cout => \u3|TrigerOut:m[27]~2\);

-- Location: LCCOMB_X19_Y20_N28
\u3|TrigerOut:m[30]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[30]~1_combout\ = (\u3|TrigerOut:m[30]~q\ & (\u3|TrigerOut:m[29]~2\ $ (GND))) # (!\u3|TrigerOut:m[30]~q\ & (!\u3|TrigerOut:m[29]~2\ & VCC))
-- \u3|TrigerOut:m[30]~2\ = CARRY((\u3|TrigerOut:m[30]~q\ & !\u3|TrigerOut:m[29]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u3|TrigerOut:m[30]~q\,
	datad => VCC,
	cin => \u3|TrigerOut:m[29]~2\,
	combout => \u3|TrigerOut:m[30]~1_combout\,
	cout => \u3|TrigerOut:m[30]~2\);

-- Location: LCCOMB_X19_Y20_N30
\u3|TrigerOut:m[31]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[31]~1_combout\ = \u3|TrigerOut:m[31]~q\ $ (\u3|TrigerOut:m[30]~2\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u3|TrigerOut:m[31]~q\,
	cin => \u3|TrigerOut:m[30]~2\,
	combout => \u3|TrigerOut:m[31]~1_combout\);

-- Location: FF_X1_Y11_N11
\u5|u1|tc[3]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u5|u1|tc[3]~8_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u5|u1|tc\(3));

-- Location: FF_X1_Y11_N7
\u5|u1|tc[1]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u5|u1|tc[1]~4_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u5|u1|tc\(1));

-- Location: LCCOMB_X1_Y11_N6
\u5|u1|tc[1]~4\ : cycloneive_lcell_comb
-- Equation(s):
-- \u5|u1|tc[1]~4_combout\ = (\u5|u1|tc\(1) & (\u5|u1|tc\(0) $ (VCC))) # (!\u5|u1|tc\(1) & (\u5|u1|tc\(0) & VCC))
-- \u5|u1|tc[1]~5\ = CARRY((\u5|u1|tc\(1) & \u5|u1|tc\(0)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0110011010001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u5|u1|tc\(1),
	datab => \u5|u1|tc\(0),
	datad => VCC,
	combout => \u5|u1|tc[1]~4_combout\,
	cout => \u5|u1|tc[1]~5\);

-- Location: LCCOMB_X1_Y11_N10
\u5|u1|tc[3]~8\ : cycloneive_lcell_comb
-- Equation(s):
-- \u5|u1|tc[3]~8_combout\ = (\u5|u1|tc\(3) & (\u5|u1|tc[2]~7\ $ (GND))) # (!\u5|u1|tc\(3) & (!\u5|u1|tc[2]~7\ & VCC))
-- \u5|u1|tc[3]~9\ = CARRY((\u5|u1|tc\(3) & !\u5|u1|tc[2]~7\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u5|u1|tc\(3),
	datad => VCC,
	cin => \u5|u1|tc[2]~7\,
	combout => \u5|u1|tc[3]~8_combout\,
	cout => \u5|u1|tc[3]~9\);

-- Location: LCCOMB_X14_Y12_N6
\u4|LessThan0~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|LessThan0~0_combout\ = ((!\u4|clock:m[3]~q\ & ((!\u4|clock:m[1]~q\) # (!\u4|clock:m[2]~q\)))) # (!\u4|clock:m[4]~q\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101010101111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u4|clock:m[4]~q\,
	datab => \u4|clock:m[2]~q\,
	datac => \u4|clock:m[1]~q\,
	datad => \u4|clock:m[3]~q\,
	combout => \u4|LessThan0~0_combout\);

-- Location: LCCOMB_X14_Y12_N22
\u4|LessThan0~4\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|LessThan0~4_combout\ = (!\u4|clock:m[17]~q\ & (!\u4|clock:m[19]~q\ & (!\u4|clock:m[18]~q\ & !\u4|clock:m[16]~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000000001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u4|clock:m[17]~q\,
	datab => \u4|clock:m[19]~q\,
	datac => \u4|clock:m[18]~q\,
	datad => \u4|clock:m[16]~q\,
	combout => \u4|LessThan0~4_combout\);

-- Location: LCCOMB_X18_Y20_N12
\u3|LessThan0~7\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|LessThan0~7_combout\ = (!\u3|TrigerOut:m[26]~q\ & (!\u3|TrigerOut:m[28]~q\ & (!\u3|TrigerOut:m[27]~q\ & !\u3|TrigerOut:m[25]~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000000001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u3|TrigerOut:m[26]~q\,
	datab => \u3|TrigerOut:m[28]~q\,
	datac => \u3|TrigerOut:m[27]~q\,
	datad => \u3|TrigerOut:m[25]~q\,
	combout => \u3|LessThan0~7_combout\);

-- Location: IOOBUF_X23_Y24_N23
\STM1_output[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u5|u1|q\(0),
	devoe => ww_devoe,
	o => \STM1_output[0]~output_o\);

-- Location: IOOBUF_X21_Y24_N2
\STM1_output[1]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u5|u1|q\(1),
	devoe => ww_devoe,
	o => \STM1_output[1]~output_o\);

-- Location: IOOBUF_X21_Y24_N9
\STM1_output[2]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u5|u1|q\(2),
	devoe => ww_devoe,
	o => \STM1_output[2]~output_o\);

-- Location: IOOBUF_X21_Y24_N16
\STM1_output[3]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u5|u1|q\(3),
	devoe => ww_devoe,
	o => \STM1_output[3]~output_o\);

-- Location: IOOBUF_X18_Y24_N9
\STM2_output[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u5|u2|q\(0),
	devoe => ww_devoe,
	o => \STM2_output[0]~output_o\);

-- Location: IOOBUF_X18_Y24_N16
\STM2_output[1]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u5|u2|q\(1),
	devoe => ww_devoe,
	o => \STM2_output[1]~output_o\);

-- Location: IOOBUF_X18_Y24_N23
\STM2_output[2]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u5|u2|q\(2),
	devoe => ww_devoe,
	o => \STM2_output[2]~output_o\);

-- Location: IOOBUF_X16_Y24_N2
\STM2_output[3]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u5|u2|q\(3),
	devoe => ww_devoe,
	o => \STM2_output[3]~output_o\);

-- Location: IOOBUF_X34_Y10_N9
\SBM_output~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u4|tclk~q\,
	devoe => ww_devoe,
	o => \SBM_output~output_o\);

-- Location: IOOBUF_X34_Y7_N9
\HS_Trigger~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u3|tclk~q\,
	devoe => ww_devoe,
	o => \HS_Trigger~output_o\);

-- Location: LCCOMB_X1_Y11_N28
\u5|u1|tc[0]~12\ : cycloneive_lcell_comb
-- Equation(s):
-- \u5|u1|tc[0]~12_combout\ = !\u5|u1|tc\(0)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \u5|u1|tc\(0),
	combout => \u5|u1|tc[0]~12_combout\);

-- Location: FF_X1_Y11_N29
\u5|u1|tc[0]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u5|u1|tc[0]~12_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u5|u1|tc\(0));

-- Location: LCCOMB_X1_Y11_N8
\u5|u1|tc[2]~6\ : cycloneive_lcell_comb
-- Equation(s):
-- \u5|u1|tc[2]~6_combout\ = (\u5|u1|tc\(2) & (!\u5|u1|tc[1]~5\)) # (!\u5|u1|tc\(2) & ((\u5|u1|tc[1]~5\) # (GND)))
-- \u5|u1|tc[2]~7\ = CARRY((!\u5|u1|tc[1]~5\) # (!\u5|u1|tc\(2)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u5|u1|tc\(2),
	datad => VCC,
	cin => \u5|u1|tc[1]~5\,
	combout => \u5|u1|tc[2]~6_combout\,
	cout => \u5|u1|tc[2]~7\);

-- Location: FF_X1_Y11_N9
\u5|u1|tc[2]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u5|u1|tc[2]~6_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u5|u1|tc\(2));

-- Location: LCCOMB_X1_Y11_N12
\u5|u1|tc[4]~10\ : cycloneive_lcell_comb
-- Equation(s):
-- \u5|u1|tc[4]~10_combout\ = \u5|u1|tc[3]~9\ $ (\u5|u1|tc\(4))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111111110000",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datad => \u5|u1|tc\(4),
	cin => \u5|u1|tc[3]~9\,
	combout => \u5|u1|tc[4]~10_combout\);

-- Location: FF_X1_Y11_N13
\u5|u1|tc[4]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u5|u1|tc[4]~10_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u5|u1|tc\(4));

-- Location: LCCOMB_X1_Y11_N14
\u5|u1|tclk~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \u5|u1|tclk~feeder_combout\ = \u5|u1|tc\(4)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \u5|u1|tc\(4),
	combout => \u5|u1|tclk~feeder_combout\);

-- Location: FF_X1_Y11_N15
\u5|u1|tclk\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u5|u1|tclk~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u5|u1|tclk~q\);

-- Location: CLKCTRL_G1
\u5|u1|tclk~clkctrl\ : cycloneive_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	ena_register_mode => "none")
-- pragma translate_on
PORT MAP (
	inclk => \u5|u1|tclk~clkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \u5|u1|tclk~clkctrl_outclk\);

-- Location: LCCOMB_X22_Y23_N6
\u5|u1|state.s0~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u5|u1|state.s0~0_combout\ = !\u5|u1|state.s3~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \u5|u1|state.s3~q\,
	combout => \u5|u1|state.s0~0_combout\);

-- Location: FF_X22_Y23_N7
\u5|u1|state.s0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \u5|u1|tclk~clkctrl_outclk\,
	d => \u5|u1|state.s0~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u5|u1|state.s0~q\);

-- Location: LCCOMB_X22_Y23_N24
\u5|u1|state.s1~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u5|u1|state.s1~0_combout\ = !\u5|u1|state.s0~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \u5|u1|state.s0~q\,
	combout => \u5|u1|state.s1~0_combout\);

-- Location: FF_X22_Y23_N25
\u5|u1|state.s1\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \u5|u1|tclk~clkctrl_outclk\,
	d => \u5|u1|state.s1~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u5|u1|state.s1~q\);

-- Location: LCCOMB_X22_Y23_N18
\u5|u1|state.s2~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \u5|u1|state.s2~feeder_combout\ = \u5|u1|state.s1~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \u5|u1|state.s1~q\,
	combout => \u5|u1|state.s2~feeder_combout\);

-- Location: FF_X22_Y23_N19
\u5|u1|state.s2\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \u5|u1|tclk~clkctrl_outclk\,
	d => \u5|u1|state.s2~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u5|u1|state.s2~q\);

-- Location: LCCOMB_X22_Y23_N20
\u5|u1|state.s3~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \u5|u1|state.s3~feeder_combout\ = \u5|u1|state.s2~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \u5|u1|state.s2~q\,
	combout => \u5|u1|state.s3~feeder_combout\);

-- Location: FF_X22_Y23_N21
\u5|u1|state.s3\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \u5|u1|tclk~clkctrl_outclk\,
	d => \u5|u1|state.s3~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u5|u1|state.s3~q\);

-- Location: LCCOMB_X22_Y23_N16
\u5|u1|q[0]~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u5|u1|q[0]~0_combout\ = !\u5|u1|state.s3~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \u5|u1|state.s3~q\,
	combout => \u5|u1|q[0]~0_combout\);

-- Location: FF_X22_Y23_N17
\u5|u1|q[0]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \u5|u1|tclk~clkctrl_outclk\,
	d => \u5|u1|q[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u5|u1|q\(0));

-- Location: LCCOMB_X22_Y23_N22
\u5|u1|q[1]~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \u5|u1|q[1]~feeder_combout\ = \u5|u1|state.s0~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \u5|u1|state.s0~q\,
	combout => \u5|u1|q[1]~feeder_combout\);

-- Location: FF_X22_Y23_N23
\u5|u1|q[1]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \u5|u1|tclk~clkctrl_outclk\,
	d => \u5|u1|q[1]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u5|u1|q\(1));

-- Location: LCCOMB_X22_Y23_N12
\u5|u1|q[2]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u5|u1|q[2]~1_combout\ = !\u5|u1|state.s1~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \u5|u1|state.s1~q\,
	combout => \u5|u1|q[2]~1_combout\);

-- Location: FF_X22_Y23_N13
\u5|u1|q[2]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \u5|u1|tclk~clkctrl_outclk\,
	d => \u5|u1|q[2]~1_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u5|u1|q\(2));

-- Location: LCCOMB_X22_Y23_N10
\u5|u1|q[3]~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \u5|u1|q[3]~2_combout\ = !\u5|u1|state.s2~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \u5|u1|state.s2~q\,
	combout => \u5|u1|q[3]~2_combout\);

-- Location: FF_X22_Y23_N11
\u5|u1|q[3]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \u5|u1|tclk~clkctrl_outclk\,
	d => \u5|u1|q[3]~2_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u5|u1|q\(3));

-- Location: LCCOMB_X1_Y11_N26
\u5|u2|tclk~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \u5|u2|tclk~feeder_combout\ = \u5|u1|tc\(4)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \u5|u1|tc\(4),
	combout => \u5|u2|tclk~feeder_combout\);

-- Location: FF_X1_Y11_N27
\u5|u2|tclk\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u5|u2|tclk~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u5|u2|tclk~q\);

-- Location: CLKCTRL_G3
\u5|u2|tclk~clkctrl\ : cycloneive_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	ena_register_mode => "none")
-- pragma translate_on
PORT MAP (
	inclk => \u5|u2|tclk~clkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \u5|u2|tclk~clkctrl_outclk\);

-- Location: LCCOMB_X18_Y23_N18
\u5|u2|state.s0~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u5|u2|state.s0~0_combout\ = !\u5|u2|state.s3~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \u5|u2|state.s3~q\,
	combout => \u5|u2|state.s0~0_combout\);

-- Location: FF_X18_Y23_N19
\u5|u2|state.s0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \u5|u2|tclk~clkctrl_outclk\,
	d => \u5|u2|state.s0~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u5|u2|state.s0~q\);

-- Location: LCCOMB_X18_Y23_N24
\u5|u2|state.s1~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u5|u2|state.s1~0_combout\ = !\u5|u2|state.s0~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \u5|u2|state.s0~q\,
	combout => \u5|u2|state.s1~0_combout\);

-- Location: FF_X18_Y23_N25
\u5|u2|state.s1\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \u5|u2|tclk~clkctrl_outclk\,
	d => \u5|u2|state.s1~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u5|u2|state.s1~q\);

-- Location: LCCOMB_X18_Y23_N10
\u5|u2|state.s2~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \u5|u2|state.s2~feeder_combout\ = \u5|u2|state.s1~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \u5|u2|state.s1~q\,
	combout => \u5|u2|state.s2~feeder_combout\);

-- Location: FF_X18_Y23_N11
\u5|u2|state.s2\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \u5|u2|tclk~clkctrl_outclk\,
	d => \u5|u2|state.s2~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u5|u2|state.s2~q\);

-- Location: LCCOMB_X18_Y23_N16
\u5|u2|state.s3~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \u5|u2|state.s3~feeder_combout\ = \u5|u2|state.s2~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \u5|u2|state.s2~q\,
	combout => \u5|u2|state.s3~feeder_combout\);

-- Location: FF_X18_Y23_N17
\u5|u2|state.s3\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \u5|u2|tclk~clkctrl_outclk\,
	d => \u5|u2|state.s3~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u5|u2|state.s3~q\);

-- Location: LCCOMB_X18_Y23_N0
\u5|u2|q[0]~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u5|u2|q[0]~0_combout\ = !\u5|u2|state.s3~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \u5|u2|state.s3~q\,
	combout => \u5|u2|q[0]~0_combout\);

-- Location: FF_X18_Y23_N1
\u5|u2|q[0]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \u5|u2|tclk~clkctrl_outclk\,
	d => \u5|u2|q[0]~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u5|u2|q\(0));

-- Location: LCCOMB_X18_Y23_N6
\u5|u2|q[1]~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \u5|u2|q[1]~feeder_combout\ = \u5|u2|state.s0~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \u5|u2|state.s0~q\,
	combout => \u5|u2|q[1]~feeder_combout\);

-- Location: FF_X18_Y23_N7
\u5|u2|q[1]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \u5|u2|tclk~clkctrl_outclk\,
	d => \u5|u2|q[1]~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u5|u2|q\(1));

-- Location: LCCOMB_X18_Y23_N20
\u5|u2|q[2]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u5|u2|q[2]~1_combout\ = !\u5|u2|state.s1~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \u5|u2|state.s1~q\,
	combout => \u5|u2|q[2]~1_combout\);

-- Location: FF_X18_Y23_N21
\u5|u2|q[2]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \u5|u2|tclk~clkctrl_outclk\,
	d => \u5|u2|q[2]~1_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u5|u2|q\(2));

-- Location: LCCOMB_X18_Y23_N26
\u5|u2|q[3]~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \u5|u2|q[3]~2_combout\ = !\u5|u2|state.s2~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \u5|u2|state.s2~q\,
	combout => \u5|u2|q[3]~2_combout\);

-- Location: FF_X18_Y23_N27
\u5|u2|q[3]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \u5|u2|tclk~clkctrl_outclk\,
	d => \u5|u2|q[3]~2_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u5|u2|q\(3));

-- Location: IOIBUF_X34_Y12_N1
\clk~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_clk,
	o => \clk~input_o\);

-- Location: CLKCTRL_G9
\clk~inputclkctrl\ : cycloneive_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	ena_register_mode => "none")
-- pragma translate_on
PORT MAP (
	inclk => \clk~inputclkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \clk~inputclkctrl_outclk\);

-- Location: LCCOMB_X13_Y13_N0
\u4|clock:m[0]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[0]~1_combout\ = \u4|clock:m[0]~q\ $ (VCC)
-- \u4|clock:m[0]~2\ = CARRY(\u4|clock:m[0]~q\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001111001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u4|clock:m[0]~q\,
	datad => VCC,
	combout => \u4|clock:m[0]~1_combout\,
	cout => \u4|clock:m[0]~2\);

-- Location: FF_X13_Y13_N1
\u4|clock:m[0]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[0]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[0]~q\);

-- Location: LCCOMB_X13_Y13_N2
\u4|clock:m[1]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[1]~1_combout\ = (\u4|clock:m[1]~q\ & (!\u4|clock:m[0]~2\)) # (!\u4|clock:m[1]~q\ & ((\u4|clock:m[0]~2\) # (GND)))
-- \u4|clock:m[1]~2\ = CARRY((!\u4|clock:m[0]~2\) # (!\u4|clock:m[1]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u4|clock:m[1]~q\,
	datad => VCC,
	cin => \u4|clock:m[0]~2\,
	combout => \u4|clock:m[1]~1_combout\,
	cout => \u4|clock:m[1]~2\);

-- Location: FF_X13_Y13_N3
\u4|clock:m[1]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[1]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[1]~q\);

-- Location: LCCOMB_X13_Y13_N4
\u4|clock:m[2]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[2]~1_combout\ = (\u4|clock:m[2]~q\ & (\u4|clock:m[1]~2\ $ (GND))) # (!\u4|clock:m[2]~q\ & (!\u4|clock:m[1]~2\ & VCC))
-- \u4|clock:m[2]~2\ = CARRY((\u4|clock:m[2]~q\ & !\u4|clock:m[1]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u4|clock:m[2]~q\,
	datad => VCC,
	cin => \u4|clock:m[1]~2\,
	combout => \u4|clock:m[2]~1_combout\,
	cout => \u4|clock:m[2]~2\);

-- Location: FF_X13_Y13_N5
\u4|clock:m[2]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[2]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[2]~q\);

-- Location: LCCOMB_X13_Y13_N8
\u4|clock:m[4]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[4]~1_combout\ = (\u4|clock:m[4]~q\ & (\u4|clock:m[3]~2\ $ (GND))) # (!\u4|clock:m[4]~q\ & (!\u4|clock:m[3]~2\ & VCC))
-- \u4|clock:m[4]~2\ = CARRY((\u4|clock:m[4]~q\ & !\u4|clock:m[3]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u4|clock:m[4]~q\,
	datad => VCC,
	cin => \u4|clock:m[3]~2\,
	combout => \u4|clock:m[4]~1_combout\,
	cout => \u4|clock:m[4]~2\);

-- Location: FF_X13_Y13_N9
\u4|clock:m[4]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[4]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[4]~q\);

-- Location: LCCOMB_X13_Y13_N10
\u4|clock:m[5]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[5]~1_combout\ = (\u4|clock:m[5]~q\ & (!\u4|clock:m[4]~2\)) # (!\u4|clock:m[5]~q\ & ((\u4|clock:m[4]~2\) # (GND)))
-- \u4|clock:m[5]~2\ = CARRY((!\u4|clock:m[4]~2\) # (!\u4|clock:m[5]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u4|clock:m[5]~q\,
	datad => VCC,
	cin => \u4|clock:m[4]~2\,
	combout => \u4|clock:m[5]~1_combout\,
	cout => \u4|clock:m[5]~2\);

-- Location: LCCOMB_X13_Y13_N12
\u4|clock:m[6]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[6]~1_combout\ = (\u4|clock:m[6]~q\ & (\u4|clock:m[5]~2\ $ (GND))) # (!\u4|clock:m[6]~q\ & (!\u4|clock:m[5]~2\ & VCC))
-- \u4|clock:m[6]~2\ = CARRY((\u4|clock:m[6]~q\ & !\u4|clock:m[5]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u4|clock:m[6]~q\,
	datad => VCC,
	cin => \u4|clock:m[5]~2\,
	combout => \u4|clock:m[6]~1_combout\,
	cout => \u4|clock:m[6]~2\);

-- Location: LCCOMB_X13_Y13_N14
\u4|clock:m[7]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[7]~1_combout\ = (\u4|clock:m[7]~q\ & (!\u4|clock:m[6]~2\)) # (!\u4|clock:m[7]~q\ & ((\u4|clock:m[6]~2\) # (GND)))
-- \u4|clock:m[7]~2\ = CARRY((!\u4|clock:m[6]~2\) # (!\u4|clock:m[7]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u4|clock:m[7]~q\,
	datad => VCC,
	cin => \u4|clock:m[6]~2\,
	combout => \u4|clock:m[7]~1_combout\,
	cout => \u4|clock:m[7]~2\);

-- Location: FF_X13_Y13_N15
\u4|clock:m[7]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[7]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[7]~q\);

-- Location: FF_X13_Y13_N11
\u4|clock:m[5]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[5]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[5]~q\);

-- Location: FF_X13_Y13_N13
\u4|clock:m[6]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[6]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[6]~q\);

-- Location: LCCOMB_X14_Y12_N16
\u4|LessThan0~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|LessThan0~1_combout\ = ((\u4|LessThan0~0_combout\ & (!\u4|clock:m[5]~q\ & !\u4|clock:m[6]~q\))) # (!\u4|clock:m[7]~q\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001100111011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u4|LessThan0~0_combout\,
	datab => \u4|clock:m[7]~q\,
	datac => \u4|clock:m[5]~q\,
	datad => \u4|clock:m[6]~q\,
	combout => \u4|LessThan0~1_combout\);

-- Location: LCCOMB_X13_Y13_N16
\u4|clock:m[8]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[8]~1_combout\ = (\u4|clock:m[8]~q\ & (\u4|clock:m[7]~2\ $ (GND))) # (!\u4|clock:m[8]~q\ & (!\u4|clock:m[7]~2\ & VCC))
-- \u4|clock:m[8]~2\ = CARRY((\u4|clock:m[8]~q\ & !\u4|clock:m[7]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u4|clock:m[8]~q\,
	datad => VCC,
	cin => \u4|clock:m[7]~2\,
	combout => \u4|clock:m[8]~1_combout\,
	cout => \u4|clock:m[8]~2\);

-- Location: FF_X13_Y13_N17
\u4|clock:m[8]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[8]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[8]~q\);

-- Location: LCCOMB_X13_Y13_N18
\u4|clock:m[9]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[9]~1_combout\ = (\u4|clock:m[9]~q\ & (!\u4|clock:m[8]~2\)) # (!\u4|clock:m[9]~q\ & ((\u4|clock:m[8]~2\) # (GND)))
-- \u4|clock:m[9]~2\ = CARRY((!\u4|clock:m[8]~2\) # (!\u4|clock:m[9]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u4|clock:m[9]~q\,
	datad => VCC,
	cin => \u4|clock:m[8]~2\,
	combout => \u4|clock:m[9]~1_combout\,
	cout => \u4|clock:m[9]~2\);

-- Location: FF_X13_Y13_N19
\u4|clock:m[9]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[9]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[9]~q\);

-- Location: LCCOMB_X13_Y13_N20
\u4|clock:m[10]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[10]~1_combout\ = (\u4|clock:m[10]~q\ & (\u4|clock:m[9]~2\ $ (GND))) # (!\u4|clock:m[10]~q\ & (!\u4|clock:m[9]~2\ & VCC))
-- \u4|clock:m[10]~2\ = CARRY((\u4|clock:m[10]~q\ & !\u4|clock:m[9]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u4|clock:m[10]~q\,
	datad => VCC,
	cin => \u4|clock:m[9]~2\,
	combout => \u4|clock:m[10]~1_combout\,
	cout => \u4|clock:m[10]~2\);

-- Location: FF_X13_Y13_N21
\u4|clock:m[10]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[10]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[10]~q\);

-- Location: LCCOMB_X13_Y13_N22
\u4|clock:m[11]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[11]~1_combout\ = (\u4|clock:m[11]~q\ & (!\u4|clock:m[10]~2\)) # (!\u4|clock:m[11]~q\ & ((\u4|clock:m[10]~2\) # (GND)))
-- \u4|clock:m[11]~2\ = CARRY((!\u4|clock:m[10]~2\) # (!\u4|clock:m[11]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u4|clock:m[11]~q\,
	datad => VCC,
	cin => \u4|clock:m[10]~2\,
	combout => \u4|clock:m[11]~1_combout\,
	cout => \u4|clock:m[11]~2\);

-- Location: FF_X13_Y13_N23
\u4|clock:m[11]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[11]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[11]~q\);

-- Location: LCCOMB_X14_Y12_N26
\u4|LessThan0~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|LessThan0~2_combout\ = (!\u4|clock:m[9]~q\ & (!\u4|clock:m[11]~q\ & (!\u4|clock:m[8]~q\ & !\u4|clock:m[10]~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000000001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u4|clock:m[9]~q\,
	datab => \u4|clock:m[11]~q\,
	datac => \u4|clock:m[8]~q\,
	datad => \u4|clock:m[10]~q\,
	combout => \u4|LessThan0~2_combout\);

-- Location: LCCOMB_X13_Y13_N24
\u4|clock:m[12]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[12]~1_combout\ = (\u4|clock:m[12]~q\ & (\u4|clock:m[11]~2\ $ (GND))) # (!\u4|clock:m[12]~q\ & (!\u4|clock:m[11]~2\ & VCC))
-- \u4|clock:m[12]~2\ = CARRY((\u4|clock:m[12]~q\ & !\u4|clock:m[11]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u4|clock:m[12]~q\,
	datad => VCC,
	cin => \u4|clock:m[11]~2\,
	combout => \u4|clock:m[12]~1_combout\,
	cout => \u4|clock:m[12]~2\);

-- Location: FF_X13_Y13_N25
\u4|clock:m[12]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[12]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[12]~q\);

-- Location: LCCOMB_X13_Y13_N28
\u4|clock:m[14]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[14]~1_combout\ = (\u4|clock:m[14]~q\ & (\u4|clock:m[13]~2\ $ (GND))) # (!\u4|clock:m[14]~q\ & (!\u4|clock:m[13]~2\ & VCC))
-- \u4|clock:m[14]~2\ = CARRY((\u4|clock:m[14]~q\ & !\u4|clock:m[13]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u4|clock:m[14]~q\,
	datad => VCC,
	cin => \u4|clock:m[13]~2\,
	combout => \u4|clock:m[14]~1_combout\,
	cout => \u4|clock:m[14]~2\);

-- Location: FF_X13_Y13_N29
\u4|clock:m[14]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[14]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[14]~q\);

-- Location: LCCOMB_X13_Y13_N30
\u4|clock:m[15]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[15]~1_combout\ = (\u4|clock:m[15]~q\ & (!\u4|clock:m[14]~2\)) # (!\u4|clock:m[15]~q\ & ((\u4|clock:m[14]~2\) # (GND)))
-- \u4|clock:m[15]~2\ = CARRY((!\u4|clock:m[14]~2\) # (!\u4|clock:m[15]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u4|clock:m[15]~q\,
	datad => VCC,
	cin => \u4|clock:m[14]~2\,
	combout => \u4|clock:m[15]~1_combout\,
	cout => \u4|clock:m[15]~2\);

-- Location: LCCOMB_X13_Y12_N0
\u4|clock:m[16]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[16]~1_combout\ = (\u4|clock:m[16]~q\ & (\u4|clock:m[15]~2\ $ (GND))) # (!\u4|clock:m[16]~q\ & (!\u4|clock:m[15]~2\ & VCC))
-- \u4|clock:m[16]~2\ = CARRY((\u4|clock:m[16]~q\ & !\u4|clock:m[15]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u4|clock:m[16]~q\,
	datad => VCC,
	cin => \u4|clock:m[15]~2\,
	combout => \u4|clock:m[16]~1_combout\,
	cout => \u4|clock:m[16]~2\);

-- Location: FF_X13_Y12_N1
\u4|clock:m[16]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[16]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[16]~q\);

-- Location: LCCOMB_X13_Y12_N2
\u4|clock:m[17]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[17]~1_combout\ = (\u4|clock:m[17]~q\ & (!\u4|clock:m[16]~2\)) # (!\u4|clock:m[17]~q\ & ((\u4|clock:m[16]~2\) # (GND)))
-- \u4|clock:m[17]~2\ = CARRY((!\u4|clock:m[16]~2\) # (!\u4|clock:m[17]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u4|clock:m[17]~q\,
	datad => VCC,
	cin => \u4|clock:m[16]~2\,
	combout => \u4|clock:m[17]~1_combout\,
	cout => \u4|clock:m[17]~2\);

-- Location: FF_X13_Y12_N3
\u4|clock:m[17]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[17]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[17]~q\);

-- Location: LCCOMB_X13_Y12_N4
\u4|clock:m[18]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[18]~1_combout\ = (\u4|clock:m[18]~q\ & (\u4|clock:m[17]~2\ $ (GND))) # (!\u4|clock:m[18]~q\ & (!\u4|clock:m[17]~2\ & VCC))
-- \u4|clock:m[18]~2\ = CARRY((\u4|clock:m[18]~q\ & !\u4|clock:m[17]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u4|clock:m[18]~q\,
	datad => VCC,
	cin => \u4|clock:m[17]~2\,
	combout => \u4|clock:m[18]~1_combout\,
	cout => \u4|clock:m[18]~2\);

-- Location: FF_X13_Y12_N5
\u4|clock:m[18]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[18]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[18]~q\);

-- Location: LCCOMB_X13_Y12_N8
\u4|clock:m[20]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[20]~1_combout\ = (\u4|clock:m[20]~q\ & (\u4|clock:m[19]~2\ $ (GND))) # (!\u4|clock:m[20]~q\ & (!\u4|clock:m[19]~2\ & VCC))
-- \u4|clock:m[20]~2\ = CARRY((\u4|clock:m[20]~q\ & !\u4|clock:m[19]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u4|clock:m[20]~q\,
	datad => VCC,
	cin => \u4|clock:m[19]~2\,
	combout => \u4|clock:m[20]~1_combout\,
	cout => \u4|clock:m[20]~2\);

-- Location: FF_X13_Y12_N9
\u4|clock:m[20]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[20]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[20]~q\);

-- Location: LCCOMB_X13_Y12_N12
\u4|clock:m[22]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[22]~1_combout\ = (\u4|clock:m[22]~q\ & (\u4|clock:m[21]~2\ $ (GND))) # (!\u4|clock:m[22]~q\ & (!\u4|clock:m[21]~2\ & VCC))
-- \u4|clock:m[22]~2\ = CARRY((\u4|clock:m[22]~q\ & !\u4|clock:m[21]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u4|clock:m[22]~q\,
	datad => VCC,
	cin => \u4|clock:m[21]~2\,
	combout => \u4|clock:m[22]~1_combout\,
	cout => \u4|clock:m[22]~2\);

-- Location: LCCOMB_X13_Y12_N14
\u4|clock:m[23]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[23]~1_combout\ = (\u4|clock:m[23]~q\ & (!\u4|clock:m[22]~2\)) # (!\u4|clock:m[23]~q\ & ((\u4|clock:m[22]~2\) # (GND)))
-- \u4|clock:m[23]~2\ = CARRY((!\u4|clock:m[22]~2\) # (!\u4|clock:m[23]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u4|clock:m[23]~q\,
	datad => VCC,
	cin => \u4|clock:m[22]~2\,
	combout => \u4|clock:m[23]~1_combout\,
	cout => \u4|clock:m[23]~2\);

-- Location: FF_X13_Y12_N15
\u4|clock:m[23]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[23]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[23]~q\);

-- Location: LCCOMB_X13_Y12_N16
\u4|clock:m[24]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[24]~1_combout\ = (\u4|clock:m[24]~q\ & (\u4|clock:m[23]~2\ $ (GND))) # (!\u4|clock:m[24]~q\ & (!\u4|clock:m[23]~2\ & VCC))
-- \u4|clock:m[24]~2\ = CARRY((\u4|clock:m[24]~q\ & !\u4|clock:m[23]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u4|clock:m[24]~q\,
	datad => VCC,
	cin => \u4|clock:m[23]~2\,
	combout => \u4|clock:m[24]~1_combout\,
	cout => \u4|clock:m[24]~2\);

-- Location: FF_X13_Y12_N17
\u4|clock:m[24]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[24]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[24]~q\);

-- Location: LCCOMB_X13_Y12_N18
\u4|clock:m[25]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[25]~1_combout\ = (\u4|clock:m[25]~q\ & (!\u4|clock:m[24]~2\)) # (!\u4|clock:m[25]~q\ & ((\u4|clock:m[24]~2\) # (GND)))
-- \u4|clock:m[25]~2\ = CARRY((!\u4|clock:m[24]~2\) # (!\u4|clock:m[25]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u4|clock:m[25]~q\,
	datad => VCC,
	cin => \u4|clock:m[24]~2\,
	combout => \u4|clock:m[25]~1_combout\,
	cout => \u4|clock:m[25]~2\);

-- Location: FF_X13_Y12_N19
\u4|clock:m[25]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[25]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[25]~q\);

-- Location: LCCOMB_X13_Y12_N20
\u4|clock:m[26]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[26]~1_combout\ = (\u4|clock:m[26]~q\ & (\u4|clock:m[25]~2\ $ (GND))) # (!\u4|clock:m[26]~q\ & (!\u4|clock:m[25]~2\ & VCC))
-- \u4|clock:m[26]~2\ = CARRY((\u4|clock:m[26]~q\ & !\u4|clock:m[25]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u4|clock:m[26]~q\,
	datad => VCC,
	cin => \u4|clock:m[25]~2\,
	combout => \u4|clock:m[26]~1_combout\,
	cout => \u4|clock:m[26]~2\);

-- Location: FF_X13_Y12_N21
\u4|clock:m[26]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[26]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[26]~q\);

-- Location: LCCOMB_X13_Y12_N22
\u4|clock:m[27]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[27]~1_combout\ = (\u4|clock:m[27]~q\ & (!\u4|clock:m[26]~2\)) # (!\u4|clock:m[27]~q\ & ((\u4|clock:m[26]~2\) # (GND)))
-- \u4|clock:m[27]~2\ = CARRY((!\u4|clock:m[26]~2\) # (!\u4|clock:m[27]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u4|clock:m[27]~q\,
	datad => VCC,
	cin => \u4|clock:m[26]~2\,
	combout => \u4|clock:m[27]~1_combout\,
	cout => \u4|clock:m[27]~2\);

-- Location: LCCOMB_X13_Y12_N24
\u4|clock:m[28]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|clock:m[28]~1_combout\ = (\u4|clock:m[28]~q\ & (\u4|clock:m[27]~2\ $ (GND))) # (!\u4|clock:m[28]~q\ & (!\u4|clock:m[27]~2\ & VCC))
-- \u4|clock:m[28]~2\ = CARRY((\u4|clock:m[28]~q\ & !\u4|clock:m[27]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u4|clock:m[28]~q\,
	datad => VCC,
	cin => \u4|clock:m[27]~2\,
	combout => \u4|clock:m[28]~1_combout\,
	cout => \u4|clock:m[28]~2\);

-- Location: FF_X13_Y12_N25
\u4|clock:m[28]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[28]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[28]~q\);

-- Location: FF_X13_Y12_N27
\u4|clock:m[29]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[29]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[29]~q\);

-- Location: FF_X13_Y12_N13
\u4|clock:m[22]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[22]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[22]~q\);

-- Location: LCCOMB_X14_Y12_N8
\u4|LessThan0~5\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|LessThan0~5_combout\ = (!\u4|clock:m[21]~q\ & (!\u4|clock:m[20]~q\ & (!\u4|clock:m[23]~q\ & !\u4|clock:m[22]~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000000001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u4|clock:m[21]~q\,
	datab => \u4|clock:m[20]~q\,
	datac => \u4|clock:m[23]~q\,
	datad => \u4|clock:m[22]~q\,
	combout => \u4|LessThan0~5_combout\);

-- Location: FF_X13_Y12_N23
\u4|clock:m[27]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[27]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[27]~q\);

-- Location: LCCOMB_X14_Y12_N14
\u4|LessThan0~6\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|LessThan0~6_combout\ = (!\u4|clock:m[24]~q\ & (!\u4|clock:m[27]~q\ & (!\u4|clock:m[26]~q\ & !\u4|clock:m[25]~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000000001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u4|clock:m[24]~q\,
	datab => \u4|clock:m[27]~q\,
	datac => \u4|clock:m[26]~q\,
	datad => \u4|clock:m[25]~q\,
	combout => \u4|LessThan0~6_combout\);

-- Location: FF_X13_Y13_N31
\u4|clock:m[15]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|clock:m[15]~1_combout\,
	sclr => \u4|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|clock:m[15]~q\);

-- Location: LCCOMB_X14_Y12_N28
\u4|LessThan0~3\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|LessThan0~3_combout\ = (!\u4|clock:m[13]~q\ & (!\u4|clock:m[15]~q\ & (!\u4|clock:m[12]~q\ & !\u4|clock:m[14]~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000000001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u4|clock:m[13]~q\,
	datab => \u4|clock:m[15]~q\,
	datac => \u4|clock:m[12]~q\,
	datad => \u4|clock:m[14]~q\,
	combout => \u4|LessThan0~3_combout\);

-- Location: LCCOMB_X14_Y12_N20
\u4|LessThan0~7\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|LessThan0~7_combout\ = (\u4|LessThan0~4_combout\ & (\u4|LessThan0~5_combout\ & (\u4|LessThan0~6_combout\ & \u4|LessThan0~3_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u4|LessThan0~4_combout\,
	datab => \u4|LessThan0~5_combout\,
	datac => \u4|LessThan0~6_combout\,
	datad => \u4|LessThan0~3_combout\,
	combout => \u4|LessThan0~7_combout\);

-- Location: LCCOMB_X14_Y12_N2
\u4|LessThan0~8\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|LessThan0~8_combout\ = (!\u4|clock:m[30]~q\ & (!\u4|clock:m[28]~q\ & (!\u4|clock:m[29]~q\ & \u4|LessThan0~7_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u4|clock:m[30]~q\,
	datab => \u4|clock:m[28]~q\,
	datac => \u4|clock:m[29]~q\,
	datad => \u4|LessThan0~7_combout\,
	combout => \u4|LessThan0~8_combout\);

-- Location: LCCOMB_X14_Y12_N0
\u4|LessThan0~9\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|LessThan0~9_combout\ = (!\u4|clock:m[31]~q\ & (((!\u4|LessThan0~8_combout\) # (!\u4|LessThan0~2_combout\)) # (!\u4|LessThan0~1_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0001010101010101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u4|clock:m[31]~q\,
	datab => \u4|LessThan0~1_combout\,
	datac => \u4|LessThan0~2_combout\,
	datad => \u4|LessThan0~8_combout\,
	combout => \u4|LessThan0~9_combout\);

-- Location: LCCOMB_X14_Y12_N24
\u4|tclk~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|tclk~0_combout\ = \u4|tclk~q\ $ (\u4|LessThan0~9_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111111110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \u4|tclk~q\,
	datad => \u4|LessThan0~9_combout\,
	combout => \u4|tclk~0_combout\);

-- Location: FF_X14_Y12_N25
\u4|tclk\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u4|tclk~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|tclk~q\);

-- Location: LCCOMB_X19_Y21_N0
\u3|TrigerOut:m[0]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[0]~1_combout\ = \u3|TrigerOut:m[0]~q\ $ (VCC)
-- \u3|TrigerOut:m[0]~2\ = CARRY(\u3|TrigerOut:m[0]~q\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001111001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u3|TrigerOut:m[0]~q\,
	datad => VCC,
	combout => \u3|TrigerOut:m[0]~1_combout\,
	cout => \u3|TrigerOut:m[0]~2\);

-- Location: FF_X19_Y21_N1
\u3|TrigerOut:m[0]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[0]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[0]~q\);

-- Location: LCCOMB_X19_Y21_N2
\u3|TrigerOut:m[1]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[1]~1_combout\ = (\u3|TrigerOut:m[1]~q\ & (!\u3|TrigerOut:m[0]~2\)) # (!\u3|TrigerOut:m[1]~q\ & ((\u3|TrigerOut:m[0]~2\) # (GND)))
-- \u3|TrigerOut:m[1]~2\ = CARRY((!\u3|TrigerOut:m[0]~2\) # (!\u3|TrigerOut:m[1]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u3|TrigerOut:m[1]~q\,
	datad => VCC,
	cin => \u3|TrigerOut:m[0]~2\,
	combout => \u3|TrigerOut:m[1]~1_combout\,
	cout => \u3|TrigerOut:m[1]~2\);

-- Location: FF_X19_Y21_N3
\u3|TrigerOut:m[1]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[1]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[1]~q\);

-- Location: LCCOMB_X19_Y21_N4
\u3|TrigerOut:m[2]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[2]~1_combout\ = (\u3|TrigerOut:m[2]~q\ & (\u3|TrigerOut:m[1]~2\ $ (GND))) # (!\u3|TrigerOut:m[2]~q\ & (!\u3|TrigerOut:m[1]~2\ & VCC))
-- \u3|TrigerOut:m[2]~2\ = CARRY((\u3|TrigerOut:m[2]~q\ & !\u3|TrigerOut:m[1]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u3|TrigerOut:m[2]~q\,
	datad => VCC,
	cin => \u3|TrigerOut:m[1]~2\,
	combout => \u3|TrigerOut:m[2]~1_combout\,
	cout => \u3|TrigerOut:m[2]~2\);

-- Location: FF_X19_Y21_N5
\u3|TrigerOut:m[2]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[2]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[2]~q\);

-- Location: LCCOMB_X19_Y21_N8
\u3|TrigerOut:m[4]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[4]~1_combout\ = (\u3|TrigerOut:m[4]~q\ & (\u3|TrigerOut:m[3]~2\ $ (GND))) # (!\u3|TrigerOut:m[4]~q\ & (!\u3|TrigerOut:m[3]~2\ & VCC))
-- \u3|TrigerOut:m[4]~2\ = CARRY((\u3|TrigerOut:m[4]~q\ & !\u3|TrigerOut:m[3]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u3|TrigerOut:m[4]~q\,
	datad => VCC,
	cin => \u3|TrigerOut:m[3]~2\,
	combout => \u3|TrigerOut:m[4]~1_combout\,
	cout => \u3|TrigerOut:m[4]~2\);

-- Location: FF_X19_Y21_N9
\u3|TrigerOut:m[4]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[4]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[4]~q\);

-- Location: LCCOMB_X19_Y21_N10
\u3|TrigerOut:m[5]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[5]~1_combout\ = (\u3|TrigerOut:m[5]~q\ & (!\u3|TrigerOut:m[4]~2\)) # (!\u3|TrigerOut:m[5]~q\ & ((\u3|TrigerOut:m[4]~2\) # (GND)))
-- \u3|TrigerOut:m[5]~2\ = CARRY((!\u3|TrigerOut:m[4]~2\) # (!\u3|TrigerOut:m[5]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u3|TrigerOut:m[5]~q\,
	datad => VCC,
	cin => \u3|TrigerOut:m[4]~2\,
	combout => \u3|TrigerOut:m[5]~1_combout\,
	cout => \u3|TrigerOut:m[5]~2\);

-- Location: LCCOMB_X19_Y21_N12
\u3|TrigerOut:m[6]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[6]~1_combout\ = (\u3|TrigerOut:m[6]~q\ & (\u3|TrigerOut:m[5]~2\ $ (GND))) # (!\u3|TrigerOut:m[6]~q\ & (!\u3|TrigerOut:m[5]~2\ & VCC))
-- \u3|TrigerOut:m[6]~2\ = CARRY((\u3|TrigerOut:m[6]~q\ & !\u3|TrigerOut:m[5]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u3|TrigerOut:m[6]~q\,
	datad => VCC,
	cin => \u3|TrigerOut:m[5]~2\,
	combout => \u3|TrigerOut:m[6]~1_combout\,
	cout => \u3|TrigerOut:m[6]~2\);

-- Location: LCCOMB_X19_Y21_N14
\u3|TrigerOut:m[7]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[7]~1_combout\ = (\u3|TrigerOut:m[7]~q\ & (!\u3|TrigerOut:m[6]~2\)) # (!\u3|TrigerOut:m[7]~q\ & ((\u3|TrigerOut:m[6]~2\) # (GND)))
-- \u3|TrigerOut:m[7]~2\ = CARRY((!\u3|TrigerOut:m[6]~2\) # (!\u3|TrigerOut:m[7]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u3|TrigerOut:m[7]~q\,
	datad => VCC,
	cin => \u3|TrigerOut:m[6]~2\,
	combout => \u3|TrigerOut:m[7]~1_combout\,
	cout => \u3|TrigerOut:m[7]~2\);

-- Location: FF_X19_Y21_N15
\u3|TrigerOut:m[7]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[7]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[7]~q\);

-- Location: LCCOMB_X19_Y21_N16
\u3|TrigerOut:m[8]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[8]~1_combout\ = (\u3|TrigerOut:m[8]~q\ & (\u3|TrigerOut:m[7]~2\ $ (GND))) # (!\u3|TrigerOut:m[8]~q\ & (!\u3|TrigerOut:m[7]~2\ & VCC))
-- \u3|TrigerOut:m[8]~2\ = CARRY((\u3|TrigerOut:m[8]~q\ & !\u3|TrigerOut:m[7]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u3|TrigerOut:m[8]~q\,
	datad => VCC,
	cin => \u3|TrigerOut:m[7]~2\,
	combout => \u3|TrigerOut:m[8]~1_combout\,
	cout => \u3|TrigerOut:m[8]~2\);

-- Location: FF_X19_Y21_N17
\u3|TrigerOut:m[8]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[8]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[8]~q\);

-- Location: LCCOMB_X19_Y21_N18
\u3|TrigerOut:m[9]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[9]~1_combout\ = (\u3|TrigerOut:m[9]~q\ & (!\u3|TrigerOut:m[8]~2\)) # (!\u3|TrigerOut:m[9]~q\ & ((\u3|TrigerOut:m[8]~2\) # (GND)))
-- \u3|TrigerOut:m[9]~2\ = CARRY((!\u3|TrigerOut:m[8]~2\) # (!\u3|TrigerOut:m[9]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u3|TrigerOut:m[9]~q\,
	datad => VCC,
	cin => \u3|TrigerOut:m[8]~2\,
	combout => \u3|TrigerOut:m[9]~1_combout\,
	cout => \u3|TrigerOut:m[9]~2\);

-- Location: FF_X19_Y21_N19
\u3|TrigerOut:m[9]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[9]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[9]~q\);

-- Location: LCCOMB_X19_Y21_N20
\u3|TrigerOut:m[10]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[10]~1_combout\ = (\u3|TrigerOut:m[10]~q\ & (\u3|TrigerOut:m[9]~2\ $ (GND))) # (!\u3|TrigerOut:m[10]~q\ & (!\u3|TrigerOut:m[9]~2\ & VCC))
-- \u3|TrigerOut:m[10]~2\ = CARRY((\u3|TrigerOut:m[10]~q\ & !\u3|TrigerOut:m[9]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u3|TrigerOut:m[10]~q\,
	datad => VCC,
	cin => \u3|TrigerOut:m[9]~2\,
	combout => \u3|TrigerOut:m[10]~1_combout\,
	cout => \u3|TrigerOut:m[10]~2\);

-- Location: FF_X19_Y21_N21
\u3|TrigerOut:m[10]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[10]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[10]~q\);

-- Location: LCCOMB_X19_Y21_N22
\u3|TrigerOut:m[11]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[11]~1_combout\ = (\u3|TrigerOut:m[11]~q\ & (!\u3|TrigerOut:m[10]~2\)) # (!\u3|TrigerOut:m[11]~q\ & ((\u3|TrigerOut:m[10]~2\) # (GND)))
-- \u3|TrigerOut:m[11]~2\ = CARRY((!\u3|TrigerOut:m[10]~2\) # (!\u3|TrigerOut:m[11]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u3|TrigerOut:m[11]~q\,
	datad => VCC,
	cin => \u3|TrigerOut:m[10]~2\,
	combout => \u3|TrigerOut:m[11]~1_combout\,
	cout => \u3|TrigerOut:m[11]~2\);

-- Location: LCCOMB_X19_Y21_N24
\u3|TrigerOut:m[12]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[12]~1_combout\ = (\u3|TrigerOut:m[12]~q\ & (\u3|TrigerOut:m[11]~2\ $ (GND))) # (!\u3|TrigerOut:m[12]~q\ & (!\u3|TrigerOut:m[11]~2\ & VCC))
-- \u3|TrigerOut:m[12]~2\ = CARRY((\u3|TrigerOut:m[12]~q\ & !\u3|TrigerOut:m[11]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u3|TrigerOut:m[12]~q\,
	datad => VCC,
	cin => \u3|TrigerOut:m[11]~2\,
	combout => \u3|TrigerOut:m[12]~1_combout\,
	cout => \u3|TrigerOut:m[12]~2\);

-- Location: FF_X19_Y21_N25
\u3|TrigerOut:m[12]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[12]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[12]~q\);

-- Location: LCCOMB_X19_Y21_N26
\u3|TrigerOut:m[13]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[13]~1_combout\ = (\u3|TrigerOut:m[13]~q\ & (!\u3|TrigerOut:m[12]~2\)) # (!\u3|TrigerOut:m[13]~q\ & ((\u3|TrigerOut:m[12]~2\) # (GND)))
-- \u3|TrigerOut:m[13]~2\ = CARRY((!\u3|TrigerOut:m[12]~2\) # (!\u3|TrigerOut:m[13]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u3|TrigerOut:m[13]~q\,
	datad => VCC,
	cin => \u3|TrigerOut:m[12]~2\,
	combout => \u3|TrigerOut:m[13]~1_combout\,
	cout => \u3|TrigerOut:m[13]~2\);

-- Location: LCCOMB_X19_Y21_N28
\u3|TrigerOut:m[14]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[14]~1_combout\ = (\u3|TrigerOut:m[14]~q\ & (\u3|TrigerOut:m[13]~2\ $ (GND))) # (!\u3|TrigerOut:m[14]~q\ & (!\u3|TrigerOut:m[13]~2\ & VCC))
-- \u3|TrigerOut:m[14]~2\ = CARRY((\u3|TrigerOut:m[14]~q\ & !\u3|TrigerOut:m[13]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u3|TrigerOut:m[14]~q\,
	datad => VCC,
	cin => \u3|TrigerOut:m[13]~2\,
	combout => \u3|TrigerOut:m[14]~1_combout\,
	cout => \u3|TrigerOut:m[14]~2\);

-- Location: FF_X19_Y21_N29
\u3|TrigerOut:m[14]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[14]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[14]~q\);

-- Location: LCCOMB_X19_Y20_N0
\u3|TrigerOut:m[16]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[16]~1_combout\ = (\u3|TrigerOut:m[16]~q\ & (\u3|TrigerOut:m[15]~2\ $ (GND))) # (!\u3|TrigerOut:m[16]~q\ & (!\u3|TrigerOut:m[15]~2\ & VCC))
-- \u3|TrigerOut:m[16]~2\ = CARRY((\u3|TrigerOut:m[16]~q\ & !\u3|TrigerOut:m[15]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u3|TrigerOut:m[16]~q\,
	datad => VCC,
	cin => \u3|TrigerOut:m[15]~2\,
	combout => \u3|TrigerOut:m[16]~1_combout\,
	cout => \u3|TrigerOut:m[16]~2\);

-- Location: FF_X19_Y20_N1
\u3|TrigerOut:m[16]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[16]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[16]~q\);

-- Location: LCCOMB_X19_Y20_N2
\u3|TrigerOut:m[17]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[17]~1_combout\ = (\u3|TrigerOut:m[17]~q\ & (!\u3|TrigerOut:m[16]~2\)) # (!\u3|TrigerOut:m[17]~q\ & ((\u3|TrigerOut:m[16]~2\) # (GND)))
-- \u3|TrigerOut:m[17]~2\ = CARRY((!\u3|TrigerOut:m[16]~2\) # (!\u3|TrigerOut:m[17]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u3|TrigerOut:m[17]~q\,
	datad => VCC,
	cin => \u3|TrigerOut:m[16]~2\,
	combout => \u3|TrigerOut:m[17]~1_combout\,
	cout => \u3|TrigerOut:m[17]~2\);

-- Location: FF_X19_Y20_N3
\u3|TrigerOut:m[17]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[17]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[17]~q\);

-- Location: LCCOMB_X19_Y20_N4
\u3|TrigerOut:m[18]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[18]~1_combout\ = (\u3|TrigerOut:m[18]~q\ & (\u3|TrigerOut:m[17]~2\ $ (GND))) # (!\u3|TrigerOut:m[18]~q\ & (!\u3|TrigerOut:m[17]~2\ & VCC))
-- \u3|TrigerOut:m[18]~2\ = CARRY((\u3|TrigerOut:m[18]~q\ & !\u3|TrigerOut:m[17]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u3|TrigerOut:m[18]~q\,
	datad => VCC,
	cin => \u3|TrigerOut:m[17]~2\,
	combout => \u3|TrigerOut:m[18]~1_combout\,
	cout => \u3|TrigerOut:m[18]~2\);

-- Location: FF_X19_Y20_N5
\u3|TrigerOut:m[18]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[18]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[18]~q\);

-- Location: LCCOMB_X19_Y20_N6
\u3|TrigerOut:m[19]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[19]~1_combout\ = (\u3|TrigerOut:m[19]~q\ & (!\u3|TrigerOut:m[18]~2\)) # (!\u3|TrigerOut:m[19]~q\ & ((\u3|TrigerOut:m[18]~2\) # (GND)))
-- \u3|TrigerOut:m[19]~2\ = CARRY((!\u3|TrigerOut:m[18]~2\) # (!\u3|TrigerOut:m[19]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u3|TrigerOut:m[19]~q\,
	datad => VCC,
	cin => \u3|TrigerOut:m[18]~2\,
	combout => \u3|TrigerOut:m[19]~1_combout\,
	cout => \u3|TrigerOut:m[19]~2\);

-- Location: LCCOMB_X19_Y20_N8
\u3|TrigerOut:m[20]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[20]~1_combout\ = (\u3|TrigerOut:m[20]~q\ & (\u3|TrigerOut:m[19]~2\ $ (GND))) # (!\u3|TrigerOut:m[20]~q\ & (!\u3|TrigerOut:m[19]~2\ & VCC))
-- \u3|TrigerOut:m[20]~2\ = CARRY((\u3|TrigerOut:m[20]~q\ & !\u3|TrigerOut:m[19]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u3|TrigerOut:m[20]~q\,
	datad => VCC,
	cin => \u3|TrigerOut:m[19]~2\,
	combout => \u3|TrigerOut:m[20]~1_combout\,
	cout => \u3|TrigerOut:m[20]~2\);

-- Location: FF_X19_Y20_N9
\u3|TrigerOut:m[20]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[20]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[20]~q\);

-- Location: LCCOMB_X19_Y20_N12
\u3|TrigerOut:m[22]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[22]~1_combout\ = (\u3|TrigerOut:m[22]~q\ & (\u3|TrigerOut:m[21]~2\ $ (GND))) # (!\u3|TrigerOut:m[22]~q\ & (!\u3|TrigerOut:m[21]~2\ & VCC))
-- \u3|TrigerOut:m[22]~2\ = CARRY((\u3|TrigerOut:m[22]~q\ & !\u3|TrigerOut:m[21]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u3|TrigerOut:m[22]~q\,
	datad => VCC,
	cin => \u3|TrigerOut:m[21]~2\,
	combout => \u3|TrigerOut:m[22]~1_combout\,
	cout => \u3|TrigerOut:m[22]~2\);

-- Location: LCCOMB_X19_Y20_N14
\u3|TrigerOut:m[23]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[23]~1_combout\ = (\u3|TrigerOut:m[23]~q\ & (!\u3|TrigerOut:m[22]~2\)) # (!\u3|TrigerOut:m[23]~q\ & ((\u3|TrigerOut:m[22]~2\) # (GND)))
-- \u3|TrigerOut:m[23]~2\ = CARRY((!\u3|TrigerOut:m[22]~2\) # (!\u3|TrigerOut:m[23]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u3|TrigerOut:m[23]~q\,
	datad => VCC,
	cin => \u3|TrigerOut:m[22]~2\,
	combout => \u3|TrigerOut:m[23]~1_combout\,
	cout => \u3|TrigerOut:m[23]~2\);

-- Location: FF_X19_Y20_N15
\u3|TrigerOut:m[23]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[23]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[23]~q\);

-- Location: LCCOMB_X19_Y20_N16
\u3|TrigerOut:m[24]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[24]~1_combout\ = (\u3|TrigerOut:m[24]~q\ & (\u3|TrigerOut:m[23]~2\ $ (GND))) # (!\u3|TrigerOut:m[24]~q\ & (!\u3|TrigerOut:m[23]~2\ & VCC))
-- \u3|TrigerOut:m[24]~2\ = CARRY((\u3|TrigerOut:m[24]~q\ & !\u3|TrigerOut:m[23]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u3|TrigerOut:m[24]~q\,
	datad => VCC,
	cin => \u3|TrigerOut:m[23]~2\,
	combout => \u3|TrigerOut:m[24]~1_combout\,
	cout => \u3|TrigerOut:m[24]~2\);

-- Location: FF_X19_Y20_N17
\u3|TrigerOut:m[24]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[24]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[24]~q\);

-- Location: LCCOMB_X19_Y20_N18
\u3|TrigerOut:m[25]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[25]~1_combout\ = (\u3|TrigerOut:m[25]~q\ & (!\u3|TrigerOut:m[24]~2\)) # (!\u3|TrigerOut:m[25]~q\ & ((\u3|TrigerOut:m[24]~2\) # (GND)))
-- \u3|TrigerOut:m[25]~2\ = CARRY((!\u3|TrigerOut:m[24]~2\) # (!\u3|TrigerOut:m[25]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u3|TrigerOut:m[25]~q\,
	datad => VCC,
	cin => \u3|TrigerOut:m[24]~2\,
	combout => \u3|TrigerOut:m[25]~1_combout\,
	cout => \u3|TrigerOut:m[25]~2\);

-- Location: FF_X19_Y20_N19
\u3|TrigerOut:m[25]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[25]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[25]~q\);

-- Location: LCCOMB_X19_Y20_N20
\u3|TrigerOut:m[26]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[26]~1_combout\ = (\u3|TrigerOut:m[26]~q\ & (\u3|TrigerOut:m[25]~2\ $ (GND))) # (!\u3|TrigerOut:m[26]~q\ & (!\u3|TrigerOut:m[25]~2\ & VCC))
-- \u3|TrigerOut:m[26]~2\ = CARRY((\u3|TrigerOut:m[26]~q\ & !\u3|TrigerOut:m[25]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u3|TrigerOut:m[26]~q\,
	datad => VCC,
	cin => \u3|TrigerOut:m[25]~2\,
	combout => \u3|TrigerOut:m[26]~1_combout\,
	cout => \u3|TrigerOut:m[26]~2\);

-- Location: FF_X19_Y20_N21
\u3|TrigerOut:m[26]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[26]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[26]~q\);

-- Location: LCCOMB_X19_Y20_N24
\u3|TrigerOut:m[28]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[28]~1_combout\ = (\u3|TrigerOut:m[28]~q\ & (\u3|TrigerOut:m[27]~2\ $ (GND))) # (!\u3|TrigerOut:m[28]~q\ & (!\u3|TrigerOut:m[27]~2\ & VCC))
-- \u3|TrigerOut:m[28]~2\ = CARRY((\u3|TrigerOut:m[28]~q\ & !\u3|TrigerOut:m[27]~2\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u3|TrigerOut:m[28]~q\,
	datad => VCC,
	cin => \u3|TrigerOut:m[27]~2\,
	combout => \u3|TrigerOut:m[28]~1_combout\,
	cout => \u3|TrigerOut:m[28]~2\);

-- Location: FF_X19_Y20_N25
\u3|TrigerOut:m[28]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[28]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[28]~q\);

-- Location: LCCOMB_X19_Y20_N26
\u3|TrigerOut:m[29]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|TrigerOut:m[29]~1_combout\ = (\u3|TrigerOut:m[29]~q\ & (!\u3|TrigerOut:m[28]~2\)) # (!\u3|TrigerOut:m[29]~q\ & ((\u3|TrigerOut:m[28]~2\) # (GND)))
-- \u3|TrigerOut:m[29]~2\ = CARRY((!\u3|TrigerOut:m[28]~2\) # (!\u3|TrigerOut:m[29]~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u3|TrigerOut:m[29]~q\,
	datad => VCC,
	cin => \u3|TrigerOut:m[28]~2\,
	combout => \u3|TrigerOut:m[29]~1_combout\,
	cout => \u3|TrigerOut:m[29]~2\);

-- Location: FF_X19_Y20_N29
\u3|TrigerOut:m[30]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[30]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[30]~q\);

-- Location: FF_X19_Y20_N27
\u3|TrigerOut:m[29]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[29]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[29]~q\);

-- Location: LCCOMB_X18_Y20_N20
\u3|LessThan0~3\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|LessThan0~3_combout\ = (!\u3|TrigerOut:m[30]~q\ & !\u3|TrigerOut:m[29]~q\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000110011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u3|TrigerOut:m[30]~q\,
	datad => \u3|TrigerOut:m[29]~q\,
	combout => \u3|LessThan0~3_combout\);

-- Location: FF_X19_Y20_N7
\u3|TrigerOut:m[19]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[19]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[19]~q\);

-- Location: LCCOMB_X18_Y20_N28
\u3|LessThan0~5\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|LessThan0~5_combout\ = (!\u3|TrigerOut:m[17]~q\ & (!\u3|TrigerOut:m[20]~q\ & (!\u3|TrigerOut:m[18]~q\ & !\u3|TrigerOut:m[19]~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000000001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u3|TrigerOut:m[17]~q\,
	datab => \u3|TrigerOut:m[20]~q\,
	datac => \u3|TrigerOut:m[18]~q\,
	datad => \u3|TrigerOut:m[19]~q\,
	combout => \u3|LessThan0~5_combout\);

-- Location: FF_X19_Y20_N13
\u3|TrigerOut:m[22]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[22]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[22]~q\);

-- Location: LCCOMB_X18_Y20_N14
\u3|LessThan0~6\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|LessThan0~6_combout\ = (!\u3|TrigerOut:m[21]~q\ & (!\u3|TrigerOut:m[22]~q\ & (!\u3|TrigerOut:m[23]~q\ & !\u3|TrigerOut:m[24]~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000000001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u3|TrigerOut:m[21]~q\,
	datab => \u3|TrigerOut:m[22]~q\,
	datac => \u3|TrigerOut:m[23]~q\,
	datad => \u3|TrigerOut:m[24]~q\,
	combout => \u3|LessThan0~6_combout\);

-- Location: FF_X19_Y21_N27
\u3|TrigerOut:m[13]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[13]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[13]~q\);

-- Location: LCCOMB_X18_Y20_N6
\u3|LessThan0~4\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|LessThan0~4_combout\ = (!\u3|TrigerOut:m[15]~q\ & (!\u3|TrigerOut:m[16]~q\ & (!\u3|TrigerOut:m[13]~q\ & !\u3|TrigerOut:m[14]~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000000001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u3|TrigerOut:m[15]~q\,
	datab => \u3|TrigerOut:m[16]~q\,
	datac => \u3|TrigerOut:m[13]~q\,
	datad => \u3|TrigerOut:m[14]~q\,
	combout => \u3|LessThan0~4_combout\);

-- Location: LCCOMB_X18_Y20_N26
\u3|LessThan0~8\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|LessThan0~8_combout\ = (\u3|LessThan0~7_combout\ & (\u3|LessThan0~5_combout\ & (\u3|LessThan0~6_combout\ & \u3|LessThan0~4_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u3|LessThan0~7_combout\,
	datab => \u3|LessThan0~5_combout\,
	datac => \u3|LessThan0~6_combout\,
	datad => \u3|LessThan0~4_combout\,
	combout => \u3|LessThan0~8_combout\);

-- Location: FF_X19_Y21_N23
\u3|TrigerOut:m[11]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[11]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[11]~q\);

-- Location: FF_X19_Y21_N13
\u3|TrigerOut:m[6]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[6]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[6]~q\);

-- Location: FF_X19_Y21_N11
\u3|TrigerOut:m[5]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|TrigerOut:m[5]~1_combout\,
	sclr => \u3|LessThan0~9_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|TrigerOut:m[5]~q\);

-- Location: LCCOMB_X18_Y20_N2
\u3|LessThan0~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|LessThan0~0_combout\ = (!\u3|TrigerOut:m[3]~q\ & (!\u3|TrigerOut:m[4]~q\ & (!\u3|TrigerOut:m[6]~q\ & !\u3|TrigerOut:m[5]~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000000001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u3|TrigerOut:m[3]~q\,
	datab => \u3|TrigerOut:m[4]~q\,
	datac => \u3|TrigerOut:m[6]~q\,
	datad => \u3|TrigerOut:m[5]~q\,
	combout => \u3|LessThan0~0_combout\);

-- Location: LCCOMB_X18_Y20_N16
\u3|LessThan0~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|LessThan0~1_combout\ = (((\u3|LessThan0~0_combout\) # (!\u3|TrigerOut:m[8]~q\)) # (!\u3|TrigerOut:m[7]~q\)) # (!\u3|TrigerOut:m[9]~q\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111101111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u3|TrigerOut:m[9]~q\,
	datab => \u3|TrigerOut:m[7]~q\,
	datac => \u3|TrigerOut:m[8]~q\,
	datad => \u3|LessThan0~0_combout\,
	combout => \u3|LessThan0~1_combout\);

-- Location: LCCOMB_X18_Y20_N10
\u3|LessThan0~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|LessThan0~2_combout\ = ((!\u3|TrigerOut:m[10]~q\ & (!\u3|TrigerOut:m[11]~q\ & \u3|LessThan0~1_combout\))) # (!\u3|TrigerOut:m[12]~q\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0001111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u3|TrigerOut:m[10]~q\,
	datab => \u3|TrigerOut:m[11]~q\,
	datac => \u3|TrigerOut:m[12]~q\,
	datad => \u3|LessThan0~1_combout\,
	combout => \u3|LessThan0~2_combout\);

-- Location: LCCOMB_X18_Y20_N4
\u3|LessThan0~9\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|LessThan0~9_combout\ = (!\u3|TrigerOut:m[31]~q\ & (((!\u3|LessThan0~2_combout\) # (!\u3|LessThan0~8_combout\)) # (!\u3|LessThan0~3_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0001010101010101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u3|TrigerOut:m[31]~q\,
	datab => \u3|LessThan0~3_combout\,
	datac => \u3|LessThan0~8_combout\,
	datad => \u3|LessThan0~2_combout\,
	combout => \u3|LessThan0~9_combout\);

-- Location: LCCOMB_X18_Y20_N24
\u3|tclk~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|tclk~0_combout\ = \u3|LessThan0~9_combout\ $ (\u3|tclk~q\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u3|LessThan0~9_combout\,
	datac => \u3|tclk~q\,
	combout => \u3|tclk~0_combout\);

-- Location: FF_X18_Y20_N25
\u3|tclk\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \u3|tclk~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|tclk~q\);

-- Location: IOIBUF_X34_Y9_N22
\HS_Echo~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_HS_Echo,
	o => \HS_Echo~input_o\);

-- Location: IOIBUF_X34_Y5_N15
\IR2_input~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_IR2_input,
	o => \IR2_input~input_o\);

-- Location: IOIBUF_X34_Y3_N15
\IR1_input~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_IR1_input,
	o => \IR1_input~input_o\);

ww_STM1_output(0) <= \STM1_output[0]~output_o\;

ww_STM1_output(1) <= \STM1_output[1]~output_o\;

ww_STM1_output(2) <= \STM1_output[2]~output_o\;

ww_STM1_output(3) <= \STM1_output[3]~output_o\;

ww_STM2_output(0) <= \STM2_output[0]~output_o\;

ww_STM2_output(1) <= \STM2_output[1]~output_o\;

ww_STM2_output(2) <= \STM2_output[2]~output_o\;

ww_STM2_output(3) <= \STM2_output[3]~output_o\;

ww_SBM_output <= \SBM_output~output_o\;

ww_HS_Trigger <= \HS_Trigger~output_o\;
END structure;


