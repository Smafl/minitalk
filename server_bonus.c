/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 14:55:27 by ekulichk          #+#    #+#             */
/*   Updated: 2023/06/26 12:06:14 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

static void	mt_sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	static char	result = 0;
	static int	current_bit = 0;
	static int	cl_pid = 0;

	(void)ucontext;
	result = result << 1;
	result |= (sig == SIGUSR1);
	if ((current_bit++) && (!cl_pid))
		cl_pid = info->si_pid;
	if (current_bit == 8)
	{
		write(1, "hi", 3);
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
