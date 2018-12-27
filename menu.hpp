#ifndef _MENU_
#define _MENU_

#ifndef _IOSTREAM_
#define _IOSTREAM_
#include<iostream>
#endif

#ifndef _WINDOWS_H_
#define _WINDOWS_H_
#include<windows.h>
#endif

#ifndef _IOMANIP_
#define _IOMANIP_
#include<iomanip>
#endif

void SetColor(HANDLE hOut, int f=15,int b=0)
{
    std::cout.flush();
    unsigned short ForeColor=f+16*b;
    SetConsoleTextAttribute(hOut,ForeColor);
};

void IMAGE(HANDLE hOut){
    auto b = "■";
    SetColor(hOut, 0,0);
    std::cout<<b<<b<<b<<b<<b;
    SetColor(hOut, 12,0);
    std::cout<<b<<b<<b<<b<<b;//1st row
    
    SetColor(hOut, 0,0);
    std::cout<<"\n"<<b<<b<<b<<b;
    SetColor(hOut, 12,0);
    std::cout<<b<<b<<b<<b<<b<<b<<b<<b<<b;  //2nd row
    
    SetColor(hOut, 0,0);
    std::cout<<"\n"<<b<<b<<b<<b;
    SetColor(hOut, 14,0);
    std::cout<<b<<b<<b;
    SetColor(hOut, 7,0);
    std::cout<<b<<b;
    SetColor(hOut, 5,0);
    std::cout<<b;
    SetColor(hOut, 7,0);
    std::cout<<b; //3rd row
    
    SetColor(hOut, 0,0);
    std::cout<<"\n"<<b<<b<<b;
    SetColor(hOut, 14,0);
    std::cout<<b;
    SetColor(hOut, 7,0);
    std::cout<<b;
    SetColor(hOut, 14,0);
    std::cout<<b;
    SetColor(hOut, 7,0);
    std::cout<<b<<b<<b;
    SetColor(hOut, 5,0);
    std::cout<<b;
    SetColor(hOut, 7,0);
    std::cout<<b<<b<<b;     //4th row
    
    SetColor(hOut, 0,0);
    std::cout<<"\n"<<b<<b<<b;
    SetColor(hOut, 14,0);
    std::cout<<b;
    SetColor(hOut, 7,0);
    std::cout<<b;
    SetColor(hOut, 14,0);
    std::cout<<b<<b;
    SetColor(hOut, 7,0);
    std::cout<<b<<b<<b;
    SetColor(hOut, 5,0);
    std::cout<<b;
    SetColor(hOut, 7,0);
    std::cout<<b<<b<<b;       //5th row
    
    SetColor(hOut, 0,0);
    std::cout<<"\n"<<b<<b<<b;
    SetColor(hOut, 14,0);
    std::cout<<b<<b;
    SetColor(hOut, 7,0);
    std::cout<<b<<b<<b<<b;
    SetColor(hOut, 5,0);
    std::cout<<b<<b<<b<<b;  //6th row
    
    SetColor(hOut, 0,0);
    std::cout<<"\n"<<b<<b<<b<<b<<b;
    SetColor(hOut, 7,0);
    std::cout<<b<<b<<b<<b<<b<<b<<b;   //7th row
   
    SetColor(hOut, 0,0);
    std::cout<<"\n"<<b<<b<<b<<b;
    SetColor(hOut, 12,0);
    std::cout<<b<<b;
    SetColor(hOut, 1,0);
    std::cout<<b;
    SetColor(hOut, 12,0);
    std::cout<<b<<b;
    SetColor(hOut, 1,0);
    std::cout<<b;
    SetColor(hOut, 12,0);
    std::cout<<b;     //8th row

    SetColor(hOut, 0,0);
    std::cout<<"\n"<<b<<b<<b;
    SetColor(hOut, 12,0);
    std::cout<<b<<b<<b;
    SetColor(hOut, 1,0);
    std::cout<<b;
    SetColor(hOut, 12,0);
    std::cout<<b<<b;
    SetColor(hOut, 1,0);
    std::cout<<b;
    SetColor(hOut, 12,0);
    std::cout<<b<<b<<b; //9th row

    SetColor(hOut, 0,0);
    std::cout<<"\n"<<b<<b;
    SetColor(hOut, 12,0);
    std::cout<<b<<b<<b<<b;
    SetColor(hOut, 1,0);
    std::cout<<b<<b<<b<<b;
    SetColor(hOut, 12,0);
    std::cout<<b<<b<<b<<b;   //10th row

    SetColor(hOut, 0,0);
    std::cout<<"\n"<<b<<b;
    SetColor(hOut, 7,0);
    std::cout<<b<<b;
    SetColor(hOut, 12,0);
    std::cout<<b;
    SetColor(hOut, 1,0);
    std::cout<<b;
    SetColor(hOut, 14,0);
    std::cout<<b;
    SetColor(hOut, 1,0);
    std::cout<<b<<b;
    SetColor(hOut, 14,0);
    std::cout<<b;
    SetColor(hOut, 1,0);
    std::cout<<b;
    SetColor(hOut, 12,0);
    std::cout<<b;
    SetColor(hOut, 7,0);
    std::cout<<b<<b;   //11th row

    SetColor(hOut, 0,0);
    std::cout<<"\n"<<b<<b;
    SetColor(hOut, 7,0);
    std::cout<<b<<b<<b;
    SetColor(hOut, 1,0);
    std::cout<<b<<b<<b<<b<<b<<b;
    SetColor(hOut, 7,0);
    std::cout<<b<<b<<b;//12th row

    SetColor(hOut, 0,0);
    std::cout<<"\n"<<b<<b;
    SetColor(hOut, 7,0);
    std::cout<<b<<b;
    SetColor(hOut, 1,0);
    std::cout<<b<<b<<b<<b<<b<<b<<b<<b;
    SetColor(hOut, 7,0);
    std::cout<<b<<b;//13th row

    SetColor(hOut, 0,0);
    std::cout<<"\n"<<b<<b<<b<<b;
    SetColor(hOut, 1,0);
    std::cout<<b<<b<<b;
    SetColor(hOut, 0,0);
    std::cout<<b<<b;
    SetColor(hOut, 1,0);
    std::cout<<b<<b<<b;   //14th row

    SetColor(hOut, 0,0);
    std::cout<<"\n"<<b<<b<<b;
    SetColor(hOut, 8,0);
    std::cout<<b<<b<<b;
    SetColor(hOut, 0,0);
    std::cout<<b<<b<<b<<b;
    SetColor(hOut, 8,0);
    std::cout<<b<<b<<b;   //15th row

    SetColor(hOut, 0,0);
    std::cout<<"\n"<<b<<b;
    SetColor(hOut, 8,0);
    std::cout<<b<<b<<b<<b;
    SetColor(hOut, 0,0);
    std::cout<<b<<b<<b<<b;
    SetColor(hOut, 8,0);
    std::cout<<b<<b<<b<<b;   //15th row
};

