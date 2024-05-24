#include "so_long.h"

void	load1(t_info *data)
{
	if (ft_load_spritesheet(data, COLLECT_SPRITE, COLLECT_SPRITESHEET) != 0)
		ft_error("Error en ft_load_spritesheet con COLLECT_SPRITESHEET");
	else if (ft_load_spritesheet(data, FIELD_SPRITE, FIELD_SPRITESHEET) != 0)
		ft_error("Error en ft_load_spritesheet con FIELD_SPRITESHEET");
	else if (ft_load_spritesheet(data, EXIT_SPRITE, EXIT_SPRITESHEET) != 0)
		ft_error("Error en ft_load_spritesheet con EXIT_SPRITESHEET");
	else if (ft_load_spritesheet(data, PLAYER_SPRITE, PLAYER_SPRITESHEET) != 0)
		ft_error("Error en ft_load_spritesheet con PLAYER_SPRITESHEET");
	else if (ft_load_spritesheet(data, WALL_SPRITE, WALL_SPRITESHEET) != 0)
		ft_error("Error en ft_load_spritesheet con WALL_SPRITESHEET");
	else if (ft_load_spritesheet(data, WINNER_SPRITE, WINNER_SPRITESHEET) != 0)
		ft_error("Error en ft_load_spritesheet con WINNER_SPRITESHEET");
	else
		ft_successful("spritesheets loaded successfully");
}

void	ft_load_info_spritesheet(t_info *data)
{
	if (ft_spritesheet(data, COLLECT_SPRITESHEET, COLLECT_SPRITE) == 1)
		ft_error("Error en ft_spritesheet con COLLECT_SPRITESHEET");
	if (ft_spritesheet(data, FIELD_SPRITESHEET, FIELD_SPRITE) == 1)
		ft_error("Error en ft_spritesheet con FIELD_SPRITESHEET");
	if (ft_spritesheet(data, EXIT_SPRITESHEET, EXIT_SPRITE) == 1)
		ft_error("Error en ft_spritesheet con EXIT_SPRITESHEET");
	if (ft_spritesheet(data, WALL_SPRITESHEET, WALL_SPRITE) == 1)
		ft_error("Error en ft_spritesheet con WALL_SPRITESHEET");
	if (ft_spritesheet(data, WINNER_SPRITESHEET, WINNER_SPRITE) == 1)
		ft_error("Error en ft_spritesheet con WINNER_SPRITESHEET");
	if (ft_spritesheet(data, PLAYER_SPRITESHEET, PLAYER_SPRITE) == 1)
		ft_error("Error en ft_spritesheet con PLAYER_SPRITESHEET");
	ft_successful("spritesheets info loaded successfully");
}

int	ft_spritesheet(t_info *data, char *path, sprite_type type)
{
	int	i;
	char	*sprite_type_info[] = {
		"COLLECT_SPRITE",
		"FIELD_SPRITE",
		"EXIT_SPRITE",
		"PLAYER_SPRITE",
		"WALL_SPRITE",
		"WINNER_SPRITE"
	};

	i = ft_get_image_dimensions(data, path, type);
	if (!data->spritesheetInfo.width[type] || !data->spritesheetInfo.height[type])
		return (1);
	ft_calculate_spritesheet_info(data, RES, RES, type);
	printf("	total_frames[%d]:	%d type: [%s]\n", type, data->spritesheetInfo.total_frames[type], sprite_type_info[type]);
	printf("	frames[%d]: 		%d type: [%s]\n", type, data->spritesheetInfo.frames[type], sprite_type_info[type]);
	printf("	rows[%d]:		%d type: [%s]\n", type, data->spritesheetInfo.rows[type], sprite_type_info[type]);
	printf("	width[%d]:		%d type: [%s]\n", type, data->spritesheetInfo.width[type], sprite_type_info[type]);
	printf("	height[%d]:		%d type: [%s]\n", type, data->spritesheetInfo.height[type], sprite_type_info[type]);
	return (i);
}
void	ft_load_img(t_info *data)
{
	ft_load_info_spritesheet(data);
	ft_successful("images info_spritesheet loaded successfully");
	ft_allocate_sprites(data, COLLECT_SPRITE);
	ft_allocate_sprites(data, FIELD_SPRITE);
	ft_allocate_sprites(data, EXIT_SPRITE);
	ft_allocate_sprites(data, PLAYER_SPRITE);
	ft_allocate_sprites(data, WALL_SPRITE);
	ft_allocate_sprites(data, WINNER_SPRITE);
	ft_successful("images allocated successfully");
	load1(data);
	ft_successful("images loaded successfully");
}