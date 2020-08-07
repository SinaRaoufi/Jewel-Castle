#ifndef MOVE_IG
#define MOVE_IG

#include "Board.hpp"

bool isMoveValid(const Board &, size_t, size_t, size_t, size_t);
bool checkVerticalMove(const Board &, size_t, size_t, size_t, size_t);
bool checkHorizontalMove(const Board &, size_t, size_t, size_t, size_t);

#endif