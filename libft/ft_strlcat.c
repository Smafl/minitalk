/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:50:36 by ekulichk          #+#    #+#             */
/*   Updated: 2022/11/10 15:05:44 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	d_i;
	size_t	s_i;

	src_len = ft_strlen(src);
	if (size == 0 && dst == NULL)
		return (src_len);
	dst_len = ft_strlen(dst);
	s_i = 0;
	if (dst_len >= size)
		dst_len = size;
	d_i = dst_len;
	if (size > 0 && dst_len < (size - 1))
	{
		while ((dst_len + s_i) < (size - 1) && src[s_i] != '\0')
		{
			dst[d_i] = src[s_i];
			d_i++;
			s_i++;
		}
		dst[d_i] = '\0';
	}
	return (dst_len + src_len);
}
