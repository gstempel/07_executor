#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>


int main(int argc, char * argv[]){
  //take input
  char line[100];
  printf("Put in input: ");
  fgets(line, sizeof(line), stdin);
  //printf("This is what was inputed: %s", line);

  //remove newline
  char * a = line;
  a[strlen(a) - 1] = 0;

  //parse
  char * command[100];
  int i = 0;
  while(a) {
    command[i] = strsep(&a, " ");
    i++;
  }
  command [i] = 0;//null terminate

  //run command
  execvp(command[0], command);
  printf("\nNOT WORKING\n");
  return 0;
}
