#1 "VCNN/src/lib/layers/relu.cpp"
#1 "VCNN/src/lib/layers/relu.cpp" 1
#1 "<built-in>" 1
#1 "<built-in>" 3
#155 "<built-in>" 3
#1 "<command line>" 1




#1 "/opt/Xilinx/Vivado_HLS/2016.1/common/technology/autopilot/etc/autopilot_ssdm_op.h" 1
/* autopilot_ssdm_op.h*/
/*
#-  (c) Copyright 2011-2016 Xilinx, Inc. All rights reserved.
#-
#-  This file contains confidential and proprietary information
#-  of Xilinx, Inc. and is protected under U.S. and
#-  international copyright and other intellectual property
#-  laws.
#-
#-  DISCLAIMER
#-  This disclaimer is not a license and does not grant any
#-  rights to the materials distributed herewith. Except as
#-  otherwise provided in a valid license issued to you by
#-  Xilinx, and to the maximum extent permitted by applicable
#-  law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
#-  WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
#-  AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
#-  BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
#-  INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
#-  (2) Xilinx shall not be liable (whether in contract or tort,
#-  including negligence, or under any other theory of
#-  liability) for any loss or damage of any kind or nature
#-  related to, arising under or in connection with these
#-  materials, including for any direct, or any indirect,
#-  special, incidental, or consequential loss or damage
#-  (including loss of data, profits, goodwill, or any type of
#-  loss or damage suffered as a result of any action brought
#-  by a third party) even if such damage or loss was
#-  reasonably foreseeable or Xilinx had been advised of the
#-  possibility of the same.
#-
#-  CRITICAL APPLICATIONS
#-  Xilinx products are not designed or intended to be fail-
#-  safe, or for use in any application requiring fail-safe
#-  performance, such as life-support or safety devices or
#-  systems, Class III medical devices, nuclear facilities,
#-  applications related to the deployment of airbags, or any
#-  other applications that could lead to death, personal
#-  injury, or severe property or environmental damage
#-  (individually and collectively, "Critical
#-  Applications"). Customer assumes the sole risk and
#-  liability of any use of Xilinx products in Critical
#-  Applications, subject only to applicable laws and
#-  regulations governing limitations on product liability.
#-
#-  THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
#-  PART OF THIS FILE AT ALL TIMES. 
#- ************************************************************************

 *
 * $Id$
 */
#145 "/opt/Xilinx/Vivado_HLS/2016.1/common/technology/autopilot/etc/autopilot_ssdm_op.h"
/*#define AP_SPEC_ATTR __attribute__ ((pure))*/




