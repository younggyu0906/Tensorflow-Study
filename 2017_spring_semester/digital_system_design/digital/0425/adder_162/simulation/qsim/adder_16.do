onerror {quit -f}
vlib work
vlog -work work adder_16.vo
vlog -work work adder_16.vt
vsim -novopt -c -t 1ps -L cycloneive_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.adder_16_vlg_vec_tst
vcd file -direction adder_16.msim.vcd
vcd add -internal adder_16_vlg_vec_tst/*
vcd add -internal adder_16_vlg_vec_tst/i1/*
add wave /*
run -all
