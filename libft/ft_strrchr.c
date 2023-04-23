/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:27:44 by ekulichk          #+#    #+#             */
/*   Updated: 2022/11/10 12:58:45 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (i > -1)
	{
		if (*(s + i) == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (0);
}

// char	*ft_strrchr(const char *s, int c)
// {
// 	char	*pnt_s;
// 	int		i;

// 	pnt_s = (char *) s;
// 	i = ft_strlen(pnt_s);
// 	while (i > -1)
// 	{
// 		if (pnt_s[i] == (char)c)
// 			return (&pnt_s[i]);
// 		i--;
// 	}
// 	return (0);
// }
