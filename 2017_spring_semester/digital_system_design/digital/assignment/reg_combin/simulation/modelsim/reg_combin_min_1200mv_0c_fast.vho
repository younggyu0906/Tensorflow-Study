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

-- DATE "05/08/2017 18:26:37"

-- 
-- Device: Altera EP4CE6F17C8 Package FBGA256
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY CYCLONEIVE;
LIBRARY IEEE;
USE CYCLONEIVE.CYCLONEIVE_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	reg_combin IS
    PORT (
	reg1 : IN std_logic_vector(3 DOWNTO 0);
	reg2 : IN std_logic_vector(7 DOWNTO 0);
	reg3 : OUT std_logic_vector(11 DOWNTO 0)
	);
END reg_combin;

-- Design Ports Information
-- reg3[0]	=>  Location: PIN_F13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reg3[1]	=>  Location: PIN_J13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reg3[2]	=>  Location: PIN_R5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reg3[3]	=>  Location: PIN_A6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reg3[4]	=>  Location: PIN_F7,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reg3[5]	=>  Location: PIN_G15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reg3[6]	=>  Location: PIN_D8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reg3[7]	=>  Location: PIN_L7,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reg3[8]	=>  Location: PIN_P1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reg3[9]	=>  Location: PIN_T9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reg3[10]	=>  Location: PIN_C2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reg3[11]	=>  Location: PIN_F2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reg2[0]	=>  Location: PIN_E16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reg2[1]	=>  Location: PIN_E15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reg2[2]	=>  Location: PIN_T5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reg2[3]	=>  Location: PIN_B6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reg2[4]	=>  Location: PIN_C8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reg2[5]	=>  Location: PIN_G16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reg2[6]	=>  Location: PIN_E8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reg2[7]	=>  Location: PIN_L8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reg1[0]	=>  Location: PIN_P2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reg1[1]	=>  Location: PIN_L9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reg1[2]	=>  Location: PIN_F3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reg1[3]	=>  Location: PIN_G5,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF reg_combin IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_reg1 : std_logic_vector(3 DOWNTO 0);
SIGNAL ww_reg2 : std_logic_vector(7 DOWNTO 0);
SIGNAL ww_reg3 : std_logic_vector(11 DOWNTO 0);
SIGNAL \reg3[0]~output_o\ : std_logic;
SIGNAL \reg3[1]~output_o\ : std_logic;
SIGNAL \reg3[2]~output_o\ : std_logic;
SIGNAL \reg3[3]~output_o\ : std_logic;
SIGNAL \reg3[4]~output_o\ : std_logic;
SIGNAL \reg3[5]~output_o\ : std_logic;
SIGNAL \reg3[6]~output_o\ : std_logic;
SIGNAL \reg3[7]~output_o\ : std_logic;
SIGNAL \reg3[8]~output_o\ : std_logic;
SIGNAL \reg3[9]~output_o\ : std_logic;
SIGNAL \reg3[10]~output_o\ : std_logic;
SIGNAL \reg3[11]~output_o\ : std_logic;
SIGNAL \reg2[0]~input_o\ : std_logic;
SIGNAL \reg2[1]~input_o\ : std_logic;
SIGNAL \reg2[2]~input_o\ : std_logic;
SIGNAL \reg2[3]~input_o\ : std_logic;
SIGNAL \reg2[4]~input_o\ : std_logic;
SIGNAL \reg2[5]~input_o\ : std_logic;
SIGNAL \reg2[6]~input_o\ : std_logic;
SIGNAL \reg2[7]~input_o\ : std_logic;
SIGNAL \reg1[0]~input_o\ : std_logic;
SIGNAL \reg1[1]~input_o\ : std_logic;
SIGNAL \reg1[2]~input_o\ : std_logic;
SIGNAL \reg1[3]~input_o\ : std_logic;

BEGIN

ww_reg1 <= reg1;
ww_reg2 <= reg2;
reg3 <= ww_reg3;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOOBUF_X34_Y17_N2
\reg3[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \reg2[0]~input_o\,
	devoe => ww_devoe,
	o => \reg3[0]~output_o\);

-- Location: IOOBUF_X34_Y11_N2
\reg3[1]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \reg2[1]~input_o\,
	devoe => ww_devoe,
	o => \reg3[1]~output_o\);

