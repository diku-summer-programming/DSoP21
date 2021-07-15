#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main (int argc, char* argv[]) {
  if (argc == 2 && strcmp(argv[1], "-h") == 0) {
	printf("Small calculator which supports operations + and -.\n");
	printf("Write an expression such as 2+2 and the result will be printed for you!\n");
	return 0;
  }

  char* line = NULL;
  size_t bufsize;
  size_t chars_read;

  if ((chars_read = getline(&line, &bufsize, stdin)) == -1) {
	return 1;
  }

  char next_op = ' ';
  int result = 0;
  int number = 0;
  for (int i = 0; i < chars_read; i++){
	if (line[i] >= '0' && line[i] <= '9') {
	  number *= 10;
	  number += line[i] - '0';

	} else if (line[i] == '+' || line[i] == '-') {
	  if (next_op == '+') {
		result += number;
	  } else if (next_op == '-') {
		result -= number;
	  } else {
		result = number;
	  }
	  next_op = line[i];
	  number = 0;

	} else if (line[i] == ' ') {
	  continue;

	} else if (line[i] == '\n') {
	  if (next_op == '+') {
		result += number;
	  } else if (next_op == '-') {
		result += number;
	  } else {
		result = number;
	  }
	  break;

	} else {
	  return 1;
	}
  }
  printf("Result: %d\n", result);
  free(line);
  return 0;
}
