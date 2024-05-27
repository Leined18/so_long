#include "so_long.h"

int	ft_spritesheet(t_info *data, char *path, sprite_type type)
{
	int	i;

	i = ft_get_s_sheet_img(data, path, type);
	if (!data->s_info.width[type] || !data->s_info.height[type])
		return (1);
	ft_calculate_spritesheet_info(data, RES, RES, type);
	printf("Sprite %d: %d %d %d %d %d\n", type, data->s_info.width[type],
		data->s_info.height[type], data->s_info.frames[type],
		data->s_info.rows[type], data->s_info.total_frames[type]);
	return (i);
}
void	ft_load_frames(t_info *data, int i)
{
    int r;
    int f;
    int count;

    count = 0;
    while (count < data->s_info.total_frames[i] && count < F)
    {
        r = 0;
        while (r < data->s_info.rows[i] && count < data->s_info.total_frames[i] && count < F)
        {
            f = 0;
            while (f < data->s_info.frames[i] && count < data->s_info.total_frames[i] && count < F)
            {
                data->images[i].frames[r][f] = ft_extract_frame(data, i, f * RES, r * RES);
                count++;
                f++;
            }
            r++;
        }
    }
}
