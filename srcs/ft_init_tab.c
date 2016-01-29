/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavanan <glavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:18:25 by glavanan          #+#    #+#             */
/*   Updated: 2015/03/01 17:08:08 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_kar_wai.h"

int		**ft_init_tab(int **tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = (int**)malloc(sizeof(int *) * 4);
	while (i < 4)
	{
		tab[i] = (int *)malloc(sizeof(int) * 4);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
	return (tab);
}
