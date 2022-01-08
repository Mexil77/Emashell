/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:14:59 by emgarcia          #+#    #+#             */
/*   Updated: 2022/01/08 17:21:29 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <emashell.h>

void	ft_checkquote(char c, char *kindquote)
{
	if (c == '\"' && !kindquote[0])
		*kindquote = '\"';
	else if (c == '\'' && !kindquote[0])
		*kindquote = '\'';
	else if (c == '\"' && kindquote[0] == '\"')
		*kindquote = 0;
	else if (c == '\'' && kindquote[0] == '\'')
		*kindquote = 0;
}
