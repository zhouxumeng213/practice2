#include<stdio.h>
#include<assert.h>
#include<string.h>
//题目一：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
//输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
//{3，4，5，1，2}为{1，2，3，4，5}的一个旋转，该数组的最小值为1

//由数组可以观察出，最小的数刚好是分界线，因此可以利用二分查找
int min_num(int arr[],int len)
{
	assert(arr);
	int left = 0;
	int right = len - 1;
	int mid = 0;//当没有旋转时，直接返回第一个元素
	while (arr[left]>=arr[right])//注意条件
	{
		if (right - left == 1)
		{
			mid = right;
			break;
		}
		mid = (left + right) / 2;//优化
		if (arr[mid] >= arr[left])
		{
			left = mid;
		}
		else if (arr[mid] <= arr[left])
		{
			right = mid;
		}
	}
	return arr[mid];
}

//补充：当left、right、mid三个指针指向的数字相同时，无法确定mid位于哪边，必须顺序查找
//如：{1，0，1，1，1}和{1，1，1，0，1}都是{0，1，1，1，1}的旋转
int find_min(int arr[], int left, int right)
{
	int ret = arr[left];
	for (int i = 1; i <= right; i++)
	{
		if (ret > arr[i])
			ret = arr[i];
	}
	return ret;
}
int min_num(int arr[], int len)
{
	assert(arr);
	int left = 0;
	int right = len - 1;
	int mid = 0;//当没有旋转时，直接返回第一个元素
	while (arr[left] >= arr[right])//注意条件
	{
		if (right - left == 1)
		{
			mid = right;
			break;
		}
		mid = (left + right) / 2;//优化
		if (arr[left] == arr[right] && arr[mid] == arr[left])
		{
			return find_min(arr, left, right);
		}
		if (arr[mid] >= arr[left])
		{
			left = mid;
		}
		else if (arr[mid] <= arr[left])
		{
			right = mid;
		}
	}
	return arr[mid];
}
int main()
{
	int arr[] = { 1, 0, 1, 1, 1 };
	int ret = min_num(arr, 5);
	printf("%d\n", ret);
	return 0;
}


//题目二：写一个函数，输入n,求斐波那契数列的第n项。

