#include "bubble.hpp"

void bubbleSort(int16_t* point, uint8_t len) {
    for (uint8_t top = 0; top < len - 1; top++) {
        for (uint8_t idx = 0; idx < len - top - 1; idx++) {
            int16_t lo = point[idx];
            int16_t hi = point[idx + 1];
            if (lo > hi) {
                point[idx] = hi;
                point[idx + 1] = lo;
            }
        }
    }
}
