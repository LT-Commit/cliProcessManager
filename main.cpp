#include <iostream>
#include <windows.h>
#include <TlHelp32.h>


int main()
{
    std::cout << "\nList of all current processes: \n";

    HANDLE hProcces =  CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

    PROCESSENTRY32 peInfo;

    
    std::cout << hProcces << std::endl;
    Process32First(hProcces, &peInfo);
    std::cout << "The Process Name: "

    std::cout << hProcces;

}