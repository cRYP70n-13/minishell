#include "../../include/errors.h"

void	ft_error_and_quit(int error_number)
{
	if (error_number == 1)
	{
		write(2, "Memory couldn't be allocated !!!", 32);
		exit(EXIT_FAILURE);
	}
}
