/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:45:45 by danpalac          #+#    #+#             */
/*   Updated: 2024/02/09 10:43:03 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
void print_data(void *data)
{
    printf("%s\n", (char *)data);
}

int main() {
    t_list *lst;
    char *strings[] = {"uno", "dos", "tres", "cuatro"};
    int i;

    // Crear la lista
    lst = NULL;
    for (i = 0; i < sizeof(strings) / sizeof(*strings); i++) {
        ft_lstadd_back(&lst, ft_lstnew((void *)strings[i]));
    }

    // Recorrer la lista e imprimir cada elemento
    ft_lstiter(lst, print_data);

    // Limpiar la lista
    ft_lstclear(&lst, free);

    return 0;
}*/
