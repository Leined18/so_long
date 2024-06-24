/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:53:48 by danpalac          #+#    #+#             */
/*   Updated: 2024/06/24 13:32:18 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freedom(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_error("Usage: ./program_name map_file");
		return (1);
	}
	if (BONUS)
	{
		ft_printf("Bonus\n");
		init_bonus(argv);
	}
	else
	{
		init(argv);
	}
	return (0);
}