void TITLE(HANDLE hOut, int highScore) {
    SetColor(hOut, 2, 0);
    std::cout<<"*************************************************************************************************************************************************************\n";
    std::cout<<std::setw(118)<<"*****   *   *   *****   *****   *****      *   *     *     *****   *****   *****\n";
    std::cout<<std::setw(118)<<"*       *   *   *   *   *       *   *      ** **    * *    *   *     *     *   *\n";
    std::cout<<std::setw(118)<<"*****   *   *   *****   *****   *****      * * *   *****   *****     *     *   *\n";
    std::cout<<std::setw(118)<<"    *   *   *   *       *       *  *       *   *   *   *   *  *      *     *   *\n";
    std::cout<<std::setw(118)<<"*****   *****   *       *****   *   *      *   *   *   *   *   *   *****   *****\n";
    std::cout<<"\n\n\n\n";

    auto block = "■";
    SetColor(hOut, 1,0);
    std::cout<<std::setw(45)<<block;
    std::cout<<" Control : Using ← → on Keyboard to Move the Character and ↑ to Jump\n";
    std::cout<<"\n\n\n\n";
    
    SetColor(hOut, 14,0);
    std::cout<<std::setw(95)<<"Press Enter to Start the Game...\n";
    

    SetColor(hOut, 0.0);
    IMAGE(hOut);
    std::cout << std::setw(100) << "HIGH SCORE: " << highScore;
    std::cout.flush();
    std::cin.get();
};

#endif