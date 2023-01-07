/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:56:08 by smounafi          #+#    #+#             */
/*   Updated: 2023/01/07 14:10:51 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_handler(int sig)
{
	static int	i;
	static int	bit;

	if (sig == SIGUSR1)
		i = i | (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	pid = getpid();
	(void)av;
	if (ac != 1)
	{
		ft_printf("\033[1;31m🛑ERROR: verify the input → ./server .");
		return (0);
	}
	ft_printf("\033[94mPID\033[0m \033[96m->\033[0m %d\n", pid);
	ft_printf("\033[90mWaiting for a message...\033[0m\n");
	while (ac == 1)
	{
		signal(SIGUSR1, bit_handler);
		signal(SIGUSR2, bit_handler);
		pause();
	}
	return (0);
}
