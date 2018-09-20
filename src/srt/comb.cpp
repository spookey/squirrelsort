#include "comb.hpp"

void combSort(int16_t* point, uint8_t len) {
    uint8_t gap = len;
    bool swapped = true;

    while (gap != 1 || swapped == true) {

        int16_t tmp_gap = floor((gap * 10) / 13);
        gap = (tmp_gap < 1 ? 1 : (uint8_t) tmp_gap);

        swapped = false;

        for (uint8_t idx = 0; idx < len - gap; idx++) {
            if (point[idx] > point[idx + gap]) {
                std::swap(point[idx + gap], point[idx]);

                swapped = true;
            }
        }
    }
}
