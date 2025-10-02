# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/23 13:20:26 by vpoka             #+#    #+#              #
#    Updated: 2025/10/02 20:33:10 by vpoka            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----VARIABLES-----#

NAME = ex02

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MD -MP

INCLUDE = -Iinclude
COMP = $(CXX) $(CXXFLAGS) $(INCLUDE)

S = src
SRCS =	$(addprefix $(S)/, \
		main.cpp \
		Fixed.cpp)

B = build
OBJS = $(SRCS:$(S)/%.cpp=$(B)/%.o)
DEPS = $(OBJS:.o=.d)

#-----COLORS-----#

RST = \033[0m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
MAGENTA = \033[1;35m
CYAN = \033[1;36m

#-----RULES-----#

-include $(DEPS)

all: $(NAME)

$(B):
	@ mkdir -p $(B)
	@ printf "$(YELLOW)$(NAME): compiling...$(RST)\n"

$(B)/%.o: $(S)/%.cpp
	$(COMP) -c $< -o $@

$(NAME): $(B) $(OBJS)
	$(COMP) $(OBJS) -o $(NAME)
	@ printf "$(GREEN)$(NAME) built successfully!$(RST)\n"

clean:
	@ rm -rf $(B)
	@ printf "$(RED)deleted BUILD files$(RST)\n"

fclean: clean
	@ rm -f $(NAME)
	@ printf "$(RED)deleted PROGRAM file$(RST)\n"

re: fclean all

run: re
	@ printf "$(CYAN)$(NAME): starting...$(RST)\n"
	@ ./$(NAME)

.PHONY: all clean fclean re run