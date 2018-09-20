#include "share.hpp"

void initRnd(void) {
    srand(time(NULL));
}


void printList(int16_t* point, uint32_t len) {
    std::cout << std::endl << "[ ";
    for (uint32_t idx = 0; idx < len; idx++) {
        std::cout << std::setw(FMT_SPACE) << point[idx] << (
            1 + idx != len ? ", " : " ]"
        );
    }
    std::cout << std::flush;
}

void printList(std::string text, int16_t* point, uint32_t len) {
    std::cout << std::endl << text << ":";
    printList(point, len);
}


void copyList(int16_t* origin, int16_t* duplicate, uint32_t len) {
    while (len--) {
        duplicate[len] = origin[len];
    }
}


void makeListRev(int16_t* origin, uint32_t len) {
    for (uint32_t idx = 0; idx < len; idx++) {
        origin[idx] = len - idx - 1;
    }
}

void makeListNeg(int16_t* origin, uint32_t len) {
    for (uint32_t idx = 0; idx < len; idx++) {
        origin[idx] = -idx;
    }
}

void makeListRnd(int16_t* origin, uint32_t len, uint16_t peak) {
    for (uint32_t idx = 0; idx < len; idx++) {
        origin[idx] = (
            rand() % peak * (rand() % 2 ? -1 : +1)
        );
    }
}
