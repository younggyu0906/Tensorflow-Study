onerror {quit -f}
vlib work
vlog -work work hw01.vo
vlog -work work hw01.vt
vsim -novopt -c -t 1ps -L cycloneii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.hw01_vlg_vec_tst
vcd file -direction hw01.msim.vcd
vcd add -internal hw01_vlg_vec_tst/*
vcd add -internal hw01_vlg_vec_tst/i1/*
add wave /*
run -all
