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

-- DATE "05/08/2017 16:15:39"

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

ENTITY 	parity IS
    PORT (
	a : IN std_logic_vector(4 DOWNTO 0);
	parity_check : OUT std_logic
	);
END parity;

-- Design Ports Information
-- parity_check	=>  Location: PIN_C2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[4]	=>  Location: PIN_B9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[0]	=>  Location: PIN_F1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[1]	=>  Location: PIN_F3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[2]	=>  Location: PIN_D1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[3]	=>  Location: PIN_G1,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF parity IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_a : std_logic_vector(4 DOWNTO 0);
SIGNAL ww_parity_check : std_logic;
SIGNAL \a[3]~input_o\ : std_logic;
SIGNAL \parity_check~output_o\ : std_logic;
SIGNAL \a[4]~input_o\ : std_logic;
SIGNAL \a[1]~input_o\ : std_logic;
SIGNAL \a[0]~input_o\ : std_logic;
SIGNAL \a[2]~input_o\ : std_logic;
SIGNAL \g1:0:g2:ux|c~0_combout\ : std_logic;
SIGNAL \g1:0:g2:ux|c~combout\ : std_logic;

BEGIN

ww_a <= a;
parity_check <= ww_parity_check;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOIBUF_X0_Y18_N22
\a[3]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(3),
	o => \a[3]~input_o\);

-- Location: IOOBUF_X0_Y22_N16
\parity_check~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \g1:0:g2:ux|c~combout\,
	devoe => ww_devoe,
	o => \parity_check~output_o\);

-- Location: IOIBUF_X16_Y24_N8
\a[4]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(4),
	o => \a[4]~input_o\);

-- Location: IOIBUF_X0_Y21_N8
\a[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(1),
	o => \a[1]~input_o\);

-- Location: IOIBUF_X0_Y19_N22
\a[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(0),
	o => \a[0]~input_o\);

-- Location: IOIBUF_X0_Y21_N22
\a[2]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(2),
	o => \a[2]~input_o\);

-- Location: LCCOMB_X1_Y21_N0
\g1:0:g2:ux|c~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \g1:0:g2:ux|c~0_combout\ = \a[3]~input_o\ $ (\a[1]~input_o\ $ (\a[0]~input_o\ $ (\a[2]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0110100110010110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \a[3]~input_o\,
	datab => \a[1]~input_o\,
	datac => \a[0]~input_o\,
	datad => \a[2]~input_o\,
	combout => \g1:0:g2:ux|c~0_combout\);

-- Location: LCCOMB_X1_Y21_N2
\g1:0:g2:ux|c\ : cycloneive_lcell_comb
-- Equation(s):
-- \g1:0:g2:ux|c~combout\ = \a[4]~input_o\ $ (\g1:0:g2:ux|c~0_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111111110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \a[4]~input_o\,
	datad => \g1:0:g2:ux|c~0_combout\,
	combout => \g1:0:g2:ux|c~combout\);

ww_parity_check <= \parity_check~output_o\;
END structure;


