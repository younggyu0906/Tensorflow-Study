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

-- DATE "05/18/2017 14:11:15"

-- 
-- Device: Altera EP4CE6E22C8 Package TQFP144
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY CYCLONEIVE;
LIBRARY IEEE;
USE CYCLONEIVE.CYCLONEIVE_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	jk_flipflop IS
    PORT (
	clk : IN std_logic;
	j : IN std_logic;
	k : IN std_logic;
	pr : IN std_logic;
	clr : IN std_logic;
	y_out : BUFFER std_logic
	);
END jk_flipflop;

-- Design Ports Information
-- clk	=>  Location: PIN_10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- j	=>  Location: PIN_124,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- k	=>  Location: PIN_1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y_out	=>  Location: PIN_11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- pr	=>  Location: PIN_3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- clr	=>  Location: PIN_7,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF jk_flipflop IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_clk : std_logic;
SIGNAL ww_j : std_logic;
SIGNAL ww_k : std_logic;
SIGNAL ww_pr : std_logic;
SIGNAL ww_clr : std_logic;
SIGNAL ww_y_out : std_logic;
SIGNAL \clk~input_o\ : std_logic;
SIGNAL \j~input_o\ : std_logic;
SIGNAL \k~input_o\ : std_logic;
SIGNAL \y_out~output_o\ : std_logic;
SIGNAL \pr~input_o\ : std_logic;
SIGNAL \clr~input_o\ : std_logic;
SIGNAL \comb~0_combout\ : std_logic;
SIGNAL \y_out$latch~combout\ : std_logic;

BEGIN

ww_clk <= clk;
ww_j <= j;
ww_k <= k;
ww_pr <= pr;
ww_clr <= clr;
y_out <= ww_y_out;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOOBUF_X0_Y18_N23
\y_out~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \y_out$latch~combout\,
	devoe => ww_devoe,
	o => \y_out~output_o\);

-- Location: IOIBUF_X0_Y23_N15
\pr~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_pr,
	o => \pr~input_o\);

-- Location: IOIBUF_X0_Y21_N8
\clr~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_clr,
	o => \clr~input_o\);

-- Location: LCCOMB_X1_Y22_N0
\comb~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \comb~0_combout\ = (\pr~input_o\ & !\clr~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \pr~input_o\,
	datad => \clr~input_o\,
	combout => \comb~0_combout\);

-- Location: LCCOMB_X1_Y22_N2
\y_out$latch\ : cycloneive_lcell_comb
-- Equation(s):
-- \y_out$latch~combout\ = (!\comb~0_combout\ & ((\y_out$latch~combout\) # (!\pr~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001100000011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \comb~0_combout\,
	datac => \pr~input_o\,
	datad => \y_out$latch~combout\,
	combout => \y_out$latch~combout\);

-- Location: IOIBUF_X0_Y18_N15
\clk~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_clk,
	o => \clk~input_o\);

-- Location: IOIBUF_X18_Y24_N15
\j~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_j,
	o => \j~input_o\);

-- Location: IOIBUF_X0_Y23_N1
\k~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_k,
	o => \k~input_o\);

ww_y_out <= \y_out~output_o\;
END structure;


