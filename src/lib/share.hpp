#ifndef __share_hpp__
#define __share_hpp__

#include <chrono>
#include <cstdint>
#include <cstring>
#include <iomanip>
#include <iostream>

#define FMT_SPACE       5

#define FMT_TIME        4 * FMT_SPACE
#define PRC_TIME        12

#define DISPLAY_LENGTH  16

#define _CH             std::chrono
#define HIGH_POINT      _CH::time_point<_CH::high_resolution_clock>

const int16_t peaksRnd[3] = {99, 999, 9999};
const uint32_t lensBench[7] = {64, 128, 256, 512, 1024, 2048, 4096};


void initRnd(void);

void printEnd(void);
void printText(std::string text);
void printTime(std::string text, double time);
void printList(int16_t* point, uint32_t len);
void printList(std::string text, int16_t* point, uint32_t len);

void copyList(int16_t* origin, int16_t* duplicate, uint32_t len);
bool checkList(int16_t* origin, uint32_t len);

void makeListRev(int16_t* origin, uint32_t len);
void makeListNeg(int16_t* origin, uint32_t len);
void makeListRnd(int16_t* origin, uint32_t len, uint16_t peak);

HIGH_POINT startTime(void);
double stopTime(HIGH_POINT start);

#endif
