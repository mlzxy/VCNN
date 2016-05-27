#include "layers.h"
#include "../util.h"


inline float avg(Layer current, int ksize, int channel, int h, int w){
	float r = 0;
	int offset = int(ksize/2);
	int karea = ksize*ksize;
	for (int i = -offset; i < offset+1; i++)
		for (int j = -offset; j<offset+1; j++)
		{
			r+=(GET_INPUT_DATA(current, channel, h+i, w+j)/karea);
		}
	return r;
}

inline float max(Layer current, int ksize, int channel, int h, int w){
	float r = -INFINITY;
	int offset = int(ksize/2);
	int karea = ksize*ksize;
	for (int i = -offset; i < offset+1; i++)
		for (int j = -offset; j<offset+1; j++)
		{
			float tmp =  GET_INPUT_DATA(current, channel, h+i, w+j);
			r = r > tmp ? r : tmp;
		}
	return r;
}

void PoolingAvg(Layer current, LayerWeight cw, Layer next){
	int ksize = current.pl_kernel_size;
	int stride = current.pl_stride;
	int channels = current.input_channel_num;
	int offset_idx = int(ksize/2);
	int height = current.input_feature_map_height-offset_idx;
	int width = current.input_feature_map_width-offset_idx;

	for (int c = 0; c < channels; c++)
		for(int h = offset_idx, hc = 0; h < height; h+=stride, hc++)
			for(int w = offset_idx, wc = 0; w < width; w+=stride, wc++)
				{
				GET_INPUT_DATA(next,c,hc,wc) = avg(current, ksize, c, h, w);
				}

}


void PoolingMax(Layer current, LayerWeight cw, Layer next){
	int ksize = current.pl_kernel_size;
	int stride = current.pl_stride;
	int channels = current.input_channel_num;
	int offset_idx = int(ksize/2);
	int height = current.input_feature_map_height-offset_idx;
	int width = current.input_feature_map_width-offset_idx;

	for (int c = 0; c < channels; c++)
		for(int h = offset_idx, hc = 0; h < height; h+=stride, hc++)
			for(int w = offset_idx, wc = 0; w < width; w+=stride, wc++)
				{
				GET_INPUT_DATA(next,c,hc,wc) = max(current, ksize, c, h, w);
				}
}
