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

-- DATE "05/16/2017 16:12:51"

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

ENTITY 	ringCount IS
    PORT (
	clk : IN std_logic;
	reset : IN std_logic;
	count : BUFFER std_logic_vector(7 DOWNTO 0)
	);
END ringCount;

-- Design Ports Information
-- count[0]	=>  Location: PIN_T3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- count[1]	=>  Location: PIN_K5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- count[2]	=>  Location: PIN_L4,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- count[3]	=>  Location: PIN_N3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- count[4]	=>  Location: PIN_P3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- count[5]	=>  Location: PIN_P2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- count[6]	=>  Location: PIN_P1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- count[7]	=>  Location: PIN_R1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- clk	=>  Location: PIN_E1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reset	=>  Location: PIN_M2,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF ringCount IS
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
SIGNAL ww_reset : std_logic;
SIGNAL ww_count : std_logic_vector(7 DOWNTO 0);
SIGNAL \reset~inputclkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \clk~inputclkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \count[0]~output_o\ : std_logic;
SIGNAL \count[1]~output_o\ : std_logic;
SIGNAL \count[2]~output_o\ : std_logic;
SIGNAL \count[3]~output_o\ : std_logic;
SIGNAL \count[4]~output_o\ : std_logic;
SIGNAL \count[5]~output_o\ : std_logic;
SIGNAL \count[6]~output_o\ : std_logic;
SIGNAL \count[7]~output_o\ : std_logic;
SIGNAL \clk~input_o\ : std_logic;
SIGNAL \clk~inputclkctrl_outclk\ : std_logic;
SIGNAL \count[1]~1_combout\ : std_logic;
SIGNAL \reset~input_o\ : std_logic;
SIGNAL \reset~inputclkctrl_outclk\ : std_logic;
SIGNAL \count[1]~reg0_q\ : std_logic;
SIGNAL \count[2]~reg0feeder_combout\ : std_logic;
SIGNAL \count[2]~reg0_q\ : std_logic;
SIGNAL \count[3]~reg0feeder_combout\ : std_logic;
SIGNAL \count[3]~reg0_q\ : std_logic;
SIGNAL \count[4]~reg0feeder_combout\ : std_logic;
SIGNAL \count[4]~reg0_q\ : std_logic;
SIGNAL \count[5]~reg0feeder_combout\ : std_logic;
SIGNAL \count[5]~reg0_q\ : std_logic;
SIGNAL \count[6]~reg0feeder_combout\ : std_logic;
SIGNAL \count[6]~reg0_q\ : std_logic;
SIGNAL \count[7]~reg0feeder_combout\ : std_logic;
SIGNAL \count[7]~reg0_q\ : std_logic;
SIGNAL \count[0]~0_combout\ : std_logic;
SIGNAL \count[0]~reg0_q\ : std_logic;
SIGNAL \ALT_INV_reset~inputclkctrl_outclk\ : std_logic;
SIGNAL \ALT_INV_count[0]~reg0_q\ : std_logic;

BEGIN

ww_clk <= clk;
ww_reset <= reset;
count <= ww_count;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

\reset~inputclkctrl_INCLK_bus\ <= (vcc & vcc & vcc & \reset~input_o\);

\clk~inputclkctrl_INCLK_bus\ <= (vcc & vcc & vcc & \clk~input_o\);
\ALT_INV_reset~inputclkctrl_outclk\ <= NOT \reset~inputclkctrl_outclk\;
\ALT_INV_count[0]~reg0_q\ <= NOT \count[0]~reg0_q\;

-- Location: IOOBUF_X1_Y0_N2
\count[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \ALT_INV_count[0]~reg0_q\,
	devoe => ww_devoe,
	o => \count[0]~output_o\);

-- Location: IOOBUF_X0_Y6_N16
\count[1]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \count[1]~reg0_q\,
	devoe => ww_devoe,
	o => \count[1]~output_o\);

-- Location: IOOBUF_X0_Y6_N23
\count[2]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \count[2]~reg0_q\,
	devoe => ww_devoe,
	o => \count[2]~output_o\);

-- Location: IOOBUF_X1_Y0_N23
\count[3]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \count[3]~reg0_q\,
	devoe => ww_devoe,
	o => \count[3]~output_o\);

-- Location: IOOBUF_X1_Y0_N16
\count[4]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \count[4]~reg0_q\,
	devoe => ww_devoe,
	o => \count[4]~output_o\);

-- Location: IOOBUF_X0_Y4_N16
\count[5]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \count[5]~reg0_q\,
	devoe => ww_devoe,
	o => \count[5]~output_o\);

-- Location: IOOBUF_X0_Y4_N23
\count[6]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \count[6]~reg0_q\,
	devoe => ww_devoe,
	o => \count[6]~output_o\);

