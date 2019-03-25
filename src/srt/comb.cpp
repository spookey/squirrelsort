#include "comb.hpp"

void combSort(int16_t* point, uint32_t len) {
    uint32_t gap = len;
    bool swapped = true;

    while (gap != 1 || swapped == true) {

        int16_t tmp_gap = static_cast<int16_t>(floor((gap * 10) / 13));
        gap = (tmp_gap < 1 ? 1 : static_cast<uint32_t>(tmp_gap));

        swapped = false;

        for (uint32_t idx = 0; idx < len - gap; idx++) {
            if (point[idx] > point[idx + gap]) {
                std::swap(point[idx + gap], point[idx]);

                swapped = true;
            }
        }
    }
}
