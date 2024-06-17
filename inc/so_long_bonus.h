/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:19:24 by danpalac          #+#    #+#             */
/*   Updated: 2024/06/12 13:56:45 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "key_linux.h"
# include "mlx.h"
# include <fcntl.h>
# include <unistd.h>
# define NAME_B "so_long_bonus"
# include "so_long.h"

typedef struct s_grafics
{
	void				*mlx;
	void				*win;
	t_img				*img;
	int					width;
	int					height;
}						t_grafics;

typedef struct s_obj
{
	int					x;
	int					y;
	int					moves;
	int					collectibles;
	char				direction;
	t_img				*img;
}						t_obj;

// Estructura para una lista enlazada de objetos
typedef struct s_obj_node
{
	t_obj				*obj;
	struct s_obj_node	*next;
}						t_obj_node;

// Estructura para el mapa del juego
typedef struct s_map
{
	int					x;
	int					y;
	char				**map;
}						t_map;

// Estructura principal del juego
typedef struct s_bonus
{
	char				*arg;
	t_grafics			grafics;
	t_map				map;
	t_obj_node			*player;
	t_obj_node			*collectibles;
	t_obj_node			*exit;
	t_obj_node			*walls;
	t_obj_node			*winner;
	t_obj_node			*field;
	t_info				info;
}						t_bonus;

void	init_bonus(int argc, char **argv);

#endif
