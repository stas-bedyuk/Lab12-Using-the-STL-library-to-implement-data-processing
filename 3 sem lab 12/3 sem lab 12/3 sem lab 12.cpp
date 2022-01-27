// 3 sem lab 12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>       
#include <string>         
#include "fstream"
using namespace std;
void case1()
{
    ofstream out1("qwza1", ios::app);
    try
    {
        if (!out1) throw 1;
        else cout << "\nFILE 'qwza1'IS OPEN FOR WRITING\n";
    }
    catch (int)
    {
        cout << "\nFILE IS NOT OPEN!!!\n";         //запись в файл
        return;
    }
    string str = ("There are two apples needle)");
    out1 << str << endl;
    out1.close();
}
void case3()
{
    ofstream out1("qwza1");
    try
    {
        if (!out1) throw 1;
        else cout << "\nFILE 'qwza1'IS OPEN FOR WRITING\n";
    }
    catch (int)
    {
        cout << "\nFILE IS NOT OPEN!!!\n";         //запись в файл
        return;
    }
    out1.close();
}
void case4(int a, int b)
{
    string str[30];
    int flag = 0;
    int i = 0;
    int j = 0;
    ifstream in("qwza1");
    try
    {
        if (!in) throw 1;
        else cout << "\nFILE 'qwza1'IS OPEN FOR READING\n\n";
    }
    catch (int)
    {
        cout << "\nFILE IS NOT OPEN!!!\n";
        exit(1);
    }
    while (in)
    {
        getline(in, str[i]);
        i++;
    }
    in.close();
    ofstream out("qwza1");
    try
    {
        if (!out) throw 1;
        else cout << "\nFILE 'qwza1'IS OPEN FOR WRITING\n";
    }
    catch (int)
    {
        cout << "\nFILE IS NOT OPEN!!!\n";         //запись в файл
        return;
    }
    while (j <= i)
    {
        if (j == b && flag == 0)
        {
            out << str[a] << endl;
            flag = 1;
            j--;
        }
        else
            out << str[j] << endl;
        j++;
    }
    out.close();
    if (flag == 0)
        cout << "\n\nUNCORRECT DATA (B)\n\n";
}
void case5()
{
    string str[30];
    int i = 0;
    int q = 0;
    int j = 0;
    int a;
    ifstream in("qwza1");
    try
    {
        if (!in) throw 1;
        else cout << "\nFILE 'qwza1'IS OPEN FOR READING\n\n";
    }
    catch (int)
    {
        cout << "\nFILE IS NOT OPEN!!!\n";
        exit(1);
    }
    while (in)
    {
        getline(in, str[i]);
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        if (q == 1) break;
        for (int k = j + 1; k < i + 1; k++)
        {
            a = k;
            if (str[j] == str[k])
            {
                q = 1;
                break;
            }
        }
    }
    in.close();
    ofstream out("qwza1");
    try
    {
        if (!out) throw 1;
        else cout << "\nFILE 'qwza1'IS OPEN FOR WRITING\n";
    }
    catch (int)
    {
        cout << "\nFILE IS NOT OPEN!!!\n";         //запись в файл
        return;
    }
    while (j <= i)
    {
        if (j != a)
        {
            out << str[j] << endl;
        }
        j++;
    }
    out.close();
    if (q == 0)
        cout << "\n\nNOT FIND!\n\n";
}
int main()
{
    //дописать данные в файл
    //меню
    //очистить файл
    //скопировать строку в указанную позицию
    //удаление дубликата
    //string str("There are two needles in this haystack with needles aneedle.");
    string str[5]
    { "There are two needles in this haystack with needles aneedle.",
        "dddd",
        "The needle aaa aaa bbb",
        "suhsjh dff zzz",
        " needle hufhueh needles qqq qqq qq qq qneedleq needle" };
    string str2;
    size_t found = 0;
    int i = 0;
    int j = 0;
    int ii = 0;
    ofstream out("qwza1");
    try
    {
        if (!out) throw 1;
        else cout << "\nFILE 'qwza1'IS OPEN FOR WRITING\n";
    }
    catch (int)
    {
        cout << "\nFILE IS NOT OPEN!!!\n";         //запись в файл
        return 1;
    }
    out << str[0] << endl;
    out << str[1] << endl;
    out << str[2] << endl;
    out << str[3] << endl;
    out << str[4] << endl;
    out.close();



    while (1)
    {
        cout << "CHOOSE THE ACTION: \n" << "1--ADD TO FILE\n" << "2--EXIT\n" << "3--CLEAR THE FILE\n" << "4--COPY A LINE TO A POSITION\n" << "5--DELETING A DUPLICATE\n" << "CHOOSE:  ";
        for (int i = 0; i < 1; i++)
        {
            try
            {
                cin >> j;
                if (!(j > -1 && j < 8)) throw 1;
            }
            catch (const exception& ex)
            {
                cout << "ERROR:Uncorrect enter!" << endl;
                cout << ex.what() << endl;
                cin.clear();
                cin.ignore(10, '\n');
                i--;
            }
            catch (int)
            {
                cout << "ERROR:Uncorrect enter!" << endl;
                cin.clear();
                cin.ignore(10, '\n');
                i--;
            }
        }
        switch (j)
        {
        case 1:
            case1();
            break;
        case 2:
            ii = 1;
            break;
        case 3:
            case3();
            break;
        case 4:
            int a, b;
            cout << "\nA: ";
            cin >> a;
            cout << "\nB: ";
            cin >> b;
            case4(a, b);
            break;
        case 5:
            case5();
            break;
        }
        if (ii == 1) break;
    }







    ofstream out1("result");
    try
    {
        if (!out1) throw 1;
        else cout << "\nFILE 'result'IS OPEN FOR WRITING\n\n";
    }
    catch (int)
    {
        cout << "\nFILE IS NOT OPEN!!!\n";         //запись в файл
        return 1;
    }

    ifstream in("qwza1");
    try
    {
        if (!in) throw 1;
        else cout << "\nFILE 'qwza1'IS OPEN FOR READING\n\n";
    }
    catch (int)
    {
        cout << "\nFILE IS NOT OPEN!!!\n";
        exit(1);
    }

    while (in)
    {
        int i = 0;
        int count = 0;
        getline(in, str2);
        while (found != string::npos)
        {
            found = str2.find("needle", found + 1, 6);
            if (found != string::npos)
            {
                i++;
                cout << " 'needle' found at position: " << found << '\n';
                out1 << " 'needle' found at position: " << found << '\n';
            }
        }
        found = 0;
        if (in && str2 != "")
        {
            cout << "Cout of words: " << i << endl;
            cout << "---------------------\n";
            out1 << "Cout of words: " << i << endl << "---------------------\n";
        }
    }
    in.close();
    out1.close();
    return 0;
}
