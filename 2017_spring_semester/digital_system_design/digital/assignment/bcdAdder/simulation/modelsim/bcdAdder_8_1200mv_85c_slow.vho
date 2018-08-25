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

-- DATE "04/15/2017 17:45:04"

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

ENTITY 	bcdAdder IS
    PORT (
	a : IN std_logic_vector(3 DOWNTO 0);
	b : IN std_logic_vector(3 DOWNTO 0);
	carryIn : IN std_logic;
	out_put_carry : OUT std_logic;
	sum : OUT std_logic_vector(3 DOWNTO 0)
	);
END bcdAdder;

-- Design Ports Information
-- out_put_carry	=>  Location: PIN_B12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- sum[0]	=>  Location: PIN_F10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- sum[1]	=>  Location: PIN_N16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- sum[2]	=>  Location: PIN_D14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- sum[3]	=>  Location: PIN_A12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[3]	=>  Location: PIN_B11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- b[3]	=>  Location: PIN_E10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[2]	=>  Location: PIN_D12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- b[2]	=>  Location: PIN_G11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[1]	=>  Location: PIN_C16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- b[1]	=>  Location: PIN_A14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- b[0]	=>  Location: PIN_F11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- carryIn	=>  Location: PIN_A11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[0]	=>  Location: PIN_F9,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF bcdAdder IS
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
SIGNAL ww_out_put_carry : std_logic;
SIGNAL ww_sum : std_logic_vector(3 DOWNTO 0);
SIGNAL \out_put_carry~output_o\ : std_logic;
SIGNAL \sum[0]~output_o\ : std_logic;
SIGNAL \sum[1]~output_o\ : std_logic;
SIGNAL \sum[2]~output_o\ : std_logic;
SIGNAL \sum[3]~output_o\ : std_logic;
SIGNAL \a[0]~input_o\ : std_logic;
SIGNAL \b[0]~input_o\ : std_logic;
SIGNAL \u1|u1|u3|c~0_combout\ : std_logic;
SIGNAL \a[1]~input_o\ : std_logic;
SIGNAL \b[1]~input_o\ : std_logic;
SIGNAL \u1|u2|u3|c~0_combout\ : std_logic;
SIGNAL \b[2]~input_o\ : std_logic;
SIGNAL \a[2]~input_o\ : std_logic;
SIGNAL \u1|u3|u2|s~combout\ : std_logic;
SIGNAL \u1|u3|u3|c~0_combout\ : std_logic;
SIGNAL \a[3]~input_o\ : std_logic;
SIGNAL \u1|u4|u2|s~combout\ : std_logic;
SIGNAL \u1|u4|u3|c~0_combout\ : std_logic;
SIGNAL \u1|u2|u2|s~combout\ : std_logic;
SIGNAL \u4|o~0_combout\ : std_logic;
SIGNAL \carryIn~input_o\ : std_logic;
SIGNAL \u5|u1|u2|c~combout\ : std_logic;
SIGNAL \u5|u3|u3|c~0_combout\ : std_logic;
SIGNAL \u5|u4|u2|c~combout\ : std_logic;
SIGNAL \u5|u1|u2|s~combout\ : std_logic;
SIGNAL \u5|u2|u2|s~combout\ : std_logic;
SIGNAL \u5|u3|u2|s~0_combout\ : std_logic;
SIGNAL \u5|u3|u2|s~1_combout\ : std_logic;
SIGNAL \b[3]~input_o\ : std_logic;
SIGNAL \u5|u4|u2|s~combout\ : std_logic;

BEGIN

ww_a <= a;
ww_b <= b;
ww_carryIn <= carryIn;
out_put_carry <= ww_out_put_carry;
sum <= ww_sum;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOOBUF_X25_Y24_N9
\out_put_carry~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u4|o~0_combout\,
	devoe => ww_devoe,
	o => \out_put_carry~output_o\);

-- Location: IOOBUF_X23_Y24_N9
\sum[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u5|u1|u2|s~combout\,
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
	i => \u5|u2|u2|s~combout\,
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
	i => \u5|u3|u2|s~1_combout\,
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
	i => \u5|u4|u2|s~combout\,
	devoe => ww_devoe,
	o => \sum[3]~output_o\);

-- Location: IOIBUF_X23_Y24_N15
\a[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(0),
	o => \a[0]~input_o\);

-- Location: IOIBUF_X23_Y24_N22
\b[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_b(0),
	o => \b[0]~input_o\);

