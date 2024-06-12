/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:16:26 by danpalac          #+#    #+#             */
/*   Updated: 2024/03/08 13:38:16 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char const *s)
{
	int	result;

	result = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (*s)
		result += ft_putchar(*s++);
	return (result);
}
/*
int main()
{
	ft_putstr("adios");
	return 0;
}*/
