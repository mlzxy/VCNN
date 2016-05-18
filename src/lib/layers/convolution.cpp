#include "layers.h"
#include "../../util.h"



inline float conv2d(Layer current, float* kernel, int ksize, int channel, int h, int w){
	float r = 0;
	int offset = int(ksize/2);
	for (int i = -offset; i < offset+1; i++)
		for (int j = -offset; j<offset+1; j++)
		{
			r+=(*(kernel + (i+offset)*ksize + (j+offset))*GET_INPUT_DATA(current, channel, h+i, w+j));
		}

	return r;
}


void Convolution(Layer current, LayerWeight cw, Layer next){
	int ksize = current.conv_filter_size;
	int stride = current.conv_stride;
	int pad = current.conv_pad;
	int channels = current.input_channel_num;
	int offset_idx = int(ksize/2) - pad;
	int height = current.input_feature_map_height-offset_idx;
	int width = current.input_feature_map_width-offset_idx;
	float *bias = cw.conv_bias;
	float *kernel = cw.conv_filter_weight;

	for (int c = 0; c < channels; c++)
		for(int h = offset_idx, hc = 0; h < height; h+=stride, hc++)
			for(int w = offset_idx, wc = 0; w < width; w+=stride, wc++)
				GET_INPUT_DATA(next,c,hc,wc) = conv2d(current, kernel, ksize, c, h, w) + *(bias + hc*height + wc);
}
