onerror {quit -f}
vlib work
vlog -work work hw02.vo
vlog -work work hw02.vt
vsim -novopt -c -t 1ps -L cycloneii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.hw02_vlg_vec_tst
vcd file -direction hw02.msim.vcd
vcd add -internal hw02_vlg_vec_tst/*
vcd add -internal hw02_vlg_vec_tst/i1/*
add wave /*
run -all
