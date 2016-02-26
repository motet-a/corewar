/*
** argparser.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Feb 22 22:51:31 2016 antoine
** Last update Mon Feb 22 22:51:31 2016 antoine
*/

#include <stdlib.h>
#include "argparser_private.h"
#include "str.h"

t_descr_list    *argparser_descr_list_new(const t_descr *descr,
                                          t_descr_list *next)
{
  t_descr_list  *list;

  list = malloc(sizeof(t_descr_list));
  list->arg_descr = *descr;
  list->next = next;
  return (list);
}

void            argparser_descr_list_delete(t_descr_list *list)
{
  if (!list)
    return ;
  argparser_descr_list_delete(list->next);
  free(list);
}

void            argparser_descr_list_add(t_descr_list **list,
                                         const t_descr *arg_descr)
{
  *list = argparser_descr_list_new(arg_descr, *list);
}

t_argparser     *argparser_new(const char *description)
{
  t_argparser   *self;

  self = malloc(sizeof(t_argparser));
  if (!self)
    return (NULL);
  self->args = NULL;
  self->description = description;
  return (self);
}

void            argparser_delete(t_argparser *self)
{
  argparser_descr_list_delete(self->args);
  free(self);
}

int             argparser_add_arg(t_argparser *self,
                                  const t_descr *descr)
{
  argparser_descr_list_add(&self->args, descr);
  return (0);
}

static t_result create_error(const char *message)
{
  t_result      result;

  result.error_message = string_duplicate(message);
  result.args = NULL;
  return (result);
}

static t_result create_result(t_arg_list *args)
{
  t_result      result;

  result.error_message = NULL;
  result.args = args;
  return (result);
}

const t_descr   *argparser_find_descr(const t_descr_list *list,
                                      const char *string)
{
  if (!list)
    return (NULL);
  if (string_equals(string, list->arg_descr.name))
    return (&list->arg_descr);
  return (argparser_find_descr(list->next, string));
}

static char     *create_expected_value_message(const char *arg_name)
{
  return (string_duplicate("Expected value after argument"));
}

char            *argparser_parse_arg(const t_argparser *self,
                                     const char *arg_string,
                                     const char *next_arg_string,
                                     t_arg *arg)
{
  const t_descr *descr;

  descr = argparser_find_descr(self->args, arg_string);
  if (!descr)
    {
      if (*arg_string == '-')
        return (string_duplicate("Unknown argument"));
      arg->name = NULL;
      arg->value = arg_string;
      return (NULL);
    }
  arg->name = descr->name;
  if (descr->action == ARGPARSER_ACTION_STORE)
    {
      if (!next_arg_string)
        return (create_expected_value_message(arg_string));
      arg->value = next_arg_string;
    }
  else
    arg->value = NULL;
  return (NULL);
}

t_result        argparser_parse(const t_argparser *self,
                                int argc,
                                char **argv)
{
  t_arg_list    *list;
  t_arg         arg;
  char          *error_message;
  const char    *next_arg_string;

  list = NULL;
  if (argc == 0)
    return create_error("argc is zero");
  while (argc) {
    next_arg_string = argc > 1 ? argv[1] : NULL;
    error_message = argparser_parse_arg(self, *argv, next_arg_string, &arg);
    if (error_message)
      {
        argparser_arg_list_delete(list);
      }
    argv++;
    argc--;
  }
  return (create_result(list));
}
