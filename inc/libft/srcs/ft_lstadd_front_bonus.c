/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:33:12 by danpalac          #+#    #+#             */
/*   Updated: 2024/02/01 10:54:29 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
void	print_list(t_list *lst)
{
	while (lst != NULL)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}

int	main()
{
	t_list *lst = NULL;
	t_list *new_node = ft_lstnew("Hello");
	t_list *new_node2 = ft_lstnew("hola");

	if (!new_node)
		return (1);
	if (!new_node2)
		return (1);
	ft_lstadd_front(&lst, new_node);
	ft_lstadd_front(&new_node2, new_node2);
	print_list(lst);
	print_list(lst);
	return (0);
}*/
