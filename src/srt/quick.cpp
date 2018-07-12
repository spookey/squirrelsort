#include "quick.hpp"

void quickSort(int16_t* point, uint8_t lpos, uint8_t rpos) {
    uint8_t ll = lpos;
    uint8_t rr = rpos;

    uint8_t mid = floor((lpos + rpos) / 2);
    int16_t pivot = point[mid];

    while (ll <= rr) {
        while (point[ll] < pivot) {
            ll++;
        }

        while (point[rr] > pivot) {
            rr--;
        }

        if (ll <= rr) {
            int16_t tmp = point[ll];
            point[ll] = point[rr];
            point[rr] = tmp;
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
