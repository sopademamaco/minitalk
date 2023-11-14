/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:33:17 by davioliv          #+#    #+#             */
/*   Updated: 2023/11/14 16:43:00 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_convert_bits(pid, c)
{
	int	bit_count;

	bit_count = 0;
	if ((c & (0x01 << bit_count)) != 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	bit_count++;
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	if (argc != 3)
		ft_printf("Try this: ./client.c <Server PID> <string_to_send>");
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		ft_convert_bits(pid, argv[2][i]);
		i++;
	}
	return (0);
}
