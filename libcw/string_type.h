/*
** string_type.h for  in /Users/westery/Documents/tek1/CPE/corewar/src/libcw/
**
** Made by Valentin Pichard
** Login   <pichar_v@epitech.net>
**
** Started on  Wed Mar  9 00:51:42 2016 Valentin Pichard
** Last update Wed Mar  9 01:35:39 2016 Valentin Pichard
*/

#ifndef STRING_TYPE_H
# define STRING_TYPE_H

int     string_is_digit(const char *str);
int     string_is_uppercase(const char *str);
int     string_is_lowercase(const char *str);
int     string_is_letter(const char *str);
int     string_is_alphanumeric(const char *str);
char    *string_to_lowercase(const char *str);
char    *string_to_uppercase(const char *str);

#endif /* STRING_TYPE_H */
