#pragma once

//符号的定义
#define ROW 3
#define COL 3

//头文件的包含
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//函数声明

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);

//打印棋盘的函数
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);

//告诉我们四种游戏状态 
//玩家赢                         '*'
//电脑赢                         '#'
//平局                           'Q'
//继续                           'C'

//判读游戏是否有输赢
char IsWin(char board[ROW][COL], int row, int col);