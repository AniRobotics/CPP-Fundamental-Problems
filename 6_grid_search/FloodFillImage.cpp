#include <iostream>
#include <vector>

using namespace std;

void colorFloodFill(std::vector<std::vector<int>> &image, int r, int c, const int &oldColor, const int &newColor)
{
    if (r<0 || r>=image.size() || c<0 || c>=image.size() || image[r][c] != oldColor)
    {
        return;
    }
    
    image[r][c] = newColor;
    
    // Then traverse recursively in 4-directionally manner
    colorFloodFill(image, r+1, c, oldColor, newColor);
    colorFloodFill(image, r-1, c, oldColor, newColor);
    colorFloodFill(image, r, c+1, oldColor, newColor);
    colorFloodFill(image, r, c-1, oldColor, newColor);
}

void printFloodFilledImage(std::vector<std::vector<int>> &image)
{
// Print the modified (flood-filled) image
    for (size_t i = 0; i < image.size(); i++)
    {
        for (size_t j = 0; j < image[0].size(); j++)
        {
            std::cout << image[i][j] << ", ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char** argv) {

    // Image array
    std::vector<std::vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    
    // Define the starting pixel coordinate
    int sr = 1, sc = 1;
    
    // Define the new color
    int newColor = 2;
    
    // Flood fill the image with the new color from the starting coordinate
    int oldColor = image[sr][sc];
    colorFloodFill(image, sr, sc, oldColor, newColor);
    
    // Print the modified image
    printFloodFilledImage(image);
    
    return 0;
}
