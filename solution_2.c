#include <stdio.h>

typedef int (*F)(char *s);

/*
 * 通过位移法判断是否是字符串结束符'\0'
 * 如果为0，返回0，定位到函数指针数组的第0个函数，即end_recursion_func
 * 如果为非0，返回1，定位到函数指针数组的第1个函数，即continue_func 
 */
int get_func_index(unsigned int n) {
    n |= n >> 16;
    n |= n >> 8;
    n |= n >> 4;
    n |= n >> 2;
    n |= n >> 1;
    return n & 1;
}


/*
 * 值为'\0'(即0)时调用的函数, 调用到此函数时结束递归
 */
int end_recursion_func(char *);
/*
 * 值为非0时调用的函数, 递归调用下一个函数
 */
int continue_func(char *);

/*
 * 函数指针数组
 */
F f[] = {end_recursion_func, continue_func};

int end_recursion_func(char *s) {
    return 0;
}

int continue_func(char *s) {
    return 1 + f[get_func_index(*s)](s+1);
}

int main(int argc, char *argv[]) {
    char *s = argv[1];
    printf("%d\n", f[get_func_index(*s)](s+1));
    return 0;
}
