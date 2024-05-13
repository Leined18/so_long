/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:23:45 by danpalac          #+#    #+#             */
/*   Updated: 2024/02/26 12:01:19 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
}
/*
int main()
{
	int c = 't';
	char s[] = "baens trdes";
	char *result;

	result = strchr(NULL,'t');
	printf("uno: %s\n",strchr(NULL,'t'));
	//printf("dos: %s\n",result);
	return (0);
}*/
