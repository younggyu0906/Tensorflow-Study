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

-- DATE "05/19/2017 16:15:14"

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

ENTITY 	laundry IS
    PORT (
	clk : IN std_logic;
	l_start : IN std_logic;
	pollution : IN std_logic;
	waterSupply : OUT std_logic;
	spin : OUT std_logic;
	drainage : OUT std_logic
	);
END laundry;

-- Design Ports Information
-- waterSupply	=>  Location: PIN_D4,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- spin	=>  Location: PIN_F5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- drainage	=>  Location: PIN_D9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- clk	=>  Location: PIN_E1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- l_start	=>  Location: PIN_E5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- pollution	=>  Location: PIN_D3,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF laundry IS
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
SIGNAL ww_l_start : std_logic;
SIGNAL ww_pollution : std_logic;
SIGNAL ww_waterSupply : std_logic;
SIGNAL ww_spin : std_logic;
SIGNAL ww_drainage : std_logic;
SIGNAL \clk~inputclkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \p1:i[1]~q\ : std_logic;
SIGNAL \clk~input_o\ : std_logic;
SIGNAL \l_start~input_o\ : std_logic;
SIGNAL \clk~inputclkctrl_outclk\ : std_logic;
SIGNAL \waterSupply~output_o\ : std_logic;
SIGNAL \spin~output_o\ : std_logic;
SIGNAL \drainage~output_o\ : std_logic;
SIGNAL \pollution~input_o\ : std_logic;
SIGNAL \l_state~8_combout\ : std_logic;
SIGNAL \Add0~0_combout\ : std_logic;
SIGNAL \p1:i[0]~q\ : std_logic;
SIGNAL \Add0~1\ : std_logic;
SIGNAL \Add0~2_combout\ : std_logic;
SIGNAL \Equal0~0_combout\ : std_logic;
SIGNAL \l_state.l2~q\ : std_logic;
SIGNAL \l_state.l3~q\ : std_logic;
SIGNAL \Selector0~0_combout\ : std_logic;
SIGNAL \l_state.l0~q\ : std_logic;
SIGNAL \Selector1~0_combout\ : std_logic;
SIGNAL \l_state.l1~q\ : std_logic;
SIGNAL \w_state~11_combout\ : std_logic;
SIGNAL \w_state.w2~q\ : std_logic;
SIGNAL \w_state~13_combout\ : std_logic;
SIGNAL \w_state.w3~q\ : std_logic;
SIGNAL \w_state~12_combout\ : std_logic;
SIGNAL \w_state.w0~q\ : std_logic;
SIGNAL \w_state~10_combout\ : std_logic;
SIGNAL \w_state.w1~q\ : std_logic;
SIGNAL \waterSupply~0_combout\ : std_logic;
SIGNAL \spin~0_combout\ : std_logic;

BEGIN

ww_clk <= clk;
ww_l_start <= l_start;
ww_pollution <= pollution;
waterSupply <= ww_waterSupply;
spin <= ww_spin;
drainage <= ww_drainage;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

\clk~inputclkctrl_INCLK_bus\ <= (vcc & vcc & vcc & \clk~input_o\);

-- Location: FF_X1_Y23_N19
\p1:i[1]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \Add0~2_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \p1:i[1]~q\);

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

-- Location: IOIBUF_X0_Y23_N8
\l_start~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_l_start,
	o => \l_start~input_o\);

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

-- Location: IOOBUF_X0_Y23_N2
\waterSupply~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \waterSupply~0_combout\,
	devoe => ww_devoe,
	o => \waterSupply~output_o\);

-- Location: IOOBUF_X0_Y23_N16
\spin~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \spin~0_combout\,
	devoe => ww_devoe,
	o => \spin~output_o\);

-- Location: IOOBUF_X18_Y24_N16
\drainage~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => GND,
	devoe => ww_devoe,
	o => \drainage~output_o\);

-- Location: IOIBUF_X1_Y24_N8
\pollution~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_pollution,
	o => \pollution~input_o\);

-- Location: LCCOMB_X1_Y23_N26
\l_state~8\ : cycloneive_lcell_comb
-- Equation(s):
-- \l_state~8_combout\ = (\l_state.l1~q\ & !\pollution~input_o\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \l_state.l1~q\,
	datad => \pollution~input_o\,
	combout => \l_state~8_combout\);

-- Location: LCCOMB_X1_Y23_N16
\Add0~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Add0~0_combout\ = \p1:i[0]~q\ $ (VCC)
-- \Add0~1\ = CARRY(\p1:i[0]~q\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001111001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \p1:i[0]~q\,
	datad => VCC,
	combout => \Add0~0_combout\,
	cout => \Add0~1\);

-- Location: FF_X1_Y23_N17
\p1:i[0]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \Add0~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \p1:i[0]~q\);

-- Location: LCCOMB_X1_Y23_N18
\Add0~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \Add0~2_combout\ = \p1:i[1]~q\ $ (\Add0~1\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \p1:i[1]~q\,
	cin => \Add0~1\,
	combout => \Add0~2_combout\);

-- Location: LCCOMB_X1_Y23_N28
\Equal0~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Equal0~0_combout\ = (!\Add0~0_combout\ & !\Add0~2_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000001010101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \Add0~0_combout\,
	datad => \Add0~2_combout\,
	combout => \Equal0~0_combout\);

