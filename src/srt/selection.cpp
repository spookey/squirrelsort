#include "selection.hpp"

void selectionSort(int16_t* point, uint32_t len) {
    for (uint32_t idx = 0; idx < len - 1; idx++) {
        uint32_t min = idx;
        for (uint32_t pos = idx + 1; pos < len; pos++) {
            if (point[pos] < point[min]) {
                min = pos;
            }
        }

        if (min != idx) {
            std::swap(point[idx], point[min]);
        }
    }
}
