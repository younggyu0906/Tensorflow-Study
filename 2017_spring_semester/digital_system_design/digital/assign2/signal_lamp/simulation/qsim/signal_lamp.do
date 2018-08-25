onerror {quit -f}
vlib work
vlog -work work signal_lamp.vo
vlog -work work signal_lamp.vt
vsim -novopt -c -t 1ps -L cycloneive_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.signal_lamp_vlg_vec_tst
vcd file -direction signal_lamp.msim.vcd
vcd add -internal signal_lamp_vlg_vec_tst/*
vcd add -internal signal_lamp_vlg_vec_tst/i1/*
add wave /*
run -all
