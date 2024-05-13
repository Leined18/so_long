/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:03:56 by danpalac          #+#    #+#             */
/*   Updated: 2024/02/26 12:13:17 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcpy(char *ptr, const char *s1)
{
	int	i;

	i = 0;
	if (!ptr || !s1)
		return ;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;

	ptr = malloc(ft_strlen(s1) + 1);
	if (!ptr)
		return (NULL);
	ft_strcpy(ptr, s1);
	return (ptr);
}
/*
int main()
{
	char *s1 = "tamaño";
    char *custom	= ft_strdup(NULL);
	//char *original	= strdup(NULL);

    //printf("Original: %s\n", original);
    printf("Custom  : %s\n", custom);

    free(custom);
	//free(original);

    return 0;
}*/
