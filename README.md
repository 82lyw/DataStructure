# DataStructure
Some practice in data structure of C++

## 线性表
#### 1.顺序表
#### 2.非循环单链表
#### 3.循环单链表
#### 4.循环双链表

## 栈
#### 1.顺序栈
##### 应用：（1）后缀表达式求解
中缀表达式：运算符号位于两个运算数之间。Eg.a+b*c-d/e <br>
后缀表达式：运算符位于两个运算数之后。Eg.a b c * + d e / -<br>
* 中缀表达式转换为后缀表达式：
Eg.23-((34-13)*7+6/2)   =>   23 34 13 - 7 * 6 2 / -

| 待处理表达式 | 堆栈状态（底<—>顶） | 输出状态 |
|:--------   | :-----   | :---- |
| 23-（（34-13）*7+6/2） |  |  |
| -（（34-13）*7+6/2） |  | 23 |
| （（34-13）*7+6/2） | - | 23 |
| （34-13）*7+6/2） | - ( | 23 |
| 34-13）*7+6/2） | - ( ( | 23 |
| -13）*7+6/2） | - ( ( | 23 34 |
| 13）*7+6/2） | - ( ( - | 23 34 |
| ）*7+6/2） | - ( ( - | 23 34 13 |
| *7+6/2） | - (  | 23 34 13 - |
| 7+6/2） | - ( * | 23 34 13 - |
| +6/2） | - ( * | 23 34 13 - 7 |
| 6/2） | - ( + | 23 34 13 - 7 * |
| /2） | - ( + | 23 34 13 - 7 * 6 |
| 2） | - ( + / | 23 34 13 - 7 * 6  |
| ） | - ( + / | 23 34 13 - 7 * 6 2 |
|  |  | 23 34 13 - 7 * 6 2 / + - |
1. 规律：操作数相对顺序不发生改变；运算符顺序发生改变（存储“等待中”的运算符，将当前运算符号与“等待中”的最后一个运算符号比较）
2. 方法：
操作数：直接输出
左括号：压栈
右括号：弹出栈顶运算符，直到遇到左括号（出栈但不输出）
运算符：优先级>栈顶运算符，压栈；<=栈顶运算符，栈顶运算符弹出并输出
* 后缀表达式的计算
后缀表达式求值：（从左往右“扫描”，逐个处理操作数和运算符号）

##### 应用：（2）迷宫求解
#### 2.链栈

### 队列
#### 1.循环顺序队列
#### 2.非循环链队

## 顺序串

## 多维数组
#### 1.稀疏矩阵（三元组表顺序存储）
#### 2.稀疏矩阵（十字链表存储）

## 广义表

## 树

## 图