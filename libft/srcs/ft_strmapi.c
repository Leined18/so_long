/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:01:01 by danpalac          #+#    #+#             */
/*   Updated: 2024/06/05 12:28:34 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Ejemplo
char	ft_toupper(unsigned int i, char c)
{
	size_t			len;
	char			*result;
	unsigned int	i;
	size_t			len;
	char			*result;
	int				i;

	if ((unsigned char)c >= 'a' && (unsigned char )c <= 'z')
		c -= 32;
	return (c);
}*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*result;
	int		i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
int	main(void) {
	char *s = "hello, world";
	printf("%s\n", ft_strmapi(s,ft_toupper));

	return (0);
}*/
