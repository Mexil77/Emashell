/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 19:09:55 by emgarcia          #+#    #+#             */
/*   Updated: 2021/12/19 17:41:44 by emgarcia         ###   ########.fr       */
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
