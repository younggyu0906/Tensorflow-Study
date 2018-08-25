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

-- DATE "03/28/2017 16:26:06"

-- 
-- Device: Altera EP2C70F672C8 Package FBGA672
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY CYCLONEII;
LIBRARY IEEE;
USE CYCLONEII.CYCLONEII_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	full_adder IS
    PORT (
	a : IN std_logic;
	b : IN std_logic;
	c_in : IN std_logic;
	c_out : OUT std_logic;
	sum : OUT std_logic
	);
END full_adder;

-- Design Ports Information
-- c_out	=>  Location: PIN_B12,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
-- sum	=>  Location: PIN_B11,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
-- a	=>  Location: PIN_C13,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- c_in	=>  Location: PIN_D13,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- b	=>  Location: PIN_C12,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default


ARCHITECTURE structure OF full_adder IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_a : std_logic;
SIGNAL ww_b : std_logic;
SIGNAL ww_c_in : std_logic;
SIGNAL ww_c_out : std_logic;
SIGNAL ww_sum : std_logic;
SIGNAL \b~combout\ : std_logic;
SIGNAL \a~combout\ : std_logic;
SIGNAL \c_in~combout\ : std_logic;
SIGNAL \c_out~0_combout\ : std_logic;
SIGNAL \sum~0_combout\ : std_logic;

BEGIN

ww_a <= a;
ww_b <= b;
ww_c_in <= c_in;
c_out <= ww_c_out;
sum <= ww_sum;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: PIN_C12,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\b~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_b,
	combout => \b~combout\);

-- Location: PIN_C13,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\a~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_a,
	combout => \a~combout\);

-- Location: PIN_D13,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\c_in~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_c_in,
	combout => \c_in~combout\);

-- Location: LCCOMB_X44_Y50_N0
\c_out~0\ : cycloneii_lcell_comb
-- Equation(s):
-- \c_out~0_combout\ = (\b~combout\ & ((\a~combout\) # (\c_in~combout\))) # (!\b~combout\ & (\a~combout\ & \c_in~combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110011000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \b~combout\,
	datac => \a~combout\,
	datad => \c_in~combout\,
	combout => \c_out~0_combout\);

-- Location: LCCOMB_X44_Y50_N10
\sum~0\ : cycloneii_lcell_comb
-- Equation(s):
-- \sum~0_combout\ = \b~combout\ $ (\a~combout\ $ (\c_in~combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100111100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \b~combout\,
	datac => \a~combout\,
	datad => \c_in~combout\,
	combout => \sum~0_combout\);

-- Location: PIN_B12,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
\c_out~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "output",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	datain => \c_out~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => VCC,
	padio => ww_c_out);

-- Location: PIN_B11,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
\sum~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "output",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	datain => \sum~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => VCC,
	padio => ww_sum);
END structure;


