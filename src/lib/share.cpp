#include "share.hpp"

void initRnd(void) {
    srand(time(NULL));
}


void printEnd(void) {
    std::cout << std::endl;
}

void printText(std::string text) {
    std::cout << std::endl << text << ":";
}

void printTime(std::string text, double time) {
    printText(text);
    std::cout << "\t" <<
        std::setw(FMT_TIME) <<
        std::setprecision(PRC_TIME) <<
        time;
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
    printText(text);
    printList(point, len);
}


void copyList(int16_t* origin, int16_t* duplicate, uint32_t len) {
    while (len--) {
        duplicate[len] = origin[len];
    }
}


bool checkList(int16_t* origin, uint32_t len) {
    for (uint32_t idx = 1; idx < len; idx++) {
        if (origin[idx] < origin[idx - 1]) {
            return false;
        }
    }
    return true;
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


HIGH_POINT startTime(void) {
    return std::chrono::high_resolution_clock::now();
}

double stopTime(HIGH_POINT start) {
    return (startTime() - start).count();
}
