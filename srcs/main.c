/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:13:22 by emgarcia          #+#    #+#             */
/*   Updated: 2021/12/21 14:49:36 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <emashell.h>

void	ft_freegeneral(t_general *g)
{
	size_t	i;

	i = -1;
	while (++i < g->npipes)
		free(g->pipes[i]);
	free(g->pipes);
	i = -1;
	while (++i < g->argssize)
		free(g->args[i].content);
	free(g->args);
	free(g->fds);
	ft_freedouble(g->parse.comnds);
}

void	ft_prompt(t_general *g)
{
	char	*command;
	pid_t	pid;

	command = ft_calloc(sizeof(char), 64);
	while (command && ft_strncmp(command, "exit", 4))
	{
		free(command);
		command = readline(BEGIN"Emashell-1.0$ "CLOSE);
		if (command && ft_strncmp(command, "exit", 4) && command[0] != '\0')
		{
			ft_inigeneral(g);
			ft_parse(g, command);
			ft_executor(g);
			//ft_printgeneral(g);
			ft_freegeneral(g);
		}
	}
	free(command);
	ft_freedouble(g->ownenv);
}

int	main(int argc, char **argv)
{
	extern char	**environ;
	pid_t		pid;
	t_general	g_minishell;

	g_minishell.ownenv = ft_ownenv(environ);
	ft_prompt(&g_minishell);
	printf("exit\n");
	return (0);
}
