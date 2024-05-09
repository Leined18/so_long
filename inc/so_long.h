#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include "key_linux.h"

# include <unistd.h>
# include <fcntl.h>

# define NAME "so_long"

# define RES 64

# define COLLECT "../assets/images/collect.xpm"
# define EMPTY "../assets/images/empty.xpm"
# define EXIT "../assets/images/exit.xpm"
# define PLAYER "../assets/images/player.xpm"
# define WALL "../assets/images/wall.xpm"
# define WINNER "../assets/images/win.xpm"

typedef struct s_images
{
	void	*collect;
	void	*empty;
	void	*exit;
	void	*player;
	void	*wall;
	void	*winner;
}	t_images;

typedef struct s_info_map
{
	int				hight;
	int				width;
	int				x;
	int				y;
	int				player;
	int				count;
	int				finish;
	unsigned int	step;
	char			*txt;
	char			**map;
	void			*mlx;
	void			*win;
	t_images		*images;
}	t_info_map;

// map

void	ft_map_size(t_info_map *data);
void	ft_malloc_map(t_info_map *data);

// checks

void	ft_check_outline(t_info_map *data);
void	ft_check_format_dotber(t_info_map *data);
void	ft_check_map_inputs(t_info_map *data);
void	ft_check_map_objects(t_info_map *data);
// void	ft_check_is_posible(t_info_map *data);

// finish

int		ft_exit(t_info_map *data);
void	ft_game_result(t_info_map *data);

// draw_map

void	ft_draw_map(t_info_map *data);
void	ft_steps(unsigned int n);

// move_key

int	ft_press_key(int keycode, t_info_map *data);

#endif