-- Location: LCCOMB_X26_Y23_N24
\u1|u1|u3|c~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u1|u1|u3|c~0_combout\ = (\carryIn~input_o\ & ((\a[0]~input_o\) # (\b[0]~input_o\))) # (!\carryIn~input_o\ & (\a[0]~input_o\ & \b[0]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110100011101000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \carryIn~input_o\,
	datab => \a[0]~input_o\,
	datac => \b[0]~input_o\,
	combout => \u1|u1|u3|c~0_combout\);

-- Location: IOIBUF_X34_Y20_N8
\a[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(1),
	o => \a[1]~input_o\);

-- Location: IOIBUF_X28_Y24_N1
\b[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_b(1),
	o => \b[1]~input_o\);

-- Location: LCCOMB_X26_Y23_N2
\u1|u2|u3|c~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u1|u2|u3|c~0_combout\ = (\u1|u1|u3|c~0_combout\ & ((\a[1]~input_o\) # (\b[1]~input_o\))) # (!\u1|u1|u3|c~0_combout\ & (\a[1]~input_o\ & \b[1]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110011000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u1|u1|u3|c~0_combout\,
	datac => \a[1]~input_o\,
	datad => \b[1]~input_o\,
	combout => \u1|u2|u3|c~0_combout\);

-- Location: IOIBUF_X34_Y20_N15
\b[2]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_b(2),
	o => \b[2]~input_o\);

-- Location: IOIBUF_X30_Y24_N1
\a[2]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(2),
	o => \a[2]~input_o\);

