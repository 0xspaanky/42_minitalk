#include "minitalk.h"

void	bit_handler(int sig, siginfo_t *info, void *s)
{
	static int	i;
	static int	bit;

    (void)info;
	(void)s;
	if (sig == SIGUSR1)
		i = i | (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
        kill(info->si_pid, SIGUSR2);
	}
}

int	main(int ac, char **av)
{
	int	pid;
    struct sigaction	sig;

	pid = getpid();
	(void)av;
	if (ac != 1)
	{
		ft_printf("\033[1;31m🛑ERROR: verify the input → ./server .");
		return (0);
	}
	ft_printf("\033[94mPID\033[0m \033[96m->\033[0m %d\n", pid);
	ft_printf("\033[90mWaiting for a message...\033[0m\n");
    sig.sa_sigaction = bit_handler;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = 0;
	while (ac == 1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause();
	}
	return (0);
}