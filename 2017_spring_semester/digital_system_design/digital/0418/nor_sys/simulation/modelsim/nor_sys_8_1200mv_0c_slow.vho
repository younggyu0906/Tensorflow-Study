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

-- DATE "04/18/2017 17:04:03"

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

ENTITY 	nor_sys IS
    PORT (
	a : IN std_logic_vector(7 DOWNTO 0);
	c : OUT std_logic
	);
END nor_sys;

-- Design Ports Information
-- c	=>  Location: PIN_K6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[0]	=>  Location: PIN_F2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[1]	=>  Location: PIN_G2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[2]	=>  Location: PIN_C3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[3]	=>  Location: PIN_J13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[4]	=>  Location: PIN_J1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[5]	=>  Location: PIN_F3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[6]	=>  Location: PIN_G1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[7]	=>  Location: PIN_G5,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF nor_sys IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_a : std_logic_vector(7 DOWNTO 0);
SIGNAL ww_c : std_logic;
SIGNAL \a[2]~input_o\ : std_logic;
SIGNAL \a[6]~input_o\ : std_logic;
SIGNAL \c~output_o\ : std_logic;
SIGNAL \a[4]~input_o\ : std_logic;
SIGNAL \a[7]~input_o\ : std_logic;
SIGNAL \a[5]~input_o\ : std_logic;
SIGNAL \ux|temp~1_combout\ : std_logic;
SIGNAL \a[1]~input_o\ : std_logic;
SIGNAL \a[3]~input_o\ : std_logic;
SIGNAL \a[0]~input_o\ : std_logic;
SIGNAL \ux|temp~0_combout\ : std_logic;
SIGNAL \ux|temp~combout\ : std_logic;
SIGNAL \ux|ALT_INV_temp~combout\ : std_logic;

BEGIN

ww_a <= a;
c <= ww_c;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
\ux|ALT_INV_temp~combout\ <= NOT \ux|temp~combout\;

-- Location: IOIBUF_X1_Y24_N1
\a[2]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(2),
	o => \a[2]~input_o\);

-- Location: IOIBUF_X0_Y18_N22
\a[6]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(6),
	o => \a[6]~input_o\);

-- Location: IOOBUF_X0_Y9_N2
\c~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \ux|ALT_INV_temp~combout\,
	devoe => ww_devoe,
	o => \c~output_o\);

-- Location: IOIBUF_X0_Y10_N15
\a[4]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(4),
	o => \a[4]~input_o\);

-- Location: IOIBUF_X0_Y19_N1
\a[7]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(7),
	o => \a[7]~input_o\);

-- Location: IOIBUF_X0_Y21_N8
\a[5]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(5),
	o => \a[5]~input_o\);

-- Location: LCCOMB_X1_Y18_N2
\ux|temp~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \ux|temp~1_combout\ = (\a[6]~input_o\ & (\a[4]~input_o\ & (\a[7]~input_o\ & \a[5]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \a[6]~input_o\,
	datab => \a[4]~input_o\,
	datac => \a[7]~input_o\,
	datad => \a[5]~input_o\,
	combout => \ux|temp~1_combout\);

-- Location: IOIBUF_X0_Y18_N15
\a[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(1),
	o => \a[1]~input_o\);

-- Location: IOIBUF_X34_Y11_N1
\a[3]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(3),
	o => \a[3]~input_o\);

-- Location: IOIBUF_X0_Y19_N15
\a[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(0),
	o => \a[0]~input_o\);

-- Location: LCCOMB_X1_Y18_N0
\ux|temp~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \ux|temp~0_combout\ = (\a[2]~input_o\ & (\a[1]~input_o\ & (\a[3]~input_o\ & \a[0]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \a[2]~input_o\,
	datab => \a[1]~input_o\,
	datac => \a[3]~input_o\,
	datad => \a[0]~input_o\,
	combout => \ux|temp~0_combout\);

-- Location: LCCOMB_X1_Y18_N20
\ux|temp\ : cycloneive_lcell_comb
-- Equation(s):
-- \ux|temp~combout\ = (\ux|temp~1_combout\ & \ux|temp~0_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \ux|temp~1_combout\,
	datad => \ux|temp~0_combout\,
	combout => \ux|temp~combout\);

ww_c <= \c~output_o\;
END structure;


