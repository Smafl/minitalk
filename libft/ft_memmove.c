/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:48:32 by ekulichk          #+#    #+#             */
/*   Updated: 2022/11/09 17:16:16 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*pnt_dst;
	const char	*pnt_src;
	size_t		i;

	pnt_dst = (char *)dst;
	pnt_src = (const char *)src;
	i = 0;
	if (n == 0)
		return (dst);
	if (pnt_dst < pnt_src)
	{
		while (i < n)
		{
			pnt_dst[i] = pnt_src[i];
			i++;
		}
	}
	else if (pnt_dst > pnt_src)
	{
		while (n-- > 0)
		{
			pnt_dst[n] = pnt_src[n];
		}
	}
	return (dst);
}
