#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <fstream>
// #include<ncurses>

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

struct Map_Components // A data structure for the components in the game map with Initialization
{
    string name = "empty";
    int Health = 0;
    int damage = 0;
    int size = 1 * 1;
    string color = "White";
    string character = "[ ]";
};

bool Menu();                                                                                                                                                                                                                // function that displays the menu to the user
bool Game_Mode();                                                                                                                                                                                                           // function that allows the user to choose between two types of games
void Initializer_Basic();                                                                                                                                                                                                   // function for game preparation and initialization for Basic Mode
void Initializer_Advanced();                                                                                                                                                                                                // function for game preparation and initialization for Advanced Mode
void positioning(vector<vector<Map_Components>> &map, int map_size, int &spaceship_health, vector<string> &Enemies_history);                                                                                                // function that determines the position of elements in the map
void display(vector<vector<Map_Components>> map, int map_size);                                                                                                                                                             // This function displays the game map
string Move_Spaceship(vector<vector<Map_Components>> &map, int map_size, int &Spaceship_position, int quorum_point, double point, int spaceship_health, vector<string> &Enemies_history, int &level, int spaceship_type);   // This function moves the spaceship left and right
void Move_Enemy_Spaceship(vector<vector<Map_Components>> &map, int map_size, int &spaceship_health, double &point, vector<string> &Enemies_history, int spaceship_type);                                                    // A function to move enemy spaceships
void Shoot(vector<vector<Map_Components>> &map, int map_size, int &Spaceship_position, int spaceship_type);                                                                                                                 // A function to fire bullets
void is_dead(vector<vector<Map_Components>> &map, int map_size);                                                                                                                                                            // This function is responsible for checking the existence of a map component
void Show_information(int map_size, int quorum_point, double point, int spaceship_health);                                                                                                                                  // This function displays game information
void save(vector<vector<Map_Components>> map, int map_size, int quorum_point, double point, int spaceship_health, vector<string> &Enemies_history, int level, int spaceship_type);                                          // A function that is responsible for storing information in a file
void Continue_Game();                                                                                                                                                                                                       // A function that loads the previously unfinished game file
void Run_game_basic(vector<vector<Map_Components>> &map, int &map_size, int &quorum_point, double &point, int &spaceship_health, int &Spaceship_position, vector<string> &Enemies_history, int &level, int spaceship_type); // A function that has the task of running the gameplay
bool Enemy_is_in(vector<vector<Map_Components>> &map, int &map_size);                                                                                                                                                       // A function that checks if there is an enemy in the map
bool End_Game(int quorum_point, double point, int spaceship_health, vector<string> &Enemies_history, int level);                                                                                                            // This function checks if the game has been completed or not and displays the killed enemies
void user_level(int point, int &level);                                                                                                                                                                                     // A function that calculates the player's level
void Run_game_Advanced(vector<vector<Map_Components>> &map, int &map_size, int &quorum_point, double &point, int &spaceship_health, int &Spaceship_position, vector<string> &Enemies_history, int &level, int spaceship_type);// A function that has the task of running the gameplay
void positioning_Advanced(vector<vector<Map_Components>> &map, int map_size, int &spaceship_health, vector<string> &Enemies_history, int level);                                                                            // function that determines the position of elements in the map
void Save_History(int level, double point, int spaceship_health, int quorum_point);                                                                                                                                         // this function save history of game
void display_History();                                                                                                                                                                                                     // this function display history of game
void SpaceShips_Description();                                                                                                                                                                                              // This function displays the characteristics of ships

int main()
{
    while (Menu())
    {
    }
    return 0;
}

bool Menu()
{
    system("cls || clear"); // This function clears the console
    bool Invalid_Selection = false;
    do
    {
        // In the next few lines, the menu will be displayed on the console
        cout << "1- Game Mode " << endl
             << "2- Continue Game " << endl
             << "3- Description of SpaceShips " << endl
             << "4- History" << endl
             << "5- Exit " << endl;
        char user_selection;
        user_selection = getch(); // We get an option chosen by the user
        switch (user_selection)
        {
        case '1':
            if (Game_Mode())    // In this case, the game mode function is called
            {
                return false;
            }
            else
                return true;
            break;

        case '2':
            Continue_Game();    // The continue game function is called
            return true;
            break;

        case '3':
            SpaceShips_Description();   // The function of the description of spaceships is called
            return true;
            break;

        case '4':
            display_History();  // call the history function
            return true;
            break;

        case '5':
            return false;
            break;

        default:
            Invalid_Selection = true;
            system("cls || clear");                                // This function clears the console
            cerr << Red << "Invalid Selection !" << Reset << endl; // In this line, if an invalid choice is made by the user, an error will be displayed on the console
            break;
        }
    } while (Invalid_Selection);
    return false;
}

