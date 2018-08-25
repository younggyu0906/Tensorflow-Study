onerror {quit -f}
vlib work
vlog -work work ringCount.vo
vlog -work work ringCount.vt
vsim -novopt -c -t 1ps -L cycloneive_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.ringCount_vlg_vec_tst
vcd file -direction ringCount.msim.vcd
vcd add -internal ringCount_vlg_vec_tst/*
vcd add -internal ringCount_vlg_vec_tst/i1/*
add wave /*
run -all
