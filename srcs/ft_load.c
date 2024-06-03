#include "so_long.h"

static int	load_all_spritesheets(t_info *data)
{
	int	result;

	result = 0;
	result += ft_spritesheet(data, COLLECT_SPRITESHEET, COLLECT);
	result += ft_spritesheet(data, FIELD_SPRITESHEET, FIELD);
	result += ft_spritesheet(data, EXIT_SPRITESHEET, EXIT);
	result += ft_spritesheet(data, PLAYER_SPRITESHEET, PLAYER);
	result += ft_spritesheet(data, WALL_SPRITESHEET, WALL);
	result += ft_spritesheet(data, WINNER_SPRITESHEET, WINNER);
	return (result);
}

static void	load_all_frames(t_info *data)
{
	int	i;

	i = -1;
	while (++i < NUMBERS_SPRITE)
		ft_load_frames(data, i);
}

void	ft_load_img(t_info *data)
{
	int i;

	i = -1;
	while (++i < NUMBERS_SPRITE)
		data->images[i].spritesheet = ft_calloc(1, sizeof(t_img));
	if (load_all_spritesheets(data))
		ft_exit_error(data, "Failed to load spritesheet");
	ft_allocate_sprites(data);
	load_all_frames(data);
}