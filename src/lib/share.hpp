#ifndef __share_hpp__
#define __share_hpp__

#include <cstdint>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <time.h>

#define FMT_SPACE       5
#define ARR_LENGTH      16

void initRnd(void);

void printList(int16_t* point, uint32_t len);
void printList(std::string text, int16_t* point, uint32_t len);

void copyList(int16_t* origin, int16_t* duplicate, uint32_t len);

bool checkList(int16_t* origin, uint32_t len);

void makeListRev(int16_t* origin, uint32_t len);
void makeListNeg(int16_t* origin, uint32_t len);
void makeListRnd(int16_t* origin, uint32_t len, uint16_t peak);

#endif
