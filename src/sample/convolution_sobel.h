/**


    Note:	This code is based on Xilinx xapp1167 reference design.
    	   	Modified in order to make it simpler to use.

    Purpose: A header file


    @author Janarbek Matai
    @version 1.0 10/07/2014
*/
#ifndef __CONVOLUTION_SOBEL_H__
#define __CONVOLUTION_SOBEL_H__

#include "hls_video.h"
using namespace std;

// maximum image size
#define MAX_WIDTH  640
#define MAX_HEIGHT 480

// kernel dimensions
#define K_WIDTH 3
#define K_HEIGHT 3

// I/O Image Settings
#define INPUT_IMAGE_GRAY          "group_gray.jpg"
#define OUTPUT_IMAGE          "result_group_gray.jpg"
#define OUTPUT_IMAGE_GOLDEN   "result_1080p_golden.jpg"

// typedef video library core structures
typedef hls::stream<ap_axiu<32,1,1,1> >               AXI_STREAM;
typedef hls::Scalar<3, unsigned char>                 RGB_PIXEL;
typedef hls::Mat<MAX_HEIGHT, MAX_WIDTH, HLS_8UC3>     RGB_IMAGE;

typedef hls::Scalar<1, unsigned char>                 GRAY_PIXEL;
typedef hls::Mat<MAX_HEIGHT, MAX_WIDTH, HLS_8UC1>     GRAY_IMAGE;

// top level function for HW synthesis
void convolution_sobel(AXI_STREAM& src_axi, AXI_STREAM& dst_axi, int rows, int cols);



#endif

