/*
** EPITECH PROJECT, 2025
** amazed
** File description:
** my_word_array_len
*/

int my_word_array_len(char **array)
{
    int i = 0;

    while (array && array[i])
        i++;
    return i;
}
