#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include "key_linux.h"

# include <unistd.h>
# include <fcntl.h>

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

# define PLAYER_SPRITESHEET "assets/sprites/p_sprites.xpm"
# define COLLECT_SPRITESHEET "assets/sprites/c_sprites.xpm"
# define FIELD_SPRITESHEET "assets/sprites/f_sprites.xpm"
# define EXIT_SPRITESHEET "assets/sprites/x_sprites.xpm"
# define WALL_SPRITESHEET "assets/sprites/w_sprites.xpm"
# define WINNER_SPRITESHEET "assets/sprites/win_sprites.xpm"

typedef enum
{
	S,
	E,
	W,
	N,
	Directions
} Direction;

typedef enum
{
	COLLECT,
	FIELD,
	EXIT,
	PLAYER,
	WALL,
	WINNER,
	NUMBERS_SPRITE
} sprite_type;

typedef struct s_img
{
	void	*img;
	int		frameNumber;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
} t_img;

typedef struct s_sprites
{
	int		sprite;
	t_img	*frames[F][F];
	t_img	*spsh;
} t_sprites;

typedef struct s_spritesheet_info
{
	int		total_frames[NUMBERS_SPRITE];
	int		frames[NUMBERS_SPRITE];
	int		rows[NUMBERS_SPRITE];
	int		width[NUMBERS_SPRITE];
	int		height[NUMBERS_SPRITE];
} t_spritesheetInfo;

typedef struct s_info
{
	int					bonus;
	int					hight;
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
} t_info;

typedef struct s_checker
{
	int		**map;
	int		coins_left;
} t_checker;

// init
void		init(char **argv);
void		list();
void		ft_init_img(t_img **img, int sp);


// lists
t_img		*createNode(int frameNumber);
void		insertAtEnd(t_img** head, int frameNumber);
void		deleteNode(t_img** head, int frameNumber);

// get_frame
t_img		*ft_extract_frame(t_info *data, sprite_type sprite, int frame_x, int frame_y);
void		ft_load_img(t_info *data);
void		ft_load_frames(t_info *data, int i);

// map
void		ft_map_size(t_info *data);
void		ft_malloc_map(t_info *data);
int			ft_frame(t_info *data);

// checks
void		ft_check_outline(t_info *data);
void		ft_check_format_dotber(t_info *data);
void		ft_check_map_inputs(t_info *data);
void		ft_check_map_objects(t_info *data);
void		ft_check_is_posible(t_info *data);
void		ft_is_posible(t_info *data, int j, int i, int left);

// free
void		freedom(void **ptr);
void		ft_free_info(t_info *data);
void		ft_reset_data(t_info *data, char *name);

// finish
int			ft_exit(t_info *data);
void		ft_game_result(t_info *data);
void		ft_exit_error(t_info *data, char *err);

// draw_map
void		ft_load_img(t_info *data);
void		ft_draw_map(t_info *data);
void		ft_steps(unsigned int n);

// move_key
int			ft_press_key(int keycode, t_info *data);

// animation
void		ft_calculate_spritesheet_info(t_info *data, int frame_width, int frame_height, sprite_type sprite);
int			ft_spritesheet(t_info *data, char *path, sprite_type type);
int			ft_get_s_sheet_img(t_info *data, char *path, sprite_type sprite);
void		ft_animation(t_info *data);
void		ft_animate(t_info *data, sprite_type sprite, int direction, int *j, int *i);

#endif
