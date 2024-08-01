/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:51:17 by mel-hime          #+#    #+#             */
/*   Updated: 2023/12/30 08:31:42 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*p;

	p = lst;
	while (p)
	{
		f(p->content);
		p = p->next;
	}
}
// void	f(void *c)
// {
// 	free (c);
// }
// int main ()
// {
// 	t_list	*s = ft_lstnew("hello");
// 	t_list	*s1 = ft_lstnew("haaaa");
// 	t_list	*s2 = ft_lstnew("yo");
// 	ft_lstadd_back(&s, s1);
// 	ft_lstadd_back(&s, s2);
// 	ft_lstiter(s, f);
// 	while (s)
// 	{
// 	printf("%s\n", s->content);
// 	s = s->next;
// 	}
// }