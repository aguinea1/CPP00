# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguinea <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/08 12:05:58 by aguinea           #+#    #+#              #
#    Updated: 2025/05/13 15:42:52 by aguinea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                              CONFIGURATION                                   #
################################################################################

NAME			= PhoneBook

CC				= c++
CFLAGS			= -Wall -Wextra -Werror  -std=c++98 -fsanitize=address -MMD
DEPFLAGS		= -MMD -MF $(DEPDIR)/$*.d

SRCDIR			= src
OBJDIR			= obj
DEPDIR			= deps

################################################################################
#                              SOURCE FILES                                    #
################################################################################

SRCS = main.cpp			\


HEADERS = phonebook.hpp	\
		  contact.hpp

################################################################################
#                             OBJECTS & DEPS                                   #
################################################################################

OBJS			= $(SRCS:%.cpp=$(OBJDIR)/%.o)
DEPS			= $(OBJS:%.o=$(DEPDIR)/%.d)

################################################################################
#                              RULES                                           #
################################################################################

all: dir $(NAME)

$(NAME): Makefile $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "\033[1;33mCPP00 EX01 [✔]\033[0m"


$(OBJDIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(dir $@) $(dir $(DEPDIR)/$*.d)
	@$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDE) -c $< -o $@

dir:
	@mkdir -p $(OBJDIR) $(DEPDIR)

clean:
	@rm -rf $(OBJDIR) $(DEPDIR)
	@echo "\033[1;33mCHAUU\033[0m"

fclean: clean
	@rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re dir
