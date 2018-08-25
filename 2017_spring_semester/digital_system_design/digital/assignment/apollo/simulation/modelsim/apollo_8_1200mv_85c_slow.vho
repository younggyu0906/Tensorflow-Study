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

-- DATE "05/08/2017 15:25:30"

-- 
-- Device: Altera EP4CE6E22C8 Package TQFP144
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY CYCLONEIVE;
LIBRARY IEEE;
LIBRARY STD;
USE CYCLONEIVE.CYCLONEIVE_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;
USE STD.STANDARD.ALL;

ENTITY 	apollo IS
    PORT (
	battery_voltage : IN STD.STANDARD.integer;
	red_led : OUT std_logic;
	green_led : OUT std_logic;
	yellow_led : OUT std_logic
	);
END apollo;

-- Design Ports Information
-- red_led	=>  Location: PIN_111,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- green_led	=>  Location: PIN_77,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- yellow_led	=>  Location: PIN_100,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[3]	=>  Location: PIN_74,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[2]	=>  Location: PIN_71,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[0]	=>  Location: PIN_103,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[1]	=>  Location: PIN_85,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[4]	=>  Location: PIN_104,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[5]	=>  Location: PIN_73,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[6]	=>  Location: PIN_114,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[7]	=>  Location: PIN_68,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[8]	=>  Location: PIN_87,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[9]	=>  Location: PIN_99,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[10]	=>  Location: PIN_88,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[11]	=>  Location: PIN_89,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[12]	=>  Location: PIN_98,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[13]	=>  Location: PIN_126,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[14]	=>  Location: PIN_106,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[15]	=>  Location: PIN_132,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[16]	=>  Location: PIN_80,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[17]	=>  Location: PIN_119,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[18]	=>  Location: PIN_124,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[19]	=>  Location: PIN_112,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[20]	=>  Location: PIN_86,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[21]	=>  Location: PIN_113,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[22]	=>  Location: PIN_84,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[23]	=>  Location: PIN_110,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[24]	=>  Location: PIN_105,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[25]	=>  Location: PIN_128,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[26]	=>  Location: PIN_90,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[27]	=>  Location: PIN_91,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[28]	=>  Location: PIN_83,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[29]	=>  Location: PIN_75,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[30]	=>  Location: PIN_115,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- battery_voltage[31]	=>  Location: PIN_76,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF apollo IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_battery_voltage : std_logic_vector(31 DOWNTO 0);
SIGNAL ww_red_led : std_logic;
SIGNAL ww_green_led : std_logic;
SIGNAL ww_yellow_led : std_logic;
SIGNAL \green_led~1_combout\ : std_logic;
SIGNAL \green_led~5_combout\ : std_logic;
SIGNAL \battery_voltage[7]~input_o\ : std_logic;
SIGNAL \battery_voltage[8]~input_o\ : std_logic;
SIGNAL \battery_voltage[9]~input_o\ : std_logic;
SIGNAL \battery_voltage[10]~input_o\ : std_logic;
SIGNAL \battery_voltage[11]~input_o\ : std_logic;
SIGNAL \battery_voltage[12]~input_o\ : std_logic;
SIGNAL \battery_voltage[18]~input_o\ : std_logic;
SIGNAL \battery_voltage[20]~input_o\ : std_logic;
SIGNAL \battery_voltage[21]~input_o\ : std_logic;
SIGNAL \battery_voltage[22]~input_o\ : std_logic;
SIGNAL \battery_voltage[23]~input_o\ : std_logic;
SIGNAL \battery_voltage[24]~input_o\ : std_logic;
SIGNAL \battery_voltage[30]~input_o\ : std_logic;
SIGNAL \red_led~output_o\ : std_logic;
SIGNAL \green_led~output_o\ : std_logic;
SIGNAL \yellow_led~output_o\ : std_logic;
SIGNAL \battery_voltage[27]~input_o\ : std_logic;
SIGNAL \battery_voltage[26]~input_o\ : std_logic;
SIGNAL \battery_voltage[25]~input_o\ : std_logic;
SIGNAL \green_led~6_combout\ : std_logic;
SIGNAL \battery_voltage[6]~input_o\ : std_logic;
SIGNAL \battery_voltage[5]~input_o\ : std_logic;
SIGNAL \battery_voltage[4]~input_o\ : std_logic;
SIGNAL \green_led~0_combout\ : std_logic;
SIGNAL \battery_voltage[17]~input_o\ : std_logic;
SIGNAL \battery_voltage[19]~input_o\ : std_logic;
SIGNAL \battery_voltage[16]~input_o\ : std_logic;
SIGNAL \green_led~3_combout\ : std_logic;
SIGNAL \battery_voltage[13]~input_o\ : std_logic;
SIGNAL \battery_voltage[15]~input_o\ : std_logic;
SIGNAL \battery_voltage[14]~input_o\ : std_logic;
SIGNAL \green_led~2_combout\ : std_logic;
SIGNAL \green_led~4_combout\ : std_logic;
SIGNAL \battery_voltage[2]~input_o\ : std_logic;
SIGNAL \battery_voltage[3]~input_o\ : std_logic;
SIGNAL \battery_voltage[0]~input_o\ : std_logic;
SIGNAL \LessThan0~1_combout\ : std_logic;
SIGNAL \LessThan0~2_combout\ : std_logic;
SIGNAL \battery_voltage[29]~input_o\ : std_logic;
SIGNAL \battery_voltage[28]~input_o\ : std_logic;
SIGNAL \green_led~7_combout\ : std_logic;
SIGNAL \green_led~8_combout\ : std_logic;
SIGNAL \battery_voltage[1]~input_o\ : std_logic;
SIGNAL \LessThan0~0_combout\ : std_logic;
SIGNAL \LessThan1~0_combout\ : std_logic;
SIGNAL \battery_voltage[31]~input_o\ : std_logic;
SIGNAL \red_led~2_combout\ : std_logic;
SIGNAL \green_led~9_combout\ : std_logic;
SIGNAL \green_led~10_combout\ : std_logic;
SIGNAL \yellow_led~2_combout\ : std_logic;
SIGNAL \ALT_INV_yellow_led~2_combout\ : std_logic;

