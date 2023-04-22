/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:48:00 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/23 00:17:15 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

static void	mt_sig_handler(int signal, siginfo_t *sig, void *context)
{
	static char	result;
	static int	current_bit;
	static int	cl_pid;

	(void)context;
	result = 0;
	current_bit = 0;
	cl_pid = 0;
	result = result << 1;
	result |= (signal == SIGUSR1);
	if ((current_bit++) && (!cl_pid))
		cl_pid = sig->si_pid;
	if (current_bit == 8)
	{
		current_bit = 0;
		if (result == '\0')
		{
			kill(cl_pid, SIGUSR2);
			cl_pid = 0;
			return ;
		}
		write(1, &result, 1);
		result = 0;
		kill(cl_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	mt_sigaction;

	ft_printf("%d\n", getpid());
	mt_sigaction.sa_flags = SA_SIGINFO;
	mt_sigaction.sa_sigaction = &mt_sig_handler;
	sigaction(SIGUSR1, &mt_sigaction, NULL);
	sigaction(SIGUSR2, &mt_sigaction, NULL);
	while (1)
		pause();
	return (0);
}
