/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkeerewe <mkeerewe@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 10:46:53 by mkeerewe          #+#    #+#             */
/*   Updated: 2025/09/15 14:01:02 by mkeerewe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "libft/libft.h"

void	ft_chrcat(char *dst, const char c);
char	*ft_ctob(int c);
int		ft_btoi(char *str);

#endif
