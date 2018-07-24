#include "selection.hpp"

void selectionSort(int16_t* point, uint8_t len) {
    for (uint8_t idx = 0; idx < len - 1; idx++) {
        uint8_t min = idx;
        for (uint8_t pos = idx + 1; pos < len; pos++) {
            if (point[pos] < point[min]) {
                min = pos;
            }
        }

        if (min != idx) {
            std::swap(point[idx], point[min]);
        }
    }
}