-- Location: IOOBUF_X9_Y0_N9
\reg3[2]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \reg2[2]~input_o\,
	devoe => ww_devoe,
	o => \reg3[2]~output_o\);

-- Location: IOOBUF_X9_Y24_N16
\reg3[3]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \reg2[3]~input_o\,
	devoe => ww_devoe,
	o => \reg3[3]~output_o\);

-- Location: IOOBUF_X11_Y24_N23
\reg3[4]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \reg2[4]~input_o\,
	devoe => ww_devoe,
	o => \reg3[4]~output_o\);

-- Location: IOOBUF_X34_Y17_N16
\reg3[5]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \reg2[5]~input_o\,
	devoe => ww_devoe,
	o => \reg3[5]~output_o\);

-- Location: IOOBUF_X13_Y24_N9
\reg3[6]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \reg2[6]~input_o\,
	devoe => ww_devoe,
	o => \reg3[6]~output_o\);

-- Location: IOOBUF_X11_Y0_N9
\reg3[7]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \reg2[7]~input_o\,
	devoe => ww_devoe,
	o => \reg3[7]~output_o\);

-- Location: IOOBUF_X0_Y4_N23
\reg3[8]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \reg1[0]~input_o\,
	devoe => ww_devoe,
	o => \reg3[8]~output_o\);

-- Location: IOOBUF_X18_Y0_N16
\reg3[9]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \reg1[1]~input_o\,
	devoe => ww_devoe,
	o => \reg3[9]~output_o\);

-- Location: IOOBUF_X0_Y22_N16
\reg3[10]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \reg1[2]~input_o\,
	devoe => ww_devoe,
	o => \reg3[10]~output_o\);

-- Location: IOOBUF_X0_Y19_N16
\reg3[11]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \reg1[3]~input_o\,
	devoe => ww_devoe,
	o => \reg3[11]~output_o\);

-- Location: IOIBUF_X34_Y12_N8
\reg2[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_reg2(0),
	o => \reg2[0]~input_o\);

-- Location: IOIBUF_X34_Y12_N1
\reg2[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_reg2(1),
	o => \reg2[1]~input_o\);

-- Location: IOIBUF_X9_Y0_N1
\reg2[2]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_reg2(2),
	o => \reg2[2]~input_o\);

-- Location: IOIBUF_X9_Y24_N22
\reg2[3]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_reg2(3),
	o => \reg2[3]~input_o\);

-- Location: IOIBUF_X13_Y24_N1
\reg2[4]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_reg2(4),
	o => \reg2[4]~input_o\);

-- Location: IOIBUF_X34_Y17_N22
\reg2[5]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_reg2(5),
	o => \reg2[5]~input_o\);

-- Location: IOIBUF_X13_Y24_N15
\reg2[6]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_reg2(6),
	o => \reg2[6]~input_o\);

-- Location: IOIBUF_X13_Y0_N15
\reg2[7]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_reg2(7),
	o => \reg2[7]~input_o\);

-- Location: IOIBUF_X0_Y4_N15
\reg1[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_reg1(0),
	o => \reg1[0]~input_o\);

-- Location: IOIBUF_X18_Y0_N1
\reg1[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_reg1(1),
	o => \reg1[1]~input_o\);

-- Location: IOIBUF_X0_Y21_N8
\reg1[2]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_reg1(2),
	o => \reg1[2]~input_o\);

-- Location: IOIBUF_X0_Y19_N1
\reg1[3]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_reg1(3),
	o => \reg1[3]~input_o\);

ww_reg3(0) <= \reg3[0]~output_o\;

ww_reg3(1) <= \reg3[1]~output_o\;

ww_reg3(2) <= \reg3[2]~output_o\;

ww_reg3(3) <= \reg3[3]~output_o\;

ww_reg3(4) <= \reg3[4]~output_o\;

ww_reg3(5) <= \reg3[5]~output_o\;

ww_reg3(6) <= \reg3[6]~output_o\;

ww_reg3(7) <= \reg3[7]~output_o\;

ww_reg3(8) <= \reg3[8]~output_o\;

ww_reg3(9) <= \reg3[9]~output_o\;

ww_reg3(10) <= \reg3[10]~output_o\;

ww_reg3(11) <= \reg3[11]~output_o\;
END structure;


