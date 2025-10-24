V = false

ifeq ($(V),true)
	ECHO =
else
	ECHO = @
endif

# Nom du programme
NAME = cub3D

# Compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address
OS = $(shell uname | tr '[:upper:]' '[:lower:]')

MAKE = make -sC
MKDIR = mkdir -p
RM = rm -rf

# Lib perso
LIB_DIR = lib
LIB = $(LIB_DIR)/lib.a
LINKER = $(LIB)

# Info système
$(info 🖥️ OS détecté : $(OS))

# MiniLibX - Platform-dependent compilation
MLX_BASE ?= minilibx
ifeq ($(OS),linux)
	MLX_DIR         := $(MLX_BASE)/minilibx-linux
	MLX             := $(MLX_DIR)/libmlx.a
	INCLUDES_FLAG   += -I$(MLX_DIR)
	LINKER          += -L$(MLX_DIR) -lmlx -lm -lz -lXext -lX11
else
	# macOS — détection du support Metal (FR/EN) + présence du dossier Metal
	METAL_SUPPORTED := $(shell system_profiler SPDisplaysDataType 2>/dev/null | grep -Eiq 'Metal.*(Pris en charge|Supported)' && echo yes || echo no)
	HAS_METAL_DIR   := $(shell test -d $(MLX_BASE)/minilibx_macos_metal && echo yes)

ifneq ($(and $(METAL_SUPPORTED),$(HAS_METAL_DIR)),)
	# → Metal OK
	MLX_DIR         := $(MLX_BASE)/minilibx_macos_metal
	MLX             := $(MLX_DIR)/libmlx.a
	INCLUDES_FLAG   += -I$(MLX_DIR)
	LINKER          += -L$(MLX_DIR) -lmlx -framework Metal -framework MetalKit -framework AppKit
else
	# → fallback OpenGL
	MLX_DIR         := $(MLX_BASE)/minilibx_macos_opengl
	MLX             := $(MLX_DIR)/libmlx.a
	INCLUDES_FLAG   += -I$(MLX_DIR)
	LINKER          += -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif
endif

# Includes
INCLUDE_DIR = include
LIB_SUBDIR = $(wildcard $(LIB_DIR)/*)

INCLUDE_FLAG = -I$(INCLUDE_DIR) \
			   $(foreach dir, $(LIB_SUBDIR), -I$(dir))

INCLUDE = $(wildcard $(INCLUDE_DIR)/*.h) \
		  $(foreach dir, $(LIB_SUBDIR), $(wildcard $(dir)/*.h))

# Dossiers sources
SRC_DIR = src/

# Fichiers sources (relatifs à SRC_DIR)


SRC_FILES = main.c



# Chemins complets des sources et objets
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS_DIR = objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRC_FILES:.c=.o))

# Couleurs ANSI
GREEN = \033[32m
RED = \033[31m
RESET = \033[0m
YELLOW = \033[33m
CLEAR_LINE = \033[2K\r
PINK  = \033[95m
WHITE = \033[97m

# Logo cool
logo ?= false   # false => affiche le logo, true => masque

PRINT_LOGO = \
	if [ "$(logo)" = "true" ]; then \
	echo ""; \
	printf "$(PINK)"; \
	printf "                                                                                         \n"; \
	printf "_|        _|                                                        _|_|_|    _|_|_|    \n"; \
	printf "_|              _|_|_|    _|_|    _|  _|_|  _|_|_|      _|_|              _|  _|    _|  \n"; \
	printf "_|        _|  _|        _|    _|  _|_|      _|    _|  _|_|_|_|        _|_|    _|    _|  \n"; \
	printf "_|        _|  _|        _|    _|  _|        _|    _|  _|                  _|  _|    _|  \n"; \
	printf "_|_|_|_|  _|    _|_|_|    _|_|    _|        _|    _|    _|_|_|      _|_|_|    _|_|_|    \n"; \
	printf "$(RESET)"; \
	printf "$(WHITE)"; \
	printf "                                   L I C O R N E   3 D                                     \n"; \
	printf "$(RESET)\n"; \
	echo "  ┌─────────────────────────────┐"; \
	echo "  │                             │"; \
	echo "  │  FPS = Frames Per Segfault  │"; \
	echo "  │                             │"; \
	echo "  └─────────────────────────────┘"; \
	echo "                                           "; \
	echo "     lea 🤝 aumartin"; \
	fi


# Compilation principale
all: $(LIB) $(MLX) $(NAME)
	@$(PRINT_LOGO)


# Compilation lib
$(LIB):
	@echo "$(YELLOW)📦 Compilation de la lib...$(RESET)\r"
	@$(MAKE) $(LIB_DIR) > /dev/null 2>&1 \
	&& echo -e "$(CLEAR_LINE)✅ Compilation lib réussie (✔)" \
	|| { echo -e "$(CLEAR_LINE)❌ Erreur : Compilation de la lib échouée (✘)"; exit 1; }

$(MLX):
	@echo "$(YELLOW)📦 Compilation de MiniLibX...$(RESET)\r"
	@$(MAKE) $(MLX_DIR) > /dev/null 2>&1 \
	&& echo -e "$(CLEAR_LINE)✅ Compilation mlx réussie (✔)" \
	|| { echo -e "$(CLEAR_LINE)❌ Erreur : Compilation de MiniLibX échouée (✘)"; exit 1; }

# Règle pour objets
$(OBJS_DIR):
	@$(MKDIR) $(OBJS_DIR)

$(OBJS_DIR)%.o: $(SRC_DIR)%.c $(INCLUDE)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE_FLAG) -c $< -o $@

$(OBJS_DIR)main.o: main.c $(INCLUDE) | $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE_FLAG) -c $< -o $(OBJS_DIR)main.o

# Compilation du binaire
$(NAME): $(OBJS) $(LIB) $(MLX)
	@echo "🚀 Compilation de $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LINKER) -o $(NAME) && echo "✅ $(NAME) a été créé avec succès (✔)" \

# Nettoyage
clean:
	@echo "$(YELLOW)🧹 Nettoyage clean en cours...$(RESET)\r"
	@$(RM) $(OBJS_DIR)
	@echo -e "$(CLEAR_LINE)✅ Nettoyage clean réussi (✔)"

fclean: clean
	@echo "$(YELLOW)🧼 Nettoyage complet fclean en cours...$(RESET)\r"
	@$(RM) $(NAME)
	@$(MAKE) $(LIB_DIR) fclean
	@$(MAKE) $(MLX_DIR) clean
	@echo -e "$(CLEAR_LINE)✅ Nettoyage complet fclean réussi (✔)"

re: fclean all

.PHONY: all clean fclean re
