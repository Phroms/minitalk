/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrimald <agrimald@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:36:30 by agrimald          #+#    #+#             */
/*   Updated: 2023/10/02 20:34:13 by agrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	send_msg(int pid, const char *msg)
{
	int		i;
	int		bit;
	char	c;

	i = 0;
	while (msg[i])
	{
		c = msg[i];
		bit = 0;
		while (bit < 8)
		{
			if ((c >> bit) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit++;
			usleep(100);
		}
		usleep(1000);
		i++;
	}
	return ;
}

void	check_arguments(int argc, char **argv)
{
	int	i;

	if (argc != 3)
	{
		ft_printf("Arguments no valid\n");
		exit(1);
	}
	i = 0;
	while (argv[1][i])
	{
		if (!(ft_isdigit(argv[1][i])))
		{
			ft_printf("Pid invalid\n");
			exit(1);
		}
		i++;
	}
	if (argc == 2)
	{
		ft_printf("Error\nMising arguments\n");
		exit(2);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				pid;

	ft_printf("Client PID: %d\n", getpid());
	check_arguments(argc, argv);
	pid = ft_atoi(argv[1]);
	send_msg(pid, argv[2]);
	return (0);
}
