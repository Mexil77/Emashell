/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:42:45 by emgarcia          #+#    #+#             */
/*   Updated: 2021/12/21 14:16:31 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <emashell.h>

void	ft_prtingeneral2(t_general *g)
{
	size_t	i;
	size_t	j;

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
		j = -1;
		while (g->args[i].content[++j])
			printf("arg[%zu].content[%zu] : %s\n", i, j, g->args[i].content[j]);
	}
	printf("-----------------------------------------\n");
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
	ft_prtingeneral2(g);
}
