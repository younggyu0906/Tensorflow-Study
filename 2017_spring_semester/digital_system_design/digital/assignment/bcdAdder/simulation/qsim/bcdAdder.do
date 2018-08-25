onerror {quit -f}
vlib work
vlog -work work bcdAdder.vo
vlog -work work bcdAdder.vt
vsim -novopt -c -t 1ps -L cycloneive_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.bcdAdder_vlg_vec_tst
vcd file -direction bcdAdder.msim.vcd
vcd add -internal bcdAdder_vlg_vec_tst/*
vcd add -internal bcdAdder_vlg_vec_tst/i1/*
add wave /*
run -all
