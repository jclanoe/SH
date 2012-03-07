/**
** @file		parse_ope_high_expr.c
** @brief		- ope_high  ::=  paren ([OPE_HIGH] paren)*
** @author		maarek_j
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "eval_expr.h"
#include "lexer/lexer.h"

s_tree_expr		*parse_ope_high_expr(s_eelex		*lex)
{
  s_token		*tok = NULL;
  s_tree_expr		*sl = NULL;
  s_tree_expr		*sr = NULL;

  if (NULL == (sl = parse_ope_power_expr(lex)))
    return (NULL);

  while ((NULL != (tok = eelex_get_token(lex))) &&
	 (tok->type == TK_OPE_HIGH))
  {
      eelex_eat_token(lex);
      if (NULL == (sr = parse_ope_power_expr(lex)))
	return (NULL);

      sl = (build_tree_expr(EXPR_TYPE_BIN, mstring_copy(tok->str), sl, sr));
  }

  return (sl);
}
