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

-- DATE "05/02/2017 16:23:38"

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

ENTITY 	kygmaxmin2 IS
    PORT (
	x : IN std_logic_vector(4 DOWNTO 0);
	y : IN std_logic_vector(4 DOWNTO 0);
	max : OUT std_logic_vector(4 DOWNTO 0);
	min : OUT std_logic_vector(4 DOWNTO 0)
	);
END kygmaxmin2;

-- Design Ports Information
-- max[0]	=>  Location: PIN_D15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- max[1]	=>  Location: PIN_D12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- max[2]	=>  Location: PIN_G11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- max[3]	=>  Location: PIN_K11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- max[4]	=>  Location: PIN_C11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- min[0]	=>  Location: PIN_C15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- min[1]	=>  Location: PIN_D14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- min[2]	=>  Location: PIN_D16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- min[3]	=>  Location: PIN_A9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- min[4]	=>  Location: PIN_A11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x[0]	=>  Location: PIN_E16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y[0]	=>  Location: PIN_E15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x[4]	=>  Location: PIN_A13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x[3]	=>  Location: PIN_L11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y[3]	=>  Location: PIN_J14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y[4]	=>  Location: PIN_C14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x[2]	=>  Location: PIN_B11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x[1]	=>  Location: PIN_F14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y[1]	=>  Location: PIN_B14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y[2]	=>  Location: PIN_C16,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF kygmaxmin2 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_x : std_logic_vector(4 DOWNTO 0);
SIGNAL ww_y : std_logic_vector(4 DOWNTO 0);
SIGNAL ww_max : std_logic_vector(4 DOWNTO 0);
SIGNAL ww_min : std_logic_vector(4 DOWNTO 0);
SIGNAL \LessThan0~1_combout\ : std_logic;
SIGNAL \max[0]~output_o\ : std_logic;
SIGNAL \max[1]~output_o\ : std_logic;
SIGNAL \max[2]~output_o\ : std_logic;
SIGNAL \max[3]~output_o\ : std_logic;
SIGNAL \max[4]~output_o\ : std_logic;
SIGNAL \min[0]~output_o\ : std_logic;
SIGNAL \min[1]~output_o\ : std_logic;
SIGNAL \min[2]~output_o\ : std_logic;
SIGNAL \min[3]~output_o\ : std_logic;
SIGNAL \min[4]~output_o\ : std_logic;
SIGNAL \y[1]~input_o\ : std_logic;
SIGNAL \y[0]~input_o\ : std_logic;
SIGNAL \x[1]~input_o\ : std_logic;
SIGNAL \LessThan0~2_combout\ : std_logic;
SIGNAL \x[2]~input_o\ : std_logic;
SIGNAL \y[2]~input_o\ : std_logic;
SIGNAL \LessThan0~3_combout\ : std_logic;
SIGNAL \x[3]~input_o\ : std_logic;
SIGNAL \x[4]~input_o\ : std_logic;
SIGNAL \y[3]~input_o\ : std_logic;
SIGNAL \LessThan0~0_combout\ : std_logic;
SIGNAL \x[0]~input_o\ : std_logic;
SIGNAL \c~0_combout\ : std_logic;
SIGNAL \c~1_combout\ : std_logic;
SIGNAL \c~2_combout\ : std_logic;
SIGNAL \c~3_combout\ : std_logic;
SIGNAL \y[4]~input_o\ : std_logic;
SIGNAL \c~4_combout\ : std_logic;
SIGNAL \d~0_combout\ : std_logic;
SIGNAL \d~1_combout\ : std_logic;
SIGNAL \d~2_combout\ : std_logic;
SIGNAL \d~3_combout\ : std_logic;
SIGNAL \d~4_combout\ : std_logic;

BEGIN

ww_x <= x;
ww_y <= y;
max <= ww_max;
min <= ww_min;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: LCCOMB_X31_Y20_N18
\LessThan0~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \LessThan0~1_combout\ = (\y[4]~input_o\ & (\x[4]~input_o\ & (\x[3]~input_o\ $ (!\y[3]~input_o\)))) # (!\y[4]~input_o\ & (!\x[4]~input_o\ & (\x[3]~input_o\ $ (!\y[3]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000010000100001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \y[4]~input_o\,
	datab => \x[3]~input_o\,
	datac => \x[4]~input_o\,
	datad => \y[3]~input_o\,
	combout => \LessThan0~1_combout\);

-- Location: IOOBUF_X34_Y19_N2
\max[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \c~0_combout\,
	devoe => ww_devoe,
	o => \max[0]~output_o\);

-- Location: IOOBUF_X30_Y24_N2
\max[1]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \c~1_combout\,
	devoe => ww_devoe,
	o => \max[1]~output_o\);

-- Location: IOOBUF_X34_Y20_N16
\max[2]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \c~2_combout\,
	devoe => ww_devoe,
	o => \max[2]~output_o\);

-- Location: IOOBUF_X34_Y6_N16
\max[3]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \c~3_combout\,
	devoe => ww_devoe,
	o => \max[3]~output_o\);

-- Location: IOOBUF_X23_Y24_N2
\max[4]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \c~4_combout\,
	devoe => ww_devoe,
	o => \max[4]~output_o\);

