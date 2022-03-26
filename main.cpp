// ------------------------ 2 Players Tic-Tac-Toe ----------------------

/*
coloring

X - 0
O - 1
borders - 2
won - 3
input - 4
num - 5

*/

#include <iostream>
#include <string>
#include <unistd.h>
#include <windows.h>

using namespace std;

bool run = false;

void board(char arr[3][3]);
char checkWin(char arr[3][3]);
char switch_turn(char);
void greet(char, char arr[3][3]);
void exit();

int colors[6] = {6, 3, 4, 2, 15, 5};

int main()
{
    int n;
    int places[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int num;
    char turn = 'X';
    char winner = ' ';
    char arr[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}};

    do
    {
        board(arr);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[4]);
        cout << "Enter Number to insert " << turn << " :- ";
        cin >> num;

        if (num == 1)
        {
            if (arr[0][0] == ' ')
            {
                arr[0][0] = turn;
            }
            else
            {
                cout << "~~~~~~~~~~~~~~~~~~ Invalid Choice ! ~~~~~~~~~~~~~~~~~~\n";
                sleep(2);
                continue;
            }
        }
        else if (num == 2)
        {
            if (arr[0][1] == ' ')
            {
                arr[0][1] = turn;
            }
            else
            {
                cout << "~~~~~~~~~~~~~~~~~~ Invalid Choice ! ~~~~~~~~~~~~~~~~~~\n";
                sleep(2);
                continue;
            }
        }
        else if (num == 3)
        {
            if (arr[0][2] == ' ')
            {
                arr[0][2] = turn;
            }
            else
            {
                cout << "~~~~~~~~~~~~~~~~~~ Invalid Choice ! ~~~~~~~~~~~~~~~~~~\n";
                sleep(2);
                continue;
            }
        }
        else if (num == 4)
        {
            if (arr[1][0] == ' ')
            {
                arr[1][0] = turn;
            }
            else
            {
                cout << "~~~~~~~~~~~~~~~~~~ Invalid Choice ! ~~~~~~~~~~~~~~~~~~\n";
                sleep(2);
                continue;
            }
        }
        else if (num == 5)
        {
            if (arr[1][1] == ' ')
            {
                arr[1][1] = turn;
            }
            else
            {
                cout << "~~~~~~~~~~~~~~~~~~ Invalid Choice ! ~~~~~~~~~~~~~~~~~~\n";
                sleep(2);
                continue;
            }
        }
        else if (num == 6)
        {
            if (arr[1][2] == ' ')
            {
                arr[1][2] = turn;
            }
            else
            {
                cout << "~~~~~~~~~~~~~~~~~~ Invalid Choice ! ~~~~~~~~~~~~~~~~~~\n";
                sleep(2);
                continue;
            }
        }
        else if (num == 7)
        {
            if (arr[2][0] == ' ')
            {
                arr[2][0] = turn;
            }
            else
            {
                cout << "~~~~~~~~~~~~~~~~~~ Invalid Choice ! ~~~~~~~~~~~~~~~~~~\n";
                sleep(2);
                continue;
            }
        }
        else if (num == 8)
        {
            if (arr[2][1] == ' ')
            {
                arr[2][1] = turn;
            }
            else
            {
                cout << "~~~~~~~~~~~~~~~~~~ Invalid Choice ! ~~~~~~~~~~~~~~~~~~\n";
                sleep(2);
                continue;
            }
        }
        else if (num == 9)
        {
            if (arr[2][2] == ' ')
            {
                arr[2][2] = turn;
            }
            else
            {
                cout << "~~~~~~~~~~~~~~~~~~ Invalid Choice ! ~~~~~~~~~~~~~~~~~~\n";
                sleep(2);
                continue;
            }
        }
        else
        {
            cout << "~~~~~~~~~~~~~~~~~~ Invalid Choice ! ~~~~~~~~~~~~~~~~~~\n";
            sleep(2);
            continue;
        }

        winner = checkWin(arr);
        if (winner == 'X' or winner == 'O')
        {
            break;
        }

        turn = switch_turn(turn);
    } while (winner != 'O' or winner != 'X');

    greet(winner, arr);

    return 0;
}

