#include "heap.hpp"

void heapify(int16_t* point, uint32_t len, uint32_t pos) {
    uint32_t top = pos;
    uint32_t ll = 2 * pos + 1;
    uint32_t rr = 2 * pos + 2;

    if (ll < len && point[ll] > point[top]) {
        top = ll;
    }
    if (rr < len && point[rr] > point[top]) {
        top = rr;
    }

    if (top != pos) {
        std::swap(point[top], point[pos]);

        heapify(point, len, top);
    }
}

void heapSort(int16_t* point, uint32_t len) {
    for (uint32_t idx = floor(len / 2); idx > 0; idx--) {
        heapify(point, len, idx - 1);
    }
    for (uint32_t idx = len; idx > 0; idx--) {
        std::swap(point[idx - 1], point[0]);

        heapify(point, idx - 1, 0);
    }
}
