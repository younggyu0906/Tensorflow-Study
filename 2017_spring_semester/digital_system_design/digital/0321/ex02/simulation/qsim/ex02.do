onerror {quit -f}
vlib work
vlog -work work ex02.vo
vlog -work work ex02.vt
vsim -novopt -c -t 1ps -L cycloneii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.comp_vlg_vec_tst
vcd file -direction ex02.msim.vcd
vcd add -internal comp_vlg_vec_tst/*
vcd add -internal comp_vlg_vec_tst/i1/*
add wave /*
run -all
