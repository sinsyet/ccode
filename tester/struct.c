#include <stdio.h>

struct _person{
  char *name;
  int age;
  int sex;     
};

struct AA{
    /* 
    // 这个写法: 12个字节, 不友好的写法; 
     char b;  
     int a;
     char c; 
     
     */ 
     // 如下只占8个字节;  
     int a;
     char b;
     char c;  
};

struct BB{
     // 占了12个字节 
     char a[10];
     char b;
     char c;  
};

struct CC{
     /*
     这种写法也有问题; short是偶数位对齐, 这个写法占了12个字节
     1    2    3   4 
     a         b1  b2                     // 可以看出, b是sizeof(short)的倍数才对齐 
     c
     i1   i2   i3   i4
     占了12个字节  
     
     浪费了的字节其实也是可用的, 我们只需要拿到该地址就可以对其进行赋值和读取
     struct CC c;
     char *p = &c;
     p + 1 指向了第一排第二列的位置 
     */
     /* 
     char a;
     short b;
     char c;
     int i;       
     */
     
     // 优化
     char a;
     char b;
     short c;
     int i;
     
     /* 占2个字节 
     1    2    3    4
     a    b    c1   c2
     i1   i2   i3   i4 
     */ 
     
} ;

/*
虽然a只使用两个比特位, 但是
 
sizeof(struct DD) 占1个字节 
*/ 
struct DD{
       char a : 2;  // 指定结构体只使用两个bit位, ps:1个字节占8个比特位       
};

/*
共使用两个比特位, 但是
 
sizeof(struct DD) 占1个字节 , 

这种特性常用于嵌入式设备, 因为内存有限 
*/ 
struct EE{
       char a : 2;
       char b : 2;       
}; 

struct FF{
       int a : 10;
       char b : 2;
       // char b : 10;      不支持这种写法, 即位数超出了数据类型       
}; 



int main()
{
    struct _person ygx = {0};   // 所有成员都赋值为0 
    struct _person xgy = {"袁光芯", 26, 1};
    printf("name: %s, age: %d, sex: %s\n",xgy.name, xgy.age, (xgy.sex == 1 ? "男":"女")); 
    
    printf("%u\n",sizeof(struct AA)); 
    printf("%u\n",sizeof(struct BB)); 
    printf("DD: %u\n",sizeof(struct DD)); 
    printf("EE: %u\n",sizeof(struct EE)); 
    printf("FF: %u\n",sizeof(struct FF));  // FF: 4 
    printf("--------------------------\n");
    struct DD d;
    
  
    // d.a: -1
    // 3的二进制: 11, 1当成符号位, 则值为-1 
    // d.a = 3;
    //  d.a = 2; // d.a: -2,  
    // d.a = 4;  // d.a: 0; 0100
    d.a = -3;    // d.a: 1 
    printf("d.a: %d\n",d.a);               // 
    /*
    DD: 1
    EE: 1
    */
    system("pause"); 
    return 0;
}
