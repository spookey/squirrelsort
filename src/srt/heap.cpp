#include "heap.hpp"

void heapify(int16_t* point, uint8_t len, uint8_t pos) {
    uint8_t top = pos;
    uint8_t ll = 2 * pos + 1;
    uint8_t rr = 2 * pos + 2;

    if (ll < len && point[ll] > point[top]) {
        top = ll;
    }
    if (rr < len && point[rr] > point[top]) {
        top = rr;
    }

    if (top != pos) {
        int16_t temp = point[top];
        point[top] = point[pos];
        point[pos] = temp;

        heapify(point, len, top);
    }
}

void heapSort(int16_t* point, uint8_t len) {
    for (uint8_t idx = floor(len / 2); idx > 0; idx--) {
        heapify(point, len, idx - 1);
    }
    for (uint8_t idx = len; idx > 0; idx--) {
        int16_t temp = point[idx - 1];
        point[idx - 1] = point[0];
        point[0] = temp;

        heapify(point, idx - 1, 0);
    }
}
