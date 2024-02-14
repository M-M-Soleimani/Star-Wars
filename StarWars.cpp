#include <iostream>
#include <conio.h>
#include <windows.h>

// Defining color codes to beautify the game
#define Black "\u001b[30m"
#define Red "\u001b[31m"
#define Green "\u001b[32m"
#define Yellow "\u001b[33m"
#define Blue "\u001b[34m"
#define Magenta "\u001b[35m"
#define Cyan "\u001b[36m"
#define White "\u001b[37m"
#define Reset "\u001b[0m"
#define Bright_Black "\u001b[30;1m"
#define Bright_Red "\u001b[31;1m"
#define Bright_Green "\u001b[32;1m"
#define Bright_Yellow "\u001b[33;1m"
#define Bright_Blue "\u001b[34;1m"
#define Bright_Magenta "\u001b[35;1m"
#define Bright_Cyan "\u001b[36;1m"
#define Bright_White "\u001b[37;1m"

using namespace std;

bool Menu();    // function that displays the menu to the user
bool Game_Mode();   // function that allows the user to choose between two types of games

int main()
{
    while (Menu())
    {
        /*code*/
    }

    return 0;
}

bool Menu()
{
    system("cls");  // This function clears the console
    bool Invalid_Selection = false;
    do
    {
        // In the next few lines, the menu will be displayed on the console
        cout << "1- Game Mode " << endl
         << "2- Continue Game " << endl
         << "3- Change SpacShip Character " << endl
         << "4- Save Game" << endl
         << "5- Description of SpaceShips " << endl
         << "6- History" << endl
         << "7- Exit " << endl;
        char user_selection;
        user_selection = getch();   // We get an option chosen by the user
        switch (user_selection)
        {
        case '1':
            if (Game_Mode())
            {
                return false;
            }
            else
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
            system("cls");  // This function clears the console
            cerr << Red << "Invalid Selection !" << Reset <<endl ;  // In this line, if an invalid choice is made by the user, an error will be displayed on the console
            break;
        }
    } while (Invalid_Selection);
    return false;
}

bool Game_Mode()
{
    system("cls");  // This function clears the console
    bool Invalid_Selection = false;
    do
    {
        // In the next few lines, the menu will be displayed on the console
        cout << "1- Basic Mode " << endl
         << "2- Advanced Mode " << endl
         << "3- Exit " << endl;
        char user_selection;
        user_selection = getch();   // We get an option chosen by the user
        switch (user_selection)
        {
        case '1':
            /* code */
            return true;
            break;

        case '2':
            /* code */
            return true;
            break;

        case '3':
            return false;
            break;

        default:
            Invalid_Selection = true;
            system("cls");  // This function clears the console
            cerr << Red << "Invalid Selection !" << Reset <<endl ;  // In this line, if an invalid choice is made by the user, an error will be displayed on the console
            break;
        }
    } while (Invalid_Selection);
    return false;
}