/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:49:04 by mel-hime          #+#    #+#             */
/*   Updated: 2023/12/28 11:52:28 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(long nb)
{
	int	len;

	len = 1;
	if (nb > 0)
		len = 0;
	if (nb == 0)
		return (len);
	while (nb)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static int	ft_neg(long *nbr)
{
	int	neg;

	neg = 1;
	if (*nbr < 0)
	{
		neg = -1;
		*nbr = *nbr * -1;
	}
	return (neg);
}

char	*ft_itoa(int nbr)
{
	int		len;
	long	nb;
	int		sign;
	char	*str;

	nb = nbr;
	len = count_len(nb);
	sign = ft_neg(&nb);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	len--;
	while (len >= 0)
	{
		str[len] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	if (sign == -1)
		str[0] = '-';
	str[count_len(nbr)] = '\0';
	return (str);
}
// int main ()
// {
// 	long nb = -120;
// 	long *n = &nb;
// 	printf("%ld\n", nb);
// 	ft_neg(n);
// 	printf("%ld\n", nb);
// }
// int main ()
// {
// 	printf("%s\n", ft_itoa(123));
// }