extern "C" {

    /****** SSDM Intrinsics: OPERATIONS ***/
    // Interface operations

    //typedef unsigned int __attribute__ ((bitwidth(1))) _uint1_;
    typedef bool _uint1_;

    void _ssdm_op_IfRead(...) __attribute__ ((nothrow));
    void _ssdm_op_IfWrite(...) __attribute__ ((nothrow));
    _uint1_ _ssdm_op_IfNbRead(...) __attribute__ ((nothrow));
    _uint1_ _ssdm_op_IfNbWrite(...) __attribute__ ((nothrow));
    _uint1_ _ssdm_op_IfCanRead(...) __attribute__ ((nothrow));
    _uint1_ _ssdm_op_IfCanWrite(...) __attribute__ ((nothrow));

    // Stream Intrinsics
    void _ssdm_StreamRead(...) __attribute__ ((nothrow));
    void _ssdm_StreamWrite(...) __attribute__ ((nothrow));
    _uint1_ _ssdm_StreamNbRead(...) __attribute__ ((nothrow));
    _uint1_ _ssdm_StreamNbWrite(...) __attribute__ ((nothrow));
    _uint1_ _ssdm_StreamCanRead(...) __attribute__ ((nothrow));
    _uint1_ _ssdm_StreamCanWrite(...) __attribute__ ((nothrow));
    unsigned _ssdm_StreamSize(...) __attribute__ ((nothrow));

    // Misc
    void _ssdm_op_MemShiftRead(...) __attribute__ ((nothrow));

    void _ssdm_op_Wait(...) __attribute__ ((nothrow));
    void _ssdm_op_Poll(...) __attribute__ ((nothrow));

    void _ssdm_op_Return(...) __attribute__ ((nothrow));

    /* SSDM Intrinsics: SPECIFICATIONS */
    void _ssdm_op_SpecSynModule(...) __attribute__ ((nothrow));
    void _ssdm_op_SpecTopModule(...) __attribute__ ((nothrow));
    void _ssdm_op_SpecProcessDecl(...) __attribute__ ((nothrow));
    void _ssdm_op_SpecProcessDef(...) __attribute__ ((nothrow));
    void _ssdm_op_SpecPort(...) __attribute__ ((nothrow));
    void _ssdm_op_SpecConnection(...) __attribute__ ((nothrow));
    void _ssdm_op_SpecChannel(...) __attribute__ ((nothrow));
    void _ssdm_op_SpecSensitive(...) __attribute__ ((nothrow));
    void _ssdm_op_SpecModuleInst(...) __attribute__ ((nothrow));
    void _ssdm_op_SpecPortMap(...) __attribute__ ((nothrow));

    void _ssdm_op_SpecReset(...) __attribute__ ((nothrow));

    void _ssdm_op_SpecPlatform(...) __attribute__ ((nothrow));
    void _ssdm_op_SpecClockDomain(...) __attribute__ ((nothrow));
    void _ssdm_op_SpecPowerDomain(...) __attribute__ ((nothrow));

    int _ssdm_op_SpecRegionBegin(...) __attribute__ ((nothrow));
    int _ssdm_op_SpecRegionEnd(...) __attribute__ ((nothrow));

    void _ssdm_op_SpecLoopName(...) __attribute__ ((nothrow));

    void _ssdm_op_SpecLoopTripCount(...) __attribute__ ((nothrow));

    int _ssdm_op_SpecStateBegin(...) __attribute__ ((nothrow));
    int _ssdm_op_SpecStateEnd(...) __attribute__ ((nothrow));

    void _ssdm_op_SpecInterface(...) __attribute__ ((nothrow));

    void _ssdm_op_SpecPipeline(...) __attribute__ ((nothrow));
    void _ssdm_op_SpecDataflowPipeline(...) __attribute__ ((nothrow));


    void _ssdm_op_SpecLatency(...) __attribute__ ((nothrow));
    void _ssdm_op_SpecParallel(...) __attribute__ ((nothrow));
    void _ssdm_op_SpecProtocol(...) __attribute__ ((nothrow));
    void _ssdm_op_SpecOccurrence(...) __attribute__ ((nothrow));

    void _ssdm_op_SpecResource(...) __attribute__ ((nothrow));
    void _ssdm_op_SpecResourceLimit(...) __attribute__ ((nothrow));
    void _ssdm_op_SpecCHCore(...) __attribute__ ((nothrow));
    void _ssdm_op_SpecFUCore(...) __attribute__ ((nothrow));
    void _ssdm_op_SpecIFCore(...) __attribute__ ((nothrow));
    void _ssdm_op_SpecIPCore(...) __attribute__ ((nothrow));
    void _ssdm_op_SpecKeepValue(...) __attribute__ ((nothrow));
    void _ssdm_op_SpecMemCore(...) __attribute__ ((nothrow));

    void _ssdm_op_SpecExt(...) __attribute__ ((nothrow));
    /*void* _ssdm_op_SpecProcess(...) SSDM_SPEC_ATTR;
    void* _ssdm_op_SpecEdge(...) SSDM_SPEC_ATTR; */

    /* Presynthesis directive functions */
    void _ssdm_SpecArrayDimSize(...) __attribute__ ((nothrow));

    void _ssdm_RegionBegin(...) __attribute__ ((nothrow));
    void _ssdm_RegionEnd(...) __attribute__ ((nothrow));

    void _ssdm_Unroll(...) __attribute__ ((nothrow));
    void _ssdm_UnrollRegion(...) __attribute__ ((nothrow));

    void _ssdm_InlineAll(...) __attribute__ ((nothrow));
    void _ssdm_InlineLoop(...) __attribute__ ((nothrow));
    void _ssdm_Inline(...) __attribute__ ((nothrow));
    void _ssdm_InlineSelf(...) __attribute__ ((nothrow));
    void _ssdm_InlineRegion(...) __attribute__ ((nothrow));

    void _ssdm_SpecArrayMap(...) __attribute__ ((nothrow));
    void _ssdm_SpecArrayPartition(...) __attribute__ ((nothrow));
    void _ssdm_SpecArrayReshape(...) __attribute__ ((nothrow));

    void _ssdm_SpecStream(...) __attribute__ ((nothrow));

    void _ssdm_SpecExpr(...) __attribute__ ((nothrow));
    void _ssdm_SpecExprBalance(...) __attribute__ ((nothrow));

    void _ssdm_SpecDependence(...) __attribute__ ((nothrow));

    void _ssdm_SpecLoopMerge(...) __attribute__ ((nothrow));
    void _ssdm_SpecLoopFlatten(...) __attribute__ ((nothrow));
    void _ssdm_SpecLoopRewind(...) __attribute__ ((nothrow));

    void _ssdm_SpecFuncInstantiation(...) __attribute__ ((nothrow));
    void _ssdm_SpecFuncBuffer(...) __attribute__ ((nothrow));
    void _ssdm_SpecFuncExtract(...) __attribute__ ((nothrow));
    void _ssdm_SpecConstant(...) __attribute__ ((nothrow));

    void _ssdm_DataPack(...) __attribute__ ((nothrow));
    void _ssdm_SpecDataPack(...) __attribute__ ((nothrow));

    void _ssdm_op_SpecBitsMap(...) __attribute__ ((nothrow));
    void _ssdm_op_SpecLicense(...) __attribute__ ((nothrow));

    void __xilinx_ip_top(...) __attribute__ ((nothrow));


}
#407 "/opt/Xilinx/Vivado_HLS/2016.1/common/technology/autopilot/etc/autopilot_ssdm_op.h"
/*#define _ssdm_op_WaitUntil(X) while (!(X)) _ssdm_op_Wait(1);
#define _ssdm_op_Delayed(X) X */
#421 "/opt/Xilinx/Vivado_HLS/2016.1/common/technology/autopilot/etc/autopilot_ssdm_op.h"
// XSIP watermark, do not delete 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#6 "<command line>" 2
#1 "<built-in>" 2
#1 "VCNN/src/lib/layers/relu.cpp" 2
#1 "VCNN/src/lib/layers/layers.h" 1



