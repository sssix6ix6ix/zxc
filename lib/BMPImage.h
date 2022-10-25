#pragma once

#include <cstdint>
#include <deque>
#include <fstream>
#include <string>

const uint32_t kINFOHEADERSIZE = 40;
const uint32_t kHeaderSize = 14;
const uint32_t kSizeOfOnePixel = 3;
const size_t kMultiplicityOfWidth = 4;
const uint8_t kAddition = 0;

struct Color {
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
};

const Color kWhite = {255, 255, 255};
const Color kGreen = {120, 214, 0};
const Color kPurple = {255,0 ,139};
const Color kYellow = {0, 255 , 255};
const Color kBlack = {0,0,0};

#pragma pack(push, 1)
class BMPImage {
public:
    char bfType[2] = {'B', 'M'};
    uint32_t bfSize = 0;
    uint32_t bfReserved = 0;
    uint32_t bf0ffBits = 54;

    uint32_t biSize = 40;

    uint32_t biWidth = 0;
    uint32_t biHeight = 0;
    uint16_t biPlanes = 1;
    uint16_t biBitCount = 24;
    uint32_t biCompression = 0;

    uint32_t biSizeImage = 0;

    uint32_t biXPelsPerMeter = 0;
    uint32_t biYPelsPerMeter = 0;
    uint32_t biClrUsed = 0;

    uint32_t biClrImportant = 0;

};
#pragma pack(pop)

void drawImage(BMPImage& image, const std::deque<std::deque<uint64_t>>& pixels, const std::string& out);
