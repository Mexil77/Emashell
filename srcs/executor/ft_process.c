/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 00:49:04 by emgarcia          #+#    #+#             */
/*   Updated: 2022/01/05 11:32:32 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <emashell.h>

size_t	ft_dupfds(t_general *g, size_t iarg, size_t exec)
{
	size_t	i;
	size_t	fdpos;

	fdpos = 0;
	i = -1;
	while (++i < iarg)
		if (g->args[i].type == 4)
			fdpos++;
	if (exec >= 1 && g->args[iarg].type != 8)
		dup2(g->pipes[exec - 1][0], STDIN_FILENO);
	if (exec < g->npipes && g->args[iarg].type != 8)
		dup2(g->pipes[exec][1], STDOUT_FILENO);
	while (g->fds && iarg < g->argssize && g->args[iarg].type != 5
		&& g->args[iarg].type != 8)
		if (!ft_validatefds(g, &iarg, &fdpos))
			return (0);
	return (1);
}

char	**ft_getbins(t_general *g)
{
	char	**ret;
	char	**auxdoble;
	char	*paths;
	char	*aux;
	size_t	i;

	if (ft_getenvpos("PATH", g->ownenv) < 0)
		return (NULL);
	paths = ft_strdup(g->ownenv[ft_getenvpos("PATH", g->ownenv)]);
	aux = paths;
	paths = ft_substr(paths, 5, ft_strlen(paths));
	free(aux);
	auxdoble = ft_split(paths, ':');
	ret = ft_calloc(sizeof(char *), (ft_splitlen(auxdoble) + 1));
	i = -1;
	while (auxdoble[++i])
		ret[i] = ft_strjoin(auxdoble[i], "/");
	ft_freedouble(auxdoble);
	return (ret);
}

void	ft_checknexer(t_general *g, char **exe)
{
	char	**bins;
	char	*path;
	size_t	i;

	ft_closeallfdspipes(g);
	if (ft_childbuiltin(g, exe))
		exit(0);
	bins = ft_getbins(g);
	if (!bins)
		exit(ft_errormsg("Path not found.\n", 127));
	if (!access(exe[0], X_OK))
		execve(exe[0], exe, g->ownenv);
	i = -1;
	while (++i < ft_splitlen(bins))
	{
		path = ft_strjoin(bins[i], exe[0]);
		if (!access(path, X_OK))
			execve(path, exe, g->ownenv);
		free (path);
	}
	ft_freedouble(bins);
	printf("Commmand -> %s not found.\n", exe[0]);
	exit(127);
}

void	ft_exer(t_general *g, size_t exec)
{
	size_t	i;
	size_t	pipes;
	char	**allcontent;

	i = 0;
	pipes = ft_countpipes(g, &i, exec);
	if (!ft_dupfds(g, i, exec))
	{
		ft_closeallfdspipes(g);
		exit(1);
	}
	i--;
	allcontent = ft_findallcontent(g, i);
	while (++i < g->argssize && g->args[i].type != 5)
	{
		if (g->args[i].type == 3)
			ft_checknexer(g, allcontent);
		if (g->args[i].type == 8)
			ft_heredock(g, i, exec);
	}
	exit(0);
}

void	ft_makeprocess(t_general *g)
{
	int		i;
	int		j;
	size_t	k;
	pid_t	pid;

	i = -1;
	while (++i < (int)g->npipes + 1)
	{
		k = 0;
		ft_countpipes(g, &k, i);
		pid = fork();
		if (pid < 0)
			return ;
		if (!pid)
			ft_exer(g, i);
		else
			if (g->args[k].type == 8)
				waitpid(pid, &j, 0);
	}
	ft_closeallfdspipes(g);
	i = -1;
	while (++i < (int)g->npipes + 1 - ft_nheredocks(g))
		waitpid(-1, &j, 0);
	g_piperet = j % 255;
}
