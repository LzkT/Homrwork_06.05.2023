#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<int> z(const string& str)
{
    vector<int> z(str.length(), 0);

    for (int i = 1, left = 0, right = 0; i < str.length(); i++) {
        if (i <= right) {
            z[i] = min(z[i - left], right - i + 1);
        }

        while (i + z[i] < str.length()) {
            if (str[i + z[i]] == str[z[i]]) {
                z[i]++;
            }
            else {
                break;
            }
        }

        if (z[i] > 0 && i + z[i] - 1 > right) {
            left = i;
            right = i + z[i] - 1;
        }
    }

    return z;
}



int main() 
{
    setlocale(LC_ALL, "rus");

    string str, word;
    cout << "Введите основную строку: " << endl;
    cin >> str;
    str = str + ".";

    cout << "Введите подстроку для поиска: " << endl;
    cin >> word;

    vector<int> t = z(word + '#' + str);

    int leng = word.length();

    for (int i = 0; i < str.length(); i++) {
        if (t[leng + 1 + i] == leng) {
            cout << i << " ";
        }
    }
}