/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkhatr <melkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:14:33 by melkhatr          #+#    #+#             */
/*   Updated: 2025/07/01 14:14:05 by melkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

# include <limits.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

long	ft_atoi(const char *str);
void	print_error(void);
void	pid_error(char *str);

#endif
