/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:43:28 by danpalac          #+#    #+#             */
/*   Updated: 2024/02/08 10:54:38 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_make_copy(unsigned char *dst, const unsigned char *src, size_t len)
{
	size_t	i;

	if (src < dst)
	{
		i = len;
		while (i > 0)
		{
			i--;
			dst[i] = src[i];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dst[i] = src[i];
			i++;
		}
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*cdst;
	const unsigned char	*csrc;

	if (!src && !dst)
		return (NULL);
	cdst = (unsigned char *)dst;
	csrc = (const unsigned char *)src;
	ft_make_copy(cdst, csrc, len);
	return (dst);
}
/*
int main()
{
	char src[] = "hello";
	char dst[] = "sdas";

	printf("%s", ft_memmove(dst, src, sizeof(dst)));
	return 0;
}*/
