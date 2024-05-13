/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:33:09 by danpalac          #+#    #+#             */
/*   Updated: 2024/02/02 16:26:46 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
void free_content(void *content)
{
    free(content);
}

int main()
{
    t_list *head = NULL;
    t_list *new_node = malloc(sizeof(t_list));

    new_node->content = strdup("Node to delete");
    new_node->next = NULL;

    head = new_node;

    printf("Before deletion: %s\n", (char *)head->content);

    ft_lstdelone(head, free_content);

    printf("After deletion: %s\n", (char *)head->content);

    return 0;
}*/
