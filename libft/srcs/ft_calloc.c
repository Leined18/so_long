/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:28:38 by danpalac          #+#    #+#             */
/*   Updated: 2024/02/08 11:36:01 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	s_zero(void *s, size_t n)
{
	while (n--)
		*(unsigned char *)s++ = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;

	if (count == 0 && size == 0 && SIZE_MAX / count < size)
		return (NULL);
	memory = malloc(count * size);
	if (!memory)
		return (NULL);
	s_zero(memory, count * size);
	return (memory);
}
/*
int main()
{
    char *i1 = calloc(2, sizeof(char));
    char *i2 = ft_calloc(0, sizeof(char));

	if (memcmp(i1, i2, 10 * sizeof(char)) == 0)
		printf("Memory contents are the same\n");
	else
		printf("Memory contents are different\n");


    printf("i1: %p\n", (void *)i1);
    printf("i2: %p\n", (void *)i2);

    free(i1);
    free(i2);

    return 0;
}*/
