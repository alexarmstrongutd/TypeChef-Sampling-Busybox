#ifndef LIBART_MULTILIB
#define LIBART_MULTILIB

#include <bits/wordsize.h>

#if __WORDSIZE == 32
# include "art_config-32.h"
#elif __WORDSIZE == 64
# include "art_config-64.h"
#else
# error "unexpected value for __WORDSIZE macro"
#endif

#endif 
