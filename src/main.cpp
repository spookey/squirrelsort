#include "main.hpp"

bool compute(
        int16_t* origin, uint32_t len,
        void (*sort)(int16_t* , uint32_t),
        std::string text
) {
    int16_t *target = new int16_t[len];
    copyList(origin, target, len);
    sort(target, len);
    bool result = checkList(origin, len);

    std::string sres =
        std::string("(") +
        (result ? "ok" : "error") +
        std::string(") - ") +
        text;
    printList(sres, target, len);

    delete [] target;
    return result;
}


void action(int16_t* origin, uint32_t len) {
    printList("unsorted", origin, len);

    compute(origin, len, bubbleSort, "bubble");
    compute(origin, len, combSort, "comb");
    compute(origin, len, heapSort, "heap");
    compute(origin, len, insertionSort, "insertion");
    compute(origin, len, mergeSort, "merge");
    compute(origin, len, quickSort, "quick");
    compute(origin, len, selectionSort, "selection");
    compute(origin, len, shellSort, "shell");

    std::cout << std::endl;
}


int32_t main(int32_t argc, char** argv) {
    (void)argc;
    (void)argv;

    initRnd();

    int16_t *origin = new int16_t[ARR_LENGTH];

    makeListRev(origin, ARR_LENGTH);
    action(origin, ARR_LENGTH);

    makeListNeg(origin, ARR_LENGTH);
    action(origin, ARR_LENGTH);

    int16_t peaks[3] = {99, 999, 9999};

    for (uint8_t pp = 0; pp < 3; pp++) {
        makeListRnd(origin, ARR_LENGTH, peaks[pp]);
        action(origin, ARR_LENGTH);
    }

    delete [] origin;

    std::cout << std::endl << std::endl;
    return EXIT_SUCCESS;
}
