/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:19:33 by davioliv          #+#    #+#             */
/*   Updated: 2023/12/21 10:16:57 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minitalk.h"

void	sigusr_handler(int signal, siginfo_t *info, void *context)
{
	static char	current;
	static int	bit_count;

	(void)context;
	if (signal == SIGUSR1)
	{
		current = current | (0x01 << bit_count);
		bit_count++;
		kill(info->si_pid, SIGUSR1);
	}
	else if (signal == SIGUSR2)
	{
		bit_count++;
		kill(info->si_pid, SIGUSR2);
	}
	if (bit_count == 8)
	{
		ft_printf("%c", current);
		current = 0;
		bit_count = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	sa.sa_sigaction = sigusr_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	if (argc != 1)
	{
		ft_printf("Try this: ./server_bonus");
		return (0);
	}
	ft_printf("Server PID: %i\n", getpid());
	ft_printf("Waiting for client's message...\n");
	while (argc == 1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
	return (0);
}
