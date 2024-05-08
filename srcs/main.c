#include "so_long.h"

int	main(void)
{
    char *s = get_next_line(1);
    printf("%s", s);
    free(s);
	return (0);
}