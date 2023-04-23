/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:57:00 by ekulichk          #+#    #+#             */
/*   Updated: 2022/11/10 14:45:14 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	get_substr_number(const char *s, char c)
{
	size_t	substr_number;
	int		flag;

	substr_number = 0;
	flag = 0;
	while (*s)
	{
		if (*s == c)
			flag = 0;
		else
		{
			if (!flag)
				++substr_number;
			flag = 1;
		}
		++s;
	}
	return (substr_number);
}

static char	**mem_free(char **array)
{
	char	**cursor;

	cursor = array;
	while (*cursor)
	{
		free(*cursor);
		cursor++;
	}
	free(array);
	return (NULL);
}

static size_t	get_word_length(char const **s, char c)
{
	size_t	len;

	len = 0;
	while (**s != c && **s != '\0')
	{
		len++;
		(*s)++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	len;
	char	**result;

	if (s == NULL)
		return (NULL);
	i = 0;
	result = malloc((get_substr_number(s, c) + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = get_word_length(&s, c);
			result[i] = ft_substr(s - len, 0, len);
			if (result[i] == NULL)
				return (mem_free(result));
			i++;
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}

/*
0       int, char, unsigned int, short, ..., float, double, ...
'\0'    char, ... int,...
NULL    (void*)0
0.0     double/float
0.      0.0
*/