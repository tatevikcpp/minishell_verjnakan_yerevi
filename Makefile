NAME = minishell

CC = cc

CFLAGS =  -I./readline_sona/include -ggdb3   -g -fsanitize=address #-Wall -Werror -Wextra

SRCS = $(wildcard *.c) 

OBJS = $(patsubst %.c, %.o, $(SRCS))

INCLUDES = -Ilibft  -I./include

LINKERS	= -L./libft  -L./readline_sona/lib -lreadline

LINKERLIB = ./libft/libft.a

LIBFT = ./libft

HEADER = $(wildcard *.h) 

RM = rm -f

RD =  $(shell find ${HOME} -name readline_sona 2>/dev/null)

LINKERS	= -lreadline


%.o: %.c  ${HEADER}
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# all: readline $(NAME) 
all: $(NAME) 
	
$(NAME): $(OBJS) $(LINKERLIB) 
	$(CC) $(CFLAGS) $(LINKERS) $(LINKERLIB) $(INCLUDES) $(OBJS) -o $(NAME)

$(LINKERLIB) :
	$(MAKE) -C $(LIBFT)

clean:
	$(MAKE) clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	$(RM) $(NAME)
	echo $(NONE) $(RED)"       >Removed< $(NAME)" $(NONE)

re: fclean all

norm: clean
	norminette $(SRCS)

readline:
	cd readline-master && make clean && ./configure --prefix=$(RD) && make  && make install

.PHONY: all clean fclean re
