#include "insertion.hpp"

void insertionSort(int16_t* point, uint32_t len) {
    for (uint32_t idx = 1; idx < len; idx++) {
        int16_t temp = point[idx];

        uint32_t pos = idx;
        while (pos > 0 && point[pos - 1] > temp) {
            point[pos] = point[pos - 1];
            pos--;
        }
        point[pos] = temp;
    }
}
