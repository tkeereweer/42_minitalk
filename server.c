/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:02:20 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/10/02 11:47:40 by mkeerewe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_byte;

void	sigusr1_handler(int signal)
{
	if (signal == SIGUSR1)
		ft_chrcat(g_byte, '0');
}

void	sigusr2_handler(int signal)
{
	if (signal == SIGUSR2)
		ft_chrcat(g_byte, '1');
}

void	sigterm_handler(int signal)
{
	if (signal == SIGTERM)
	{
		free(g_byte);
		exit(0);
	}
}

void	set_signal_action(void)
{
	struct sigaction	bit_0;
	struct sigaction	bit_1;
	struct sigaction	term;

	ft_bzero(&bit_0, sizeof(bit_0));
	bit_0.sa_handler = &sigusr1_handler;
	sigaction(SIGUSR1, &bit_0, NULL);
	ft_bzero(&bit_1, sizeof(bit_1));
	bit_1.sa_handler = &sigusr2_handler;
	sigaction(SIGUSR2, &bit_1, NULL);
	ft_bzero(&term, sizeof(term));
	term.sa_handler = &sigterm_handler;
	sigaction(SIGTERM, &term, NULL);
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	set_signal_action();
	g_byte = (char *) malloc(9 * sizeof(char));
	if (g_byte == (void *) 0)
		return (0);
	g_byte[0] = '\0';
	while (1)
	{
		if (ft_strlen(g_byte) == 8)
		{
			ft_printf("%c", ft_btoi(g_byte));
			g_byte[0] = '\0';
		}
	}
}
