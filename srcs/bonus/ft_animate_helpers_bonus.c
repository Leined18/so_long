#include "so_long_bonus.h"

static void	ft_animate_player(t_bonus *data, t_info2 *info2)
{
	static int	sp = 0;
	static int	count = 0;
	int			delay;

	delay = DELAY;
	count++;
	if (count >= delay)
	{
		count = 0;
		sp++;
		if (data->info.img[PLAYER].frames[info2->direction][sp] == NULL)
			sp = 0;
	}
	if (data->info.player.direction == 'N')
		mlx_put_image_to_window(data->info.grafics.mlx, data->info.grafics.win,
			data->info.img[PLAYER].frames[N][sp]->img, info2->x * RES, info2->y * RES);
	else if (data->info.player.direction == 'S')
		mlx_put_image_to_window(data->info.grafics.mlx, data->info.grafics.win,
			data->info.img[PLAYER].frames[S][sp]->img, info2->x * RES, info2->y * RES);
	else if (data->info.player.direction == 'E')
		mlx_put_image_to_window(data->info.grafics.mlx, data->info.grafics.win,
			data->info.img[PLAYER].frames[E][sp]->img, info2->x * RES, info2->y * RES);
	else if (data->info.player.direction == 'W')
		mlx_put_image_to_window(data->info.grafics.mlx, data->info.grafics.win,
			data->info.img[PLAYER].frames[W][sp]->img, info2->x * RES, info2->y * RES);
	data->info.player.y = info2->y;
	data->info.player.x = info2->x;
}

void	ft_animate(t_bonus *data, t_info2 *info2)
{
	static int	count = 0;
	int			delay;

	delay = DELAY;
	if (info2->sprite == PLAYER)
	{
		ft_animate_player(data, info2);
		return ;
	}
	count++;
	if (count >= delay)
	{
		count = 0;
		info2->anim->frame++;
		if (data->info.img[info2->sprite].frames[info2->direction][info2->anim->frame] == NULL)
			info2->anim->frame = 0;
	}
	data->info.img_ptr = data->info.img[info2->sprite].frames[info2->direction][info2->anim->frame]->img;
	mlx_put_image_to_window(data->info.grafics.mlx, data->info.grafics.win, data->info.img_ptr, info2->x * RES, info2->y * RES);
}
