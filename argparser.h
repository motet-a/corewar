/*
** argparser.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Feb 22 21:23:47 2016 antoine
** Last update Mon Feb 22 21:23:47 2016 antoine
*/

#ifndef ARGPARSER_H
# define ARGPARSER_H

typedef enum                    e_argparser_action
{
  ARGPARSER_ACTION_STORE,
  ARGPARSER_ACTION_STORE_CONST,
  ARGPARSER_ACTION_STORE_TRUE,
  ARGPARSER_ACTION_STORE_FALSE,
}                               t_argparser_action;

/*
** An argument parser.
*/
typedef struct s_argparser      t_argparser;

typedef struct                  s_argument
{
  const char                    *name;
  const char                    *value;
}                               t_argument;

typedef struct                  s_argument_list
{
  t_argument                    argument;
  struct s_argument_list        *next;
}                               t_argument_list;

/*
** error_message is NULL in case of success.
*/
typedef struct                  s_argparser_result
{
  t_argument_list               *arguments;
  char                          *error_message;
}                               t_argparser_result;

/*
** Creates a new argparser.
** The returned t_argparser must be deleted with argparser_delete().
** Returns NULL on error
** description: The description of the program
*/
t_argparser             *argparser_new(const char *description);

void                    argparser_delete(t_argparser *self);

/*
** Adds an argument to the parser.
**
** action: An ARGPARSER_ACTION_*.
** const_string: The stored string if the action is
** ARGPARSER_ACTION_STORE_CONST. This argument is ignored if
** the action is not ARGPARSER_ACTION_STORE_CONST.
**
** Return 0 on success, -1 on error.
*/
int                     argparser_add_argument(t_argparser *self,
                                               t_argparser_action action,
                                               const char *const_string,
                                               const char *help);

/*
** Parse the given command-line arguments.
**
** argparser_result_free() must be called on the returned
** t_argparser_result.
*/
t_argparser_result      argparser_parse(const t_argparser *self,
                                        int argc,
                                        char **argv);

void                    argparser_result_free(t_argparser_result *result);

void                    argparser_print_usage(const t_argparser *self,
                                              int output_file);

#endif /* ARGPARSER_H */
