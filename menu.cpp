#include<iostream>
#include<windows.h>
#include<iomanip>

using namespace std;

void SetColor(int f=15,int b=0)
{
    unsigned short ForeColor=f+16*b;
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,ForeColor);
}

class TITLE{
    public:
        TITLE(){
            SetColor(2,0);
            cout<<"*************************************************************************************************************************************************************\n";
            cout<<setw(118)<<"*****   *   *   *****   *****   *****      *   *     *     *****   *****   *****\n";
            cout<<setw(118)<<"*       *   *   *   *   *       *   *      ** **    * *    *   *     *     *   *\n";
            cout<<setw(118)<<"*****   *   *   *****   *****   *****      * * *   *****   *****     *     *   *\n";
            cout<<setw(118)<<"    *   *   *   *       *       *  *       *   *   *   *   *  *      *     *   *\n";
            cout<<setw(118)<<"*****   *****   *       *****   *   *      *   *   *   *   *   *   *****   *****\n";
            cout<<"\n\n\n\n";
    
            SetConsoleOutputCP(437);
            char block=254;
            SetColor(1,0);
            cout<<setw(45)<<block;
            cout<<" Control : Using A D on Keyboard to Move the Character and W to Jump\n";
            cout<<"\n\n\n\n";
    
            SetColor(14,0);
            cout<<setw(95)<<"Press Space to Start the Game...\n";
    

            SetColor(0.0);}
};

class IMAGE{
    public:
        char b=254; //brick
        IMAGE(){
            SetColor(0,0);
            cout<<b<<b<<b<<b<<b;
            SetColor(12,0);
            cout<<b<<b<<b<<b<<b;                        //1st row
            
            SetColor(0,0);
            cout<<"\n"<<b<<b<<b<<b;
            SetColor(12,0);
            cout<<b<<b<<b<<b<<b<<b<<b<<b<<b;          //2nd row
            
            SetColor(0,0);
            cout<<"\n"<<b<<b<<b<<b;
            SetColor(14,0);
            cout<<b<<b<<b;
            SetColor(7,0);
            cout<<b<<b;
            SetColor(5,0);
            cout<<b;
            SetColor(7,0);
            cout<<b;                                 //3rd row
            
            SetColor(0,0);
            cout<<"\n"<<b<<b<<b;
            SetColor(14,0);
            cout<<b;
            SetColor(7,0);
            cout<<b;
            SetColor(14,0);
            cout<<b;
            SetColor(7,0);
            cout<<b<<b<<b;
            SetColor(5,0);
            cout<<b;
            SetColor(7,0);
            cout<<b<<b<<b;                     //4th row
            
            SetColor(0,0);
            cout<<"\n"<<b<<b<<b;
            SetColor(14,0);
            cout<<b;
            SetColor(7,0);
            cout<<b;
            SetColor(14,0);
            cout<<b<<b;
            SetColor(7,0);
            cout<<b<<b<<b;
            SetColor(5,0);
            cout<<b;
            SetColor(7,0);
            cout<<b<<b<<b;               //5th row
            
            SetColor(0,0);
            cout<<"\n"<<b<<b<<b;
            SetColor(14,0);
            cout<<b<<b;
            SetColor(7,0);
            cout<<b<<b<<b<<b;
            SetColor(5,0);
            cout<<b<<b<<b<<b;                  //6th row
            
            SetColor(0,0);
            cout<<"\n"<<b<<b<<b<<b<<b;
            SetColor(7,0);
            cout<<b<<b<<b<<b<<b<<b<<b;           //7th row
           
            SetColor(0,0);
            cout<<"\n"<<b<<b<<b<<b;
            SetColor(12,0);
            cout<<b<<b;
            SetColor(1,0);
            cout<<b;
            SetColor(12,0);
            cout<<b<<b;
            SetColor(1,0);
            cout<<b;
            SetColor(12,0);
            cout<<b;             //8th row

            SetColor(0,0);
            cout<<"\n"<<b<<b<<b;
            SetColor(12,0);
            cout<<b<<b<<b;
            SetColor(1,0);
            cout<<b;
            SetColor(12,0);
            cout<<b<<b;
            SetColor(1,0);
            cout<<b;
            SetColor(12,0);
            cout<<b<<b<<b;         //9th row

            SetColor(0,0);
            cout<<"\n"<<b<<b;
            SetColor(12,0);
            cout<<b<<b<<b<<b;
            SetColor(1,0);
            cout<<b<<b<<b<<b;
            SetColor(12,0);
            cout<<b<<b<<b<<b;           //10th row

            SetColor(0,0);
            cout<<"\n"<<b<<b;
            SetColor(7,0);
            cout<<b<<b;
            SetColor(12,0);
            cout<<b;
            SetColor(1,0);
            cout<<b;
            SetColor(14,0);
            cout<<b;
            SetColor(1,0);
            cout<<b<<b;
            SetColor(14,0);
            cout<<b;
            SetColor(1,0);
            cout<<b;
            SetColor(12,0);
            cout<<b;
            SetColor(7,0);
            cout<<b<<b;           //11th row

            SetColor(0,0);
            cout<<"\n"<<b<<b;
            SetColor(7,0);
            cout<<b<<b<<b;
            SetColor(1,0);
            cout<<b<<b<<b<<b<<b<<b;
            SetColor(7,0);
            cout<<b<<b<<b;        //12th row

            SetColor(0,0);
            cout<<"\n"<<b<<b;
            SetColor(7,0);
            cout<<b<<b;
            SetColor(1,0);
            cout<<b<<b<<b<<b<<b<<b<<b<<b;
            SetColor(7,0);
            cout<<b<<b;        //13th row

            SetColor(0,0);
            cout<<"\n"<<b<<b<<b<<b;
            SetColor(1,0);
            cout<<b<<b<<b;
            SetColor(0,0);
            cout<<b<<b;
            SetColor(1,0);
            cout<<b<<b<<b;           //14th row

            SetColor(0,0);
            cout<<"\n"<<b<<b<<b;
            SetColor(8,0);
            cout<<b<<b<<b;
            SetColor(0,0);
            cout<<b<<b<<b<<b;
            SetColor(8,0);
            cout<<b<<b<<b;           //15th row

            SetColor(0,0);
            cout<<"\n"<<b<<b;
            SetColor(8,0);
            cout<<b<<b<<b<<b;
            SetColor(0,0);
            cout<<b<<b<<b<<b;
            SetColor(8,0);
            cout<<b<<b<<b<<b;           //15th row



         }
};
int main(void){
    TITLE();
    IMAGE();




    SetColor();
    system("pause");
    return 0;
}