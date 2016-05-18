#include "layers.h"
#include "../../util.h"

void Relu(Layer current, LayerWeight cw, Layer next) {

	int channels = current.input_channel_num;
	int height = current.input_feature_map_height;
	int width = current.input_feature_map_width;

	for (int c = 0; c < channels; c++)
		for(int h = 0; h < height; h++)
			for(int w = 0; w < width; w++)
				{
					float tmp = GET_INPUT_DATA(current,c,h,w);
					GET_INPUT_DATA(next,c,h,w) = tmp > 0 ? tmp : 0;
				}
}
