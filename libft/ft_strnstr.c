/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:14:21 by ekulichk          #+#    #+#             */
/*   Updated: 2022/11/10 15:10:41 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	haystack_i;
	size_t	needle_i;

	haystack_i = 0;
	if (haystack == NULL && len == 0)
		return (NULL);
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (haystack[0] == '\0' || len == 0)
		return (NULL);
	while (haystack_i < len && haystack[haystack_i])
	{
		needle_i = 0;
		while (haystack[haystack_i + needle_i] == needle[needle_i]
			&& (haystack_i + needle_i) <= len)
		{
			if (needle[needle_i + 1] == '\0'
				&& (haystack_i + needle_i + 1) <= len)
				return ((char *)haystack + haystack_i);
			needle_i++;
		}
		haystack_i++;
	}
	return (NULL);
}

/*
! check needle at first, there is no need to check it enymore 
1) haystack and needle are empty → haystack
2) needle is empty → haystack
3) haystack is empty (needle is not empty) → null
4) no needle in haystack → null
5) other → a pointer to the first character 
	of the first occurrence of needle

array[i] is the same as *(array + i)
if (!*needle)
if (*needle == 0) вместо if (needle[0] == '\0')
*/