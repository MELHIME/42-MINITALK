/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:59:35 by mel-hime          #+#    #+#             */
/*   Updated: 2024/05/13 11:43:29 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

void	putnbr(int nb)
{
	if (nb >= 10)
		putnbr(nb / 10);
	write (1, &"0123456789"[nb % 10], 1);
}

void	sighandler(int sig, siginfo_t *info, void *context)
{
	(void) context;
	check_client(&g_data, info->si_pid);
	if (g_data.receive < 32)
		receive_len(&g_data, sig);
	else
	{
		if (!g_data.is_allocated)
			alloc_text(&g_data, g_data.len);
		if (sig == SIGUSR1)
			g_data.c = g_data.c << 1;
		else if (sig == SIGUSR2)
			g_data.c = (g_data.c << 1) | 1;
		g_data.index++;
		if (g_data.index > 7)
		{
			g_data.received_text[g_data.text_index++] = g_data.c;
			g_data.index = 0;
		}
		if (g_data.text_index == g_data.len)
		{
			ft_putstr_fd(g_data.received_text, 1);
			kill(g_data.client_id, SIGUSR1);
			init_g_data(&g_data, 0);
		}
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	ft_bzero(&sa, sizeof(sa));
	sa.sa_sigaction = sighandler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	putnbr(pid);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
