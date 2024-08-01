/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:32:06 by mel-hime          #+#    #+#             */
/*   Updated: 2024/05/13 17:08:49 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	init_g_data(t_data *g_data, pid_t pid)
{
	if (g_data->is_allocated)
		free(g_data->received_text);
	g_data->received_text = NULL;
	g_data->index = 0;
	g_data->c = 0;
	g_data->len = 0;
	g_data->receive = 0;
	g_data->client_id = pid;
	g_data->is_allocated = 0;
	g_data->text_index = 0;
}

void	alloc_text(t_data *g_data, size_t len)
{
	g_data->received_text = (char *) malloc(len + 1);
	if (!g_data->received_text)
	{
		init_g_data(g_data, 0);
	}
	g_data->received_text[len] = '\0';
	g_data->is_allocated = 1;
}

void	receive_len(t_data *g_data, int sig)
{
	if (sig == SIGUSR1)
		g_data->len = g_data->len << 1;
	else if (sig == SIGUSR2)
		g_data->len = (g_data->len << 1) | 1;
	g_data->receive++;
}

void	check_client(t_data *g_data, pid_t pid)
{
	if (!g_data->client_id)
		g_data->client_id = pid;
	if (g_data->client_id != pid)
	{
		init_g_data(g_data, pid);
	}
}