bool Game_Mode()
{
    system("cls || clear"); // This function clears the console
    bool Invalid_Selection = false;
    do
    {
        // In the next few lines, the menu will be displayed on the console
        cout << "1- Basic Mode " << endl
             << "2- Advanced Mode " << endl
             << "3- Exit " << endl;
        char user_selection;
        user_selection = getch(); // We get an option chosen by the user
        switch (user_selection)
        {
        case '1':
            Initializer_Basic();    // call the basic initializer function
            return true;
            break;

        case '2':
            Initializer_Advanced();  // // call the basic Advanced function
            return true;
            break;

        case '3':
            return false;
            break;

        default:
            Invalid_Selection = true;
            system("cls || clear");                                // This function clears the console
            cerr << Red << "Invalid Selection !" << Reset << endl; // In this line, if an invalid choice is made by the user, an error will be displayed on the console
            break;
        }
    } while (Invalid_Selection);
    return false;
}

void Initializer_Basic()
{
    system("cls || clear"); // This function clears the console
    bool Invalid_Selection = false;
    int map_size;
    do
    {
        Invalid_Selection = false;
        cout << "Enter the map size : "; // In these few lines, the dimensions of the playground are received from the user
        cin >> map_size;
        if (map_size <= 15)
        {
            Invalid_Selection = true;
            system("cls || clear");  // This function clears the console
            cerr << Red << "Invalid size ! (Map size should be bigger than 15) " << Reset << endl; // In this line, if an invalid choice is made by the user, an error will be displayed on the console
        }
    } while (Invalid_Selection);
    vector<vector<Map_Components>> map;
    map.resize(map_size, vector<Map_Components>(map_size)); // Creates a two-dimensional vector with the dimensions of map size * map size

    system("cls || clear"); // This function clears the console
    cout << "Enter the map size : " << map_size << endl;
    cout << "Enter the quorum for the win : "; // In these few lines, a quorum of points to win is received from the user
    int quorum_point;
    cin >> quorum_point;
    double point = 0;
    int spaceship_health;
    int Spaceship_position;
    int level;
    int Spaceship_type = 1;
    vector<string> Enemies_history;
    Run_game_basic(map, map_size, quorum_point, point, spaceship_health, Spaceship_position, Enemies_history, level, Spaceship_type); // Calling the run game function
}

void Initializer_Advanced()
{
    system("cls || clear"); // This function clears the console
    bool Invalid_Selection = false;
    int map_size;
    do
    {
        Invalid_Selection = false;
        cout << "Enter the map size : "; // In these few lines, the dimensions of the playground are received from the user
        cin >> map_size;
        if (map_size <= 15)
        {
            Invalid_Selection = true;
            system("cls || clear");     // This function clears the console
            cerr << Red << "Invalid size ! (Map size should be bigger than 15) " << Reset << endl; // In this line, if an invalid choice is made by the user, an error will be displayed on the console
        }
    } while (Invalid_Selection);
    vector<vector<Map_Components>> map;
    map.resize(map_size, vector<Map_Components>(map_size)); // Creates a two-dimensional vector with the dimensions of map size * map size

    cout << "Enter the quorum for the win : "; // In these few lines, a quorum of points to win is received from the user
    int quorum_point;
    cin >> quorum_point;
    int spaceship_type;
    Invalid_Selection = false;
    do
    {
        string Spaceship_Type_name;
        Invalid_Selection = false;
        // In these few lines, we take the type of spaceship from the user
        cout << "Select the type of spaceship : " << endl 
             << "1- spaceship 1" << endl
             << "2- spaceship 2" << endl
             << "3- spaceship 3" << endl;
        spaceship_type = getch() - 48;
        switch (spaceship_type)
        {
        case 1:
            system("cls || clear"); // This function clears the console
            cout << "Select the type of spaceship : spaceship 1 " << endl;
            Spaceship_Type_name = "spaceship 1"; // In this line, we assign the name of a type of spaceship to a string variable to be used in subsequent functions.
            break;

        case 2:
            system("cls || clear"); // This function clears the console
            cout << "Select the type of spaceship : spaceship 2 " << endl;
            Spaceship_Type_name = "spaceship 2"; // In this line, we assign the name of a type of spaceship to a string variable to be used in subsequent functions.
            break;

        case 3:
            system("cls || clear"); // This function clears the console
            cout << "Select the type of spaceship : spaceship 3 " << endl;
            Spaceship_Type_name = "spaceship 3"; // In this line, we assign the name of a type of spaceship to a string variable to be used in subsequent functions.
            break;

        default:
            Invalid_Selection = true;
            system("cls || clear");    // This function clears the console
            cerr << Red << "Invalid Selection !" << Reset << endl; // In this line, if an invalid choice is made by the user, an error will be displayed on the console
            break;
        }
    } while (Invalid_Selection);
    cout << "Enter the map size : " << map_size << endl;
    cout << "Enter the quorum for the win : " << quorum_point << endl;
    double point = 0;
    int spaceship_health;
    int Spaceship_position;
    int level;
    vector<string> Enemies_history;
    Run_game_Advanced(map, map_size, quorum_point, point, spaceship_health, Spaceship_position, Enemies_history, level, spaceship_type); // Calling the run game function
}

