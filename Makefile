# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melkhatr <melkhatr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/02 11:40:10 by melkhatr          #+#    #+#              #
#    Updated: 2025/07/02 11:40:11 by melkhatr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = client
NAME2 = server
NAMEB1 = client_bonus
NAMEB2 = server_bonus

CC = cc
RM = rm -rf
FLAGS = -Wall -Wextra -Werror
SRC1 = client.c utils.c
SRC2 = server.c

SRCB1 = client_bonus.c utils_bonus.c
SRCB2 = server_bonus.c

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

OBJB1 = $(SRCB1:.c=.o)
OBJB2 = $(SRCB2:.c=.o)

all: $(NAME1) $(NAME2)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME1): $(OBJ1)
	@$(CC) $(OBJ1) -o $(NAME1)

$(NAME2): $(OBJ2)
	@$(CC) $(OBJ2) -o $(NAME2)

bonus: $(NAMEB1) $(NAMEB2)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAMEB1): $(OBJB1)
	@$(CC) $(OBJB1) -o $(NAMEB1)

$(NAMEB2): $(OBJB2)
	@$(CC) $(OBJB2) -o $(NAMEB2)

clean:
	@$(RM) *.o
	
fclean: clean
	@$(RM) $(NAME1) $(NAME2)
	@$(RM) $(NAMEB1) $(NAMEB2)

re: fclean all

.PHONY : clean fclean re all bonus