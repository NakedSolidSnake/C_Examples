 #include <arpa/inet.h>
 #include <stdio.h>

 int main(int argc, char const *argv[])
 {
     short value = 57;

     short go = htons(value);
     printf("htons: %d %X\n", go, go);
     short back = ntohs(go);
     printf("ntohs: %d %X\n", back, back);
     
     return 0;
 }
 