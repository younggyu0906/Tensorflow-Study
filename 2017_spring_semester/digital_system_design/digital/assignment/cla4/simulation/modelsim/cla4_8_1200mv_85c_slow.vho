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

-- DATE "05/08/2017 15:41:03"

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

ENTITY 	cla4 IS
    PORT (
	a : IN std_logic_vector(3 DOWNTO 0);
	b : IN std_logic_vector(3 DOWNTO 0);
	carryIn : IN std_logic;
	carry : OUT std_logic;
	sum : OUT std_logic_vector(3 DOWNTO 0)
	);
END cla4;

-- Design Ports Information
-- carry	=>  Location: PIN_M10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- sum[0]	=>  Location: PIN_B16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- sum[1]	=>  Location: PIN_R7,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- sum[2]	=>  Location: PIN_A11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- sum[3]	=>  Location: PIN_B11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[0]	=>  Location: PIN_A14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- b[0]	=>  Location: PIN_P15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- carryIn	=>  Location: PIN_J12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- b[1]	=>  Location: PIN_E9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[1]	=>  Location: PIN_C15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[2]	=>  Location: PIN_E11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- b[2]	=>  Location: PIN_D15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- b[3]	=>  Location: PIN_A12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[3]	=>  Location: PIN_C11,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF cla4 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_a : std_logic_vector(3 DOWNTO 0);
SIGNAL ww_b : std_logic_vector(3 DOWNTO 0);
SIGNAL ww_carryIn : std_logic;
SIGNAL ww_carry : std_logic;
SIGNAL ww_sum : std_logic_vector(3 DOWNTO 0);
SIGNAL \carry~output_o\ : std_logic;
SIGNAL \sum[0]~output_o\ : std_logic;
SIGNAL \sum[1]~output_o\ : std_logic;
SIGNAL \sum[2]~output_o\ : std_logic;
SIGNAL \sum[3]~output_o\ : std_logic;
SIGNAL \b[0]~input_o\ : std_logic;
SIGNAL \a[0]~input_o\ : std_logic;
SIGNAL \carryIn~input_o\ : std_logic;
SIGNAL \u13|u2|s~0_combout\ : std_logic;
SIGNAL \u12|o~1_combout\ : std_logic;
SIGNAL \b[1]~input_o\ : std_logic;
SIGNAL \a[1]~input_o\ : std_logic;
SIGNAL \u12|o~0_combout\ : std_logic;
SIGNAL \u14|u2|s~combout\ : std_logic;
SIGNAL \b[2]~input_o\ : std_logic;
SIGNAL \u11|o~0_combout\ : std_logic;
SIGNAL \a[2]~input_o\ : std_logic;
SIGNAL \u15|u2|s~0_combout\ : std_logic;
SIGNAL \b[3]~input_o\ : std_logic;
SIGNAL \a[3]~input_o\ : std_logic;
SIGNAL \u16|u2|s~0_combout\ : std_logic;
SIGNAL \u16|u2|s~combout\ : std_logic;

BEGIN

ww_a <= a;
ww_b <= b;
ww_carryIn <= carryIn;
carry <= ww_carry;
sum <= ww_sum;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOOBUF_X28_Y0_N2
\carry~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => GND,
	devoe => ww_devoe,
	o => \carry~output_o\);

-- Location: IOOBUF_X34_Y18_N2
\sum[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u13|u2|s~0_combout\,
	devoe => ww_devoe,
	o => \sum[0]~output_o\);

-- Location: IOOBUF_X11_Y0_N2
\sum[1]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u14|u2|s~combout\,
	devoe => ww_devoe,
	o => \sum[1]~output_o\);

-- Location: IOOBUF_X25_Y24_N16
\sum[2]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u15|u2|s~0_combout\,
	devoe => ww_devoe,
	o => \sum[2]~output_o\);

-- Location: IOOBUF_X25_Y24_N23
\sum[3]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u16|u2|s~combout\,
	devoe => ww_devoe,
	o => \sum[3]~output_o\);

-- Location: IOIBUF_X34_Y4_N15
\b[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_b(0),
	o => \b[0]~input_o\);

-- Location: IOIBUF_X28_Y24_N1
\a[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(0),
	o => \a[0]~input_o\);

-- Location: IOIBUF_X34_Y11_N8
\carryIn~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_carryIn,
	o => \carryIn~input_o\);

