#include "quick.hpp"

void quickSort(int16_t* point, uint32_t lpos, uint32_t rpos) {
    int64_t ll = lpos;
    int64_t rr = rpos;

    uint32_t mid = static_cast<uint32_t>(floor(lpos + (rpos - lpos) / 2));
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
        quickSort(point, lpos, static_cast<uint32_t>(rr));
    }
    if (ll < rpos) {
        quickSort(point, static_cast<uint32_t>(ll), rpos);
    }
}

void quickSort(int16_t* point, uint32_t len) {
    quickSort(point, 0, len - 1);
}