void positioning(vector<vector<Map_Components>> &map, int map_size, int &spaceship_health, vector<string> &Enemies_history)
{
    srand(time(0)); // A function that generates random numbers with an initial seed of time 0
    unsigned int row, column;
    bool in_it = false;
    for (size_t i = 0; i < map_size; i++) // In these few lines, if there is no native ship, a ship will be created
    {
        if (map[map_size - 1][i].name == "Spaceship")
        {
            in_it = true;
            spaceship_health = map[map_size - 1][i].Health;
            break;
        }
    }
    if (!in_it)
    {
        map[map_size - 1][(map_size - 1) / 2].name = "Spaceship";
        map[map_size - 1][(map_size - 1) / 2].Health = 3;
        map[map_size - 1][(map_size - 1) / 2].damage = 2147483647; // The largest possible value for an integer data type
        map[map_size - 1][(map_size - 1) / 2].size = 1;
        map[map_size - 1][(map_size - 1) / 2].color = "Bright_Green";
        map[map_size - 1][(map_size - 1) / 2].character = "[#]";

        spaceship_health = map[map_size - 1][(map_size - 1) / 2].Health;
    }
    int Enemy_Type;
    bool Invalid_position = false;
    Enemy_Type = rand() % 4; // This function generates random numbers between 0 and 3
    switch (Enemy_Type)      // This section selects the type of enemy to create in the map
    {
    case 0: // In each section of the switch case, a type of enemy is created
        column = rand() % map_size;
        map[0][column].name = "Dart";
        map[0][column].Health = 1;
        map[0][column].damage = 1;
        map[0][column].size = 1 * 1;
        map[0][column].color = "Bright_Cyan";
        map[0][column].character = "[*]";
        Enemies_history.push_back("Dart");
        break;

    case 1:
        do
        {
            Invalid_position = false;
            column = rand() % map_size;
            if (column + 2 <= map_size)
            {
                for (size_t i = 0; i < 2; i++)
                {
                    for (size_t j = 0; j < 2; j++)
                    {
                        map[i][column + j].name = "Striker";
                        map[i][column + j].Health = 2;
                        map[i][column + j].damage = 1;
                        map[i][column + j].size = 2 * 2;
                        map[i][column + j].color = "Bright_Blue";
                        map[i][column + j].character = "[*]";
                    }
                }
            }
            else
            {
                Invalid_position = true;
            }
        } while (Invalid_position);
        Enemies_history.push_back("Striker");
        break;

    case 2:
        do
        {
            Invalid_position = false;
            column = rand() % map_size;
            if (column + 3 <= map_size)
            {
                for (size_t i = 0; i < 3; i++)
                {
                    for (size_t j = 0; j < 3; j++)
                    {
                        map[i][column + j].name = "Wraith";
                        map[i][column + j].Health = 4;
                        map[i][column + j].damage = 1;
                        map[i][column + j].size = 3 * 3;
                        map[i][column + j].color = "Blue";
                        map[i][column + j].character = "[*]";
                    }
                }
            }
            else
            {
                Invalid_position = true;
            }
        } while (Invalid_position);
        Enemies_history.push_back("Wraith");
        break;

    case 3:
        do
        {
            Invalid_position = false;
            column = rand() % map_size;
            if (column + 4 <= map_size)
            {
                for (size_t i = 0; i < 4; i++)
                {
                    for (size_t j = 0; j < 4; j++)
                    {
                        map[i][column + j].name = "Banshee";
                        map[i][column + j].Health = 6;
                        map[i][column + j].damage = 1;
                        map[i][column + j].size = 4 * 4;
                        map[i][column + j].color = "Magenta";
                        map[i][column + j].character = "[*]";
                    }
                }
            }
            else
            {
                Invalid_position = true;
            }
        } while (Invalid_position);
        Enemies_history.push_back("Banshee");
        break;
    }
}

void display(vector<vector<Map_Components>> map, int map_size)
{
    system("cls || clear"); // This function clears the console
    for (size_t i = 0; i < map_size; i++)
    {
        for (size_t j = 0; j < map_size; j++)
        {
            if (map[i][j].color == "Bright_Green") // In the following conditions, the color for printing the map components is specified and they are displayed in the console
            {
                cout << Bright_Green << map[i][j].character << Reset;
            }
            else if (map[i][j].color == "Bright_Cyan")
            {
                cout << Bright_Cyan << map[i][j].character << Reset;
            }
            else if (map[i][j].color == "Bright_Blue")
            {
                cout << Bright_Blue << map[i][j].character << Reset;
            }
            else if (map[i][j].color == "Blue")
            {
                cout << Blue << map[i][j].character << Reset;
            }
            else if (map[i][j].color == "Magenta")
            {
                cout << Magenta << map[i][j].character << Reset;
            }
            else if (map[i][j].color == "Bright_Red")
            {
                cout << Bright_Red << map[i][j].character << Reset;
            }
            else
            {
                cout << White << map[i][j].character << Reset;
            }
        }
        cout << endl;
    }
}

