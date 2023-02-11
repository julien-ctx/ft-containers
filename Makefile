GREEN = "\033[1;32m"
RED = "\033[1;31m"
YELLOW = "\033[1;33m"
BLUE = "\033[1;34m"
WHITE = "\033[1;37m"
RESET = "\033[0m"

NAME = ft_containers

PROJECT = FT_CONTAINERS

SRCS = main.cpp \
		$(addprefix ./tests/, vectorTest.cpp stackTest.cpp mapTest.cpp) \
		
OBJS = $(SRCS:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME) 

mli:
	@if [ ! -d "./containers_test" ]; then \
		git clone https://github.com/mli42/containers_test.git; \
		awk '{if(NR==3) {print "# include \"../../../containers/vector.hpp\""} else {print}}' containers_test/srcs/vector/common.hpp > tmp && mv tmp containers_test/srcs/vector/common.hpp; \
		awk '{if(NR==3) {print "# include \"../../../containers/stack.hpp\""} else {print}}' containers_test/srcs/stack/common.hpp > tmp && mv tmp containers_test/srcs/stack/common.hpp; \
		awk '{if(NR==3) {print "# include \"../../../containers/map.hpp\""} else {print}}' containers_test/srcs/map/common.hpp > tmp && mv tmp containers_test/srcs/map/common.hpp; \
	fi
	cd containers_test && ./do.sh vector && ./do.sh stack && ./do.sh map; \

.cpp.o: $(SRCS)
	@printf $(GREEN)"\r\033[KCreating object files 👉 "$(YELLOW)"<$<> "$(RESET)
	@c++ $(CPPFLAGS) -c $< -o $(<:.cpp=.o)

main.o: containers/*.hpp utils/*.hpp

$(NAME): $(OBJS)
	@c++ $(CPPFLAGS) -o $(NAME) $(SRCS)
	@printf $(GREEN)"\r\033[K✅ SUCCESS: "$(WHITE)$(NAME)$(GREEN)" has been created\n"$(RESET)

clean:
	@rm -rf $(OBJS) 
	@printf $(RED)"\r\033[K➜ ["$(PROJECT)"] "$(WHITE)"clean"$(RED)" has been done\n"$(RESET)

fclean: clean
	@rm -rf $(NAME)
	@printf $(RED)"\r\033[K➜ ["$(PROJECT)"] "$(WHITE)"fclean"$(RED)" has been done\n"$(RESET)

re: fclean all

.PHONY: all clean fclean re mli
