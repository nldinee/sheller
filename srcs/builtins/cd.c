#include "../../includes/minishell.h"


int check_errs(char *str)
{
	DIR *dir;
	dir = opendir(str);
	if (dir)
	{
		closedir(dir);
		return (1);
	}
	else 
	{
		if (access(str, F_OK) == -1)
		{
			ft_putstr("cd: ");
			ft_putstr(str);
			ft_putendl(" No such file or directory");
		}
		else if (access(str, R_OK|W_OK|X_OK) == -1)
		{
			ft_putstr("cd: ");
			ft_putstr(str);
			ft_putendl(" Permission denied");
		}
		return (0);
	}
}

void		ft_cd(char **cmdargs, t_env **env)
{
	char buff[4096];
	t_env *e;
	char *tmp;
	if (!cmdargs[1])
	{
		e = get_env(env, "HOME");
		if (e)
			chdir(e->value);
		else
			ft_putendl("cd: HOME not set");	
	}
	else if (cmdargs[1] && cmdargs[1][0] == '-')
		chdir(get_env(env, "OLDPWD")->value);
	else
	{
		if (check_errs(cmdargs[1]))
			chdir(cmdargs[1]);
		else
			return ;
	}
	tmp = get_env(env, "PWD")->value;
	get_env(env, "PWD")->value = ft_strdup(getcwd(buff,4096));
	free(get_env(env, "OLDPWD")->value);
	get_env(env, "OLDPWD")->value = ft_strdup(tmp);
	free(tmp);
}