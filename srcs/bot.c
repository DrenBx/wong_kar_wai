/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavanan <glavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:08:07 by glavanan          #+#    #+#             */
/*   Updated: 2015/03/01 17:03:15 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_kar_wai.h"

static int		**action_bot(int j, int i, int *lim, int **tab)
{
	while (i < 4)
	{
		if (i + 1 < 4 && tab[i + 1][j] == tab[i][j] && (i - 1) < *lim
				&& tab[i][j] != 0)
		{
			tab[i][j] = 0;
			tab[i + 1][j] *= 2;
			*lim = i - 1;
		}
		if (i + 1 < 4 && tab[i + 1][j] == 0 && tab[i][j] != 0)
		{
			tab[i + 1][j] = tab[i][j];
			tab[i][j] = 0;
		}
		i++;
	}
	return (tab);
}

void			bot(t_core *core)
{
	int		i;
	int		j;
	int		lim;

	i = 0;
	j = 0;
	while (j < 4)
	{
		lim = 5;
		i = 3;
		while (i >= 0)
		{
			core->tab = action_bot(j, i, &lim, core->tab);
			i--;
		}
		j++;
	}
	if (ft_valid_moove(core->tab, core->save))
	{
		core->tab = ft_random(core->tab);
		core->save = ft_save_save(core->tab, core->save);
		clear_all_win(core);
		win(core);
	}
}
