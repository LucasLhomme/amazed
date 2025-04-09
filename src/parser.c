/*
** EPITECH PROJECT, 2025
** amazed
** File description:
** parser
*/

#include "my.h"
#include "lib.h"

int nb_robots(char *input, maze_t *maze)
{
    static int first_line = 1;
    char **list = my_str_to_word_array(input);

    if (!first_line)
    return 0;
    first_line = 0;
    if (!list || !list[0] || !my_getnbr(list[0]) || my_getnbr(list[0]) < 0)
    return 84;
    maze->nb_robots = my_getnbr(list[0]);
    my_printf("%i\n", maze->nb_robots);
    return 1;
}

maze_t *fill_room(maze_t *maze, char **list)
{
    room_t *new_node = malloc(sizeof(room_t));

    if (!new_node)
        return maze;
    new_node->name = list[0];
    new_node->x = list[1];
    new_node->y = list[2];
    new_node->next = NULL;
    while (maze->rooms != NULL)
        maze->rooms = maze->rooms->next;
    maze->rooms = new_node;
    return maze;
}

int is_room(char *input, maze_t *maze)
{
    static int printed = 0;
    char **list = my_str_to_word_array(input);
    int count = my_word_array_len(list);

    if (!input)
    return 84;
    if (my_strncmp(input, "##start", 7) == 0 ||
    my_strncmp(input, "##end", 5) == 0) {
        my_printf("%s", input);
        return 1;
    }
    if (count != 3)
    return (count > 0) ? 0 : 84;
    if (!printed) {
        my_printf("#rooms\n");
        printed = 1;
    }
    my_printf("%s", input);
    maze = fill_room(maze, list);
    return 1;
}

int is_tunnel(char *input, maze_t *maze)
{
    static int count = 0;

    if (!input)
    return 84;
    if (input[0] == '#' || my_strncmp(input, "##", 2) == 0)
    return 0;
    for (int i = 0; input[i]; i++) {
        if (input[i] == '-')
        count++;
    }
    if (count == 1)
    my_printf("#tunnels\n");
    return (count >= 1) ? 1 : 0;
}

int parser(char *input, maze_t *maze)
{
    int robots = nb_robots(input, maze);
    int tunnel = is_tunnel(input, maze);
    int room = is_room(input, maze);

    if (!input)
        return 84;
    if (robots == 1) {
        return 0;
    }
    if (tunnel == 1) {
        my_printf("%s", input);
        return 0;
    }
    if (room == 1)
        return 0;
    return 0;
}
