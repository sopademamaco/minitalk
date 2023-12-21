/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:33:17 by davioliv          #+#    #+#             */
/*   Updated: 2023/12/21 12:00:29 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minitalk.h"

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

void	sig_handler(int signal)
{
	static int	bit_count;
	static char	bits[8];

	if (signal == SIGUSR1)
	{
		bits[bit_count] = '1';
		bit_count++;
	}
	else if (signal == SIGUSR2)
	{
		bits[bit_count] = '0';
		bit_count++;
	}
	if (bit_count == 8)
	{
		ft_printf("%s ", bits);
		ft_bzero(bits, bit_count);
		bit_count = 0;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	if (argc != 3)
	{
		ft_printf("Try this: ./client_bonus <Server PID> <\"string_to_send\">");
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
