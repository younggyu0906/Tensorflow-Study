onerror {quit -f}
vlib work
vlog -work work full_adder.vo
vlog -work work full_adder.vt
vsim -novopt -c -t 1ps -L cycloneive_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.full_adder_vlg_vec_tst
vcd file -direction full_adder.msim.vcd
vcd add -internal full_adder_vlg_vec_tst/*
vcd add -internal full_adder_vlg_vec_tst/i1/*
add wave /*
run -all
