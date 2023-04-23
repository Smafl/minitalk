/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:51:31 by ekulichk          #+#    #+#             */
/*   Updated: 2022/11/10 14:41:44 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	len_s;

	if (s == NULL)
		return (NULL);
	i = 0;
	len_s = ft_strlen(s);
	if (len_s - start < len)
		len = len_s - start;
	result = malloc(sizeof(char) * (len * (len_s >= start) + 1));
	if (result == NULL)
		return (NULL);
	result[0] = '\0';
	if (len_s < start)
		return (result);
	while (i < len)
	{
		result[i] = s[start];
		i++;
		start++;
	}
	result[i] = '\0';
	return (result);
}

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*result;
// 	size_t	i;
// 	size_t	len_s;

// 	i = 0;
// 	len_s = ft_strlen(s);
// 	if (len_s - start < len)
// 	len = len_s - start;
// 	result = malloc(sizeof(char) * (len + 1));
// 	if (len_s < start)
// 		return (result);
// 	if (!result)
// 		return (NULL);
// 	while (i < len)
// 	{
// 		result[i] = s[start];
// 		i++;
// 		start++;
// 	}
// 	result[i] = '\0';
// 	return (result);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char			*result;
// 	size_t			i;
// 	size_t			j;
// 	size_t			len_s;

// 	i = 0;
// 	len_s = ft_strlen(s);
// 	if (len_s > len)
// 		len_s = len;
// 	result = malloc(sizeof(char) * (len_s + 1));
// 	if (!result || !s)
// 		return (NULL);
// 	j = 0;
// 	while (s[i])
// 	{
// 		if (i >= start && j < len)
// 			result[j++] = s[i];
// 		i++;
// 	}
// 	result[j] = '\0';
// 	return (result);
// }
