GAME = so_long

PROG = so_long.c

CFLAGS = -Wextra -Wall -Werror

FRAMEWORK = -lmlx -framework OpenGL -framework AppKit

SRC = Src/init.c Src/error.c

MAP = Map/parse_map.c Map/check_map.c

WORLD = World/set_map.c World/set_wall.c

UTILS = Utils/ft_split.c Utils/ft_strjoin.c Utils/ft_strlcat.c Utils/ft_substr.c Utils/ft_itoa.c \
		Utils/ft_calloc.c Utils/ft_strcmp.c Utils/ft_strlen.c

END = End/end_game.c End/over.c

ANIMATION = Animation/anime_utils.c Animation/anime_utils1.c Animation/anime.c Animation/anime_player.c Animation/anime_enemy.c

PLAY =  Play/move.c PLay/collision.c Play/move_count.c Play/move_player.c

all : $(GAME)

$(GAME) : $(MAP) $(UTILS) $(PROG) $(SRC) $(ANIMATION) $(WORLD) $(PLAY) $(END)
	gcc $(CFLAGS) $(FRAMEWORK) -lmlx -framework OpenGL -framework AppKit $(MAP) $(UTILS) $(PROG) $(SRC) $(ANIMATION) $(WORLD) $(PLAY) $(END) -o $(GAME)

bonus : $(GAME)

clean :

fclean : clean
	rm -f $(GAME)

re : fclean all

.PHONY: all game clean fclean re