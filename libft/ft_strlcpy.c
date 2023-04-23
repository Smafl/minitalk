/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:52:20 by ekulichk          #+#    #+#             */
/*   Updated: 2022/10/19 14:37:22 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len_src;

	len_src = 0;
	while (src[len_src] != '\0')
	{
		if (len_src < size)
			dst[len_src] = src[len_src];
		len_src++;
	}
	if (size != 0)
	{
		if (len_src < size)
		{
			dst[len_src] = '\0';
		}
		else
		{
			dst[size - 1] = '\0';
		}
	}
	return (len_src);
}
