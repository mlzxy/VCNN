

#include "convolution_sobel.h"
#include "math.h"
#define ABSDIFF(x,y)	((x>y)? x - y : y - x)
#define ABS(x)          ((x>0)? x : -x)

#define SLIDE_WINDOW_BUFFER(x,y,z)  \
			window_buffer[0][2] = x; \
	    	window_buffer[1][2] = y; \
	    	window_buffer[2][2] = z;




void convolution_sobel(AXI_STREAM& INPUT_STREAM, AXI_STREAM& OUTPUT_STREAM, int rows, int cols) {
	//Create AXI streaming interfaces for the core
	#pragma HLS INTERFACE axis port=INPUT_STREAM
	#pragma HLS INTERFACE axis port=OUTPUT_STREAM

	//[ASK] Row and Col and return value, are in the Control BUS
	#pragma HLS RESOURCE core=AXI_SLAVE variable=rows metadata="-bus_bundle CONTROL_BUS"
	#pragma HLS RESOURCE core=AXI_SLAVE variable=cols metadata="-bus_bundle CONTROL_BUS"
	#pragma HLS RESOURCE core=AXI_SLAVE variable=return metadata="-bus_bundle CONTROL_BUS"

	//[ASK] stable port
	#pragma HLS INTERFACE ap_stable port=rows
	#pragma HLS INTERFACE ap_stable port=cols

	hls::Mat<MAX_HEIGHT, MAX_WIDTH, HLS_8UC1> img_0(rows, cols);
	hls::Mat<MAX_HEIGHT, MAX_WIDTH, HLS_8UC1> img_1(rows, cols);
	//hls::Mat<MAX_HEIGHT, MAX_WIDTH, HLS_8UC1> img_2(rows, cols);

  //Convert the Stream into Matrix
	hls::AXIvideo2Mat(INPUT_STREAM, img_0);

  //Sobel Filter
	const char Gx[3][3] = { {-1,0,1},
				    {-2,0,2},
				    {-1,0,1}};
	const char Gy[3][3] = { {-1,-2,-1},
				    {0,0,0},
				    {1,2,1}};


	    assert(rows <= MAX_HEIGHT);
	    assert(cols <= MAX_WIDTH);

	    unsigned char edge_val;
	    short x_dir;
	    short y_dir;
	    short edge_weight;
	    int output_row,output_col;


	    unsigned char line_buffer[3][cols] = {0};
	    unsigned char window_buffer[3][3] = {0};

	    for(int row = 0; row<rows + K_HEIGHT/2; row++)
	    	for(int col = 0; col<cols + K_WIDTH/2; col++){
				#pragma pipeline
	    		x_dir = 0;
	    		y_dir = 0;
	    		edge_val = 0;
	    		output_row = row-K_HEIGHT/2;
	    		output_col = col-K_WIDTH/2;

	    		//Slide the Window Buffer
	    		for(int k=0;k<3;k++){
	    			window_buffer[k][0] = window_buffer[k][1];
	    			window_buffer[k][1] = window_buffer[k][2];
	    		}


	    		//Fill the Line Buffer
	    		if(col < cols && row < rows){
	    			line_buffer[0][col] = line_buffer[1][col];
	    			line_buffer[1][col] = line_buffer[2][col];
	    			line_buffer[2][col] = img_0.read().val[0];
	    			SLIDE_WINDOW_BUFFER(line_buffer[0][col],
	    				    							line_buffer[1][col],
	    												line_buffer[2][col]);
	    		} else{
	    			//Fill the Window Buffer
	    			SLIDE_WINDOW_BUFFER(0,0,0);
	    		}



	    		if(output_row < 0 || output_col < 0){
	    			continue;
	    		} else if(output_row == 0        ||
	    				  output_col == 0        ||
						  output_row == (rows-1) ||
						  output_col == (cols-1)){
	    			edge_val = 0;
	    		}else{
	    			for(int i = 0; i < 3; i++){
	    				for(int j = 0; j < 3; j++){
	    					x_dir = x_dir+window_buffer[i][j]* Gx[i][j];
	    					y_dir = y_dir+window_buffer[i][j]* Gy[i][j];
	    				}
	    			}
	    			edge_weight = ABS(x_dir)+ABS(y_dir);
	    			edge_val = (255-(unsigned char)(edge_weight));
	    			if(edge_val > 200)
	    				edge_val = 0;   //edge_weight < 55
	    			else if(edge_val < 50)
	    				edge_val = 255; //edge_weight > 205
	    		}

	    		GRAY_PIXEL result;
	    		result.val[0] = edge_val;
	    		img_1 << result;
	    	}


	    hls::Mat2AXIvideo(img_1, OUTPUT_STREAM);


}
