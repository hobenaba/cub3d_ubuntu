/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:33:23 by hobenaba          #+#    #+#             */
/*   Updated: 2023/08/11 12:13:04 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	algo(char **map, int i, int j, int base)
{
	if (i < 0 || j < 0 || i >= dl_strlen(map, 0) || j >= ft_strlen(map[i]))
		print_error(8);
	if (base == 0 && map[i][j] == ' ')
		print_error(11);
	if (map[i][j] == '1' || map[i][j] == 'J')
		return ;
	else
	{
		map[i][j] = 'J';
		algo(map, i + 1, j, base);
		algo(map, i - 1, j, base);
		algo(map, i, j + 1, base);
		algo(map, i, j - 1, base);
	}
}

int	empty_space(char **map, int *info)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("0NSWE", map[i][j]))
			{
				info[0] = i;
				info[1] = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	check_walls(char **map, t_infos2 *player)
{
	int	*info;

	info = malloc(sizeof(int) * 2);
	algo(map, player->info[0], player->info[1], 0);
	while (empty_space(map, info))
	{
		algo(map, info[0], info[1], 1);
		free(info);
		info = malloc(sizeof(int) * 2);
	}
	free(info);
	free_dlptr(map);
}

void	check_map_format(char *map)
{
	char	*s1;

	s1 = bring_last_dot(map);
	if (s1 == NULL || ft_strcmp(s1, ".cub"))
		print_error(1);
}
