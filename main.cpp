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

    // Instantiating File Objects for reading
    string filename(argv[1]);
    string path = "./input_images/" + filename;
    ifstream infile(path, ios::binary);

    string filename2(argv[2]);
    string path2 = "./input_images/" + filename2;
    ifstream infile2(path2, ios::binary);

    // Exit program if file doesn't open
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

    // Else continue
    // Instantiating File Objects for writing
    ofstream avg_fused("./fused_output_images/avg_fused.pgm", ios::binary);
    ofstream max_fused("./fused_output_images/max_fused.pgm", ios::binary);
    ofstream min_fused("./fused_output_images/min_fused.pgm", ios::binary);
    ofstream freq_fused("./fused_output_images/freq_fused.pgm", ios::binary);

    char buffer[1024], buffer2[1024];
    int width, height, intensity, width2, height2, intensity2;

    // Storing Headers
    infile >> buffer >> width >> height >> intensity;
    infile2 >> buffer2 >> width2 >> height2 >> intensity2;

    // Initializing Arrays to store image intensities
    int **pic1 = create2DArray(height, width);
    int **pic2 = create2DArray(height2, width2);

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

    /* Generating Outputs */

    // By taking Mean of both the intensities
    int **result_avg = average(pic1, pic2, height, width);

    avg_fused << buffer << '\n'
              << width << " " << height << '\n'
              << intensity;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg_fused << (char)*(*(result_avg + i) + j);
        }
    }
    avg_fused.close();

    // By taking larger of both the intensities
    int **result_max = max(pic1, pic2, height, width);

    max_fused << buffer << '\n'
              << width << " " << height << '\n'
              << intensity;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            max_fused << (char)*(*(result_max + i) + j);
        }
    }
    max_fused.close();

    // By taking smaller of both intensities
    min_fused << buffer << '\n'
              << width << " " << height << '\n'
              << intensity;

    int **result_min = min(pic1, pic2, height, width);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            min_fused << (char)*(*(result_min + i) + j);
        }
    }
    min_fused.close();

    // By taking sharp area into consideration from both images
    freq_fused << buffer << '\n'
               << width << " " << height << '\n'
               << intensity;

    int **result_freq = freqCheck(pic1, pic2, height, width);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            freq_fused << (char)*(*(result_freq + i) + j);
        }
    }
    freq_fused.close();

    return 0;
}