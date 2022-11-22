/*
NIM             : 13521144
Nama            : Bintang Dwi Marthen
Tanggal         : 21 November 2022
Topik Praktikum : ADT Binary Tree
Deskripsi       : Implementasi ADT Binary Tree
*/
#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree){
    BinTree t = newTreeNode(root);
    if(t!=NULL){
        LEFT(t)=left_tree;
        RIGHT(t)=right_tree;
    }
    return t;
}

void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p){
    *p = NewTree(root, left_tree, right_tree);
}

Address newTreeNode(ElType val){
    Address p = (Address)malloc(sizeof(TreeNode));
    if(p!=NULL){
        ROOT(p) = val;
        LEFT(p) = NULL;
        RIGHT(p) = NULL;
    }
}

void deallocTreeNode (Address p){
    free(p);
}

boolean isTreeEmpty (BinTree p){
    return p==NULL;
}

boolean isOneElmt (BinTree p){
    if(!isTreeEmpty(p)){
        return (LEFT(p)==NULL && RIGHT(p)==NULL);
    }
    return false;
}

boolean isUnerLeft (BinTree p){
    if(!isTreeEmpty(p)){
        return (LEFT(p)!=NULL && RIGHT(p)==NULL);
    }
    return false;
}

boolean isUnerRight (BinTree p){
    if(!isTreeEmpty(p)){
        return (LEFT(p)==NULL && RIGHT(p)!=NULL);
    }
    return false;
}

boolean isBinary (BinTree p){
    if(!isTreeEmpty(p)){
        return (LEFT(p)!=NULL && RIGHT(p)!=NULL);
    }
    return false;
}

void printPreorder(BinTree p){
    printf("(");
    if (!isTreeEmpty(p)) {
        printf("%d", ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
    }
    printf(")");
}

void printInorder(BinTree p){
    printf("(");
    if (!isTreeEmpty(p)) {
        printInorder(LEFT(p));
        printf("%d", ROOT(p));
        printInorder(RIGHT(p));
    }
    printf(")");
}

void printPostorder(BinTree p){
    printf("(");
    if (!isTreeEmpty(p)) {
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p));
        printf("%d", ROOT(p));
    }
    printf(")");
}

void printTreeDepth(BinTree p, int h, int depth){
    if(!isTreeEmpty(p)){
        int i;
        for(i=0;i<(h*depth);i++){
            printf(" ");
        }
        printf("%d\n", ROOT(p));
        printTreeDepth(LEFT(p), h, depth+1);
        printTreeDepth(RIGHT(p), h, depth+1);
    }
}

void printTree(BinTree p, int h){
    printTreeDepth(p, h, 0);
}