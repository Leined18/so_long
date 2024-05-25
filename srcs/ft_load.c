#include "so_long.h"

int	ft_spritesheet(t_info *data, char *path, sprite_type type)
{
	int	i;
	
	i = ft_get_s_sheet_img(data, path, type);
	if (!data->s_info.width[type] || !data->s_info.height[type])
		return (1);
	ft_calculate_spritesheet_info(data, RES, RES, type);
	return (i);
}
void	ft_load_img(t_info *data)
{
	int i;

	ft_allocate_sprites(data);
	i = 0;
	i = ft_spritesheet(data, COLLECT_SPRITESHEET, COLLECT);
	i = ft_spritesheet(data, FIELD_SPRITESHEET, FIELD);
	i = ft_spritesheet(data, EXIT_SPRITESHEET, EXIT);
	i = ft_spritesheet(data, PLAYER_SPRITESHEET, PLAYER);
	i = ft_spritesheet(data, WALL_SPRITESHEET, WALL);
	i = ft_spritesheet(data, WINNER_SPRITESHEET, WINNER);
	if (i)
		ft_exit_error(data, "Error\nFailed to load spritesheet\n");
	data->images[COLLECT].frames[0] = ft_extract_frame(data, COLLECT, 0, 0);
	data->images[FIELD].frames[0] = ft_extract_frame(data, FIELD, 0, 0);
	data->images[EXIT].frames[0] = ft_extract_frame(data, EXIT, 0, 0);
	data->images[PLAYER].frames[0] = ft_extract_frame(data, PLAYER, 0, 0);
	data->images[WALL].frames[0] = ft_extract_frame(data, WALL, 0, 0);
	data->images[WINNER].frames[0] = ft_extract_frame(data, WINNER, 0, 0);
	if (!data->images[COLLECT].frames[0] || !data->images[FIELD].frames[0]
		|| !data->images[EXIT].frames[0] || !data->images[PLAYER].frames[0]
		|| !data->images[WALL].frames[0] || !data->images[WINNER].frames[0])
		ft_exit_error(data, "Error\nFailed to load spritesheet\n");
}