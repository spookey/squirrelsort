#include "shell.hpp"

void shellSort(int16_t* point, uint32_t len) {
    for (uint32_t gap = floor(len / 2); gap > 0; gap = floor(gap / 2)) {
        for (uint32_t idx = gap; idx < len; idx++) {
            int16_t temp = point[idx];
            uint32_t pos = idx;

            while (pos >= gap && point[pos - gap] > temp) {
                point[pos] = point[pos - gap];
                pos -= gap;
            }

            point[pos] = temp;
        }
    }
}
