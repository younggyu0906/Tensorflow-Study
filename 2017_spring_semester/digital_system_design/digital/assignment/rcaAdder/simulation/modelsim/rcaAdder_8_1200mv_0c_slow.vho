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

-- DATE "04/15/2017 15:33:38"

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

ENTITY 	rcaAdder IS
    PORT (
	x : IN std_logic_vector(3 DOWNTO 0);
	y : IN std_logic_vector(3 DOWNTO 0);
	c_in : IN std_logic;
	carry : OUT std_logic;
	sum : OUT std_logic_vector(3 DOWNTO 0)
	);
END rcaAdder;

-- Design Ports Information
-- carry	=>  Location: PIN_B12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- sum[0]	=>  Location: PIN_F10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- sum[1]	=>  Location: PIN_N16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- sum[2]	=>  Location: PIN_D14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- sum[3]	=>  Location: PIN_A12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x[3]	=>  Location: PIN_B11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y[3]	=>  Location: PIN_E10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x[2]	=>  Location: PIN_D12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y[2]	=>  Location: PIN_G11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x[1]	=>  Location: PIN_C16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y[1]	=>  Location: PIN_A14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y[0]	=>  Location: PIN_F11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- c_in	=>  Location: PIN_A11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x[0]	=>  Location: PIN_F9,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF rcaAdder IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_x : std_logic_vector(3 DOWNTO 0);
SIGNAL ww_y : std_logic_vector(3 DOWNTO 0);
SIGNAL ww_c_in : std_logic;
SIGNAL ww_carry : std_logic;
SIGNAL ww_sum : std_logic_vector(3 DOWNTO 0);
SIGNAL \carry~output_o\ : std_logic;
SIGNAL \sum[0]~output_o\ : std_logic;
SIGNAL \sum[1]~output_o\ : std_logic;
SIGNAL \sum[2]~output_o\ : std_logic;
SIGNAL \sum[3]~output_o\ : std_logic;
SIGNAL \y[2]~input_o\ : std_logic;
SIGNAL \x[2]~input_o\ : std_logic;
SIGNAL \u3|u3|c~0_combout\ : std_logic;
SIGNAL \x[3]~input_o\ : std_logic;
SIGNAL \y[3]~input_o\ : std_logic;
SIGNAL \u4|u3|c~0_combout\ : std_logic;
SIGNAL \c_in~input_o\ : std_logic;
SIGNAL \x[0]~input_o\ : std_logic;
SIGNAL \y[0]~input_o\ : std_logic;
SIGNAL \u1|u2|s~0_combout\ : std_logic;
SIGNAL \u1|u3|c~0_combout\ : std_logic;
SIGNAL \x[1]~input_o\ : std_logic;
SIGNAL \y[1]~input_o\ : std_logic;
SIGNAL \u2|u2|s~combout\ : std_logic;
SIGNAL \u2|u3|c~0_combout\ : std_logic;
SIGNAL \u3|u2|s~combout\ : std_logic;
SIGNAL \u4|u2|s~combout\ : std_logic;

BEGIN

ww_x <= x;
ww_y <= y;
ww_c_in <= c_in;
carry <= ww_carry;
sum <= ww_sum;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOOBUF_X25_Y24_N9
\carry~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u4|u3|c~0_combout\,
	devoe => ww_devoe,
	o => \carry~output_o\);

-- Location: IOOBUF_X23_Y24_N9
\sum[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u1|u2|s~0_combout\,
	devoe => ww_devoe,
	o => \sum[0]~output_o\);

-- Location: IOOBUF_X34_Y7_N23
\sum[1]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u2|u2|s~combout\,
	devoe => ww_devoe,
	o => \sum[1]~output_o\);

-- Location: IOOBUF_X32_Y24_N16
\sum[2]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u3|u2|s~combout\,
	devoe => ww_devoe,
	o => \sum[2]~output_o\);

-- Location: IOOBUF_X25_Y24_N2
\sum[3]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u4|u2|s~combout\,
	devoe => ww_devoe,
	o => \sum[3]~output_o\);

-- Location: IOIBUF_X34_Y20_N15
\y[2]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_y(2),
	o => \y[2]~input_o\);

-- Location: IOIBUF_X30_Y24_N1
\x[2]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x(2),
	o => \x[2]~input_o\);

