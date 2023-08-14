/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:18:09 by hobenaba          #+#    #+#             */
/*   Updated: 2023/08/04 10:53:37 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

t_infos1	*ft_lstnew(char *type, char *info)
{
	t_infos1	*p;

	p = malloc(sizeof (t_infos));
	if (!p)
		return (NULL);
	p -> type = ft_strdup(type);
	p -> info = info;
	p -> next = NULL;
	return (p);
}

void	ft_lstaddback(t_infos1 **lst, t_infos1 *new)
{
	t_infos1	*p;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	p = *lst;
	if (!p)
		return ;
	while (p-> next)
		p = p -> next;
	p -> next = new;
}

t_infos2	*ft_lstnew2(char *type, int *info)
{
	t_infos2	*p;

	p = malloc(sizeof (t_infos2));
	if (!p)
		return (NULL);
	p -> type = ft_strdup(type);
	p -> info = info;
	p -> next = NULL;
	return (p);
}

void	ft_lstaddback2(t_infos2 **lst, t_infos2 *new)
{
	t_infos2	*p;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	p = *lst;
	if (!p)
		return ;
	while (p-> next)
		p = p -> next;
	p -> next = new;
}
