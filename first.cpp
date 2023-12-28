#include <iostream>
#include <string>

int main()
{
    using namespace std;

    int a1 = 20, a2 = 40;
    char a[a1][a2];
    string str = "";
    int rowNum = 18, colNum = 18, rowP = 1, rowM = 1, colP = 1, colM = 1;


    for(int i = 0; i < a1; i++)
    {
        for(int j = 0; j < a2; j++)
        {
            if((i >= 1 && j >= 1) && (i != (a1 - 1) && j != (a2 - 1)))
                a[i][j] = ' ';
            else
                a[i][j] = '#';
        }
    }

    do
    {
            for(int i = 0; i < a1; i++)
            {
                for(int j = 0; j < a2; j++)
                {
                    if(str == "w")
                    {
                        if(a[rowNum - rowM + rowP][colNum - colM + colP] == '#')
                        {
                            a[(rowNum - rowM + rowP) + 1][colNum - colM + colP] = ' ';
                            rowM = 1;
                        }
                        else
                            {
                                if(a[(rowNum - rowM + rowP) + 1][colNum - colM + colP] != '#')
                                {
                                    a[rowNum - rowM + rowP][colNum - colM + colP] = '*';
                                    a[(rowNum - rowM + rowP) + 1][colNum - colM + colP] = ' ';
                                }
                                else
                                    a[rowNum - rowM + rowP][colNum - colM + colP] = '*';
                            }
                    }
                    if(str == "s")
                    {
                        if(a[rowNum - rowM + rowP][colNum - colM + colP] == '#')
                            rowP = 1;
                        else
                            {
                                if(a[(rowNum - rowM + rowP) - 1][colNum - colM + colP] != '#')
                                {
                                    a[rowNum - rowM + rowP][colNum - colM + colP] = '*';
                                    a[(rowNum - rowM + rowP) - 1][colNum - colM + colP] = ' ';
                                }
                                else
                                    a[rowNum - rowM + rowP][colNum - colM + colP] = '*';
                            }
                    }
                    if(str == "a")
                    {
                        if(a[rowNum - rowM + rowP][colNum - colM + colP] == '#')
                            colM = -a2;
                        else
                            a[rowNum - rowM + rowP][colNum - colM + colP] = '*';
                    }
                    if(str == "d")
                    {
                        if(a[rowNum - rowM + rowP][colNum - colM + colP] == '#')
                            colP = 1;
                        else
                            a[rowNum - rowM + rowP][colNum - colM + colP] = '*';
                    }
                    cout << a[i][j];
                }
                cout << endl;
            }
            cout << "exit - exit, a - left, d - right, w - up, s - down\n";
            cin >> str;
            system("cls");
            if(!(str == "exit" || str == "a" || str == "d" || str == "s" || str == "w"))
                {
                    cout << "Incorrect symb.\n";
                    system("pause");
                    system("cls");
                }
            if(str == "w")
                {
                    ++rowM;
                }
            if(str == "s")
                {
                    ++rowP;
                }
            if(str == "a")
                {
                    ++colM;
                }
            if(str == "d")
                {
                    ++colP;
                }
    }
    while(str != "exit");

    return 0;
}
