onerror {quit -f}
vlib work
vlog -work work sys_var.vo
vlog -work work sys_var.vt
vsim -novopt -c -t 1ps -L cycloneii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.sys_var_vlg_vec_tst
vcd file -direction sys_var.msim.vcd
vcd add -internal sys_var_vlg_vec_tst/*
vcd add -internal sys_var_vlg_vec_tst/i1/*
add wave /*
run -all
