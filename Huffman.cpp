#include <iostream>
#include <queue>
using namespace std;
#define MAXNUM 100      //����ַ��������鳤��
#define MAXHUFF 100     //���������ڵ�ṹ���������
#define MAXCODE 100     //������������ṹ������ĸ���
#define MAXWEIGHT 10000 //���Ȩֵ

typedef struct Huffman {
    int weight;      //Ȩֵ
    char ch;         //�ַ�
    int parent;      //���ڵ�
    int lchild;   //����
    int rchild;  //�Һ���
}HuffmanNode;

typedef struct Code {
    int code[MAXNUM];    //�洢�ַ�����������
    int start;    
}HuffmanCode;

HuffmanNode huffman[MAXHUFF];
HuffmanCode code[MAXCODE];

void buildHuffmanTree(int n) {
    int x1, x2, w1, w2;

    //��ʼ��
    for (int i = 0; i < n * 2 - 1; ++i) {
        huffman[i].weight = 0;
        huffman[i].parent = -1;
        huffman[i].lchild = -1;
        huffman[i].rchild = -1;
    }

    for (int i = 0; i < n; i++) {
        printf("��ֱ������%d���������ַ���Ȩ�أ�", i);
        cin >> huffman[i].ch;
        scanf("%d", &huffman[i].weight);
    }

    for (int i = 0; i < n - 1; i++) {
        x1 = x2 = -1;
        w1 = w2 = MAXWEIGHT;
        for (int j = 0; j < n + i; j++) {
            if (huffman[j].parent == -1 && huffman[j].weight < w1) {
                w2 = w1;    //ÿ����С�ĸ����ˣ����ϴ���С�ĸ��ڶ�С��   
                x2 = x1;
                x1 = j;
                w1 = huffman[j].weight;
            }
            else if (huffman[j].parent == -1 && huffman[j].weight < w2) {
                x2 = j;
                w2 = huffman[j].weight;
            }
        }
        //�ҵ���С�������ڵ��ϲ���һ���µĽڵ�
        huffman[n + i].lchild = x1;
        huffman[n + i].rchild = x2;
        huffman[n + i].weight = w1 + w2;
        huffman[x1].parent = n + i;
        huffman[x2].parent = n + i;
    }
}

void Print(int n) {
    HuffmanCode hcode;   //���浱ǰҶ�ӽڵ���ַ�����
    int curParent;       //��ǰ���ڵ�
    int c;               //�±��Ҷ�ӽڵ�ı��

    for (int i = 0; i < n; ++i) {
        hcode.start = n - 1;
        c = i;
        curParent = huffman[i].parent;
        //�ж���ڵ��Ƿ�Ϊ��ǰֵ�������ȡ�ڵ�0,����ȡ�ڵ�1
        while (curParent != -1) {
            if (huffman[curParent].lchild == c) 
                hcode.code[hcode.start] = 0;
            else 
                hcode.code[hcode.start] = 1;
            hcode.start--;
            c = curParent;
            curParent = huffman[c].parent;
        }
        //�ѵ�ǰ��Ҷ�ӽڵ���Ϣ���浽����ṹ������
        for (int j = hcode.start + 1; j < n; j++) 
            code[i].code[j] = hcode.code[j];
        code[i].start = hcode.start;
    }
}
int main() {
    int n = 0;
    printf("������������ַ�������");
    cin >> n;
    if (n == 0) 
        exit(0);
    buildHuffmanTree(n);
    Print(n);
    for (int i = 0; i < n; i++) {
        printf("%c������ǰ׺�����ǣ�", huffman[i].ch);
        for (int j = code[i].start + 1; j < n; ++j) 
            printf("%d", code[i].code[j]);
        printf("\n");
    }
    return 0;
}