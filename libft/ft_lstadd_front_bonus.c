/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:20:59 by mel-hime          #+#    #+#             */
/*   Updated: 2023/12/28 12:03:30 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// int main ()
// {
// 	t_list	*s = ft_lstnew("heeeey");
// 	t_list	*s1 = ft_lstnew("babe");
// 	ft_lstadd_front(&s, s1);
// 	printf("%s", s->content);
// }