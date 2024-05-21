#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include "key_linux.h"

# include <unistd.h>
# include <fcntl.h>

# define NAME "so_long"

# define RES 40
#define F_W 64
#define F_H 64
#define N_FPD 4
#define DELAY 100000

#define PLAYER_SPRITESHEET "assets/images/p_sprites.xpm"

# define COLLECT "assets/images/collect.xpm"
# define EMPTY "assets/images/empty.xpm"
# define EXIT "assets/images/exit.xpm"

# define PLAYER_UP "assets/images/p_up.xpm"
# define PLAYER_DOWN "assets/images/p_down.xpm"
# define PLAYER_LEFT "assets/images/p_left.xpm"
# define PLAYER_RIGHT "assets/images/p_right.xpm"

# define WALL "assets/images/wall.xpm"
# define WINNER "assets/images/win.xpm"

typedef enum
{
    DOWN,
    LEFT,
    RIGHT,
    UP,
    N_D
} Direction;

typedef enum
{
    COLLECT_SPRITE,
    EMPTY_SPRITE,
    EXIT_SPRITE,
    PLAYER_SPRITE,
    WALL_SPRITE,
    WINNER_SPRITE,
    NUMBERS_SPRITE
} Sprites;


typedef struct s_images
{
	void	*collect;
	void	*empty;
	void    *exit;
	void	*p_up;
    void	*p_down;
    void	*p_left;
    void	*p_right;
    void    *spritesheet[NUMBERS_SPRITE];
    void    *sprites[NUMBERS_SPRITE][N_D][N_FPD];
	void	*wall;
	void	*winner;
}	t_images;

typedef struct s_info
{
    int             hight;
    int             width;
    int             x;
    int             y;
    int             has_changed;
    int             player;
    int             count;
    int             finish;
    unsigned int    step;
    char            *txt;
    char            **map;
    void            *mlx;
    void            *win;
    char            direction;
    t_images        *images;
    Sprites         *sprite;
    Direction       *directions;
}   t_info;

typedef struct s_checker
{
	int	**map;
	int	coins_left;
}	t_checker;

// init

void init(char **argv);
// map

void	ft_map_size(t_info *data);
void	ft_malloc_map(t_info *data);
int     ft_frame(t_info *data);

// checks

void	ft_check_outline(t_info *data);
void	ft_check_format_dotber(t_info *data);
void	ft_check_map_inputs(t_info *data);
void	ft_check_map_objects(t_info *data);
void	ft_check_is_posible(t_info *data);
void	ft_is_posible(t_info *data, int j, int i, int left);

// free

void    ft_free_info(t_info *data);

// finish

int		ft_exit(t_info *data);
void	ft_game_result(t_info *data);

// draw_map

void    ft_load_spritesheet(t_info *data, Sprites sprite, char *sheet_path);
void    ft_load_img(t_info *data);
void	ft_draw_map(t_info *data);
void	ft_steps(unsigned int n);

// move_key

int     ft_press_key(int keycode, t_info *data);

// animation
void    ft_animate_sprites(Sprites sprite , Direction direction, t_info *data);

#endif