-- Location: LCCOMB_X28_Y22_N24
\u13|u2|s~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u13|u2|s~0_combout\ = \b[0]~input_o\ $ (\a[0]~input_o\ $ (\carryIn~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100111100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \b[0]~input_o\,
	datac => \a[0]~input_o\,
	datad => \carryIn~input_o\,
	combout => \u13|u2|s~0_combout\);

-- Location: LCCOMB_X28_Y22_N12
\u12|o~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u12|o~1_combout\ = (\carryIn~input_o\ & ((\b[0]~input_o\) # (\a[0]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \b[0]~input_o\,
	datac => \a[0]~input_o\,
	datad => \carryIn~input_o\,
	combout => \u12|o~1_combout\);

-- Location: IOIBUF_X18_Y24_N22
\b[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_b(1),
	o => \b[1]~input_o\);

-- Location: IOIBUF_X34_Y20_N1
\a[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(1),
	o => \a[1]~input_o\);

-- Location: LCCOMB_X28_Y22_N10
\u12|o~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u12|o~0_combout\ = (\b[0]~input_o\ & \a[0]~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100000011000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \b[0]~input_o\,
	datac => \a[0]~input_o\,
	combout => \u12|o~0_combout\);

-- Location: LCCOMB_X28_Y22_N22
\u14|u2|s\ : cycloneive_lcell_comb
-- Equation(s):
-- \u14|u2|s~combout\ = \b[1]~input_o\ $ (\a[1]~input_o\ $ (((\u12|o~1_combout\) # (\u12|o~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001110010110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u12|o~1_combout\,
	datab => \b[1]~input_o\,
	datac => \a[1]~input_o\,
	datad => \u12|o~0_combout\,
	combout => \u14|u2|s~combout\);

-- Location: IOIBUF_X34_Y19_N1
\b[2]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_b(2),
	o => \b[2]~input_o\);

-- Location: LCCOMB_X28_Y22_N0
\u11|o~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u11|o~0_combout\ = (\b[1]~input_o\ & ((\u12|o~1_combout\) # ((\a[1]~input_o\) # (\u12|o~0_combout\)))) # (!\b[1]~input_o\ & (\a[1]~input_o\ & ((\u12|o~1_combout\) # (\u12|o~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110011101000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u12|o~1_combout\,
	datab => \b[1]~input_o\,
	datac => \a[1]~input_o\,
	datad => \u12|o~0_combout\,
	combout => \u11|o~0_combout\);

-- Location: IOIBUF_X28_Y24_N15
\a[2]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(2),
	o => \a[2]~input_o\);

-- Location: LCCOMB_X28_Y22_N2
\u15|u2|s~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u15|u2|s~0_combout\ = \b[2]~input_o\ $ (\u11|o~0_combout\ $ (\a[2]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1001011010010110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \b[2]~input_o\,
	datab => \u11|o~0_combout\,
	datac => \a[2]~input_o\,
	combout => \u15|u2|s~0_combout\);

-- Location: IOIBUF_X25_Y24_N1
\b[3]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_b(3),
	o => \b[3]~input_o\);

-- Location: IOIBUF_X23_Y24_N1
\a[3]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(3),
	o => \a[3]~input_o\);

-- Location: LCCOMB_X28_Y22_N28
\u16|u2|s~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u16|u2|s~0_combout\ = \a[3]~input_o\ $ (((\b[2]~input_o\ & ((\u11|o~0_combout\) # (\a[2]~input_o\))) # (!\b[2]~input_o\ & (\u11|o~0_combout\ & \a[2]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0001011111101000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \b[2]~input_o\,
	datab => \u11|o~0_combout\,
	datac => \a[2]~input_o\,
	datad => \a[3]~input_o\,
	combout => \u16|u2|s~0_combout\);

-- Location: LCCOMB_X28_Y22_N6
\u16|u2|s\ : cycloneive_lcell_comb
-- Equation(s):
-- \u16|u2|s~combout\ = \b[3]~input_o\ $ (\u16|u2|s~0_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001111001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \b[3]~input_o\,
	datad => \u16|u2|s~0_combout\,
	combout => \u16|u2|s~combout\);

ww_carry <= \carry~output_o\;

ww_sum(0) <= \sum[0]~output_o\;

ww_sum(1) <= \sum[1]~output_o\;

ww_sum(2) <= \sum[2]~output_o\;

ww_sum(3) <= \sum[3]~output_o\;
END structure;


