#include "so_long.h"

void	load1(t_info *data)
{
	ft_load_spritesheet(data, COLLECT_SPRITE, COLLECT_SPRITESHEET);
	ft_load_spritesheet(data, FIELD_SPRITE, FIELD_SPRITESHEET);
	ft_load_spritesheet(data, EXIT_SPRITE, EXIT_SPRITESHEET);
	ft_load_spritesheet(data, WALL_SPRITE, WALL_SPRITESHEET);
	ft_load_spritesheet(data, WINNER_SPRITE, WINNER_SPRITESHEET);
	ft_load_spritesheet(data, PLAYER_SPRITE, PLAYER_SPRITESHEET);
	ft_successful("spritesheets loaded successfully");
}

void	ft_load_info_spritesheet(t_info *data)
{
	if (ft_spritesheet(data, (char *)COLLECT_SPRITESHEET))
	    ft_error("Error en ft_spritesheet con COLLECT_SPRITESHEET");
	if (ft_spritesheet(data, (char *)FIELD_SPRITESHEET))
	    ft_error("Error en ft_spritesheet con FIELD_SPRITESHEET");
	if (ft_spritesheet(data, (char *)EXIT_SPRITESHEET))
	    ft_error("Error en ft_spritesheet con EXIT_SPRITESHEET");
	if (ft_spritesheet(data, (char *)WALL_SPRITESHEET))
	    ft_error("Error en ft_spritesheet con WALL_SPRITESHEET");
	if (ft_spritesheet(data, (char *)WINNER_SPRITESHEET))
	    ft_error("Error en ft_spritesheet con WINNER_SPRITESHEET");
	if (ft_spritesheet(data, (char *)PLAYER_SPRITESHEET))
	    ft_error("Error en ft_spritesheet con PLAYER_SPRITESHEET");
	ft_successful("spritesheets info loaded successfully");
}

int	ft_spritesheet(t_info *data, char *path)
{
	t_info *new;
	t_info *temp;
	int i;

	temp = data;
	i = ft_get_image_dimensions(data, path);
	new = ft_calculate_spritesheet_info(data, F_W, F_H);
	if (!new)
		ft_error("Error creando información del spritesheet");
	ft_lst_info_add_back(temp, new);
	return (i);
}
void	ft_load_img(t_info *data)
{
	t_info *temp;

	ft_load_info_spritesheet(data);
	temp = data;
	temp = temp->next;
	ft_successful("images info_spritesheet loaded successfully");
	ft_allocate_sprites(&(data->images.sprites), &(data->images.spritesheet), (t_spritesheetInfo *)data->next);	
	ft_successful("images allocated successfully");
	load1(data);
	ft_successful("images loaded successfully");
}