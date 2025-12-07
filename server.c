/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkhatr <melkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 13:11:44 by melkhatr          #+#    #+#             */
/*   Updated: 2025/07/01 14:50:34 by melkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk_bonus.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putnbr(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		ft_putchar('-', fd);
		ft_putnbr(-n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10, fd);
		ft_putnbr(n % 10, fd);
	}
	else
		ft_putchar(n + '0', fd);
}

static void	handle_signal(int sig, siginfo_t *info, void *ucontext)
{
	static pid_t	pid_clt;
	static int		bit;
	static char		character;

	(void)ucontext;
	if (pid_clt != info->si_pid)
	{
		pid_clt = info->si_pid;
		character = 0;
		bit = 0;
	}
	if (sig == SIGUSR1)
		character |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (character == '\0')
			kill(pid_clt, SIGUSR2);
		write(1, &character, 1);
		character = 0;
		bit = 0;
	}
	usleep(20);
	kill(pid_clt, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	write(1, "(PID): ", 8);
	ft_putnbr(getpid(), 1);
	write(1, "\n", 1);
	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
	{
		pause();
	}
}
