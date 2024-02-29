#include <iostream>
#include <conio.h>
#include <windows.h>
#include<vector>
#include<string>
#include <time.h>
#include <stdlib.h>
#include<fstream>

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
#define Bright_Yellow_new "\u001b[33;4m"

using namespace std;

struct Map_Components   // A data structure for the components in the game map with Initialization
{
    string name = "empty";
    int Health = 0;
    int damage = 0 ;
    int size = 1*1 ;
    string color = "Bright_cyan" ;
    string character = "[ ]";
};


bool Menu();    // function that displays the menu to the user
bool Game_Mode();   // function that allows the user to choose between two types of games
void Initializer_Basic(); // function for game preparation and initialization for Basic Mode
void Initializer_Advanced(); // function for game preparation and initialization for Advanced Mode
void positioning( vector <vector<Map_Components>>& map , int map_size , int &spaceship_health); // function that determines the position of elements in the map
void display( vector <vector<Map_Components>> map , int map_size ); // This function displays the game map
string Move_Spaceship( vector <vector<Map_Components>>& map , int map_size , int& Spaceship_position , int quorum_point , int point , int spaceship_health); //This function moves the spaceship left and right
void Move_Enemy_Spaceship( vector <vector<Map_Components>>& map , int map_size , int &spaceship_health );   // A function to move enemy spaceships
void Shoot( vector <vector<Map_Components>>& map , int map_size , int& Spaceship_position );    // A function to fire bullets
void is_dead( vector <vector<Map_Components>>& map , int map_size );    // This function is responsible for checking the existence of a map component
void Show_information(int map_size , int quorum_point , int point , int spaceship_health ); // This function displays game information
void save(vector <vector<Map_Components>> map , int map_size , int quorum_point , int point , int spaceship_health );   // A function that is responsible for storing information in a file

int main()
{
    while (Menu())
    {
        
    }

    return 0;
}

bool Menu()
{
    system("cls || clear");  // This function clears the console
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
            system("cls || clear");  // This function clears the console
            cerr << Red << "Invalid Selection !" << Reset <<endl ;  // In this line, if an invalid choice is made by the user, an error will be displayed on the console
            break;
        }
    } while (Invalid_Selection);
    return false;
}

bool Game_Mode()
{
    system("cls || clear");  // This function clears the console
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
            system("cls || clear");  // This function clears the console
            cerr << Red << "Invalid Selection !" << Reset <<endl ;  // In this line, if an invalid choice is made by the user, an error will be displayed on the console
            break;
        }
    } while (Invalid_Selection);
    return false;
}

void Initializer_Basic()
{
    system("cls || clear");  // This function clears the console
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
            system("cls || clear");  // This function clears the console
            cerr << Red << "Invalid size ! (Map size should be bigger than 15) " << Reset <<endl ;  // In this line, if an invalid choice is made by the user, an error will be displayed on the console
        }
    } while (Invalid_Selection);
    vector <vector<Map_Components>> map ;
    map.resize( map_size , vector<Map_Components> (map_size) ); // Creates a two-dimensional vector with the dimensions of map size * map size

    system("cls || clear");  // This function clears the console
    cout << "Enter the map size : " << map_size << endl ;
    cout << "Enter the quorum for the win : ";  // In these few lines, a quorum of points to win is received from the user
    int quorum_point;
    cin >> quorum_point;
    int Spaceship_position ;
    int point = 0 ;
    int spaceship_health ;
    positioning( map , map_size , spaceship_health);  // This function specifies the position of game elements
    while (true)    // just for test
    {
        display( map , map_size );  // This function displays the game map
        Show_information(map_size , quorum_point , point , spaceship_health );  // call the function that displays game information
        if (Move_Spaceship( map , map_size , Spaceship_position , quorum_point , point , spaceship_health)== "saved successfully")    // call the Move_Spaceship function
        {
            cout << Bright_Green << "Game saved !" << Reset ;
            break;
        }
        Move_Enemy_Spaceship( map , map_size , spaceship_health); // Calling a function to move enemy spaceships
        is_dead( map , map_size ); // Calling a function to check health of map map Components
        Shoot( map , map_size , Spaceship_position );   // Calling a function to fire bullets
        is_dead( map , map_size ); // Calling a function to check health of map map Components
        save(map , map_size , quorum_point , point , spaceship_health );    // Calling a function to save game data
    }
}

