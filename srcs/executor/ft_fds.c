/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 22:15:27 by emgarcia          #+#    #+#             */
/*   Updated: 2021/12/18 23:06:52 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <emashell.h>

void	ft_openfds(t_general *g)
{
	size_t	i;
	size_t	nfd;

	nfd = 0;
	i = -1;
	while (++i < g->argssize)
	{
		if (g->args[i].type == 4)
		{
			if (g->args[i - 1].type == 1)
				g->fds[nfd++] = open(g->args[i].content, O_RDONLY);
			else if (g->args[i - 1].type == 2)
				g->fds[nfd++] = open(g->args[i].content,
						O_CREAT | O_RDWR | O_TRUNC, 0644);
		}
	}
}

void	ft_createfds(t_general *g)
{
	size_t	i;

	g->fds = calloc(sizeof(int), g->nfds);
	if (!g->fds)
		return ;
	ft_openfds(g);
	i = -1;
	while (++i < g->nfds)
		printf("fds[%zu] : %d\n", i, g->fds[i]);
}
