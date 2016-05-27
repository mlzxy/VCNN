#include "custom.h"
#include <stdio.h>
#include "./mnist/mnist_data.h"


#define MNIST_TEST_IMAGE_PATH  "/home/xy0/Workspace/vivado_hls/VCNN/VCNN/src/custom/mnist/mnist_data/t10k-images-idx3-ubyte"
#define MNIST_TEST_LABEL_PATH  "/home/xy0/Workspace/vivado_hls/VCNN/VCNN/src/custom/mnist/mnist_data/t10k-labels-idx1-ubyte"





int main(){
	 float result[nOutput];
	 int (*images)[28][28]  = mnist_images;
	 int* labels = mnist_labels;
	 int corrected_number = 0;

	 for(int i = 0; i<MNIST_TEST_NUM; i++,images++){
		/*
		 * image, label
		 */
		neural_net(layers_weight, mean_image, images, result);
		float max_val = -10000;
		int max_idx = -1;
		for (int c=0; c < nOutput; c++)
			if (result[c] > max_val){
				max_val = result[c];
				max_idx = c;
			}
		if(labels[i] == max_idx){
			corrected_number++;
		}
	 }

	float rate = (float)corrected_number/MNIST_TEST_NUM;
	printf("Detection Rate is %.2f%%\n", rate*100);
	if (rate > 0.9)
		printf("Neural Network is Working :)");
	else
		printf("Neural Network is not working :(");
	return 0;
}