void Initializer_Advanced()
{
    system("cls || clear");  // This function clears the console
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
            system("cls || clear");  // This function clears the console
            cerr << Red << "Invalid size ! (Map size should be bigger than 15) " << Reset <<endl ;  // In this line, if an invalid choice is made by the user, an error will be displayed on the console
        }
    } while (Invalid_Selection);
    vector <vector<Map_Components>> map ;
    map.resize( map_size , vector<Map_Components> (map_size) ); // Creates a two-dimensional vector with the dimensions of map size * map size

    cout << "Enter the quorum for the win : ";  // In these few lines, a quorum of points to win is received from the user
    int quorum_point;
    cin >> quorum_point;

    Invalid_Selection = false;
    do
    {
        char Spaceship_Type ;
        string Spaceship_Type_name ;
        Invalid_Selection = false;
        cout << "Select the type of spaceship : " << endl   // In these few lines, we take the type of spaceship from the user
         << "1- spaceship 1" << endl
         << "2- spaceship 2" << endl
         << "3- spaceship 3" << endl ;
        Spaceship_Type = getch();
        switch (Spaceship_Type)
        {
        case '1':
            system("cls || clear");  // This function clears the console
            cout << "Select the type of spaceship : spaceship 1 " << endl ;
            Spaceship_Type_name = "spaceship 1" ;   // In this line, we assign the name of a type of spaceship to a string variable to be used in subsequent functions.
            break;

        case '2':
            system("cls || clear");  // This function clears the console
            cout << "Select the type of spaceship : spaceship 2 " << endl ;
            Spaceship_Type_name = "spaceship 2" ;   // In this line, we assign the name of a type of spaceship to a string variable to be used in subsequent functions.
            break;

        case '3':
            system("cls || clear");  // This function clears the console
            cout << "Select the type of spaceship : spaceship 3 " << endl ;
            Spaceship_Type_name = "spaceship 3" ;   // In this line, we assign the name of a type of spaceship to a string variable to be used in subsequent functions.
            break;

        default:
            Invalid_Selection = true;
            system("cls || clear");  // This function clears the console
            cerr << Red << "Invalid Selection !" << Reset <<endl ;  // In this line, if an invalid choice is made by the user, an error will be displayed on the console
            break;
        }
    } while (Invalid_Selection);
    cout << "Enter the map size : " << map_size << endl ;
    cout << "Enter the quorum for the win : " << quorum_point << endl; 
}

void positioning( vector <vector<Map_Components>>& map , int map_size  , int &spaceship_health)
{
    srand(time(0)); // A function that generates random numbers with an initial seed of time 0
    unsigned int row , column ;
    bool in_it = false ;
    for (size_t i = 0; i < (map_size - 1); i++) // In these few lines, if there is no native ship, a ship will be created
    {
        if (map[map_size - 1][i].name == "Spaceship")
        {
            in_it = true ;
            spaceship_health = map[map_size - 1][i].Health ;
            break;
        }
    }
    if (!in_it)
    {
        map[map_size - 1][(map_size - 1) / 2].name = "Spaceship" ;
        map[map_size - 1][(map_size - 1) / 2].Health = 3 ;
        map[map_size - 1][(map_size - 1) / 2].damage = 2147483647 ; // The largest possible value for an integer data type
        map[map_size - 1][(map_size - 1) / 2].size = 1 ;
        map[map_size - 1][(map_size - 1) / 2].color = "Bright_Green" ;
        map[map_size - 1][(map_size - 1) / 2].character = "[#]" ;

        spaceship_health = map[map_size - 1][(map_size - 1) / 2].Health ;
    }
    int Enemy_Type ;
    bool Invalid_position = false ;
    Enemy_Type = rand() % 4 ;   // This function generates random numbers between 0 and 3
    switch (Enemy_Type)     // This section selects the type of enemy to create in the map
    {
    case 0:     // In each section of the switch case, a type of enemy is created
        column = rand() % map_size ;
        map[0][column].name = "Dart" ;
        map[0][column].Health = 1 ;
        map[0][column].damage = 1 ;
        map[0][column].size = 1*1 ;
        map[0][column].color = "Bright_Cyan" ;
        map[0][column].character = "[*]" ;
        break;
    
    case 1:
        do
        {
        column = rand() % map_size ;
        if (column + 2 <= map_size )
        {
            for (size_t i = 0; i < 2; i++)
            {
                for (size_t j = 0; j < 2; j++)
                {
                    map[i][column + j].name = "Striker" ;
                    map[i][column + j].Health = 2 ;
                    map[i][column + j].damage = 1 ;
                    map[i][column + j].size = 2*2 ;
                    map[i][column + j].color = "Bright_Blue" ;
                    map[i][column + j].character = "[*]" ;
                } 
            }
        }
        else
        {
            Invalid_position = true ;
        }
        } while (Invalid_position);
        break;
    
    case 2:
        Invalid_position = false ;
        do
        {
        if (column + 3 <= map_size)
        {
            for (size_t i = 0; i < 3; i++)
            {
                for (size_t j = 0; j < 3; j++)
                {
                    map[i][column + j].name = "Wraith" ;
                    map[i][column + j].Health = 4 ;
                    map[i][column + j].damage = 1 ;
                    map[i][column + j].size = 3*3 ;
                    map[i][column + j].color = "Blue" ;
                    map[i][column + j].character = "[*]" ;
                } 
            }
        }
        else
        {
            Invalid_position = true ;
        }
        } while (Invalid_position);
        break;

    case 3:
        Invalid_position = false ;
        do
        {
        if (column + 4 <= map_size)
        {
            for (size_t i = 0; i < 4; i++)
            {
                for (size_t j = 0; j < 4; j++)
                {
                    map[i][column + j].name = "Banshee" ;
                    map[i][column + j].Health = 6 ;
                    map[i][column + j].damage = 1 ;
                    map[i][column + j].size = 4*4 ;
                    map[i][column + j].color = "Magenta" ;
                    map[i][column + j].character = "[*]" ;
                } 
            }
        }
        else
        {
            Invalid_position = true ;
        }
        } while (Invalid_position);
        break;
    }
}

