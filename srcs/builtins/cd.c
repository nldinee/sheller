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

static void swap_env(t_env **env, char *key, char *value)
{
	env_delete(env, key);
	printf(">>>>>>>>>>> What ! m joking !\n");
	env_append(env, new_env(key, value));
}

void		ft_cd(char **cmdargs, t_env **env)
{
	char buff[4096];
	t_env *_env;
	t_env *pwd;
	t_env *oldpwd;
	getcwd(buff, 4096);

	if (!cmdargs[1])
	{	
		_env = get_env(env, "HOME");
		if (!_env)
			ft_putendl("HOME not set.");
		else
		{
			chdir(_env->value);
			swap_env(env, "PWD", _env->value);
		}
	}
	else if (cmdargs[1][0] == '-')
	{
		oldpwd = get_env(env, "OLDPWD");
		if (!oldpwd)
			ft_putendl("OLDPWD not set");
		else
		{
				chdir(oldpwd->value);
				swap_env(env, "OLDPWD", buff);
		}
	}
	else if (check_errs(cmdargs[1]))
	{
		pwd = get_env(env, "PWD");
		if (!pwd)
			env_append(env, new_env("PWD", cmdargs[1]));
		chdir(cmdargs[1]);
		swap_env(env, "OLDPWD", buff);
	}
}