#include "bubble.hpp"

void bubbleSort(int16_t* point, uint32_t len) {
    for (uint32_t top = 0; top < len - 1; top++) {
        for (uint32_t idx = 0; idx < len - top - 1; idx++) {
            int16_t lo = point[idx];
            int16_t hi = point[idx + 1];
            if (lo > hi) {
                point[idx] = hi;
                point[idx + 1] = lo;
            }
        }
    }
}
