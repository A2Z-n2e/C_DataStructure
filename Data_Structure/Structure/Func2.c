//
// Created by Administrator on 2024/4/9.
//25数据结构1.2.3单项选择题第10题，递归调用 - 原代码
#include <stdio.h>

int func2(int n) {
    if (n == 1) {
        printf("%d\n", n);
        printf("----1----");
        return 1;
    } else {
        printf("%d\n", n);
        return 2 * func2(n / 2) + n;
    }
}


int main() {
    func2(4);

    return 0;
}