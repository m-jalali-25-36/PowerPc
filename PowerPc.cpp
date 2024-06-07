#include <iostream>
#include <conio.h>
#include <bits/stdc++.h>
#include <cwchar>
#include <windows.h>
#include <cstdlib>
#include <string>
#include <math.h>
#include <Wincon.h>
#include <ctime>    
#include <cstdlib>

using namespace std;

string tolower(char const argv[]);
void CONSOLE();
void PrintMainMenu();
void  Shutdown();
void  Restart();
void  Hibernate();
void  Sleep();
void  LogOff();
void  Lock();
void  SwitchUser();
int argvToInt(char const argv[]);

int main(int argc, char const *argv[])
{
    static CONSOLE_FONT_INFOEX  fontex;
    fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetCurrentConsoleFontEx(hOut, 0, &fontex);
    fontex.FontWeight = 700;
    fontex.dwFontSize.X = 36;
    fontex.dwFontSize.Y = 36;
    SetCurrentConsoleFontEx(hOut, NULL, &fontex);
    cout << "This text is bold, like me.\n";
  return 0;
    CONSOLE();
    bool ex = false;
    int a;
    while (true)
    {
        system("cls");
        if(argc >= 2)
            a = argvToInt(argv[1]);
        else
        {
            PrintMainMenu();
            a = getch();
        }
        printf("\n");
        if(a == '0'){ return 0;}
        else if(a == '1') { printf("Are you sure it's Shutdown? (Cancel esc)>>"); if(argc >= 3 && (a = argvToInt(argv[2])) == -1) ; else a = getch(); if(a != 27) Shutdown(); }
        else if(a == '2') { printf("Are you sure it's Restart? (Cancel esc)>>"); if(argc >= 3 && (a = argvToInt(argv[2])) == -1) ; else a = getch(); if(a != 27) Restart(); }
        else if(a == '3') { printf("Are you sure it's Hibernate? (Cancel esc)>>"); if(argc >= 3 && (a = argvToInt(argv[2])) == -1) ; else a = getch(); if(a != 27) Hibernate(); }
        else if(a == '4') { printf("Are you sure it's Sleep? (Cancel esc)>>"); if(argc >= 3 && (a = argvToInt(argv[2])) == -1) ; else a = getch(); if(a != 27) Sleep(); }
        else if(a == '5') { printf("Are you sure it's LogOff? (Cancel esc)>>"); if(argc >= 3 && (a = argvToInt(argv[2])) == -1) ; else a = getch(); if(a != 27) LogOff(); }
        else if(a == '6') { printf("Are you sure it's Lock? (Cancel esc)>>"); if(argc >= 3 && (a = argvToInt(argv[2])) == -1) ; else a = getch(); if(a != 27) Lock(); }
        else if(a == '7') { printf("Are you sure it's SwitchUser? (Cancel esc)>>"); if(argc >= 3 && (a = argvToInt(argv[2])) == -1) ; else a = getch(); if(a != 27) SwitchUser(); }
        else if(a == 27){if(ex) return 0; ex = true; continue;}
        ex = false;
        argc = 0;
    }
    
    return 0;
}



int argvToInt(char const argv[]){
    string a = tolower(argv);
    if(a == "shutdown" || a == "sh" || a == "1")
        return '1';
    if(a == "restart" || a == "r" || a == "2")
        return '2';
    if(a == "hibernate" || a == "h" || a == "3")
        return '3';
    if(a == "sleep" || a == "p" || a == "4")
        return '4';
    if(a == "logoff" || a == "lo" || a == "5")
        return '5';
    if(a == "lock" || a == "l" || a == "6")
        return '6';
    if(a == "switchuser" || a == "su" || a == "7")
        return '7';
    if(a == "y" || a == "-y" || a == "--yes"|| a == "--yes")
        return -1;
    return -1;
}

void PrintMainMenu(){
    printf("  0) Exit \n");
    printf("  1) Shutdown \n");
    printf("  2) Restart \n");
    printf("  3) Hibernate \n");
    printf("  4) Sleep \n");
    printf("  5) Log Off \n");
    printf("  6) Lock \n");
    printf("  7) Switch User \n");
    printf("  8) \n");
    printf("esc) Back \n");
    printf(">>>");
}


void  Shutdown(){ system("Shutdown -s -t 00"); }
void  Restart(){ system("Shutdown -r -f -t 00"); }
void  Hibernate(){ system("Shutdown -h"); }
void  Sleep(){ system("rundll32.exe powrprof.dll,SetSuspendState Sleep"); }
void  LogOff(){ system("Shutdown -l"); }
void  Lock(){ system("Rundll32 User32.dll,LockWorkStation"); }
void  SwitchUser(){ system("tsdiscon.exe"); }
// Shutdown => Shutdown -s -t 00
// Restart => Shutdown -r -f -t 00
// Hibernate => Shutdown -h
// Sleep => rundll32.exe powrprof.dll,SetSuspendState Sleep
// Log Off => Shutdown -l
// Lock => Rundll32 User32.dll,LockWorkStation
// Switch User => tsdiscon.exe


string tolower(char const argv[]){
    string r = "";
    int len =strlen(argv);
    for (int i = 0; i < len; i++){
          r+= (char)tolower(argv[i]);
    }
    return r;
}

void CONSOLE(){
    // CONSOLE_FONT_INFOEX cfi;
    // cfi.cbSize = sizeof(cfi);
    // cfi.nFont = 0;
    // cfi.dwFontSize.X = 0;                   // Width of each character in the font
    // cfi.dwFontSize.Y = 24;                  // Height
    // cfi.FontFamily = FF_DONTCARE;
    // cfi.FontWeight = FW_NORMAL;
    // std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
    // SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}