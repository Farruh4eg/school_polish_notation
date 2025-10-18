#include "input/input.h"
#include "lexer/lexer.h"
#include "parser/parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *input = read_line();
  if (input != NULL) {
    printf("GOT %s. LENGTH = %lu", input, strlen(input));
  }

  return 0;
}
