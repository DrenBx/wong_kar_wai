/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavanan <glavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 17:28:38 by glavanan          #+#    #+#             */
/*   Updated: 2015/03/01 17:48:28 by glavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_kar_wai.h"

void		ft_free(t_core *core)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		free(core->tab[i]);
		free(core->save[i]);
		i++;
	}
	free(core->save);
	free(core->tab);
}
