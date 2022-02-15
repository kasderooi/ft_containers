NAME		=	catch_test
SRCDIR		=	.
SRCS		=	main.cpp vector_test.cpp stack_test.cpp map_test.cpp
OBJDIR		=	objs
OBJS		=	$(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))
CC			=	clang++
FLAGS		=	-std=c++11
INC			=	-I../includes/containers -I../includes/iterators -I../includes/utils -I.

all:		$(NAME)

$(NAME):	$(OBJS)
	@$(CC) $(OBJS) $(FLAGS) -o $(NAME)
	@echo "You can now run ./$(NAME), enjoy!"

$(OBJDIR)/%.o:  $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	@$(CC) $(FLAGS) -c $< -o $@ $(INCS)

run:	$(NAME)
	@./catch_test

clean:
	@rm -rf $(OBJDIR)

fclean:		clean
	@rm -f $(NAME)

re:			fclean all

.PHONY:	all clean fclean re .cpp.o