//1.递归解法
int fib(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	if (n == 1 || n == 2)
	{
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}

//2.常规解法
int fib(int n)
{
	int first = 1;
	int second = 1;
	int sum = 0;
	if (n == 1 || n == 2)
		return 1;
	for (int i = 3; i <= n; i++)
	{
		sum = first + second;
		first = second;
		second = sum;
	}
	return sum;
}
int main()
{
	int ret = fib(8);
	printf("%d\n", ret);
	return 0;
}
//类似题目一：青蛙跳问题：一直青蛙一次可以跳上一级台阶，也可以跳上两级。求该青蛙
//跳上一个n级的台阶总共有多少种跳法

//类似题目二：可以用2*1的小矩形横着或竖着去覆盖更大的矩形，请问用8个2*1的小矩形
//无重叠地覆盖一个2*8的大矩形，总共有多少种方法




//题目三：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如把9表示成二进制
//是1001，有2位是1.因此如果输入9，该函数输出2

//1.缺点：当n是负数的时候，会出现死循环，因为负数右移的话给最高位置1
int numOf1(int n)
{
	int count = 0;
	while (n > 0)
	{
		if (n & 1)
			count++;
		n = n >> 1;
	}
	return count;
}

//2.置flag=1，然后把flag左移，n的二进制有多少位，就左移多少位
int numOf1(int n)
{
	int count = 0;
	int flag = 1;
	while (flag)
	{
		if (n & flag)
			count++;
		flag = flag << 1;
	}
	return count;
}

//3.再优化：一个数与它减1相与，就会把该数的最右边的一位置为0

//类似题目一：用一条语句判断一个整数是不是2的整数次方。2的整数次方只有
//一位是1，所以用该数和它减1相与，如果结果为零，则是2的整数次方

//类似题目二：输入两个整数m和n，计算需要改变m的二进制表示中的多少位
//才能得到n。第一步求m和n异或的结果，第二步统计异或结果中1的位数
int numOf1(int n)
{
	int count = 0;
	while (n)
	{
		count++;
		n = n&(n - 1);
	}
	return count;
}
int main()
{
	int num = 9;
	int ret = numOf1(num);
	printf("%d\n", ret);
}



//题目四：实现函数double Power(double base,int exponent)，求base的
//exponent次方。不得使用库函数，同时不需要考虑大数问题

//注意：1.底数和指数的正负、零的情况
//      2.浮点数和零的比较不能直接用==
bool is_equal_zero(int num1, int num2)
{
	if ((num1 - num2) > -0.00001 && (num1 - num2) < 0.00001)
	{
		return true;
	}
	return false;
}
double PowerResult(double base, unsigned int absExponent)
{
	double result = 1.0;
	int i = 0;
	for (i = 0; i < absExponent; i++)
	{
		result*=base;
	}
	return result;
}
//优化PowerResult：采用递归的思想，比如求2的32次方，先求平方，再求4次方..8次方..16次方..32次方
double PowerResult2(double base, unsigned int absExponent)
{
	if (absExponent == 0)
		return 1.0;
	if (absExponent == 1)
		return base;
	double result = PowerResult(base, absExponent >> 1);
	result *= result;
	if (absExponent & 0x1 == 1)
	{
		result *= base;
	}
	return result;
}
bool InvalidInput = false;//标识是输入错误返回idea0还是正常运行返回的0
double Power(double base, int exponent)
{
	InvalidInput = false;
	//输入错误
	if (is_equal_zero(base, 0.0) && exponent < 0)
	{
		InvalidInput = true;
		return 0.0;
	}
	if (is_equal_zero(base, 0.0))
	{
		return 1.0;
	}
	unsigned int absExponent = (unsigned int)(exponent);
	if (exponent < 0)
	{
		absExponent = (unsigned int)(-exponent);
	}
	double result = PowerResult2(base, absExponent);
	if (exponent < 0)
	{
		result = 1.0 / result;
	}
	return result;
}
int main()
{
	double base = 2.0;
	int exponent = 3;
	double ret=Power(base, exponent);
	printf("%f\n", ret);
	return 0;
}


//**题目五：输入数字n,按顺序打印出从1最大的n位十进制数。比如输入3，则打印出
//1、2、3一直到最大的3位数即999

//注意：1.考虑大数问题
//      2.打印时考虑用户的习惯，不打印最前面的0
//      3.最大的数的判断溢出问题

bool OverFlow(char* number)
{
	bool isOverFlow = false;
	int TakeOver = 0;
	int len = strlen(number);
	for (int i = len - 1; i >= 0; i--)
	{
		int sum = number[i] - '0' + TakeOver;
		if (i == len - 1)
		{
			sum++;
		}
		if (sum >= 10)
		{
			if (i == 0)
			{
				isOverFlow = true;
			}
			else
			{
				sum -= 10;
				TakeOver = 1;
				number[i] = '0' + sum;
			}
		}
		else
		{
			number[i] = '0' + sum;
			break;
		}
	}
	return isOverFlow;
}
void PrintNum(char* number)
{
	bool begin = true;
	int len = strlen(number);
	for (int i = 0; i < len; i++)
	{
		if (begin && number[i] != '0')
		{
			begin = false;
		}
		if (!begin)
		{
			printf("%c", number[i]);
		}
	}
	printf("\t");
}
void Print(int n)
{
	if (n <= 0)
	{
		return;
	}
	char* number = new char[n + 1];
	memset(number, '\0', n);
	number[n] = '\0';
	while (!OverFlow(number))
	{
		PrintNum(number);
	}
	delete[]number;
}
int main()
{
	Print(1);
	return 0;
}



//题目六：给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该结点
//链表结点与函数的定义如下
struct PLinkNode
{
	int data;
	PLinkNode* next;
};
//1.常规解法，但是不满足时间复杂度为O(1)
void RemoveNode(PLinkNode** pList,PLinkNode* delNode)
{
	assert(pList);
	assert(delNode);
	PLinkNode* begin = *pList;
	PLinkNode* prev = NULL;
	//只有一个结点，而且是要删除的结点
	if (begin->next == NULL && begin->data == delNode->data)
	{
		delete delNode;
		delNode = NULL;
		return;
	}
	//有多个结点，要删除的是头节点，要更新头
	if (begin->data == delNode->data)
	{
		*pList = begin->next;
		delete delNode;
		delNode = NULL;
		return;
	}
	while (begin->next != NULL)
	{
		if (begin->data == delNode->data)
		{
			prev->next = begin->next;
		}
		prev = begin;
		begin = begin->next;
	}
	delete delNode;
	delNode = NULL;
}
//2.时间复杂度为O(1)的解法
//思想：不用遍历链表，将要删除的结点的后一个节点的数据赋值给
//要删除的结点，然后删除后面的结点
void RemoveNode(PLinkNode** pList, PLinkNode* delNode)
{
	assert(pList);
	assert(delNode);
	//只有一个节点，而且是要删除的结点
	if ((*pList)->next == NULL && (*pList)->data == delNode->data)
	{
		delete delNode;
		delNode = NULL;
		return;
	}
	//删除的是尾结点,没有后一个结点，所以必须遍历
	PLinkNode* begin = *pList;
	while (begin->next!=delNode)
	{
		begin = begin->next;
	}
	begin->next = NULL;
	delete delNode;
	delNode = NULL;
	//正常情况
	if (delNode->next != NULL)
	{
		PLinkNode* pNext = delNode->next;
		delNode->data = pNext->data;
		delNode->next = pNext->next;
		delete pNext;
		pNext = NULL;
	}
}



//题目七：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
//奇数位于数组的前半部分，所有偶数位于数组的后半部分

void Adjust(int arr[], int len)
{
	if (arr == NULL || len == 0)
	{
		return;
	}
	int left = 0;
	int right = len-1 ;
	while (left <= right)
	{
		while ( (left<=right) && (arr[left] & 0x1 != 0))
		{
			left++;
		}
		while ((left<=right) && ((arr[right])%2 == 0))//?
		{
			right--;
		}
		if (left<=right)
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7};
	Adjust(arr, 7);
	int i = 0;
	for (i = 0; i < 7; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}





