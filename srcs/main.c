/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:13:22 by emgarcia          #+#    #+#             */
/*   Updated: 2021/12/18 19:41:38 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <emashell.h>

void	ft_prompt(t_general *g_m)
{
	char	*command;
	pid_t	pid;

	command = ft_calloc(sizeof(char), 64);
	while (command && ft_strncmp(command, "exit", 4))
	{
		free(command);
		command = readline(BEGIN(1, 49, 34)"Emashell-1.0$ "CLOSE);
		/* if (command && ft_strncmp(command, "exit", 4) && command[0] != '\0')
		{
			ft_inigeneral(g_m);
			ft_parse(g_m, command);
			ft_printgeneral(g_m);
			ft_executor(g_m, g_m->ownenv, &pid);
			printf("return: %d\n", g_piperet);
			free_gminishell(g_m);
		}
		else if (command && !ft_strncmp(command, "exit", 4))
			exit_error(&command); */
	}
	free(command);
	ft_freedouble(g_m->ownenv);
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
