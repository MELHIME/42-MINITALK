/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:31:32 by mel-hime          #+#    #+#             */
/*   Updated: 2023/12/30 16:51:58 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_words(const char *str, char c)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	j = 0;
	check = 0;
	while (str[j])
	{
		if (str[j] != c && check == 0)
		{
			check = 1;
			i++;
		}
		else if (str[j] == c)
			check = 0;
		j++;
	}
	return (i);
}

static char	*alloc_word(const char *s, int *i, char c)
{
	int		j;
	int		start;
	int		len;
	char	*word;

	len = ft_strlen(s);
	start = *i;
	while (s[*i] && s[*i] != c)
	{
		(*i)++;
	}
	word = (char *)malloc ((*i - start) + 1);
	if (word == NULL)
		return (NULL);
	j = 0;
	while (start < *i)
	{
		word[j] = s[start];
		start++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

static char	**memfree(char **split, int j)
{
	while (j >= 0)
	{
		free(split[j]);
		j--;
	}
	free(split);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	if (s == NULL)
		return (NULL);
	split = malloc ((check_words(s, c) + 1) * sizeof (char *));
	if (split == NULL)
		return (NULL);
	j = 0;
	while (j < check_words(s, c) && s[i])
	{
		if (s[i] != c)
		{
			split[j] = alloc_word(s, &i, c);
			if (split[j] == NULL)
				return (memfree(split, (j - 1)));
			j++;
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}
