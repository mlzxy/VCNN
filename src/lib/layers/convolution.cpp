#include "layers.h"
#include "../util.h"
#include "../../custom/custom.h"

inline float conv3d(Layer current, float* kernel, int ksize, int channels, int h, int w){
	float r = 0;
	int offset = int(ksize/2);
	int karea = ksize*ksize;
	for (int c = 0; c<channels; c++)
		for (int i = -offset; i < offset+1; i++)
			for (int j = -offset; j<offset+1; j++)
			{
				float kernel_v = *(kernel + c*(karea) + (offset+i)*ksize + (offset+j));
				float image_v = GET_INPUT_DATA(current, c, h+i, w+j);
				r+= kernel_v * image_v;
			}

	return r;
}



void Convolution(Layer current, LayerWeight cw, Layer next){
	int ksize = current.conv_filter_size;
	int fnum = current.conv_filter_num;
	int stride = current.conv_stride;
	int pad = current.conv_pad;
	int channels = current.input_channel_num;
	int offset_idx = int(ksize/2) - pad;
	int height = current.input_feature_map_height-offset_idx;
	int width = current.input_feature_map_width-offset_idx;
	int filterSize = ksize*ksize*channels;
	float *bias = cw.conv_bias;
	float *kernel = cw.conv_filter_weight;

//	printf("======================================\n");


	for (int fn = 0; fn < fnum; fn++){
			for(int h = offset_idx, hc = 0; h < height; h+=stride, hc++)
				for(int w = offset_idx, wc = 0; w < width; w+=stride, wc++){
					//the conv is like in volume
					float temp = conv3d(current, kernel+fn*filterSize, ksize, channels, h, w); //need change here
//					if(fn == 0){
//						printf("filter<%d,%d,%d> = conv3d + bias = %f + %f = %f \n",fn, hc,wc,temp,*(bias + fn),temp+*(bias + fn));
//					}
					GET_INPUT_DATA(next,fn,hc,wc) = temp+*(bias + fn);
				}
	}
}