void display( vector <vector<Map_Components>> map , int map_size )
{
    system("cls || clear");  // This function clears the console
    for (size_t i = 0; i < map_size; i++)
    {
        for (size_t j = 0; j < map_size; j++)
        {
            if (map[i][j].color == "Bright_Green")  // In the following conditions, the color for printing the map components is specified and they are displayed in the console
            {
                cout << Bright_Green << map[i][j].character << Reset ;
            }
            else if (map[i][j].color == "Bright_Cyan")
            {
                cout << Bright_Cyan << map[i][j].character << Reset ;
            }
            else if (map[i][j].color == "Bright_Blue")
            {
                cout << Bright_Blue << map[i][j].character << Reset ;
            }
            else if (map[i][j].color == "Blue")
            {
                cout << Blue << map[i][j].character << Reset ;
            }
            else if (map[i][j].color == "Magenta")
            {
                cout << Magenta << map[i][j].character << Reset ;
            }
            else if (map[i][j].color == "Bright_Red")
            {
                cout << Bright_Red << map[i][j].character << Reset ;
            }
            else
            {
                cout << White << map[i][j].character << Reset ;
            }
        }
        cout << endl;
    }
}

string Move_Spaceship( vector <vector<Map_Components>>& map , int map_size , int& Spaceship_position , int quorum_point , int point , int spaceship_health)
{
    int User_Selection ;
    User_Selection = getch();
    int row , colum ;    
    for (size_t i = 0 ; i < map_size ; i++) // In these few lines we find the position of the spaceship
    {
        if (map[map_size -1][i].name == "Spaceship" )
        {
            row = map_size - 1 ;
            colum = i ;
            Spaceship_position = colum ;
            break;
        }
    }
    switch (User_Selection)
    {
    case 100 :  // If we choose the letter D, we move to the right
        if ( (colum + 1 ) < map_size )  // This condition checks not to leave the game map
        {
            map[row][colum + 1].name = map[row][colum].name ;
            map[row][colum + 1].Health = map[row][colum].Health;
            map[row][colum + 1].damage = map[row][colum].damage ;
            map[row][colum + 1].size = map[row][colum].size ;
            map[row][colum + 1].color = map[row][colum].color ;
            map[row][colum + 1].character = map[row][colum].character ;

            map[row][colum].name = "empty";
            map[row][colum].Health = 0;
            map[row][colum].damage = 0 ;
            map[row][colum].size = 1*1 ;
            map[row][colum].color = "White" ;
            map[row][colum].character = "[ ]";
        }
        else
        {
            cerr << Red << "Invalid Move !" << Reset <<endl ;  // In this line, if an invalid move is made by the user, an error will be displayed on the console
            Sleep(200); //This function freezes the console for 200 milliseconds
        }
        return "The move was successful" ;
        break;
    
    case 97 :   // If we choose the letter A, we move to the left
        if ( colum - 1 >= 0 )   //// This condition checks not to leave the game map
        {
            map[row][colum - 1].name = map[row][colum].name ;
            map[row][colum - 1].Health = map[row][colum].Health;
            map[row][colum - 1].damage = map[row][colum].damage ;
            map[row][colum - 1].size = map[row][colum].size ;
            map[row][colum - 1].color = map[row][colum].color ;
            map[row][colum - 1].character = map[row][colum].character ;

            map[row][colum].name = "empty";
            map[row][colum].Health = 0;
            map[row][colum].damage = 0 ;
            map[row][colum].size = 1*1 ;
            map[row][colum].color = "White" ;
            map[row][colum].character = "[ ]";
        }
        else
        {
            cerr << Red << "Invalid Move !" << Reset <<endl ;  // In this line, if an invalid move is made by the user, an error will be displayed on the console
            Sleep(200); //This function freezes the console for 200 milliseconds
        }
        return "The move was successful" ;
        break;
    
    case 115 :
        save(map , map_size , quorum_point , point , spaceship_health );
        return "saved successfully" ;
        break;

    case 32 :
        int user_slection  ;
        do
        {
            system("cls || clear");  // This function clears the console
            cout << Bright_Yellow_new << "Press space to continue the game or press S to save" << Reset << endl ;
            user_slection = getch() ;
            if (user_slection == 115)
            {
                save(map , map_size , quorum_point , point , spaceship_health );
                return "saved successfully";
                break;
            }
        } while (user_slection != 32 && user_slection != 115 );
        break;

    default:
        cerr << Red << "Invalid Selection !" << Reset <<endl ;  // In this line, if an invalid choice is made by the user, an error will be displayed on the console        Sleep(200); //This function freezes the console for 200 milliseconds
        Sleep(200); //This function freezes the console for 200 milliseconds
        break;
    }
    return "The move was successful" ;
}

