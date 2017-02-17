# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchaumar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/23 12:31:27 by cchaumar          #+#    #+#              #
#    Updated: 2017/02/17 05:47:51 by cchaumar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME   = glhandler.a
CFLG   =  -Wextra -Wall -Werror -g -fsanitize=address
FILES  = gl_objects.c
SRCD   = srcs/
OBJD   = objs/
GITLIB = 'https://github.com\/sethquantix/libft.git'
SRCS   = $(addprefix $(SRCD),$(FILES))
OBJS   = $(addprefix $(OBJD),$(FILES:.c=.o))
FROPEN = -framework OpenGL -framework OpenCL
FRMCOS = -framework Appkit
LIBD   = libs
LIBFT  = $(LIBD)/libft
MLX    = $(LIBD)/mlx
GLEW   = $(LIBD)/glew
FRAMEWORKS = $(FROPEN) $(FRMCOS)
INCD   = -Iincludes -I$(LIBFTI) -I$(MLXI) -I$(GLEWINC)

all : $(NAME)

$(OBJD)%.o: $(SRCD)%.c
	@mkdir -p objs
	gcc $(CFLG) $(INCD) -c -o $@ $<

build:
		make -C $(LIBFT)
		make -C $(MLX)

$(NAME): $(OBJS) build
		ar rc $@ $(OBJS)
		ranlib $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all
