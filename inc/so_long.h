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
# define DELAY 100000
# define FALSE 0
# define TRUE 1

# define PLAYER_SPRITESHEET "assets/sprites/p_sprites.xpm"
# define COLLECT_SPRITESHEET "assets/sprites/c_sprites.xpm"
# define FIELD_SPRITESHEET "assets/sprites/f_sprites.xpm"
# define EXIT_SPRITESHEET "assets/sprites/x_sprites.xpm"
# define WALL_SPRITESHEET "assets/sprites/w_sprites.xpm"
# define WINNER_SPRITESHEET "assets/sprites/win_sprites.xpm"

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


typedef struct s_img {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int     width;
    int     height;
}               t_img;



typedef struct s_spritesheet_info
{
    int total_frames[NUMBERS_SPRITE];
    int frames[NUMBERS_SPRITE];
    int rows[NUMBERS_SPRITE];
    int width[NUMBERS_SPRITE];
    int height[NUMBERS_SPRITE];
} t_spritesheetInfo;

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
    struct
    {
        void   *spritesheet[NUMBERS_SPRITE];
        void    ****sprites;
        t_img    *img[NUMBERS_SPRITE];
        t_img    *spritesheet_img[NUMBERS_SPRITE];
    } images;
    void            *img;
    t_spritesheetInfo spritesheetInfo;
} t_info;

typedef struct s_checker
{
    int **map;
    int coins_left;
} t_checker;

// init
void init(char **argv);

// map
void ft_map_size(t_info *data);
void ft_malloc_map(t_info *data);
int ft_frame(t_info *data);

// checks
void ft_check_outline(t_info *data);
void ft_check_format_dotber(t_info *data);
void ft_check_map_inputs(t_info *data);
void ft_check_map_objects(t_info *data);
void ft_check_is_posible(t_info *data);
void ft_is_posible(t_info *data, int j, int i, int left);

// free
void ft_free_info(t_info *data, sprite_type type);;
void ft_free_data(t_info *data, sprite_type type);
void ft_reset_data(t_info *data, char *name);

// finish
int ft_exit(t_info *data);
void ft_game_result(t_info *data);

// draw_map
int	ft_load_spritesheet(t_info *data, sprite_type sprite, char *spritesheet_path);
void ft_load_img(t_info *data);
void ft_draw_map(t_info *data);
void ft_steps(unsigned int n);

// move_key
int ft_press_key(int keycode, t_info *data);

// animation
void ft_lst_info_add_back(t_info *data, t_info *new);
void ft_animate_sprites(sprite_type sprite, direction direction, t_info *data);
void ft_calculate_spritesheet_info(t_info *data, int frame_width, int frame_height, sprite_type sprite);
int ft_get_image_dimensions(t_info *data, char *file_path, sprite_type sprite);
int ft_spritesheet(t_info *data, char *path, sprite_type type);
void	ft_allocate_sprites(t_info *data);
#endif
