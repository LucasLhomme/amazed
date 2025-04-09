/*
** EPITECH PROJECT, 2025
** amazed
** File description:
** my
*/

typedef struct room_s {
    char *name;
    char *x;
    char *y;
    struct room_s *next;
} room_t;

typedef struct tunnel_s {
    int nb_robots;
} tunnel_t;

typedef struct maze_s {
    int nb_robots;
    room_t *rooms;
    tunnel_t *tunnels;
    char *start_room;
    char *end_room;
} maze_t;

#ifndef MY_H_
    #define MY_H_
void amazed(void);
int is_tunnel(char *input, maze_t *maze);
int parser(char *input, maze_t *maze);

#endif /* MY_H_ */
