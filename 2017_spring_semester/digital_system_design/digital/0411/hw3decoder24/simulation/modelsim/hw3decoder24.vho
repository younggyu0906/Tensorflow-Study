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

-- DATE "04/22/2017 08:02:14"

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

ENTITY 	hw3decoder24 IS
    PORT (
	a : IN std_logic_vector(1 DOWNTO 0);
	y : OUT std_logic_vector(3 DOWNTO 0)
	);
END hw3decoder24;

-- Design Ports Information
-- y[0]	=>  Location: PIN_F1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y[1]	=>  Location: PIN_B1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y[2]	=>  Location: PIN_G5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y[3]	=>  Location: PIN_C2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[0]	=>  Location: PIN_D1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[1]	=>  Location: PIN_F3,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF hw3decoder24 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_a : std_logic_vector(1 DOWNTO 0);
SIGNAL ww_y : std_logic_vector(3 DOWNTO 0);
SIGNAL \y[0]~output_o\ : std_logic;
SIGNAL \y[1]~output_o\ : std_logic;
SIGNAL \y[2]~output_o\ : std_logic;
SIGNAL \y[3]~output_o\ : std_logic;
SIGNAL \a[1]~input_o\ : std_logic;
SIGNAL \a[0]~input_o\ : std_logic;
SIGNAL \Mux3~0_combout\ : std_logic;
SIGNAL \Mux1~0_combout\ : std_logic;
SIGNAL \Mux1~1_combout\ : std_logic;
SIGNAL \Mux1~2_combout\ : std_logic;
SIGNAL \ALT_INV_Mux3~0_combout\ : std_logic;

BEGIN

ww_a <= a;
y <= ww_y;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
\ALT_INV_Mux3~0_combout\ <= NOT \Mux3~0_combout\;

-- Location: IOOBUF_X0_Y19_N23
\y[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \ALT_INV_Mux3~0_combout\,
	devoe => ww_devoe,
	o => \y[0]~output_o\);

-- Location: IOOBUF_X0_Y22_N2
\y[1]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Mux1~0_combout\,
	devoe => ww_devoe,
	o => \y[1]~output_o\);

-- Location: IOOBUF_X0_Y19_N2
\y[2]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Mux1~1_combout\,
	devoe => ww_devoe,
	o => \y[2]~output_o\);

-- Location: IOOBUF_X0_Y22_N16
\y[3]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Mux1~2_combout\,
	devoe => ww_devoe,
	o => \y[3]~output_o\);

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

-- Location: IOIBUF_X0_Y21_N22
\a[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(0),
	o => \a[0]~input_o\);

-- Location: LCCOMB_X1_Y21_N16
\Mux3~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Mux3~0_combout\ = (\a[1]~input_o\) # (\a[0]~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111110101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \a[1]~input_o\,
	datad => \a[0]~input_o\,
	combout => \Mux3~0_combout\);

-- Location: LCCOMB_X1_Y21_N2
\Mux1~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Mux1~0_combout\ = (!\a[1]~input_o\ & \a[0]~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101010100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \a[1]~input_o\,
	datad => \a[0]~input_o\,
	combout => \Mux1~0_combout\);

-- Location: LCCOMB_X1_Y21_N20
\Mux1~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \Mux1~1_combout\ = (\a[1]~input_o\ & !\a[0]~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \a[1]~input_o\,
	datad => \a[0]~input_o\,
	combout => \Mux1~1_combout\);

-- Location: LCCOMB_X1_Y21_N6
\Mux1~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \Mux1~2_combout\ = (\a[1]~input_o\ & \a[0]~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \a[1]~input_o\,
	datad => \a[0]~input_o\,
	combout => \Mux1~2_combout\);

ww_y(0) <= \y[0]~output_o\;

ww_y(1) <= \y[1]~output_o\;

ww_y(2) <= \y[2]~output_o\;

ww_y(3) <= \y[3]~output_o\;
END structure;


