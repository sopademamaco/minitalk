/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:33:17 by davioliv          #+#    #+#             */
/*   Updated: 2023/12/05 03:47:33 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_sig(int pid, char c)
{
	int	bit_count;

	bit_count = 0;
	while (bit_count < 8)
	{
		if ((c & (0x01 << bit_count)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(5000);
		bit_count++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Try this: ./client <Server PID> <\"string_to_send\">");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		ft_send_sig(pid, argv[2][i]);
		i++;
	}
	ft_send_sig(pid, '\n');
	return (0);
}