string Move_Spaceship(vector<vector<Map_Components>> &map, int map_size, int &Spaceship_position, int quorum_point, double point, int spaceship_health, vector<string> &Enemies_history, int &level, int spaceship_type)
{
    int User_Selection;
    User_Selection = getch();
    int row, colum;
    for (size_t i = 0; i < map_size; i++) // In these few lines we find the position of the spaceship
    {
        if (map[map_size - 1][i].name == "Spaceship")
        {
            row = map_size - 1;
            colum = i;
            Spaceship_position = colum;
            break;
        }
    }
    switch (User_Selection)
    {
    case 100:                       
        // If we choose the letter D, we move to the right
        if ((colum + 1) < map_size) // This condition checks not to leave the game map
        {
            map[row][colum + 1].name = map[row][colum].name;
            map[row][colum + 1].Health = map[row][colum].Health;
            map[row][colum + 1].damage = map[row][colum].damage;
            map[row][colum + 1].size = map[row][colum].size;
            map[row][colum + 1].color = map[row][colum].color;
            map[row][colum + 1].character = map[row][colum].character;

            map[row][colum].name = "empty";
            map[row][colum].Health = 0;
            map[row][colum].damage = 0;
            map[row][colum].size = 1 * 1;
            map[row][colum].color = "White";
            map[row][colum].character = "[ ]";
        }
        else
        {
            cerr << Red << "Invalid Move !" << Reset << endl; // In this line, if an invalid move is made by the user, an error will be displayed on the console
            Sleep(200);     // This function freezes the console for 200 milliseconds
        }
        return "The move was successful";
        break;

    case 97:                
        // If we choose the letter A, we move to the left
        if (colum - 1 >= 0) //// This condition checks not to leave the game map
        {
            map[row][colum - 1].name = map[row][colum].name;
            map[row][colum - 1].Health = map[row][colum].Health;
            map[row][colum - 1].damage = map[row][colum].damage;
            map[row][colum - 1].size = map[row][colum].size;
            map[row][colum - 1].color = map[row][colum].color;
            map[row][colum - 1].character = map[row][colum].character;

            map[row][colum].name = "empty";
            map[row][colum].Health = 0;
            map[row][colum].damage = 0;
            map[row][colum].size = 1 * 1;
            map[row][colum].color = "White";
            map[row][colum].character = "[ ]";
        }
        else
        {
            cerr << Red << "Invalid Move !" << Reset << endl; // In this line, if an invalid move is made by the user, an error will be displayed on the console
            Sleep(200);   // This function freezes the console for 200 milliseconds
        }
        return "The move was successful";
        break;

    case 115:
        // If you press the S key, you will remain without moving
        break;

    case 27:    // By pressing the esc key, the game is saved and the program is closed
        save(map, map_size, quorum_point, point, spaceship_health, Enemies_history, level, spaceship_type);
        Save_History(level, point, spaceship_health, quorum_point);
        return "saved successfully";
        break;

    case 32:
        // In the next few lines, the game will be saved by pressing the space bar, then if you press the S key, the game will be saved and the game will be closed.
        int user_slection;
        do
        {
            system("cls || clear"); // This function clears the console
            cout << Bright_Yellow_new << "Press space to continue the game or press S to save" << Reset << endl;
            user_slection = getch();
            if (user_slection == 115)
            {
                save(map, map_size, quorum_point, point, spaceship_health, Enemies_history, level, spaceship_type);
                Save_History(level, point, spaceship_health, quorum_point);
                return "saved successfully";
                break;
            }
        } while (user_slection != 32 && user_slection != 115);
        return "play";
        break;

    default:
        cerr << Red << "Invalid Selection !" << Reset << endl; // In this line, if an invalid choice is made by the user, an error will be displayed on the console        
        Sleep(200);   // This function freezes the console for 200 milliseconds
        break;
    }
    return "The move was successful";
}

void Move_Enemy_Spaceship(vector<vector<Map_Components>> &map, int map_size, int &spaceship_health, double &point, vector<string> &Enemies_history, int spaceship_type)
{
    // In the following few lines, by scrolling the vector from the bottom to the top, we move the enemy ships down if possible
    for (int i = (map_size - 1); i >= 0; i--)
    {
        for (int j = (map_size - 1); j >= 0; j--)
        {
            if (map[i][j].name == "Dart" || map[i][j].name == "Striker" || map[i][j].name == "Wraith" || map[i][j].name == "Banshee")
            {
                if ((i + 1) < map_size && map[i + 1][j].name == "Spaceship") // In the following few lines, if the enemy spaceship hits our ship, we will destroy it and we will lose some of our health.
                {
                    for (int z = 0; z < map_size; z++)
                    {
                        for (int k = 0; k < map_size; k++)
                        {
                            if (map[z][k].name != "Spaceship" && map[z][k].name != "bullet")
                            {
                                map[z][k].name = "empty";
                                map[z][k].Health = 0;
                                map[z][k].damage = 0;
                                map[z][k].size = 1 * 1;
                                map[z][k].color = "White";
                                map[z][k].character = "[ ]";
                            }
                        }
                    }
                    map[i + 1][j].Health = map[i + 1][j].Health - 1; // In this line, we reduce one of the health of the spaceship
                    spaceship_health = map[i + 1][j].Health;
                }
                else if ((i + 1) < map_size)
                {
                    // In the following few lines, if a bullet hits the space safe, we will reduce its health
                    bool is_hit = false;
                    if (map[i + 1][j].name == "bullet" || map[i][j].name == "bullet")
                    {
                        for (int z = 0; z < map_size; z++)
                        {
                            for (int k = 0; k < map_size; k++)
                            {
                                if (map[z][k].name == "Dart" || map[z][k].name == "Striker" || map[z][k].name == "Wraith" || map[z][k].name == "Banshee")
                                {
                                    map[z][k].Health = map[z][k].Health - (spaceship_type * 2);
                                    is_hit = true;
                                }
                            }
                        }
                    }
                    if (is_hit)
                    {
                        int i = Enemies_history.size();
                        if (Enemies_history[i - 1] == "Dart")
                        {
                            point += 2;
                        }
                        else if (Enemies_history[i - 1] == "Striker")
                        {
                            point += 4;
                        }
                        else if (Enemies_history[i - 1] == "Wraith")
                        {
                            point += 4.5;
                        }
                        else if (Enemies_history[i - 1] == "Banshee")
                        {
                            point += (double)16 / 3;
                        }
                    }

                    map[i + 1][j].name = map[i][j].name;
                    map[i + 1][j].Health = map[i][j].Health;
                    map[i + 1][j].damage = map[i][j].damage;
                    map[i + 1][j].size = map[i][j].size;
                    map[i + 1][j].color = map[i][j].color;
                    map[i + 1][j].character = map[i][j].character;

                    map[i][j].name = "empty";
                    map[i][j].Health = 0;
                    map[i][j].damage = 0;
                    map[i][j].size = 1 * 1;
                    map[i][j].color = "White";
                    map[i][j].character = "[ ]";
                }
                else
                {
                    map[i][j].name = "empty";
                    map[i][j].Health = 0;
                    map[i][j].damage = 0;
                    map[i][j].size = 1 * 1;
                    map[i][j].color = "White";
                    map[i][j].character = "[ ]";
                }
            }
        }
    }
}

