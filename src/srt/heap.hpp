#ifndef __heap_hpp__
#define __heap_hpp__

#include <algorithm>
#include <cmath>
#include <cstdint>

void heapify(int16_t* point, uint32_t len, uint32_t pos);
void heapSort(int16_t* point, uint32_t len);

#endif
