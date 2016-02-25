/*
** str.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Feb 22 22:59:36 2016 antoine
** Last update Thu Feb 25 21:26:15 2016 Antoine Baudrand
*/

#ifndef STR_H
# define STR_H

/*
** Like strlen().
*/
int             string_get_length(const char *string);

/*
** Like strcat().
*/
void            string_concat(char *dest, const char *source);

/*
** Like string_concat(), but appends a character.
*/
void            string_concat_char(char *dest, char source);

void            string_copy(char *dest, const char *source);
void            string_copy_n(char *dest, const char *source, int n);

/*
** Like strdup().
** Can return NULL.
*/
char            *string_duplicate(const char *source);

/*
** Like strndup().
** Can return NULL.
*/
char            *string_duplicate_n(const char *source, int n);

/*
** Like strchr().
**
** Returns an pointer to the first occurrence of the character c
** in the string. Returns NULL if the given string doesn't contain c.
*/
const char      *string_find_char(const char *string, char c);

/*
** Like string_find_char(), but case insensitive.
*/
const char      *string_find_char_no_case(const char *string, char c);

/*
** Like strstr().
*/
const char      *string_find(const char *string, const char *needle);

/*
** Like string_find(), but case insensitive.
*/
const char      *string_find_no_case(const char *string, const char *needle);

#endif /* STR_H */
