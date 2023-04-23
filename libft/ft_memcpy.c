/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:43:42 by ekulichk          #+#    #+#             */
/*   Updated: 2022/11/09 17:23:58 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*pnt_dst;
	const unsigned char	*pnt_src;
	size_t				i;

	pnt_src = src;
	pnt_dst = dst;
	i = 0;
	if (dst == src)
		return (dst);
	while (i < n)
	{
		pnt_dst[i] = pnt_src[i];
		i++;
	}
	return (dst);
}
