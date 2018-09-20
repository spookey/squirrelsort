#include "shell.hpp"

void shellSort(int16_t* point, uint8_t len) {
    for (uint8_t gap = floor(len / 2); gap > 0; gap = floor(gap / 2)) {
        for (uint8_t idx = gap; idx < len; idx++) {
            int16_t temp = point[idx];
            uint8_t pos = idx;

            while (pos >= gap && point[pos - gap] > temp) {
                point[pos] = point[pos - gap];
                pos -= gap;
            }

            point[pos] = temp;
        }
    }
}
