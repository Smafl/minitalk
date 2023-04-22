/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:36:25 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/23 00:20:37 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

static void	mt_get_sig(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("Message recived");
}

static void	mt_send_sig(int pid, char *str)
{
	int		i;
	char	c;
	char	temp;

	c = 0;
	while (*str)
	{
		i = 0;
		c = *str;
		while (i < 8)
		{
			temp = c >> (7 - i);
			if (temp & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
		}
		i++;
		str++;
		usleep(50);
	}
	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR2);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (EXIT_FAILURE);
	pid = ft_atoi(argv[1]);
	if (!pid)
		return (EXIT_FAILURE);
	signal(SIGUSR1, mt_get_sig);
	signal(SIGUSR2, mt_get_sig);
	mt_send_sig(pid, argv[2]);
	return (0);
}
