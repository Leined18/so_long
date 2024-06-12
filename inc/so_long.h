/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:19:24 by danpalac          #+#    #+#             */
/*   Updated: 2024/06/12 13:57:23 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "key_linux.h"
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <unistd.h>

# define NAME "so_long"

# define RES 40
# define N_FPD 4
# define F 20
# define DELAY 10000
# define FALSE 0
# define TRUE 1
# define UP 9
# define DOWN 4
# define RIGHT 8
# define LEFT 7
# define ESC 53
# define BONUS FALSE
#if (BONUS == TRUE)
	# include "so_long_bonus.h"
#endif

# define PLAYER_SPRITESHEET "assets/sprites/p_sprites.xpm"
# define COLLECT_SPRITESHEET "assets/sprites/c_sprites.xpm"
# define FIELD_SPRITESHEET "assets/sprites/f_sprites.xpm"
# define EXIT_SPRITESHEET "assets/sprites/x_sprites.xpm"
# define WALL_SPRITESHEET "assets/sprites/w_sprites.xpm"
# define WINNER_SPRITESHEET "assets/sprites/win_sprites.xpm"

typedef enum e_direction
{
	S,
	E,
	W,
	N,
	Directions
}						t_direction;

typedef enum e_sp
{
	COLLECT,
	FIELD,
	EXIT,
	PLAYER,
	WALL,
	WINNER,
	NUMBERS_SPRITE
}						t_spr;

typedef struct s_img
{
	void				*img;
	int					framenumber;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					width;
	int					height;
}						t_img;

typedef struct s_sprites
{
	int					sprite;
	t_img				*frames[F][F];
	t_img				*spsh;
}						t_sprites;

typedef struct s_spritesheet_info
{
	int					total_frames[NUMBERS_SPRITE];
	int					frames[NUMBERS_SPRITE];
	int					rows[NUMBERS_SPRITE];
	int					width[NUMBERS_SPRITE];
	int					height[NUMBERS_SPRITE];
}						t_spritesheetInfo;

typedef struct s_info
{
	int					bonus;
	int					lost;
	int					height;
	int					width;
	int					px;
	int					py;
	int					has_changed;
	int					running;
	int					player;
	int					coins;
	int					finish;
	unsigned int		step;
	char				*txt;
	char				**map;
	void				*mlx;
	void				*win;
	char				direction;
	void				*img_ptr;
	t_sprites			img[NUMBERS_SPRITE];
	t_spritesheetInfo	s_info;
}						t_info;

typedef struct s_checker
{
	int					**map;
	int					coins_left;
}						t_checker;

// init
void					init(char **argv);
void					ft_init_img(t_img **img, int sp);
// lists
t_img					*createNode(int framenumber);
void					insertAtEnd(t_img **head, int framenumber);
void					deleteNode(t_img **head, int framenumber);

// get_frame
t_img					*ft_extract_frame(t_info *data, t_spr sprite,
							int frame_x, int frame_y);
void					ft_load_img(t_info *data);
void					ft_load_frames(t_info *data, int i);

// map
void					ft_map_size(t_info *data);
void					ft_malloc_map(t_info *data);
int						ft_frame(t_info *data);

// checks
void					ft_check_outline(t_info *data);
void					ft_check_format_dotber(t_info *data);
void					ft_check_map_inputs(t_info *data);
void					ft_check_map_objects(t_info *data);
void					ft_check_is_posible(t_info *data);
void					ft_is_posible(t_info *data, int j, int i, int left);

// free
void					freedom(void **ptr);
void					ft_free_info(t_info *data);
void					ft_reset_data(t_info *data, char *name);

// finish
int						ft_exit(t_info *data);
void					ft_game_result(t_info *data);
void					ft_exit_error(t_info *data, char *err);

// draw_map
void					ft_load_img(t_info *data);
void					ft_draw_map(t_info *data);
void					ft_steps(t_info *data);

// move_key
int						ft_press_key(int keycode, t_info *data);

// animation

void					init_bonus(int argc, char **argv);
void					ft_calculate_spritesheet_info(t_info *data,
							int frame_width, int frame_height,
							t_spr sprite);
int						ft_spritesheet(t_info *data, char *path,
							t_spr type);
int						ft_get_s_sheet_img(t_info *data, char *path,
							t_spr sprite);
void					ft_animation(t_info *data);

#endif