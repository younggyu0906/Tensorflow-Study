onerror {quit -f}
vlib work
vlog -work work nor_sys.vo
vlog -work work nor_sys.vt
vsim -novopt -c -t 1ps -L cycloneive_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.nor_sys_vlg_vec_tst
vcd file -direction nor_sys.msim.vcd
vcd add -internal nor_sys_vlg_vec_tst/*
vcd add -internal nor_sys_vlg_vec_tst/i1/*
add wave /*
run -all
