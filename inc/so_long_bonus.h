/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:19:24 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/08 05:25:41 by danpalac         ###   ########.fr       */
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

# define ENEMY_SPRITESHEET "assets/sprites/e_sprites.xpm"

typedef struct s_info2
{
	int		direction;
	int		x;
	int		y;
	int		sprite;
	int		open;
	t_obj	enemy;
}			t_info2;

typedef struct s_bonus
{
	t_info2	info2;
	t_info	info;
}			t_bonus;

void		init_bonus(char **argv);
void		ft_animation(t_bonus *data);
void		ft_draw_map_bonus(t_bonus *data);
void		ft_check_map_inputs_bonus(t_bonus *data);
void		ft_check_map_objects_bonus(t_bonus *data);
int			ft_press_key_bonus(int keycode, t_bonus *data);
int			move_enemy_loop(t_bonus *data);
void		ft_animation(t_bonus *data);
void		ft_animate(t_bonus *data, int direction, int *j, int *i);
void		ft_draw(t_bonus *data, int x, int y, int sprite);
void		handle_tile(t_bonus *data, char tile, int x, int y);

#endif
