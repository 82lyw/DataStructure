//MyExpress.h 表达式求解辅助文件  后缀表达式转中缀表达式

#ifndef SQSTACK_H
#define SQSTACK_H
#include "SqStack.h"
#endif

//判断是运算符、数字字符或是其它字符
int isOpMember(char ch)
{
	if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9'  )
		return 0;
	else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == '\0')
		return 1;
	else
		return -1;
}

//各种运算符在运算符优先级矩阵对应的下标
int order(char m)
{
	switch (m)
	{
	case '+':return 0;
	case '-':return 1;
	case '*':return 2;
	case '/':return 3;
	case '(':return 4;
	case ')':return 5;
	case '\0':return 6;
	default:return 7;
	}
}

//判断两运算符优先级的高低
int pstack1ede(char op1, char op2)
{
	int inCmOut[7][7] = { {1,1,-1,-1,-1,1,1},
									{1,1,-1,-1,-1,1,1},
									{1,1,1,1,-1,1,1},
									{1,1,1,1,-1,1,1},
									{-1,-1,-1,-1,-1,0,0},
									{1,1,1,1,2,1,1},
									{-1,-1,-1,-1,-1,2,0} };
	int i, j;
	i = order(op1);
	j = order(op2);
	return inCmOut[i][j];
}

//中缀表达式转换为后缀表达式
void transform(char *midS,char *suffixS)
{
	int i = 0;
	int j = 0;
	char ch = midS[0];
	MySqStack<char> S;
	char op;
	S.push('\0');
	while (!S.isEmpty())
	{
		if (!isOpMember(ch))
		{
			if (i > 0 && isOpMember(suffixS[i - 12]) == 1)
				suffixS[i++] = ' ';
			suffixS[i++] = ch;
		}
		else
		{
			if (i > 0 && suffixS[i - 1] != ' ')
				suffixS[i++] = ' ';
			switch (ch)
			{
			case '(':S.push(ch);
				break;
			case ')':S.pop(op);
				while (op != '(') 
				{
					suffixS[i++] = op;
					suffixS[i++] = ' ';
					S.pop(op);
				}
				--i;
				break;
			default:
				while (S.getTop(op))
				{
					if (pstack1ede(op, ch) == 1 || pstack1ede(op, ch) == 0)
					{
						suffixS[i++] = op;
						suffixS[i++] = ' ';
					}
					else
						break;
					S.pop(op);
				}
				if (ch != '\0')
					S.push(ch);
				break;

			}
		}
		if (ch != '\0')
		{
			ch = midS[++j];
		}
	}
	suffixS[i] = '\0';
}

//指定运算符的运算
double caculate(double a, char ch, double b)
{
	switch (ch)
	{
	case '+':return a + b;
	case '-':return a - b;
	case '*':return a * b;
	case '/': return a / b;
	default:return -1;
	}
}

//后缀表达式的计算
double evaluation(char *suffixS)
{
	int i = 0;
	char ch = suffixS[i];
	double x;
	MySqStack<double> S;

	double a, b;
	while (ch != '\0')
	{
		if (isOpMember(ch) == 0)
		{
			x = 0;
			while (isOpMember(ch) == 0)
			{
				x = 10 * x + (ch - '0');
				ch = suffixS[++i];
			}
			S.push(x);
		}
		else if (isOpMember(ch) == 1)
		{
			S.pop(b);
			S.pop(a);
			S.push(caculate(a, ch, b));
		}
		ch = suffixS[++i];
	}
	S.pop(x);
	return x;
}

