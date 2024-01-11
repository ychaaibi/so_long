/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychaaibi <ychaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:12:56 by ychaaibi          #+#    #+#             */
/*   Updated: 2022/02/06 15:47:07 by ychaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_anime
{
	struct s_anime	*next;
	void			*img;
}				t_anime;

typedef struct s_player
{
	int			x;
	int			y;
	int			moves;
	int			count;
	int			dir;
	t_anime		*left_anime;
	t_anime		*right_anime;
	t_anime		*current_anime;

}			t_player;

typedef struct s_enemy
{
	int				x;
	int				y;
	int				dir;
	int				width;
	int				height;
	int				exist;
	int				count;
	int				count_move;
	int				curr_anime_ind;
	t_anime			*current_anime;
	t_anime			*left_anime;
	t_anime			*right_anime;
}				t_enemy;

typedef struct s_collectibe_position
{
	int	x;
	int	y;
	int	still;
}				t_collectibe_position;

typedef struct s_collectibe
{
	int			x;
	int			y;
	int			count;
	t_anime		*current_anime;
	t_anime		*anime;
}				t_collectibe;

typedef struct s_game
{
	void					*mlx;
	void					*window;
	void					*ground_img;
	void					*collectibe_img;
	void					*exit_img;
	void					*exit_open_img;
	int						w;
	int						width;
	int						h;
	int						height;
	int						collectibe_count;
	int						end;
	int						end_count;
	char					**map;
	t_player				*player;
	t_enemy					*enemy;
}				t_game;

typedef struct s_end
{
	int	x;
	int	y;
	int	fin[3];
	int	start_x;
	int	start_y;
}			t_end;

//_______________________Utils_______________________//

int			ft_strlen(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dest, char const *src, size_t size);
char		*ft_itoa(int n);
void		*ft_calloc(size_t count, size_t size);
int			ft_strcmp(char *s1, char *s2);

//_______________________Map________________________//

void		check_ext(char *map_path);
void		check_new_line(char *full_map, char **line_map);
void		init_zeros(int *arr, int size);
void		check_map(char *line, int *cep, int index, int *dim);
void		valid_map(char **map);
char		**read_map(int fd);
char		**parse_map(char *map_path, int *length);

//_______________________Init________________________//

void		moves_count(t_game *game);
void		error(void);
t_game		*init_game(int height, int width, char **map);
t_player	*init_player(void);
t_enemy		*init_enemy(void);
t_anime		*init_anime(void *img);

void		*init_player_img(t_game *game, char	*path);
void		set_player(t_game *game, int new_x, int new_y);
void		set_map(t_game *game);
void		set_wall(t_game *game, char **map, int x, int y);
void		set_coll(t_game *game, int x, int y);

//_______________________Anime________________________//

char		*get_path_anime(char	*path, int index);
t_anime		*init_anime(void *img);
void		append_anime(t_anime **head, t_anime *anime);

//Enemy

void		enemy_anime(t_game *game);
void		anime_enemy(t_game *game);

//Player

void		anime_player(t_game *game);
void		player_anime(t_game *game);

int			key_hook(int keycode, t_game *game);
int			anime(t_game *game);

void		player_move(int keycode, t_game *game);
void		enemy_move(t_game *game);

//______________________Move________________________//

void		player_move_up(t_game *game);
void		player_move_down(t_game *game);
void		player_move_right(t_game *game);
void		player_move_left(t_game *game);

//______________________set_________________________//

void		set_wall(t_game *game, char	**map, int x, int y);
void		set_ground(t_game *game, int x, int y);
void		set_exit(t_game *game, int x, int y);

void		*get_image(char *path, t_game *game);
void		collision(t_game *game);
void		end_game(t_game *game);
int			over(t_game *game);

#endif