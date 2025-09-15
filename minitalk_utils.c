/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 10:36:56 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/09/15 16:02:53 by mkeerewe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_chrcat(char *dst, const char c)
{
	int	i;

	i = 0;
	while (dst[i] != '\0')
		i++;
	dst[i] = c;
	dst[i + 1] = '\0';
}

static void	int_to_str(char *out, int nb)
{
	if (nb < 2)
	{
		ft_chrcat(out, nb + '0');
	}
	else
	{
		int_to_str(out, nb / 2);
		int_to_str(out, nb % 2);
	}
}

char	*ft_ctob(int c)
{
	char			*out;

	out = (char *) malloc(9 * sizeof(char));
	if (out == (void *) 0)
		return (out);
	out[0] = '\0';
	int_to_str(out, c);
	while (ft_strlen(out) != 8)
	{
		ft_memmove(&out[1], out, ft_strlen(out));
		out[0] = '0';
	}
	return (out);
}

int	ft_btoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < 8)
	{
		res = (res * 2) + (str[i] - '0');
		i++;
	}
	return (res);
}

// int	main(void)
// {
// 	ft_btoi("01100101");
// 	return(0);
// }
