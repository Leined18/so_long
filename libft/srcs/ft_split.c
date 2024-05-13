/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:47:33 by danpalac          #+#    #+#             */
/*   Updated: 2024/02/26 12:16:41 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// obtener la cantidad de letras encontradas
static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else if (s[i] == c)
			i++;
	}
	return (count);
}

// para obtener el largo de la string hasta donde se encuentre el caracter 'c'
static size_t	get_word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

// para liberar espacio del array
static void	free_array(size_t i, char **array)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
}

// para dividir la string
static char	**split(char const *s, char c, char **array, size_t words_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words_count)
	{
		while (s[j] && s[j] == c)
			j++;
		array[i] = ft_substr(s, j, get_word_len(&s[j], c));
		if (!array[i])
		{
			free_array(i, array);
			return (NULL);
		}
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
	array[i] = NULL;
	return (array);
}

// la funcion ft_split que llamara las demas funciones
char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	array = split(s, c, array, words);
	return (array);
}

/*
void print_string_array(char **arr)
{
	if (!arr)
	{
		printf("Array is NULL\n");
		return ;
	}

	for (int i = 0; arr[i]; i++)
	{
		printf("%s\n", arr[i]);
	}
}

int main()
{
	char const *input_str = "Ejemplo-de-cadena";
	char delimiter = '-';
	char **result = ft_split(input_str, delimiter);

	print_string_array(result);
	// Liberar memoria
	int i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return 0;
}*/
