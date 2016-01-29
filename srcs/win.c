/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavanan <glavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:22:43 by glavanan          #+#    #+#             */
/*   Updated: 2015/03/01 17:17:29 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_kar_wai.h"

void		win(t_core *core)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (core->winit)
		return ;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (core->tab[i][j] == core->victory_condition)
			{
				core->winit = 1;
				core->end_game = 2;
			}
			j++;
		}
		i++;
	}
}