void Move_Enemy_Spaceship( vector <vector<Map_Components>>& map , int map_size , int &spaceship_health )
{
    // In the following few lines, by scrolling the vector from the bottom to the top, we move the enemy ships down if possible
    for (int i = (map_size - 1) ; i >= 0 ; i--)
    {
        for (int j = (map_size - 1); j >= 0; j--)
        {
            if (map[i][j].name == "Dart" || map[i][j].name == "Striker" || map[i][j].name == "Wraith" || map[i][j].name == "Banshee")
            {
                if ((i + 1) < map_size && map[i + 1][j].name == "Spaceship")    // In the following few lines, if the enemy spaceship hits our ship, we will destroy it and we will lose some of our health.
                {
                    for (int z = 0; z < map_size; z++)
                    {
                        for (int k = 0; k < map_size; k++)
                        {
                            if (map[z][k].name != "Spaceship" && map[z][k].name != "bullet")
                            {
                                map[z][k].name = "empty";
                                map[z][k].Health = 0;
                                map[z][k].damage = 0 ;
                                map[z][k].size = 1*1 ;
                                map[z][k].color = "White" ;
                                map[z][k].character = "[ ]";
                            }
                        }
                    }
                    map[i + 1][j].Health = map[i + 1][j].Health - 1 ; // In this line, we reduce one of the health of the spaceship
                    spaceship_health = map[i + 1][j].Health ;
                }
                else if( (i + 1) < map_size )
                {
                    // In the following few lines, if a bullet hits the space safe, we will reduce its health
                    if ( map[i+1][j].name == "bullet" ||  map[i][j].name == "bullet")
                    {
                        for (int z = 0; z < map_size; z++)
                        {
                            for (int k = 0; k < map_size; k++)
                            {
                                if (map[z][k].name == "Dart" || map[z][k].name == "Striker" || map[z][k].name == "Wraith" || map[z][k].name == "Banshee")
                                {
                                    map[z][k].Health = map[z][k].Health - 2;

                                }
                            }
                        }
                    }
                    map[i + 1][j].name = map[i][j].name ;
                    map[i + 1][j].Health = map[i][j].Health;
                    map[i + 1][j].damage = map[i][j].damage ;
                    map[i + 1][j].size = map[i][j].size ;
                    map[i + 1][j].color = map[i][j].color ;
                    map[i + 1][j].character = map[i][j].character ;

                    map[i][j].name = "empty";
                    map[i][j].Health = 0;
                    map[i][j].damage = 0 ;
                    map[i][j].size = 1*1 ;
                    map[i][j].color = "White" ;
                    map[i][j].character = "[ ]";
                }
                else
                {
                    map[i][j].name = "empty";
                    map[i][j].Health = 0;
                    map[i][j].damage = 0 ;
                    map[i][j].size = 1*1 ;
                    map[i][j].color = "White" ;
                    map[i][j].character = "[ ]";
                }
            }
        }
    }
}

