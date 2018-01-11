#include <stdio.h>

// static 其实更像是针对.c文件和.c文件之间的私有
// .h文件我觉得其实就是把.h文件拷贝到main.c里一样， 所以static没用
/*static*/ int aa = 10;
/*static*/ int add(int x, int y)
{
	return x + y;
}
