/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabdelba <nabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:42:51 by nabdelba          #+#    #+#             */
/*   Updated: 2021/03/22 16:44:56 by nabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <sys/stat.h>
# include <sys/wait.h>
# include <dirent.h>

typedef struct		s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

t_env				*new_env(char *key, char *value);
void				env_append(t_env **env, t_env *item);
void				env_delete(t_env **env, char *key);
void				free_env(t_env **env);
void				copy_env(t_env **env, char **environ);
t_env				*get_env(t_env **env, char *key);

void				exec_builtins(char **input, char *cmd,\
								char ***cmdargs, t_env **env);
int					check_builtins(char *cmd);
void				ft_exit(char ***final, t_env **env, char **input);
void				ft_cd(char **cmdargs, t_env **env);
void				ft_setenv(char **cmdargs, t_env **env);
void				ft_unsetenv(char **cmdargs, t_env **env);
void				ft_echo(char **cmdargs);
void				ft_env(t_env *env);

int					handle_exp(char **cmd, t_env **env);
int					list_len(t_env *env);
void				free_array(char ***arr);
char				**env_to_array(t_env *env);
void				check_file_perm(char *path);
void				handle_cmd(char **cmd, t_env **env);
#endif
