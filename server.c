/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:19:33 by davioliv          #+#    #+#             */
/*   Updated: 2023/11/14 17:08:28 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal)
{
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 1)
		ft_printf("Try this: ./server");
	pid = getpid();
	ft_printf("%i", pid);
	while (argv[1][i])
	{
	}
	return (0);
}
