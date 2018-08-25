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

-- DATE "04/16/2017 13:25:39"

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

ENTITY 	claDesign IS
    PORT (
	p : IN std_logic_vector(2 DOWNTO 0);
	g : IN std_logic_vector(2 DOWNTO 0);
	carryIn : IN std_logic;
	carry : OUT std_logic_vector(2 DOWNTO 0)
	);
END claDesign;

-- Design Ports Information
-- carry[0]	=>  Location: PIN_F2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- carry[1]	=>  Location: PIN_G5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- carry[2]	=>  Location: PIN_G2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- g[0]	=>  Location: PIN_F1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- p[0]	=>  Location: PIN_D16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- carryIn	=>  Location: PIN_G1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- g[1]	=>  Location: PIN_A10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- p[1]	=>  Location: PIN_D1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- g[2]	=>  Location: PIN_F3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- p[2]	=>  Location: PIN_L6,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF claDesign IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_p : std_logic_vector(2 DOWNTO 0);
SIGNAL ww_g : std_logic_vector(2 DOWNTO 0);
SIGNAL ww_carryIn : std_logic;
SIGNAL ww_carry : std_logic_vector(2 DOWNTO 0);
SIGNAL \carry[0]~output_o\ : std_logic;
SIGNAL \carry[1]~output_o\ : std_logic;
SIGNAL \carry[2]~output_o\ : std_logic;
SIGNAL \g[0]~input_o\ : std_logic;
SIGNAL \carryIn~input_o\ : std_logic;
SIGNAL \p[0]~input_o\ : std_logic;
SIGNAL \u9|o~combout\ : std_logic;
SIGNAL \p[1]~input_o\ : std_logic;
SIGNAL \g[1]~input_o\ : std_logic;
SIGNAL \u8|o~combout\ : std_logic;
SIGNAL \p[2]~input_o\ : std_logic;
SIGNAL \g[2]~input_o\ : std_logic;
SIGNAL \u7|o~combout\ : std_logic;

BEGIN

ww_p <= p;
ww_g <= g;
ww_carryIn <= carryIn;
carry <= ww_carry;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOOBUF_X0_Y19_N16
\carry[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u9|o~combout\,
	devoe => ww_devoe,
	o => \carry[0]~output_o\);

-- Location: IOOBUF_X0_Y19_N2
\carry[1]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u8|o~combout\,
	devoe => ww_devoe,
	o => \carry[1]~output_o\);

-- Location: IOOBUF_X0_Y18_N16
\carry[2]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u7|o~combout\,
	devoe => ww_devoe,
	o => \carry[2]~output_o\);

-- Location: IOIBUF_X0_Y19_N22
\g[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_g(0),
	o => \g[0]~input_o\);

-- Location: IOIBUF_X0_Y18_N22
\carryIn~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_carryIn,
	o => \carryIn~input_o\);

-- Location: IOIBUF_X34_Y19_N8
\p[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_p(0),
	o => \p[0]~input_o\);

-- Location: LCCOMB_X1_Y20_N24
\u9|o\ : cycloneive_lcell_comb
-- Equation(s):
-- \u9|o~combout\ = (\g[0]~input_o\) # ((\carryIn~input_o\ & \p[0]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111101010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \g[0]~input_o\,
	datac => \carryIn~input_o\,
	datad => \p[0]~input_o\,
	combout => \u9|o~combout\);

-- Location: IOIBUF_X0_Y21_N22
\p[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_p(1),
	o => \p[1]~input_o\);

-- Location: IOIBUF_X21_Y24_N8
\g[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_g(1),
	o => \g[1]~input_o\);

-- Location: LCCOMB_X1_Y20_N2
\u8|o\ : cycloneive_lcell_comb
-- Equation(s):
-- \u8|o~combout\ = (\g[1]~input_o\) # ((\u9|o~combout\ & \p[1]~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111111000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u9|o~combout\,
	datac => \p[1]~input_o\,
	datad => \g[1]~input_o\,
	combout => \u8|o~combout\);

-- Location: IOIBUF_X0_Y9_N8
\p[2]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_p(2),
	o => \p[2]~input_o\);

-- Location: IOIBUF_X0_Y21_N8
\g[2]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_g(2),
	o => \g[2]~input_o\);

-- Location: LCCOMB_X1_Y20_N4
\u7|o\ : cycloneive_lcell_comb
-- Equation(s):
-- \u7|o~combout\ = (\g[2]~input_o\) # ((\p[2]~input_o\ & \u8|o~combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110111011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \p[2]~input_o\,
	datab => \g[2]~input_o\,
	datad => \u8|o~combout\,
	combout => \u7|o~combout\);

ww_carry(0) <= \carry[0]~output_o\;

ww_carry(1) <= \carry[1]~output_o\;

ww_carry(2) <= \carry[2]~output_o\;
END structure;


