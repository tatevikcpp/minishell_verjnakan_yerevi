NAME = minishell

CC = cc

CFLAGS =  -I./readline_sona/include -ggdb3  -Wall -Wextra -Werror #-fsanitize=address -g  #-Werror #-fstack-protector-all    

SRCS = $(wildcard ./src/*.c) 

OBJS = $(patsubst %.c, %.o, $(SRCS))

INCLUDES = -Ilibft  -I./include

LINKERS	= -L./libft   -lreadline

LINKERLIBFT = ./libft/libft.a

LIBFT = ./libft

LINKERLIBFTPRINTF = ./ft_printf/libftprintf.a

FTPRINTF = ./ft_printf

HEADER = $(wildcard ./src/*.h) 

RM = rm -f

RD =  $(PWD)/readline-tatev


ifeq ($(HOME), /Users/tkhechoy)
LINKERS	+= -L./readline-tatev/lib
INCLUDES += -I$(PWD)/readline-tatev/include
else
INCLUDES += -I$(PWD)/readline-sona/include
LINKERS	+= -L./readline_sona/lib
endif

%.o: %.c  ${HEADER} Makefile
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME) 
	
$(NAME): $(OBJS) $(LINKERLIBFT) $(LINKERLIBFTPRINTF)
	$(CC) $(CFLAGS) $(LINKERS) $(LINKERLIBFT) $(LINKERLIBFTPRINTF) $(INCLUDES) $(OBJS) -o $(NAME)

$(LINKERLIBFTPRINTF) :
	$(MAKE) -C $(FTPRINTF)

$(LINKERLIBFT) :
	$(MAKE) -C $(LIBFT)

clean:
	$(MAKE) clean -C $(LIBFT)
	$(MAKE) clean -C $(FTPRINTF)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	$(MAKE) fclean -C $(FTPRINTF)
	$(RM) $(NAME)
	echo $(NONE) $(RED)"       >Removed< $(NAME)" $(NONE)

re: fclean all

norm: clean
	norminette $(SRCS)

readline:
	cd readline-master  && make clean && ./configure --prefix=$(RD) && make  && make install

.PHONY: all clean fclean re
