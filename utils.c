/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkhatr <melkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:08:36 by melkhatr          #+#    #+#             */
/*   Updated: 2025/07/01 14:13:25 by melkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	print_error(void)
{
	write(1, "Pid not found\n", 15);
	exit(1);
}

void	pid_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			write(1, "Error Pid must be number\n", 25);
			exit(1);
		}
		i++;
	}
}
