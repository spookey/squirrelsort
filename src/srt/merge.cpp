#include "merge.hpp"

void merge(int16_t* point, uint8_t lpos, uint8_t middle, uint8_t rpos) {
    uint8_t llen = middle - lpos + 1;
    uint8_t rlen = rpos - middle;

    int16_t* llist = new int16_t[llen];
    int16_t* rlist = new int16_t[rlen];

    for (uint8_t idx = 0; idx < llen; idx++) {
        llist[idx] = point[lpos + idx];
    }
    for (uint8_t idx = 0; idx < rlen; idx++) {
        rlist[idx] = point[middle + 1 + idx];
    }

    uint8_t ll = 0;
    uint8_t rr = 0;
    uint8_t pp = lpos;

    while (ll < llen && rr < rlen) {
        if (llist[ll] <= rlist[rr]) {
            point[pp] = llist[ll];
            ll++;
        }
        else {
            point[pp] = rlist[rr];
            rr++;
        }
        pp++;
    }

    while (ll < llen) {
        point[pp] = llist[ll];
        ll++;
        pp++;
    }
    while (rr < rlen) {
        point[pp] = rlist[rr];
        rr++;
        pp++;
    }

    delete [] llist;
    delete [] rlist;
}

void mergeSort(int16_t* point, uint8_t lpos, uint8_t rpos) {
    if (lpos < rpos) {
        uint8_t middle = floor((lpos + rpos) / 2);
        mergeSort(point, lpos, middle);
        mergeSort(point, middle + 1, rpos);

        merge(point, lpos, middle, rpos);
    }
}

void mergeSort(int16_t* point, uint8_t len) {
    mergeSort(point, 0, len - 1);
}
