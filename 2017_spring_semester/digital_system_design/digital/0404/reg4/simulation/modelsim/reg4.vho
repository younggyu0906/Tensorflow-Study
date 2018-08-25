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

-- DATE "04/12/2017 21:25:48"

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

ENTITY 	reg4 IS
    PORT (
	clk : IN std_logic;
	data_in : IN std_logic_vector(3 DOWNTO 0);
	reg_in : INOUT std_logic_vector(3 DOWNTO 0);
	reg_out : INOUT std_logic_vector(3 DOWNTO 0)
	);
END reg4;

-- Design Ports Information
-- reg_in[0]	=>  Location: PIN_A12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reg_in[1]	=>  Location: PIN_B12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reg_in[2]	=>  Location: PIN_A11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reg_in[3]	=>  Location: PIN_B11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reg_out[0]	=>  Location: PIN_F11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reg_out[1]	=>  Location: PIN_A15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reg_out[2]	=>  Location: PIN_A10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reg_out[3]	=>  Location: PIN_B10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- data_in[0]	=>  Location: PIN_N3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- data_in[1]	=>  Location: PIN_P3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- data_in[2]	=>  Location: PIN_R3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- data_in[3]	=>  Location: PIN_T3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- clk	=>  Location: PIN_R4,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF reg4 IS
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
SIGNAL ww_data_in : std_logic_vector(3 DOWNTO 0);
SIGNAL \reg_in[0]~input_o\ : std_logic;
SIGNAL \reg_in[1]~input_o\ : std_logic;
SIGNAL \reg_in[2]~input_o\ : std_logic;
SIGNAL \reg_in[3]~input_o\ : std_logic;
SIGNAL \reg_out[0]~input_o\ : std_logic;
SIGNAL \reg_out[1]~input_o\ : std_logic;
SIGNAL \reg_out[2]~input_o\ : std_logic;
SIGNAL \reg_out[3]~input_o\ : std_logic;
SIGNAL \reg_in[0]~output_o\ : std_logic;
SIGNAL \reg_in[1]~output_o\ : std_logic;
SIGNAL \reg_in[2]~output_o\ : std_logic;
SIGNAL \reg_in[3]~output_o\ : std_logic;
SIGNAL \reg_out[0]~output_o\ : std_logic;
SIGNAL \reg_out[1]~output_o\ : std_logic;
SIGNAL \reg_out[2]~output_o\ : std_logic;
SIGNAL \reg_out[3]~output_o\ : std_logic;
SIGNAL \data_in[0]~input_o\ : std_logic;
SIGNAL \data_in[1]~input_o\ : std_logic;
SIGNAL \data_in[2]~input_o\ : std_logic;
SIGNAL \data_in[3]~input_o\ : std_logic;
SIGNAL \clk~input_o\ : std_logic;
SIGNAL \reg_out[0]~reg0feeder_combout\ : std_logic;
SIGNAL \reg_out[0]~reg0_q\ : std_logic;
SIGNAL \reg_out[1]~reg0feeder_combout\ : std_logic;
SIGNAL \reg_out[1]~reg0_q\ : std_logic;
SIGNAL \reg_out[2]~reg0feeder_combout\ : std_logic;
SIGNAL \reg_out[2]~reg0_q\ : std_logic;
SIGNAL \reg_out[3]~reg0feeder_combout\ : std_logic;
SIGNAL \reg_out[3]~reg0_q\ : std_logic;

BEGIN

ww_clk <= clk;
ww_data_in <= data_in;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOOBUF_X25_Y24_N2
\reg_in[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \data_in[0]~input_o\,
	oe => VCC,
	devoe => ww_devoe,
	o => \reg_in[0]~output_o\);

-- Location: IOOBUF_X25_Y24_N9
\reg_in[1]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \data_in[1]~input_o\,
	oe => VCC,
	devoe => ww_devoe,
	o => \reg_in[1]~output_o\);

-- Location: IOOBUF_X25_Y24_N16
\reg_in[2]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \data_in[2]~input_o\,
	oe => VCC,
	devoe => ww_devoe,
	o => \reg_in[2]~output_o\);

-- Location: IOOBUF_X25_Y24_N23
\reg_in[3]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \data_in[3]~input_o\,
	oe => VCC,
	devoe => ww_devoe,
	o => \reg_in[3]~output_o\);

-- Location: IOOBUF_X23_Y24_N23
\reg_out[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \reg_out[0]~reg0_q\,
	oe => VCC,
	devoe => ww_devoe,
	o => \reg_out[0]~output_o\);

-- Location: IOOBUF_X21_Y24_N2
\reg_out[1]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \reg_out[1]~reg0_q\,
	oe => VCC,
	devoe => ww_devoe,
	o => \reg_out[1]~output_o\);

