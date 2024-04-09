//
// Created by Administrator on 2024/4/9.
//25数据结构1.2.3单项选择题第10题，递归调用 - 参考代码
#include <stdio.h>
void func(int n)
{
    if(n<=10){
        printf("%d\n", n);
         func(n + 1);
    }

}

int main()
{
    func(0);
    return 0;
}