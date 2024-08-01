/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:13:55 by mel-hime          #+#    #+#             */
/*   Updated: 2023/12/28 12:03:38 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	p = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (p->next != NULL)
		p = p->next;
	p->next = new;
}
// int main ()
// {
// 	t_list *s = ft_lstnew("HEEEY");
// 	t_list *s1 = ft_lstnew("SWEETIE");
// 	ft_lstadd_back(&s, s1);
// 	printf("%s", s->next->content);
// }