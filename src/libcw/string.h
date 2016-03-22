/*
** string.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Feb 26 17:52:52 2016 antoine
** Last update Mon Feb 29 15:04:46 2016 Valentin Pichard
*/

#ifndef STRING_H
# define STRING_H

/*
** Sets the `n` firsts chars of the given string to the character `c`.
*/
void            string_set_n_chars(char *string, char c, int n);

/*
** Like strlen().
*/
int             string_get_length(const char *string);

/*
** Like strcat().
*/
void            string_concat(char *dest, const char *source);

/*
** Like strncat().
*/
void		string_concat_n(char *dest, const char *source, int n);

/*
** Like string_concat(), but appends a character.
*/
void            string_concat_char(char *dest, char source);

char            *string_copy(char *dest, const char *source);
char            *string_copy_n(char *dest, const char *source, int n);

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
** Returns 1 if the two strings contains the same characters.
*/
int             string_equals(const char *a, const char *b);
int             string_equals_no_case(const char *a, const char *b);

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

/*
** Check if string starts with begin
*/
int             string_starts_with(const char *string, const char *begin);

/*
** Like string_starts_with(), but case insensitive
*/
int             string_starts_with_no_case(const char *string,
                                           const char *begin);

/*
** Check if string ends with end
*/
int		string_ends_with(const char *string,
				 const char *end);

/*
** Like string_ends_with(), but case insensitive
*/
int		string_ends_with_no_case(const char *string,
                                         const char *end);

#endif /* STRING_H */