void Shoot(vector<vector<Map_Components>> &map, int map_size, int &Spaceship_position, int spaceship_type)
{
    for (size_t i = 0; i < map_size; i++) // In the following few lines, if there is a bullet, and if possible, we move the bullet up
    {
        for (size_t j = 0; j < map_size; j++)
        {
            if (map[i][j].name == "bullet")
            {
                if (i > 0 && map[i - 1][j].name == "empty") // If possible, we move the bullet up
                {
                    map[i - 1][j].name = map[i][j].name;
                    map[i - 1][j].Health = map[i][j].Health;
                    map[i - 1][j].damage = map[i][j].damage;
                    map[i - 1][j].size = map[i][j].size;
                    map[i - 1][j].color = map[i][j].color;
                    map[i - 1][j].character = map[i][j].character;

                    map[i][j].name = "empty";
                    map[i][j].Health = 0;
                    map[i][j].damage = 0;
                    map[i][j].size = 1 * 1;
                    map[i][j].color = "White";
                    map[i][j].character = "[ ]";
                }
                else // Otherwise (the bullet is on the edge of the map) we remove it from the map
                {
                    map[i][j].name = "empty";
                    map[i][j].Health = 0;
                    map[i][j].damage = 0;
                    map[i][j].size = 1 * 1;
                    map[i][j].color = "White";
                    map[i][j].character = "[ ]";
                }
            }
        }
    }
    // We create a bullet in a few lines below
    map[map_size - 2][Spaceship_position].name = "bullet";
    map[map_size - 2][Spaceship_position].Health = 0;
    map[map_size - 2][Spaceship_position].damage = spaceship_type;
    map[map_size - 2][Spaceship_position].size = 1;
    map[map_size - 2][Spaceship_position].color = "Bright_Red";
    map[map_size - 2][Spaceship_position].character = "[^]";
}

void is_dead(vector<vector<Map_Components>> &map, int map_size)
{
    // In the following few lines, we search all the elements of the map and if the health is less than 0, we delete it
    for (size_t i = 0; i < map_size; i++)
    {
        for (size_t j = 0; j < map_size; j++)
        {
            if (map[i][j].Health <= 0 && map[i][j].name != "bullet")
            {
                map[i][j].name = "empty";
                map[i][j].Health = 0;
                map[i][j].damage = 0;
                map[i][j].size = 1 * 1;
                map[i][j].color = "White";
                map[i][j].character = "[ ]";
            }
        }
    }
}

void Show_information(int map_size, int quorum_point, double point, int spaceship_health, int level)
{
    // In a few lines below we display the information of the game
    cout << Yellow << "map size : " << map_size << "*" << map_size << Reset << endl;
    cout << Green << "health : " << Reset;
    for (size_t i = 0; i < spaceship_health; i++)
    {
        cout << Red << "*" << Reset;
    }
    cout << endl;
    cout << Bright_Cyan << "Quorum of points : " << quorum_point << Reset << endl;
    cout << Bright_Blue << "point : " << point << Reset << endl;
    cout << Bright_Yellow << "level : " << level << Reset << endl;
    cout << Bright_Yellow_new << "Select 'ecs' to exit and save" << Reset << endl;
    cout << Bright_Yellow_new << "Press space to pause the game" << Reset << endl;
}

