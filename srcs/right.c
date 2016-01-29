/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavanan <glavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:09:06 by glavanan          #+#    #+#             */
/*   Updated: 2015/03/01 17:05:43 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_kar_wai.h"

static int		**action_right(int j, int i, int *lim, int **tab)
{
	while (j < 4)
	{
		if (j + 1 < 4 && tab[i][j + 1] == tab[i][j] && (j - 1) < *lim
				&& tab[i][j] != 0)
		{
			tab[i][j] = 0;
			tab[i][j + 1] *= 2;
			*lim = j - 1;
		}
		if (j + 1 < 4 && tab[i][j + 1] == 0 && tab[i][j] != 0)
		{
			tab[i][j + 1] = tab[i][j];
			tab[i][j] = 0;
		}
		j++;
	}
	return (tab);
}

void			right(t_core *core)
{
	int			i;
	int			j;
	int			lim;

	i = 0;
	j = 0;
	while (i < 4)
	{
		lim = 5;
		j = 3;
		while (j >= 0)
		{
			core->tab = action_right(j, i, &lim, core->tab);
			j--;
		}
		i++;
	}
	if (ft_valid_moove(core->tab, core->save))
	{
		core->tab = ft_random(core->tab);
		core->save = ft_save_save(core->tab, core->save);
		clear_all_win(core);
		win(core);
	}
}
