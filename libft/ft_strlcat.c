/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:11:50 by mel-hime          #+#    #+#             */
/*   Updated: 2023/12/30 16:53:10 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	ldst;
	size_t	lsrc;

	lsrc = ft_strlen(src);
	if (dest == NULL && size == 0)
		return (lsrc);
	ldst = ft_strlen(dest);
	i = ldst;
	j = 0;
	if (size == 0)
		return (lsrc);
	if (size < ldst)
		return (lsrc + size);
	while ((ldst + j + 1) < size && src[j])
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (ldst + lsrc);
}
/*int main() {
    char dest[40] = "hello";
    const char *src = "worldw";

    size_t dest_size = sizeof(dest);
    size_t result = ft_strlcat(dest, src, 2);

    printf("Concatenated string: %s\n", dest);
    printf("Total length after concatenation: %zu\n", result);

    return 0;
}*/
