#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>

int main(){

  int Socket1,Socket2;
  char text[1024],a[50];
  struct sockaddr_in serverAddr;
  struct sockaddr_storage serverStorage;
  socklen_t addr_size;
  
  Socket1 = socket(PF_INET, SOCK_STREAM, 0);

  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(5471);
  serverAddr.sin_addr.s_addr = inet_addr("192.168.1.47");

  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

  bind(Socket1, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

  if(listen(Socket1,5)==0)

    printf("Listening....\n");

  else

    printf("Error...Please try again!!\n");

  addr_size = sizeof serverStorage;

  Socket2 = accept(Socket1, (struct sockaddr *) &serverStorage, 
&addr_size);

  puts("Connected");

  recv(Socket2, text , 50 , 0);
  char s[]="Assalamualaikum";
  a[50];
  strcpy(a,text);

  if(strcasecmp(a , s)==0)
  {

	strcpy(text, "waalaikumussalam\n");
  }
  else
  {
	strcpy(text,"Are you muslim?\n");
  }
  send(Socket2,text,50, 0);
  return 0;
  }

