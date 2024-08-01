/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:47:26 by mel-hime          #+#    #+#             */
/*   Updated: 2023/12/28 12:41:40 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

// int main ()
// {
// 	t_list	*s = ft_lstnew("hello");
// 	t_list	*s1 = ft_lstnew("haaaa");
// 	t_list	*s2 = ft_lstnew("yo");
// 	ft_lstadd_back(&s, s1);
// 	ft_lstadd_back(&s, s2);
// 	printf ("%s", ft_lstlast(s)->content);
// 	}