BEGIN

ww_battery_voltage <= IEEE.STD_LOGIC_ARITH.CONV_STD_LOGIC_VECTOR(battery_voltage, 32);
red_led <= ww_red_led;
green_led <= ww_green_led;
yellow_led <= ww_yellow_led;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
\ALT_INV_yellow_led~2_combout\ <= NOT \yellow_led~2_combout\;

-- Location: LCCOMB_X33_Y8_N12
\green_led~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \green_led~1_combout\ = (!\battery_voltage[10]~input_o\ & (!\battery_voltage[8]~input_o\ & (!\battery_voltage[11]~input_o\ & !\battery_voltage[9]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000000001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \battery_voltage[10]~input_o\,
	datab => \battery_voltage[8]~input_o\,
	datac => \battery_voltage[11]~input_o\,
	datad => \battery_voltage[9]~input_o\,
	combout => \green_led~1_combout\);

-- Location: LCCOMB_X33_Y8_N10
\green_led~5\ : cycloneive_lcell_comb
-- Equation(s):
-- \green_led~5_combout\ = (!\battery_voltage[21]~input_o\ & (!\battery_voltage[22]~input_o\ & (!\battery_voltage[23]~input_o\ & !\battery_voltage[20]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000000001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \battery_voltage[21]~input_o\,
	datab => \battery_voltage[22]~input_o\,
	datac => \battery_voltage[23]~input_o\,
	datad => \battery_voltage[20]~input_o\,
	combout => \green_led~5_combout\);

-- Location: IOIBUF_X30_Y0_N8
\battery_voltage[7]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(7),
	o => \battery_voltage[7]~input_o\);

-- Location: IOIBUF_X34_Y10_N8
\battery_voltage[8]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(8),
	o => \battery_voltage[8]~input_o\);

-- Location: IOIBUF_X34_Y17_N15
\battery_voltage[9]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(9),
	o => \battery_voltage[9]~input_o\);

-- Location: IOIBUF_X34_Y12_N22
\battery_voltage[10]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(10),
	o => \battery_voltage[10]~input_o\);

