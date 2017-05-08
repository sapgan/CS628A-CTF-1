#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int main(int argc,char* argv[]){
  int course=628;
  int mul=4;
  int offset=431653871;
  int origpasscode=offset+course*-course*course*mul;
  int fd,len,bytes;
  char buf[32];
  if(fd=open("password",O_RDONLY,0400)<0){
    printf("can't open password\n");
    return 0;
  }
  printf("How many bytes you want to read from file\n" );
  scanf("%d",&bytes);
  printf("Reading %d bytes\n",bytes );
  printf("You will be banned if you bruteforce...\n");
  sleep(time(0)%50);

  if(!(len=read(fd,buf,bytes) > 0)){
    printf("Error in reading\n");
    close(fd);
    return 0;
  }
  unsigned int passcode_from_file=atoi(buf)^0xABBEBABE;
  if(origpasscode==passcode_from_file){
    printf("OK Here's the flag\n");
    system("/bin/cat flag.txt\n");
  }
  else{
    printf("Sorry Password in file is wrong\n");
  }
  return 0;
}
