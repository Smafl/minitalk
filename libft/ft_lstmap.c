/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:35 by ekulichk          #+#    #+#             */
/*   Updated: 2022/11/08 18:31:00 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*temp_node;

	if (!lst)
		return (NULL);
	temp_node = ft_lstnew(f(lst->content));
	if (!temp_node)
		return (NULL);
	result = temp_node;
	lst = lst->next;
	while (lst)
	{
		temp_node->next = ft_lstnew(f(lst->content));
		if (!temp_node->next)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		temp_node = temp_node->next;
		lst = lst->next;
	}
	temp_node->next = NULL;
	return (result);
}
