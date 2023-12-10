
// 入口主程序，初始化图对象并进入操作菜单

#include <iostream>
#include "arrayWDigraph.h"

int main(){

    arrayWDigraph<int> W(0); // 初始化一个空图
    W.init(); // 初始化并进入操作界面

    return 0;
}