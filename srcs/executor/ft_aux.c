/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:21:26 by emgarcia          #+#    #+#             */
/*   Updated: 2022/01/04 13:06:39 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <emashell.h>

size_t	ft_validatefds(t_general *g, size_t *iarg, size_t *fdpos)
{
	char	*aux;

	if (g->args[*iarg].type == 1 || g->args[*iarg].type == 2
		|| g->args[*iarg].type == 7)
	{
		if (g->fds[*fdpos] == -1)
		{
			aux = ft_strjoin(g->args[*iarg + 1].content[0],
					": No such file or directory\n");
			write(2, aux, ft_strlen(aux));
			free (aux);
			return (0);
		}
		else if (g->args[*iarg].type == 1)
			dup2(g->fds[*fdpos], STDIN_FILENO);
		else
			dup2(g->fds[*fdpos], STDOUT_FILENO);
		(*fdpos)++;
	}
	(*iarg)++;
	return (1);
}

size_t	ft_isinvalidbuiltin(char **cmd)
{
	if (!ft_strncmp(cmd[0], "exit\0", 5) || !ft_strncmp(cmd[0], "unset\0", 6)
		|| !ft_strncmp(cmd[0], "cd\0", 3)
		|| (!ft_strncmp(cmd[0], "export\0", 7) && ft_splitlen(cmd) > 1))
		return (1);
	return (0);
}

size_t	ft_countpipes(t_general *g, size_t *i, size_t exec)
{
	size_t	pipes;

	pipes = -1;
	while (++pipes < exec)
	{
		while (*i < g->argssize && g->args[*i].type != 5)
			(*i)++;
		(*i)++;
	}
	return (pipes);
}
