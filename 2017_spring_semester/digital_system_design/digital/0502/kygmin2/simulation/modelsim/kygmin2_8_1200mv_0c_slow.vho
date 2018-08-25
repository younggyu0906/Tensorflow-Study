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

-- DATE "05/02/2017 17:29:51"

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

ENTITY 	kygmin2 IS
    PORT (
	a : IN std_logic_vector(7 DOWNTO 0);
	b : IN std_logic_vector(7 DOWNTO 0);
	y_out : OUT std_logic_vector(7 DOWNTO 0)
	);
END kygmin2;

-- Design Ports Information
-- y_out[0]	=>  Location: PIN_G2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y_out[1]	=>  Location: PIN_R1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y_out[2]	=>  Location: PIN_K6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y_out[3]	=>  Location: PIN_D3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y_out[4]	=>  Location: PIN_B1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y_out[5]	=>  Location: PIN_C3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y_out[6]	=>  Location: PIN_F2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y_out[7]	=>  Location: PIN_F5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[0]	=>  Location: PIN_M2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- b[0]	=>  Location: PIN_M1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[7]	=>  Location: PIN_G1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- b[7]	=>  Location: PIN_E5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[6]	=>  Location: PIN_L2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- b[6]	=>  Location: PIN_B3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[5]	=>  Location: PIN_P1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- b[5]	=>  Location: PIN_F3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[4]	=>  Location: PIN_D1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- b[4]	=>  Location: PIN_J6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[3]	=>  Location: PIN_G5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- b[3]	=>  Location: PIN_J2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[2]	=>  Location: PIN_P6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- b[2]	=>  Location: PIN_F1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[1]	=>  Location: PIN_A6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- b[1]	=>  Location: PIN_D4,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF kygmin2 IS
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
SIGNAL ww_b : std_logic_vector(7 DOWNTO 0);
SIGNAL ww_y_out : std_logic_vector(7 DOWNTO 0);
SIGNAL \y_out[0]~output_o\ : std_logic;
SIGNAL \y_out[1]~output_o\ : std_logic;
SIGNAL \y_out[2]~output_o\ : std_logic;
SIGNAL \y_out[3]~output_o\ : std_logic;
SIGNAL \y_out[4]~output_o\ : std_logic;
SIGNAL \y_out[5]~output_o\ : std_logic;
SIGNAL \y_out[6]~output_o\ : std_logic;
SIGNAL \y_out[7]~output_o\ : std_logic;
SIGNAL \b[0]~input_o\ : std_logic;
SIGNAL \a[0]~input_o\ : std_logic;
SIGNAL \a[7]~input_o\ : std_logic;
SIGNAL \b[7]~input_o\ : std_logic;
SIGNAL \b[6]~input_o\ : std_logic;
SIGNAL \a[5]~input_o\ : std_logic;
SIGNAL \a[4]~input_o\ : std_logic;
SIGNAL \a[3]~input_o\ : std_logic;
SIGNAL \a[2]~input_o\ : std_logic;
SIGNAL \a[1]~input_o\ : std_logic;
SIGNAL \LessThan0~1_cout\ : std_logic;
SIGNAL \LessThan0~3_cout\ : std_logic;
SIGNAL \LessThan0~5_cout\ : std_logic;
SIGNAL \LessThan0~7_cout\ : std_logic;
SIGNAL \LessThan0~9_cout\ : std_logic;
SIGNAL \LessThan0~11_cout\ : std_logic;
SIGNAL \LessThan0~13_cout\ : std_logic;
SIGNAL \LessThan0~14_combout\ : std_logic;
SIGNAL \temp~0_combout\ : std_logic;
SIGNAL \b[1]~input_o\ : std_logic;
SIGNAL \temp~1_combout\ : std_logic;
SIGNAL \b[2]~input_o\ : std_logic;
SIGNAL \temp~2_combout\ : std_logic;
SIGNAL \b[3]~input_o\ : std_logic;
SIGNAL \temp~3_combout\ : std_logic;
SIGNAL \b[4]~input_o\ : std_logic;
SIGNAL \temp~4_combout\ : std_logic;
SIGNAL \b[5]~input_o\ : std_logic;
SIGNAL \temp~5_combout\ : std_logic;
SIGNAL \a[6]~input_o\ : std_logic;
SIGNAL \temp~6_combout\ : std_logic;
SIGNAL \temp~7_combout\ : std_logic;

