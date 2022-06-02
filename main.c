#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
int main()
{
	int		fd_sherk;
	char	*path_shrek = "/home/coder/gnl/texto/shrek";
	char	*result;

	fd_sherk = open(path_shrek, O_RDONLY);
	while ((result = get_next_line(fd_sherk)) != NULL)
	{
		printf("%s", result);
		free(result);
	}
	close(fd_sherk);
}
