/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:01:02 by ekulichk          #+#    #+#             */
/*   Updated: 2022/11/09 16:04:28 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*pnt_s1;
	unsigned char	*pnt_s2;
	size_t			i;

	pnt_s1 = (unsigned char *)s1;
	pnt_s2 = (unsigned char *)s2;
	i = 0;
	while (i != n)
	{
		if (pnt_s1[i] != pnt_s2[i])
		{
			return (pnt_s1[i] - pnt_s2[i]);
		}
		i++;
	}
	return (0);
}
