/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wong_kar_wai.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 00:38:55 by fkalb             #+#    #+#             */
/*   Updated: 2015/03/01 17:55:10 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WONG_KAR_WAI_H
# define WONG_KAR_WAI_H

# define MINSIZE_X (core->board_size_x * 14)
# define MINSIZE_Y (core->board_size_y * 6)

# include <ncurses.h>
# include <stdlib.h>
# include <time.h>
# include <stdio.h>

enum		e_const
{
	WIN_VALUE = 42
};

typedef struct	s_slot
{
	int	pos_x;
	int	pos_y;
	int	size_x;
	int	size_y;
	int	value;
	WINDOW	*win;
}		t_slot;

typedef struct	s_core
{
	int	width;
	int	height;
	int	board_size_x;
	int	board_size_y;
	t_slot	board[4][4];
	int	**tab;
	int	**save;
	int	end_game;
	int	victory_condition;
	int	winit;
}		t_core;

void		init(t_core *core);
void		game(void);
void		menu(t_core *core, int menu);
void		get_new_winsize(t_core *core, short int first_time);
void		clear_all_win(t_core *core);
int		ft_loose(int **tab);
int		**ft_init_tab(int **tab);
int		ft_valid_moove(int **tab, int **save);
int		**ft_random(int **tab);
int		**ft_save_save(int **tab, int **save);
void		bot(t_core *core);
void		top(t_core *core);
void		left(t_core *core);
void		right(t_core *core);
void		win(t_core *core);
void		ft_free(t_core *core);

#endif
