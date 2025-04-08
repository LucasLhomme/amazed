/*
** EPITECH PROJECT, 2025
** B-CPE-200-LIL-2-1-amazed-fabien.skotarek
** File description:
** amazed
*/
#include <stdio.h>
#include <unistd.h>
#include "lib.h"
#include "my.h"

int amazed(int argc, char **argv)
{
    char *input = NULL;
    size_t buffer_size = 0;
    maze_t *maze = malloc(sizeof(maze_t));

    my_printf("#number_of_robots\n");
    while ((getline(&input, &buffer_size, stdin)) != -1) {
        parser(input, maze);
    }
    free(input);
}
