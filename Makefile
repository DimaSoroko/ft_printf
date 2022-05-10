# --------------------------------------------------------------------VARS ---------------------------------------------------------------------------------------------

NAME			= libftprintf.a                    									# name of the programm

CC				= gcc                        										# compiler

FLAGS			= -Wall -Wextra -Werror      										# flags

RM				= rm -f                      										# remove 

LIBC 			= ar rcs					 										# creates library archive

# -----------------------------------------------------------------SOURCE FILES ----------------------------------------------------------------------------------------

SRCS			= 	ft_length_and_transform.c\
					ft_print_chars.c\
					ft_print_nbrs.c\
					ft_get_and_print_pointer.c\
					ft_printf.c\


OBJS	   		 = $(addprefix srcs/, $(SRCS:.c=.o))       	 										# trasnforms all the ".c" files into ".o" (objects)

# -------------------------------------------------------------------- RULES -------------------------------------------------------------------------------------------

.c.o:		
			$(CC) $(FLAGS) -c -I./includes $< -o $(<:.c=.o)

all:	    $(NAME)   																# will execute NAME rule
		
$(NAME):	$(OBJS)                                                                      
			$(LIBC) $(NAME) $(OBJS)
			@echo "...Compilation succeeded, 'libftprintf.a has beed created!"

clean: 																				# remove all .o
			$(RM) $(OBJS) 
			@echo "...clean succeeded, all the '.o' has been removed!"
														         
fclean: clean                            											# force remove NAME
			$(RM) $(NAME)
			@echo "...fclean succeeded, 'libftprintf.a' has been removed!"


re: fclean all																		# rule to recompile MAKEFILE (will remove everything and allows to recompile again)
			@echo "...recompile succeeded!"		

# ----------------------------------------------------------------------PHONY --------------------------------------------------------------------------------------------

.PHONY: all clean fclean re             											 # in phony section we need to include all used rules
