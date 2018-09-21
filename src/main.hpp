#ifndef __main_hpp__
#define __main_hpp__

#include "lib/share.hpp"
#include "srt/bubble.hpp"
#include "srt/comb.hpp"
#include "srt/heap.hpp"
#include "srt/insertion.hpp"
#include "srt/merge.hpp"
#include "srt/quick.hpp"
#include "srt/selection.hpp"
#include "srt/shell.hpp"


bool compute(
        int16_t* origin, uint32_t len,
        void (*sort)(int16_t* , uint32_t),
        std::string text
);
void action(int16_t* origin, uint32_t len);

int32_t main(int32_t argc, char** argv);

#endif
