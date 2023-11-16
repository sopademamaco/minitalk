/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:19:33 by davioliv          #+#    #+#             */
/*   Updated: 2023/11/16 12:09:57 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sigusr_handler(int signal)
{
	static char	current;
	static int	bit_count;


	if (signal == SIGUSR1)
	{
		current = current | (0x01 << bit_count);
		bit_count++;
	}
	else if (signal == SIGUSR2)
		bit_count++;
	if (bit_count == 8)
	{
		ft_printf("%c", current);
		current = 0;
		bit_count = 0;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		ft_printf("Try this: ./server");
		return (0);
	}
	ft_printf("Server PID: %i\n", getpid());
	while (argc == 1)
	{
		signal(SIGUSR1, sigusr_handler);
		signal(SIGUSR2, sigusr_handler);
	}
	return (0);
}
