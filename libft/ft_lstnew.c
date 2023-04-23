/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:19:41 by ekulichk          #+#    #+#             */
/*   Updated: 2022/11/05 16:37:26 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst_new;

	lst_new = malloc(sizeof(t_list));
	if (!lst_new)
		return (NULL);
	lst_new->content = content;
	lst_new->next = NULL;
	return (lst_new);
}

// int	*ft_int_new(int content)
// {
// 	int *a;
// 	a = malloc(sizeof(int));
// 	*a = content;
// 	return (a);
// }