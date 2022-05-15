int **create2DArray(unsigned int height, unsigned int width)
{
    int **array2D = 0;
    array2D = new int *[height];

    for (int h = 0; h < height; h++)
    {
        array2D[h] = new int[width];

        for (int w = 0; w < width; w++)
        {
            // fill in some initial values (0 here)
            array2D[h][w] = 0;
        }
    }

    return array2D;
}