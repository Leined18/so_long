/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:01:58 by danpalac          #+#    #+#             */
/*   Updated: 2024/06/05 12:28:05 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*//ESTOS SON EJEMPLOS DE FUNCIONES QUE SE PUEDEN USAR EN ft_STRITERI
static void	ft_tolower(unsigned int index, char *c)
{
	if (*c >= 'A' && *c <= 'Z')
	{
		*c += 32;
	}
}
static void	noalpha_space(unsigned int index, char *c)
{
	size_t			len;
	unsigned int	i;
	int				len;
	int				i;

	if (!(*c >= 'a' && *c <= 'z')){
		*c = ' ';
	}
}*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t			len;
	unsigned int	i;

	if (!s || !f)
		return ;
	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
}
/*
int	main(void) {
	char s[] = "HeLlo..""MIAU""..WorLDDD";
	ft_striteri(NULL, ft_tolower);
	printf("%s\n", s);

	return (0);
}*/
