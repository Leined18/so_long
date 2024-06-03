# include "so_long.h"

void	ft_animate_player(t_info *data)
{
	static int	frame = 0;
	static int	count = 0;

	if (count == 0)
	{
		if (frame == 0)
			frame = 1;
		else
			frame = 0;
	}
	count++;
	if (count == 10)
		count = 0;
	data->player->img = data->images[PLAYER].frames[0][frame]->img;
}