/*
    addCU is a kernel that adds two numbers.

    This main() adds 1 and 2, printing the output.
*/

#include <stdio.h>

__global__ void addCU(int* num1, int* num2, int* output) {
    *output = *num1 + *num2;
}

int main() {
    int size = 1 * sizeof(int);
    int num1, num2, output;
    int *dev_num1, *dev_num2, *dev_output;

    cudaMalloc(&dev_num1, size);
    cudaMalloc(&dev_num2, size);
    cudaMalloc(&dev_output, size);

    num1 = 1;
    num2 = 2;

    cudaMemcpy(dev_num1, &num1, size, cudaMemcpyHostToDevice);
    cudaMemcpy(dev_num2, &num2, size, cudaMemcpyHostToDevice);

    addCU<<<1,1>>>(dev_num1, dev_num2, dev_output);

    cudaMemcpy(&output, dev_output, size, cudaMemcpyDeviceToHost);

    cudaFree(dev_num1);
    cudaFree(dev_num2);
    cudaFree(dev_output);

    printf("%i\n", output);
    
    return 0;
}