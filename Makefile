NAME = humangl
CFLAGS =  -Wno-deprecated-declarations -Wno-macro-redefined -Wno-c++11-extensions -std=c++11
GLFW = -I/Users/${USER}/.brew/Cellar/glfw/3.3.8/include -L/Users/${USER}/.brew/Cellar/glfw/3.3.8/lib -lglfw -framework OpenGL -framework CoreGraphics -framework CoreFoundation
GLEW = -I/Users/${USER}/.brew/Cellar/glew/2.2.0_1/include -L/Users/${USER}/.brew/Cellar/glew/2.2.0_1/lib -lGLEW -framework OpenGL

GLAD = glad.o
GLADLIB = gcc -c includes/glad/glad.c -Ilibs

EXEC = ./humangl

# Vertex and Fragment shader source files
VERTEX_SOURCE = ../shader/vertexSource.vertex
FRAGMENT_SOURCE = ../shader/fragmentSource.fragment

RS = ../resources/
TX = ../textures/

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
OBJECT_H = ${RS}humangl.obj


REBUILD = make re
RM		= rm -rf
CC		= c++
SRC_DIR = src/
OBJ_DIR = objects/
SHADER_DIR = shader/
SHADER_OBJ = objects/
IMGUI_DIR = includes/imgui/
IMGUI_OBJ = objects/

SRC = scop \
	  glfw \
	  camera \
	  render \
	  object \
	  texture \
	  keyPress \
	  renderText \
	  processObjFile \

SHADER = shader \

# Imgui source files to compile
IMGUI =	imgui \
		imgui_demo \
		imgui_draw \
		imgui_tables \
		imgui_widgets \
		imgui_impl_glfw \
		imgui_impl_opengl3 \

SHADER_SRCS	= $(addprefix $(SHADER_DIR), $(addsuffix .cpp, $(SHADER)))
SHADER_OBJS	= $(addprefix $(SHADER_OBJ), $(addsuffix .o, $(SHADER)))
SRCS	= $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRC)))
OBJS	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC)))
IMGUI_SRCS	= $(addprefix $(IMGUI_DIR), $(addsuffix .cpp, $(IMGUI)))
IMGUI_OBJS	= $(addprefix $(IMGUI_OBJ), $(addsuffix .o, $(IMGUI)))

all: $(NAME)

$(NAME): ${SHADER_OBJS} $(OBJS) ${IMGUI_OBJS}
	@echo "$(YELLOW)Compiling..$(COLOR_END)"
	@${GLADLIB}
	@$(CC) $(CFLAGS) $(GLEW) $(GLFW) ${GLAD} ${SHADER_OBJS} $(OBJS) ${IMGUI_OBJS} -o $(NAME)
	@echo "$(GREEN)The project is compiled..$(COLOR_END)"

$(SHADER_OBJ)%.o: $(SHADER_DIR)%.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(IMGUI_OBJ)%.o: $(IMGUI_DIR)%.cpp
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

# Test options
h:
	@${REBUILD}
	@${EXEC} ${VERTEX_SOURCE} ${FRAGMENT_SOURCE} ${OBJECT_H} ${TEXTURES}


.PHONY: all clean fclean re 42 teapot spider skull axe alien building sw hb camel castle trex house parrot tricc plane monster sculp

COLOR_END = \033[0;39m
CYAN3 = \033[1;4;96m
YELLOW = \033[1;33m
PURPLE = \033[1;35m
BWhite = \033[1;37m
RED = \033[1;91m
GREEN = \033[1;92m
CYAN2 = \x1B[1;36m
CYAN = \033[1;96m