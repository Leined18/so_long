#include "so_long.h"

void	*new_win(void *mlx_ptr, int height, int width, char *name)
{
	return (mlx_new_window(mlx_ptr, width * RES, height * RES, name));
}

void	init_mlx(t_mlx *mlx, t_map *map)
{
	if (mlx->map->height * RES > MAC_H || mlx->map->width * RES > MAC_W)
		ft_error("map error: map is too large");
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		ft_error("mlx failed");
	mlx->win_ptr = new_win(mlx->mlx_ptr, map->height, map->width, NAME);
	if (!mlx->win_ptr)
		ft_error("mlx failed");
}