/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 23:14:47 by emgarcia          #+#    #+#             */
/*   Updated: 2021/12/23 16:24:10 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <emashell.h>

void	ft_createpipes(t_general *g)
{
	size_t	i;

	g->pipes = ft_calloc(sizeof(int *), g->npipes);
	if (!g->pipes)
		return ;
	i = -1;
	while (++i < g->npipes)
	{
		g->pipes[i] = ft_calloc(sizeof(int), 2);
		if (!g->pipes[i])
			return ;
		pipe(g->pipes[i]);
	}
}
