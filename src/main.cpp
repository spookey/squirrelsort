#include "main.hpp"

bool compute(
        int16_t* origin, uint32_t len, bool prepare,
        void (*sort)(int16_t* , uint32_t),
        std::string text
) {
    int16_t *target = new int16_t[len];
    copyList(origin, target, len);
    HIGH_POINT start = startTime();
    sort(target, len);
    double elapsed = stopTime(start);
    bool result = checkList(target, len);

        std::string sres =
            std::string("(") +
            (result ? "ok" : "error") +
            std::string(") - ") +
            text;
    if (prepare) {
        printList(sres, target, len);
    } else {
        printTime(sres, elapsed);
    }

    delete [] target;
    return result;
}


void action(int16_t* origin, uint32_t len, bool prepare) {
    if (prepare) {
        printList("input data", origin, len);
    } else {
        printTime("input length", len);
    }

    compute(origin, len, prepare, bubbleSort, "bubble");
    compute(origin, len, prepare, combSort, "comb");
    compute(origin, len, prepare, heapSort, "heap");
    compute(origin, len, prepare, insertionSort, "insert");
    compute(origin, len, prepare, mergeSort, "merge");
    compute(origin, len, prepare, quickSort, "quick");
    compute(origin, len, prepare, selectionSort, "select");
    compute(origin, len, prepare, shellSort, "shell");

    printEnd();
}


void printer(void) {
    uint32_t len = DISPLAY_LENGTH;
    int16_t *origin = new int16_t[len];

    makeListRev(origin, len);
    action(origin, len, true);

    makeListNeg(origin, len);
    action(origin, len, true);

    for (
        uint8_t peakPos = 0;
        peakPos < sizeof(peaksRnd)/sizeof(uint16_t);
        peakPos++
    ) {
        makeListRnd(origin, len, peaksRnd[peakPos]);
        action(origin, len, true);
    }

    delete [] origin;

    printEnd();
}

void marker(void) {
    for (
        uint8_t lenPos = 0;
        lenPos < sizeof(lensBench)/sizeof(uint32_t);
        lenPos++
    ) {
        uint32_t len = lensBench[lenPos];
        int16_t *origin = new int16_t[len];

        makeListRnd(origin, len, peaksRnd[2]);
        action(origin, len, false);

        delete [] origin;
    }

    printEnd();
}


int32_t main(int32_t argc, char** argv) {
    (void)argc;
    (void)argv;

    initRnd();

    printer();
    marker();

    printEnd();

    return EXIT_SUCCESS;
}
