#include "main.hpp"

void compute(
        int16_t* origin, uint32_t len,
        std::string text, void (*sort)(int16_t* , uint32_t)
) {
    int16_t *result = new int16_t[len];
    copyList(origin, result, len);
    sort(result, len);
    printList(text, result, len);
    delete [] result;
}


void action(int16_t* origin, uint32_t len) {
    printList("unsorted", origin, len);

    compute(origin, len, "bubble", bubbleSort);
    compute(origin, len, "comb", combSort);
    compute(origin, len, "heap", heapSort);
    compute(origin, len, "insertion", insertionSort);
    compute(origin, len, "merge", mergeSort);
    compute(origin, len, "quick", quickSort);
    compute(origin, len, "selection", selectionSort);
    compute(origin, len, "shell", shellSort);

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
