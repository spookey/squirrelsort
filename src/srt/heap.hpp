#ifndef __heap_hpp__
#define __heap_hpp__

#include <cstdint>
#include <cmath>

void heapify(int16_t* point, uint8_t len, uint8_t pos);
void heapSort(int16_t* point, uint8_t len);

#endif