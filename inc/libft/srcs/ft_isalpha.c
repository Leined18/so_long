/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:14:37 by danpalac          #+#    #+#             */
/*   Updated: 2024/02/08 11:37:38 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/*
int main()
{
	char c;
   	scanf("%c ", &c);
	char a;
   	scanf("%c", &a);

	printf("%d\n", ft_isalpha(c));	
	printf("%d\n", ft_isalpha(a));

	return (0);
}*/
