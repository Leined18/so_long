#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"

# include <unistd.h>
# include <fcntl.h>

# define RES 64
# define MAC_W 4096
# define MAC_H 2304
# define NAME "so_long"

# define COLLECT	"../assets/images/collect.xpm"
# define EMPTY		"../assets/images/empty.xpm"
# define EXIT		"../assets/images/exit.xpm"
# define PLAYER		"../assets/images/player.xpm"
# define WALL		"../assets/images/wall.xpm"
# define WINNER		"../assets/images/win.xpm"

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

// funtions

void	ft_map_size(t_info_map *data);
void	ft_malloc_map(t_info_map *data);

#endif
