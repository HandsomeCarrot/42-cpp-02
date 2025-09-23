# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/23 13:18:37 by vpoka             #+#    #+#              #
#    Updated: 2025/09/23 13:21:17 by vpoka            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----VARIABLES-----#

NAME = ex00

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

INCLUDE = -Iinclude
COMP = $(CXX) $(CXXFLAGS) $(INCLUDE)

S = src
SRCS =	$(addprefix $(S)/, \
		main.cpp)

B = build
OBJS = $(SRCS:$(S)/%.cpp=$(B)/%.o)

#-----COLORS-----#

RST = \033[0m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
MAGENTA = \033[1;35m
CYAN = \033[1;36m

#-----RULES-----#

all: $(NAME)

$(B):
	@ mkdir -p $(B)
	@ echo "$(YELLOW)$(NAME): compiling...$(RST)"

$(B)/%.o: $(S)/%.cpp
	$(COMP) -c $< -o $@

$(NAME): $(B) $(OBJS)
	$(COMP) $(OBJS) -o $(NAME)
	@ echo "$(GREEN)$(NAME) built successfully!$(RST)"

clean:
	@ rm -rf $(B)
	@ echo "$(RED)deleted BUILD files$(RST)"

fclean: clean
	@ rm -f $(NAME)
	@ echo "$(RED)deleted PROGRAM file$(RST)"

re: fclean all

run: re
	@ echo "$(CYAN)$(NAME): starting...$(RST)"
	@ ./$(NAME)

.PHONY: all clean fclean re run