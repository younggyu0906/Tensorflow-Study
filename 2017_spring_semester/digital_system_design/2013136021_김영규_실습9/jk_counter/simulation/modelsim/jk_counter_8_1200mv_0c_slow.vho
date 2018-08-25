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

-- DATE "05/16/2017 17:15:40"

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

ENTITY 	jk_counter IS
    PORT (
	clk : IN std_logic;
	reset : IN std_logic;
	x : IN std_logic;
	y_out : INOUT std_logic_vector(3 DOWNTO 0)
	);
END jk_counter;

-- Design Ports Information
-- clk	=>  Location: PIN_C8,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- reset	=>  Location: PIN_F15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- x	=>  Location: PIN_G5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y_out[0]	=>  Location: PIN_T13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y_out[1]	=>  Location: PIN_E5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y_out[2]	=>  Location: PIN_F5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y_out[3]	=>  Location: PIN_T12,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF jk_counter IS
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
SIGNAL ww_x : std_logic;
SIGNAL \clk~input_o\ : std_logic;
SIGNAL \reset~input_o\ : std_logic;
SIGNAL \x~input_o\ : std_logic;
SIGNAL \y_out[0]~input_o\ : std_logic;
SIGNAL \y_out[1]~input_o\ : std_logic;
SIGNAL \y_out[2]~input_o\ : std_logic;
SIGNAL \y_out[3]~input_o\ : std_logic;
SIGNAL \y_out[0]~output_o\ : std_logic;
SIGNAL \y_out[1]~output_o\ : std_logic;
SIGNAL \y_out[2]~output_o\ : std_logic;
SIGNAL \y_out[3]~output_o\ : std_logic;

BEGIN

ww_clk <= clk;
ww_reset <= reset;
ww_x <= x;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOOBUF_X28_Y0_N9
\y_out[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => VCC,
	oe => VCC,
	devoe => ww_devoe,
	o => \y_out[0]~output_o\);

-- Location: IOOBUF_X0_Y23_N9
\y_out[1]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => VCC,
	oe => VCC,
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
	i => VCC,
	oe => VCC,
	devoe => ww_devoe,
	o => \y_out[2]~output_o\);

-- Location: IOOBUF_X25_Y0_N23
\y_out[3]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => VCC,
	oe => VCC,
	devoe => ww_devoe,
	o => \y_out[3]~output_o\);

-- Location: IOIBUF_X13_Y24_N1
\clk~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_clk,
	o => \clk~input_o\);

-- Location: IOIBUF_X34_Y18_N15
\reset~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_reset,
	o => \reset~input_o\);

-- Location: IOIBUF_X0_Y19_N1
\x~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_x,
	o => \x~input_o\);

-- Location: IOIBUF_X28_Y0_N8
\y_out[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => y_out(0),
	o => \y_out[0]~input_o\);

-- Location: IOIBUF_X0_Y23_N8
\y_out[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => y_out(1),
	o => \y_out[1]~input_o\);

-- Location: IOIBUF_X0_Y23_N15
\y_out[2]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => y_out(2),
	o => \y_out[2]~input_o\);

-- Location: IOIBUF_X25_Y0_N22
\y_out[3]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => y_out(3),
	o => \y_out[3]~input_o\);

y_out(0) <= \y_out[0]~output_o\;

y_out(1) <= \y_out[1]~output_o\;

y_out(2) <= \y_out[2]~output_o\;

y_out(3) <= \y_out[3]~output_o\;
END structure;


