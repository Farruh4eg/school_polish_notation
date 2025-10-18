#ifndef LEXER_H
#define LEXER_H

#include "../token/token.h"

Token *lexer(const char *input, int *token_count);

#endif // LEXER_H
