/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavanan <glavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:29:43 by glavanan          #+#    #+#             */
/*   Updated: 2015/03/01 17:30:13 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_kar_wai.h"

int		**ft_random(int **tab)
{
	int		ok;
	int		i;
	int		j;

	ok = 0;
	while (ok == 0)
	{
		i = rand() % 4;
		j = rand() % 4;
		if (tab[i][j] == 0)
		{
			if (rand() % 42 == 0)
				tab[i][j] = 4;
			else
				tab[i][j] = 2;
			ok = 1;
		}
	}
	return (tab);
}
