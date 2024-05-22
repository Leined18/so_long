#include "so_long.h"

t_info	*ft_calculate_spritesheet_info(t_info *data, int frame_width, int frame_height)
{
	t_info	*info;
	int					columns;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		ft_error("Error reservando memoria para la información del spritesheet");
	if (frame_width == 0 || frame_height == 0)
	{
		info->spritesheetInfo.total_frames = 0;
		info->spritesheetInfo.rows = 0;
	}
	else
	{
		info->spritesheetInfo.rows = data->spritesheetInfo.height / frame_height;
		columns = data->width / frame_width;
		info->spritesheetInfo.total_frames = info->spritesheetInfo.rows * columns;
		info->spritesheetInfo.frames = columns;
		info->next = NULL;
	}
	return (info);
}

int	ft_get_image_dimensions(t_info *data, char *file_path)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(data->mlx, file_path, &width, &height);
	if (!img)
	{
		data->spritesheetInfo.width = 0;
		data->spritesheetInfo.height = 0;
		return (1);
	}
	if (data && data->spritesheetInfo.width == 0 && data->spritesheetInfo.height == 0)
	{
    	data->spritesheetInfo.width = width;
    	data->spritesheetInfo.height = height;
	}
	else
    	ft_error("Error: 'data' no ha sido asignado.");
	mlx_destroy_image(data->mlx, img);
	return (0);
}
void	ft_lst_info_add_back(t_info *data, t_info *new)
{
	t_info	*temp;

	if (data == NULL)
		ft_error("Error: 'data' es NULL.");
	if (new == NULL)
		ft_error("Error: 'new' no ha sido asignado.");
	if (data->next == NULL)
	{
		data->next = new;
		new->next = NULL;
		return;
	}
	temp = data;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	new->next = NULL;
}