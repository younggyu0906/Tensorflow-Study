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

-- DATE "03/14/2017 17:55:14"

-- 
-- Device: Altera EP2C70F672C8 Package FBGA672
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY CYCLONEII;
LIBRARY IEEE;
LIBRARY STD;
USE CYCLONEII.CYCLONEII_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;
USE STD.STANDARD.ALL;

ENTITY 	combosys IS
    PORT (
	in1 : IN std_logic;
	in2 : IN std_logic;
	in3 : IN std_logic;
	in4 : IN std_logic;
	o1 : OUT STD.STANDARD.bit;
	o2 : OUT STD.STANDARD.bit;
	o3 : OUT STD.STANDARD.bit
	);
END combosys;

-- Design Ports Information
-- o1	=>  Location: PIN_B14,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
-- o2	=>  Location: PIN_C12,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
-- o3	=>  Location: PIN_AE15,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
-- in1	=>  Location: PIN_C13,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- in2	=>  Location: PIN_D13,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- in3	=>  Location: PIN_D14,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- in4	=>  Location: PIN_AD15,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default


ARCHITECTURE structure OF combosys IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_in1 : std_logic;
SIGNAL ww_in2 : std_logic;
SIGNAL ww_in3 : std_logic;
SIGNAL ww_in4 : std_logic;
SIGNAL ww_o1 : std_logic;
SIGNAL ww_o2 : std_logic;
SIGNAL ww_o3 : std_logic;
SIGNAL \in1~combout\ : std_logic;
SIGNAL \in2~combout\ : std_logic;
SIGNAL \o1~0_combout\ : std_logic;
SIGNAL \in3~combout\ : std_logic;
SIGNAL \o2~0_combout\ : std_logic;
SIGNAL \in4~combout\ : std_logic;
SIGNAL \ALT_INV_in4~combout\ : std_logic;
SIGNAL \ALT_INV_o2~0_combout\ : std_logic;

BEGIN

ww_in1 <= in1;
ww_in2 <= in2;
ww_in3 <= in3;
ww_in4 <= in4;
o1 <= IEEE.STD_LOGIC_1164.TO_BIT(ww_o1);
o2 <= IEEE.STD_LOGIC_1164.TO_BIT(ww_o2);
o3 <= IEEE.STD_LOGIC_1164.TO_BIT(ww_o3);
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
\ALT_INV_in4~combout\ <= NOT \in4~combout\;
\ALT_INV_o2~0_combout\ <= NOT \o2~0_combout\;

-- Location: PIN_C13,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\in1~I\ : cycloneii_io
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
	padio => ww_in1,
	combout => \in1~combout\);

-- Location: PIN_D13,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\in2~I\ : cycloneii_io
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
	padio => ww_in2,
	combout => \in2~combout\);

-- Location: LCCOMB_X48_Y50_N0
\o1~0\ : cycloneii_lcell_comb
-- Equation(s):
-- \o1~0_combout\ = (\in1~combout\) # (\in2~combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110011111100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \in1~combout\,
	datac => \in2~combout\,
	combout => \o1~0_combout\);

-- Location: PIN_D14,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\in3~I\ : cycloneii_io
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
	padio => ww_in3,
	combout => \in3~combout\);

-- Location: LCCOMB_X48_Y50_N2
\o2~0\ : cycloneii_lcell_comb
-- Equation(s):
-- \o2~0_combout\ = (\in3~combout\ & \in2~combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010000010100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \in3~combout\,
	datac => \in2~combout\,
	combout => \o2~0_combout\);

-- Location: PIN_AD15,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\in4~I\ : cycloneii_io
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
	padio => ww_in4,
	combout => \in4~combout\);

-- Location: PIN_B14,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
\o1~I\ : cycloneii_io
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
	datain => \o1~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => VCC,
	padio => ww_o1);

-- Location: PIN_C12,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
\o2~I\ : cycloneii_io
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
	datain => \ALT_INV_o2~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => VCC,
	padio => ww_o2);

-- Location: PIN_AE15,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
\o3~I\ : cycloneii_io
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
	datain => \ALT_INV_in4~combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => VCC,
	padio => ww_o3);
END structure;