-- Location: IOOBUF_X34_Y20_N2
\min[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \d~0_combout\,
	devoe => ww_devoe,
	o => \min[0]~output_o\);

-- Location: IOOBUF_X32_Y24_N16
\min[1]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \d~1_combout\,
	devoe => ww_devoe,
	o => \min[1]~output_o\);

-- Location: IOOBUF_X34_Y19_N9
\min[2]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \d~2_combout\,
	devoe => ww_devoe,
	o => \min[2]~output_o\);

-- Location: IOOBUF_X16_Y24_N2
\min[3]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \d~3_combout\,
	devoe => ww_devoe,
	o => \min[3]~output_o\);

-- Location: IOOBUF_X25_Y24_N16
\min[4]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \d~4_combout\,
	devoe => ww_devoe,
	o => \min[4]~output_o\);

-- Location: IOIBUF_X28_Y24_N8
\y[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_y(1),
	o => \y[1]~input_o\);

-- Location: IOIBUF_X34_Y12_N1
\y[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_y(0),
	o => \y[0]~input_o\);

-- Location: IOIBUF_X34_Y19_N15
\x[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x(1),
	o => \x[1]~input_o\);

-- Location: LCCOMB_X31_Y20_N20
\LessThan0~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \LessThan0~2_combout\ = (\y[1]~input_o\ & (\x[0]~input_o\ & (!\y[0]~input_o\ & \x[1]~input_o\))) # (!\y[1]~input_o\ & ((\x[1]~input_o\) # ((\x[0]~input_o\ & !\y[0]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011101100000010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \x[0]~input_o\,
	datab => \y[1]~input_o\,
	datac => \y[0]~input_o\,
	datad => \x[1]~input_o\,
	combout => \LessThan0~2_combout\);

-- Location: IOIBUF_X25_Y24_N22
\x[2]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x(2),
	o => \x[2]~input_o\);

-- Location: IOIBUF_X34_Y20_N8
\y[2]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_y(2),
	o => \y[2]~input_o\);

-- Location: LCCOMB_X31_Y20_N22
\LessThan0~3\ : cycloneive_lcell_comb
-- Equation(s):
-- \LessThan0~3_combout\ = (\LessThan0~1_combout\ & ((\LessThan0~2_combout\ & ((\x[2]~input_o\) # (!\y[2]~input_o\))) # (!\LessThan0~2_combout\ & (\x[2]~input_o\ & !\y[2]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000000010101000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \LessThan0~1_combout\,
	datab => \LessThan0~2_combout\,
	datac => \x[2]~input_o\,
	datad => \y[2]~input_o\,
	combout => \LessThan0~3_combout\);

-- Location: IOIBUF_X32_Y0_N15
\x[3]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x(3),
	o => \x[3]~input_o\);

-- Location: IOIBUF_X30_Y24_N8
\x[4]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x(4),
	o => \x[4]~input_o\);

-- Location: IOIBUF_X34_Y10_N1
\y[3]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_y(3),
	o => \y[3]~input_o\);

-- Location: LCCOMB_X31_Y20_N0
\LessThan0~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \LessThan0~0_combout\ = (\y[4]~input_o\ & (\x[3]~input_o\ & (\x[4]~input_o\ & !\y[3]~input_o\))) # (!\y[4]~input_o\ & ((\x[4]~input_o\) # ((\x[3]~input_o\ & !\y[3]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101000011010100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \y[4]~input_o\,
	datab => \x[3]~input_o\,
	datac => \x[4]~input_o\,
	datad => \y[3]~input_o\,
	combout => \LessThan0~0_combout\);

-- Location: IOIBUF_X34_Y12_N8
\x[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x(0),
	o => \x[0]~input_o\);

-- Location: LCCOMB_X31_Y20_N8
\c~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \c~0_combout\ = (\LessThan0~3_combout\ & (((\x[0]~input_o\)))) # (!\LessThan0~3_combout\ & ((\LessThan0~0_combout\ & ((\x[0]~input_o\))) # (!\LessThan0~0_combout\ & (\y[0]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111000010000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \LessThan0~3_combout\,
	datab => \LessThan0~0_combout\,
	datac => \y[0]~input_o\,
	datad => \x[0]~input_o\,
	combout => \c~0_combout\);

-- Location: LCCOMB_X31_Y20_N2
\c~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \c~1_combout\ = (\LessThan0~3_combout\ & (((\x[1]~input_o\)))) # (!\LessThan0~3_combout\ & ((\LessThan0~0_combout\ & ((\x[1]~input_o\))) # (!\LessThan0~0_combout\ & (\y[1]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111000010000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \LessThan0~3_combout\,
	datab => \LessThan0~0_combout\,
	datac => \y[1]~input_o\,
	datad => \x[1]~input_o\,
	combout => \c~1_combout\);