-- Location: LCCOMB_X26_Y23_N12
\u3|u3|c~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|u3|c~0_combout\ = (\u2|u3|c~0_combout\ & ((\y[2]~input_o\) # (\x[2]~input_o\))) # (!\u2|u3|c~0_combout\ & (\y[2]~input_o\ & \x[2]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111101010100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|u3|c~0_combout\,
	datac => \y[2]~input_o\,
	datad => \x[2]~input_o\,
	combout => \u3|u3|c~0_combout\);

-- Location: IOIBUF_X25_Y24_N22
\x[3]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x(3),
	o => \x[3]~input_o\);

-- Location: IOIBUF_X28_Y24_N22
\y[3]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_y(3),
	o => \y[3]~input_o\);

-- Location: LCCOMB_X26_Y23_N22
\u4|u3|c~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|u3|c~0_combout\ = (\u3|u3|c~0_combout\ & ((\x[3]~input_o\) # (\y[3]~input_o\))) # (!\u3|u3|c~0_combout\ & (\x[3]~input_o\ & \y[3]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111101010100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u3|u3|c~0_combout\,
	datac => \x[3]~input_o\,
	datad => \y[3]~input_o\,
	combout => \u4|u3|c~0_combout\);

-- Location: IOIBUF_X25_Y24_N15
\c_in~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_c_in,
	o => \c_in~input_o\);

-- Location: IOIBUF_X23_Y24_N15
\x[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x(0),
	o => \x[0]~input_o\);

-- Location: IOIBUF_X23_Y24_N22
\y[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_y(0),
	o => \y[0]~input_o\);

-- Location: LCCOMB_X26_Y23_N0
\u1|u2|s~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u1|u2|s~0_combout\ = \c_in~input_o\ $ (\x[0]~input_o\ $ (\y[0]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1001011010010110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \c_in~input_o\,
	datab => \x[0]~input_o\,
	datac => \y[0]~input_o\,
	combout => \u1|u2|s~0_combout\);

-- Location: LCCOMB_X26_Y23_N24
\u1|u3|c~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u1|u3|c~0_combout\ = (\c_in~input_o\ & ((\x[0]~input_o\) # (\y[0]~input_o\))) # (!\c_in~input_o\ & (\x[0]~input_o\ & \y[0]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110100011101000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \c_in~input_o\,
	datab => \x[0]~input_o\,
	datac => \y[0]~input_o\,
	combout => \u1|u3|c~0_combout\);

-- Location: IOIBUF_X34_Y20_N8
\x[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x(1),
	o => \x[1]~input_o\);

-- Location: IOIBUF_X28_Y24_N1
\y[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_y(1),
	o => \y[1]~input_o\);

-- Location: LCCOMB_X26_Y23_N26
\u2|u2|s\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|u2|s~combout\ = \u1|u3|c~0_combout\ $ (\x[1]~input_o\ $ (\y[1]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100111100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u1|u3|c~0_combout\,
	datac => \x[1]~input_o\,
	datad => \y[1]~input_o\,
	combout => \u2|u2|s~combout\);

-- Location: LCCOMB_X26_Y23_N10
\u2|u3|c~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|u3|c~0_combout\ = (\u1|u3|c~0_combout\ & ((\x[1]~input_o\) # (\y[1]~input_o\))) # (!\u1|u3|c~0_combout\ & (\x[1]~input_o\ & \y[1]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110011000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u1|u3|c~0_combout\,
	datac => \x[1]~input_o\,
	datad => \y[1]~input_o\,
	combout => \u2|u3|c~0_combout\);

-- Location: LCCOMB_X26_Y23_N20
\u3|u2|s\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|u2|s~combout\ = \u2|u3|c~0_combout\ $ (\y[2]~input_o\ $ (\x[2]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010101011010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|u3|c~0_combout\,
	datac => \y[2]~input_o\,
	datad => \x[2]~input_o\,
	combout => \u3|u2|s~combout\);

-- Location: LCCOMB_X26_Y23_N6
\u4|u2|s\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|u2|s~combout\ = \u3|u3|c~0_combout\ $ (\x[3]~input_o\ $ (\y[3]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010101011010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u3|u3|c~0_combout\,
	datac => \x[3]~input_o\,
	datad => \y[3]~input_o\,
	combout => \u4|u2|s~combout\);

ww_carry <= \carry~output_o\;

ww_sum(0) <= \sum[0]~output_o\;

ww_sum(1) <= \sum[1]~output_o\;

ww_sum(2) <= \sum[2]~output_o\;

ww_sum(3) <= \sum[3]~output_o\;
END structure;


