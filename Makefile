#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 19:14:04 by rmc-coma          #+#    #+#              #
#    Updated: 2018/03/21 01:54:55 by rmc-coma         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all clean fclean clean_libs fclean_libs fclean_shaders \
	re shaders debug set_debug_mode

UNAME_S = $(shell uname -s)

NAME =			Engine
BUILDPATH =		build/
BUILD =			$(BUILDPATH)$(NAME)

HDRPATH =		includes/
SRCPATH =		sources/
LIBPATH =		lib/
BREWLIBPATH =	/Users/rmc-coma/.brew/include/
OBJPATH =		obj/
SHDPATH =		shaders/
LIBDIRS :=		QuickMaths/

LIBDIRS :=		$(LIBDIRS:%=$(LIBPATH)%)
HDRDIRS :=		$(HDRPATH) \
				$(BREWLIBPATH) \
				$(LIBPATH)QuickMaths/includes/

ifeq ($(UNAME_S),Linux)
INCLUDE_LIBS :=	-lSDL2 -lGL -lm -lassimp
endif
ifeq ($(UNAME_S),Darwin)
INCLUDE_LIBS := -framework SDL2 -framework OpenGL
endif


INCLUDE_LIBS := $(INCLUDE_LIBS)

LIBS :=			
LIBS :=			$(LIBS:%=$(LIBPATH)%)

SRCS =			\
				main.cpp \
				Transform.class.cpp \
				Window.class.cpp \
				Scene.class.cpp \
				GameObject.class.cpp \
				Component.class.cpp \
				MeshFilter.class.cpp \
				Mesh.class.cpp


HDRS_FILES =	\
				Transform.class.hpp \
				Window.class.hpp \
				Scene.class.hpp \
				GameObject.class.hpp \
				Component.class.hpp \
				MeshFilter.class.hpp \
				Mesh.class.hpp

HDRS =			$(HDRS_FILES:%=$(HDRPATH)%)
OBJS =			$(SRCS:%.cpp=$(OBJPATH)%.o)


CFLAGS =		-Wall -Wextra -Werror -g -fsanitize=address
LFLAGS =		-shared /Users/rmc-coma/.brew/Cellar/assimp/4.1.0/lib/*.dylib

CLEAN_LIBS =	$(LIBDIRS:%=$(MAKE) -C % clean > /dev/null;)
RM_LIBS =		$(LIBS:%=/bin/rm -f % > /dev/null;)

COMPILER =		g++ -std=c++11


all: $(BUILD)

$(OBJPATH)%.o: $(SRCPATH)%.cpp $(HDRS)
	@echo "$(NAME): compiling $<..."
	@mkdir -p $(@D)
	@$(COMPILER) $(CFLAGS) -o $@ -c $< $(HDRDIRS:%=-I%)

$(BUILD): $(LIBS) $(OBJS)
	@echo "$(NAME): linking..."
	@mkdir -p $(BUILDPATH)
	@$(COMPILER) $(CFLAGS) $(LFLAGS) -o "$(BUILDPATH)$(NAME)" $(OBJS) $(LIBDIRS:%=-L%) $(INCLUDE_LIBS)
	@echo "$(NAME): done"

%.a:
	@echo "$(NAME): compiling $@..."
	@$(MAKE) -s -C $(@D) > /dev/null

clean: clean_$(NAME) clean_libs

clean_$(NAME):
	@echo "$(NAME): cleaning..."
	@/bin/rm -f $(OBJS)

clean_libs:
	@echo "$(NAME): cleaning libs..."
	@$(CLEAN_LIBS)

fclean_libs: clean_libs
	@echo "$(NAME): removing lib builds..."
	@$(RM_LIBS)

fclean: clean_$(NAME) fclean_libs
	@/bin/rm -f $(BUILD)

fuckoff: debug

re: fclean all