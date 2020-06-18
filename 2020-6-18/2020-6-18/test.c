#include<stdio.h>
#include<windows.h>
#pragma warning (disable:4996)
//编写一个函数 reverse_string(char * string)（递归实现）
//
//实现：将参数字符串中的字符反向排列。
//
//要求：不能使用C函数库中的字符串操作函数。
void ReverseString(char *arr)
{
	char *start = arr;
	char *end = arr + strlen(arr) - 1;
	char temp = *start;
	*start = *end;
	*end = '\0';
	if (strlen(arr + 1) >= 2){
		ReverseString(arr + 1);
	}
	*end = temp;
	//code1:
	//char *start = arr;
	//char *end = arr + strlen(arr) - 1;
	//while (start < end){
	//	char temp = *start;
	//	*start = *end;
	//	*end = temp;
	//	start++;
	//	end--;
	//}
}
int main()
{
	char arr[] = "abcdef";
	printf("%s\n", arr);
	ReverseString(arr);
	printf("%s\n", arr);
	system("pause");
	return 0;
}
