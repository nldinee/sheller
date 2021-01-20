#include "../../includes/minishell.h"

void	ft_echo(char **cmdargs)
{
	int i;

	i = 1;
	while (cmdargs[i])
	{
		ft_putstr(cmdargs[i]);
		if (cmdargs[i + 1])
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}