#include <fstream>
#include <cmath>
#include <iostream>
#include "operation.hpp"

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        cout << argc << endl;
        cout << "proper syntax: ./a.out <input flename1> <input filename2>";
        return 0;
    }

    // Exit program if file doesn't open
    string filename(argv[1]);
    string path = "./input_images/" + filename;
    ifstream infile(path, ios::binary);

    string filename2(argv[2]);
    string path2 = "./input_images/" + filename2;
    ifstream infile2(path2, ios::binary);

    if (!infile.is_open() || !infile2.is_open())
    {
        if (!infile.is_open())
        {
            cout << "File " << path << " not found in directory." << endl;
            return 0;
        }
        if (!infile2.is_open())
        {
            cout << "File2 " << path2 << " not found in directory." << endl;
            return 0;
        }
    }
    ofstream avg_fused("./fused_output_images/avg_fused.pgm", ios::binary);
    ofstream mm_fused("./fused_output_images/min_max_fused.pgm", ios::binary);
    ofstream pca_fused("./fused_output_images/pca_fused.pgm", ios::binary);

    char buffer[1024], buffer2[1024];
    int width, height, intensity, width2, height2, intensity2;

    infile >> buffer >> width >> height >> intensity;
    infile2 >> buffer2 >> width2 >> height2 >> intensity2;

    int pic1[height][width], pic2[height][width];

    // Reading in the first input image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            pic1[i][j] = (int)infile.get();
        }
    }
    infile.close();

    // Reading in the second input image
    for (int i = 0; i < height2; i++)
    {
        for (int j = 0; j < width2; j++)
        {
            pic2[i][j] = (int)infile2.get();
        }
    }
    infile2.close();

    // Generating Outputs
    // By taking Mean of both the intensities
    int **result_avg = average(*pic1, *pic2, height, width);

    avg_fused << buffer << '\n'
              << width << " " << height << '\n'
              << intensity;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {   
            avg_fused << (char)*(*(result_avg + i) + j);
        }
        //avg_fused << flush;
    }

    // By taking larger of both the intensities
    int **result_max = min_max(*pic1, *pic2, height, width);

    mm_fused << buffer << '\n'
             << width << " " << height << '\n'
             << intensity;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            mm_fused << (char)*(*(result_max + i) + j);
        }
        //mm_fused << flush;
    }
    /*
    for (int i = 0; i < height2; i++)
    {
        for (int j = 0; j < width2; j++)
        {
            pca_fused << (char)pic2[i][j];
        }
        //pca_fused << endl;
    }
    */
    return 0;
}