-- Location: IOIBUF_X34_Y12_N15
\battery_voltage[11]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(11),
	o => \battery_voltage[11]~input_o\);

-- Location: IOIBUF_X34_Y17_N22
\battery_voltage[12]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(12),
	o => \battery_voltage[12]~input_o\);

-- Location: IOIBUF_X18_Y24_N15
\battery_voltage[18]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(18),
	o => \battery_voltage[18]~input_o\);

-- Location: IOIBUF_X34_Y9_N1
\battery_voltage[20]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(20),
	o => \battery_voltage[20]~input_o\);

-- Location: IOIBUF_X28_Y24_N8
\battery_voltage[21]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(21),
	o => \battery_voltage[21]~input_o\);

-- Location: IOIBUF_X34_Y9_N15
\battery_voltage[22]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(22),
	o => \battery_voltage[22]~input_o\);

-- Location: IOIBUF_X30_Y24_N1
\battery_voltage[23]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(23),
	o => \battery_voltage[23]~input_o\);

-- Location: IOIBUF_X34_Y19_N15
\battery_voltage[24]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(24),
	o => \battery_voltage[24]~input_o\);

-- Location: IOIBUF_X28_Y24_N22
\battery_voltage[30]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(30),
	o => \battery_voltage[30]~input_o\);

-- Location: IOOBUF_X30_Y24_N23
\red_led~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \red_led~2_combout\,
	devoe => ww_devoe,
	o => \red_led~output_o\);

-- Location: IOOBUF_X34_Y4_N16
\green_led~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \green_led~10_combout\,
	devoe => ww_devoe,
	o => \green_led~output_o\);

-- Location: IOOBUF_X34_Y17_N2
\yellow_led~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \ALT_INV_yellow_led~2_combout\,
	devoe => ww_devoe,
	o => \yellow_led~output_o\);

-- Location: IOIBUF_X34_Y12_N1
\battery_voltage[27]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(27),
	o => \battery_voltage[27]~input_o\);

-- Location: IOIBUF_X34_Y12_N8
\battery_voltage[26]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(26),
	o => \battery_voltage[26]~input_o\);

-- Location: IOIBUF_X16_Y24_N15
\battery_voltage[25]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(25),
	o => \battery_voltage[25]~input_o\);

-- Location: LCCOMB_X33_Y8_N28
\green_led~6\ : cycloneive_lcell_comb
-- Equation(s):
-- \green_led~6_combout\ = (!\battery_voltage[24]~input_o\ & (!\battery_voltage[27]~input_o\ & (!\battery_voltage[26]~input_o\ & !\battery_voltage[25]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000000001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \battery_voltage[24]~input_o\,
	datab => \battery_voltage[27]~input_o\,
	datac => \battery_voltage[26]~input_o\,
	datad => \battery_voltage[25]~input_o\,
	combout => \green_led~6_combout\);

-- Location: IOIBUF_X28_Y24_N15
\battery_voltage[6]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(6),
	o => \battery_voltage[6]~input_o\);

-- Location: IOIBUF_X34_Y2_N22
\battery_voltage[5]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(5),
	o => \battery_voltage[5]~input_o\);

-- Location: IOIBUF_X34_Y18_N1
\battery_voltage[4]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(4),
	o => \battery_voltage[4]~input_o\);

-- Location: LCCOMB_X33_Y8_N2
\green_led~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \green_led~0_combout\ = (!\battery_voltage[7]~input_o\ & (!\battery_voltage[6]~input_o\ & (!\battery_voltage[5]~input_o\ & !\battery_voltage[4]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000000001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \battery_voltage[7]~input_o\,
	datab => \battery_voltage[6]~input_o\,
	datac => \battery_voltage[5]~input_o\,
	datad => \battery_voltage[4]~input_o\,
	combout => \green_led~0_combout\);

-- Location: IOIBUF_X23_Y24_N1
\battery_voltage[17]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(17),
	o => \battery_voltage[17]~input_o\);

-- Location: IOIBUF_X28_Y24_N1
\battery_voltage[19]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(19),
	o => \battery_voltage[19]~input_o\);

