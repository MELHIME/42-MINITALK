/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:05:45 by mel-hime          #+#    #+#             */
/*   Updated: 2023/12/23 16:01:12 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sbstr;
	size_t	i;
	size_t	flen;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || !len)
		return (ft_strdup(""));
	flen = ft_strlen(s + start);
	if (flen > len)
		flen = len;
	sbstr = (char *)malloc(flen + 1);
	if (!sbstr)
		return (NULL);
	while (i < flen)
	{
		sbstr[i] = s[i + start];
		i++;
	}
	sbstr[i] = '\0';
	return (sbstr);
}
/*
int main ()
{
	char	*str = "THE FUCKING JOKER IS BACK";
	printf("%s", ft_substr(str, 30, 13));

}*/