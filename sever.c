/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sever.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrimald <agrimald@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:27:20 by agrimald          #+#    #+#             */
/*   Updated: 2023/09/28 19:52:29 by agrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	send_msg(int dst_pid, const char *msg)
{
	int		i;
	int		bit;
	char	c;

	i = 0;
	while (msg[i])
	{
		while (bit < 8)
		{
			c = msg[i];
			bit = 0;
			if ((c >> bit) & 1)
				kill(dst_pid, SIGUSR1);
			else
				kill(dst_pid, SIGUSR2);
			bit++;
			usleep(100);
		}
		usleep(1000);
		i++;
	}
	return ;
}
