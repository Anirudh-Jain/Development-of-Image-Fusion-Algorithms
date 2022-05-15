#include "getFreq.hpp"
#include <cmath>

int **freqCheck(int **arr1, int **arr2, int hgt, int wdth)
{
    int **ptr = new int *[hgt];

    for (int i = 0; i < hgt; i++)
    {
        ptr[i] = new int[wdth];
        for (int j = 0; j < wdth; j++)
        {
            if (i == 0 || j == 0 || i == hgt - 1 || j == wdth - 1)
            {
                // Taking Mean on Border Values to avoid Padding
                *(*(ptr + i) + j) = (*(*(arr1 + i) + j) + *(*(arr2 + i) + j)) / 2;
            }
            else
            {
                // Finding Sharper Block/Area
                if (abs(getFreq(arr1, i, j)) >= abs(getFreq(arr2, i, j)))
                {
                    // Image 1 has sharper block
                    *(*(ptr + i) + j) = *(*(arr1 + i) + j);
                }
                else
                    // Image 2 has sharper block
                    *(*(ptr + i) + j) = *(*(arr2 + i) + j);
            }
        }
    }
    return ptr;
}