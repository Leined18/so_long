/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:35:01 by danpalac          #+#    #+#             */
/*   Updated: 2024/02/12 23:32:57 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s2 && *s1 == *s2 && n > 1)
	{
		s1++;
		s2++;
		n--;
	}
	return (((unsigned char)(*s1) - (unsigned char)(*s2)));
}
/*
int main()
{
	char str1[] = "Hello";
	char str2[] = "World";
	int result = ft_strncmp(str1, str2, sizeof(str1));

	char str3[] = "Hellb";
	char str4[] = "Hella";
	int result2 = ft_strncmp(str3, str4, sizeof(str3));

	printf("%d\n%d\n",result, result2);
}*/
