#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream> 
#include <string> 
#include<sys/stat.h>
//#include "D:\Program Files (x86)\Dev-Cpp\MinGW64\x86_64-w64-mingw32\include\windows.h"
#include <windows.h> 
#include<fcntl.h>
#include<stdlib.h>
using namespace std; 
#define BLACK_COLOR 0
#define GREEN_COLOR 3
void gotoxy(int xpos, int ypos)

{

  COORD scrn;

  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);

  scrn.X = xpos; scrn.Y = ypos;

  SetConsoleCursorPosition(hOuput,scrn);

} 



void ShowConsoleCursor(bool showFlag)

{

    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);



    CONSOLE_CURSOR_INFO     cursorInfo;



    GetConsoleCursorInfo(out, &cursorInfo);

    cursorInfo.bVisible = showFlag; // set the cursor visibility

    SetConsoleCursorInfo(out, &cursorInfo);

}



HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


int main()

{
	ShowConsoleCursor(false);

	bool end_flag = false;
	
	int x=1, y=1;
	int reset[9][9]={
	{0,0,0,9,2,0,0,0,0},
	
 	{0,4,0,8,5,1,0,0,0},
 	
 	{2,5,6,0,0,3,0,9,1},
 	
 	{1,0,0,0,8,5,4,0,9},
 	
	{0,9,8,7,3,0,1,6,2},
	
 	{0,0,0,2,0,0,5,3,0},
 	
 	{0,0,7,0,6,0,9,0,0},
 	
 	{9,0,0,0,0,2,6,8,0},
 	
 	{0,8,0,0,9,0,0,5,4},
 	};

	int sudoku[9][9] = {
	{0,0,0,9,2,0,0,0,0},
	
 	{0,4,0,8,5,1,0,0,0},
 	
 	{2,5,6,0,0,3,0,9,1},
 	
 	{1,0,0,0,8,5,4,0,9},
 	
	{0,9,8,7,3,0,1,6,2},
	
 	{0,0,0,2,0,0,5,3,0},
 	
 	{0,0,7,0,6,0,9,0,0},
 	
 	{9,0,0,0,0,2,6,8,0},
 	
 	{0,8,0,0,9,0,0,5,4},
 	};
 	int ans[9][9] = {
	{8,7,1,9,2,6,3,4,5},
		
	{3,4,9,8,5,1,1,2,6},
	 	
	{2,5,6,4,7,3,8,9,1},
	
 	{1,3,2,6,8,5,4,7,9},
	 	
	{5,9,8,7,3,4,1,6,2},
		
 	{7,6,4,2,1,9,5,3,8},
	 	
 	{4,2,7,5,6,8,9,1,3},
	 	
 	{9,1,5,3,4,2,6,8,7},
	 	
 	{6,8,3,1,9,7,2,5,4},
 	};
	int f1 = open("D:\\sudoku.bin",O_RDONLY|O_BINARY, S_IREAD|S_IWRITE);
	int f2 = open("D:\\sudoku.bin",O_CREAT|O_RDWR|O_BINARY, S_IREAD|S_IWRITE);
	gotoxy(27,3);
//	SetConsoleTextAttribute(hConsole, GREEN_COLOR);
	cout<<"Q 離開";
	gotoxy(27,6);
	cout<<"O 存檔";
	gotoxy(35,3);
	cout<<"I 讀檔";
	gotoxy(35,6);
	cout<<"R 重來";
	
 
while(!end_flag)

{
	
	for(int i=0;i<9; i++)
	{
		for(int j=0;j<9; j++)
		{
			gotoxy(j*3,i*3);
			SetConsoleTextAttribute(hConsole, GREEN_COLOR);
			cout << sudoku[i][j];
		}	
	}
	
	
	for(int k = 1; k < 255 && !end_flag; k++) {
		
		if (kbhit()) {
			char key = getch();
			int correct=0;
			switch(key){
				case 'r':
					gotoxy(x*3,y*3+1);	
					SetConsoleTextAttribute(hConsole, BLACK_COLOR);	
					cout << "X";	 	

					SetConsoleTextAttribute(hConsole, GREEN_COLOR);
					gotoxy(x*3,y*3+1);
					cout << "Reseting..";
					Sleep(700);
						
					gotoxy(x*3,y*3+1);	
					SetConsoleTextAttribute(hConsole, BLACK_COLOR);	
					cout<<"Reseting...";
					cout << "X";	
						
					SetConsoleTextAttribute(hConsole, GREEN_COLOR);
					gotoxy(x*3,y*3+1);
					cout << "X";
					for(int i=0;i<9;i++){
						for(int j=0;j<9;j++){
							sudoku[i][j]=reset[i][j];
						}
					}
					break;	
  				case 'q':
  					cout<<correct;
  					end_flag = true;
					break;
				case 'i':
					read(f1,&sudoku,sizeof(sudoku));
					gotoxy(x*3,y*3+1);	
					SetConsoleTextAttribute(hConsole, BLACK_COLOR);	
					cout << "X";	 	

					SetConsoleTextAttribute(hConsole, GREEN_COLOR);
					gotoxy(x*3,y*3+1);
					cout << "Process  loading...";
					Sleep(700);
						
					gotoxy(x*3,y*3+1);	
					SetConsoleTextAttribute(hConsole, BLACK_COLOR);	
					cout<<"Process  loading...";
					cout << "X";	
						
					SetConsoleTextAttribute(hConsole, GREEN_COLOR);
					gotoxy(x*3,y*3+1);
					cout << "X";
					break;
					
				case 'o':
					write(f2,&sudoku,sizeof(sudoku));
					close(f1);
					close(f2);
					gotoxy(x*3,y*3+1);
					SetConsoleTextAttribute(hConsole, BLACK_COLOR);
					cout << "X";
					SetConsoleTextAttribute(hConsole, GREEN_COLOR);
					gotoxy(x*3,y*3+1);
					cout << "You have saved yout process.";
					end_flag = true;
					break;
  				case 'a':
//clear old
					gotoxy(x*3,y*3+1);
					SetConsoleTextAttribute(hConsole, BLACK_COLOR);
					cout << "X";
	  				x-=1;
	  				if(x<0) x=50; 
//print new
					SetConsoleTextAttribute(hConsole, GREEN_COLOR);
					gotoxy(x*3,y*3+1);
					cout << "X";
					break;
				
  				case 'd':
//clear old
					gotoxy(x*3,y*3+1);
					SetConsoleTextAttribute(hConsole, BLACK_COLOR);
					cout << "X";
					x+=1;
					if(x>50) x=0; 
//print new
					SetConsoleTextAttribute(hConsole, GREEN_COLOR);	
					gotoxy(x*3,y*3+1);
					cout << "X";
					break;	
					
	  			case 'w':
//clear old
					gotoxy(x*3,y*3+1);
					SetConsoleTextAttribute(hConsole, BLACK_COLOR);
					cout << "X";
					y-=1;
					if(y<0) y=0; 
//print new	
					SetConsoleTextAttribute(hConsole, GREEN_COLOR);	
					gotoxy(x*3,y*3+1);	
					cout << "X";	
					break;
	
	 			 case 's':
//clear old
					gotoxy(x*3,y*3+1);	
					SetConsoleTextAttribute(hConsole, BLACK_COLOR);	
					cout << "X";	
					y+=1;	
					if(y>50) y=50; 	
//print new
					SetConsoleTextAttribute(hConsole, GREEN_COLOR);
					gotoxy(x*3,y*3+1);
					cout << "X";	
					break;

 

				case '0':	
					gotoxy(x*3,y*3+1);
					SetConsoleTextAttribute(hConsole, BLACK_COLOR);
					cout << "X";
					cout<<"0";
					SetConsoleTextAttribute(hConsole, GREEN_COLOR);
					gotoxy(x*3,y*3+1);
					cout << "X";
					cout<<"0";	
					break;
				case '1':
				
					if(x==2 && y==0 || x==6 && y==1 || x==4 && y==5 || x==7 && y==6 || x==1 && y==7 || x==3 && y==8){
						sudoku[y][x]=1;
						gotoxy(x*3,y*3+1);
						SetConsoleTextAttribute(hConsole, BLACK_COLOR);
						cout << "X";
						int correct=0;
							for(int i=0;i<9; i++){
								for(int j=0;j<9; j++){
									if(sudoku[i][j]==ans[i][j]){
										correct+=1;
									}
								}	
							}
						if(correct==81){
							SetConsoleTextAttribute(hConsole, GREEN_COLOR);
							gotoxy(x*3,y*3+1);
							cout << "Congratuation! You have finished the sudoku!";
							end_flag = true;	
						}
						else{
							SetConsoleTextAttribute(hConsole, GREEN_COLOR);
							gotoxy(x*3,y*3+1);
							cout << "X";
						}
						
					}
					else{
						
						gotoxy(x*3,y*3+1);	
						SetConsoleTextAttribute(hConsole, BLACK_COLOR);	
						cout << "X";	 	

						SetConsoleTextAttribute(hConsole, GREEN_COLOR);
						gotoxy(x*3,y*3+1);
						cout << "ERROR";
						Sleep(500);
						
						gotoxy(x*3,y*3+1);	
						SetConsoleTextAttribute(hConsole, BLACK_COLOR);	
						cout<<"ERROR";
						cout << "X";	
						
						SetConsoleTextAttribute(hConsole, GREEN_COLOR);
						gotoxy(x*3,y*3+1);
						cout << "X";
					}			
					break;
				case '2':
					
					if(x==7 && y==1 || x==2 && y==3 || x==1 && y==6 || x==6 && y==8){
						sudoku[y][x]=2;
						gotoxy(x*3,y*3+1);
						SetConsoleTextAttribute(hConsole, BLACK_COLOR);
						cout << "X";
						int correct=0;
							for(int i=0;i<9; i++){
								for(int j=0;j<9; j++){
									if(sudoku[i][j]==ans[i][j]){
										correct+=1;
									}
								}	
							}
						if(correct==81){
							SetConsoleTextAttribute(hConsole, GREEN_COLOR);
							gotoxy(x*3,y*3+1);
							cout << "Congratuation! You have finished the sudoku!";
							end_flag = true;	
						}
						else{
							SetConsoleTextAttribute(hConsole, GREEN_COLOR);
							gotoxy(x*3,y*3+1);
							cout << "X";
						}
						
					}
					else{
						gotoxy(x*3,y*3+1);	
						SetConsoleTextAttribute(hConsole, BLACK_COLOR);	
						cout << "X";	 	

						SetConsoleTextAttribute(hConsole, GREEN_COLOR);
						gotoxy(x*3,y*3+1);
						cout << "ERROR";
						Sleep(500);
						
						gotoxy(x*3,y*3+1);	
						SetConsoleTextAttribute(hConsole, BLACK_COLOR);	
						cout<<"ERROR";
						cout << "X";	
						
						SetConsoleTextAttribute(hConsole, GREEN_COLOR);
						gotoxy(x*3,y*3+1);
						cout << "X";
					}
					break;
				case '3':
					
					if(x==6 && y==0 || x==0 && y==1 || x==1 && y==3 || x==8 && y==6 || x==3 && y==7 || x==2 && y==8){
						sudoku[y][x]=3;
						gotoxy(x*3,y*3+1);
						SetConsoleTextAttribute(hConsole, BLACK_COLOR);
						cout << "X";
						int correct=0;
							for(int i=0;i<9; i++){
								for(int j=0;j<9; j++){
									if(sudoku[i][j]==ans[i][j]){
										correct+=1;
									}
								}	
							}
						if(correct==81){
							SetConsoleTextAttribute(hConsole, GREEN_COLOR);
							gotoxy(x*3,y*3+1);
							cout << "Congratuation! You have finished the sudoku!";
							end_flag = true;	
						}
						else{
							SetConsoleTextAttribute(hConsole, GREEN_COLOR);
							gotoxy(x*3,y*3+1);
							cout << "X";
						}
						
					}
					else{
						gotoxy(x*3,y*3+1);	
						SetConsoleTextAttribute(hConsole, BLACK_COLOR);	
						cout << "X";		

						SetConsoleTextAttribute(hConsole, GREEN_COLOR);
						gotoxy(x*3,y*3+1);
						cout << "ERROR";
						Sleep(500);
						
						gotoxy(x*3,y*3+1);	
						SetConsoleTextAttribute(hConsole, BLACK_COLOR);	
						cout<<"ERROR";
						cout << "X";	
						
						SetConsoleTextAttribute(hConsole, GREEN_COLOR);
						gotoxy(x*3,y*3+1);
						cout << "X";
					}
					break;
				case '4':
					
					if(x==7 && y==0 || x==3 && y==2 || x==5 && y==4 || x==2 && y==5 || x==0 && y==6 || x==4 && y==7){
						sudoku[y][x]=4;
						gotoxy(x*3,y*3+1);
						SetConsoleTextAttribute(hConsole, BLACK_COLOR);
						cout << "X";
						int correct=0;
							for(int i=0;i<9; i++){
								for(int j=0;j<9; j++){
									if(sudoku[i][j]==ans[i][j]){
										correct+=1;
									}
								}	
							}
						if(correct==81){
							SetConsoleTextAttribute(hConsole, GREEN_COLOR);
							gotoxy(x*3,y*3+1);
							cout << "Congratuation! You have finished the sudoku!";
							end_flag = true;	
						}
						else{
							SetConsoleTextAttribute(hConsole, GREEN_COLOR);
							gotoxy(x*3,y*3+1);
							cout << "X";
						}
						
					}
					else{
						gotoxy(x*3,y*3+1);	
						SetConsoleTextAttribute(hConsole, BLACK_COLOR);	
						cout << "X";	 	

						SetConsoleTextAttribute(hConsole, GREEN_COLOR);
						gotoxy(x*3,y*3+1);
						cout << "ERROR";
						Sleep(500);
						
						gotoxy(x*3,y*3+1);	
						SetConsoleTextAttribute(hConsole, BLACK_COLOR);	
						cout<<"ERROR";
						cout << "X";	
						
						SetConsoleTextAttribute(hConsole, GREEN_COLOR);
						gotoxy(x*3,y*3+1);
						cout << "X";
					}
					break;
				case '5':
					
					if(x==8 && y==0 || x==0 && y==4 || x==3 && y==6 || x==2 && y==7){
						sudoku[y][x]=5;
						gotoxy(x*3,y*3+1);
						SetConsoleTextAttribute(hConsole, BLACK_COLOR);
						cout << "X";
						int correct=0;
							for(int i=0;i<9; i++){
								for(int j=0;j<9; j++){
									if(sudoku[i][j]==ans[i][j]){
										correct+=1;
									}
								}	
							}
						if(correct==81){
							SetConsoleTextAttribute(hConsole, GREEN_COLOR);
							gotoxy(x*3,y*3+1);
							cout << "Congratuation! You have finished the sudoku!";
							end_flag = true;	
						}
						else{
							SetConsoleTextAttribute(hConsole, GREEN_COLOR);
							gotoxy(x*3,y*3+1);
							cout << "X";
						}
						
					}
					else{
						gotoxy(x*3,y*3+1);	
						SetConsoleTextAttribute(hConsole, BLACK_COLOR);	
						cout << "X";		

						SetConsoleTextAttribute(hConsole, GREEN_COLOR);
						gotoxy(x*3,y*3+1);
						cout << "ERROR";
						Sleep(500);
						
						gotoxy(x*3,y*3+1);	
						SetConsoleTextAttribute(hConsole, BLACK_COLOR);	
						cout<<"ERROR";
						cout << "X";	
						
						SetConsoleTextAttribute(hConsole, GREEN_COLOR);
						gotoxy(x*3,y*3+1);
						cout << "X";
					}
					break;
				case '6':
					
					if(x==5 && y==0 || x==8 && y==1 || x==3 && y==3 || x==1 && y==5 || x==0 && y==8){
						sudoku[y][x]=6;
						gotoxy(x*3,y*3+1);
						SetConsoleTextAttribute(hConsole, BLACK_COLOR);
						cout << "X";
						int correct=0;
							for(int i=0;i<9; i++){
								for(int j=0;j<9; j++){
									if(sudoku[i][j]==ans[i][j]){
										correct+=1;
									}
								}	
							}
						if(correct==81){
							SetConsoleTextAttribute(hConsole, GREEN_COLOR);
							gotoxy(x*3,y*3+1);
							cout << "Congratuation! You have finished the sudoku!";
							end_flag = true;	
						}
						else{
							SetConsoleTextAttribute(hConsole, GREEN_COLOR);
							gotoxy(x*3,y*3+1);
							cout << "X";
						}
					}
					else{
						gotoxy(x*3,y*3+1);	
						SetConsoleTextAttribute(hConsole, BLACK_COLOR);	
						cout << "X";		

						SetConsoleTextAttribute(hConsole, GREEN_COLOR);
						gotoxy(x*3,y*3+1);
						cout << "ERROR";
						Sleep(500);
						
						gotoxy(x*3,y*3+1);	
						SetConsoleTextAttribute(hConsole, BLACK_COLOR);	
						cout<<"ERROR";
						cout << "X";	
						
						SetConsoleTextAttribute(hConsole, GREEN_COLOR);
						gotoxy(x*3,y*3+1);
						cout << "X";
					}
					break;
				case '7':
					
					if(x==1 && y==0 || x==4 && y==2 || x==7 && y==3 || x==0 && y==5 || x==8 && y==7 || x==5 && y==8){
						sudoku[y][x]=7;
						gotoxy(x*3,y*3+1);
						SetConsoleTextAttribute(hConsole, BLACK_COLOR);
						cout << "X";
						int correct=0;
							for(int i=0;i<9; i++){
								for(int j=0;j<9; j++){
									if(sudoku[i][j]==ans[i][j]){
										correct+=1;
									}
								}	
							}
						if(correct==81){
							SetConsoleTextAttribute(hConsole, GREEN_COLOR);
							gotoxy(x*3,y*3+1);
							cout << "Congratuation! You have finished the sudoku!";
							end_flag = true;	
						}
						else{
							SetConsoleTextAttribute(hConsole, GREEN_COLOR);
							gotoxy(x*3,y*3+1);
							cout << "X";
						}
						
					}
					else{
						gotoxy(x*3,y*3+1);	
						SetConsoleTextAttribute(hConsole, BLACK_COLOR);	
						cout << "X";		

						SetConsoleTextAttribute(hConsole, GREEN_COLOR);
						gotoxy(x*3,y*3+1);
						cout << "ERROR";
						Sleep(500);
						
						gotoxy(x*3,y*3+1);	
						SetConsoleTextAttribute(hConsole, BLACK_COLOR);	
						cout<<"ERROR";
						cout << "X";	
						
						SetConsoleTextAttribute(hConsole, GREEN_COLOR);
						gotoxy(x*3,y*3+1);
						cout << "X";
					}
					break;
				case '8':
					
					if(x==0 && y==0 || x== 6 && y==2 || x==8 && y==5 || x==5 && y==6){
						sudoku[y][x]=8;
						gotoxy(x*3,y*3+1);
						SetConsoleTextAttribute(hConsole, BLACK_COLOR);
						cout << "X";
						int correct=0;
							for(int i=0;i<9; i++){
								for(int j=0;j<9; j++){
									if(sudoku[i][j]==ans[i][j]){
										correct+=1;
									}
								}	
							}
						if(correct==81){
							SetConsoleTextAttribute(hConsole, GREEN_COLOR);
							gotoxy(x*3,y*3+1);
							cout << "Congratuation! You have finished the sudoku!";
							end_flag = true;	
						}
						else{
							SetConsoleTextAttribute(hConsole, GREEN_COLOR);
							gotoxy(x*3,y*3+1);
							cout << "X";
						}
						
					}
					else{
						gotoxy(x*3,y*3+1);	
						SetConsoleTextAttribute(hConsole, BLACK_COLOR);	
						cout << "X";	 	

						SetConsoleTextAttribute(hConsole, GREEN_COLOR);
						gotoxy(x*3,y*3+1);
						cout << "ERROR";
						Sleep(500);
						
						gotoxy(x*3,y*3+1);	
						SetConsoleTextAttribute(hConsole, BLACK_COLOR);	
						cout<<"ERROR";
						cout << "X";	
						
						SetConsoleTextAttribute(hConsole, GREEN_COLOR);
						gotoxy(x*3,y*3+1);
						cout << "X";
					}
					break;
				case '9':
					
					if(x==2 && y==1 || x==5 && y==5 ){
						sudoku[y][x]=9;
						gotoxy(x*3,y*3+1);
						SetConsoleTextAttribute(hConsole, BLACK_COLOR);
						cout << "X";
						int correct=0;
							for(int i=0;i<9; i++){
								for(int j=0;j<9; j++){
									if(sudoku[i][j]==ans[i][j]){
										correct+=1;
									}
								}	
							}
						if(correct==81){
							SetConsoleTextAttribute(hConsole, GREEN_COLOR);
							gotoxy(x*3,y*3+1);
							cout << "Congratuation! You have finished the sudoku!";
							end_flag = true;	
						}
						else{
							SetConsoleTextAttribute(hConsole, GREEN_COLOR);
							gotoxy(x*3,y*3+1);
							cout << "X";
						}
						
					}
					else{
						gotoxy(x*3,y*3+1);	
						SetConsoleTextAttribute(hConsole, BLACK_COLOR);	
						cout << "X";	

						SetConsoleTextAttribute(hConsole, GREEN_COLOR);
						gotoxy(x*3,y*3+1);
						cout << "ERROR";
						Sleep(500);
						
						gotoxy(x*3,y*3+1);	
						SetConsoleTextAttribute(hConsole, BLACK_COLOR);	
						cout<<"ERROR";
						cout << "X";	
						
						SetConsoleTextAttribute(hConsole, GREEN_COLOR);
						gotoxy(x*3,y*3+1);
						cout << "X";
					}
					break;
				
				break;

 			 }
  		}

	}
		
}
}


