/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:45:14 by emgarcia          #+#    #+#             */
/*   Updated: 2021/12/31 17:09:37 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <emashell.h>

void	ft_openfds(t_general *g, int tmp, size_t exec, size_t iarg)
{
	size_t	fdpos;
	size_t	i;

	dup2(tmp, STDIN_FILENO);
	if (g->npipes > exec)
		dup2(g->pipes[exec][1], STDOUT_FILENO);
	fdpos = 0;
	i = -1;
	while (++i < iarg)
		if (g->args[i].type == 4)
			fdpos++;
	while (g->fds && iarg < g->argssize && g->args[iarg].type != 5)
	{
		if (g->args[iarg].type == 1)
			dup2(g->fds[fdpos++], STDIN_FILENO);
		else if (g->args[iarg].type == 2 || g->args[iarg].type == 7)
			dup2(g->fds[fdpos++], STDOUT_FILENO);
		iarg++;
	}
}

void	ft_restorvalues(t_general *g, int tmp)
{
	close(tmp);
	unlink(".tmp");
	ft_closeallfdspipes(g);
	ft_signals();
}

void	ft_heredock(t_general *g, size_t i, size_t exec)
{
	char	*line;
	char	*eof;
	int		tmp;

	ft_sigheredock();
	tmp = open(".tmp", O_CREAT | O_RDWR, 0644);
	eof = g->args[i + 1].content[0];
	line = ft_strdup("");
	while ((ft_strncmp(line, eof, ft_strlen(eof))
			|| ft_strlen(eof) != ft_strlen(line)) && line)
	{
		write(tmp, line, ft_strlen(line));
		if (line && ft_strncmp(line, "", 1))
			write(tmp, "\n", 1);
		free(line);
		line = readline(BEGIN"> "CLOSE);
	}
	close(tmp);
	tmp = open(".tmp", O_CREAT | O_RDWR, 0644);
	ft_openfds(g, tmp, exec, i);
	free(line);
	ft_restorvalues(g, tmp);
	if (i + 2 >= g->argssize || g->args[i + 2].type == 5)
		exit(0);
}

int	ft_nheredocks(t_general *g)
{
	size_t	i;
	int		nheredocks;

	nheredocks = 0;
	i = -1;
	while (++i < g->argssize)
		if (g->args[i].type == 8)
			nheredocks++;
	return (nheredocks);
}