#1 "VCNN/src/lib/layers/../../custom/caffe_model_layer.h" 1


static int const nLayers = 9;
static float const dataScale= 0.00390625;
static int const nOutput = 10;
typedef enum {CONVOLUTION,POOLING_AVG,POOLING_MAX,RELU,INNERPRODUCT,SOFTMAX,RETURN_CALLBACK} LayerType;

typedef struct {
    int id;
    LayerType type;
    /*
     # Meta Data
    All meta data for every type of layer are put here, for easy initialization. HLS C don't allow dynamic memory operation.
    Hopefully the complier will optimize the unused variable for us.(It should be able to.)
    */
    /* for convolutional layer
     the conv layer here won't take care about padding, since we gonna use pixel streaming,
     FPGA is best for streaming processing, fast and efficient*/

    int conv_filter_channels;
    int conv_filter_size;
    int conv_filter_num;
    int conv_stride;
    int conv_pad;

    /*for pooling layer*/
    int pl_kernel_size;
    int pl_stride;

    /*for inner product layer*/
    int ip_channel_num;
    int ip_output_num;


    int input_channel_num;
    int input_feature_map_height;
    int input_feature_map_width;

    float* input_data;
} Layer;






typedef struct {

  int id;
  //for convolutional layer
  float *conv_filter_weight; // 32->3->5x5
  float *conv_bias; //1x32

  /*for inner product layer*/
  float *ip_weight;
  float *ip_bias;

} LayerWeight;


static int const nChannels = 1;
static int const imgWidth = 28;
static int const imgHeight = 28;
static int const nLayerTypes = 7;
extern float mean_image[1][28][28];




extern LayerWeight layers_weight[9];
extern Layer layers[10];
#5 "VCNN/src/lib/layers/layers.h" 2

using namespace std;



typedef void (*Layer_f) (Layer current, LayerWeight cw, Layer next);

//you must take layer weight as input parameter, because they
//may in the external memory
void Convolution(Layer current, LayerWeight cw, Layer next);
void PoolingAvg(Layer current, LayerWeight cw, Layer next);
void PoolingMax(Layer current, LayerWeight cw, Layer next);
void Relu(Layer current, LayerWeight cw, Layer next);
void InnerProduct(Layer current, LayerWeight cw, Layer next);
void Softmax(Layer current, LayerWeight cw, Layer next);
void ReturnCallback(Layer current, LayerWeight cw, Layer next);

//you don't need mean image here, just substract them in the main
// function
static Layer_f layer_dict[nLayerTypes] = {
  Convolution,
  PoolingAvg,
  PoolingMax,
  Relu,
  InnerProduct,
  Softmax,
  ReturnCallback
};
#2 "VCNN/src/lib/layers/relu.cpp" 2
#1 "VCNN/src/lib/layers/../util.h" 1
//#ifdef VCNN_UTIL_H
//#define VCNN_UTIL_H
#12 "VCNN/src/lib/layers/../util.h"
//#endif
#3 "VCNN/src/lib/layers/relu.cpp" 2

void Relu(Layer current, LayerWeight cw, Layer next) {

 int channels = current.input_channel_num;
 int height = current.input_feature_map_height;
 int width = current.input_feature_map_width;

 for (int c = 0; c < channels; c++)
  for(int h = 0; h < height; h++)
   for(int w = 0; w < width; w++)
    {
     float tmp = *(current.input_data + (c)*(current.input_feature_map_height*current.input_feature_map_width) + (h)*current.input_feature_map_width + (w));
     *(next.input_data + (c)*(next.input_feature_map_height*next.input_feature_map_width) + (h)*next.input_feature_map_width + (w)) = tmp > 0 ? tmp : 0;
    }
}

class ssdm_global_array_relupp0cppaplinecpp {
	public:
		 inline __attribute__((always_inline)) ssdm_global_array_relupp0cppaplinecpp() {
			_ssdm_SpecConstant(&nLayers);
			_ssdm_SpecConstant(&dataScale);
			_ssdm_SpecConstant(&nOutput);
			_ssdm_SpecConstant(&nChannels);
			_ssdm_SpecConstant(&imgWidth);
			_ssdm_SpecConstant(&imgHeight);
			_ssdm_SpecConstant(&nLayerTypes);
		}
};
static ssdm_global_array_relupp0cppaplinecpp ssdm_global_array_ins;
