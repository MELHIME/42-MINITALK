/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:20:02 by mel-hime          #+#    #+#             */
/*   Updated: 2023/12/28 17:32:48 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *)dest;
	s = (char *)src;
	if (!s && !d)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
// int main()
// {
//     int p2[20] = {1, 2, 3, 4};
//     int t1[20] = {5, 6, 7, 8};
//     ft_memcpy(t1,p2, 8);
// 	int i = 0;
// 	while (i < 4)
// 	{
// 	printf("column number %d : %d\n", (i + 1),t1[i]);
//     i++;
// 	}
// }
