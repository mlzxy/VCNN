#include "layers.h"


void InnerProduct(Layer current, LayerWeight cw, Layer next){
	int channels = current.input_channel_num;
	int height = current.input_feature_map_height;
	int width = current.input_feature_map_width;
	float *weight = cw.ip_weight;
	float *bias = cw.ip_bias;

	int total_input = channels*height*width;
	int total_output = current.ip_output_num;
	for(int i=0; i<total_output; i++)
	{
		float r = 0.0;
		for(int j=0; j<total_input; j++)
			r+=((*(current.input_data+j)) * (*(weight + i*total_input + j)));

		*(next.input_data+i) = r + *(bias+i);
	}
}
