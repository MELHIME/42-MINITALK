/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:10:26 by mel-hime          #+#    #+#             */
/*   Updated: 2023/12/28 14:22:45 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
// int main ()
// {
// 	t_list	*s = ft_lstnew("sorry");
// 	t_list	*s1 = ft_lstnew("bae");
// 	t_list	*s2 = ft_lstnew("its oky");
// 	ft_lstadd_front(&s, s1);
// 	ft_lstadd_back(&s, s2);
// 	printf("%d",ft_lstsize(s));
// }