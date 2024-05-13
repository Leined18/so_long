/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:26:06 by danpalac          #+#    #+#             */
/*   Updated: 2024/02/26 12:19:04 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int nbr)
{
	int	len;

	len = 0;
	if (nbr < 1)
		len++;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static long long	make_positive(long long n)
{
	long long	nb;

	nb = 1;
	if (n < 0)
		nb *= -n;
	else
		nb *= n;
	return (nb);
}

static char	*allocate_str(size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	int				sign;
	int				len;
	char			*str;

	sign = 0;
	if (n < 0)
		sign = 1;
	len = count_digits(n);
	str = allocate_str(len);
	if (!str)
		return (NULL);
	*(str + len) = '\0';
	nbr = make_positive(n);
	while (len--)
	{
		*(str + len) = '0' + nbr % 10;
		nbr /= 10;
	}
	if (sign)
		*(str) = '-';
	return (str);
}

/*
int	main(void)
{
	int		n;
	char	*result;

	scanf("%d", &n); // Lee un entero de la entrada estándar
	result = ft_itoa(n); // Convierte el entero a cadena de caracteres
	printf("%s\n", result); // Imprime la cadena resultante
	free(result); // Libera la memoria asignada para result
	return (0);
}*/
