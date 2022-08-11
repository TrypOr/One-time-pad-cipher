#include<stdio.h>
#include <assert.h>
#include <fcntl.h>
#include<string.h>
#include <unistd.h>

/*One pad encryption function*/
char* one_time_pad_encr(char* plaintext,unsigned char* randomkey);
/*One pad decryption function*/
char* one_time_pad_decr(char* ciphertext,unsigned char* randomkey);

char *one_time_pad_encr(char* plaintext,unsigned char* randomkey){
  size_t i = 0U;
  /*Assert size*/
  assert(plaintext != NULL);
  assert(randomkey != NULL);
  /*Check wheter the random key is shorter than plaintext*/
  if(strlen((char*)randomkey)<strlen(plaintext)){
      return "Key smaller than plaintext";
  }
  while (plaintext[i] != '\0') { /*Loop while s2 has not reached its end*/
    plaintext[i] ^= randomkey[i];          /*copying the string*/
   i++;
  }
  return plaintext;
}
char *one_time_pad_decr(char* ciphertext,unsigned char* randomkey){
  size_t i = 0U;
  /*Assert size*/
  assert(ciphertext != NULL);
  assert(randomkey != NULL);
  /*Check wheter the random key is shorter than plaintext*/
  if(strlen((char*)randomkey)<strlen(ciphertext)){
      return "Key smaller than ciphertext";
  }
  while (ciphertext[i] != '\0') { /*Loop while s2 has not reached its end*/
    ciphertext[i] ^= randomkey[i];          /*copying the string*/
   i++;
  }
  return ciphertext;
}
/*Main to test one time pad*/
 int main(void){
    int i; 
    unsigned char randomkey[30];
    char test1[13]="Hello world!";
    char test2[30]="Everything works fine!";
    char test3[50]="fgwrdfhwegerwgfrwehgwterhwtergwergferwferw";
    int fd = open("/dev/urandom", O_RDONLY);
        read(fd, randomkey, 30);
        /*randomkey now contains the random data*/
        close(fd);
        printf("Randomly generated key is:");
        for(i = 0; i < 30; ++i){
                printf("%02X", randomkey[i]);
        }
        printf("\n");
        /*ONE TIME PAD TEST 1*/
        printf("ONE TIME PAD TEST 1 :\n");
        printf("Encrypted key from one time pad is %s\n",one_time_pad_encr(test1,randomkey));
        printf("Decrypted key from one time pad is %s\n",one_time_pad_decr(test1,randomkey));
         /*ONE TIME PAD TEST 2*/
        printf("ONE TIME PAD TEST  2 :\n");
        printf("Encrypted key from one time pad is %s\n",one_time_pad_encr(test2,randomkey));
        printf("Decrypted key from one time pad is %s\n",one_time_pad_decr(test2,randomkey));
        /*ONE TIME PAD TEST 3*/
        printf("ONE TIME PAD TEST  3 :\n");
        printf("Encrypted key from one time pad is %s\n",one_time_pad_encr(test3,randomkey));
        printf("Decrypted key from one time pad is %s\n",one_time_pad_decr(test3,randomkey));
        return 0;
    }