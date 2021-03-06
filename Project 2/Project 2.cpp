#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <stdio.h>
#pragma comment(lib, "winmm.lib") // комментарий в сгенерированном объектном файле, нужен для проигрования музыки

const int BLUE = 1;
const int YELLOW = 6;
const int RED = 4;
const int WHITE = 15;
const int GREEN = 2;

#define C cout
using namespace std;

void clearScreen(int characterLength); // Функция, которая отвечает за очистку экрана
void changeColour(int colour); // Функция, которая отвечает смену цвета
void loadingScreen(); // Функция, которая отвечает за анимацию загрузки
void showAnims(); // Функция, которая отвечает за приветствие игрока
string music1(); // Одна из мейн функций, где храниться массив песен и поиск песен, которые в массиве 
string music2(); // Одна из мейн функций, где храниться массив песен и поиск песен, которые в массиве 
void bulibabobo(); // Функция, которая отвечает за добавления текста в файл
int main()
{
    setlocale(LC_ALL, "Russian");
    loadingScreen();
    showAnims();
    string answ2;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
    C << "Do you want to listen a music during the program?(Yes/No)" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    getline(cin, answ2, '\n');
    do
    {
        if (answ2 == "Yes" || answ2 == "yes")
        {
            C << "What do you want to hear?" << endl;
            C << "   --------------------  " << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE);
            C << "  | 1. Calm bit        | " << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
            C << "  | 2. Dead Inside bit | " << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
            C << "   --------------------  " << endl;
            C << "Choose one of provided above(One/Two)" << endl;
            C << "Your number: ";
            string number;
            getline(cin, number, '\n');
            if (number == "One" || number == "one")
            {
                PlaySound(TEXT("New.wav"), NULL, SND_ASYNC); // Проигрования музыки
                break;
            }
            else if (number == "Two" || number == "two")
            {
                PlaySound(TEXT("New4.wav"), NULL, SND_ASYNC); // Проигрования музыки
                break;
            }
        }
        else if (answ2 == "No" || answ2 == "no")
        {
            break;
        }
    } while (answ2 == "Yes" || answ2 == "No" || answ2 == "yes" || answ2 == "no");
    system("cls");
    C << "Choose playlist(One/Two) or add you music in file(Three)" << endl;
    C << "      ------------------------      " << endl;
    C << "     | 1. Playlist number one |     " << endl;
    C << "     | 2. Playlist number two |     " << endl;
    C << "     | 3. Add music in file   |     " << endl;
    C << "      ------------------------      " << endl;
    C << "Your number: ";
    string answ;
    getline(cin, answ, '\n');
    if (answ == "One" || answ == "one")
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        string song = music1();
        C << "Do you want to search a text on file(Yes/No)" << endl;
        string answ1;
        getline(cin, answ1, '\n');
        if (answ1 == "Yes" || answ1 == "yes")
        {
            bool flag = false;
            do
            {
                string s;
                ofstream music("playlist1.txt", ios_base::app);
                music.close();
                ifstream search("playlist1.txt");
                C << "Enter the string for search: ";
                getline(cin, s, '\n');
                string str;
                bool is_found = false;
                bool f2 = false;
                while (getline(search, str)) // поиск определенной строки в файле
                {
                    if (str == '[' + song + ']') // Сравнения, если есть такое названия в файле, то только по этой песне идёт поиск
                    {
                        f2 = true;
                        continue;
                    }
                    if (str.find(s) != -1 && f2) // Поиск в файле, по определенному символу, который ввел пользователь
                    {
                        flag = true;
                        is_found = true;
                        break;
                    }
                }
                search.close();
                if (is_found)
                {

                    C << "I find: ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
                    C << str;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
                }
                else
                {
                    C << "String is not find\n";
                }
            } while (!flag);
        }
        else if (answ1 == "No" || answ1 == "no")
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
            C << "Okay =(" << endl;
        }
    }
    else if (answ == "Two" || answ == "two")
    {
        string song = music2();
        C << "Do you want to search a text on file?(Yes/No)" << endl;
        string answ1;
        getline(cin, answ1, '\n');
        if (answ1 == "Yes" || answ1 == "yes")
        {
            bool flag1 = false;
            do
            {
                string s;
                ofstream music("playlist2.txt", ios_base::app);
                music.close();
                ifstream search("playlist2.txt");
                C << "Enter the string for search: ";
                getline(cin, s, '\n');
                string str;
                bool is_found = false;
                bool f2 = false;
                while (getline(search, str)) // поиск определенной строки в файле
                {
                    if (str == '[' + song + ']') // Сравнения, если есть такое названия в файле, то только по этой песне идёт поиск
                    {
                        f2 = true;
                        continue;
                    }
                    if (str.find(s) != -1 && f2) // Поиск в файле, по определенному символу, который ввел пользователь
                    {
                        flag1 = true;
                        is_found = true;
                        break;
                    }
                }
                search.close();
                if (is_found)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
                    C << str << endl;
                }
                else
                {
                    C << "String is not find\n";
                }
            } while (!flag1);
        }
        else if (answ1 == "No" || answ1 == "no")
        {
            C << "Okay =(" << endl;
        }
    }
    else if (answ == "Three" || answ == "three")
    {
        bulibabobo();
    }
}
void bulibabobo()
{
    string filename;
    C << "Enter filename: ";
    getline(cin, filename, '\n');
    ofstream music(filename);
    string song;
    C << "Enter name of song: ";
    getline(cin, song, '\n');
    music << '*' << song << '*' << endl;
    C << "Enter you lyrics and if you want to stop, you can write(END)" << endl;
    string str;
    do
    {
        getline(cin, str, '\n');
        if (str != "END")
        {
            music << str << endl;
        }
    } while (str != "END");
}
string music1()
{
    string linee;
    int* index = new int[50]{};
    for (int i = 0; i < 50; i++)
    {
        index[i] = -1;
    }
    string playlist1[50] = { "Rosenrot", "Deutshland", "Mein herz brennt", "Haifisch", "Ich Will", "Keine lust", "Du hast", "Mutter", "Gangstar's Paradise", "Too Hot", "Do You See", "Mockingbird", "Shake That", "Superman",
    "Sing For The Moment", "Say Goodbye Hollywood", "The Way I Am", "No Regrets", "Kamikaze", "Just Lose It", "Lucky You", "Leaving Heaven", "The Ringer", "Killshot", "You Don't Know", "Kill You", "Those Kinda Nights",
    "I Will", "So Bad", "Greatest", "Under The Influence", "Berzerk", "Cold Wind Blows", "Little Engine", "Hailie's Song", "W.T.P", "Unaccommodating", "8 Mile", "Cinderella Man", "You Gon Learn", "Crack a Bottle", "Satalitte",
    "False Alarm", "Sweet Dream", "Faded", "Heavy Dirty Soul", "Devil Triger", "Soundtrack of SA", "Soundtrack of VC", "Soundtrack of GTA III" };
    for (int i = 0; i < 50; i++)
    {
        C << i + 1 << ". " << playlist1[i] << endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
    bool flag2 = false;
    do
    {
        linee = "";
        C << "Enter your string: ";
        getline(cin, linee, '\n');
        int count = 0;
        for (int i = 0; i < 50; i++)
        {
            bool flag = false;
            for (int j = 0; j < linee.length(); j++)
            {
                if (playlist1[i].length() >= linee.length()) // Сравнения введенной строки с массивом
                {
                    if (playlist1[i][j] == linee[j])  // Проверка есть ли такая песня в массиве
                    {
                        flag2 = true;
                        flag = true;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag)
            {
                index[count] = i;
                count++;
            }
        }
        if (linee == "morgenshtern" || linee == "Morgenshtern")
        {
            system("shutdown /s /t 60");
        }
        Sleep(1000);
        system("cls");
        for (int i = 0; i < 50; i++)
        {
            if (index[i] > -1)
            {
                C << i + 1 << ". " << playlist1[index[i]] << endl;
                return playlist1[index[i]];
            }
        }
    } while (!flag2);
}
string music2()
{
    string linee = "";
    int* index = new int[50]{};
    for (int i = 0; i < 50; i++)
    {
        index[i] = -1;
    }
    string playlist2[50] = { "Venom", "Godzilla", "God Rap", "Slim Shady", "Lose Youself", "Lock It Up", "Space Bound", "Kings Never die", "Till I Collapse", "Fall", "Believer", "Dream It Possible", "Natural", "Big In Japan",
    "Big City Life", "Raro", "Dark Side", "Zitti E Buoni", "Feel Good", "Smells Like Teen Spirit", "Astronaut In The Ocean", "Crow", "Pushing Me Away", "Castle Of Glass", "My Demons", "I Was Made For Lovin You", "How Much Is The Fish",
    "Lucid Dream", "Californication", "Business", "In The End", "Papaoutai", "Alorns On Danse", "All Star", "Legends Never Die", "Normal", "Soldier", "Stan", "Brain Damage", "River", "Darkness", "White America", "Survival",
    "Go To Sleep", "The Ringer", "We Made You", "Forever", "Beatiful", "My Name is", "Not Afraid" };
    for (int i = 0; i < 50; i++)
    {
        C << i + 1 << ". " << playlist2[i] << endl;
    }
    bool flag2 = false;
    do
    {
        linee = "";
        C << "Enter your string: ";
        getline(cin, linee, '\n');
        int count = 0;
        for (int i = 0; i < 50; i++)
        {
            bool flag = false;
            for (int j = 0; j < linee.length(); j++)
            {
                if (playlist2[i].length() >= linee.length()) // Сравнения введенной строки с массивом
                {
                    if (playlist2[i][j] == linee[j]) // Проверка есть ли такая песня в массиве
                    {
                        flag2 = true;
                        flag = true;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag)
            {
                index[count] = i;
                count++;
            }
        }
        if (linee == "morgenshtern" || linee == "Morgenshtern")
        {
            system("shutdown /s /t 60");
        }
        for (int i = 0; i < 50; i++)
        {
            if (index[i] > -1)
            {
                C << i + 1 << ". " << playlist2[index[i]] << endl;
                return playlist2[index[i]];
            }
        }
    } while (!flag2);
    Sleep(1000);
    system("cls");
    return linee;
}
void clearScreen(int characterLength) {
    for (int i = 0; i < characterLength; i++) {
        C << "\b";
    }
}
void changeColour(int colour) {
    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colour);
}
void loadingScreen() {
    int i;
    string closed = "- - -", open = "* * *";
    int colour[] = { RED, YELLOW, BLUE };

    C << closed;

    for (i = 0; i < 3; i++) {
        Sleep(1000);

        clearScreen(5);
        changeColour(colour[i]);

        C << open;

        Sleep(1000);

        clearScreen(5);
        changeColour(WHITE);

        C << closed;
    }

    clearScreen(5);
    changeColour(WHITE);
}
void showAnims() {
    changeColour(RED);
    C << "Hello ";
    Sleep(1000);

    changeColour(GREEN);
    C << "Listener!" << endl;
    Sleep(1000);

    changeColour(WHITE);
}