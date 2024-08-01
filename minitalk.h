/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:50:51 by mel-hime          #+#    #+#             */
/*   Updated: 2024/05/12 15:30:57 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_data
{
	char	*received_text;
	int		index;
	char	c;
	size_t	len;
	int		receive;
	char	*text;
	int		client_id;
	int		is_allocated;
	size_t	text_index;
	int		server_id;
}				t_data;

void	alloc_text(t_data *g_data, size_t len);
void	init_g_data(t_data *g_data, pid_t pid);
void	receive_len(t_data *g_data, int sig);
void	check_client(t_data *g_data, pid_t pid);

#endif