/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:17:50 by mel-hime          #+#    #+#             */
/*   Updated: 2023/12/28 14:35:14 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((unsigned char *)(s + i));
		i++;
	}
	return (NULL);
}

// int main ()
// {
// 	char s[10] = "break";
// 	printf("%s", ft_memchr(s, 97, 4));
// }
// int main ()
// {
// 	int tab[3] ={1, 2 ,3};
// 	int *tab1 = ft_memchr(tab, 0, 4);
// 	int i = 0;
// 	while (i < 3)
// 	{
// 		printf("%d\n", tab1[i]);
// 		i++;
// 	}
// }