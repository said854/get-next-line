#include "get_next_line.h"
int check_new_line_buffer(char  *str)
{
   int i;
   i = 0;
   while (str[i])
   {
      if(str[i] == '\n')
         return (i);
      i++;   
   }
   return (0);
}

// int get_len(char *str)
// {
//    int i;

//    i = 0;
//    while (str[i])
//    {0§Q2W
//       if(str[i] == '\n')
//          return i;
//       i++;   
//    }
//    return 0;
// }
ssize_t read_data(int fd, char *str)
{
   ssize_t bytes_to_read;

   bytes_to_read = 0;
   ft_bzero(str, BUFFER_SIZE);
   bytes_to_read =  read(fd, str, BUFFER_SIZE);
   return(bytes_to_read);
}

char *line_to_read(char *buff)
{
   int i;
   char *ptr;

   i = 0;
   ptr = (char *)malloc(BUFFER_SIZE + 1);
   while(i < BUFFER_SIZE)
   {
      ptr[i] = buff[i];
      i++;
   }
   return ptr;
}

int get_len(const char *str) {
    const char *newline = strchr(str, '\n');
    if (newline != NULL) {
        return newline - str + 1;
    }
    return 0;
}

char *after_new_line(const char *str) {
   if (str == NULL) {
      return NULL;
   }

   int len = strlen(str);
   int i = get_len(str);

   if (i == 0 || i >= len) {
      return strdup(""); // Return an empty string
   }
   char *rest = (char *)malloc(len - i + 1);
   if (rest == NULL) {
      return NULL;
   }
   strcpy(rest, str + i);
   return rest;
}

char *get_next_line(fd)
{
   char *buffer;
   static char *ptr;
   char *temp;
   char *rest;
   int i;

   buffer = (char *)malloc(BUFFER_SIZE + 1);
   temp = (char *)malloc(get_len(ptr) + 1);
   if(ptr)
   {
      rest = after_new_line(ptr);
      temp = ft_strjoin(rest, ptr);
      printf("rest is :{%s}\n",rest);
   }
   read_data(fd, buffer);
   ptr = strdup(buffer);
   while(!check_new_line_buffer(ptr))
   {
      read_data(fd, buffer);
      // printf("buffer is :{%s}\n",buffer);
      ptr = ft_strjoin(ptr, buffer);
   }
   i = 0;
   while(i < get_len(ptr))
   {
      temp[i] = ptr[i];
      i++;
   }
   // else if(!buffer && check_new_line_buffer(ptr))
   //    ft_memcpy(ptr, strlen(rest), );
   return temp;  
}

#include <stdio.h>
int main()
{
   int fd;
   char *ptr;

   fd = open("hello.txt", O_RDWR);
   if(fd == -1){
      return (0);
   }
   // get_next_line(fd);
   // get_next_line(fd);
   ptr = get_next_line(fd);
   // ptr = get_next_line(fd);
   printf("%s\n", ptr);
   // close(fd);
   
}