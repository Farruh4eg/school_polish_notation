#ifndef PARSER_H
#define PARSER_H

#include "../token/token.h"

Token *parse_to_rpn(Token *infix_tokens, int infix_count, int *rpn_count);
void print_rpn(Token *rpn_tokens, int rpn_count);

#endif // PARSER_H
