/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:06:26 by danpalac          #+#    #+#             */
/*   Updated: 2024/06/12 10:15:08 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include "libft.h"

int		ft_putnbr(int n);
int		ft_putchar(int c);
int		ft_printf(const char *str, ...);
long	ft_abs(long n);
void	ft_putbase_fd(int nbr, const char *base, int fd);
int		ft_puthexa(unsigned long n, char format);
int		ft_putstr(char const *s);
int		ft_putunsigned(unsigned long n);
int		ft_putaddress(void *format);

#endif
