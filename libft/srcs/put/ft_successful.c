/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_successful.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:29:08 by danpalac          #+#    #+#             */
/*   Updated: 2024/06/05 12:29:11 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_successful(char *success)
{
	ft_putstr_fd("\x1b[32mSuccessful\x1b[0m\n", 2);
	if (success && *success)
	{
		ft_putstr_fd(success, 2);
		write(2, "\n", 1);
	}
}
