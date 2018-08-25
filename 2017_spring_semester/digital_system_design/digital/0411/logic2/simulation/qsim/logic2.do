onerror {quit -f}
vlib work
vlog -work work logic2.vo
vlog -work work logic2.vt
vsim -novopt -c -t 1ps -L cycloneive_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.logic2_vlg_vec_tst
vcd file -direction logic2.msim.vcd
vcd add -internal logic2_vlg_vec_tst/*
vcd add -internal logic2_vlg_vec_tst/i1/*
add wave /*
run -all
