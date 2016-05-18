#include "layers.h"
#include "../../util.h"
#include <math.h>

void Softmax(Layer current, LayerWeight cw, Layer next){
	float exp_sum = 0.0;
	int channels = current.input_channel_num;
	int height = current.input_feature_map_height;
	int width = current.input_feature_map_width;
	int total_input = channels*width*height;

	for(int i=0; i<total_input; i++){
		float tmp =  exp(*(current.input_data+i));
		*(next.input_data+i) = tmp;
		exp_sum += tmp;
	}
	for(int i=0; i<total_input; i++){
		*(next.input_data+i) = (*(next.input_data+i))/exp_sum;
	}
}
