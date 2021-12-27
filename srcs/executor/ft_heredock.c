/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:45:14 by emgarcia          #+#    #+#             */
/*   Updated: 2021/12/27 12:45:38 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <emashell.h>

void	ft_heredock(t_general *g, size_t i)
{
	char	*line;
	char	*eof;

	eof = g->args[i + 1].content[0];
	line = NULL;
	while (ft_strncmp(line, eof, ft_strlen(eof))
		|| ft_strlen(eof) != ft_strlen(line))
	{
		free(line);
		line = readline(BEGIN"> "CLOSE);
		add_history (line);
		printf("%s\n", line);
	}
	free(line);
	exit(0);
}
