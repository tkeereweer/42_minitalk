/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 10:14:02 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/10/02 11:51:09 by mkeerewe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
// #include <stdio.h>

void	ft_sendbits(char c, int pid)
{
	char	*byte;
	int		i;

	byte = ft_ctob(c);
	i = 0;
	while (i < 8)
	{
		if (byte[i] == '0')
			kill(pid, SIGUSR1);
		else if (byte[i] == '1')
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
	free(byte);
}

void	ft_sendmsg(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_sendbits(str[i], pid);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	ft_sendmsg(argv[2], pid);
	return (0);
}
