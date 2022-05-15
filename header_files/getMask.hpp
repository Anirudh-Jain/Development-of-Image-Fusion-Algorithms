int** getMask(int** arr, int idx, int idy)
{   
    int **out = 0;                   
    out = new int *[3];

    for (int h = 0; h < 3; h++)
    {
        out[h] = new int[3];
        for (int w = 0; w < 3; w++)
        {
            out[h][w] = arr[idx-(h-1)][idy-(w-1)];      // Filling Values from Image Input
        }
    }
    
    return out;
}