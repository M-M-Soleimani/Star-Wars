#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool Menu();

int main()
{
    while (Menu())
    {
        Menu();
    }
    
    return 0;
}

bool Menu()
{
    system("cls");
    cout << "1- Game Mode " << endl
         << "2- Continue Game " << endl
         << "3- Change SpacShip Character " << endl
         << "4- Save Game" << endl
         << "5- Description of SpaceShips " << endl
         << "6- History" << endl
         << "7- Exit " << endl;
    char user_selection;
    user_selection = getch();
    bool Invalid_Selection = false;
    do
    {
        switch (user_selection)
        {
        case '1':
            /*code*/
            return true;
            break;

        case '2':
            /*code*/
            return true;
            break;

        case '3':
            /*code*/
            return true;
            break;

        case '4':
            /*code*/
            return true;
            break;

        case '5':
            /*code*/
            return true;
            break;

        case '6':
            /*code*/
            return true;
            break;

        case '7':
            /*code*/
            return false;
            break;

        default:
            Invalid_Selection = true;
            break;
        }
    } while (Invalid_Selection);
    return false;
}