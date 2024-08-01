/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:22:55 by mel-hime          #+#    #+#             */
/*   Updated: 2023/12/28 12:17:22 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	if (del)
	{
		del(lst->content);
	}
	free (lst);
}
// void	del(void *c)
// {
// 	free(c);
// }
// int main ()
// {
// 	t_list	*s = ft_lstnew("heey");
// 	ft_lstdelone(s, del);
// 	printf("%s", s->content);
// }