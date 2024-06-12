/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:38:23 by danpalac          #+#    #+#             */
/*   Updated: 2024/03/08 13:38:54 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned long n)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789";
	if (n > (ft_strlen(base) - 1))
		len += ft_putunsigned(n / ft_strlen(base));
	len += ft_putchar(*(base + (n % ft_strlen(base))));
	return (len);
}
/*
int main(void)
{
	unsigned long number = 429; // Example number
	int printed_chars;

	printed_chars = ft_putunsigned(number);
	ft_putchar('\n');
	ft_putstr("Printed characters: ");
	ft_putnbr(printed_chars);
	ft_putchar('\n');

	return (0);
}*/
