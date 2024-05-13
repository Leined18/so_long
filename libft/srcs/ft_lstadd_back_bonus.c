/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:44:00 by danpalac          #+#    #+#             */
/*   Updated: 2024/02/13 10:19:38 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}
/*
int main()
{
    t_list *head = NULL;
    t_list *new_node = malloc(sizeof(t_list));

    new_node->content = "New Node";
    new_node->next = NULL;

    ft_lstadd_back(&head, new_node);

    t_list *current = head;
    while (current != NULL)
    {
        printf("%s\n", (char *)current->content);
        current = current->next;
    }

    free(new_node);
    return 0;
}*/
