/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrimald <agrimald@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:33:46 by agrimald          #+#    #+#             */
/*   Updated: 2023/10/05 19:50:44 by agrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	handler(int num_sig, siginfo_t *info, void *context)
{
	static unsigned char	recivied_char = '\0';
	static int				bit_count = 0;

	recivied_char = recivied_char << 1;
	if (num_sig == SIGUSR1)
		recivied_char = recivied_char | 1;
	bit_count++;
	if (bit_count == 8)
	{
		ft_printf("%c", recivied_char);
		bit_count = 0;
		recivied_char = '\0';
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				pid;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 \
				|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error\n");
		exit(1);
	}
	while (1)
		sleep(1);
	return (0);
}
