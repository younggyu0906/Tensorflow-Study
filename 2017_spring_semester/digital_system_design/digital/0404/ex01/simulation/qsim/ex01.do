onerror {quit -f}
vlib work
vlog -work work ex01.vo
vlog -work work ex01.vt
vsim -novopt -c -t 1ps -L cycloneive_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.logic_vlg_vec_tst
vcd file -direction ex01.msim.vcd
vcd add -internal logic_vlg_vec_tst/*
vcd add -internal logic_vlg_vec_tst/i1/*
add wave /*
run -all
