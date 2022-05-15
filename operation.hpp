#include "header_files/max.hpp"
#include "header_files/min.hpp"
#include "header_files/averaging.hpp"
#include "header_files/freqCheck.hpp"
#include "header_files/create2DArray.hpp"
#include "header_files/write.hpp"

int **create2DArray(unsigned int height, unsigned int width);
int **average(int **arr1, int **arr2, int x, int y);
int **max(int **arr1, int **arr2, int x, int y);
int **min(int **arr1, int **arr2, int x, int y);
int **freqCheck(int **arr1, int **arr2, int hgt, int wdth);
void write(std::ofstream object, int** result, int height, int width);