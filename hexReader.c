#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

      FILE *file;
      unsigned char *palloc;
      char input[50];
      unsigned long int num_bytes = 0, i = 0;
      int chr, j = 0;

      printf("Enter file path: ");
      scanf("%s", &input);

      file = fopen(input, "r");

      if(file == NULL){
            printf("Failed open file");
            return -1;
      }

      while((chr = fgetc(file))!=EOF)
            num_bytes++;

      printf("\nFile size %lu bytes\n\n", num_bytes);

      rewind(file);

      palloc = (unsigned char *) malloc(num_bytes);
      
      if(palloc == NULL){
            printf("Memory full");
            return -1;
      }

      while((chr = fgetc(file))!=EOF){
            if(i<=num_bytes) palloc[i] = (unsigned char) chr;
            i++;
      }

      for(i=0;i<num_bytes;i++){
            if(j < 9){
                  printf("%2hx ",palloc[i]);
                  j++;
            } else {
                  printf("\n");
                  j = 0;
            }
      }

      free(palloc);

      fclose(file);

      return 0;
}