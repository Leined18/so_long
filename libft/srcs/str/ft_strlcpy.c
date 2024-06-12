/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:33:19 by danpalac          #+#    #+#             */
/*   Updated: 2024/02/26 11:59:47 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;	

	i = 0;
	while (src[i])
		i++;
	if (!dstsize)
		return (i);
	while (--dstsize != 0 && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (i);
}
/*
int main()
{
	char src[] = "nice to meeto you";
	char dst[] = "buenas tardes";
	printf("%zu\n%s", ft_strlcpy(dst, src, sizeof(dst)), dst);
	
	return (0);
}*/
