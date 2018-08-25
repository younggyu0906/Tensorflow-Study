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

-- DATE "04/15/2017 03:20:36"

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

ENTITY 	adder IS
    PORT (
	a : IN std_logic_vector(3 DOWNTO 0);
	b : IN std_logic_vector(3 DOWNTO 0);
	carry : INOUT std_logic_vector(4 DOWNTO 0);
	y_out : OUT std_logic_vector(4 DOWNTO 0)
	);
END adder;

-- Design Ports Information
-- y_out[0]	=>  Location: PIN_C2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y_out[1]	=>  Location: PIN_A10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y_out[2]	=>  Location: PIN_F5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y_out[3]	=>  Location: PIN_E10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y_out[4]	=>  Location: PIN_F8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- carry[0]	=>  Location: PIN_N2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- carry[1]	=>  Location: PIN_T6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- carry[2]	=>  Location: PIN_L10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- carry[3]	=>  Location: PIN_F10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- carry[4]	=>  Location: PIN_D8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[0]	=>  Location: PIN_E5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- b[0]	=>  Location: PIN_B1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[1]	=>  Location: PIN_B10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- b[1]	=>  Location: PIN_A15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[2]	=>  Location: PIN_C3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- b[2]	=>  Location: PIN_D3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[3]	=>  Location: PIN_A14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- b[3]	=>  Location: PIN_B14,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF adder IS
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
SIGNAL ww_y_out : std_logic_vector(4 DOWNTO 0);
SIGNAL \carry[0]~input_o\ : std_logic;
SIGNAL \carry[1]~input_o\ : std_logic;
SIGNAL \carry[2]~input_o\ : std_logic;
SIGNAL \carry[3]~input_o\ : std_logic;
SIGNAL \carry[0]~output_o\ : std_logic;
SIGNAL \carry[1]~output_o\ : std_logic;
SIGNAL \carry[2]~output_o\ : std_logic;
SIGNAL \carry[3]~output_o\ : std_logic;
SIGNAL \carry[4]~output_o\ : std_logic;
SIGNAL \y_out[0]~output_o\ : std_logic;
SIGNAL \y_out[1]~output_o\ : std_logic;
SIGNAL \y_out[2]~output_o\ : std_logic;
SIGNAL \y_out[3]~output_o\ : std_logic;
SIGNAL \y_out[4]~output_o\ : std_logic;
SIGNAL \a[0]~input_o\ : std_logic;
SIGNAL \b[0]~input_o\ : std_logic;
SIGNAL \y_out~0_combout\ : std_logic;
SIGNAL \b[1]~input_o\ : std_logic;
SIGNAL \a[1]~input_o\ : std_logic;
SIGNAL \y_out~1_combout\ : std_logic;
SIGNAL \a[2]~input_o\ : std_logic;
SIGNAL \b[2]~input_o\ : std_logic;
SIGNAL \y_out~2_combout\ : std_logic;
SIGNAL \a[3]~input_o\ : std_logic;
SIGNAL \b[3]~input_o\ : std_logic;
SIGNAL \y_out~3_combout\ : std_logic;
SIGNAL \carry[4]~input_o\ : std_logic;

BEGIN

ww_a <= a;
ww_b <= b;
y_out <= ww_y_out;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOOBUF_X0_Y7_N16
\carry[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => VCC,
	oe => VCC,
	devoe => ww_devoe,
	o => \carry[0]~output_o\);

-- Location: IOOBUF_X11_Y0_N16
\carry[1]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => VCC,
	oe => VCC,
	devoe => ww_devoe,
	o => \carry[1]~output_o\);

-- Location: IOOBUF_X25_Y0_N9
\carry[2]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => VCC,
	oe => VCC,
	devoe => ww_devoe,
	o => \carry[2]~output_o\);

-- Location: IOOBUF_X23_Y24_N9
\carry[3]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => VCC,
	oe => VCC,
	devoe => ww_devoe,
	o => \carry[3]~output_o\);

-- Location: IOOBUF_X13_Y24_N9
\carry[4]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "true")
-- pragma translate_on
PORT MAP (
	i => VCC,
	devoe => ww_devoe,
	o => \carry[4]~output_o\);

