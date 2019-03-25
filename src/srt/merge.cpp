#include "merge.hpp"

void merge(int16_t* point, uint32_t lpos, uint32_t middle, uint32_t rpos) {
    uint32_t llen = middle - lpos + 1;
    uint32_t rlen = rpos - middle;

    int16_t* llist = new int16_t[llen];
    int16_t* rlist = new int16_t[rlen];

    for (uint32_t idx = 0; idx < llen; idx++) {
        llist[idx] = point[lpos + idx];
    }
    for (uint32_t idx = 0; idx < rlen; idx++) {
        rlist[idx] = point[middle + 1 + idx];
    }

    uint32_t ll = 0;
    uint32_t rr = 0;
    uint32_t pp = lpos;

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

void mergeSort(int16_t* point, uint32_t lpos, uint32_t rpos) {
    if (lpos < rpos) {
        uint32_t middle = static_cast<uint32_t>(floor((lpos + rpos) / 2));
        mergeSort(point, lpos, middle);
        mergeSort(point, middle + 1, rpos);

        merge(point, lpos, middle, rpos);
    }
}

void mergeSort(int16_t* point, uint32_t len) {
    mergeSort(point, 0, len - 1);
}
