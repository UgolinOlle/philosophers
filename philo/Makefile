# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/28 23:23:14 by uolle             #+#    #+#              #
#    Updated: 2024/02/16 10:33:55 by ugolin-olle      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -- Variables
HDRDIR       = includes
SRCSDIR      = srcs
OBJDIR       = objs

SRC_FILES = $(wildcard $(SRCSDIR)/*.c)
OBJ_FILES = $(patsubst $(SRCSDIR)/%.c,$(OBJDIR)/%.o,$(SRC_FILES))

CC = cc
C_FLAGS = -Werror -Wall -Wextra
HDR_FLAG = includes/philosophers.h
INC_FLAGS = -I $(HDRDIR)

RM = rm -rf
MKDIR = mkdir -p

NAME = philo

RESET = \033[0m
BLUE = \033[0;94m
GREEN = \033[0;92m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "$(BLUE)[INFO] - Linking: $(NAME)$(RESET)"
	@$(CC) $(C_FLAGS) $(OBJ_FILES) -o $(NAME)
	@echo "$(GREEN)[OK] - $(NAME) has been successfully compiled$(RESET)"

$(OBJDIR)/%.o: $(SRCSDIR)/%.c $(HDR_FLAG) | $(OBJDIR)
	@echo "$(BLUE)[INFO] - Compiling: $< $(RESET)"
	@$(CC) $(C_FLAGS) $(INC_FLAGS) -c $< -o $@

$(OBJDIR):
	@$(MKDIR) $(OBJDIR)

clean:
	@$(RM) $(OBJDIR)
	@echo "$(GREEN)[OK] - $(NAME) object files cleaned!$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN)[OK] - $(NAME) executable has been cleaned!$(RESET)"

re: fclean all
	@echo "$(GREEN)[OK] - Cleaned and rebuilt successfully!$(RESET)"
