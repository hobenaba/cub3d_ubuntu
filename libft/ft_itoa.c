/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:37:19 by hobenaba          #+#    #+#             */
/*   Updated: 2022/11/04 19:46:18 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_signe(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
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

char	*ft_itoa(int n)
{
	char	*p;
	int		i;
	int		res;
	int		a;

	res = 0;
	a = 0;
	i = my_countnbr(n);
	p = malloc(sizeof(char) * (my_countnbr(n) + 1));
	if (!p)
		return (NULL);
	p[my_countnbr(n)] = '\0';
	if (n < 0)
	{
		p[0] = '-';
		a = 1;
	}
	while (--i >= a)
	{
		res = ft_signe(n % 10);
		p[i] = res + '0';
		n /= 10;
	}
	return (p);
}