-- Location: LCCOMB_X26_Y23_N26
\u1|u3|u2|s\ : cycloneive_lcell_comb
-- Equation(s):
-- \u1|u3|u2|s~combout\ = \u1|u2|u3|c~0_combout\ $ (\b[2]~input_o\ $ (\a[2]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100111100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u1|u2|u3|c~0_combout\,
	datac => \b[2]~input_o\,
	datad => \a[2]~input_o\,
	combout => \u1|u3|u2|s~combout\);

-- Location: LCCOMB_X26_Y23_N20
\u1|u3|u3|c~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u1|u3|u3|c~0_combout\ = (\u1|u2|u3|c~0_combout\ & ((\b[2]~input_o\) # (\a[2]~input_o\))) # (!\u1|u2|u3|c~0_combout\ & (\b[2]~input_o\ & \a[2]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110011000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u1|u2|u3|c~0_combout\,
	datac => \b[2]~input_o\,
	datad => \a[2]~input_o\,
	combout => \u1|u3|u3|c~0_combout\);

-- Location: IOIBUF_X25_Y24_N22
\a[3]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(3),
	o => \a[3]~input_o\);

-- Location: LCCOMB_X26_Y23_N8
\u1|u4|u2|s\ : cycloneive_lcell_comb
-- Equation(s):
-- \u1|u4|u2|s~combout\ = \b[3]~input_o\ $ (\u1|u3|u3|c~0_combout\ $ (\a[3]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1001011010010110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \b[3]~input_o\,
	datab => \u1|u3|u3|c~0_combout\,
	datac => \a[3]~input_o\,
	combout => \u1|u4|u2|s~combout\);

-- Location: LCCOMB_X26_Y23_N22
\u1|u4|u3|c~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u1|u4|u3|c~0_combout\ = (\b[3]~input_o\ & ((\u1|u3|u3|c~0_combout\) # (\a[3]~input_o\))) # (!\b[3]~input_o\ & (\u1|u3|u3|c~0_combout\ & \a[3]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110100011101000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \b[3]~input_o\,
	datab => \u1|u3|u3|c~0_combout\,
	datac => \a[3]~input_o\,
	combout => \u1|u4|u3|c~0_combout\);

-- Location: LCCOMB_X26_Y23_N28
\u1|u2|u2|s\ : cycloneive_lcell_comb
-- Equation(s):
-- \u1|u2|u2|s~combout\ = \u1|u1|u3|c~0_combout\ $ (\a[1]~input_o\ $ (\b[1]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100111100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u1|u1|u3|c~0_combout\,
	datac => \a[1]~input_o\,
	datad => \b[1]~input_o\,
	combout => \u1|u2|u2|s~combout\);

-- Location: LCCOMB_X26_Y23_N6
\u4|o~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|o~0_combout\ = (\u1|u4|u3|c~0_combout\) # ((\u1|u4|u2|s~combout\ & ((\u1|u3|u2|s~combout\) # (\u1|u2|u2|s~combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110011111000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u1|u3|u2|s~combout\,
	datab => \u1|u4|u2|s~combout\,
	datac => \u1|u4|u3|c~0_combout\,
	datad => \u1|u2|u2|s~combout\,
	combout => \u4|o~0_combout\);

-- Location: IOIBUF_X25_Y24_N15
\carryIn~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_carryIn,
	o => \carryIn~input_o\);

-- Location: LCCOMB_X26_Y23_N10
\u5|u1|u2|c\ : cycloneive_lcell_comb
-- Equation(s):
-- \u5|u1|u2|c~combout\ = (\u5|u4|u2|c~combout\ & (\carryIn~input_o\ $ (\a[0]~input_o\ $ (\b[0]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1001000001100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \carryIn~input_o\,
	datab => \a[0]~input_o\,
	datac => \u5|u4|u2|c~combout\,
	datad => \b[0]~input_o\,
	combout => \u5|u1|u2|c~combout\);

-- Location: LCCOMB_X26_Y23_N18
\u5|u3|u3|c~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u5|u3|u3|c~0_combout\ = (\u1|u3|u2|s~combout\ & ((\u1|u4|u3|c~0_combout\) # ((\u1|u2|u2|s~combout\ & \u5|u1|u2|c~combout\)))) # (!\u1|u3|u2|s~combout\ & (\u1|u4|u3|c~0_combout\ & ((\u1|u2|u2|s~combout\) # (\u5|u1|u2|c~combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111100011100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u1|u3|u2|s~combout\,
	datab => \u1|u2|u2|s~combout\,
	datac => \u1|u4|u3|c~0_combout\,
	datad => \u5|u1|u2|c~combout\,
	combout => \u5|u3|u3|c~0_combout\);

-- Location: LCCOMB_X26_Y23_N30
\u5|u4|u2|c\ : cycloneive_lcell_comb
-- Equation(s):
-- \u5|u4|u2|c~combout\ = (\u5|u3|u3|c~0_combout\ & (\b[3]~input_o\ $ (\a[3]~input_o\ $ (\u1|u3|u3|c~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000010001001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \b[3]~input_o\,
	datab => \u5|u3|u3|c~0_combout\,
	datac => \a[3]~input_o\,
	datad => \u1|u3|u3|c~0_combout\,
	combout => \u5|u4|u2|c~combout\);

-- Location: LCCOMB_X26_Y23_N0
\u5|u1|u2|s\ : cycloneive_lcell_comb
-- Equation(s):
-- \u5|u1|u2|s~combout\ = \carryIn~input_o\ $ (\a[0]~input_o\ $ (\u5|u4|u2|c~combout\ $ (\b[0]~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0110100110010110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \carryIn~input_o\,
	datab => \a[0]~input_o\,
	datac => \u5|u4|u2|c~combout\,
	datad => \b[0]~input_o\,
	combout => \u5|u1|u2|s~combout\);

-- Location: LCCOMB_X26_Y23_N12
\u5|u2|u2|s\ : cycloneive_lcell_comb
-- Equation(s):
-- \u5|u2|u2|s~combout\ = \u5|u1|u2|c~combout\ $ (\u1|u2|u2|s~combout\ $ (\u1|u4|u3|c~0_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1001011010010110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u5|u1|u2|c~combout\,
	datab => \u1|u2|u2|s~combout\,
	datac => \u1|u4|u3|c~0_combout\,
	combout => \u5|u2|u2|s~combout\);

-- Location: LCCOMB_X26_Y23_N14
\u5|u3|u2|s~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u5|u3|u2|s~0_combout\ = (\u5|u4|u2|c~combout\ & (\carryIn~input_o\ $ (\a[0]~input_o\ $ (\b[0]~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1001000001100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \carryIn~input_o\,
	datab => \a[0]~input_o\,
	datac => \u5|u4|u2|c~combout\,
	datad => \b[0]~input_o\,
	combout => \u5|u3|u2|s~0_combout\);

-- Location: LCCOMB_X26_Y23_N16
\u5|u3|u2|s~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u5|u3|u2|s~1_combout\ = \u1|u3|u2|s~combout\ $ (((\u5|u3|u2|s~0_combout\ & (!\u1|u4|u3|c~0_combout\ & \u1|u2|u2|s~combout\)) # (!\u5|u3|u2|s~0_combout\ & (\u1|u4|u3|c~0_combout\ & !\u1|u2|u2|s~combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010011010011010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u1|u3|u2|s~combout\,
	datab => \u5|u3|u2|s~0_combout\,
	datac => \u1|u4|u3|c~0_combout\,
	datad => \u1|u2|u2|s~combout\,
	combout => \u5|u3|u2|s~1_combout\);

-- Location: IOIBUF_X28_Y24_N22
\b[3]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_b(3),
	o => \b[3]~input_o\);

-- Location: LCCOMB_X26_Y23_N4
\u5|u4|u2|s\ : cycloneive_lcell_comb
-- Equation(s):
-- \u5|u4|u2|s~combout\ = \b[3]~input_o\ $ (\u5|u3|u3|c~0_combout\ $ (\a[3]~input_o\ $ (\u1|u3|u3|c~0_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0110100110010110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \b[3]~input_o\,
	datab => \u5|u3|u3|c~0_combout\,
	datac => \a[3]~input_o\,
	datad => \u1|u3|u3|c~0_combout\,
	combout => \u5|u4|u2|s~combout\);

ww_out_put_carry <= \out_put_carry~output_o\;

ww_sum(0) <= \sum[0]~output_o\;

ww_sum(1) <= \sum[1]~output_o\;

ww_sum(2) <= \sum[2]~output_o\;

ww_sum(3) <= \sum[3]~output_o\;
END structure;


