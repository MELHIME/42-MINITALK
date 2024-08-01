/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:30:58 by mel-hime          #+#    #+#             */
/*   Updated: 2023/12/30 16:54:35 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*nextnode;
	void	*fcontnt;

	if (!lst || !f || !del)
		return (0);
	newlst = 0;
	while (lst)
	{
		fcontnt = f(lst->content);
		nextnode = ft_lstnew(fcontnt);
		if (!nextnode)
		{
			del(fcontnt);
			ft_lstclear(&newlst, del);
			return (0);
		}
		ft_lstadd_back(&newlst, nextnode);
		lst = lst->next;
	}
	return (newlst);
}

// void	del(void *c)
// {
// 	free (c);
// }
// void	*f(void *a)
// {
// 	char	*s = a;
// 	s[0] = '#';
// 	return (s);
// }
// int main ()
// {
// 	char	t1[] = "THE";
// 	t_list	*s = ft_lstnew(t1);
// 	char	t2[] = "JOKER";
// 	t_list	*s1 = ft_lstnew(t2);
// 	char	t3[] = "IS HERE";
// 	t_list	*s2 = ft_lstnew(t3);
// 	ft_lstadd_back(&s, s1);
// 	ft_lstadd_back(&s, s2);
// 	t_list	*cs = s;
// 	while (s)
// 	{
// 		printf("%s ",s->content);
// 		s = s->next;
// 	}
// 	printf("\nRESULTS :\n");
// 	t_list	*nlst = ft_lstmap(cs, f, del);
// 	while (nlst)
// 	{
// 		printf("%s\n",nlst->content);
// 		nlst = nlst->next;
// 	}
// 	}