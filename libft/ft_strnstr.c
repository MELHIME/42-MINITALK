/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:10:43 by mel-hime          #+#    #+#             */
/*   Updated: 2023/12/30 16:53:43 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (to_find[i])
		i++;
	if (i == 0)
		return ((char *)str);
	j = 0;
	while (str[j] && j < n)
	{
		k = 0;
		while (str[j + k] == to_find[k] && (j + k) < n)
		{
			k++;
			if (k == i)
				return ((char *)&str[j]);
		}
		j++;
	}
	return (0);
}
