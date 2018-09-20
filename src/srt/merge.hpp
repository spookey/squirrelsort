#ifndef __merge_hpp__
#define __merge_hpp__

#include <cmath>
#include <cstdint>

void merge(int16_t* point, uint32_t lpos, uint32_t middle, uint32_t rpos);
void mergeSort(int16_t* point, uint32_t lpos, uint32_t rpos);
void mergeSort(int16_t* point, uint32_t len);

#endif