void Shoot( vector <vector<Map_Components>>& map , int map_size , int& Spaceship_position )
{
    for (size_t i = 0; i < map_size ; i++)  // In the following few lines, if there is a bullet, and if possible, we move the bullet up
    {
        for (size_t j = 0; j < map_size; j++)
        {
            if (map[i][j].name == "bullet")
            {
                if( i > 0 && map[i-1][j].name == "empty" )   // If possible, we move the bullet up
                {
                    map[i - 1][j].name = map[i][j].name ;
                    map[i - 1][j].Health = map[i][j].Health;
                    map[i - 1][j].damage = map[i][j].damage ;
                    map[i - 1][j].size = map[i][j].size ;
                    map[i - 1][j].color = map[i][j].color ;
                    map[i - 1][j].character = map[i][j].character ;

                    map[i][j].name = "empty";
                    map[i][j].Health = 0;
                    map[i][j].damage = 0 ;
                    map[i][j].size = 1*1 ;
                    map[i][j].color = "White" ;
                    map[i][j].character = "[ ]";
                }
                else    // Otherwise (the bullet is on the edge of the map) we remove it from the map
                {
                    map[i][j].name = "empty";
                    map[i][j].Health = 0;
                    map[i][j].damage = 0 ;
                    map[i][j].size = 1*1 ;
                    map[i][j].color = "White" ;
                    map[i][j].character = "[ ]";
                }
            }
        }
    }
    // We create a bullet in a few lines below
    map[map_size - 2][Spaceship_position].name = "bullet" ;
    map[map_size - 2][Spaceship_position].Health = 0 ;
    map[map_size - 2][Spaceship_position].damage = 1 ; 
    map[map_size - 2][Spaceship_position].size = 1 ;
    map[map_size - 2][Spaceship_position].color = "Bright_Red" ;
    map[map_size - 2][Spaceship_position].character = "[^]" ;
}

void is_dead( vector <vector<Map_Components>>& map , int map_size )
{
    // In the following few lines, we search all the elements of the map and if the health is less than 0, we delete it
    for (size_t i = 0; i < map_size; i++)
    {
        for (size_t j = 0; j < map_size; j++)
        {
            if ( map[i][j].Health <= 0 && map[i][j].name != "bullet" )
            {
                map[i][j].name = "empty";
                map[i][j].Health = 0;
                map[i][j].damage = 0 ;
                map[i][j].size = 1*1 ;
                map[i][j].color = "White" ;
                map[i][j].character = "[ ]";
            }
        }   
    }
}

void Show_information(int map_size , int quorum_point , int point , int spaceship_health )
{
    // In a few lines below we display the information of the game
    cout << Yellow << "map size : " << map_size << "*" << map_size << Reset <<endl ;
    cout << Green << "health : " << Reset ;
    for (size_t i = 0; i < spaceship_health ; i++)
    {
        cout << Red << "*" << Reset ;
    }
    cout << endl ;
    cout << Bright_Cyan << "Quorum of points : " << quorum_point << Reset << endl ;
    cout << Bright_Blue << "point : " << point << Reset << endl ;
    cout << Bright_Yellow_new << "Select 'ecs' to exit and save" << Reset << endl ;
    cout << Bright_Yellow_new << "Press space to pause the game" << Reset << endl ;
}

void save(vector <vector<Map_Components>> map , int map_size , int quorum_point , int point , int spaceship_health )
{
    ofstream out("game.txt" , ios :: out ); // We create an output stream with the name "out"
    // In the following few lines, we save the game information in the file
    out << map_size << endl ;
    out << quorum_point << endl ;
    out << point << endl ;
    out << spaceship_health << endl ;
    for (size_t i = 0; i < map_size; i++)
    {
        for (size_t j = 0; j < map_size; j++)
        {
            if (map[i][j].name != "empty" )
            {
                out << map[i][j].name << " " << i << " " << j << " " << map[i][j].Health << endl ;
            }
        }
    }
    system("cls || clear");  // This function clears the console
    out.close();
}