/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:25:44 by hobenaba          #+#    #+#             */
/*   Updated: 2023/08/01 13:39:48 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	check_len(char **str, int i)
{
	int	j;
	int	a;

	j = 0;
	while (str[i])
	{
		a = ft_strlen (str[i]);
		if (a > j)
			j = a;
		i++;
	}
	return (j);
}

char	*add_space_to_str(char *str, int a)
{
	char		*s1;
	int			i;

	i = -1;
	s1 = malloc (sizeof(char) * (a + 1));
	while (str[++i])
		s1[i] = str[i];
	i--;
	while (++i < a)
		s1[i] = ' ';
	s1[i] = '\0';
	return (s1);
}

char	**save_this_map(char **str, int i)
{
	int		j;
	char	**dup;
	char	*s1;
	int		a;

	j = 0;
	dup = malloc(sizeof(char *) * (dl_strlen(str, i) + 1));
	a = check_len(str, i);
	while (str[i])
	{
		s1 = add_space_to_str(str[i], a);
		dup[j] = ft_strdup(s1);
		i++;
		j++;
		free (s1);
	}
	dup[j] = NULL;
	return (dup);
}

void	save_player(int i, int j, t_infos2 **player, char c)
{
	(*player)->type = ft_substr(&c, 0, 1);
	(*player)->info[0] = i;
	(*player)->info[1] = j;
	(*player)->next = NULL;
}

int	dl_strlen(char **str, int i)
{
	int	j;

	j = 0;
	while (str[i])
	{
		i++;
		j++;
	}
	return (j);
}
