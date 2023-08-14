/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:35:43 by hobenaba          #+#    #+#             */
/*   Updated: 2023/08/10 21:10:09 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	check_col_valid(t_infos2 *map_col)
{
	t_infos2	*p;
	int			a;
	int			b;

	p = map_col;
	a = 0;
	b = 0;
	while (p)
	{
		if (a == 0 && !ft_strcmp(p ->type, "F"))
			a++;
		else
			b++;
		p = p->next;
	}
	if (a != 1 || b != 1)
		print_error(3);
	if (check_rgb(map_col))
		print_error(4);
}

int	check_rgb(t_infos2 *map_col)
{
	t_infos2	*p;
	int			j;

	p = map_col;
	while (p)
	{
		j = 0;
		while (j < 3)
		{
			if (p->info[j] > 255 || p->info[j] < 0)
				return (1);
			j++;
		}
		p = p->next;
	}
	return (0);
}

void	check_tex_valid(t_infos1 *map_tex)
{
	t_infos1	*p;
	t_helper	h;

	p = map_tex;
	h.a = 0;
	h.b = 0;
	h.c = 0;
	h.d = 0;
	h.e = 0;
	while (p)
	{
		if (h.a == 0 && !ft_strcmp(p ->type, "NO"))
			h.a++;
		else if (h.b == 0 && !ft_strcmp(p ->type, "SO"))
			h.b++;
		else if (h.c == 0 && !ft_strcmp(p ->type, "WE"))
			h.c++;
		else if (h.d == 0 && !ft_strcmp(p ->type, "EA"))
			h.d++;
		else
			h.e++;
		p = p->next;
	}
	if (h.a != 1 || h.b != 1 || h.c != 1 || h.d != 1 || h.e != 0)
		print_error(2);
}

int	just_check(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_strchr("NSWE01 ", str[i]))
			return (1);
	}
	return (0);
}

void	check_char(char **str, int i, t_infos2 **player)
{
	int	j;
	int	a;
	int	b;

	a = 5;
	while (str[i])
	{
		j = -1;
		b = just_check(str[i]);
		while (str[i][++j])
		{
			if (b)
				print_error(6);
			if (ft_strchr("NSWE", str[i][j]))
			{
				a++;
				if (a != 6)
					print_error(a);
				save_player(i, j, player, str[i][j]);
			}
		}
		i++;
	}
	if (a != 6)
		print_error(a);
}
