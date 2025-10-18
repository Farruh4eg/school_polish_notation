#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int handle_input_chunk(char *buffer, unsigned int *length,
                       unsigned int capacity) {
  // 1 -> done
  // 0 -> continue
  // -1 -> error
  int status = 0;

  if (fgets(buffer + *length, capacity - *length, stdin) == NULL) {
    if (*length == 0) {
      status = -1;
    } else {
      status = 1;
    }
  } else {
    unsigned int last_read_len = strlen(buffer + *length);
    *length += last_read_len;

    if (*length > 0 && buffer[*length - 1] == '\n') {
      buffer[*length - 1] = '\0';
      status = 1;
    } else if (feof(stdin)) {
      status = 1;
    }
  }

  return status;
}

char *resize_buffer(char *buffer, unsigned int *capacity, int *success) {
  unsigned int new_capacity = *capacity * 2;
  char *new_buffer = realloc(buffer, new_capacity);

  if (new_buffer == NULL) {
    *success = 0;
  } else {
    *capacity = new_capacity;
  }

  return new_buffer;
}

char *read_line() {
  unsigned int length = 0;
  unsigned int capacity = BASE_BUFFER_LENGTH;
  char *buffer = NULL;
  int success = 1;
  int done = 0;

  buffer = malloc(capacity * sizeof(char));
  if (buffer == NULL) {
    success = 0;
  }

  while (success && !done) {
    int chunk_result = handle_input_chunk(buffer, &length, capacity);

    if (chunk_result == 1) {
      done = 1;
    } else if (chunk_result == -1) {
      success = 0;
    } else {
      buffer = resize_buffer(buffer, &capacity, &success);
    }
  }

  if (!success) {
    free(buffer);
    buffer = NULL;
  }

  return buffer;
}