-- Location: IOOBUF_X21_Y24_N9
\reg_out[2]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \reg_out[2]~reg0_q\,
	oe => VCC,
	devoe => ww_devoe,
	o => \reg_out[2]~output_o\);

-- Location: IOOBUF_X21_Y24_N16
\reg_out[3]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \reg_out[3]~reg0_q\,
	oe => VCC,
	devoe => ww_devoe,
	o => \reg_out[3]~output_o\);

-- Location: IOIBUF_X1_Y0_N22
\data_in[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_data_in(0),
	o => \data_in[0]~input_o\);

-- Location: IOIBUF_X1_Y0_N15
\data_in[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_data_in(1),
	o => \data_in[1]~input_o\);

-- Location: IOIBUF_X1_Y0_N8
\data_in[2]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_data_in(2),
	o => \data_in[2]~input_o\);

-- Location: IOIBUF_X1_Y0_N1
\data_in[3]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_data_in(3),
	o => \data_in[3]~input_o\);

-- Location: IOIBUF_X5_Y0_N22
\clk~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_clk,
	o => \clk~input_o\);

-- Location: LCCOMB_X17_Y18_N24
\reg_out[0]~reg0feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \reg_out[0]~reg0feeder_combout\ = \data_in[0]~input_o\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \data_in[0]~input_o\,
	combout => \reg_out[0]~reg0feeder_combout\);

-- Location: FF_X17_Y18_N25
\reg_out[0]~reg0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~input_o\,
	d => \reg_out[0]~reg0feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \reg_out[0]~reg0_q\);

-- Location: LCCOMB_X17_Y18_N10
\reg_out[1]~reg0feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \reg_out[1]~reg0feeder_combout\ = \data_in[1]~input_o\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \data_in[1]~input_o\,
	combout => \reg_out[1]~reg0feeder_combout\);

-- Location: FF_X17_Y18_N11
\reg_out[1]~reg0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~input_o\,
	d => \reg_out[1]~reg0feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \reg_out[1]~reg0_q\);

-- Location: LCCOMB_X17_Y18_N12
\reg_out[2]~reg0feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \reg_out[2]~reg0feeder_combout\ = \data_in[2]~input_o\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \data_in[2]~input_o\,
	combout => \reg_out[2]~reg0feeder_combout\);

-- Location: FF_X17_Y18_N13
\reg_out[2]~reg0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~input_o\,
	d => \reg_out[2]~reg0feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \reg_out[2]~reg0_q\);

-- Location: LCCOMB_X17_Y18_N6
\reg_out[3]~reg0feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \reg_out[3]~reg0feeder_combout\ = \data_in[3]~input_o\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \data_in[3]~input_o\,
	combout => \reg_out[3]~reg0feeder_combout\);

-- Location: FF_X17_Y18_N7
\reg_out[3]~reg0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~input_o\,
	d => \reg_out[3]~reg0feeder_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \reg_out[3]~reg0_q\);

-- Location: IOIBUF_X25_Y24_N1
\reg_in[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => reg_in(0),
	o => \reg_in[0]~input_o\);

-- Location: IOIBUF_X25_Y24_N8
\reg_in[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => reg_in(1),
	o => \reg_in[1]~input_o\);

-- Location: IOIBUF_X25_Y24_N15
\reg_in[2]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => reg_in(2),
	o => \reg_in[2]~input_o\);

-- Location: IOIBUF_X25_Y24_N22
\reg_in[3]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => reg_in(3),
	o => \reg_in[3]~input_o\);

-- Location: IOIBUF_X23_Y24_N22
\reg_out[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => reg_out(0),
	o => \reg_out[0]~input_o\);

-- Location: IOIBUF_X21_Y24_N1
\reg_out[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => reg_out(1),
	o => \reg_out[1]~input_o\);

-- Location: IOIBUF_X21_Y24_N8
\reg_out[2]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => reg_out(2),
	o => \reg_out[2]~input_o\);

-- Location: IOIBUF_X21_Y24_N15
\reg_out[3]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => reg_out(3),
	o => \reg_out[3]~input_o\);

reg_in(0) <= \reg_in[0]~output_o\;

reg_in(1) <= \reg_in[1]~output_o\;

reg_in(2) <= \reg_in[2]~output_o\;

reg_in(3) <= \reg_in[3]~output_o\;

reg_out(0) <= \reg_out[0]~output_o\;

reg_out(1) <= \reg_out[1]~output_o\;

reg_out(2) <= \reg_out[2]~output_o\;

reg_out(3) <= \reg_out[3]~output_o\;
END structure;


