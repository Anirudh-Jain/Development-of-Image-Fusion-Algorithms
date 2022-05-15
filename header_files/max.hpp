int **max(int **arr1, int **arr2, int hgt, int wdth)
{
    int **ptr = new int *[hgt];

    for (int i = 0; i < hgt; i++)
    {
        ptr[i] = new int[wdth];
        for (int j = 0; j < wdth; j++)
        {
            // Finding Max Intensity --> Output
            if (arr1[i][j] < arr2[i][j])
                *(*(ptr + i) + j) = arr2[i][j];
            else
                *(*(ptr + i) + j) = arr1[i][j];
        }
    }
    return ptr;
}