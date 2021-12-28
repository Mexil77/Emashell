/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:21:26 by emgarcia          #+#    #+#             */
/*   Updated: 2021/12/28 12:36:34 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <emashell.h>

size_t	ft_isbuiltin(char *str)
{
	if (!ft_strncmp(str, "unset", 4)
		|| !ft_strncmp(str, "export", 6)
		|| !ft_strncmp(str, "cd", 2))
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
