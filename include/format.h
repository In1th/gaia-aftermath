/* ===========================================
 * format.h file
 * ===========================================
 * author: Mateusz Kruk
 * e-mail: krukm634@gmail.com
 * last modified: 25.05.2021
 * ===========================================
 * version: 0.1.0-a.1 [backpack]
 * ===========================================
 */

#ifndef FORMAT_H

#define FORMAT_H

#include <iostream>

#define print std::cout
#define eol std::endl

/*Name            FG  BG
Black           30  40
Red             31  41
Green           32  42
Yellow          33  43
Blue            34  44
Magenta         35  45
Cyan            36  46
White           37  47
Bright Black    90  100
Bright Red      91  101
Bright Green    92  102
Bright Yellow   93  103
Bright Blue     94  104
Bright Magenta  95  105
Bright Cyan     96  106
Bright White    97  107
 */

#define DEBUG "\033[1m[\033[91m DEBUG\033[37m ]\033[0m"
#define WARNING "\033[1m[\033[31m OSTRZEŻENIE\033[37m ]\033[0m"
#define ERROR "\033[1m[\033[31m BŁĄD\033[37m ]\033[0m"
#define INFO "\033[1m[\033[34m INFORMACJA\033[37m ]\033[0m"
#define SUCCESS "\033[1m[\033[32m UDANE\033[37m ]\033[0m"

#define EKWIPUNEK "\033[1m[\033[35m EKWIPUNEK\033[37m ]\033[0m"

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

#define BRIGHT_BLACK "\033[90m"
#define BRIGHT_RED "\033[91m"
#define BRIGHT_GREEN "\033[92m"
#define BRIGHT_YELLOW "\033[93m"
#define BRIGHT_BLUE "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN "\033[96m"
#define BRIGHT_WHITE "\033[97m"

#define NORMAL "\033[0m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"
#define FLASHING "\033[5m"
#define INVERSE "\033[7m"
#define CLEAR "\033c"

#define c_goto(x,y) \033[x:yH

#define line(x)                            \
    for (int i = 0; i < x; i++){           \
        print <<  "\u2500";                \
    }                                      \
    print << eol

#endif