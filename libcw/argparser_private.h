/*
** argparser_private.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Feb 22 22:48:56 2016 antoine
** Last update Wed Feb 24 17:24:16 2016 Antoine Baudrand
*/

#ifndef ARGPARSER_PRIVATE_H
# define ARGPARSER_PRIVATE_H

# include "argparser.h"

/*
** Don't include this file outside of the argparser
** implementation. This is private.
**
**
** There is no C++ namespaces in C, but we can "import"
** stuff with typedefs:
*/
typedef t_argparser_arg_descr   t_arg_descr;
typedef t_argparser_result      t_result;
typedef t_argparser_arg         t_arg;
typedef t_argparser_arg_list    t_arg_list;

t_arg_list      *argparser_arg_list_new(const t_arg *arg,
                                        t_arg_list *next);
void            argparser_arg_list_delete(t_arg_list *list);

void            argparser_arg_list_add(t_arg_list **list,
                                       const t_arg *arg);

typedef struct                  s_arg_descr_list
{
  t_arg_descr                   arg_descr;
  struct s_arg_descr_list       *next;
}                               t_arg_descr_list;

t_arg_descr_list        *argparser_descr_list_new(const t_arg_descr *descr,
                                                  t_arg_descr_list *next);
void                    argparser_descr_list_delete(t_arg_descr_list *list);

void                    argparser_descr_list_add(t_arg_descr_list **list,
                                                 const t_arg_descr *descr);

struct                          s_argparser {
  t_arg_descr_list              *args;
  const char                    *description;
};

#endif /* ARGPARSER_PRIVATE_H */
