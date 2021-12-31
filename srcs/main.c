/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:13:22 by emgarcia          #+#    #+#             */
/*   Updated: 2021/12/31 13:47:18 by emgarcia         ###   ########.fr       */
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
		ft_freebidstr(g->args[i].content);
	if (g->args)
		free(g->args);
	if (g->parse.comnds)
		ft_freebidstr(g->parse.comnds);
	if (g->fds)
		free(g->fds);
}

void	ft_prompt(t_general *g)
{
	char	*command;

	command = ft_calloc(sizeof(char), 64);
	while (command && ft_strncmp(command, "exit\0", 5))
	{
		free(command);
		command = readline(BEGIN"Emashell-1.0$ "CLOSE);
		add_history (command);
		if (command && ft_strncmp(command, "exit\0", 5) && command[0] != '\0')
		{
			ft_inigeneral(g);
			ft_parse(g, command);
			if (g->args)
				ft_executor(g);
			//ft_printgeneral(g);
			ft_freegeneral(g);
			system("leaks minishell > /dev/ttys001");
		}
	}
	free(command);
	ft_freedouble(g->ownenv);
}

int	main(void)
{
	extern char	**environ;
	t_general	g_minishell;

	ft_signals();
	g_minishell.ownenv = ft_ownenv(environ);
	ft_prompt(&g_minishell);
	printf("exit\n");
	return (0);
}
