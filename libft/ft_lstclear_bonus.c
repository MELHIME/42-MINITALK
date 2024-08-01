/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:46:54 by mel-hime          #+#    #+#             */
/*   Updated: 2023/12/28 12:09:53 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;
	t_list	*clst;

	clst = *lst;
	while (clst)
	{
		p = clst->next;
		del(clst->content);
		free (clst);
		clst = p;
	}
	*lst = 0;
}
// void	del(void *a)
// {
// 	free(a);
// }
// int main ()
// {
// 	t_list	*s = ft_lstnew("heeey");
// 	ft_lstclear(&s, del);
// 	printf("%s", s->content);
// }