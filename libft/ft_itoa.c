/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:55:19 by ekulichk          #+#    #+#             */
/*   Updated: 2022/11/01 13:27:01 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(int n)
{
	size_t	size;

	size = 0;
	if (n <= 0)
		size = 1;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		size;
	long	digit;

	size = get_size(n);
	result = malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	digit = (long)n;
	if (n < 0)
	{
		digit *= -1;
		*result = '-';
	}
	result[size--] = '\0';
	while (digit >= 0)
	{
		result[size--] = (digit % 10) + '0';
		digit /= 10;
		if (digit == 0)
			break ;
	}
	return (result);
}
