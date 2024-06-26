NAME = scop
CFLAGS =  -Wno-deprecated-declarations -Wno-macro-redefined -Wno-c++11-extensions -std=c++11 -Werror -Wall -Wextra -Wno-reorder -I/Users/${USER}/.brew/Cellar/glm/1.0.1/include
GLFW = -I/Users/${USER}/.brew/Cellar/glfw/3.4/include -L/Users/${USER}/.brew/Cellar/glfw/3.4/lib -lglfw -framework OpenGL -framework CoreGraphics -framework CoreFoundation
GLEW = -I/Users/${USER}/.brew/Cellar/glew/2.2.0_1/include -L/Users/${USER}/.brew/Cellar/glew/2.2.0_1/lib -lGLEW -framework OpenGL
GLAD = glad.o
GLADLIB = gcc -c src/includes/glad/glad.c -Ilibs

EXEC = ./scop

# Vertex and Fragment shader source files
VERTEX_SOURCE = src/shader/vertexSource.vertex
FRAGMENT_SOURCE = src/shader/fragmentSource.fragment

RS = ../resources/
TX = textures/

# Texture files
TEXTURE_OK = ${TX}ok.jpeg
TEXTURE_COLORS = ${TX}colors.jpeg
TEXTURE_SKULL = ${TX}skull.jpeg
TEXTURE_CAMEL = ${TX}camel.jpeg
TEXTURE_UVMAP = ${TX}uvmap.jpeg
TEXTURE_TREX = ${TX}trex.jpeg
TEXTURE_PUMPKIN = ${TX}pumpkin.png
TEXTURE_MONSTER = ${TX}monster.jpeg

TEXTURES = ${TEXTURE_OK} ${TEXTURE_COLORS} ${TEXTURE_CAMEL} \
		   ${TEXTURE_SKULL} ${TEXTURE_TREX} ${TEXTURE_UVMAP} \
		   ${TEXTURE_MONSTER} ${TEXTURE_PUMPKIN} \

# Object files
OBJECT_HUMAN = ${RS}human.obj

REBUILD = make re
RM		= rm -rf
CC		= c++
SRC_DIR = src/
OBJ_DIR = objects/

SRC = scop \
	  glfw \
	  utils \
	  camera \
	  render \
	  object \
	  texture \
	  keyPress \
	  renderText \
	  shader/shader \
	  processObjFile \
	  slider \
	  cube \

# Imgui source files to compile
IMGUI =	includes/imgui/imgui \
		includes/imgui/imgui_demo \
		includes/imgui/imgui_draw \
		includes/imgui/imgui_tables \
		includes/imgui/imgui_widgets \
		includes/imgui/imgui_impl_glfw \
		includes/imgui/imgui_impl_opengl3 \

SRCS	= $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRC)))
OBJS	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC)))
IMGUI_SRCS	= $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(IMGUI)))
IMGUI_OBJS	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(IMGUI)))
all: $(NAME)

$(NAME): $(OBJS) ${IMGUI_OBJS}
	@echo "$(YELLOW)Compiling..$(COLOR_END)"
	@${GLADLIB}
	@$(CC) $(CFLAGS) $(GLEW) $(GLFW) ${GLAD} $(OBJS) ${IMGUI_OBJS} -o $(NAME)
	@echo "$(GREEN)The project is compiled..$(COLOR_END)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning...$(COLOR_END)"
	@$(RM) $(OBJ_DIR)
	@echo "$(GREEN)Cleaning done.$(COLOR_END)"


fclean: clean
	@echo "$(YELLOW)Cleaning everything...$(COLOR_END)"
	@$(RM) $(NAME) home_shrubbery
	@echo "$(GREEN)Cleaning done.$(COLOR_END)"

re:
	@echo "$(YELLOW)Recompiling...$(COLOR_END)"
	@make fclean
	@rm -rf ${OBJ_DIR}
	@make all
	@echo "$(GREEN)The project has been recompiled.$(COLOR_END)"

# Test option
human:
	make
	@${EXEC} ${VERTEX_SOURCE} ${FRAGMENT_SOURCE} ${OBJECT_HUMAN} ${TEXTURES}

dependencies:
	@echo "$(YELLOW)Installing dependencies...$(COLOR_END)"
	@brew install glfw glew glm
	@echo "$(GREEN)Dependencies installed.$(COLOR_END)"

.PHONY: all clean fclean re human dependencies

COLOR_END = \033[0;39m
CYAN3 = \033[1;4;96m
YELLOW = \033[1;33m
PURPLE = \033[1;35m
BWhite = \033[1;37m
RED = \033[1;91m
GREEN = \033[1;92m
CYAN2 = \x1B[1;36m
CYAN = \033[1;96m