-- Location: FF_X1_Y23_N27
\l_state.l2\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \l_state~8_combout\,
	ena => \Equal0~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \l_state.l2~q\);

-- Location: FF_X1_Y23_N29
\l_state.l3\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	asdata => \l_state.l2~q\,
	sload => VCC,
	ena => \Equal0~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \l_state.l3~q\);

-- Location: LCCOMB_X1_Y23_N10
\Selector0~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Selector0~0_combout\ = (!\l_state.l3~q\ & ((\l_start~input_o\) # (\l_state.l0~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \l_start~input_o\,
	datac => \l_state.l0~q\,
	datad => \l_state.l3~q\,
	combout => \Selector0~0_combout\);

-- Location: FF_X1_Y23_N11
\l_state.l0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \Selector0~0_combout\,
	ena => \Equal0~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \l_state.l0~q\);

-- Location: LCCOMB_X1_Y23_N8
\Selector1~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Selector1~0_combout\ = (\l_start~input_o\ & (((\pollution~input_o\ & \l_state.l1~q\)) # (!\l_state.l0~q\))) # (!\l_start~input_o\ & (\pollution~input_o\ & (\l_state.l1~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100000011101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \l_start~input_o\,
	datab => \pollution~input_o\,
	datac => \l_state.l1~q\,
	datad => \l_state.l0~q\,
	combout => \Selector1~0_combout\);

-- Location: FF_X1_Y23_N9
\l_state.l1\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \Selector1~0_combout\,
	ena => \Equal0~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \l_state.l1~q\);

-- Location: LCCOMB_X1_Y23_N22
\w_state~11\ : cycloneive_lcell_comb
-- Equation(s):
-- \w_state~11_combout\ = (\l_state.l2~q\ & (((\w_state.w1~q\)))) # (!\l_state.l2~q\ & ((\l_state.l1~q\ & ((\w_state.w1~q\))) # (!\l_state.l1~q\ & (\w_state.w3~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110011001010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \w_state.w3~q\,
	datab => \w_state.w1~q\,
	datac => \l_state.l2~q\,
	datad => \l_state.l1~q\,
	combout => \w_state~11_combout\);

-- Location: FF_X1_Y23_N23
\w_state.w2\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \w_state~11_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \w_state.w2~q\);

-- Location: LCCOMB_X1_Y23_N6
\w_state~13\ : cycloneive_lcell_comb
-- Equation(s):
-- \w_state~13_combout\ = (\l_state.l2~q\ & (((\w_state.w2~q\)))) # (!\l_state.l2~q\ & ((\l_state.l1~q\ & ((\w_state.w2~q\))) # (!\l_state.l1~q\ & (!\w_state.w0~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000010110001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \l_state.l2~q\,
	datab => \w_state.w0~q\,
	datac => \w_state.w2~q\,
	datad => \l_state.l1~q\,
	combout => \w_state~13_combout\);

-- Location: FF_X1_Y23_N7
\w_state.w3\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \w_state~13_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \w_state.w3~q\);

-- Location: LCCOMB_X1_Y23_N14
\w_state~12\ : cycloneive_lcell_comb
-- Equation(s):
-- \w_state~12_combout\ = (\l_state.l2~q\ & (!\w_state.w3~q\)) # (!\l_state.l2~q\ & ((\w_state.w3~q\ & ((!\l_state.l1~q\))) # (!\w_state.w3~q\ & ((\l_state.l1~q\) # (!\w_state.w0~q\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001101100111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \l_state.l2~q\,
	datab => \w_state.w3~q\,
	datac => \w_state.w0~q\,
	datad => \l_state.l1~q\,
	combout => \w_state~12_combout\);

-- Location: FF_X1_Y23_N15
\w_state.w0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \w_state~12_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \w_state.w0~q\);

-- Location: LCCOMB_X1_Y23_N24
\w_state~10\ : cycloneive_lcell_comb
-- Equation(s):
-- \w_state~10_combout\ = (!\w_state.w0~q\ & ((\l_state.l2~q\) # (\l_state.l1~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \l_state.l2~q\,
	datac => \w_state.w0~q\,
	datad => \l_state.l1~q\,
	combout => \w_state~10_combout\);

-- Location: FF_X1_Y23_N25
\w_state.w1\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \clk~inputclkctrl_outclk\,
	d => \w_state~10_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \w_state.w1~q\);

-- Location: LCCOMB_X1_Y23_N20
\waterSupply~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \waterSupply~0_combout\ = (\l_state.l0~q\ & \w_state.w1~q\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \l_state.l0~q\,
	datad => \w_state.w1~q\,
	combout => \waterSupply~0_combout\);

-- Location: LCCOMB_X1_Y23_N12
\spin~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \spin~0_combout\ = (\l_state.l0~q\ & \w_state.w2~q\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010000010100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \l_state.l0~q\,
	datac => \w_state.w2~q\,
	combout => \spin~0_combout\);

ww_waterSupply <= \waterSupply~output_o\;

ww_spin <= \spin~output_o\;

ww_drainage <= \drainage~output_o\;
END structure;


