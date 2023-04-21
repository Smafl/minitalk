/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:36:25 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/21 13:54:20 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (EXIT_FAILURE);
	pid = ft_atoi(argv[1]);
	if (!pid)
		return (EXIT_FAILURE);
}
