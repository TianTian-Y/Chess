#include<stdio.h>
#include<windows.h>
#pragma warning (disable:4996)
//��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
//
//ʵ�֣��������ַ����е��ַ��������С�
//
//Ҫ�󣺲���ʹ��C�������е��ַ�������������
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