BEGIN

ww_a <= a;
ww_b <= b;
y_out <= ww_y_out;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOOBUF_X0_Y18_N16
\y_out[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \temp~0_combout\,
	devoe => ww_devoe,
	o => \y_out[0]~output_o\);

-- Location: IOOBUF_X0_Y5_N23
\y_out[1]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \temp~1_combout\,
	devoe => ww_devoe,
	o => \y_out[1]~output_o\);

-- Location: IOOBUF_X0_Y9_N2
\y_out[2]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \temp~2_combout\,
	devoe => ww_devoe,
	o => \y_out[2]~output_o\);

-- Location: IOOBUF_X1_Y24_N9
\y_out[3]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \temp~3_combout\,
	devoe => ww_devoe,
	o => \y_out[3]~output_o\);

-- Location: IOOBUF_X0_Y22_N2
\y_out[4]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \temp~4_combout\,
	devoe => ww_devoe,
	o => \y_out[4]~output_o\);

-- Location: IOOBUF_X1_Y24_N2
\y_out[5]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \temp~5_combout\,
	devoe => ww_devoe,
	o => \y_out[5]~output_o\);

-- Location: IOOBUF_X0_Y19_N16
\y_out[6]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \temp~6_combout\,
	devoe => ww_devoe,
	o => \y_out[6]~output_o\);

-- Location: IOOBUF_X0_Y23_N16
\y_out[7]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \temp~7_combout\,
	devoe => ww_devoe,
	o => \y_out[7]~output_o\);

-- Location: IOIBUF_X0_Y11_N22
\b[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_b(0),
	o => \b[0]~input_o\);

-- Location: IOIBUF_X0_Y11_N15
\a[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(0),
	o => \a[0]~input_o\);

-- Location: IOIBUF_X0_Y18_N22
\a[7]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(7),
	o => \a[7]~input_o\);

-- Location: IOIBUF_X0_Y23_N8
\b[7]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_b(7),
	o => \b[7]~input_o\);

-- Location: IOIBUF_X3_Y24_N22
\b[6]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_b(6),
	o => \b[6]~input_o\);

-- Location: IOIBUF_X0_Y4_N22
\a[5]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(5),
	o => \a[5]~input_o\);

-- Location: IOIBUF_X0_Y21_N22
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
\a[3]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(3),
	o => \a[3]~input_o\);

-- Location: IOIBUF_X7_Y0_N1
\a[2]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(2),
	o => \a[2]~input_o\);

-- Location: IOIBUF_X9_Y24_N15
\a[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(1),
	o => \a[1]~input_o\);

