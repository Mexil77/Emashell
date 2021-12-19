/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 19:09:55 by emgarcia          #+#    #+#             */
/*   Updated: 2021/12/18 23:56:39 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <emashell.h>

size_t	ft_findspchar(char *str)
{
	if (ft_findchar(str, '|') || ft_findchar(str, '<')
		|| ft_findchar(str, '>') || ft_findchar(str, ';'))
		return (1);
	return (0);
}

size_t	ft_spchar(char c)
{
	if (c == '|' || c == '>' || c == '<' || c == ';')
		return (1);
	return (0);
}

void	ft_printgeneral(t_general *g)
{
	size_t	i;

	printf("------------ general struct --------------\n");
	printf("nexecutables : %zu\n", g->nexecutables);
	printf("nredirections : %zu\n", g->nredirections);
	printf("quot : %d\n", g->quot);
	printf("dquot : %d\n\n", g->dquot);
	printf("COMMNDS\n");
	printf("comndssize : %zu\n", g->parse.comndssize);
	i = -1;
	while (g->parse.comnds && ++i < g->parse.comndssize)
		printf("comnds[%zu] : %s\n", i, g->parse.comnds[i]);
	printf("\n");
	printf("FDS\n");
	printf("nfds : %zu\n", g->nfds);
	i = -1;
	while (g->fds && ++i < g->nfds)
		printf("fds[%zu] : %d\n", i, g->fds[i]);
	printf("\n");
	printf("PIPES\n");
	printf("npipes : %zu\n", g->npipes);
	i = -1;
	while (g->pipes && ++i < g->npipes)
		printf("pipe[%zu] : [%d <-> %d]\n", i, g->pipes[i][0], g->pipes[i][1]);
	printf("\n");
	printf("ARGS\n");
	printf("argssize : %zu\n", g->argssize);
	i = -1;
	while (g->args && ++i < g->argssize)
	{
		printf("arg[%zu].type : %zu\n", i, g->args[i].type);
		printf("arg[%zu].content : %s\n", i, g->args[i].content);
	}
	printf("-----------------------------------------\n");
}

size_t	ft_error(size_t ncomands)
{
	if (ncomands > 3)
		printf("syntax error near unexpected token `>>'\n");
	else
		printf("syntax error near unexpected token `>'\n");
	return (0);
}

void	ft_inigeneral(t_general *general)
{
	general->npipes = 0;
	general->nfds = 0;
	general->nexecutables = 0;
	general->nsemicolons = 0;
	general->nredirections = 0;
	general->args = NULL;
	general->fds = NULL;
	general->pipes = NULL;
	general->quot = 1;
	general->dquot = 1;
	general->parse.comand = -1;
	general->parse.comnds = NULL;
	general->parse.comndssize = 0;
	general->argssize = 0;
}
