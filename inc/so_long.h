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
# define HOUR 4

typedef struct s_map
{
    void **map;
    int     width;
    int     height;

} t_map;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		moves;
	t_map	*map;
}				t_mlx;

// init_mlx.c
void	init_mlx(t_mlx *mlx, t_map *map);
void	*new_win(void *mlx_ptr, int height, int width, char *name);

#endif
