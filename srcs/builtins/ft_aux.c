/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 14:05:41 by emgarcia          #+#    #+#             */
/*   Updated: 2022/01/03 18:36:49 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <emashell.h>

size_t	ft_childbuiltin(t_general *g, char **exe)
{
	if (ft_isinvalidbuiltin(exe))
		return (1);
	else if (!ft_strncmp(exe[0], "export\0", 7) && ft_splitlen(exe) == 1)
	{
		ft_parsebuiltin(g, exe);
		return (1);
	}
	else if (!ft_strncmp(exe[0], "echo\0", 5))
	{
		ft_echo(exe);
		return (1);
	}
	return (0);
}

size_t	ft_cdretvalue(char *path)
{
	if (!path)
		return (0);
	else if (chdir(path))
		return (1);
	return (0);
}

size_t	ft_exportretvalue(char *newenv)
{
	size_t	i;
	size_t	ultima;
	char	*name;

	i = 0;
	ultima = 0;
	while (newenv[i] && newenv[i] != '=')
		i++;
	name = ft_substr(newenv, ultima, i);
	if (!ft_checkenvname(name) || !ft_strlen(name))
	{
		free (name);
		return (1);
	}
	free (name);
	return (0);
}

size_t	ft_unsetbiultinvalue(char *remenv)
{
	if (!ft_checkenvname(remenv))
		return (1);
	return (0);
}
