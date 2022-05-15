int** average(int **arr1,int **arr2,int hgt,int wdth)
{   
    int sum;
    int **ptr = new int*[hgt];

    for (int i = 0; i < hgt; i++)
    {
        ptr[i] = new int[wdth];
        for (int j = 0; j < wdth; j++)
        {
            // Calculating Sum --> Mean --> Output
            sum = arr1[i][j] + arr2[i][j];
            *(*(ptr + i) + j)  = sum/2;
        }
        
    }
    return ptr;
}