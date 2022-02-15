NAME		=	$(TEST_VEC) $(TEST_STA) $(TEST_MAP)
TEST_VEC	=	time_vec
TEST_STA	=	time_sta
TEST_MAP	=	time_map
SRCS_VEC	=	main_vec.cpp
SRCS_STA	=	main_stack.cpp
SRCS_MAP	=	main_map.cpp
OBJDIR_VEC	=	objs_vec
OBJDIR_STA	=	objs_sta
OBJDIR_MAP	=	objs_map
OBJS_VEC	=	$(addprefix $(OBJDIR_VEC)/, $(SRCS_VEC:.cpp=.o))
OBJS_STA	=	$(addprefix $(OBJDIR_STA)/, $(SRCS_STA:.cpp=.o))
OBJS_MAP	=	$(addprefix $(OBJDIR_MAP)/, $(SRCS_MAP:.cpp=.o))
CC			=	clang++
FLAGS		=	-Wall -Wextra -Werror -pedantic -std=c++98
INCS		=	-I../includes/containers -I../includes/iterators -I../includes/utils

all:		$(NAME)

$(TEST_VEC):	$(OBJS_VEC)
	@$(CC) $(OBJS_VEC) $(FLAGS) -o $(TEST_VEC)

$(OBJDIR_VEC)/%.o:  $(SRCS_VEC)
	@mkdir -p $(OBJDIR_VEC)
	@$(CC) $(FLAGS) -c $< -o $@ $(INCS)

$(TEST_STA):	$(OBJS_STA)
	@$(CC) $(OBJS_STA) $(FLAGS) -o $(TEST_STA)

$(OBJDIR_STA)/%.o:  $(SRCS_STA)
	@mkdir -p $(OBJDIR_STA)
	@$(CC) $(FLAGS) -c $< -o $@ $(INCS)

$(TEST_MAP):	$(OBJS_MAP)
	@$(CC) $(OBJS_MAP) $(FLAGS) -o $(TEST_MAP)

$(OBJDIR_MAP)/%.o:  $(SRCS_MAP)
	@mkdir -p $(OBJDIR_MAP)
	@$(CC) $(FLAGS) -c $< -o $@ $(INCS)

run:	$(NAME)
	@echo "\033[92m***********************_______Vector speed test_______***********************\033[0m"
	@./time_vec
	@echo "\033[92m***********************_______Stack speed test_______***********************\033[0m"
	@./time_sta
	@echo "\033[92m***********************_______Map speed test_______***********************\033[0m"
	@./time_map

clean:
	@rm -rf $(OBJDIR_VEC) $(OBJDIR_STA) $(OBJDIR_MAP)

fclean:		clean
	@rm -f $(NAME)

re:			fclean all

.PHONY:	all clean fclean re .cpp.o