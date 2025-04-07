//
// Created by Administrator on 2024/7/27.
//
/*01.从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删元素的值。
 * 空出的位置由最后一个元素填补，若顺序表为空，则显示出错信息并退出运行。
【提炼】顺序表 - 删min（返回min，空出位置用最后一个元素填补）
【算法思想】搜索整个顺序表，查找最小值元素并记住其位置，搜索结束后用最后一个元素填补空出的原最小值元素的位置。
本题代码如下：*/
#include "C2_2_2_3_01.h"
bool Del_Min(SqList &L,ElemType &value){
//删除顺序表L中最小值元素节点，并通过引用型参数value返回其值
//若删除成功，则返回true；否则返回false
    if(L.length==0){
        return false;                   //表空，中止操作返回
    }
    value=L.data[0];
    int pos=0;                          //假定0号元素的值最小
    for(int i=1;i<L.length;i++){        //循环，寻找具有最小值的元素
        if(L.data[i]<value){            //让value记忆当前具有最小值的元素
            value=L.data[i];
            pos=i;
        }
    }
    L.data[pos]=L.data[L.length-1];     //空出的位置由最后一个元素填补
    L.length--;
    return true;                        //此时，value即为最小值
}
/*注意：本题也可用函数返回值返回，两者的区别是：
 * 函数返回值只能返回一个值，而参数返回（引用传参）可以返回多个值*/

