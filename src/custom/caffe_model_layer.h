typedef enum {CONVOLUTION,POOLING_AVG,POOLING_MAX,RELU,INNERPRODUCT,SOFTMAX} LayerType;

typedef  struct {
    int id;
    LayerType type;
    /*
     # Meta Data
    All meta data for every type of layer are put here, for easy initialization. HLS C don't allow dynamic memory operation.
    Hopefully the complier will optimize the unused variable for us.(It should be able to.)
    */
    /* for convolutional layer
     the conv layer here won't take care about padding, since we gonna use pixel streaming,
     FPGA is best for streaming processing, fast and efficient*/

    int conv_filter_channels;
    int conv_filter_size;
    int conv_filter_num;
    int conv_stride;


    /*for pooling layer*/
    int pl_kernel_size;
    int pl_stride;

    /*for inner product layer*/
    int ip_channel_num;
    int ip_output_num;
} Layer;


         

#ifndef LAYER_WEIGHT_STRUCT
#define LAYER_WEIGHT_STRUCT
typedef struct {

  int id;
  //for convolutional layer
  float *conv_filter_weight; // 32->3->5x5
  float *conv_bias; //1x32

  /*for inner product layer*/
  float *ip_weight;

} LayerWeight;
#endif

static int const nChannels = 3;
static int const imgWidth = 32;
static int const imgHeight = 32;
Layer  layers[12] = {
{
                .id = 0,
            .type=CONVOLUTION,
            .conv_filter_channels=3,
            .conv_filter_size=5,
            .conv_filter_num=32,
            .conv_stride=1
            
            }
,
{
                .id = 1,
            .type=POOLING_AVG,
            .pl_kernel_size=2,
            .pl_stride=3
            
            }
,
{
                .id = 2,.type=RELU
            }
,
{
                .id = 3,
            .type=CONVOLUTION,
            .conv_filter_channels=32,
            .conv_filter_size=5,
            .conv_filter_num=32,
            .conv_stride=1
            
            }
,
{
                .id = 4,.type=RELU
            }
,
{
                .id = 5,
            .type=POOLING_AVG,
            .pl_kernel_size=2,
            .pl_stride=3
            
            }
,
{
                .id = 6,
            .type=CONVOLUTION,
            .conv_filter_channels=32,
            .conv_filter_size=5,
            .conv_filter_num=64,
            .conv_stride=1
            
            }
,
{
                .id = 7,.type=RELU
            }
,
{
                .id = 8,
            .type=POOLING_AVG,
            .pl_kernel_size=2,
            .pl_stride=3
            
            }
,
{
                .id = 9,
            .type=INNERPRODUCT,
            .ip_channel_num=1024,
            .ip_output_num=64
            
            }
,
{
                .id = 10,
            .type=INNERPRODUCT,
            .ip_channel_num=64,
            .ip_output_num=10
            
            }
,
{
                .id = 11,.type=SOFTMAX
            }
};
