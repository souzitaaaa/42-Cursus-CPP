#-------------------------------------  COLORS  --------------------------------
RESET			= \033[0m
BLACK 			= \033[1;30m
RED 			= \033[1;31m
GREEN 			= \033[1;32m
YELLOW		 	= \033[1;33m
BLUE			= \033[1;34m
PURPLE 			= \033[1;35m
CYAN 			= \033[1;36m
WHITE 			= \033[1;37m

#----------------------------------- COMMANDS ----------------------------------
CC				= c++
RM				= rm -rf

ifeq ($(OS),Windows_NT)
	DETECT_OS = Windows
	MKDIR = mkdir
	RM = del /Q /S
	FIX_PATH = $(subst /,\,$1)
	EXEC_EXT = .exe
else
	DETECT_OS = Linux
	MKDIR = mkdir -p
	RM = rm -rf
	FIX_PATH = $1
	EXEC_EXT = 
endif

#-----------------------------------  FLAGS  -----------------------------------
CFLAGS			= -Wall -Wextra -Werror -std=c++98
NPD				= --no-print-directory

#--------------------------------- FILES  ---------------------------------------
NAME 			= PmergeMe$(EXEC_EXT)
INCLUDE			= includes
OBJDIR			= obj

_FILES 			= PmergeMe

OBJ				= $(_FILES:%=%.o)
TARGET			= $(addprefix $(OBJDIR)/, $(OBJ))
_HEADERS		= PmergeMe.hpp
HDR				= $(call FIX_PATH,$(addprefix $(INCLUDE)/, $(_HEADERS)))

#---------------------------------  RULES  --------------------------------------

all: $(NAME)

$(NAME): $(OBJDIR) $(TARGET) main.cpp
	$(CC) $(CFLAGS) main.cpp  $(TARGET) -I $(INCLUDE) -o $(NAME)
	echo "[$(GREEN)Success$(RESET)] $(NAME) created!$(BOLD)$(RESET)"

$(OBJDIR)/%.o : %.cpp $(HDR)
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

$(OBJDIR):
	$(MKDIR) $(OBJDIR)

clean:
	$(RM) $(call FIX_PATH,$(OBJDIR))
	echo "[$(RED)Deleting$(RESET)]  object files deleted$(BOLD)$(RESET)"

fclean: clean
	$(RM) $(call FIX_PATH,$(NAME))
	echo "[$(RED)Deleting$(RESET)]  executable deleted$(BOLD)$(RESET)"

re: fclean all

.SILENT:

.PHONY: all clean fclean re
