
CLEAR		:= \e[0K

SRED		:= \033[0;31m
SGREEN		:= \033[0;32m
SYELLOW		:= \033[0;33m
SCYAN		:= \033[0;36m
SPURPLE		:= \033[0;35m
SOFF		:= \033[0m

RED			:= '\033[0;31m'
GREEN		:= '\033[0;32m'
YELLOW		:= '\033[0;33m'
CYAN		:= '\033[0;36m'
PURPLE		:= '\033[0;35m'
OFF			:= '\033[0m'

#SRCS

NAME	:= RPN

SRCS	:= main.cpp RPN.cpp

OBJS_DIR := ./objs/

OBJS	:= $(SRCS:.cpp=.o)

OBJS	:= $(addprefix $(OBJS_DIR),$(OBJS))

DEPS	:= ${OBJS:.o=.d}

CC		:= c++

CFLAGS	:= -Wall -Wextra -Werror -std=c++98 -MMD -g3

RM		:= rm -rf

MKDIR	:= mkdir -p

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

debug	: CFLAGS += -D DEBUG
debug	: re

clean	:
	${RM} ${OBJS_DIR}

fclean : clean
	${RM} ${NAME}

re		: fclean all

.PHONY	: all clean fclean re

#create objsdir and .o

$(OBJS_DIR)%.o	: %.cpp
				@${MKDIR} $(@D)
				@${CC} ${CFLAGS} -c $< -o $@

-include $(DEPS)
