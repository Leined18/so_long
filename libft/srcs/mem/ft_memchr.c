/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:31:19 by danpalac          #+#    #+#             */
/*   Updated: 2024/02/26 12:11:23 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s++ == (unsigned char)c)
			return ((void *)(unsigned char *)s - 1);
	}
	return (NULL);
}
/*
int main()
{
	char s[] = {0, 1, 2 ,3 ,4 ,5};

	printf("%s\n", memchr(NULL, 'G', 3));
	printf("%s\n", ft_memchr(NULL, 'g', 3));
}*/
