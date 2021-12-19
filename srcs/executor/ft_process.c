/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 00:49:04 by emgarcia          #+#    #+#             */
/*   Updated: 2021/12/19 14:20:59 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <emashell.h>

void	ft_dupfds(t_general *g, size_t iarg, size_t exec)
{
	size_t	i;
	size_t	fdpos;

	fdpos = 0;
	i = -1;
	while (++i < iarg)
	{
		if (g->args[i].type == 4)
			fdpos++;
	}
	if (exec >= 1)
		dup2(g->pipes[exec - 1][0], STDIN_FILENO);
	if (exec < g->npipes)
		dup2(g->pipes[exec][1], STDOUT_FILENO);
	while (g->fds && iarg < g->argssize && g->args[iarg].type != 5)
	{
		if (g->args[iarg].type == 1)
			dup2(g->fds[fdpos++], STDIN_FILENO);
		else if (g->args[iarg].type == 2 || g->args[iarg].type == 7)
			dup2(g->fds[fdpos++], STDOUT_FILENO);
		iarg++;
	}
	ft_closeallfdspipes(g);
}

void	ft_checknexer(t_general *g, char *exe)
{
	char	**bins;
	char	**myexe;
	char	*paths;
	char	*aux;
	size_t	i;

	paths = ft_strdup(g->ownenv[ft_getenvpos("PATH", g->ownenv)]);
	aux = paths;
	paths = ft_substr(paths, 5, ft_strlen(paths));
	free(aux);
	bins = ft_split(paths, ':');
	free(paths);
	myexe = ft_split(exe, ' ');
	i = -1;
	while (++i < ft_splitlen(bins))
	{
		paths = ft_strjoin(bins[i], "/");
		ft_strownjoin(&paths, myexe[0]);
		if (!access(paths, X_OK))
			execve(paths, myexe, g->ownenv);
		free (paths);
	}
	ft_freedouble(bins);
	ft_freedouble(myexe);
	printf("Commmand not found.\n");
	exit(0);
}

void	ft_execuve(t_general *g, size_t iarg)
{
	while (iarg < g->argssize && g->args[iarg].type != 5)
	{
		if (g->args[iarg].type == 3)
			ft_checknexer(g, g->args[iarg].content);
		iarg++;
	}
}

void	ft_exer(t_general *g, size_t exec)
{
	size_t	i;
	size_t	pipes;

	pipes = -1;
	i = 0;
	while (++pipes < exec)
	{
		while (i < g->argssize && g->args[i].type != 5)
			i++;
		i++;
	}
	ft_dupfds(g, i, exec);
	ft_execuve(g, i);
}

void	ft_makeprocess(t_general *g)
{
	int		i;
	int		j;
	pid_t	pid;

	i = -1;
	while (++i < g->npipes + 1)
	{
		pid = fork();
		if (pid < 0)
			return ;
		if (!pid)
			ft_exer(g, i);
	}
	ft_closeallfdspipes(g);
	i = -1;
	while (++i < g->npipes + 1)
		waitpid(-1, &j, 0);
}
