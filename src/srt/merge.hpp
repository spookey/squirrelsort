#ifndef _merge_hpp_
#define _merge_hpp_

#include <cmath>
#include <cstdint>

void merge(int16_t* point, uint32_t lpos, uint32_t middle, uint32_t rpos);
void mergeSort(int16_t* point, uint32_t lpos, uint32_t rpos);
void mergeSort(int16_t* point, uint32_t len);

#endif
