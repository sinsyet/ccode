#include <stdio.h>

int main()
{
    char file_name[20];
    printf("input file path: "); 
    scanf("%s",file_name);
    printf("%s\n",file_name);
   
     
    // r+以读写mode打开文件, 该文件必须存在; 
    FILE *f = fopen(file_name, "r+");
    if(f == NULL)
    {
         printf("no file\n");
         return 0;     
    }
    char buf[64 + 1];
    size_t buf_len = sizeof(buf); 
    buf[buf_len - 1] = 0;
    size_t len = fread(buf, sizeof(char), buf_len - 1,f);
    if(len == buf_len - 1)
    {
           printf("%s",buf);
           while(len == buf_len - 1)
           {
               len = fread(buf, sizeof(char), buf_len - 1,f);
               if(len < buf_len - 1)
               {
                      buf[len + 1] = 0;
               }    
               printf("%s",buf);
           }
    }
    else
    {
         buf[len + 1] = 0;
         printf("%s",buf);
    } 
    printf("\n");
    system("pause");
    return 0;
}
