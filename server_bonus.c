/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkhatr <melkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:42:12 by melkhatr          #+#    #+#             */
/*   Updated: 2025/07/01 14:56:16 by melkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

static void	write_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	put_nbr(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write_fd('-', fd);
		put_nbr(-n, fd);
	}
	else if (n > 9)
	{
		put_nbr(n / 10, fd);
		put_nbr(n % 10, fd);
	}
	else
		write_fd(n + '0', fd);
}

static void	process_bit(int signal, pid_t sender, int *count, char *position)
{
	if (signal == SIGUSR1)
		*position |= (1 << *count);
	(*count)++;
	if (*count == 8)
	{
		if (*position == '\0')
		{
			write(1, "\nMessage complete", 18);
			kill(sender, SIGUSR2);
		}
		else
			write(1, position, 1);
		*count = 0;
		*position = 0;
	}
}

static void	handle_signal(int signal, siginfo_t *info, void *ctx)
{
	static int		count = 0;
	static char		position = 0;
	static pid_t	sender = 0;

	(void)ctx;
	if (sender != info->si_pid)
	{
		sender = info->si_pid;
		count = 0;
		position = 0;
	}
	process_bit(signal, sender, &count, &position);
	usleep(50);
	kill(sender, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	write(1, "SERVER PID :", 13);
	put_nbr(getpid(), 1);
	write(1, "\n", 1);
	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
