/*
** EPITECH PROJECT, 2025
** B-CPE-200-LIL-2-1-amazed-fabien.skotarek
** File description:
** amazed
*/
#include <stdio.h>
#include <unistd.h>
#include "lib.h"

int amazed(int argc, char **argv)
{
    char *input = NULL;
    size_t buffer_size = 0;

    (void)argc;
    (void)argv;
    my_printf("#number_of_robots\n");
    while ((getline(&input, &buffer_size, stdin)) != -1) {
        if (my_strstr(input, "##"))
            my_printf("#\n%s", input);
        else
            my_printf("%s", input);
    }
    free(input);
    return (0);
}

/*
    while ((characters = getline(&input, &buffer_size, stdin)) != -1) {
        if (strstr(input, "##")) {
            char *modified_input = malloc(strlen(input) + 2);
            if (!modified_input) {
                perror("malloc");
                free(input);
                exit(EXIT_FAILURE);
            }
            sprintf(modified_input, "#%s", input);
            printf("%s", modified_input);
            free(modified_input);
        } else {
            printf("%s", input);
        }
    }
*/