-- Location: LCCOMB_X1_Y11_N4
\LessThan0~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \LessThan0~1_cout\ = CARRY((!\a[0]~input_o\ & \b[0]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000001000100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \a[0]~input_o\,
	datab => \b[0]~input_o\,
	datad => VCC,
	cout => \LessThan0~1_cout\);

-- Location: LCCOMB_X1_Y11_N6
\LessThan0~3\ : cycloneive_lcell_comb
-- Equation(s):
-- \LessThan0~3_cout\ = CARRY((\b[1]~input_o\ & (\a[1]~input_o\ & !\LessThan0~1_cout\)) # (!\b[1]~input_o\ & ((\a[1]~input_o\) # (!\LessThan0~1_cout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000001001101",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \b[1]~input_o\,
	datab => \a[1]~input_o\,
	datad => VCC,
	cin => \LessThan0~1_cout\,
	cout => \LessThan0~3_cout\);

-- Location: LCCOMB_X1_Y11_N8
\LessThan0~5\ : cycloneive_lcell_comb
-- Equation(s):
-- \LessThan0~5_cout\ = CARRY((\b[2]~input_o\ & ((!\LessThan0~3_cout\) # (!\a[2]~input_o\))) # (!\b[2]~input_o\ & (!\a[2]~input_o\ & !\LessThan0~3_cout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000101011",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \b[2]~input_o\,
	datab => \a[2]~input_o\,
	datad => VCC,
	cin => \LessThan0~3_cout\,
	cout => \LessThan0~5_cout\);

-- Location: LCCOMB_X1_Y11_N10
\LessThan0~7\ : cycloneive_lcell_comb
-- Equation(s):
-- \LessThan0~7_cout\ = CARRY((\b[3]~input_o\ & (\a[3]~input_o\ & !\LessThan0~5_cout\)) # (!\b[3]~input_o\ & ((\a[3]~input_o\) # (!\LessThan0~5_cout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000001001101",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \b[3]~input_o\,
	datab => \a[3]~input_o\,
	datad => VCC,
	cin => \LessThan0~5_cout\,
	cout => \LessThan0~7_cout\);

-- Location: LCCOMB_X1_Y11_N12
\LessThan0~9\ : cycloneive_lcell_comb
-- Equation(s):
-- \LessThan0~9_cout\ = CARRY((\b[4]~input_o\ & ((!\LessThan0~7_cout\) # (!\a[4]~input_o\))) # (!\b[4]~input_o\ & (!\a[4]~input_o\ & !\LessThan0~7_cout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000101011",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \b[4]~input_o\,
	datab => \a[4]~input_o\,
	datad => VCC,
	cin => \LessThan0~7_cout\,
	cout => \LessThan0~9_cout\);

-- Location: LCCOMB_X1_Y11_N14
\LessThan0~11\ : cycloneive_lcell_comb
-- Equation(s):
-- \LessThan0~11_cout\ = CARRY((\b[5]~input_o\ & (\a[5]~input_o\ & !\LessThan0~9_cout\)) # (!\b[5]~input_o\ & ((\a[5]~input_o\) # (!\LessThan0~9_cout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000001001101",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \b[5]~input_o\,
	datab => \a[5]~input_o\,
	datad => VCC,
	cin => \LessThan0~9_cout\,
	cout => \LessThan0~11_cout\);

-- Location: LCCOMB_X1_Y11_N16
\LessThan0~13\ : cycloneive_lcell_comb
-- Equation(s):
-- \LessThan0~13_cout\ = CARRY((\a[6]~input_o\ & (\b[6]~input_o\ & !\LessThan0~11_cout\)) # (!\a[6]~input_o\ & ((\b[6]~input_o\) # (!\LessThan0~11_cout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000001001101",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \a[6]~input_o\,
	datab => \b[6]~input_o\,
	datad => VCC,
	cin => \LessThan0~11_cout\,
	cout => \LessThan0~13_cout\);

-- Location: LCCOMB_X1_Y11_N18
\LessThan0~14\ : cycloneive_lcell_comb
-- Equation(s):
-- \LessThan0~14_combout\ = (\a[7]~input_o\ & (\LessThan0~13_cout\ & \b[7]~input_o\)) # (!\a[7]~input_o\ & ((\LessThan0~13_cout\) # (\b[7]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111001100110000",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \a[7]~input_o\,
	datad => \b[7]~input_o\,
	cin => \LessThan0~13_cout\,
	combout => \LessThan0~14_combout\);

-- Location: LCCOMB_X1_Y11_N0
\temp~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \temp~0_combout\ = (\LessThan0~14_combout\ & ((\a[0]~input_o\))) # (!\LessThan0~14_combout\ & (\b[0]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \b[0]~input_o\,
	datac => \a[0]~input_o\,
	datad => \LessThan0~14_combout\,
	combout => \temp~0_combout\);

-- Location: IOIBUF_X0_Y23_N1
\b[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_b(1),
	o => \b[1]~input_o\);

-- Location: LCCOMB_X1_Y11_N26
\temp~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \temp~1_combout\ = (\LessThan0~14_combout\ & ((\a[1]~input_o\))) # (!\LessThan0~14_combout\ & (\b[1]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110111000100010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \b[1]~input_o\,
	datab => \LessThan0~14_combout\,
	datad => \a[1]~input_o\,
	combout => \temp~1_combout\);

-- Location: IOIBUF_X0_Y19_N22
\b[2]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_b(2),
	o => \b[2]~input_o\);

-- Location: LCCOMB_X1_Y11_N28
\temp~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \temp~2_combout\ = (\LessThan0~14_combout\ & ((\a[2]~input_o\))) # (!\LessThan0~14_combout\ & (\b[2]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110000110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \LessThan0~14_combout\,
	datac => \b[2]~input_o\,
	datad => \a[2]~input_o\,
	combout => \temp~2_combout\);

