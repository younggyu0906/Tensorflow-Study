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

-- DATE "04/11/2017 16:13:03"

-- 
-- Device: Altera EP4CE6F17C8 Package FBGA256
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY CYCLONEIVE;
LIBRARY IEEE;
LIBRARY STD;
USE CYCLONEIVE.CYCLONEIVE_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;
USE STD.STANDARD.ALL;

ENTITY 	logic IS
    PORT (
	a : IN std_logic;
	b : IN std_logic;
	c : IN std_logic;
	d : IN std_logic;
	y_out : OUT STD.STANDARD.bit
	);
END logic;

-- Design Ports Information
-- y_out	=>  Location: PIN_D3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d	=>  Location: PIN_R1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a	=>  Location: PIN_K5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- b	=>  Location: PIN_P1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- c	=>  Location: PIN_P2,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF logic IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_a : std_logic;
SIGNAL ww_b : std_logic;
SIGNAL ww_c : std_logic;
SIGNAL ww_d : std_logic;
SIGNAL ww_y_out : std_logic;
SIGNAL \y_out~output_o\ : std_logic;
SIGNAL \b~input_o\ : std_logic;
SIGNAL \d~input_o\ : std_logic;
SIGNAL \c~input_o\ : std_logic;
SIGNAL \a~input_o\ : std_logic;
SIGNAL \y_out~0_combout\ : std_logic;

BEGIN

ww_a <= a;
ww_b <= b;
ww_c <= c;
ww_d <= d;
y_out <= IEEE.STD_LOGIC_1164.TO_BIT(ww_y_out);
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOOBUF_X1_Y24_N9
\y_out~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \y_out~0_combout\,
	devoe => ww_devoe,
	o => \y_out~output_o\);

-- Location: IOIBUF_X0_Y4_N22
\b~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_b,
	o => \b~input_o\);

-- Location: IOIBUF_X0_Y5_N22
\d~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d,
	o => \d~input_o\);

-- Location: IOIBUF_X0_Y4_N15
\c~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_c,
	o => \c~input_o\);

-- Location: IOIBUF_X0_Y6_N15
\a~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a,
	o => \a~input_o\);

-- Location: LCCOMB_X1_Y5_N8
\y_out~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \y_out~0_combout\ = (\d~input_o\ & (!\c~input_o\ & ((!\a~input_o\) # (!\b~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000010000001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \b~input_o\,
	datab => \d~input_o\,
	datac => \c~input_o\,
	datad => \a~input_o\,
	combout => \y_out~0_combout\);

ww_y_out <= \y_out~output_o\;
END structure;


