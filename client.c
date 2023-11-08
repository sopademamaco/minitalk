/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:33:17 by davioliv          #+#    #+#             */
/*   Updated: 2023/11/08 16:43:21 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	i;
	int	p;

	i = 0;
	if (argc != 3)
		ft_printf("Try this: ./client.c <string to send> <Server PID>");
	p = ft_atoi(argv[2]);
	while (argv[1][i])
	{
		kill(p, (argv[1][i]) * 8);
		i++;
	}
	return (0);
}
