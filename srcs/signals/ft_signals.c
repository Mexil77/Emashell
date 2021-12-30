/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:44:27 by emgarcia          #+#    #+#             */
/*   Updated: 2021/12/30 13:58:36 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <emashell.h>

void	ft_stopsignal(int sig)
{
	if (sig)
		printf(BEGIN"Emashell-1.0$ "CLOSE);
}

void	ft_signals(void)
{
	signal(SIGINT, ft_stopsignal);
	//signal(SIGQUIT, SIG_IGN);
}
