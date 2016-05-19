#include<stdio.h>
#include<assert.h>
#include<string.h>
//��Ŀһ����һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
//����һ����������������һ����ת�������ת�������СԪ�ء���������
//{3��4��5��1��2}Ϊ{1��2��3��4��5}��һ����ת�����������СֵΪ1

//��������Թ۲������С�����պ��Ƿֽ��ߣ���˿������ö��ֲ���
int min_num(int arr[],int len)
{
	assert(arr);
	int left = 0;
	int right = len - 1;
	int mid = 0;//��û����תʱ��ֱ�ӷ��ص�һ��Ԫ��
	while (arr[left]>=arr[right])//ע������
	{
		if (right - left == 1)
		{
			mid = right;
			break;
		}
		mid = (left + right) / 2;//�Ż�
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

//���䣺��left��right��mid����ָ��ָ���������ͬʱ���޷�ȷ��midλ���ıߣ�����˳�����
//�磺{1��0��1��1��1}��{1��1��1��0��1}����{0��1��1��1��1}����ת
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
	int mid = 0;//��û����תʱ��ֱ�ӷ��ص�һ��Ԫ��
	while (arr[left] >= arr[right])//ע������
	{
		if (right - left == 1)
		{
			mid = right;
			break;
		}
		mid = (left + right) / 2;//�Ż�
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


//��Ŀ����дһ������������n,��쳲��������еĵ�n�

//1.�ݹ�ⷨ
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

//2.����ⷨ
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
//������Ŀһ�����������⣺һֱ����һ�ο�������һ��̨�ף�Ҳ���������������������
//����һ��n����̨���ܹ��ж���������

//������Ŀ����������2*1��С���κ��Ż�����ȥ���Ǹ���ľ��Σ�������8��2*1��С����
//���ص��ظ���һ��2*8�Ĵ���Σ��ܹ��ж����ַ���




//��Ŀ������ʵ��һ������������һ��������������������Ʊ�ʾ��1�ĸ����������9��ʾ�ɶ�����
//��1001����2λ��1.����������9���ú������2

//1.ȱ�㣺��n�Ǹ�����ʱ�򣬻������ѭ������Ϊ�������ƵĻ������λ��1
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

//2.��flag=1��Ȼ���flag���ƣ�n�Ķ������ж���λ�������ƶ���λ
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

//3.���Ż���һ����������1���룬�ͻ�Ѹ��������ұߵ�һλ��Ϊ0

//������Ŀһ����һ������ж�һ�������ǲ���2�������η���2�������η�ֻ��
//һλ��1�������ø���������1���룬������Ϊ�㣬����2�������η�

//������Ŀ����������������m��n��������Ҫ�ı�m�Ķ����Ʊ�ʾ�еĶ���λ
//���ܵõ�n����һ����m��n���Ľ�����ڶ���ͳ���������1��λ��
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



//��Ŀ�ģ�ʵ�ֺ���double Power(double base,int exponent)����base��
//exponent�η�������ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ�������

//ע�⣺1.������ָ����������������
//      2.����������ıȽϲ���ֱ����==
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
//�Ż�PowerResult�����õݹ��˼�룬������2��32�η�������ƽ��������4�η�..8�η�..16�η�..32�η�
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
bool InvalidInput = false;//��ʶ��������󷵻�idea0�����������з��ص�0
double Power(double base, int exponent)
{
	InvalidInput = false;
	//�������
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


//**��Ŀ�壺��������n,��˳���ӡ����1����nλʮ����������������3�����ӡ��
//1��2��3һֱ������3λ����999

//ע�⣺1.���Ǵ�������
//      2.��ӡʱ�����û���ϰ�ߣ�����ӡ��ǰ���0
//      3.���������ж��������

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



//��Ŀ�����������������ͷָ���һ�����ָ�룬����һ��������O(1)ʱ��ɾ���ý��
//�������뺯���Ķ�������
struct PLinkNode
{
	int data;
	PLinkNode* next;
};
//1.����ⷨ�����ǲ�����ʱ�临�Ӷ�ΪO(1)
void RemoveNode(PLinkNode** pList,PLinkNode* delNode)
{
	assert(pList);
	assert(delNode);
	PLinkNode* begin = *pList;
	PLinkNode* prev = NULL;
	//ֻ��һ����㣬������Ҫɾ���Ľ��
	if (begin->next == NULL && begin->data == delNode->data)
	{
		delete delNode;
		delNode = NULL;
		return;
	}
	//�ж����㣬Ҫɾ������ͷ�ڵ㣬Ҫ����ͷ
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
//2.ʱ�临�Ӷ�ΪO(1)�Ľⷨ
//˼�룺���ñ���������Ҫɾ���Ľ��ĺ�һ���ڵ�����ݸ�ֵ��
//Ҫɾ���Ľ�㣬Ȼ��ɾ������Ľ��
void RemoveNode(PLinkNode** pList, PLinkNode* delNode)
{
	assert(pList);
	assert(delNode);
	//ֻ��һ���ڵ㣬������Ҫɾ���Ľ��
	if ((*pList)->next == NULL && (*pList)->data == delNode->data)
	{
		delete delNode;
		delNode = NULL;
		return;
	}
	//ɾ������β���,û�к�һ����㣬���Ա������
	PLinkNode* begin = *pList;
	while (begin->next!=delNode)
	{
		begin = begin->next;
	}
	begin->next = NULL;
	delete delNode;
	delNode = NULL;
	//�������
	if (delNode->next != NULL)
	{
		PLinkNode* pNext = delNode->next;
		delNode->data = pNext->data;
		delNode->next = pNext->next;
		delete pNext;
		pNext = NULL;
	}
}



//��Ŀ�ߣ�����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ������
//����λ�������ǰ�벿�֣�����ż��λ������ĺ�벿��

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





