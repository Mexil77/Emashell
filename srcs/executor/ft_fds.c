/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 22:15:27 by emgarcia          #+#    #+#             */
/*   Updated: 2021/12/30 12:16:20 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <emashell.h>

void	ft_createfds(t_general *g)
{
	size_t	i;
	size_t	nfd;

	g->fds = ft_calloc(sizeof(int), g->nfds);
	if (!g->fds)
		return ;
	nfd = 0;
	i = -1;
	while (++i < g->argssize)
	{
		if (g->args[i].type == 4)
		{
			if (g->args[i - 1].type == 1)
				g->fds[nfd++] = open(g->args[i].content[0], O_RDONLY);
			else if (g->args[i - 1].type == 2)
				g->fds[nfd++] = open(g->args[i].content[0],
						O_CREAT | O_RDWR | O_TRUNC, 0644);
			else if (g->args[i - 1].type == 7)
				g->fds[nfd++] = open(g->args[i].content[0],
						O_CREAT | O_RDWR | O_APPEND, 0644);
		}
	}
}