-- Location: LCCOMB_X31_Y20_N4
\c~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \c~2_combout\ = (\LessThan0~3_combout\ & (((\x[2]~input_o\)))) # (!\LessThan0~3_combout\ & ((\LessThan0~0_combout\ & (\x[2]~input_o\)) # (!\LessThan0~0_combout\ & ((\y[2]~input_o\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000111100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \LessThan0~3_combout\,
	datab => \LessThan0~0_combout\,
	datac => \x[2]~input_o\,
	datad => \y[2]~input_o\,
	combout => \c~2_combout\);

-- Location: LCCOMB_X31_Y20_N6
\c~3\ : cycloneive_lcell_comb
-- Equation(s):
-- \c~3_combout\ = (\LessThan0~0_combout\ & (\x[3]~input_o\)) # (!\LessThan0~0_combout\ & ((\LessThan0~3_combout\ & (\x[3]~input_o\)) # (!\LessThan0~3_combout\ & ((\y[3]~input_o\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110111001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \LessThan0~0_combout\,
	datab => \x[3]~input_o\,
	datac => \LessThan0~3_combout\,
	datad => \y[3]~input_o\,
	combout => \c~3_combout\);

-- Location: IOIBUF_X32_Y24_N8
\y[4]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_y(4),
	o => \y[4]~input_o\);

-- Location: LCCOMB_X31_Y20_N24
\c~4\ : cycloneive_lcell_comb
-- Equation(s):
-- \c~4_combout\ = (\LessThan0~3_combout\ & (((\x[4]~input_o\)))) # (!\LessThan0~3_combout\ & ((\LessThan0~0_combout\ & (\x[4]~input_o\)) # (!\LessThan0~0_combout\ & ((\y[4]~input_o\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000111100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \LessThan0~3_combout\,
	datab => \LessThan0~0_combout\,
	datac => \x[4]~input_o\,
	datad => \y[4]~input_o\,
	combout => \c~4_combout\);

-- Location: LCCOMB_X31_Y20_N10
\d~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \d~0_combout\ = (\LessThan0~3_combout\ & (((\y[0]~input_o\)))) # (!\LessThan0~3_combout\ & ((\LessThan0~0_combout\ & (\y[0]~input_o\)) # (!\LessThan0~0_combout\ & ((\x[0]~input_o\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000111100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \LessThan0~3_combout\,
	datab => \LessThan0~0_combout\,
	datac => \y[0]~input_o\,
	datad => \x[0]~input_o\,
	combout => \d~0_combout\);

-- Location: LCCOMB_X31_Y20_N12
\d~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \d~1_combout\ = (\LessThan0~3_combout\ & (((\y[1]~input_o\)))) # (!\LessThan0~3_combout\ & ((\LessThan0~0_combout\ & (\y[1]~input_o\)) # (!\LessThan0~0_combout\ & ((\x[1]~input_o\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000111100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \LessThan0~3_combout\,
	datab => \LessThan0~0_combout\,
	datac => \y[1]~input_o\,
	datad => \x[1]~input_o\,
	combout => \d~1_combout\);

-- Location: LCCOMB_X31_Y20_N30
\d~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \d~2_combout\ = (\LessThan0~3_combout\ & (((\y[2]~input_o\)))) # (!\LessThan0~3_combout\ & ((\LessThan0~0_combout\ & ((\y[2]~input_o\))) # (!\LessThan0~0_combout\ & (\x[2]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111000010000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \LessThan0~3_combout\,
	datab => \LessThan0~0_combout\,
	datac => \x[2]~input_o\,
	datad => \y[2]~input_o\,
	combout => \d~2_combout\);

-- Location: LCCOMB_X31_Y20_N16
\d~3\ : cycloneive_lcell_comb
-- Equation(s):
-- \d~3_combout\ = (\LessThan0~0_combout\ & (((\y[3]~input_o\)))) # (!\LessThan0~0_combout\ & ((\LessThan0~3_combout\ & ((\y[3]~input_o\))) # (!\LessThan0~3_combout\ & (\x[3]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111000000100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \LessThan0~0_combout\,
	datab => \x[3]~input_o\,
	datac => \LessThan0~3_combout\,
	datad => \y[3]~input_o\,
	combout => \d~3_combout\);

-- Location: LCCOMB_X31_Y20_N26
\d~4\ : cycloneive_lcell_comb
-- Equation(s):
-- \d~4_combout\ = (\LessThan0~3_combout\ & (((\y[4]~input_o\)))) # (!\LessThan0~3_combout\ & ((\LessThan0~0_combout\ & ((\y[4]~input_o\))) # (!\LessThan0~0_combout\ & (\x[4]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111000010000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \LessThan0~3_combout\,
	datab => \LessThan0~0_combout\,
	datac => \x[4]~input_o\,
	datad => \y[4]~input_o\,
	combout => \d~4_combout\);

ww_max(0) <= \max[0]~output_o\;

ww_max(1) <= \max[1]~output_o\;

ww_max(2) <= \max[2]~output_o\;

ww_max(3) <= \max[3]~output_o\;

ww_max(4) <= \max[4]~output_o\;

ww_min(0) <= \min[0]~output_o\;

ww_min(1) <= \min[1]~output_o\;

ww_min(2) <= \min[2]~output_o\;

ww_min(3) <= \min[3]~output_o\;

ww_min(4) <= \min[4]~output_o\;
END structure;


