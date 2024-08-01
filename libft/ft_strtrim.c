/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:33:37 by mel-hime          #+#    #+#             */
/*   Updated: 2023/12/30 08:30:06 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_char(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*strt;
	size_t		len;
	size_t		i;
	int			j;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	len = ft_strlen((char *)s1);
	while (i < len && check_char(set, s1[i]) == 1)
		i++;
	while (i < len && check_char(set, s1[len - 1]) == 1)
		len--;
	strt = (char *)malloc(len - i + 1);
	if (!strt)
		return (NULL);
	j = 0;
	while (i < len)
		strt[j++] = s1[i++];
	strt[j] = '\0';
	return (strt);
}
