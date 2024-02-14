#include <iostream>
#include <conio.h>
#include <windows.h>
#include<vector>
#include<string>

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

struct Map_Components   // A data structure for the components in the game map
{
    string name ;
    int Health ;
    int damage ;
};


bool Menu();    // function that displays the menu to the user
bool Game_Mode();   // function that allows the user to choose between two types of games
void Initializer_Basic(); // A function for game preparation and initialization for Basic Mode
void Initializer_Advanced(); // A function for game preparation and initialization for Advanced Mode

int main()
{
    while (Menu())
    {
        
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
            Initializer_Basic();
            return true;
            break;

        case '2':
            Initializer_Advanced();
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

void Initializer_Basic()
{
    system("cls");  // This function clears the console
    bool Invalid_Selection = false;
    int map_size ;
    do
    {
        Invalid_Selection = false;
        cout << "Enter the map size : " ;   // In these few lines, the dimensions of the playground are received from the user
        cin >> map_size ;
        if ( map_size <= 15 )
        {
            Invalid_Selection = true;
            system("cls");  // This function clears the console
            cerr << Red << "Invalid size ! (Map size should be bigger than 15) " << Reset <<endl ;  // In this line, if an invalid choice is made by the user, an error will be displayed on the console
        }
    } while (Invalid_Selection);
    vector <vector<Map_Components>> map ;
    map.resize( map_size , vector<Map_Components> (map_size) ); // Creates a two-dimensional vector with the dimensions of map size * map size

    system("cls");  // This function clears the console
    cout << "Enter the map size : " << map_size << endl ;
    cout << "Enter the quorum for the win : ";  // In these few lines, a quorum of points to win is received from the user
    int quorum_point;
    cin >> quorum_point;

}

void Initializer_Advanced()
{
    system("cls");  // This function clears the console
    bool Invalid_Selection = false;
    int map_size ;
    do
    {
        Invalid_Selection = false;
        cout << "Enter the map size : " ;   // In these few lines, the dimensions of the playground are received from the user
        cin >> map_size ;
        if ( map_size <= 15 )
        {
            Invalid_Selection = true;
            system("cls");  // This function clears the console
            cerr << Red << "Invalid size ! (Map size should be bigger than 15) " << Reset <<endl ;  // In this line, if an invalid choice is made by the user, an error will be displayed on the console
        }
    } while (Invalid_Selection);
    vector <vector<Map_Components>> map ;
    map.resize( map_size , vector<Map_Components> (map_size) ); // Creates a two-dimensional vector with the dimensions of map size * map size

    system("cls");  // This function clears the console
    cout << "Enter the map size : " << map_size << endl ;
    cout << "Enter the quorum for the win : ";  // In these few lines, a quorum of points to win is received from the user
    int quorum_point;
    cin >> quorum_point;

}