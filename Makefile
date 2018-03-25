# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 19:14:04 by rmc-coma          #+#    #+#              #
#    Updated: 2018/03/24 15:19:49 by rmc-coma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean clean_libs fclean_libs fclean_shaders \
	re shaders debug set_debug_mode

UNAME_S = $(shell uname -s)

NAME =			Engine
BUILDPATH =		build/
BUILD =			$(BUILDPATH)$(NAME)

HDRPATH =		includes/
SRCPATH =		sources/
LIBPATH =		lib/
OBJPATH =		obj/
SHDPATH =		shaders/
LIBDIRS :=		QuickMaths/														\
				assimp/lib/

LIBDIRS :=		$(LIBDIRS:%=$(LIBPATH)%)
HDRDIRS :=		$(HDRPATH)														\
				$(LIBPATH)QuickMaths/includes/									\
				$(LIBPATH)assimp/includes/

ifeq ($(UNAME_S),Linux)
INCLUDE_LIBS :=	-lSDL2 -lGL -lm -lassimp
endif
ifeq ($(UNAME_S),Darwin)
INCLUDE_LIBS := -framework SDL2 -framework OpenGL -lassimp
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
				AComponent.class.cpp \
				MeshFilter.class.cpp \
				Mesh.class.cpp \
				MeshRenderer.class.cpp \
				Camera.class.cpp \
				Shader.class.cpp \
				Program.class.cpp \
				VAO.class.cpp \
				VBO.class.cpp \


HDRS_FILES =	\
				Transform.class.hpp \
				Window.class.hpp \
				Scene.class.hpp \
				GameObject.class.hpp \
				AComponent.class.hpp \
				MeshFilter.class.hpp \
				Mesh.class.hpp \
				MeshRenderer.class.hpp \
				Camera.class.hpp \
				Shader.class.hpp \
				Program.class.hpp \
				VAO.class.hpp \
				VBO.class.hpp \
				IUpdatable.class.hpp \
				IInitializable.class.hpp

HDRS =			$(HDRS_FILES:%=$(HDRPATH)%)
OBJS =			$(SRCS:%.cpp=$(OBJPATH)%.o)


CFLAGS =		-Wall -Wextra -Werror -g -fsanitize=address

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
	@$(COMPILER) $(CFLAGS) -o "$(BUILDPATH)$(NAME)" $(OBJS) $(LIBDIRS:%=-L%) $(INCLUDE_LIBS)
	@echo "$(NAME): done"

%.a:
	@echo "$(NAME): compiling $@..."
	@$(MAKE) -s -C $(@D) > /dev/null

clean: clean_$(NAME) #clean_libs

clean_$(NAME):
	@echo "$(NAME): cleaning..."
	@/bin/rm -f $(OBJS)

#clean_libs:
#	@echo "$(NAME): cleaning libs..."
#	@$(CLEAN_LIBS)

#fclean_libs: clean_libs
#	@echo "$(NAME): removing lib builds..."
#	@$(RM_LIBS)

fclean: clean_$(NAME) #fclean_libs
	@/bin/rm -f $(BUILD)
	@/bin/rm -rf $(BUILDPATH)
	@/bin/rm -rf $(OBJPATH)

fuckoff: debug

re: fclean all