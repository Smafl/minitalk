/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 14:56:05 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/23 14:56:16 by ekulichk         ###   ########.fr       */
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

	while (*str)
	{
		i = 0;
		c = *str++;
		while (i <= 7)
		{
			temp = c >> (7 - i);
			if (temp & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
			i++;
		}
	}
	i = 0;
	while (i++ <= 7)
	{
		kill(pid, SIGUSR2);
		usleep(50);
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
