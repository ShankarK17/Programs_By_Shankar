#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
void *write_thread_fun(void *args)
{
   char *file_path = (char *)args;
   int fd;
   char wbuffer[80]; 
   fd = open(file_path, O_WRONLY);
       if (fd == -1)
       {
           printf("Error while opening file for writing\n");
           pthread_exit(NULL);
       }
   while (1)
   {
       printf("You: ");
       fgets(wbuffer, 80, stdin);
       if (write(fd, wbuffer, strlen(wbuffer) + 1) == -1)
       {
           printf("Error while writing to file\n");
           close(fd);
           pthread_exit(NULL);
       }
   }
   if (close(fd) == -1)
       {
           printf("Error while closing the file after writing\n");
           pthread_exit(NULL);
       }
   return NULL;
}
void *read_thread_fun(void *args)
{
   char *file_path = (char *)args;
   int fd;
   char rbuffer[80]; 
   fd = open(file_path, O_RDONLY);
       if (fd == -1)
       {
           printf("Error while opening file for reading\n");
           pthread_exit(NULL);
       }
   while (1)
   {
       int byteread = read(fd, rbuffer, sizeof(rbuffer) - 1);
       if (byteread <= 0)
       {
           printf("Error while reading from file\n");
           close(fd);
           pthread_exit(NULL);
       }
       rbuffer[byteread] = '\0';
       printf("User1: %s", rbuffer);
   }
   if (close(fd) == -1)
       {
           printf("Error while closing file after reading\n");
           pthread_exit(NULL);
       }
   return NULL;
}
int main()
{
   char *myFifo1 = "fifoChannel1";
   char *myFifo2 = "fifoChannel2";
	


   pthread_t w_thread, r_thread;
   if (pthread_create(&r_thread, NULL, read_thread_fun, (void *)myFifo1) != 0)
   {
       printf("Error while creating read thread\n");
       return 1;
   }
   if (pthread_create(&w_thread, NULL, write_thread_fun, (void *)myFifo2) != 0)
   {
       printf("Error while creating write thread\n");
       return 1;
   }
   pthread_join(w_thread, NULL);
   pthread_join(r_thread, NULL);
   return 0;
}
