#ifndef VCNN_LAYERS_H
#define VCNN_LAYERS_H

#include "../../custom/caffe_model_layer.h"

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


#endif
