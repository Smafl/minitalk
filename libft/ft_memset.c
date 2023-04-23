/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:57:15 by ekulichk          #+#    #+#             */
/*   Updated: 2022/11/08 18:40:57 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*pnt;

	pnt = s;
	while (n > 0)
	{
		*pnt = (unsigned char) c;
		pnt++;
		n--;
	}
	return (s);
}

/*
в функцию передается void *, указатель на неизвестный тип
и переписать надо количество байт, сначала приведя указатель
потому что разыменовать void * нельзя (получить доступ к памяти по этому адресу)

The memset() function writes len bytes of 
value c (converted to an unsigned char) to the string b
*/