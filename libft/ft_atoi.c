/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:39:29 by mel-hime          #+#    #+#             */
/*   Updated: 2023/12/30 13:22:21 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_neg(const char *s, int *i)
{
	int	sgn;

	sgn = 1;
	while ((s[*i] >= 9 && s[*i] <= 13) || s[*i] == 32)
		(*i)++;
	while (s[*i] == 45 || s[*i] == 43)
	{
		if (s[*i] == 45)
			sgn = -1;
		if (s[*i + 1] == 45 || s[*i + 1] == 43)
			return (0);
		(*i)++;
	}
	return (sgn);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	somme;
	long	tmp;

	somme = 0;
	i = 0;
	sign = is_neg(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = somme;
		somme = somme * 10 + (str[i] - 48);
		if (somme / 10 != tmp && sign == -1)
			return (0);
		if (somme / 10 != tmp)
			return (-1);
		i++;
	}
	return (somme * sign);
}
// #include <stdio.h>

//  int main ()
//  {
//  	printf("%d", ft_atoi("-120"));
//  }