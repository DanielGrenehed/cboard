#ifndef COLORS_H
#define COLORS_H

#ifdef COLORS

#define C_DEF "\x1B[0m"
#define C_RED "\x1B[31m"
#define C_GRN "\x1B[32m"
#define C_YLW "\x1B[33m"
#define C_BLU "\x1B[34m"
#define C_MAG "\x1B[35m"
#define C_CYN "\x1B[36m"
#define C_WHT "\x1B[37m"

#else

#define C_DEF ""
#define C_RED ""
#define C_GRN ""
#define C_YLW ""
#define C_BLU ""
#define C_MAG ""
#define C_CYN ""
#define C_WHT ""

#endif

#endif /* ifndef COLORS_H */
