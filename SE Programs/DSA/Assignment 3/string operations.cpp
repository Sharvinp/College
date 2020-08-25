#include <iostream>
using namespace std;
class strings
{
public:
	int getlength(char[]);
	void getconcat(char[], char[]);
	void getsubstring(char[], char[]);
	void getreverse(char[]);
	bool getpalindrome(char[], int, int);
};
int strings::getlength(char str[])
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}
void strings::getconcat(char str1[], char str2[])
{
	char str3[50];
	int i, j;
	for (i = 0; str1[i] != '\0'; i++)
	{
		str3[i] = str1[i];
	}
	for (j = 0; str2[j] != '\0'; j++)
	{
		str3[i + j] = str2[j];
	}
	str3[i + j] = '\0';
	cout << "\nConcatenated string: " << str3;
}
void strings::getsubstring(char str[], char substr[])
{
	int i;
	int count = 0;
	int m = getlength(str);
	int n = getlength(substr);
	for (i = 0; i <= m - n; i++)
	{
		int j = 0;
		for (j = 0; j < n; j++)
		{
			if (str[i + j] != substr[j])
				break;
		}
		if (j == n)
		{
			count++;
			j = 0;
		}
	}
	cout << "\nSubstring " << substr << " found in string " << str << " " << count << " times.";
}
void strings::getreverse(char* str)
{
	if (*str == '\0')
	{
		return;
	}
	else
	{
		getreverse(str + 1);
		cout << *str;
	}
}
bool strings::getpalindrome(char str[], int m, int n)
{
	if (m >= n)
		return true;
	if (str[m] != str[n])
		return false;
	return (str, m + 1, n - 1);
}
int main()
{
	char a[30], b[30], t;
	int i, len, choice;
	cout << "Enter first string: ";
	cin >> a;
	strings S;
	len = S.getlength(a);
	do
	{
		cout << "\nChoose operation to be performed on strings: 1-Length, 2-Concatenation,3-Substring,4-Reverse,5-Palindrome" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "\nLength of the string is " << len;
			break;
		case 2:
			cout << "\nEnter second string: ";
			cin >> b;
			S.getconcat(a, b);
			break;
		case 3:
			cout << "\nEnter substring: ";
			cin >> b;
			S.getsubstring(a, b);
			break;
		case 4:
			S.getreverse(a);
			break;
		case 5:
			if (S.getpalindrome(a, 0, len - 1))
				cout << "\nIt is a Palindrome";
			else
				cout << "\nNot a Palindrome";
			break;
		}
		cout << "\nDo you want to continue? (y/n) ";
		cin >> t;
	} while (t == 'y');
	return 0;
}
