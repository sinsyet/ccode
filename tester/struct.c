#include <stdio.h>

struct _person{
  char *name;
  int age;
  int sex;     
};

struct AA{
    /* 
    // ���д��: 12���ֽ�, ���Ѻõ�д��; 
     char b;  
     int a;
     char c; 
     
     */ 
     // ����ֻռ8���ֽ�;  
     int a;
     char b;
     char c;  
};

struct BB{
     // ռ��12���ֽ� 
     char a[10];
     char b;
     char c;  
};

struct CC{
     /*
     ����д��Ҳ������; short��ż��λ����, ���д��ռ��12���ֽ�
     1    2    3   4 
     a         b1  b2                     // ���Կ���, b��sizeof(short)�ı����Ŷ��� 
     c
     i1   i2   i3   i4
     ռ��12���ֽ�  
     
     �˷��˵��ֽ���ʵҲ�ǿ��õ�, ����ֻ��Ҫ�õ��õ�ַ�Ϳ��Զ�����и�ֵ�Ͷ�ȡ
     struct CC c;
     char *p = &c;
     p + 1 ָ���˵�һ�ŵڶ��е�λ�� 
     */
     /* 
     char a;
     short b;
     char c;
     int i;       
     */
     
     // �Ż�
     char a;
     char b;
     short c;
     int i;
     
     /* ռ2���ֽ� 
     1    2    3    4
     a    b    c1   c2
     i1   i2   i3   i4 
     */ 
     
} ;

/*
��Ȼaֻʹ����������λ, ����
 
sizeof(struct DD) ռ1���ֽ� 
*/ 
struct DD{
       char a : 2;  // ָ���ṹ��ֻʹ������bitλ, ps:1���ֽ�ռ8������λ       
};

/*
��ʹ����������λ, ����
 
sizeof(struct DD) ռ1���ֽ� , 

�������Գ�����Ƕ��ʽ�豸, ��Ϊ�ڴ����� 
*/ 
struct EE{
       char a : 2;
       char b : 2;       
}; 

struct FF{
       int a : 10;
       char b : 2;
       // char b : 10;      ��֧������д��, ��λ����������������       
}; 



int main()
{
    struct _person ygx = {0};   // ���г�Ա����ֵΪ0 
    struct _person xgy = {"Ԭ��о", 26, 1};
    printf("name: %s, age: %d, sex: %s\n",xgy.name, xgy.age, (xgy.sex == 1 ? "��":"Ů")); 
    
    printf("%u\n",sizeof(struct AA)); 
    printf("%u\n",sizeof(struct BB)); 
    printf("DD: %u\n",sizeof(struct DD)); 
    printf("EE: %u\n",sizeof(struct EE)); 
    printf("FF: %u\n",sizeof(struct FF));  // FF: 4 
    printf("--------------------------\n");
    struct DD d;
    
  
    // d.a: -1
    // 3�Ķ�����: 11, 1���ɷ���λ, ��ֵΪ-1 
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
