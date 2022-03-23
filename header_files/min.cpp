int **min(int *arr1, int *arr2, int hgt, int wdth)
{
    int i, j, k = 0;
    int **ptr = new int *[wdth];

    for (int i = 0; i < hgt; i++)
    {
        ptr[i] = new int[hgt];
        for (int j = 0; j < wdth; j++)
        {
            if (arr1[k] > arr2[k])
                *(*(ptr + i) + j) = arr2[k];
            else
                *(*(ptr + i) + j) = arr1[k];
            k++;
        }
    }
    return ptr;
}