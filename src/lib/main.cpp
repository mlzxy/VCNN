#include "./layers/layers.h"
#include "../custom/caffe_model_layer.h"
#include "util.h"
#include "../custom/custom.h"


//image_type
void neural_net(LayerWeight layer_weights[nLayers], MEAN_IMAGE_TYPE mean_image[nChannels][imgHeight][imgWidth], INPUT_IMAGE_TYPE input_image[nChannels][imgHeight][imgWidth], float result[nOutput]){
	//input image
	//input weight
	//mean image
	//subtract the input image by mean_image
	for(int i = 0; i<nChannels; i++)
		for(int j = 0; j<imgHeight; j++)
			for(int k = 0; k<imgWidth; k++){
				float temp =  (input_image[i][j][k] - mean_image[i][j][k]) * dataScale;
				GET_INPUT_DATA(layers[0], i,j,k) = temp;
			}
	for(int i = 0;i<nLayers;i++){
		layer_dict[layers[i].type](layers[i], layer_weights[i], layers[i+1]);
	}

	for(int i = 0;i<nOutput;i++){
		result[i] = *(layers[nLayers-1].input_data+i);
	}

}

/*
 * Unsynthesiable problem
 *
 * 1. Your top level function contains a port that is a pointer to the MODEL struct which has itself pointers (even double pointers).

 * 2. unsupported type conversion: ENUM=>INT
 *
 * 3. Unsupport memory access, compiler is not able to know the size of layers.input_data.
 *
 * 4. Function Pointer is not support
 * */

