/*
** label.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar 25 15:40:18 2016 antoine
** Last update Fri Mar 25 15:40:18 2016 antoine
*/

#include <stdlib.h>
#include <assert.h>
#include "../libcw/print.h"
#include "../libcw/string.h"
#include "asm.h"

void                    label_init(t_label *label, t_token *label_token)
{
  assert(label_token->type == TOKEN_TYPE_LABEL_DEF);
  label->name = string_duplicate(label_token->string_value);
  label->instr = NULL;
}

void                    label_free(t_label *label)
{
  free(label->name);
}

void                    label_print(const t_label *label)
{
  print_string("name: ");
  print_string(label->name);
  print_string("\n");
}