/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_save.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavanan <glavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 14:12:18 by glavanan          #+#    #+#             */
/*   Updated: 2015/03/01 17:04:07 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_kar_wai.h"

int			**ft_save_save(int **tab, int **save)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			save[i][j] = tab[i][j];
			j++;
		}
		i++;
	}
	return (save);
}
