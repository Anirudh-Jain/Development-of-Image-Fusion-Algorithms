#include<iostream>

int** average(int *arr1,int *arr2,int hgt,int wdth)
{   
    //int output[hgt][wdth];
    int i,j,k = 0;
    int sum;

    int **ptr = new int*[wdth];

    for (int i = 0; i < hgt; i++)
    {
        ptr[i] = new int[hgt];
        for (int j = 0; j < wdth; j++)
        {
            sum = arr1[k] + arr2[k];
            //std::cout<<arr1[k]<<"\t"<<(char)arr1[k]<<std::endl;
            *(*(ptr + i) + j)  = sum/2;
            //std::cout<<*(*(ptr + i) + j)<<"\t"<<(char)*(*(ptr + i) + j)<<std::endl;
            k++;
        }
        
    }
    return ptr;
}