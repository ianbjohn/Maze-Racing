#include "RLEDecompress.h"

void RLEdecompress(const unsigned char* compressed, unsigned char** decompressed, int width, int height)
{
    //decompress a 1d array into a 2d array RLE style
    int decCounter = 0, comCounter = 0;
    while (decCounter < width * height) {
        //expect whatever value is currently being read to be a run-length
        int runLength = compressed[comCounter];

        //load that many of the next value into the  array
        while (runLength > 0) {
            decompressed[decCounter / width][decCounter % width] = compressed[comCounter + 1];
            decCounter++;
            runLength--;
        }
        comCounter += 2;
    }
}
