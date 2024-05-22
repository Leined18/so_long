#include "so_long.h"

#include "so_long.h"

void	ft_allocate_single_sprite(void ****sprite, t_info *temp, sprite_type type)
{
	unsigned int	j;

	if (temp->spritesheetInfo.rows[type] >= 500 || temp->spritesheetInfo.frames[type] >= 50)
		ft_error("Invalid number of rows or frames");
	if (temp->spritesheetInfo.rows[type] <= 0 || temp->spritesheetInfo.frames[type] <= 0)
		ft_error("Invalid number of rows or frames");
	*sprite = malloc(temp->spritesheetInfo.rows[type] * sizeof(void *));
	if (!*sprite)
		ft_error("Error allocating memory for the second level");
	j = 0;
	while (j < temp->spritesheetInfo.rows[type])
	{
		(*sprite)[j] = malloc(temp->spritesheetInfo.frames[type] * sizeof(void *));
		if (!(*sprite)[j])
			ft_error("Error allocating memory for the third level");
		j++;
	}
}

void	ft_allocate_sprites(void ****sprite, void ***spritesheet, t_info *data, sprite_type type)
{
	int i;

	*sprite = malloc(NUMBERS_SPRITE * sizeof(void **));
	if (!*sprite)
		ft_error("Error reservando memoria para el primer nivel");
	*spritesheet = malloc(NUMBERS_SPRITE * sizeof(void *));
	if (!*spritesheet)
		ft_error("Error reservando memoria para spritesheet");
	i = 0;
	while (i < NUMBERS_SPRITE)
	{
		ft_allocate_single_sprite(&(sprite[i]), data, type);
		i++;
	}
}