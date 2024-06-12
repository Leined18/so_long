/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:56:07 by danpalac          #+#    #+#             */
/*   Updated: 2024/02/02 12:33:41 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
	{
		if ((*(unsigned char *)s1) != *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1 = (unsigned char *)s1 + 1;
		s2 = (unsigned char *)s2 + 1;
	}
	return (0);
}
/*
int main()
{
	char arr1[] = {2, 3, 5};
	char arr2[] = {2, 3, 7};
	int result1 = ft_memcmp(arr1, arr2, sizeof(arr1));

	int a = 121;
	int b = 113;
	int result2 = ft_memcmp(&a, &b, sizeof(int));

	printf("%d\n%d\n", result1, result2);
	return (0);
}*/
