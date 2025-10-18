#ifndef TOKEN_H
#define TOKEN_H
typedef enum {
  NUMBER,
  VARIABLE,
  OPERATOR,
  L_PAREN,
  R_PAREN,
  FUNCTION,
  UNARY_MINUS
} TokenType;

typedef struct Token {
  TokenType type;

  union {
    double value;
    char op;
    char func_name[8];
  } data;

} Token;

#endif // TOKEN_H
