#ifndef INPUT_H
#define INPUT_H
#define BASE_BUFFER_LENGTH 128
int handle_input_chunk(char *buffer, unsigned int *length,
                       unsigned int capacity);
char *read_line();
char *resize_buffer(char *buffer, unsigned int *capacity, int *success);

#endif // INPUT_H
