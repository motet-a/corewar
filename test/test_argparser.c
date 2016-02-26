/*
** test_argparser.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Feb 26 10:33:22 2016 antoine
** Last update Fri Feb 26 10:33:22 2016 antoine
*/

#include <stdlib.h>
#include "../libcw/argparser.h"

static t_argparser      *create_parser(void)
{
  t_argparser           *parser;
  t_argparser_arg_descr message;

  message.name = "-help";
  message.variable_name = NULL;
  message.action = ARGPARSER_ACTION_STORE_TRUE;
  message.help = "Prints this help and exit";
  parser = argparser_new("Say hello");
  argparser_add_arg(parser, &message);
  return (parser);
}

void                    test_suite_argparser(void)
{
  t_argparser           *parser;
  char                  *argv[9];

  argv[0] = "hello";
  argv[1] = "-help";
  argv[2] = NULL;
  parser = create_parser();
  argparser_parse(parser, 2, argv);
  argparser_delete(parser);
}