void save(vector<vector<Map_Components>> map, int map_size, int quorum_point, double point, int spaceship_health, vector<string> &Enemies_history, int level, int spaceship_type)
{
    ofstream out("game.txt", ios ::out); // We create an output stream with the name "out"
    // In the following few lines, we save the game information in the file
    out << map_size << endl;
    out << quorum_point << endl;
    out << point << endl;
    out << spaceship_health << endl;
    out << level << endl;
    out << spaceship_type << endl;
    out << Enemies_history.size() << endl;
    for (size_t i = 0; i < Enemies_history.size(); i++)
    {
        out << Enemies_history[i] << " ";
    }
    out << endl;
    for (size_t i = 0; i < map_size; i++)
    {
        for (size_t j = 0; j < map_size; j++)
        {
            if (map[i][j].name != "empty")
            {
                out << i << " " << j << " " << map[i][j].name << " " << map[i][j].Health << " " << map[i][j].character << " " << map[i][j].color << " " << map[i][j].damage << " " << map[i][j].size << endl;
            }
        }
    }
    system("cls || clear"); // This function clears the console
    out.close();
}

void Continue_Game()
{
    vector<vector<Map_Components>> map;
    int map_size, quorum_point, spaceship_health;
    int i, j;
    double point;
    int level;
    int Spaceship_position;
    int spaceship_type;
    ifstream in; // We create an input stream with the name "in"
    in.open("game.txt");
    if (!in.is_open()) // If there is no appropriate error file, it will be displayed
    {
        cerr << Red << "Error opening file !" << Reset << endl;
        Sleep(1000);
    }
    else // In the following few lines, we read the game information from the file
    {
        in >> map_size >> quorum_point >> point >> spaceship_health;
        int Enemies_history_size;
        in >> level;
        in >> spaceship_type;
        in >> Enemies_history_size;
        vector<string> Enemies_history;
        Enemies_history.resize(Enemies_history_size);
        for (size_t i = 0; i < Enemies_history_size; i++)
        {
            in >> Enemies_history[i];
        }
        map.resize(map_size, vector<Map_Components>(map_size));   // Creates a two-dimensional vector with the dimensions of map size * map size
        while (in >> i >> j >> map[i][j].name >> map[i][j].Health >> map[i][j].character >> map[i][j].color >> map[i][j].damage >> map[i][j].size) // Read them as long as there is information in the file
        {
            if (map[i][j].name == "Spaceship")
            {
                Spaceship_position = j;
            }
        }
        if (point >= quorum_point || spaceship_health <= 0)
        {
            cerr << Red << "You can not continue the game that has ended !" << Reset << endl;
            Sleep(1000);
        }
        else
        {
            Run_game_basic(map, map_size, quorum_point, point, spaceship_health, Spaceship_position, Enemies_history, level, spaceship_type); // Calling the run game function
        }
        in.close();
    }
}

void Run_game_basic(vector<vector<Map_Components>> &map, int &map_size, int &quorum_point, double &point, int &spaceship_health, int &Spaceship_position, vector<string> &Enemies_history, int &level, int spaceship_type)
{
    while (true && !End_Game(quorum_point, point, spaceship_health, Enemies_history, level)) // just for test
    {
        if (!Enemy_is_in(map, map_size))
        {
            positioning(map, map_size, spaceship_health, Enemies_history); // This function specifies the position of game elements
        }
        display(map, map_size);    // This function displays the game map
        Show_information(map_size, quorum_point, point, spaceship_health, level);     // call the function that displays game information
        string temp = Move_Spaceship(map, map_size, Spaceship_position, quorum_point, point, spaceship_health, Enemies_history, level, spaceship_type);
        if (temp == "saved successfully") // call the Move_Spaceship function
        {
            cout << Bright_Green << "Game saved !" << Reset;
            break;
        }
        else if ( temp == "play")
        {
            continue;
        }
        else
        Move_Enemy_Spaceship(map, map_size, spaceship_health, point, Enemies_history, spaceship_type); // Calling a function to move enemy spaceships
        is_dead(map, map_size);       // Calling a function to check health of map map Components
        Shoot(map, map_size, Spaceship_position, spaceship_type);       // Calling a function to fire bullets
        is_dead(map, map_size);        // Calling a function to check health of map map Components
        user_level(point, level);
        save(map, map_size, quorum_point, point, spaceship_health, Enemies_history, level, spaceship_type); // Calling a function to save game data
    }
}

bool Enemy_is_in(vector<vector<Map_Components>> &map, int &map_size)
{
    // In the following few lines, we navigate the map, if there is an enemy, it returns the true value
    for (size_t i = 0; i < map_size; i++)
    {
        for (size_t j = 0; j < map_size; j++)
        {
            if (map[i][j].name == "Dart" || map[i][j].name == "Striker" || map[i][j].name == "Wraith" || map[i][j].name == "Banshee")
            {
                return true;
            }
        }
    }
    return false;
}

