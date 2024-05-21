#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_error("Usage: ./program_name map_file");
		return (1);
	}
	init(argv);
	return (0);
}