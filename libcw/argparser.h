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
  ARGPARSER_ACTION_STORE_TRUE,
  ARGPARSER_ACTION_STORE_FALSE,
}                               t_argparser_action;

typedef struct s_argparser_group t_argparser_group;

/*
** An argument parser.
*/
typedef struct s_argparser      t_argparser;

typedef struct                  s_argument_descr
{
  const char                    *name;
  const char                    *variable_name;
  t_argparser_action            action;
  const char                    *help;
}                               t_argument_descr;

typedef struct                  s_argparser_arg_list t_argparser_arg_list;

/*
** If name is NULL, this structure represents an argument group.
** If name is not NULL, this structure represents an argument.
*/
typedef struct                  s_argparser_arg
{
  t_argparser_arg_list          *group;
  const char                    *name;
  const char                    *value;
}                               t_argparser_arg;

struct                          s_argparser_arg_list
{
  t_argparser_arg               argument;
  struct s_argparser_arg_list   *next;
};

/*
** error_message is NULL in case of success.
*/
typedef struct                  s_argparser_result
{
  t_argparser_arg_list          *arguments;
  char                          *error_message;
}                               t_argparser_result;

/*
** Creates a new argparser.
** The returned t_argparser must be deleted with argparser_delete().
** Returns NULL on error
** description: The description of the program
*/
t_argparser     *argparser_new(const char *description);

void            argparser_delete(t_argparser *self);

/*
** Adds an argument to the parser.
**
** action: An ARGPARSER_ACTION_*.
** Return 0 on success, -1 on error.
*/
int             argparser_add_argument(t_argparser *self,
                                       const t_argument_descr *arg_descr);

t_argparser_group       *argparser_group_new(int repeat);
void                    argparser_group_delete(t_argparser_group *group);

int             argparser_group_add_argument(t_argparser_group *self,
                                             const t_argument_descr *arg);

int             argparser_add_group(t_argparser *self,
                                    t_argparser_group *group);

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

/*
** output_file: An Unix file descriptor.
*/
void                    argparser_print_usage(const t_argparser *self,
                                              int output_file);

#endif /* ARGPARSER_H */
