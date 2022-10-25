#include "BMPImage.h"
#include <iostream>
#include <windef.h>

void drawImage(BMPImage& image,const std::deque<std::deque<uint64_t>>& graph, const std::string& out) {

    image.biHeight = graph.size();
    image.biWidth = graph[0].size();
    uint32_t padding = (kMultiplicityOfWidth - (kSizeOfOnePixel * image.biWidth % kMultiplicityOfWidth)) % kMultiplicityOfWidth;
    image.bfSize = image.bf0ffBits + kSizeOfOnePixel * image.biHeight * image.biWidth + padding * image.biHeight;

    std::ofstream file(out);

    file.write(reinterpret_cast<const char *>((LPSTR) &image), sizeof(image));
    for (size_t y = 0; y < image.biHeight; y++) {
        for (size_t x = 0; x < image.biWidth; x++) {
            Color color;
            if (graph[y][x] > 3) color = kBlack;
            if (graph[y][x] == 3) color = kYellow;
            if (graph[y][x] == 2) color = kPurple;
            if (graph[y][x] == 1) color = kGreen;
            if (graph[y][x] == 0) color = kWhite;
            file.write(reinterpret_cast<const char *>((LPSTR)&color), sizeof(color));
        }

        for (size_t i = 0 ; i < padding; i++) {
            file.write(reinterpret_cast<const char*>((LPSTR)&kAddition), 1);
        }
    }
}
