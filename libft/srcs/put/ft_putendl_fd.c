/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:03:22 by danpalac          #+#    #+#             */
/*   Updated: 2024/01/25 09:44:49 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
/*
int main() {
    // Write C code here
    char c[] = "Ayuda";
    int i = 0;

    while (i < sizeof(short int))
    {
        ft_putendl_fd(c,1);
        i++;
    }

    return 0;
}*/
