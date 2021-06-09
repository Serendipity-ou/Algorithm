#include <iostream>
#include <queue>
using namespace std;
#define MAXNUM 100      //最大字符编码数组长度
#define MAXHUFF 100     //最大哈夫曼节点结构体数组个数
#define MAXCODE 100     //最大哈夫曼编码结构体数组的个数
#define MAXWEIGHT 10000 //最大权值

typedef struct Huffman {
    int weight;      //权值
    char ch;         //字符
    int parent;      //父节点
    int lchild;   //左孩子
    int rchild;  //右孩子
}HuffmanNode;

typedef struct Code {
    int code[MAXNUM];    //存储字符哈夫曼编码
    int start;    
}HuffmanCode;

HuffmanNode huffman[MAXHUFF];
HuffmanCode code[MAXCODE];

void buildHuffmanTree(int n) {
    int x1, x2, w1, w2;

    //初始化
    for (int i = 0; i < n * 2 - 1; ++i) {
        huffman[i].weight = 0;
        huffman[i].parent = -1;
        huffman[i].lchild = -1;
        huffman[i].rchild = -1;
    }

    for (int i = 0; i < n; i++) {
        printf("请分别输入第%d个哈夫曼字符和权重：", i);
        cin >> huffman[i].ch;
        scanf("%d", &huffman[i].weight);
    }

    for (int i = 0; i < n - 1; i++) {
        x1 = x2 = -1;
        w1 = w2 = MAXWEIGHT;
        for (int j = 0; j < n + i; j++) {
            if (huffman[j].parent == -1 && huffman[j].weight < w1) {
                w2 = w1;    //每次最小的更新了，把上次最小的给第二小的   
                x2 = x1;
                x1 = j;
                w1 = huffman[j].weight;
            }
            else if (huffman[j].parent == -1 && huffman[j].weight < w2) {
                x2 = j;
                w2 = huffman[j].weight;
            }
        }
        //找到最小的两个节点后合并成一个新的节点
        huffman[n + i].lchild = x1;
        huffman[n + i].rchild = x2;
        huffman[n + i].weight = w1 + w2;
        huffman[x1].parent = n + i;
        huffman[x2].parent = n + i;
    }
}

void Print(int n) {
    HuffmanCode hcode;   //保存当前叶子节点的字符编码
    int curParent;       //当前父节点
    int c;               //下标和叶子节点的编号

    for (int i = 0; i < n; ++i) {
        hcode.start = n - 1;
        c = i;
        curParent = huffman[i].parent;
        //判断左节点是否为当前值，如果是取节点0,否则取节点1
        while (curParent != -1) {
            if (huffman[curParent].lchild == c) 
                hcode.code[hcode.start] = 0;
            else 
                hcode.code[hcode.start] = 1;
            hcode.start--;
            c = curParent;
            curParent = huffman[c].parent;
        }
        //把当前的叶子节点信息保存到编码结构体里面
        for (int j = hcode.start + 1; j < n; j++) 
            code[i].code[j] = hcode.code[j];
        code[i].start = hcode.start;
    }
}
int main() {
    int n = 0;
    printf("请输入哈夫曼字符个数：");
    cin >> n;
    if (n == 0) 
        exit(0);
    buildHuffmanTree(n);
    Print(n);
    for (int i = 0; i < n; i++) {
        printf("%c的最优前缀编码是：", huffman[i].ch);
        for (int j = code[i].start + 1; j < n; ++j) 
            printf("%d", code[i].code[j]);
        printf("\n");
    }
    return 0;
}