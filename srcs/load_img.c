#include "so_long.h"

void	load1(t_info *data)
{
	ft_load_spritesheet(data, COLLECT_SPRITE, COLLECT_SPRITESHEET);
	ft_load_spritesheet(data, FIELD_SPRITE, FIELD_SPRITESHEET);
	ft_load_spritesheet(data, EXIT_SPRITE, EXIT_SPRITESHEET);
	ft_load_spritesheet(data, WALL_SPRITE, WALL_SPRITESHEET);
	ft_load_spritesheet(data, WINNER_SPRITE, WINNER_SPRITESHEET);
	ft_load_spritesheet(data, PLAYER_SPRITE, PLAYER_SPRITESHEET);
}
void	ft_load_img(t_info *data)
{
	load1(data);
	ft_successful("images 1 loaded successfully");
}