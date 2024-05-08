/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:06:44 by danpalac          #+#    #+#             */
/*   Updated: 2024/02/02 10:46:28 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cuenta el numero de nodos de la lista
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*temp;

	if (!lst)
		return (0);
	temp = lst;
	size = 0;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}
/*
int main(void)
{
    t_list *l;
 	int actual;
 	int expected;

 	l = ft_lstnew(strdup("1"));
 	l->next = ft_lstnew(strdup("2"));
 	l->next->next = ft_lstnew(strdup("3"));

	while (l)
	{
    	printf("Size of the list: %d\n", ft_lstsize(l));
		l = l->next;
	}
    return 0;
}*/
