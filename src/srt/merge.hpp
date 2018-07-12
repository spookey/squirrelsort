#ifndef __merge_hpp__
#define __merge_hpp__

#include <cstdint>
#include <cmath>

void merge(int16_t* point, uint8_t lpos, uint8_t middle, uint8_t rpos);
void mergeSort(int16_t* point, uint8_t lpos, uint8_t rpos);
void mergeSort(int16_t* point, uint8_t len);

#endif
