/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:44:19 by mel-hime          #+#    #+#             */
/*   Updated: 2024/05/13 11:54:08 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

void	sighandler(int sig)
{
	if (sig == SIGUSR1)
	{
		write(1, "\033[1;32mSEND SUCCEFULLY ;)\n\033[0m", 30);
		exit(0);
	}
}

void	send_len(int len)
{
	int	i;
	int	bit;

	i = 32;
	while (--i >= 0)
	{
		bit = (len >> i) & 1;
		if (bit == 0)
			kill(g_data.server_id, SIGUSR1);
		else
			kill(g_data.server_id, SIGUSR2);
		usleep(50);
	}
}

void	send_bits(void)
{
	int			i;
	int			bit;
	const char	*str;

	str = g_data.text;
	send_len(ft_strlen(str));
	while (*str)
	{
		i = 7;
		while (i >= 0)
		{
			bit = *str >> i & 1;
			if (bit == 0)
				kill(g_data.server_id, SIGUSR1);
			else
				kill(g_data.server_id, SIGUSR2);
			usleep(50);
			i--;
		}
		str++;
	}
}

int	main(int c, char **v)
{
	if (c == 3 && ft_atoi(v[1]) >= 0)
	{
		g_data.server_id = ft_atoi(v[1]);
		g_data.text = v[2];
		signal(SIGUSR1, sighandler);
		send_bits();
		while (1)
			pause();
	}
	else
		write(2, "\033[1;31mError!!!\n\033[0m", 20);
	return (0);
}
