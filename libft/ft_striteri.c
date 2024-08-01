/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:31:43 by mel-hime          #+#    #+#             */
/*   Updated: 2023/12/24 16:21:48 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	len;
	unsigned int	i;

	i = 0;
	len = 0;
	if (!s)
		return ;
	while (s[len])
		len++;
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
}

/*void f(unsigned int i, char *c)
{
	printf("old : %c\n", *c);
	*c = *c + i;
	printf("new : %c\n", *c);
}

int main ()
{
	char str[10] = "abcde";
	ft_striteri(str, f);
	printf("%s\n", str);
}*/