

#SRCS

NAME	:= Arry

SRCS	:= main.cpp

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


$(OBJS_DIR)%.o	: %.cpp
				@${MKDIR} $(@D)
				@${CC} ${CFLAGS} -c $< -o $@

-include $(DEPS)
