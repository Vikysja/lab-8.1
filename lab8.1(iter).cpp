// lab8.1(iter).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Квецко Вікторія
// Варіант 32

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int CountIncludes(char* str, char* letters);
char* Change(char* str, const char* fromPart, const char* toPart);

bool IncludeLetter(char* findIn, char letter);
int getIncludesIndex(char* findIn, const char* part, const int StartIndex);

int main()
{
	const int strLength = 101;

	char str[strLength];

	cout << "Enter string:" << endl;
	cin.getline(str, strLength - 1);

	char letters[] = "BASIC";

	cout << endl;

	cout << "String contained " << CountIncludes(str, letters)
		<< " letters of word: " << letters << endl << endl;

	char* dest = new char[strLength * 1.5];
	dest = Change(str, "BASIC", "Delphi");

	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;

	return 0;
}

int CountIncludes(char* str, char* letters)
{
	int k = 0;

	for (int i = 0; str[i] != '\0'; i++)
		if (IncludeLetter(letters, str[i]))
			k++;

	return k;
}

char* Change(char* str, const char* fromPart, const char* toPart)
{
	size_t len = strlen(str);
	size_t lenFromPart = strlen(fromPart);
	size_t lenToPart = strlen(toPart);

	if (len < lenFromPart)
		return str;

	char* temp = new char[len * (lenToPart - 1) / (lenFromPart - 1) + 1];
	char* t = temp;
	temp[0] = '\0';

	size_t i = 0;

	while (i < len && str[i + (lenFromPart - lenToPart)] != 0)
	{
		if (getIncludesIndex(str, fromPart, i) == i)
		{
			strcat(t, toPart);

			t += lenToPart;
			i += lenFromPart;
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
		}
	}


	*t++ = str[i++];
	*t++ = str[i++];
	*t = '\0';

	return temp;
}

#pragma region subProgram
int getIncludesIndex(char* findIn, const char* part, const int StartIndex)
{
	int j, k;
	for (int i = StartIndex; findIn[i] != '\0'; i++)
	{
		j = 0;
		k = i;

		while (part[j] != '\0')
		{
			if (findIn[k] == part[j] && findIn[k] != '\0')
			{
				j++;
				k++;
			}
			else
				break;
		}

		if (part[j] == '\0')
			return i;
	}

	return -1;
}

bool IncludeLetter(char* findIn, char letter)
{
	for (int i = 0; findIn[i] != '\0'; i++)
		if (findIn[i] == letter)
			return true;

	return false;
}
#pragma endregion
