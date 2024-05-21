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
#define FALSE 0
#define TRUE 1

#define PLAYER_SPRITESHEET "assets/images/p_sprites.xpm" // done
#define COLLECT_SPRITESHEET "assets/images/c_sprites.xpm" // done
#define FIELD_SPRITESHEET "assets/images/f_sprites.xpm" // done
#define EXIT_SPRITESHEET "assets/images/x_sprites.xpm"
#define WALL_SPRITESHEET "assets/images/w_sprites.xpm" // done
#define WINNER_SPRITESHEET "assets/images/win_sprites.xpm"

typedef enum
{
    DOWN,
    LEFT,
    RIGHT,
    UP,
    N_D
} direction;

typedef enum
{
    COLLECT_SPRITE,
    FIELD_SPRITE,
    EXIT_SPRITE,
    PLAYER_SPRITE,
    WALL_SPRITE,
    WINNER_SPRITE,
    NUMBERS_SPRITE
} sprite_type;


typedef struct s_sprites
{
    void    *spritesheet[NUMBERS_SPRITE];
    void    *sprites[NUMBERS_SPRITE][N_D][N_FPD];
}	t_sprites;



typedef struct s_info
{
    int             hight;
    int             width;
    int             px;
    int             py;
    int             has_changed;
    int             running;
    int             player;
    int             count;
    int             finish;
    unsigned int    step;
    char            *txt;
    char            **map;
    void            *mlx;
    void            *win;
    char            direction;
    t_sprites       images;
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

void    ft_load_spritesheet(t_info *data, sprite_type sprite, char *sheet_path);
void    ft_load_img(t_info *data);
void	ft_draw_map(t_info *data);
void	ft_steps(unsigned int n);

// move_key

int     ft_press_key(int keycode, t_info *data);

// animation
void    ft_animate_sprites(sprite_type sprite , direction direction, t_info *data);

#endif
