/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 20:31:48 by emgarcia          #+#    #+#             */
/*   Updated: 2021/12/19 17:05:50 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <emashell.h>

void	ft_closeallfdspipes(t_general *g)
{
	size_t	i;

	i = -1;
	while (++i < g->nfds)
		close(g->fds[i]);
	i = -1;
	while (++i < g->npipes)
	{
		close(g->pipes[i][0]);
		close(g->pipes[i][1]);
	}
}

void	ft_executor(t_general *g)
{
	ft_createfds(g);
	ft_createpipes(g);
	ft_makeprocess(g);
}
