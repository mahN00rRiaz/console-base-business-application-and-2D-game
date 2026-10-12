#include <iostream>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y);
void printMaze();

int main()
{
    int x = 1, y = 1;
    system("cls");
    printMaze();

    while (y < 10)
    {
        gotoxy(x, y);
        cout << "P";
        
        Sleep(300);

        gotoxy(x, y);
        cout << " ";

        y = y + 1;
    }

    gotoxy(x, y);
    cout << "P";

    return 0;
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void printMaze()
{
    for (int i = 0; i < 20; i++) cout << "#";
    cout << endl;
    for (int j = 0; j < 10; j++) cout << "#                  #" << endl;
    for (int i = 0; i < 20; i++) cout << "#";
    cout << endl;
}