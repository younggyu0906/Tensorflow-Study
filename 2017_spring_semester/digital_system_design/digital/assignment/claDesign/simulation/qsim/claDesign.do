onerror {quit -f}
vlib work
vlog -work work claDesign.vo
vlog -work work claDesign.vt
vsim -novopt -c -t 1ps -L cycloneive_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.claDesign_vlg_vec_tst
vcd file -direction claDesign.msim.vcd
vcd add -internal claDesign_vlg_vec_tst/*
vcd add -internal claDesign_vlg_vec_tst/i1/*
add wave /*
run -all
