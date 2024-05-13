/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:56:53 by danpalac          #+#    #+#             */
/*   Updated: 2024/02/26 10:18:32 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	if (!src)
		return (dest);
	if (!dest)
		return (NULL);
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest);
}

static char	*ft_strcat(char *dest, const char *src)
{
	char	*ptr;

	ptr = dest;
	while (*ptr)
		ptr++;
	while (*src)
		*ptr++ = *src++;
	*ptr = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	total_len;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	total_len = len1 + len2;
	ptr = (char *)malloc((total_len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strcpy(ptr, (char *)s1);
	ft_strcat(ptr, (char *)s2);
	return (ptr);
}
/*
int main()
{
    const char *cadena1 = "Hola, ";
    const char *cadena2 = "mundo!";

    char *resultado = ft_strjoin(NULL, NULL);

    printf("Cadena resultante: %s\n", resultado);

    // Libera la memoria asignada para la cadena resultante
    free(resultado);

    return 0;
}*/
