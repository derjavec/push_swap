NAME		=	push_swap
NAME_B		= 	checker
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g #-fsanitize=address
RM			=	rm -rf
MAIN        	= 	main.c
MAIN_O		=	$(MAIN:.c=.o)
SRC			=	push_swap.c push.c swap.c rotate.c reverse_rotate.c \
				utils/parsing.c utils/ft_split.c utils/ft_split_utils.c \
				utils/creat_list.c utils/return_to_a.c utils/base_case.c utils/error.c \
				utils/ft_bzero.c utils/ft_atoi.c utils/ft_lstadd_back.c utils/ft_lstadd_front.c \
				utils/ft_lstclear.c utils/ft_lstdellast.c utils/ft_lstlast.c utils/ft_lstnew.c \
				utils/ft_strlen.c utils/ft_order.c utils/ft_find_min_max.c utils/ft_position_x.c \
				utils/break_point.c utils/calculate_fraction.c utils/find_div.c utils/push_b_borders.c \
				utils/turn_list_a.c  utils/choice_ra_rra.c  utils/free_all.c 
OBJ			=	$(SRC:.c=.o)
SRC_B		=    Bonus/free_all_bonus.c Bonus/push_bonus.c Bonus/swap_bonus.c \
				Bonus/rotate_bonus.c Bonus/reverse_rotate_bonus.c  Bonus/checker_utils.c \
				Bonus/checker.c Bonus/ft_strncmp.c Bonus/gnl/get_next_line.c Bonus/gnl/get_next_line_utils.c Bonus/take_instructions.c \
				push_swap.c push.c swap.c rotate.c reverse_rotate.c \
				utils/parsing.c utils/ft_split.c utils/ft_split_utils.c \
				utils/creat_list.c utils/return_to_a.c utils/base_case.c utils/error.c \
				utils/ft_bzero.c utils/ft_atoi.c utils/ft_lstadd_back.c utils/ft_lstadd_front.c \
				utils/ft_lstclear.c utils/ft_lstdellast.c utils/ft_lstlast.c utils/ft_lstnew.c \
				utils/ft_strlen.c utils/ft_order.c utils/ft_find_min_max.c utils/ft_position_x.c \
				utils/break_point.c utils/calculate_fraction.c utils/find_div.c utils/push_b_borders.c \
				utils/turn_list_a.c  utils/choice_ra_rra.c  utils/free_all.c 

OBJ_B			=	$(SRC_B:.c=.o)
HEADER		= push_swap.h Bonus/checker.h Bonus/gnl/get_next_line.h


%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(MAIN_O)
	$(CC) $(CFLAGS) $(OBJ) $(MAIN_O) -o $(NAME)

bonus: $(OBJ_B)
	$(CC) $(CFLAGS) $(OBJ_B) -o $(NAME_B)

clean:
	$(RM) $(OBJ) $(OBJ_B) $(MAIN_O)
	
fclean: clean
	$(RM) $(NAME) $(NAME_B)
	
re: fclean all
	
.PHONY: all bonus clean fclean re
