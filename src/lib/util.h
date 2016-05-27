//#ifdef VCNN_UTIL_H
//#define VCNN_UTIL_H

#define GET_INPUT_DATA(l, i,j,k) \
	*(l.input_data + i*(l.input_feature_map_height*l.input_feature_map_width) + j*l.input_feature_map_width + k)


#define is_a_ge_zero_and_a_lt_b(a,b) (a>=0 && a<b)
#define INFINITY (1e99)


//#endif