-- Location: IOOBUF_X0_Y5_N23
\count[7]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \count[7]~reg0_q\,
	devoe => ww_devoe,
	o => \count[7]~output_o\);

-- Location: IOIBUF_X0_Y11_N8
\clk~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_clk,
	o => \clk~input_o\);

-- Location: CLKCTRL_G2
\clk~inputclkctrl\ : cycloneive_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	ena_register_mode => "none")
-- pragma translate_on
PORT MAP (
	inclk => \clk~inputclkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \clk~inputclkctrl_outclk\);

-- Location: LCCOMB_X1_Y4_N18
\count[1]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \count[1]~1_combout\ = !\count[0]~reg0_q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \count[0]~reg0_q\,
	combout => \count[1]~1_combout\);

-- Location: IOIBUF_X0_Y11_N15
\reset~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_reset,
	o => \reset~input_o\);

-- Location: CLKCTRL_G4
\reset~inputclkctrl\ : cycloneive_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	ena_register_mode => "none")
-- pragma translate_on
PORT MAP (
	inclk => \reset~inputclkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \reset~inputclkctrl_outclk\);

-- Location: FF_X1_Y4_N19
\count[1]~reg0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \count[1]~1_combout\,
	clrn => \ALT_INV_reset~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \count[1]~reg0_q\);

-- Location: LCCOMB_X1_Y4_N12
\count[2]~reg0feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \count[2]~reg0feeder_combout\ = \count[1]~reg0_q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \count[1]~reg0_q\,
	combout => \count[2]~reg0feeder_combout\);

-- Location: FF_X1_Y4_N13
\count[2]~reg0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \count[2]~reg0feeder_combout\,
	clrn => \ALT_INV_reset~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \count[2]~reg0_q\);

-- Location: LCCOMB_X1_Y4_N2
\count[3]~reg0feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \count[3]~reg0feeder_combout\ = \count[2]~reg0_q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \count[2]~reg0_q\,
	combout => \count[3]~reg0feeder_combout\);

-- Location: FF_X1_Y4_N3
\count[3]~reg0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \count[3]~reg0feeder_combout\,
	clrn => \ALT_INV_reset~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \count[3]~reg0_q\);

-- Location: LCCOMB_X1_Y4_N24
\count[4]~reg0feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \count[4]~reg0feeder_combout\ = \count[3]~reg0_q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \count[3]~reg0_q\,
	combout => \count[4]~reg0feeder_combout\);

-- Location: FF_X1_Y4_N25
\count[4]~reg0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \count[4]~reg0feeder_combout\,
	clrn => \ALT_INV_reset~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \count[4]~reg0_q\);

-- Location: LCCOMB_X1_Y4_N6
\count[5]~reg0feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \count[5]~reg0feeder_combout\ = \count[4]~reg0_q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \count[4]~reg0_q\,
	combout => \count[5]~reg0feeder_combout\);

-- Location: FF_X1_Y4_N7
\count[5]~reg0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \count[5]~reg0feeder_combout\,
	clrn => \ALT_INV_reset~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \count[5]~reg0_q\);

-- Location: LCCOMB_X1_Y4_N16
\count[6]~reg0feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \count[6]~reg0feeder_combout\ = \count[5]~reg0_q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \count[5]~reg0_q\,
	combout => \count[6]~reg0feeder_combout\);

-- Location: FF_X1_Y4_N17
\count[6]~reg0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \count[6]~reg0feeder_combout\,
	clrn => \ALT_INV_reset~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \count[6]~reg0_q\);

-- Location: LCCOMB_X1_Y4_N10
\count[7]~reg0feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \count[7]~reg0feeder_combout\ = \count[6]~reg0_q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \count[6]~reg0_q\,
	combout => \count[7]~reg0feeder_combout\);

-- Location: FF_X1_Y4_N11
\count[7]~reg0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \count[7]~reg0feeder_combout\,
	clrn => \ALT_INV_reset~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \count[7]~reg0_q\);

-- Location: LCCOMB_X1_Y4_N0
\count[0]~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \count[0]~0_combout\ = !\count[7]~reg0_q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \count[7]~reg0_q\,
	combout => \count[0]~0_combout\);

-- Location: FF_X1_Y4_N1
\count[0]~reg0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \count[0]~0_combout\,
	clrn => \ALT_INV_reset~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \count[0]~reg0_q\);

ww_count(0) <= \count[0]~output_o\;

ww_count(1) <= \count[1]~output_o\;

ww_count(2) <= \count[2]~output_o\;

ww_count(3) <= \count[3]~output_o\;

ww_count(4) <= \count[4]~output_o\;

ww_count(5) <= \count[5]~output_o\;

ww_count(6) <= \count[6]~output_o\;

ww_count(7) <= \count[7]~output_o\;
END structure;


