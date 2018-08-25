onerror {quit -f}
vlib work
vlog -work work maxmin.vo
vlog -work work maxmin.vt
vsim -novopt -c -t 1ps -L cycloneive_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.kygmaxmin_vlg_vec_tst
vcd file -direction maxmin.msim.vcd
vcd add -internal kygmaxmin_vlg_vec_tst/*
vcd add -internal kygmaxmin_vlg_vec_tst/i1/*
add wave /*
run -all
