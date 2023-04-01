#include "minishell.h"

int    ft_pwd(int fd)
{
	char cwd[256];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
		perror("getcwd() error");
	else
		ft_printf(fd, "%s\n", cwd);
	return (0); 
}
