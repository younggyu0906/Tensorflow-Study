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

-- DATE "05/28/2017 04:54:20"

-- 
-- Device: Altera EP4CE6F17C8 Package FBGA256
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY ALTERA;
LIBRARY CYCLONEIVE;
LIBRARY IEEE;
USE ALTERA.ALTERA_PRIMITIVES_COMPONENTS.ALL;
USE CYCLONEIVE.CYCLONEIVE_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	jk_counter2 IS
    PORT (
	clk : IN std_logic;
	y_out : BUFFER std_logic_vector(3 DOWNTO 0)
	);
END jk_counter2;

-- Design Ports Information
-- y_out[0]	=>  Location: PIN_J13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y_out[1]	=>  Location: PIN_L4,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y_out[2]	=>  Location: PIN_K5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y_out[3]	=>  Location: PIN_R1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- clk	=>  Location: PIN_J12,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF jk_counter2 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_clk : std_logic;
SIGNAL ww_y_out : std_logic_vector(3 DOWNTO 0);
SIGNAL \u1|y_out~clkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \u1|y_out~0_combout\ : std_logic;
SIGNAL \y_out[0]~output_o\ : std_logic;
SIGNAL \y_out[1]~output_o\ : std_logic;
SIGNAL \y_out[2]~output_o\ : std_logic;
SIGNAL \y_out[3]~output_o\ : std_logic;
SIGNAL \clk~input_o\ : std_logic;
SIGNAL \u1|y_out~feeder_combout\ : std_logic;
SIGNAL \u1|y_out~q\ : std_logic;
SIGNAL \u1|y_out~clkctrl_outclk\ : std_logic;
SIGNAL \u3|y_out~0_combout\ : std_logic;
SIGNAL \u3|y_out~q\ : std_logic;
SIGNAL \u4|y_out~0_combout\ : std_logic;
SIGNAL \u4|y_out~q\ : std_logic;
SIGNAL \u2|y_out~0_combout\ : std_logic;
SIGNAL \u2|y_out~feeder_combout\ : std_logic;
SIGNAL \u2|y_out~q\ : std_logic;

BEGIN

ww_clk <= clk;
y_out <= ww_y_out;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

\u1|y_out~clkctrl_INCLK_bus\ <= (vcc & vcc & vcc & \u1|y_out~q\);

-- Location: LCCOMB_X33_Y11_N6
\u1|y_out~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u1|y_out~0_combout\ = !\u1|y_out~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001100110011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u1|y_out~q\,
	combout => \u1|y_out~0_combout\);

-- Location: IOOBUF_X34_Y11_N2
\y_out[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u1|y_out~q\,
	devoe => ww_devoe,
	o => \y_out[0]~output_o\);

-- Location: IOOBUF_X0_Y6_N23
\y_out[1]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u2|y_out~q\,
	devoe => ww_devoe,
	o => \y_out[1]~output_o\);

-- Location: IOOBUF_X0_Y6_N16
\y_out[2]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u3|y_out~q\,
	devoe => ww_devoe,
	o => \y_out[2]~output_o\);

-- Location: IOOBUF_X0_Y5_N23
\y_out[3]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u4|y_out~q\,
	devoe => ww_devoe,
	o => \y_out[3]~output_o\);

-- Location: IOIBUF_X34_Y11_N8
\clk~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_clk,
	o => \clk~input_o\);

-- Location: LCCOMB_X33_Y11_N10
\u1|y_out~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \u1|y_out~feeder_combout\ = \u1|y_out~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u1|y_out~0_combout\,
	combout => \u1|y_out~feeder_combout\);

-- Location: FF_X33_Y11_N11
\u1|y_out\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~input_o\,
	d => \u1|y_out~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u1|y_out~q\);

-- Location: CLKCTRL_G7
\u1|y_out~clkctrl\ : cycloneive_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	ena_register_mode => "none")
-- pragma translate_on
PORT MAP (
	inclk => \u1|y_out~clkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \u1|y_out~clkctrl_outclk\);

-- Location: LCCOMB_X1_Y6_N2
\u3|y_out~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u3|y_out~0_combout\ = !\u3|y_out~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \u3|y_out~q\,
	combout => \u3|y_out~0_combout\);

-- Location: FF_X1_Y6_N3
\u3|y_out\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \u2|y_out~q\,
	d => \u3|y_out~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u3|y_out~q\);

-- Location: LCCOMB_X1_Y6_N28
\u4|y_out~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u4|y_out~0_combout\ = (!\u4|y_out~q\ & ((!\u3|y_out~q\) # (!\u2|y_out~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000011100000111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|y_out~q\,
	datab => \u3|y_out~q\,
	datac => \u4|y_out~q\,
	combout => \u4|y_out~0_combout\);

-- Location: FF_X1_Y6_N29
\u4|y_out\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \u1|y_out~clkctrl_outclk\,
	d => \u4|y_out~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u4|y_out~q\);

-- Location: LCCOMB_X1_Y6_N0
\u2|y_out~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|y_out~0_combout\ = (!\u2|y_out~q\ & \u4|y_out~q\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \u2|y_out~q\,
	datad => \u4|y_out~q\,
	combout => \u2|y_out~0_combout\);

-- Location: LCCOMB_X1_Y6_N6
\u2|y_out~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|y_out~feeder_combout\ = \u2|y_out~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \u2|y_out~0_combout\,
	combout => \u2|y_out~feeder_combout\);

-- Location: FF_X1_Y6_N7
\u2|y_out\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \u1|y_out~clkctrl_outclk\,
	d => \u2|y_out~feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u2|y_out~q\);

ww_y_out(0) <= \y_out[0]~output_o\;

ww_y_out(1) <= \y_out[1]~output_o\;

ww_y_out(2) <= \y_out[2]~output_o\;

ww_y_out(3) <= \y_out[3]~output_o\;
END structure;


