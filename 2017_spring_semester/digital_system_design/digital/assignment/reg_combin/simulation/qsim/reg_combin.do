onerror {quit -f}
vlib work
vlog -work work reg_combin.vo
vlog -work work reg_combin.vt
vsim -novopt -c -t 1ps -L cycloneive_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.reg_combin_vlg_vec_tst
vcd file -direction reg_combin.msim.vcd
vcd add -internal reg_combin_vlg_vec_tst/*
vcd add -internal reg_combin_vlg_vec_tst/i1/*
add wave /*
run -all
