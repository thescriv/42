/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_visualizer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aetchego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:36:50 by aetchego          #+#    #+#             */
/*   Updated: 2018/12/10 18:38:52 by aetchego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	init_infos(void)
{
	int	margin_left;
	int	margin_top;

	margin_left = COLS / 3 * 2;
	margin_top = 20;
	attron(COLOR_PAIR(6) | A_BOLD);
	move(margin_top, margin_left);
	printw("NUMBER OF PLAYERS");
	move(margin_top + 4, margin_left);
	printw("NUMBER OF PROCESS");
	move(margin_top + 8, margin_left);
	printw("NUMBER OF LIVES");
	move(margin_top + 12, margin_left);
	printw("CYCLES TO DIE");
	move(margin_top + 16, margin_left);
	printw("CYCLES LEFT");
	move(margin_top + 20, margin_left);
	printw("CYCLES TOTAL");
	move(margin_top + 24, margin_left);
	printw("CHECKS");
	refresh();
}

void	initialiser(void)
{
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	refresh();
	nodelay(stdscr, 0);
	curs_set(FALSE);
}

void	init_colors(void)
{
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_RED);
	init_pair(3, COLOR_BLACK, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
	init_pair(6, COLOR_RED, COLOR_BLACK);
	init_pair(7, COLOR_YELLOW, COLOR_BLACK);
	init_pair(8, COLOR_CYAN, COLOR_BLACK);
	init_pair(9, COLOR_GREEN, COLOR_GREEN);
	init_pair(10, COLOR_RED, COLOR_RED);
	init_pair(11, COLOR_BLACK, COLOR_YELLOW);
}

void	init_windows(WINDOW *win, WINDOW *win_left,
WINDOW *win_right, WINDOW *win_down)
{
	win = newwin(LINES, COLS, 0, 0);
	wbkgd(win, COLOR_PAIR(2));
	wrefresh(win);
	win_left = subwin(win, 66, 195, 1, 2);
	wbkgd(win_left, COLOR_PAIR(1));
	wrefresh(win_left);
	win_right = subwin(win, 66, 164, 1, 200);
	wbkgd(win_right, COLOR_PAIR(1));
	wrefresh(win_right);
	win_down = subwin(win, LINES - 68, COLS, 68, 0);
	wbkgd(win_down, COLOR_PAIR(1));
	wrefresh(win_down);
}

void	create_visualizer(t_vm *vm, t_win *display)
{
	initialiser();
	init_colors();
	init_windows(display->win, display->win_left, display->win_right,
	display->win_down);
	init_infos();
	init_players(vm);
	vm->speed = 0;
	getch();
	nodelay(stdscr, 1);
}
