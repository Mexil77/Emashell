/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 14:05:41 by emgarcia          #+#    #+#             */
/*   Updated: 2021/12/31 14:13:42 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <emashell.h>

size_t	ft_childbuiltin(t_general *g, char **exe)
{
	if (ft_isinvalidbuiltin(exe))
		return (1);
	else if (!ft_strncmp(exe[0], "export\0", 7) && ft_splitlen(exe) == 1)
	{
		ft_parsebuiltin(g, exe);
		return (1);
	}
	else if (!ft_strncmp(exe[0], "echo\0", 5))
	{
		ft_echo(exe);
		return (1);
	}
	return (0);
}
