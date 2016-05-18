#include "./layers/layers.h"
#include "../caffe_model_layer.h"
#include "util.h"
#include "../custom.h"

void neural_net(LayerWeight layer_weights, MEAN_IMAGE_TYPE mean_image, INPUT_IMAGE_TYPE input_image){
	//input image
	//input weight
	//mean image
	init();
	//subtract the input image by mean_image
	for(int i = 0; i<nChannels; i++)
		for(int j = 0; j<imgHeight; j++)
			for(int k = 0; k<imgWidth; k++)
				GET_INPUT_DATA(layers[0], i,j,k) =input_image[i][j][k] - mean_image[i][j][k];


	for(int i = 0;i<nLayers;i++){
		layer_dict[layers[i].type](layers[i], layer_weights[i], layers[i+1]);
	}
}

