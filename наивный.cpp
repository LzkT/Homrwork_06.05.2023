#include <iostream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	string s, st;
	cout << "Введите основную строку: " << endl;
	cin >> s;
	s = s + ".";

	cout << "Введите подстроку для поиска: " << endl;
	cin >> st;

	int size1 = s.length();
	int size2 = st.length();

	bool f = false;

	for (int i = 0; i < size1 - size2 + 1; i++)
	{
		f = false;

		if (s[i] == st[0])
		{
			f = true;

			for (int j = 0; j < size2; j++)
			{
				if (s[j + i] != st[j])
				{
					f = false;
				};
			};

			if (f == true)
			{
				cout << i << " ";
			};
		};
	};
}


