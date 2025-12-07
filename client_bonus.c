/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkhatr <melkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:06:01 by melkhatr          #+#    #+#             */
/*   Updated: 2025/07/01 14:22:04 by melkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk_bonus.h"

static int	g_recieved = 0;

static void	recieved(int signal)
{
	(void)signal;
	g_recieved = 1;
}

void	pis_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			write(1, "this pid is not correct", 24);
			exit(1);
		}
		i++;
	}
}

static void	send_bit(int pid, int bit)
{
	int	sleep;

	sleep = 500;
	if (bit)
	{
		if (kill(pid, SIGUSR1) == -1)
			print_error();
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
			print_error();
	}
	while (!g_recieved)
	{
		usleep(200);
		if (--sleep <= 0)
			exit(1);
	}
	g_recieved = 0;
}

static void	send_char(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		send_bit(pid, (c >> bit) & 1);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*msg;
	int		i;

	i = 0;
	if (argc != 3)
	{
		write(2, "Usage: ./client_bonus <PID> <message>\n", 39);
		return (1);
	}
	pis_error(argv[1]);
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	signal(SIGUSR1, recieved);
	signal(SIGUSR2, complete);
	while (msg[i])
		send_char(pid, msg[i++]);
	send_char(pid, '\0');
	return (0);
}
