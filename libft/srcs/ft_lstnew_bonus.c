/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:47:44 by danpalac          #+#    #+#             */
/*   Updated: 2024/02/26 10:15:08 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
int main()
{
    t_list	*list;
	t_list	*list2;
	int		lol[] = {1, 4, 5, 6};

    list = ft_lstnew("buenas");
    list2 = ft_lstnew(lol);
    printf("%zu\n", sizeof(t_list));
    printf("%s\n", list->content);
    printf("%s\n", list2->content);
	free(list);
	return (0);
}*/
