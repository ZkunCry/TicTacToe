#include <iostream>
#include <Windows.h>
#include <ctime>
using namespace std;


enum Menu
{
    EXIT,
    PLAY
};

typedef struct TicTac
{
    int size=3;
    char board[3][3] = { { ' ',' ',' ', },
                     {' ', ' ', ' '},
                     {' ',' ',' '} };

}TicTac;

int win(TicTac& a)
{
    int index = 0;
    int countRow=0,countCol=0,countDiag=0;
    int countAiRow = 0, countAiCol = 0, countAiDiag = 0;
    for (int i = 0; i < a.size; i++) //Проверка строк, есть ли три в ряда подряд Крестиков и Ноликов
    {
        for (int j = 0; j < a.size; j++)
        {
            if (a.board[i][j] == 'x')
                countRow++;
            else if (a.board[i][j] == 'o')
                countAiRow++;
        }
        if (countRow == 3)
        {
            cout << "Вы выиграли!\n";
            return 1;
        }
        else if (countAiRow == 3)
        {
            cout << "Вы проиграли!\n";
            return -1;
        }
        else
        {
            countRow = 0;
            countAiRow = 0;
        }
    }
    for (int i = 0; i < a.size;i++) //Проверка столбцов 
    {
        for (int j = 0; j < a.size; j++)
        {
            if (a.board[j][i] == 'x')
                countCol++;
            else if (a.board[j][i] == 'o')
                countAiCol++;
        }
        if (countCol == 3)
        {
            cout << "Вы выиграли!\n";
            return 1;
        }
        else if (countAiCol == 3)
        {
            cout << "Вы проиграли!\n";
            return -1;
        }
        else
        {
            countCol = 0;
            countAiCol = 0;
        }
    }
    for (int i = 0; i < a.size; i++)//Проверка главной диагонали
    {

        if (a.board[index][i] == 'x')
            countDiag++;
        else if (a.board[index][i] == 'o')
            countAiDiag++;
        index++;
        if (countDiag == 3)
        {
            cout << "Вы выиграли!\n";
            return 1;
        }
        else if (countAiDiag == 3)
        {
            cout << "Вы проиграли!\n";
            return -1;
        }
    }
    index = 0;
    /*for (int i = 2; i >0; i++)//Проверка побочной диагонали
    {

        if (a.board[index][i] == 'x')
            countDiag++;
        else if (a.board[index][i] == 'o')
            countAiDiag++;
        if (countDiag == 3)
        {
            cout << "Вы выиграли!\n";
            return 1;
        }
        else if (countAiDiag == 3)
        {
            cout << "Вы проиграли!\n";
            return -1;
        }
        index++;
    }
    */
    
}
void outBoard(TicTac& a)
{
    for (int i = 0; i < a.size; i++)
    {
        cout << "|";
        for (int j = 0; j < a.size; j++)
            cout << a.board[i][j] << " ";
        cout << "|" << endl;
    }
}
void game(TicTac& a)
{
    srand(time(NULL));
    int indexX, indexY,count=0;
    while (count != 1)
    {
        for (int i = 0; i < a.size; i++)
        {
            for (int j = 0; j < a.size; j++)
            {
                indexX = rand() % 3;
                indexY = rand() % 3;
                if (a.board[indexX][indexY] == 'x')
                    continue;
                else if (a.board[indexX][indexY] == ' ')
                {
                    count++;
                    a.board[indexX][indexY] = 'o';
                    break;
                }
            }break;
        }
    }
    system("cls");
    outBoard(a);
}

int Fillboard(TicTac& a)
{
    int count=0;
    for (int q = 0; q < a.size; q++)
    {
        for (int t = 0; t < a.size; t++)
        {
            int x = 0, y = 0; //Координаты которые вводит пользователь
            cout << "Введите координаты клетки X и Y:\n";
            cin >> x >> y;
            x--;
            y--;
            if (a.board[x][y] != 'o')
                a.board[x][y] = 'x';
            else if(a.board[x][y] == 'o')
            {
                bool flag=1;
                while (flag)
                {
                    cout << "Это поле занято!\n";
                    cout << "Введите координаты клетки X и Y:\n";
                    cin >> x >> y;
                    x--;
                    y--;
                    if (a.board[x][y] != 'o')
                    {
                        flag = 0;
                        a.board[x][y] = 'x';
                    }
                }
            }
            count++;
            system("cls");
            for (int i = 0; i < a.size; i++)
            {
                cout << "|";
                for (int j = 0; j < a.size; j++)
                    cout << a.board[i][j] << " ";
                cout << "|" << endl;
            }
            if (count >= 3)
            {
                int result = 0;
                result =win(a);
                if (result == 1 || result == -1)
                    return 0;
            }
            game(a);
        }
    }
}
int main()
{
    system("chcp 1251 >null");
    TicTac a;
    int choose = 0;
    cin >> choose;
    do
    {
        switch (choose)
        {
        case EXIT:
            choose = 0;
            break;
        case PLAY:
            choose =Fillboard(a);
            break;
        }
    } while (choose != 0);
    return 0;
}