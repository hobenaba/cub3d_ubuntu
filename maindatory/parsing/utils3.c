/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:29:17 by hobenaba          #+#    #+#             */
/*   Updated: 2023/08/10 10:36:16 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_comma(char *str)
{
	int	i;
	int	a;

	i = -1;
	a = 0;
	while (str[++i])
	{
		if (str[i] == ',')
			a++;
		if (a == 3)
			return (1);
	}
	return (0);
}

void	init(t_infos *cub)
{
	cub->map_col = NULL;
	cub->map_tex = NULL;
	cub->player = NULL;
}

int	space(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0 && str[i] == ' ')
		i--;
	return (i + 1);
}
