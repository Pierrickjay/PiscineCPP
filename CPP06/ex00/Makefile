
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

NAME	:= ScalarConverter

SRCS	:= main.cpp ScalarConverter.cpp

OBJS_DIR := ./objs/

OBJS	:= $(SRCS:.cpp=.o)

OBJS	:= $(addprefix $(OBJS_DIR),$(OBJS))

DEPS	:= ${OBJS:.o=.d}

CC		:= c++

CFLAGS	:= -Wall -Wextra -Werror -std=c++98 -MMD -g3

RM		:= rm -rf

MKDIR	:= mkdir -p

# PROGRESS BAR

NB_OBJS			= ${words ${OBJS}}

COUNTER			= 1

PROGRESS		= 0

DONE 			= 100

SPACE		 	= 0

FILL			= 0

EMPTY			= 0

#define PROGRESS_BAR
#	$(eval PROGRESS=$(shell echo $$(($(COUNTER) * 100 / $(NB_OBJS)))))
#	$(eval DONE=$(shell echo $$(($(PROGRESS) * 30 / 100))))
#	$(eval SPACE=$(shell echo $$((30 - $(DONE)))))
#	$(eval FILL=$(shell printf "%*s" ${DONE} | sed 's/ /█/g'))
#	$(eval EMPTY=$(shell printf "%*s" ${SPACE} | sed 's/ /█/g'))
#	printf "\r${CLEAR}${SYELLOW}Compile : ${SGREEN}${FILL}${SRED}${EMPTY} ${SGREEN}%3d%%${SOFF} %s.cpp" ${PROGRESS} $1
#	$(eval COUNTER=$(shell echo $$(($(COUNTER) + 1))))
#endef

# RULES

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

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
#				@$(call PROGRESS_BAR, $(basename $(notdir $<)))

-include $(DEPS)
