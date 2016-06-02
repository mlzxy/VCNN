#include "custom.h"
#include "./mnist/mnist_data.h"




#define MNIST_TEST_IMAGE_PATH  "/home/xy0/Workspace/vivado_hls/VCNN/VCNN/src/custom/mnist/mnist_data/t10k-images-idx3-ubyte"
#define MNIST_TEST_LABEL_PATH  "/home/xy0/Workspace/vivado_hls/VCNN/VCNN/src/custom/mnist/mnist_data/t10k-labels-idx1-ubyte"


void print_mnist(int images[nChannels][imgHeight][imgWidth]){
	for(int i = 0; i<imgHeight; i++){
		for(int j = 0; j<imgWidth; j++)
			printf("%d ", images[0][i][j]);
		printf("\n");
	}
}


int main(){
	 float result[nOutput];
	 int (*images)[28][28]  = mnist_images;
	 int* labels = mnist_labels;
	 int corrected_number = 0;
	 //MNIST_TEST_NUM
	 for(int i = 0; i<MNIST_TEST_NUM; i++,images++){
		/*
		 * image, label
		 */
//		print_mnist(images);
		neural_net(layers_weight, mean_image, images, result);
		float max_val = -10000;
		int max_idx = -1;
		for (int c=0; c < nOutput; c++)
			if (result[c] > max_val){
				max_val = result[c];
				max_idx = c;
			}
		printf("the corrected label = %d; the detected label = %d;\n", labels[i], max_idx);
		if(labels[i] == max_idx){
			corrected_number++;
		}
	 }

	float rate = (float)corrected_number/MNIST_TEST_NUM;
	printf("Detection Rate is %.2f%%\n", rate*100);
	if (rate > 0.9)
		printf("Neural Network is Working :)\n");
	else
		printf("Neural Network is not working :(\n");
	return 0;
}


