#include "quick.hpp"

void quickSort(int16_t* point, uint8_t lpos, uint8_t rpos) {
    int16_t ll = lpos;
    int16_t rr = rpos;

    uint8_t mid = floor(lpos + (rpos - lpos) / 2);
    int16_t pivot = point[mid];

    while (ll <= rr) {
        while (point[ll] < pivot) {
            ll++;
        }

        while (point[rr] > pivot) {
            rr--;
        }

        if (ll <= rr) {
            std::swap(point[ll], point[rr]);
            ll++;
            rr--;
        }
    }

    if (lpos < rr) {
        quickSort(point, lpos, rr);
    }
    if (ll < rpos) {
        quickSort(point, ll, rpos);
    }
}

void quickSort(int16_t* point, uint8_t len) {
    quickSort(point, 0, len - 1);
}
