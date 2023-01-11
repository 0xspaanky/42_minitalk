/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:48:04 by smounafi          #+#    #+#             */
/*   Updated: 2023/01/11 18:43:32 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bits_passing(int pid, char *str, int len)
{
	int	bit;
	int	i;

	i = 0;
	while (i < len)
	{
		bit = 0;
		while (bit <= 7)
		{
			if ((str[i] & (0x01 << bit)) != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit++;
			usleep(300);
		}
		i++;
	}
}

void	confirm_reicept(int len)
{
	ft_printf("\e[92m%d signals sent successfully\n\e[92m", len);
}

int	check_args(int ac, char **av)
{
	int	returned;

	returned = 0;
	if (ac != 3)
	{
		ft_printf("\033[1;31m🛑ERROR: verify the input →");
		ft_printf("./client <PID> <Message>");
	}
	else if (!ft_isstrdigit(av[1]))
	{
		ft_printf("\033[1;31m🛑ERROR: verify the PID!");
		ft_printf(" → It should contain only numbers.");
	}
	else if (*av[2] == 0)
		ft_printf("\033[1;31m🛑ERROR: insert a non-empty message.");
	else
		returned = 1;
	return (returned);
}

int	main(int ac, char **av)
{
	int		i;
	char	*str;
	int		pid;

	i = 0;
	if (check_args(ac, av) == 1)
	{
		pid = ft_atoi(av[1]);
		str = av[2];
		bits_passing(pid, str, ft_strlen(str));
		bits_passing(pid, "\n", 1);
		confirm_reicept(ft_strlen(str));
	}
	return (0);
}
