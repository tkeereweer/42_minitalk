/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:42:45 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/09/15 11:11:06 by mkeerewe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s)
{
	if (s != (void *) 0)
	{
		write(1, s, ft_strlen(s));
		return (ft_strlen(s));
	}
	else
	{
		write(1, "(null)", 6);
		return (6);
	}
}
