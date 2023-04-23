/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:39:40 by ekulichk          #+#    #+#             */
/*   Updated: 2022/11/09 14:11:16 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*result;

	if (size && size * count / size != count)
		return (NULL);
	result = malloc(size * count);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, size * count);
	return (result);
}

/*
if (!result)
	return (0);
need with every malloc using

if (size && size * count / size == count)
if (size && SIZE_MAX / size >= count)
*/