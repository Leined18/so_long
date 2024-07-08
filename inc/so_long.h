/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 05:29:22 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/08 05:29:23 by danpalac         ###   ########.fr       */
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

# define MAC_W 4096
# define MAC_H 2304

# define DELAY 10000
# define FALSE 0
# define TRUE 1
# define UP 9
# define DOWN 4
# define RIGHT 8
# define LEFT 7
# define ESC 53

# ifndef BONUS
#  define BONUS 0
# endif

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
	ENEMY,
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

typedef struct s_grafics
{
	void				*mlx;
	void				*win;
	t_img				*img;
	int					width;
	int					height;
	int					x;
	int					y;
	char				**map;
	char				*txt;
}						t_grafics;

typedef struct s_sprites
{
	int					sprite;
	t_img				*frames[F][F];
	t_img				*spsh;
}						t_sprites;

typedef struct s_spritesheet_info
{
	int					total_frames;
	int					frames;
	int					rows;
	int					width;
	int					height;
}						t_spritesheetInfo;

typedef struct s_obj
{
	int					x;
	int					y;
	unsigned int		step;
	int					coins;
	char				direction;
	int					alive;
	int					open;
	t_img				*img;
}						t_obj;

typedef struct s_info
{
	int					enemies;
	int					has_changed;
	int					running;
	int					finish;
	void				*img_ptr;
	t_obj				player;
	t_grafics			grafics;
	t_sprites			img[NUMBERS_SPRITE];
	t_spritesheetInfo	s_info[NUMBERS_SPRITE];
}						t_info;

typedef struct s_checker
{
	int					**map;
	int					coins_left;
}						t_checker;

// init
void					init_bonus(char **argv);
void					init(char **argv);
void					ft_init_img(t_img **img, int sp);

// lists
t_img					*createNode(int framenumber);
void					insertAtEnd(t_img **head, int framenumber);
void					deleteNode(t_img **head, int framenumber);

// get_frame
t_img					*ft_extract_frame(t_info *data, int sprite, int frame_x,
							int frame_y);
void					ft_load_img(t_info *data);
void					ft_load_frames(t_info *data, int i);

// map
void					ft_map_size(t_info *data);
void					ft_malloc_map(t_info *data);
int						ft_frame(t_info *data);

// checks
void					ft_general_check(t_info *data);
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

// Frame

void					ft_calculate_spritesheet_info(t_info *data,
							int frame_width, int frame_height, int sprite);
int						ft_spritesheet(t_info *data, char *path, int type);
int						ft_get_s_sheet_img(t_info *data, char *path,
							int sprite);
#endif
