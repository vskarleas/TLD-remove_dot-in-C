#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void read_and_replace(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (!fp) {
    printf("Error opening file: %s\n", filename);
    exit(1);
  }

  char line[1024];
  while (fgets(line, sizeof(line), fp)) {
    char *p = strstr(line, ".net");
    if (p) {
      // Replace ".net" with "net"
      *p = '\0';
    }

    // Write the modified line to the output file
    printf("%s", line);
  }

  fclose(fp);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    exit(1);
  }

  read_and_replace(argv[1]);

  return 0;
}