-- Location: IOIBUF_X34_Y7_N8
\battery_voltage[16]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(16),
	o => \battery_voltage[16]~input_o\);

-- Location: LCCOMB_X33_Y8_N14
\green_led~3\ : cycloneive_lcell_comb
-- Equation(s):
-- \green_led~3_combout\ = (!\battery_voltage[18]~input_o\ & (!\battery_voltage[17]~input_o\ & (!\battery_voltage[19]~input_o\ & !\battery_voltage[16]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000000001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \battery_voltage[18]~input_o\,
	datab => \battery_voltage[17]~input_o\,
	datac => \battery_voltage[19]~input_o\,
	datad => \battery_voltage[16]~input_o\,
	combout => \green_led~3_combout\);

-- Location: IOIBUF_X16_Y24_N1
\battery_voltage[13]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(13),
	o => \battery_voltage[13]~input_o\);

-- Location: IOIBUF_X13_Y24_N15
\battery_voltage[15]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(15),
	o => \battery_voltage[15]~input_o\);

-- Location: IOIBUF_X34_Y20_N8
\battery_voltage[14]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(14),
	o => \battery_voltage[14]~input_o\);

-- Location: LCCOMB_X14_Y17_N0
\green_led~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \green_led~2_combout\ = (!\battery_voltage[12]~input_o\ & (!\battery_voltage[13]~input_o\ & (!\battery_voltage[15]~input_o\ & !\battery_voltage[14]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000000001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \battery_voltage[12]~input_o\,
	datab => \battery_voltage[13]~input_o\,
	datac => \battery_voltage[15]~input_o\,
	datad => \battery_voltage[14]~input_o\,
	combout => \green_led~2_combout\);

-- Location: LCCOMB_X33_Y8_N8
\green_led~4\ : cycloneive_lcell_comb
-- Equation(s):
-- \green_led~4_combout\ = (\green_led~1_combout\ & (\green_led~0_combout\ & (\green_led~3_combout\ & \green_led~2_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \green_led~1_combout\,
	datab => \green_led~0_combout\,
	datac => \green_led~3_combout\,
	datad => \green_led~2_combout\,
	combout => \green_led~4_combout\);

-- Location: IOIBUF_X32_Y0_N15
\battery_voltage[2]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(2),
	o => \battery_voltage[2]~input_o\);

-- Location: IOIBUF_X34_Y2_N15
\battery_voltage[3]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(3),
	o => \battery_voltage[3]~input_o\);

-- Location: IOIBUF_X34_Y18_N15
\battery_voltage[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(0),
	o => \battery_voltage[0]~input_o\);

-- Location: LCCOMB_X33_Y8_N20
\LessThan0~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \LessThan0~1_combout\ = (\battery_voltage[3]~input_o\) # ((\battery_voltage[1]~input_o\ & (\battery_voltage[2]~input_o\ & \battery_voltage[0]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111100011110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \battery_voltage[1]~input_o\,
	datab => \battery_voltage[2]~input_o\,
	datac => \battery_voltage[3]~input_o\,
	datad => \battery_voltage[0]~input_o\,
	combout => \LessThan0~1_combout\);

-- Location: LCCOMB_X33_Y8_N30
\LessThan0~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \LessThan0~2_combout\ = (((\LessThan0~1_combout\) # (!\green_led~4_combout\)) # (!\green_led~6_combout\)) # (!\green_led~5_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111101111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \green_led~5_combout\,
	datab => \green_led~6_combout\,
	datac => \green_led~4_combout\,
	datad => \LessThan0~1_combout\,
	combout => \LessThan0~2_combout\);

-- Location: IOIBUF_X34_Y3_N22
\battery_voltage[29]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(29),
	o => \battery_voltage[29]~input_o\);

-- Location: IOIBUF_X34_Y9_N22
\battery_voltage[28]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(28),
	o => \battery_voltage[28]~input_o\);

