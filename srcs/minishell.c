#include "../includes/minishell.h"

char **env_to_array(t_env *env)
{
	char **array;
	char *envi;
	int i;

	i = 0;
	array = (char **)ft_memalloc(sizeof(char *) * list_len(env) + 1);
	while (env)
	{
		envi = ft_strnew((int)ft_strlen(env->key) + 1 + (int)ft_strlen(env->value));
		ft_strcpy(envi, env->key);
		ft_strcat(envi, "=");
		ft_strcat(envi, env->value);
		array[i++] = ft_strdup(envi);
		env = env->next;
		free(envi);
	}
	array[i] = NULL;
	return (array);
}

char *check_cmd(t_env *env, char *executable)
{
	char *path;
	char **paths;
	char *tmp;
	char *tmp1;
	int i;

	if (executable[0] != '.')
	{
		path = get_env(&env, "PATH")->value;
		paths = ft_strsplit(path, ':');
		i = 0;
		while (paths[i])
		{
			tmp = ft_strnew((int)ft_strlen(paths[i]) + 1 + (int)ft_strlen(executable));
			ft_strcpy(tmp, paths[i++]);
			ft_strcat(tmp, "/");
			ft_strcat(tmp, executable);
			if (access(tmp, F_OK) != -1)
			{
				if (paths)
					free_array(&paths);
				return (tmp);
			}
			else
				free(tmp);
		}
		free_array(&paths);
	}
	return (ft_strdup(executable));
}

void		check_file_perm(char *path)
{
	if ((access(path, F_OK) != -1))
	{
		if (access(path, X_OK) )
		{
			ft_putstr(path);
			ft_putendl(": Permission Denied.");
		}
	}
	else
	{
		ft_putstr(path);
		ft_putendl(" : Command not found.");
	}
}

void	exec_cmd(char *cmd ,char **cmdargs, t_env **env)
{
	char	**env_arr;
	int pid;

	env_arr = NULL;
	env_arr = env_to_array((*env));
	if ((pid = fork()))
		wait(0);
	else
	{
		if (execve(cmd, cmdargs, env_arr) == -1)
		{
			check_file_perm(cmdargs[0]);
			exit(0);
		}
	}
	free_array(&env_arr);
}

void	handle_cmd(char **cmd, t_env **env)
{
	char **cmdargs;
	char **environ;
	char	*fullpath;
	int i;

	cmdargs = NULL;
	fullpath = NULL;
	i = 0;
	cmdargs = ft_strsplitstr(*cmd, "\r\t \"");
	if (!cmdargs)
		return;
	handle_exp(cmdargs, env);
	printf("ENTERD CMD : [%s] \n", cmdargs[0]);
	if (check_builtins(cmdargs[0]))
		exec_builtins(cmd ,cmdargs[0], &cmdargs, env);
	else
	{
		if (get_env(env, "PATH"))
			fullpath = check_cmd(*env, cmdargs[0]);
		else
			fullpath = ft_strdup(cmdargs[0]);
		exec_cmd(fullpath, cmdargs, env);
		ft_strdel(&fullpath);
	}
	free_array(&cmdargs);
}

void	init_shell(t_env **env)
{
	char *cmd;
	char *path;
	char buff[1024];
	cmd = NULL;
	path = NULL;
	while (1)
	{
		getcwd(buff, 1024);
		
		ft_putstr(buff);
		ft_putstr(" -> ");
		ft_getline(0, &cmd);
		handle_cmd(&cmd, env);
		free(cmd);
	}
}

int main(int ac, char **av, char **environ)
{
    t_env *env;
	t_env *tmp;
	env = NULL;
	tmp = NULL;
	if (*environ == NULL)
	{
		ft_putendl("Enviroment variable are not set");
		exit(1);
	}
	copy_env(&env, environ);
	init_shell(&env);
	free_env(&env);
	return (0);
}