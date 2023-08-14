/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:14:21 by hobenaba          #+#    #+#             */
/*   Updated: 2023/08/04 15:40:32 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	free_tex(t_infos1 *map_tex)
{
	t_infos1	*p;

	while (map_tex)
	{
		free(map_tex->type);
		free(map_tex->info);
		p = (map_tex)->next;
		free(map_tex);
		map_tex = p;
	}
}

void	free_col(t_infos2 *map_col)
{
	t_infos2	*p;

	while (map_col)
	{
		free(map_col->type);
		free(map_col->info);
		p = (map_col)->next;
		free(map_col);
		map_col = p;
	}
}

void	free_dlptr(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
