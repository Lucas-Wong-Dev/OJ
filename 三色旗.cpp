// 三色旗
/*
三色旗的问题最早由E.W.Dijkstra 所提出，他所使用的用语为 Dutch Nation Flag(Dijkstra 为荷兰人)，而多数的作者则使用 Three-Color Flag 来称之。
假设有一条绳子，上面有红、白、蓝三种颜色的旗子，起初绳子上的旗子颜色并没有顺序，您希望将之分类，并排列为蓝、白、红的顺序，要如何移动次数才会最少，注意您只能在绳子上进行这个动作，而且一次只能调换两个旗子。
*/

#include <stdio.h>
// #include <stdlib.h>
#include <string.h>

const char BLUE = 'b';
const char WHITE = 'w';
const char RED = 'r';

void print(char array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%c ", array[i]);
    }
    printf("\n");
}

void swap(char color[], int x, int y)
{
    char temp;
    temp = color[x];
    color[x] = color[y];
    color[y] = temp;
}

int main()
{
    char color[] = {'r', 'w', 'b', 'w', 'w', 'b', 'r', 'b', 'w', 'r', '\0'};
    int wFlag = 0;
    int bFlag = 0;
    int rFlag = strlen(color) - 1;

    int len = strlen(color);
    print(color, len);

    // 要求把数组元素排列为蓝、白、红的顺序
    while (wFlag <= rFlag)
    {
        if (color[wFlag] == WHITE) // 如果w指针当前指向的是白色元素
        {
            wFlag++; // 不做任何处理，w指针接着向右遍历数组
        }
        else if (color[wFlag] == BLUE) // 如果w指针当前指向的是蓝色元素
        {
            swap(color, bFlag, wFlag); // 将当前这个蓝色元素与b指针指向的非蓝元素交换，以将当前这个蓝色元素移动到数组前部。注意：被交换到w指针当前所指向的位置的元素一定是非红元素，因为在w指针从左向右的遍历过程中，只要w指针遇到了红色元素，就通过交换把这个红色元素移动到数组后部，故w指针遍历过的位置存放的只可能是非红色元素，因此被交换到w指针当前所指向的位置的元素只可能是白色元素或蓝色元素。
            bFlag++; // b指针永远指向从左到右第一个非蓝元素，现在已经知道b指针当前指向的元素是蓝色元素，所以b指针要接着向右走
            wFlag++; // w指针用来对数组进行遍历，从最左边第一个元素起向右依次递增
        }
        else // 如果w指针当前指向的是红色元素
        {
            while (color[rFlag] == RED && wFlag < rFlag) // r指针从右向左找到第一个非红色元素
                rFlag--;
            swap(color, rFlag, wFlag); // 将找到第一个非红色元素与w指针当前指向的红色元素交换
            rFlag--; // r指针永远指向从右到左第一个非红元素，现在已经知道r指针当前指向的元素是红色元素，所以r指针要接着向左走
        }
    }

    print(color, len);
    return 0;
}