-- Location: IOOBUF_X0_Y22_N16
\y_out[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \y_out~0_combout\,
	devoe => ww_devoe,
	o => \y_out[0]~output_o\);

-- Location: IOOBUF_X21_Y24_N9
\y_out[1]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \y_out~1_combout\,
	devoe => ww_devoe,
	o => \y_out[1]~output_o\);

-- Location: IOOBUF_X0_Y23_N16
\y_out[2]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \y_out~2_combout\,
	devoe => ww_devoe,
	o => \y_out[2]~output_o\);

-- Location: IOOBUF_X28_Y24_N23
\y_out[3]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \y_out~3_combout\,
	devoe => ww_devoe,
	o => \y_out[3]~output_o\);

-- Location: IOOBUF_X13_Y24_N23
\y_out[4]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \carry[4]~input_o\,
	devoe => ww_devoe,
	o => \y_out[4]~output_o\);

-- Location: IOIBUF_X0_Y23_N8
\a[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(0),
	o => \a[0]~input_o\);

-- Location: IOIBUF_X0_Y22_N1
\b[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_b(0),
	o => \b[0]~input_o\);

-- Location: LCCOMB_X1_Y22_N16
\y_out~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \y_out~0_combout\ = \a[0]~input_o\ $ (!\b[0]~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000000001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \a[0]~input_o\,
	datad => \b[0]~input_o\,
	combout => \y_out~0_combout\);

-- Location: IOIBUF_X21_Y24_N1
\b[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_b(1),
	o => \b[1]~input_o\);

-- Location: IOIBUF_X21_Y24_N15
\a[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(1),
	o => \a[1]~input_o\);

-- Location: LCCOMB_X22_Y23_N0
\y_out~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \y_out~1_combout\ = \b[1]~input_o\ $ (!\a[1]~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110000110011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \b[1]~input_o\,
	datad => \a[1]~input_o\,
	combout => \y_out~1_combout\);

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

-- Location: IOIBUF_X1_Y24_N8
\b[2]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_b(2),
	o => \b[2]~input_o\);

-- Location: LCCOMB_X1_Y23_N16
\y_out~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \y_out~2_combout\ = \a[2]~input_o\ $ (!\b[2]~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010110100101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \a[2]~input_o\,
	datac => \b[2]~input_o\,
	combout => \y_out~2_combout\);

-- Location: IOIBUF_X28_Y24_N1
\a[3]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(3),
	o => \a[3]~input_o\);

-- Location: IOIBUF_X28_Y24_N8
\b[3]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_b(3),
	o => \b[3]~input_o\);

-- Location: LCCOMB_X28_Y23_N0
\y_out~3\ : cycloneive_lcell_comb
-- Equation(s):
-- \y_out~3_combout\ = \a[3]~input_o\ $ (!\b[3]~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001111000011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \a[3]~input_o\,
	datac => \b[3]~input_o\,
	combout => \y_out~3_combout\);

-- Location: IOIBUF_X13_Y24_N8
\carry[4]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => carry(4),
	o => \carry[4]~input_o\);

-- Location: IOIBUF_X0_Y7_N15
\carry[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => carry(0),
	o => \carry[0]~input_o\);

-- Location: IOIBUF_X11_Y0_N15
\carry[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => carry(1),
	o => \carry[1]~input_o\);

-- Location: IOIBUF_X25_Y0_N8
\carry[2]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => carry(2),
	o => \carry[2]~input_o\);

-- Location: IOIBUF_X23_Y24_N8
\carry[3]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => carry(3),
	o => \carry[3]~input_o\);

ww_y_out(0) <= \y_out[0]~output_o\;

ww_y_out(1) <= \y_out[1]~output_o\;

ww_y_out(2) <= \y_out[2]~output_o\;

ww_y_out(3) <= \y_out[3]~output_o\;

ww_y_out(4) <= \y_out[4]~output_o\;

carry(0) <= \carry[0]~output_o\;

carry(1) <= \carry[1]~output_o\;

carry(2) <= \carry[2]~output_o\;

carry(3) <= \carry[3]~output_o\;

carry(4) <= \carry[4]~output_o\;
END structure;


