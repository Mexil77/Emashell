/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 19:08:17 by emgarcia          #+#    #+#             */
/*   Updated: 2021/12/19 17:22:29 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <emashell.h>

size_t	ft_getpathpos(char	**env)
{
	size_t	i;

	i = -1;
	while (env[++i])
		if (!ft_strncmp(env[i], "PWD", 3))
			return (i);
	return (0);
}

size_t	ft_getoldpathpos(char	**env)
{
	size_t	i;

	i = -1;
	while (env[++i])
		if (!ft_strncmp(env[i], "OLDPWD", 6))
			return (i);
	return (0);
}

int	ft_getenvpos(char *envvar, char **env)
{
	size_t	i;

	i = -1;
	while (env[++i])
		if (!ft_strncmp(env[i], envvar, ft_strlen(envvar)))
			return (i);
	return (-1);
}

void	ft_cd(char	***env, char *path)
{
	char	*pwdbuf;
	char	*auxpath;

	if (!path)
	{
		auxpath = ft_substr(env[0][ft_getenvpos("HOME", env[0])], 5,
				ft_strlen(env[0][ft_getenvpos("HOME", env[0])]));
		chdir(auxpath);
		free (auxpath);
	}
	else if (chdir(path))
	{
		printf("minishell: cd: %s: No such file or directory\n", path);
		return ;
	}
	auxpath = ft_strjoin("OLD", env[0][ft_getpathpos(env[0])]);
	env[0][ft_getoldpathpos(env[0])] = ft_strdup(auxpath);
	free (auxpath);
	pwdbuf = calloc(sizeof(char), (PATH_MAX + 1));
	getcwd(pwdbuf, PATH_MAX);
	env[0][ft_getpathpos(env[0])] = ft_strjoin("PWD=", pwdbuf);
	free (pwdbuf);
}
