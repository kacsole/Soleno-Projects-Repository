/*
Soleno, Keziah Antonette C.
CS127-8l/OL162
February 2, 2021
*/
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

//global variable
bool inputerror;

//function prototype
void Instructions();
void Game();
void HighScore_File();

int main()
{
	int choice;
	char again; 
	inputerror = false;
	
	do{	
		do{
			cout<<"~~~~~~~~~~ M E N U  O P T I O N ~~~~~~~~~~"<<endl
				<<"[1] How to Play the Rock, Paper, Scissors Game"<<endl
				<<"[2] Play Rock, Paper, Scissors"<<endl
				<<"[3] Open Data File for Reading the High Score"<<endl
				<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl
				<<"Enter your choice: ";
			cin>>choice;
		
		//input validation
		inputerror = cin.fail();
		if(inputerror)
			cout<<"INVALID CHOICE! Invalid input data type. Please try again.";
		cin.clear();
		cin.ignore(5, '\n');
		}while(inputerror);
			
		switch(choice)
		{
			case 1: Instructions();
					break;
			case 2: Game();
					break;
			case 3: HighScore_File();
					break;
			default: cout<<"INVALID CHOICE! Try again.";
					break;
		}
		
		do{
			cout<<"Press [Y/y] to return to main menu or press any key to exit the game. ";
			cin>>again;
		
		//input validation	
		inputerror = cin.fail();
		if(inputerror)
			cout<<"INVALID CHOICE! Invalid input data type. Please try again.";
		cin.clear();
		cin.ignore(5, '\n');
		}while(inputerror);
		
	}while (again == 'Y'|| again == 'y'); //to repeat when user inputs Y to play again
}

void Instructions()
{
	cout<<"Hi there! Welcome to the Rock, Paper, Scissors Game!"<<endl
		<<"This game will be played by two players, Player 1 (the user) "<<endl
		<<"and Player 2 (the computer). PLayer 1 will be asked his name "<<endl
		<<"so that his name may be saved in a file displaying his respective score. "<<endl<<endl
		<<"Player 1 will be prompted to make a choice between Rock (R), Paper (P), and Scissors (S) "<<endl
		<<"while the computer generates its random choice."<<endl<<endl
		<<"The following is what determines who will be the winner between the two players: "<<endl<<endl
		<<"Rock always WINS against Scissors, but Rock always LOSES to Paper."<<endl
		<<"Paper always WINS against Rock, but Paper always LOSES to Scissors."<<endl
		<<"Scissors always WINS against Paper, but Scissors always LOSES to Rock."<<endl<<endl
		<<"Are you ready to play?"<<endl;
}

