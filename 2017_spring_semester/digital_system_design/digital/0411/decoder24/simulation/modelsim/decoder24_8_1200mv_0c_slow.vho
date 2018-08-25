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

-- DATE "04/11/2017 17:05:24"

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

ENTITY 	decoder24 IS
    PORT (
	a : IN std_logic_vector(1 DOWNTO 0);
	y : OUT std_logic_vector(3 DOWNTO 0)
	);
END decoder24;

-- Design Ports Information
-- a[0]	=>  Location: PIN_R13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- a[1]	=>  Location: PIN_D1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y[0]	=>  Location: PIN_T12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y[1]	=>  Location: PIN_E5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y[2]	=>  Location: PIN_D14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- y[3]	=>  Location: PIN_A5,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF decoder24 IS
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
SIGNAL \a[0]~input_o\ : std_logic;
SIGNAL \a[1]~input_o\ : std_logic;
SIGNAL \y[0]~output_o\ : std_logic;
SIGNAL \y[1]~output_o\ : std_logic;
SIGNAL \y[2]~output_o\ : std_logic;
SIGNAL \y[3]~output_o\ : std_logic;

BEGIN

ww_a <= a;
y <= ww_y;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: IOOBUF_X25_Y0_N23
\y[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => VCC,
	devoe => ww_devoe,
	o => \y[0]~output_o\);

-- Location: IOOBUF_X0_Y23_N9
\y[1]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => VCC,
	devoe => ww_devoe,
	o => \y[1]~output_o\);

-- Location: IOOBUF_X32_Y24_N16
\y[2]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => VCC,
	devoe => ww_devoe,
	o => \y[2]~output_o\);

-- Location: IOOBUF_X7_Y24_N16
\y[3]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => VCC,
	devoe => ww_devoe,
	o => \y[3]~output_o\);

-- Location: IOIBUF_X28_Y0_N15
\a[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(0),
	o => \a[0]~input_o\);

-- Location: IOIBUF_X0_Y21_N22
\a[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_a(1),
	o => \a[1]~input_o\);

ww_y(0) <= \y[0]~output_o\;

ww_y(1) <= \y[1]~output_o\;

ww_y(2) <= \y[2]~output_o\;

ww_y(3) <= \y[3]~output_o\;
END structure;