-- Location: IOIBUF_X0_Y10_N1
\b[3]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_b(3),
	o => \b[3]~input_o\);

-- Location: LCCOMB_X1_Y11_N22
\temp~3\ : cycloneive_lcell_comb
-- Equation(s):
-- \temp~3_combout\ = (\LessThan0~14_combout\ & ((\a[3]~input_o\))) # (!\LessThan0~14_combout\ & (\b[3]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \b[3]~input_o\,
	datac => \a[3]~input_o\,
	datad => \LessThan0~14_combout\,
	combout => \temp~3_combout\);

-- Location: IOIBUF_X0_Y10_N22
\b[4]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_b(4),
	o => \b[4]~input_o\);

-- Location: LCCOMB_X1_Y11_N24
\temp~4\ : cycloneive_lcell_comb
-- Equation(s):
-- \temp~4_combout\ = (\LessThan0~14_combout\ & ((\a[4]~input_o\))) # (!\LessThan0~14_combout\ & (\b[4]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \b[4]~input_o\,
	datac => \a[4]~input_o\,
	datad => \LessThan0~14_combout\,
	combout => \temp~4_combout\);

-- Location: IOIBUF_X0_Y21_N8
\b[5]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_b(5),
	o => \b[5]~input_o\);

-- Location: LCCOMB_X1_Y11_N2
\temp~5\ : cycloneive_lcell_comb
-- Equation(s):
-- \temp~5_combout\ = (\LessThan0~14_combout\ & (\a[5]~input_o\)) # (!\LessThan0~14_combout\ & ((\b[5]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101011110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \a[5]~input_o\,
	datac => \b[5]~input_o\,
	datad => \LessThan0~14_combout\,
	combout => \temp~5_combout\);

-- Location: IOIBUF_X0_Y8_N15
\a[6]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(6),
	o => \a[6]~input_o\);

-- Location: LCCOMB_X1_Y11_N20
\temp~6\ : cycloneive_lcell_comb
-- Equation(s):
-- \temp~6_combout\ = (\LessThan0~14_combout\ & (\a[6]~input_o\)) # (!\LessThan0~14_combout\ & ((\b[6]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111001111000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \LessThan0~14_combout\,
	datac => \a[6]~input_o\,
	datad => \b[6]~input_o\,
	combout => \temp~6_combout\);

-- Location: LCCOMB_X1_Y11_N30
\temp~7\ : cycloneive_lcell_comb
-- Equation(s):
-- \temp~7_combout\ = (\LessThan0~14_combout\ & ((\a[7]~input_o\))) # (!\LessThan0~14_combout\ & (\b[7]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \b[7]~input_o\,
	datab => \a[7]~input_o\,
	datad => \LessThan0~14_combout\,
	combout => \temp~7_combout\);

ww_y_out(0) <= \y_out[0]~output_o\;

ww_y_out(1) <= \y_out[1]~output_o\;

ww_y_out(2) <= \y_out[2]~output_o\;

ww_y_out(3) <= \y_out[3]~output_o\;

ww_y_out(4) <= \y_out[4]~output_o\;

ww_y_out(5) <= \y_out[5]~output_o\;

ww_y_out(6) <= \y_out[6]~output_o\;

ww_y_out(7) <= \y_out[7]~output_o\;
END structure;


