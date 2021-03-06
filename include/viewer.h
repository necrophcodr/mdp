#if !defined( VIEWER_H )
#define VIEWER_H

/*
 * Functions necessary to display a deck of slides in different color modes
 * using ncurses. Only white, red, and blue are supported, as they can be
 * faded in 256 color mode.
 * Copyright (C) 2014 Michael Goehler
 *
 * This file is part of mdp.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 *
 * function: ncurses_display initializes ncurses, defines colors, calculates
 *           window geometry and handles key strokes
 * function: add_line detects inline markdown formating and prints line char
 *           by char
 * function: fade_in, fade_out implementing color fading in 256 color mode
 * function: int_length to calculate decimal length of slide count
 *
 */

#include <ncurses.h>

#include "parser.h"
#include "cstack.h"

#define CP_WHITE  1 // 255
#define CP_BLUE   2 // 123
#define CP_RED    3 // 213
#define CP_YELLOW 4 // 208

#define FADE_DELAY 15000 // micro seconds

int ncurses_display(deck_t *deck, int notrans, int nofade);
void add_line(WINDOW *window, int y, int x, line_t *line, int max_cols, int colors);
void fade_out(WINDOW *window, int trans, int colors);
void fade_in(WINDOW *window, int trans, int colors);
int int_length (int val);

#endif // !defined( VIEWER_H )
