#include "caffe_model_layer.h"
#include <stdio.h>

void return_callback(Layer layer);
void neural_net(LayerWeight layer_weights[nLayers], MEAN_IMAGE_TYPE mean_image[nChannels][imgHeight][imgWidth], INPUT_IMAGE_TYPE input_image[nChannels][imgHeight][imgWidth], float result[nOutput]);
