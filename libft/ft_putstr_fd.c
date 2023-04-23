/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:21:43 by ekulichk          #+#    #+#             */
/*   Updated: 2022/11/10 14:34:46 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	len;

	if (s == NULL)
		return ;
	len = ft_strlen(s);
	write(fd, s, len);
}

// void	ft_putstr_fd(char *s, int fd)
// {
// 	while (*s)
// 	{
// 		ft_putchar_fd(*s, fd);
// 		s++;
// 	}
// }
