#include <iostream>
#include <windows.h>
#include <TlHelp32.h>

void ListProcesses();
void UserOptions();

int main()
{
    while(TRUE)
    {
        UserOptions();
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
        do
        {
           std::wcout << L"The process Name is: " << peInfo.szExeFile << std::endl;
        } 
        while ((Process32Next(hProcces, &peInfo)));
        
    }
    CloseHandle(hProcces);
}

void UserOptions()
{
    int UserInput;
    std::cout << "What you wanna do?\n1. List all Processes\n";
    std::cin >> UserInput;

    switch (UserInput)
    {
    case 1:
        ListProcesses();
        break;
    
    default:
        break;
    }


}