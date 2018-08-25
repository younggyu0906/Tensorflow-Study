onerror {quit -f}
vlib work
vlog -work work hw2logic.vo
vlog -work work hw2logic.vt
vsim -novopt -c -t 1ps -L cycloneive_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.hw2logic_vlg_vec_tst
vcd file -direction hw2logic.msim.vcd
vcd add -internal hw2logic_vlg_vec_tst/*
vcd add -internal hw2logic_vlg_vec_tst/i1/*
add wave /*
run -all
