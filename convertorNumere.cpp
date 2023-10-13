#include <iostream>
#include <cmath>
#include <string>
#include <list>
using namespace std;

string b2b10(string cn)
{
    int c = 0;
    long long int a = 0;
    for (int i = cn.length() -1; i >= 0; i--)
        if (cn[i] == '1')
            a += pow(2, c) * (cn[i] - '0'), c++;
        else
            c++;
    return to_string(a);
}

string b8b10(string cn)
{
    int c = 0;
    long long int a = 0;
    for (int i = cn.length() -1; i >= 0; i--)
            a += pow(8, c) * (cn[i] - '0'), c++;
    return to_string(a);
}

string b16b10(string cn)
{
    int c = 0, k;
    long long int a = 0;
    for (int i = cn.length() - 1; i >= 0; i--)
    {
        switch (cn[i])
        {
            case 'A':
            {
                a += pow(16, c) * 10;
                break;
            }
            case 'B':
            {
                a += pow(16, c) * 11;
                break;
            }
            case 'C':
            {
                a += pow(16, c) * 12;
                break;
            }
            case 'D':
            {
                a += pow(16, c) * 13;
                break;
            }
            case 'E':
            {
                a += pow(16, c) * 14;
                break;
            }
            case 'F':
            {
                a += pow(16, c) * 15;
                break;
            }
            default:
            {
                a += pow(16, c) * (cn[i] - '0');
                break;
            }
        }
        c++;
    }
    return to_string(a);
}

void b10b2(string cn)
{
    if (cn == "0")
        cout << 0;
    else
    {
        int p = 1;
        list<int> v;
        long long int n = stoi(cn);
        while (n)
        {
            v.push_front(n % 2);
            n /= 2;
        }
        for (auto i: v)
            cout << i;
    }
}

void b10b8(string cn)
{
    if (cn == "0")
        cout << 0;
    else
    {
        int p = 1;
        list<int> v;
        long long int n = stoi(cn);
        while (n)
        {
            v.push_front(n % 8);
            n /= 8;
        }
        for (auto i: v)
            cout << i;
    }
}

void b10b16(string cn)
{
    if (cn == "0")
        cout << 0;
    else
    {
        int p = 1;
        list<string> v;
        long long int n = stoi(cn);
        while (n)
        {
            switch (n % 16)
            {
                case 10:
                {
                    v.push_front("A");
                    break;
                }
                case 11:
                {
                    v.push_front("B");
                    break;
                }
                case 12:
                {
                    v.push_front("C");
                    break;
                }
                case 13:
                {
                    v.push_front("D");
                    break;
                }
                case 14:
                {
                    v.push_front("E");
                    break;
                }
                case 15:
                {
                    v.push_front("F");
                    break;
                }
                default:
                {
                    v.push_front(to_string(n % 16));
                    break;
                }
            }
            n /= 16;
        }
        for (auto i: v)
            cout << i;
    }
}

int main()
{
    string s, nB10;
    int n;
    cout << "Scrie numarul\n";
    cin >> s;
    cout << "Scrie baza numarului:\n";
    cin >> n;
    switch (n)
    {
        case 2:
        {
            nB10 = b2b10(s);
            break;
        }
        case 8:
        {
            nB10 = b8b10(s);
            break;
        }
        case 10:
        {
            nB10 = s;
            break;
        }
        case 16:
        {
            nB10 = b16b10(s);
            break;
        }
        default:
        {
            cout << "Eroare";
            return 0;
        }
    }
    cout << "Scrie baza in care vrei sa convertesti:\n";
    cin >> n;
    switch (n)
    {
        case 2:
        {
            b10b2(nB10);
            return 0;
        }
        case 8:
        {
            b10b8(nB10);
            return 0;
        }
        case 10:
        {
            cout << nB10;
            return 0;
        }
        case 16:
        {
            b10b16(nB10);
            break;
        }
        default:
        {
            cout << "Eroare";
            return 0;
        }
    }
}
