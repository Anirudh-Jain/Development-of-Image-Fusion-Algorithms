#include "getMask.hpp"
#define STRIDE 1

const int FILTER[3][3] = {{-1, 2, -1},   // Laplacian Filter
                          {2, -4, 2}, 
                          {-1, 2, -1}};


int getFreq(int** arr, int idx, int idy)
{
    int** mask = getMask(arr,idx,idy);    // Extracting Block(Area)
    int freqVal = 0;

    for (int i = 0; i < 3; i += STRIDE)
    {
        for (int j = 0; j < 3; j += STRIDE)
        {
            freqVal += mask[i][j] * (FILTER[i][j]);     // Sum of change in the area
        }
    }

    return freqVal;
}