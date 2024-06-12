/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:05:52 by danpalac          #+#    #+#             */
/*   Updated: 2024/01/18 12:36:31 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ((unsigned char)c >= 'a' && (unsigned char )c <= 'z')
		c -= 32;
	return (c);
}
/*
int main()
{
	int a = 'z';
	printf("%c",ft_toupper(a));
	return 0;
}*/
