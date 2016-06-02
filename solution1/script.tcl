############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
############################################################
open_project VCNN
set_top neural_net
add_files VCNN/src/lib/layers/Softmax.cpp
add_files VCNN/src/VCNN.h
add_files VCNN/src/custom/caffe_model_layer.cpp
add_files VCNN/src/custom/caffe_model_layer.h
add_files VCNN/src/lib/layers/convolution.cpp
add_files VCNN/src/custom/custom.cpp
add_files VCNN/src/custom/custom.h
add_files VCNN/src/lib/layers/inner_product.cpp
add_files VCNN/src/lib/layers/layers.h
add_files VCNN/src/lib/main.cpp
add_files VCNN/src/lib/layers/pooling.cpp
add_files VCNN/src/lib/layers/relu.cpp
add_files VCNN/src/lib/layers/return_callback.cpp
add_files VCNN/src/lib/util.h
add_files -tb VCNN/src/custom/mnist/mnist_data.h
add_files -tb VCNN/src/custom/test.cpp
open_solution "solution1"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default
set_clock_uncertainty 2
#source "./VCNN/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