bool End_Game(int quorum_point, double point, int spaceship_health, vector<string> &Enemies_history, int level)
{
    // In the following few lines, the number of enemies killed by type is specified
    int Dart_counter = 0, Striker_counter = 0, Wraith_counter = 0, Banshee_counter = 0;
    for (auto &Enemie_type : Enemies_history)
    {
        if (Enemie_type == "Dart")
        {
            Dart_counter++;
        }
        else if (Enemie_type == "Striker")
        {
            Striker_counter++;
        }
        else if (Enemie_type == "Wraith")
        {
            Wraith_counter++;
        }
        else if (Enemie_type == "Banshee")
        {
            Banshee_counter++;
        }
    }

    static bool infinite_mode = false;
    if (infinite_mode && spaceship_health > 0)
    {
        return false;
    }
    if (spaceship_health <= 0)
    {
        cout << Bright_Red << "  _ " << endl
             << " | | ___  ___  ___ " << endl
             << " | |/ _ \\/ __|/ _ \\ " << endl
             << " | | (_) \\__ \\  __/" << endl
             << " |_|\\___/|___/\\___|" << Reset << endl;

        cout << Bright_Yellow_new << "List of enemies you have fought with:" << endl
             << Reset
             << Bright_Cyan << "Dart : " << Dart_counter << endl
             << Reset
             << Bright_Blue << "Striker : " << Striker_counter << endl
             << Reset
             << Blue << "Wraith : " << Wraith_counter << endl
             << Reset
             << Magenta << "Banshee : " << Banshee_counter << endl
             << Reset;
        Save_History(level, point, spaceship_health, quorum_point);     // The save history function is called
        return true;
    }
    else if (point >= quorum_point)
    {
        cout << Bright_Green
             << "__    __ _  __  _" << endl
             << "\\ \\/\\/ /| ||  \\| |" << endl
             << " \\_/\\_/ |_||_|\\__|" << Reset << endl;
        cout << Bright_Yellow_new << "If you want to continue playing without restrictions, press y (press any key to finish):" << endl
             << Reset;
        if (getch() == 121)
        {
            infinite_mode = true;
        }
        else
        {
            cout << Bright_Yellow_new << "List of enemies you have fought with:" << endl
                 << Reset
                 << Bright_Cyan << "Dart : " << Dart_counter << endl
                 << Reset
                 << Bright_Blue << "Striker : " << Striker_counter << endl
                 << Reset
                 << Blue << "Wraith : " << Wraith_counter << endl
                 << Reset
                 << Magenta << "Banshee : " << Banshee_counter << endl
                 << Reset;
            Save_History(level, point, spaceship_health, quorum_point);     // The save history function is called
            return true;
        }
    }
    else
    {
        return false;
    }
    return false;
}

void user_level(int point, int &level)
{
    level = point / 200;
}

void Run_game_Advanced(vector<vector<Map_Components>> &map, int &map_size, int &quorum_point, double &point, int &spaceship_health, int &Spaceship_position, vector<string> &Enemies_history, int &level, int spaceship_type)
{
    while (true && !End_Game(quorum_point, point, spaceship_health, Enemies_history, level)) // just for test
    {
        if (!Enemy_is_in(map, map_size))
        {
            positioning_Advanced(map, map_size, spaceship_health, Enemies_history, level); // This function specifies the position of game elements
        }
        display(map, map_size);                                                                                                                                       // This function displays the game map
        Show_information(map_size, quorum_point, point, spaceship_health, level);                                                                                     // call the function that displays game information
        string temp = Move_Spaceship(map, map_size, Spaceship_position, quorum_point, point, spaceship_health, Enemies_history, level, spaceship_type);
        if (temp == "saved successfully") // call the Move_Spaceship function
        {
            cout << Bright_Green << "Game saved !" << Reset;
            break;
        }
        else if ( temp == "play")
        {
            continue;
        }
        else
        Move_Enemy_Spaceship(map, map_size, spaceship_health, point, Enemies_history, spaceship_type); // Calling a function to move enemy spaceships
        is_dead(map, map_size);                                                                        // Calling a function to check health of map map Components
        Shoot(map, map_size, Spaceship_position, spaceship_type);                                      // Calling a function to fire bullets
        is_dead(map, map_size);                                                                        // Calling a function to check health of map map Components
        user_level(point, level);
        save(map, map_size, quorum_point, point, spaceship_health, Enemies_history, level, spaceship_type); // Calling a function to save game data
    }
}

