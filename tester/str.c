#include <stdio.h>
#include <string.h> 

size_t m_strlen(const char *s); 
char* m_strtok(char s[], const char *delim);
int m_strcmp(const char *s, const char *s2);
char* m_strstr(char *s, const char *s2);

void test()
{
    int cmp = m_strncmp("hello","hello ",5);
    char ch[5] = {'h','z','x','c','v'}; 
    size_t len = m_strlen("hello"); 
    printf("%d, len: %u\n",cmp, len);
    // hzxcv, 5, 5, 5 , 感觉字符串最后最好默认追加个0 
    printf("%s, %u, %u, %u\n",ch,strlen(ch), m_strlen(ch),sizeof(ch));
} 

void test2()
{
      char buf[64];
    // strcpy(buf, "@12@34@56");
    strcpy(buf, "987654321");
    // char *s = m_strtok(buf, "@"); 
    char *s = strtok(buf, "@");
    printf("%s ", s);
    while(s)
    {
          s = strtok(NULL, "@");
          if(s)
               printf("%s ", s);
    }
    printf("\n");
}

void test3()
{
     /*
    char buf[64];
    strcpy(buf, "hello world");*/
    char *buf = "hello world";   // 可以的哦, 因为只是read, 没有去修改 
    // strcpy(buf, "world");
    char *wtf = m_strstr(buf, " ");
    printf("%s\n",wtf);
    /*
    printf("----------------------------------\n");
    int r = m_strncmp(buf, "wor", 3);
    printf("%d\n", r);
    */
}
int main()
{
    char s[64] = "1232425";       // 支持这种赋值方式 
    char *buf = m_strtok(s,"2");
    printf("%s, s:%s\n",buf,s); 
    while(buf = m_strtok(NULL, "2"))
    {
         printf("%s, s:%s\n",buf,s); 
    }
    system("pause"); 
    return 0;
} 

char *strtok_buf; 
int start_index;
int end_index; 
char* m_strtok(char s[], const char *delim)
{
      if(s == NULL && strtok_buf == NULL)
      { 
           return NULL;   
      }
      
      if(delim == NULL) return strtok_buf;
      
      if(s != NULL) {
           strtok_buf = s; 
           start_index = -1;
           end_index = -1; 
      }
      size_t delim_len = m_strlen(delim); 
            
      char *tmp = m_strstr(strtok_buf, delim);

      char *res = strtok_buf;
      if(tmp == NULL) 
      {
            strtok_buf = NULL; 
            return res; 
      }

      int i = 0;
      for(;i<delim_len;i++)
      {
            *(tmp + i) = 0; 
      } 
      strtok_buf = tmp + delim_len;
      return res;       
}

int m_strcmp(const char *s, const char *s2)
{
    if(s == NULL && s2 == NULL) return 0;
    if(s == NULL) return -1;
    if(s2 == NULL) return 1;
    
    size_t len1 = m_strlen(s);
    size_t len2 = m_strlen(s2);
    
    size_t min_len = len1 < len2 ? len1 : len2;
    
    int index = 0;
    char a, b; 
    while(index < min_len)
    {
        a = s[index];
        b = s2[index];
        if(a > b) return 1;
        if(a < b) return -1; 
        index ++; 
    } 
    if(len1 == len2) return 0;
    
    return len1 > len2 ? 1 : -1;
} 

int m_strncmp(const char *s, const char *s2, size_t count)
{
     if(s == NULL && s2 == NULL) return 0;
    if(s == NULL) return -1;
    if(s2 == NULL) return 1;
    
    size_t len1 = m_strlen(s);
    size_t len2 = m_strlen(s2);
    
    size_t min_len = len1 < len2 ? len1 : len2;
    size_t cmp_len = min_len < count ? min_len : count;
    
    int index = 0;
    char a, b; 
    while(index < cmp_len)
    {
        a = s[index];
        b = s2[index];
        if(a > b) return 1;
        if(a < b) return -1; 
        index ++; 
    } 
    
    if(cmp_len == count) return 0;
    
    return len1 > len2 ? 1 : -1;
} 

size_t m_strlen(const char *s)
{
       size_t len = 0;
       while(s[len] != 0)
       {
                    len ++; 
       }
       return len;
} 

char* m_strstr(char *s, const char *s2)
{
      size_t len2 = m_strlen(s2);
      size_t len1 = m_strlen(s);
      // printf("len2:%u, len1: %u\n",len2, len1);
      char *tmp = s;
      while(0 != m_strncmp(tmp, s2, len2))
      {
          tmp = tmp + len2;
          len1 -= len2;
          if(len1 < len2) return NULL;
      }
      return tmp;
}


