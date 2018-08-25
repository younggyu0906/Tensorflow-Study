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

-- DATE "04/15/2017 11:54:42"

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

ENTITY 	full_adder IS
    PORT (
	w : IN std_logic;
	x : IN std_logic;
	y : IN std_logic;
	carry : OUT std_logic;
	sum : OUT std_logic
	);
END full_adder;

-- Design Ports Information
-- carry	=>  Location: PIN_A6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- sum	=>  Location: PIN_C2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x	=>  Location: PIN_B1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y	=>  Location: PIN_F5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- w	=>  Location: PIN_D1,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF full_adder IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_w : std_logic;
SIGNAL ww_x : std_logic;
SIGNAL ww_y : std_logic;
SIGNAL ww_carry : std_logic;
SIGNAL ww_sum : std_logic;
SIGNAL \carry~output_o\ : std_logic;
SIGNAL \sum~output_o\ : std_logic;
SIGNAL \w~input_o\ : std_logic;
SIGNAL \y~input_o\ : std_logic;
SIGNAL \x~input_o\ : std_logic;
SIGNAL \u3|c~0_combout\ : std_logic;
SIGNAL \u2|s~0_combout\ : std_logic;

BEGIN

ww_w <= w;
ww_x <= x;
ww_y <= y;
carry <= ww_carry;
sum <= ww_sum;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOOBUF_X9_Y24_N16
\carry~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u3|c~0_combout\,
	devoe => ww_devoe,
	o => \carry~output_o\);

-- Location: IOOBUF_X0_Y22_N16
\sum~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u2|s~0_combout\,
	devoe => ww_devoe,
	o => \sum~output_o\);

-- Location: IOIBUF_X0_Y21_N22
\w~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_w,
	o => \w~input_o\);

-- Location: IOIBUF_X0_Y23_N15
\y~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_y,
	o => \y~input_o\);

-- Location: IOIBUF_X0_Y22_N1
\x~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x,
	o => \x~input_o\);

-- Location: LCCOMB_X1_Y22_N0
\u3|c~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|c~0_combout\ = (\w~input_o\ & ((\y~input_o\) # (\x~input_o\))) # (!\w~input_o\ & (\y~input_o\ & \x~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110011000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \w~input_o\,
	datac => \y~input_o\,
	datad => \x~input_o\,
	combout => \u3|c~0_combout\);

-- Location: LCCOMB_X1_Y22_N2
\u2|s~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|s~0_combout\ = \w~input_o\ $ (\y~input_o\ $ (\x~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100111100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \w~input_o\,
	datac => \y~input_o\,
	datad => \x~input_o\,
	combout => \u2|s~0_combout\);

ww_carry <= \carry~output_o\;

ww_sum <= \sum~output_o\;
END structure;


