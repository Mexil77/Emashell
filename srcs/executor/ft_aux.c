/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:21:26 by emgarcia          #+#    #+#             */
/*   Updated: 2021/12/30 13:26:38 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <emashell.h>

size_t	ft_isinvalidbuiltin(char **cmd)
{
	if (!ft_strncmp(cmd[0], "unset\0", 6) || !ft_strncmp(cmd[0], "cd\0", 3)
		|| (!ft_strncmp(cmd[0], "export\0", 7) && ft_splitlen(cmd) > 1))
		return (1);
	return (0);
}

size_t	ft_countpipes(t_general *g, size_t *i, size_t exec)
{
	size_t	pipes;

	pipes = -1;
	while (++pipes < exec)
	{
		while (*i < g->argssize && g->args[*i].type != 5)
			(*i)++;
		(*i)++;
	}
	return (pipes);
}
