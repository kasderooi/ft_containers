NAME				=	$(TEST_SUBJECT_FT) $(TEST_SUBJECT_STD)
TEST_SUBJECT_FT		=	test_subject_ft
TEST_SUBJECT_STD	=	test_subject_std
SRCS_SUBJECT_FT		=	main_subject_ft.cpp
SRCS_SUBJECT_STD	=	main_subject_std.cpp
OBJDIR_SUBJECT_FT	=	objs_subject_ft
OBJDIR_SUBJECT_STD	=	objs_subject_std
OBJS_SUBJECT_FT		=	$(addprefix $(OBJDIR_SUBJECT_FT)/, $(SRCS_SUBJECT_FT:.cpp=.o))
OBJS_SUBJECT_STD	=	$(addprefix $(OBJDIR_SUBJECT_STD)/, $(SRCS_SUBJECT_STD:.cpp=.o))
CC					=	clang++
FLAGS				=	-Wall -Wextra -Werror -pedantic -std=c++98
INCS				=	-I../includes/containers -I../includes/iterators -I../includes/utils

all:		$(NAME)

$(TEST_SUBJECT_FT):	$(OBJS_SUBJECT_FT)
	@$(CC) $(OBJS_SUBJECT_FT) $(FLAGS) -o $(TEST_SUBJECT_FT)

$(OBJDIR_SUBJECT_FT)/%.o:  $(SRCS_SUBJECT_FT)
	@mkdir -p $(OBJDIR_SUBJECT_FT)
	@$(CC) $(FLAGS) -c $< -o $@ $(INCS)

$(TEST_SUBJECT_STD):	$(OBJS_SUBJECT_STD)
	@$(CC) $(OBJS_SUBJECT_STD) $(FLAGS) -o $(TEST_SUBJECT_STD)

$(OBJDIR_SUBJECT_STD)/%.o:  $(SRCS_SUBJECT_STD)
	@mkdir -p $(OBJDIR_SUBJECT_STD)
	@$(CC) $(FLAGS) -c $< -o $@ $(INCS)

run:	$(NAME)
	@echo "\033[92m***********************_______Subject_ft_______***********************\033[0m"
	@echo "test seed is 25"
	@echo "\033[92m_______Subject_ft_______\033[0m"
	@./test_subject_ft 25
	@echo "\033[92m_______Subject_std_______\033[0m"
	@./test_subject_std 25

clean:
	@rm -rf $(OBJDIR_SUBJECT_FT) $(OBJDIR_SUBJECT_STD)

fclean:		clean
	@rm -f $(NAME)

re:			fclean all

.PHONY:	all clean fclean re .cpp.o