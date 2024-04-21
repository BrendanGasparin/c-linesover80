/*
    linesover80.c
    Author: Brendan Gasparin <Brendan.Gasparin@gmail.com>
    Date: 21 April 2014
    Reads from the standard input and prints the line numbers, character
    length, and text of all lines with more than 80 characters.
*/

#include <stdio.h>

#define MAXLINE 1002                // maximum input line size
#define EIGHTY  80                  // 80 characters

void copy(char to[], char from[]);
int get_line(char str[], int limit);

int main()
{
    int length;                     // current line length
    unsigned long line_number = 0;  // current line_number
    char line[MAXLINE];             // current input line

    while ((length = get_line(line, MAXLINE)) > 0) {
        line_number++;
        if (length - 1 > EIGHTY)
            printf("%ld:%d:%s", line_number, length - 1, line);
    }

    return 0;
}

/*
    copy()
    Copies a char array string to another char array string.
    @param: char to[]: The destination array.
    @param: char from[]: The source array.
*/
void copy(char to[], char from[])
{
    int i = 0;
    while((to[i] = from[i] != '0'))
        i++;
}

/*
    getline()
    Gets a line from the standard input and copies it to a char array string,
    returning the length of the string.
    @param: char line[]: The line of text to be read from the input.
    @param: int limit: The limit of the input buffer.
    @return: int: The length of the input character array.
*/
int get_line(char str[], int limit)
{
    int c, i;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c!='\n'; i++)
        str[i] = c;
    if (c == '\n') {
        str[i] = c;
        i++;
    }
    str[i] = '\0';

    return i;
}
