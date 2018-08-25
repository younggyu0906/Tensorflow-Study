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

-- DATE "04/04/2017 16:44:41"

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

ENTITY 	ex02 IS
    PORT (
	d : IN std_logic;
	en : IN std_logic;
	q : OUT std_logic
	);
END ex02;

-- Design Ports Information
-- q	=>  Location: PIN_K1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- d	=>  Location: PIN_L3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- en	=>  Location: PIN_N1,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF ex02 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_d : std_logic;
SIGNAL ww_en : std_logic;
SIGNAL ww_q : std_logic;
SIGNAL \q~output_o\ : std_logic;
SIGNAL \d~input_o\ : std_logic;
SIGNAL \en~input_o\ : std_logic;
SIGNAL \q$latch~combout\ : std_logic;

BEGIN

ww_d <= d;
ww_en <= en;
q <= ww_q;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOOBUF_X0_Y8_N9
\q~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \q$latch~combout\,
	devoe => ww_devoe,
	o => \q~output_o\);

-- Location: IOIBUF_X0_Y7_N1
\d~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_d,
	o => \d~input_o\);

-- Location: IOIBUF_X0_Y7_N22
\en~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_en,
	o => \en~input_o\);

-- Location: LCCOMB_X1_Y7_N8
\q$latch\ : cycloneive_lcell_comb
-- Equation(s):
-- \q$latch~combout\ = (\en~input_o\ & (\d~input_o\)) # (!\en~input_o\ & ((\q$latch~combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110011110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \d~input_o\,
	datac => \q$latch~combout\,
	datad => \en~input_o\,
	combout => \q$latch~combout\);

ww_q <= \q~output_o\;
END structure;


