/*
** instr_list.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Mar 25 09:46:07 2016 antoine
** Last update Fri Mar 25 09:46:07 2016 antoine
*/

#include "asm.h"

t_instr_list            *instr_list_new(const t_instr *instr,
                                        t_instr_list *next);
void                    instr_list_add(t_instr_list **list_pointer,
                                       const t_instr *instr);
void                    instr_list_delete(t_instr_list *list);