void exit()
{
    cout << "Exiting in 5 seconds !" << endl;
    for (int i = 5; i > 0; i--)
    {
        sleep(1);
    }
}

void greet(char winner, char arr[3][3])
{
    system("cls");
    board(arr);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[3]);
    cout << "Player " << winner << " Won !" << endl
         << endl;

    // Re - Play

    char choice;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[4]);
    cout << "Do you want to replay (y/n) :- ";
    cin >> choice;

    switch (choice)
    {
    case 'y':
        run = false;
        main();
        break;

    case 'n':
        exit();
        break;

    default:
        break;
    }
}

char switch_turn(char a)
{
    switch (a)
    {
    case 'X':
        return 'O';
        break;
    case 'O':
        return 'X';

    default:
        break;
    }
}

char checkWin(char arr[3][3])
{
    // side check
    if (arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2])
    {
        return arr[0][0];
    }
    if (arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2])
    {
        return arr[0][0];
    }
    else if (arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2])
    {
        return arr[1][0];
    }
    else if (arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2])
    {
        return arr[2][0];
    }

    // upside down check

    else if (arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0])
    {
        return arr[0][0];
    }
    else if (arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1])
    {
        return arr[0][1];
    }
    else if (arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2])
    {
        return arr[0][2];
    }

    // cross check

    else if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
    {
        return arr[0][0];
    }
    else if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
    {
        return arr[2][0];
    }
    else
    {
        return 'N';
    }
}

void board(char arr[3][3])
{
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[4]);
    cout << "--------------- Tic Tac Toe -------------" << endl;
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j < 3 and not(run))
            {
                switch (arr[i][j])
                {
                case ' ':
                    if (i == 0 and j == 0)
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[5]);
                        cout << "\t 1 ";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[2]);
                        cout << "|";
                        continue;
                    }
                    else if (i == 0 and j == 1)
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[5]);
                        cout << " 2 ";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[2]);
                        cout << "|";
                        continue;
                    }
                    else if (i == 0 and j == 2)
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[5]);
                        cout << " 3 ";
                        continue;
                    }
                    else if (i == 1 and j == 0)
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[5]);
                        cout << "\t 4 ";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[2]);
                        cout << "|";
                        continue;
                    }
                    else if (i == 1 and j == 1)
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[5]);
                        cout << " 5 ";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[2]);
                        cout << "|";
                        continue;
                    }
                    else if (i == 1 and j == 2)
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[5]);
                        cout << " 6 ";
                        continue;
                    }
                    else if (i == 2 and j == 0)
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[5]);
                        cout << "\t 7 ";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[2]);
                        cout << "|";
                        continue;
                    }
                    else if (i == 2 and j == 1)
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[5]);
                        cout << " 8 ";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[2]);
                        cout << "|";
                        continue;
                    }
                    else if (i == 2 and j == 2)
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[5]);
                        cout << " 9 ";
                        continue;
                    }
                    run = true;
                    break;
                }
            }
            if (j < 2)
            {
                switch (arr[i][j])
                {
                case ' ':
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[2]);
                    cout << "   |";
                    break;

                case 'X':
                    if (j==0){
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[0]);
                        cout << "\t X ";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[2]);
                        cout << "|";
                        break;
                    }
                    else
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[0]);
                        cout << " X ";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[2]);
                        cout << "|";
                        break;
                    }

                case 'O':
                    if (j==0){
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[1]);
                        cout << "\t O ";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[2]);
                        cout << "|";
                        break;
                    }
                    else
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[1]);
                        cout << " O ";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[2]);
                        cout << "|";
                        break;
                    }
                }
            }

            else
            {
                switch (arr[i][j])
                {
                case ' ':
                    cout << "   ";
                    break;

                case 'X':
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[0]);
                    cout << " X ";
                    break;

                case 'O':
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[1]);
                    cout << " O ";
                default:
                    break;
                }
            }
        }
        if (i < 2)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[2]);
            cout << "\n";
            cout << "\t___ ___ ___";
            cout << "\n\n";
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors[2]);
            cout << "\n";
            cout << "\n\n";
        }
    }
}