void Game()
{
	char P1, P2, retry;
	int scoreP1, scoreP2, numP2;
	string nameP1;
	
	string filename = "highscoreRPS.txt";
	ofstream outFile;

	//outFile.open("highscoreRPS.txt", ios_base::trunc);
	outFile.open(filename.c_str(), ios_base::app); 
	
	if (!outFile)
	{
		cout<<"ERROR: Cannot open data file!"<<endl
			<<"Please check that the file currently exists."<<endl;
		exit(1);
	}

	cout<<"Enter your name: ";
	getline(cin, nameP1);
    outFile<<nameP1<<"\t"; //on text file
	//cin.ignore();
	
	scoreP1 = 0;
	scoreP2 = 0;

	do{
	
		cout<<"Hi there, "<<nameP1<<"! You're Player 1, let's start the game."<<endl;

		do{
		cout<<"Input your choice (R, P, or S): ";
		cin>>P1;
		P1 = toupper(P1);
		
		inputerror = cin.fail();
		if(inputerror)
			cout<<"INVALID CHOICE! Invalid input data type. Please try again.";
		cin.clear();
		cin.ignore(5, '\n');
		
		if (P1 != 'R' && P1 != 'P' && P1 != 'S')
			cout<<"Selected choice is not within the given. Please try again."<<endl;
			
		}while(inputerror || P1 != 'R' && P1 != 'P' && P1 != 'S');
		
		srand(time(0));
		numP2 = rand() % 3;
		
		if (numP2 == 0)
			P2 = 'R';
		else if (numP2 == 1)
			P2 = 'S';
		else if (numP2 == 2)
			P2 = 'P';	
		cout<<"Player 2 (R, S, or P): "<<P2<<endl;
		
		if(P1=='R' && P2=='S')
		{   scoreP1++;
			cout<<"Player 1 Wins!"<<endl;
			cout<<"Score of Player 1 = "<<scoreP1<<endl;		 
		}
		else if(P1=='S' && P2=='R')
		{   scoreP2++;
			cout<<"Player 2 Wins!"<<endl;
			cout<<"Score of Player 2 = "<<scoreP2<<endl;
		}
		else if(P1=='P' && P2=='R')
		{   scoreP1++;
			cout<<"Player 1 Wins!"<<endl;
			cout<<"Score of Player 1 = "<<scoreP1<<endl;		 
		}
		else if(P1=='R' && P2=='P')
		{   scoreP2++;
			cout<<"Player 2 Wins!"<<endl;
			cout<<"Score of Player 2 = "<<scoreP2<<endl;		 
		}
		else if(P1=='S' && P2=='P')
		{   scoreP1++;
			cout<<"Player 1 Wins!"<<endl;
			cout<<"Score of Player 1 = "<<scoreP1<<endl;		 
		}
		else if(P1=='P' && P2=='S')
		{   scoreP2++;
			cout<<"Player 2 Wins!"<<endl;
			cout<<"Score of Player 2 = "<<scoreP2<<endl;		 
		}
		else if (P1 == P2)
		{
			cout<<"It's a tie!"<<endl;
		}
		
		do{
		cout<<"Press any key to play again or [N/n] to exit.";
		cin>>retry;
		retry = toupper(retry);
		
		inputerror = cin.fail();
		if(inputerror)
			cout<<"INVALID CHOICE! Invalid input data type. Please try again.";
		cin.clear();
		cin.ignore(5, '\n');
		}while (inputerror);

	}while(retry != 'N');
	
	outFile<<scoreP1<<endl; //displays player one score in text file

	outFile.close();
	//cin.ignore();
	 
}

void HighScore_File()
{
	string nameP1, Player1[100], temp2;
	int dataCtr = 0, scoreP1, Score1[100], temp, ctr;
	
	string filename = "highscoreRPS.txt";  //data/text file for Jack and Poy scoring
	ifstream inFile;
	
	inFile.open(filename.c_str());

	if (inFile.fail())  //check if file exist for successful open
	{
		cout<<"ERROR: Cannot open data file!"<<endl
			<<"Please check that the file currently exists."<<endl;
		exit(1);
	}
	
	cout<<endl<<"SCORES FROM HIGHEST TO LOWEST"<<endl<<endl;
	cout<<"PLAYER"<<"\t\t	SCORE"<<endl;	
	
	inFile>>nameP1>>scoreP1;  //to display the first line of date from file stream
	
	do
	{
		inFile>>nameP1>>scoreP1;
		dataCtr++;
			
	}while(!inFile.eof());

	inFile.close();
	//cin.ignore();
	
	//sorting logic (descending)
	
	inFile.open(filename.c_str());
	inFile>>nameP1>>scoreP1;
	
	do{
		for (ctr = 0; ctr<dataCtr; ctr++)
		{
			Player1[ctr] = nameP1;
			Score1[ctr] = scoreP1;
			inFile>>nameP1>>scoreP1;
		}
	}while(!inFile.eof());
	
	for(ctr = 0; ctr<dataCtr; ctr++)
	{
		for (int j=ctr+1; j<dataCtr; j++)
		{
			if (Score1[j] > Score1[ctr])
			{
				temp = Score1[ctr];
				temp2 = Player1[ctr];
				
				Score1[ctr] = Score1[j];
				Player1[ctr] = Player1[j];
				
				Score1[j] = temp;
				Player1[j] = temp2;
			}
		}
	}
		
	for (ctr = 0; ctr<dataCtr; ctr++)
	{
		cout<<Player1[ctr]<<"\t\t	"<<Score1[ctr]<<endl;
	}
	
	inFile.close();
	cin.ignore();
	
}

