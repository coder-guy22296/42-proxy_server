#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/07 19:32:52 by cyildiri          #+#    #+#              #
#    Updated: 2017/05/07 19:39:54 by cyildiri         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = proxy
SRC =   src/main.c\
		src/server_socket_setup.c\
		src/handle_requests.c\
		src/web_request.c
OFILES = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	gcc -o $(NAME) $(OFILES)

%.o: %.c
	gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -rf $(OFILES)

fclean: clean

re: fclean all
