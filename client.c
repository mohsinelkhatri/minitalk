/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkhatr <melkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:09:39 by melkhatr          #+#    #+#             */
/*   Updated: 2025/07/01 14:19:04 by melkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

static int	g_recieved = 0;

static void	handle_ack(int signal)
{
	(void)signal;
	g_recieved = 1;
}

long	ft_atoi(const char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		if (result > INT_MAX)
			exit(1);
		i++;
	}
	return (result);
}

static void	send_bit(pid_t pid, int bit)
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
	pid_t	pid;
	char	*msg;
	int		i;

	i = 0;
	if (argc != 3)
	{
		write(1, "Usage: ./client <PID> <message>\n", 33);
		return (1);
	}
	pid_error(argv[1]);
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	signal(SIGUSR1, handle_ack);
	while (msg[i])
		send_char(pid, msg[i++]);
	return (0);
}
