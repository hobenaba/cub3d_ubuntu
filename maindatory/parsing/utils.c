/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenabad <hbenabad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:25:32 by hobenaba          #+#    #+#             */
/*   Updated: 2023/08/10 10:44:08 by hbenabad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	print_error(int num)
{
	if (num == 0)
		printf("Error\nEmpty file\n");
	else if (num == 1)
		printf("Error\nwrong map format\n");
	else if (num == 2)
		printf("Error\nwrong number of textures\n");
	else if (num == 3)
		printf("Error\nwrong number of colors\n");
	else if (num == 4)
		printf ("Error\nRGB range is false\n");
	else if (num == 5)
		printf ("Error\nno player available\n");
	else if (num == 6)
		printf("Error\nusage of a forbidden char\n");
	else if (num == 7)
		printf("Error\nthere is multiple players\n");
	else if (num == 8)
		printf("Error\nThe map is not surrounded by walls\n");
	else if (num == 9)
		printf ("Error\nThis Map doesn't exit\n");
	else if (num == 10)
		printf ("Error\none of the xpm files doesn't exit\n");
	else
		printf ("Error\nThe map is invalid\n");
	exit (1);
}

char	*bring_last_dot(char *map)
{
	int	i;

	i = ft_strlen(map) -1;
	while (i >= 0)
	{
		if (map[i] == '.')
			return (map + i);
		i--;
	}
	return (NULL);
}

int	my_countnbr(int n)
{
	int	j;

	j = 0;
	if (n <= 0)
		j++;
	while (n != 0)
	{
		n /= 10;
		j++;
	}
	return (j);
}

int	ft_check_space(char *str)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	if (str == NULL)
		return (a);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n')
			a++;
		i++;
	}
	return (a);
}

char	*the_process(char *str, int fd)
{
	int		a;
	char	*s1;

	s1 = NULL;
	a = 0;
	while (str != NULL)
	{
		if (a == 0 && ft_strcmp(str, "\n") && !ft_check_space(str))
			print_error(11);
		if (a == 0 && (!ft_strcmp(str, "\n")))
		{
			free (str);
			str = get_next_line(fd);
		}
		if (a == 1 && !ft_strcmp(str, "\n"))
			print_error(11);
		if (str != NULL && ft_atoi (str) != 0)
			a = 1;
		if ((a == 0 && (ft_strcmp(str, "\n") && ft_check_space(str))) || a == 1)
			s1 = ft_strjoin(s1, str);
		free (str);
		str = get_next_line(fd);
	}
	return (s1);
}