void positioning_Advanced(vector<vector<Map_Components>> &map, int map_size, int &spaceship_health, vector<string> &Enemies_history, int level)
{
    srand(time(0)); // A function that generates random numbers with an initial seed of time 0
    unsigned int row, column;
    bool in_it = false;
    for (size_t i = 0; i < map_size; i++) // In these few lines, if there is no native ship, a ship will be created
    {
        if (map[map_size - 1][i].name == "Spaceship")
        {
            in_it = true;
            spaceship_health = map[map_size - 1][i].Health;
            break;
        }
    }
    if (!in_it)
    {
        map[map_size - 1][(map_size - 1) / 2].name = "Spaceship";
        map[map_size - 1][(map_size - 1) / 2].Health = 3;
        map[map_size - 1][(map_size - 1) / 2].damage = 2147483647; // The largest possible value for an integer data type
        map[map_size - 1][(map_size - 1) / 2].size = 1;
        map[map_size - 1][(map_size - 1) / 2].color = "Bright_Green";
        map[map_size - 1][(map_size - 1) / 2].character = "[#]";

        spaceship_health = map[map_size - 1][(map_size - 1) / 2].Health;
    }
    int Enemy_Type;
    bool Invalid_position = false;
    if (level > 3)
    {
        Enemy_Type = 3; // This function generates number 3
    }
    else if (level > 2)
    {
        Enemy_Type = rand() % 2 + 2; // This function generates random numbers between 2 and 3
    }
    else if (level > 1)
    {
        Enemy_Type = rand() % 3 + 1; // This function generates random numbers between 1 and 3
    }
    else if (level >= 0)
    {
        Enemy_Type = rand() % 4; // This function generates random numbers between 0 and 3
    }

    switch (Enemy_Type) // This section selects the type of enemy to create in the map
    {
    case 0: // In each section of the switch case, a type of enemy is created
        column = rand() % map_size;
        map[0][column].name = "Dart";
        map[0][column].Health = 1;
        map[0][column].damage = 1;
        map[0][column].size = 1 * 1;
        map[0][column].color = "Bright_Cyan";
        map[0][column].character = "[*]";
        Enemies_history.push_back("Dart");
        break;

    case 1:
        do
        {
            Invalid_position = false;
            column = rand() % map_size;
            if (column + 2 <= map_size)
            {
                for (size_t i = 0; i < 2; i++)
                {
                    for (size_t j = 0; j < 2; j++)
                    {
                        map[i][column + j].name = "Striker";
                        map[i][column + j].Health = 2;
                        map[i][column + j].damage = 1;
                        map[i][column + j].size = 2 * 2;
                        map[i][column + j].color = "Bright_Blue";
                        map[i][column + j].character = "[*]";
                    }
                }
            }
            else
            {
                Invalid_position = true;
            }
        } while (Invalid_position);
        Enemies_history.push_back("Striker");
        break;

    case 2:
        do
        {
            Invalid_position = false;
            column = rand() % map_size;
            if (column + 3 <= map_size)
            {
                for (size_t i = 0; i < 3; i++)
                {
                    for (size_t j = 0; j < 3; j++)
                    {
                        map[i][column + j].name = "Wraith";
                        map[i][column + j].Health = 4;
                        map[i][column + j].damage = 1;
                        map[i][column + j].size = 3 * 3;
                        map[i][column + j].color = "Blue";
                        map[i][column + j].character = "[*]";
                    }
                }
            }
            else
            {
                Invalid_position = true;
            }
        } while (Invalid_position);
        Enemies_history.push_back("Wraith");
        break;

    case 3:
        do
        {
            Invalid_position = false;
            column = rand() % map_size;
            if (column + 4 <= map_size)
            {
                for (size_t i = 0; i < 4; i++)
                {
                    for (size_t j = 0; j < 4; j++)
                    {
                        map[i][column + j].name = "Banshee";
                        map[i][column + j].Health = 6;
                        map[i][column + j].damage = 1;
                        map[i][column + j].size = 4 * 4;
                        map[i][column + j].color = "Magenta";
                        map[i][column + j].character = "[*]";
                    }
                }
            }
            else
            {
                Invalid_position = true;
            }
        } while (Invalid_position);
        Enemies_history.push_back("Banshee");
        break;
    }
}

void Save_History(int level, double point, int spaceship_health, int quorum_point)
{
    ofstream out("History.txt", ios ::out | ios ::app);
    out << "level : " << level << " - "
        << "point : " << point << " - "
        << "health : " << spaceship_health << " - ";
    if (point >= quorum_point)
    {
        out << "win" << endl;
    }
    else if (spaceship_health <= 0)
    {
        out << "lose" << endl;
    }
    else
    {
        out << "Continue" << endl;
    }
    out.close();
}

void display_History()
{
    ifstream in;
    in.open("History.txt");
    string data;
    cout << Bright_Yellow_new << "History of games : " << Reset << endl;
    while (getline(in, data, '\n'))
    {
        cout << data << endl;
    }
    cout << Bright_Yellow_new << "Press one of the keys to return to the menu !" << Reset << endl;
    int temp = getch();
    in.close();
}

void SpaceShips_Description()
{
    system("cls || clear"); // This function clears the console
    cout << Bright_Green << "SpaceShips : " << endl
         << "Health : 3 " << endl
         << "damage : infinity " << endl
         << "size : 1*1 " << endl
         << "character : [#] " << Reset << endl;
    cout << "________________________________________" << endl;
    cout << Bright_Cyan << "Dart : " << endl
         << "Health : 1 " << endl
         << "damage : 1 " << endl
         << "size : 1*1 " << endl
         << "character : [*] " << Reset << endl;
    cout << "________________________________________" << endl;
    cout << Bright_Blue << "Striker : " << endl
         << "Health : 2 " << endl
         << "damage : 1 " << endl
         << "size : 2*2 " << endl
         << "character : [*][*] " << endl
         << "            [*][*] " << Reset << endl;
    cout << "________________________________________" << endl;
    cout << Blue << "Wraith : " << endl
         << "Health : 4 " << endl
         << "damage : 1 " << endl
         << "size : 3*3 " << endl
         << "character : [*][*][*] " << endl
         << "            [*][*][*] " << endl
         << "            [*][*][*] " << Reset << endl;
    cout << "________________________________________" << endl;
    cout << Magenta << "Banshee : " << endl
         << "Health : 6 " << endl
         << "damage : 1 " << endl
         << "size : 4*4 " << endl
         << "character : [*][*][*][*] " << endl
         << "            [*][*][*][*] " << endl
         << "            [*][*][*][*] " << endl
         << "            [*][*][*][*] " << Reset << endl;
    cout << "________________________________________" << endl;
    cout << Bright_Yellow_new << "Press one of the keys to return to the menu !" << Reset << endl;
    int temp = getch();
}