-- Location: LCCOMB_X33_Y8_N6
\green_led~7\ : cycloneive_lcell_comb
-- Equation(s):
-- \green_led~7_combout\ = (!\battery_voltage[30]~input_o\ & (!\battery_voltage[29]~input_o\ & !\battery_voltage[28]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000000101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \battery_voltage[30]~input_o\,
	datac => \battery_voltage[29]~input_o\,
	datad => \battery_voltage[28]~input_o\,
	combout => \green_led~7_combout\);

-- Location: LCCOMB_X33_Y8_N24
\green_led~8\ : cycloneive_lcell_comb
-- Equation(s):
-- \green_led~8_combout\ = (\green_led~5_combout\ & (\green_led~6_combout\ & (\green_led~4_combout\ & \green_led~7_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \green_led~5_combout\,
	datab => \green_led~6_combout\,
	datac => \green_led~4_combout\,
	datad => \green_led~7_combout\,
	combout => \green_led~8_combout\);

-- Location: IOIBUF_X34_Y9_N8
\battery_voltage[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(1),
	o => \battery_voltage[1]~input_o\);

-- Location: LCCOMB_X33_Y8_N0
\LessThan0~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \LessThan0~0_combout\ = (\battery_voltage[1]~input_o\ & \battery_voltage[0]~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \battery_voltage[1]~input_o\,
	datad => \battery_voltage[0]~input_o\,
	combout => \LessThan0~0_combout\);

-- Location: LCCOMB_X33_Y8_N18
\LessThan1~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \LessThan1~0_combout\ = ((\battery_voltage[3]~input_o\ & ((\battery_voltage[2]~input_o\) # (\LessThan0~0_combout\)))) # (!\green_led~8_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111001110110011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \battery_voltage[2]~input_o\,
	datab => \green_led~8_combout\,
	datac => \battery_voltage[3]~input_o\,
	datad => \LessThan0~0_combout\,
	combout => \LessThan1~0_combout\);

-- Location: IOIBUF_X34_Y4_N22
\battery_voltage[31]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_battery_voltage(31),
	o => \battery_voltage[31]~input_o\);

-- Location: LCCOMB_X33_Y8_N4
\red_led~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \red_led~2_combout\ = ((\battery_voltage[31]~input_o\) # ((!\LessThan0~2_combout\ & \green_led~7_combout\))) # (!\LessThan1~0_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111011111110011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \LessThan0~2_combout\,
	datab => \LessThan1~0_combout\,
	datac => \battery_voltage[31]~input_o\,
	datad => \green_led~7_combout\,
	combout => \red_led~2_combout\);

-- Location: LCCOMB_X33_Y8_N16
\green_led~9\ : cycloneive_lcell_comb
-- Equation(s):
-- \green_led~9_combout\ = (((!\battery_voltage[1]~input_o\ & !\battery_voltage[0]~input_o\)) # (!\battery_voltage[3]~input_o\)) # (!\battery_voltage[2]~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011111101111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \battery_voltage[1]~input_o\,
	datab => \battery_voltage[2]~input_o\,
	datac => \battery_voltage[3]~input_o\,
	datad => \battery_voltage[0]~input_o\,
	combout => \green_led~9_combout\);

-- Location: LCCOMB_X33_Y8_N26
\green_led~10\ : cycloneive_lcell_comb
-- Equation(s):
-- \green_led~10_combout\ = (!\battery_voltage[31]~input_o\ & (\green_led~8_combout\ & (\LessThan0~2_combout\ & \green_led~9_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0100000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \battery_voltage[31]~input_o\,
	datab => \green_led~8_combout\,
	datac => \LessThan0~2_combout\,
	datad => \green_led~9_combout\,
	combout => \green_led~10_combout\);

-- Location: LCCOMB_X33_Y8_N22
\yellow_led~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \yellow_led~2_combout\ = (\LessThan1~0_combout\) # ((\battery_voltage[31]~input_o\) # ((!\LessThan0~2_combout\ & \green_led~7_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110111111100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \LessThan0~2_combout\,
	datab => \LessThan1~0_combout\,
	datac => \battery_voltage[31]~input_o\,
	datad => \green_led~7_combout\,
	combout => \yellow_led~2_combout\);

ww_red_led <= \red_led~output_o\;

ww_green_led <= \green_led~output_o\;

ww_yellow_led <= \yellow_led~output_o\;
END structure;


