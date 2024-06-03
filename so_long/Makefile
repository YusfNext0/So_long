NAME = so_long

NAME_BONUS = so_long_bonus

SRCS = mandatory/main.c mandatory/src/ft_strchr.c mandatory/src/ft_strlen.c mandatory/src/ft_putstr_fd.c \
		mandatory/src/ft_itoa.c mandatory/src/ft_strdup.c mandatory/get_next_line/get_next_line.c mandatory/get_next_line/get_next_line_utils.c  \
		mandatory/src/ft_strcmp.c mandatory/src/ft_split.c mandatory/src/ft_substr.c mandatory/src/ft_strlcpy.c \
		mandatory/src/free_mat.c mandatory/parsing.c mandatory/parsing_utils.c \
		mandatory/ft_put_img.c mandatory/parsing_utils2.c

SRCS_BONUS = bonus/main_bonus.c bonus/src/ft_strchr_bonus.c bonus/src/ft_strlen_bonus.c bonus/src/ft_putstr_fd_bonus.c \
		bonus/src/ft_itoa_bonus.c bonus/src/ft_strdup_bonus.c bonus/get_next_line/get_next_line_bonus.c bonus/get_next_line/get_next_line_utils_bonus.c \
		bonus/src/ft_strcmp_bonus.c bonus/src/ft_split_bonus.c bonus/src/ft_substr_bonus.c bonus/src/ft_strlcpy_bonus.c \
		bonus/src/free_mat_bonus.c bonus/parsing_bonus.c bonus/parsing_utils_bonus.c \
		bonus/ft_put_img_bonus.c bonus/parsing_utils2_bonus.c bonus/animation_utils_bonus.c

OBJ = $(SRCS:.c=.o)
OBJ_BONUS = $(SRCS_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

bonus: $(NAME_BONUS)

mandatory/%.o: mandatory/%.c mandatory/so_long.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus/%.o: bonus/%.c bonus/so_long_bonus.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $^ -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS) 

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all
