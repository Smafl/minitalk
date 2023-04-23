/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:24:41 by ekulichk          #+#    #+#             */
/*   Updated: 2022/10/25 13:47:31 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*pnt_s;
	size_t	i;

	pnt_s = (char *)s;
	i = 0;
	while (i < n)
	{
		if (pnt_s[i] == (char)c)
			return (&pnt_s[i]);
		i++;
	}
	return (0);
}
