/*
** char_type.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Feb 25 20:44:01 2016 antoine
** Last update Thu Feb 25 20:44:01 2016 antoine
*/

#ifndef CHAR_TYPE_H
# define CHAR_TYPE_H

/*
** Return true if char c is a digit
*/
int     char_is_digit(char c);

/*
** Return true if char c is uppercase
*/
int     char_is_uppercase(char c);

/*
** Return true if char c is lowercase 
*/
int     char_is_lowercase(char c);

/*
** Return true if char c is a letter 
*/
int     char_is_letter(char c);


/*
** Return true if char c is a letter or a digit
*/
int     char_is_alphanumeric(char c);

/*
** Return lowercase of c
*/
char    char_to_lowercase(char c);


/*
** Return uppercase of c
*/
char    char_to_uppercase(char c);

#endif /* CHAR_TYPE_H */
