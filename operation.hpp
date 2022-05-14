#include "header_files/max.cpp"
#include "header_files/min.cpp"
#include "header_files/averaging.cpp"
#include "header_files/freqCheck.cpp"
#include "header_files/create2DArray.cpp"

int **create2DArray(unsigned height, unsigned width);
int **average(int **arr1, int **arr2, int x, int y);
int **max(int **arr1, int **arr2, int x, int y);
int **min(int **arr1, int **arr2, int x, int y);
int **freqCheck(int **arr1, int **arr2, int hgt, int wdth);
