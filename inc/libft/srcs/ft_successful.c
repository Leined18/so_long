#include "libft.h"

void	ft_successful(char *success)
{
	ft_putstr_fd("\x1b[32mSuccessful\x1b[0m\n", 2);
	if (success && *success)
	{
		ft_putstr_fd(success, 2);
		write(2, "\n", 1);
	}
}