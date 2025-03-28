#include <iostream>
#include <windows.h>
#include <TlHelp32.h>
#include <vector>

void ListProcesses();
bool UserOptions();
void ListProcessIDS();

std::vector<int> Proccesses;

int main()
{
    bool MainLoop = true;
    while(MainLoop)
    {
        MainLoop = UserOptions();
    }


    return 0;

}

void ListProcesses()
{
    std::cout << "\nList of all current processes: \n";

    HANDLE hProcces =  CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

    PROCESSENTRY32 peInfo;
    peInfo.dwSize = sizeof(PROCESSENTRY32); // sET BEFORE PR OC32FIRST

    // Initial test
    /*
    std::cout << hProcces << std::endl;
    Process32First(hProcces, &peInfo);
    std::wcout << L"The Process Name: " << peInfo.szExeFile;
    */

    if (Process32First(hProcces, &peInfo))
    {
        int i = 0;
        do
        {
           std::wcout << i <<L") The process Name is: " << peInfo.szExeFile << std::endl;
           std::wcout << "      -The Amount of threads of this proocess are: " << peInfo.cntThreads << std::endl;
           std::wcout << "      -Process I.D : " << peInfo.th32ProcessID << std::endl;

           Proccesses.push_back(peInfo.th32ProcessID);
           i++;
        } 
        while ((Process32Next(hProcces, &peInfo)));

    }
    CloseHandle(hProcces);
}

void ListProcessIDS()
{
    for(int i = 0; i < std::size(Proccesses); i++)
    {
        std::cout << Proccesses[i] << std::endl;
    }
}

bool UserOptions()
{
    int UserInput;
    std::cout << "What you wanna do?\n1. List all Processes\n2. List all process IDS\n3. Quit"; // Just print
    std::cin >> UserInput;

    switch (UserInput)
    {
    case 1:
        ListProcesses(); // list all processes 
        break;
    case 2:
        ListProcessIDS();
        break;
    default:
        return false;
    }
    return true;
}

// void 