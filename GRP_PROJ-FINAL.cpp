 /*
* Programmers: 	Franco, Jose Rafael A. 
				Lagarto, Miguel Andrine
				San Pedro, Paulo
				Soleno, Keziah Antonette
				
*Purpose: This program is focused on buying, selling and stocking of goods. In the menu part, the user will be asked whether he/she is a customer, administrator, or
wants to exit. If the customer option will be selected, all items for sale will be displayed. This specific transaction will include all functions particular with 
buying of products. There will be sections for meat, dairy, and basic necessities.

* Date Created: 01/31/2021

* Program: BSCS

* Course / Section: CS127-8L/OL162
*/

#include <iostream> 
#include <string>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <fstream>
using namespace std;

//global variable
bool inputerror;
int MeatStock = 5;
int DairyStock = 5;
int BasicNec = 5;
int meat_stocks, dairy_stock, bNec_stock;	
double cash;
double meatTotal = 0, dairyTotal = 0, basicNTotal = 0, CustomerTotal = 0;
//ofstream outFile ("Meat Stocks.txt", ios_base::app);
//ifstream inFile ("Number of Stocks.txt");
//ofstream outFile("Number of Stocks.txt", ios_base::trunc);

//struct
struct AdminType
{
	int meat_code[5], dairy_code[5], basicN_code[5];
	string meat_name[5], dairy_name[5], basicN_name[5];
	int meat_price[5], dairy_price[5], basicN_price[5];
};
//global variable
AdminType Products;

//function prototype
void Cus();
void Ad();
void password();
void LogIn();

int main()
{
	int ch;
	char repeat;
	
	do  {
	system ("cls");	
		do{
		system("cls");
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      FRALASO Grocery Store     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"[1] Customer "<<endl;
		cout<<"[2] Admin"<<endl;
		cout<<"[3] Exit"<<endl
			<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		
		inputerror = cin.fail();
		if(inputerror)
		cout<<"INVALID INPUT! Invalid input data type. Please try again."<<endl;
		cin.clear();
		cin.ignore(3, '\n');
		
		system("pause");
		}while(inputerror);
		
	
			switch (ch)
			{
			case 1: LogIn();
					Cus(); //function call
				break;
			case 2: Ad();//function call
					password();//function call
				break;
			case 3: cout<<"Thank you for shopping at FRALASO Grocery Store! Until next time!"<<endl;
				break;
	    	default: cout<<"INVALID CHOICE!"<<endl;
			}
		
		cout<<"\nPress any key to return to the main menu or [N/n] to exit FRALASO Grocery Store."<<endl;
		cin>>repeat;
		repeat = tolower(repeat);
		}while(repeat != 'n');

}

void LogIn ()
{
	string username, password;
	string Inusername, Inpassword;
	string Rusername, Rpassword;
	int choice;
	char login;
	ofstream file;
	ifstream elif;
	
	do{
		do{	
		system("cls");
		cout<<"CUSTOMER'S REGISTRATION/LOG-IN OPTIONS"<<endl
			<<"[1] Register Account"<<endl
			<<"[2] Log-In to Existing Account"<<endl
			<<"[3] Exit"<<endl
			<<"Enter your choice: ";
		cin>>choice;
		
		inputerror = cin.fail();
		if (inputerror)
			cout<<"INVALID INPUT! Invalid input data type. Please try again.\n";
		cin.clear();
		cin.ignore(3, '\n');
		}while(inputerror);
		
		
		switch (choice)
		{
			case 1: file.open("registration.txt");
				if (!file.is_open())
				{
					cout<<"Cannot Locate File";		
				}
				
			cout<<"New Username: ";
			//cin.clear();
			cin.ignore(3, '\n');
			getline(cin, Rusername);
			file<<Rusername;
			file<<'\n';
			
			cout<<"New Password: ";
			//cin.clear();
			cin.ignore(3, '\n');
			getline(cin, Rpassword);
			file<<Rpassword;
			Rpassword = getch();
			
			file.close();
			
			cout<<"You have successfully registered for a new account!\n";
			break;
			
			case 2: elif.open("registration.txt");
			if (!elif.is_open())
			{
				cout<<"Cannot Locate File";	
			}
			
			getline(elif, Rusername, '\n');
			getline(elif, Rpassword, '\n');
			
			username = Rusername;
			password = Rpassword;
			elif.close();
			
				system ("cls");
				cout<<"Enter Username: ";
				//cin.clear();
				cin.ignore(3, '\n');
				getline(cin, Inusername);
				
				cout<<"Enter Password: ";
				//cin.clear();
				cin.ignore(3, '\n');
				getline(cin, Inpassword);
				
				if (Inusername == username && Inpassword == password)
				{
					cout<<"You have Logged-In Successfully!"<<endl
						<<"Welcome "<<Inusername<<"!";
				}
				else 
					cout<<"Incorrect Username/Password!"<<endl;
					
			break;
			case 3: exit (0);
			default: "INVALID CHOICE! Please try again.\n";
		}
		
		do{
		cout<<"\nPress any key to return to log-in menu or [N/n] to exit the log-in menu. ";
		cin>>login;
		login = toupper(login);
		
		inputerror = cin.fail();
		if (inputerror)
			cout<<"INVALID INPUT! Invalid input data type.\n";
		cin.clear();
		cin.ignore(5,'\n');
		
		}while (inputerror);
		
		}while(login != 'N');
	//return Cus ();
}

void Ad()
{
	system("cls");
	cout<<"Administrator's Office"<<endl;
}

string EnterPassword()
{
   //add code here
    string password=""; //programming 
    char ch=getch();
   
    do
    {
	   if(ch=='\b') //if 'backspce' key is pressed
	   	{
			if (password.size() != 0) //if the password string contains data, erase last character
			   {
				   cout<<"\b \b";
				   password.erase(password.size() - 1, 1);
			   }
			ch=getch();
		}
		
		else
		{
			cout<<'*'; //***********
			password+=ch;
			ch=getch(); //enter
		}
				
    }while (ch!='\r');
   return password;

}  // end EnterPassword

void password()//also admin
{
	AdminType Products;
	int ctr, choice;
	inputerror = false;
	char again;
	int AD_choice;
	ofstream outFile;
	int PcodeMeat;
	
   cout<<"Enter Password: ";
   string password=EnterPassword(); //"programming"
   int attempts=1;

    if(password=="administrator")
    {  cout<<"\nloading your password";
		for(int i=1;i<=13;i++)
		{	Sleep(100);
			cout<<".";
		}
 	} 	
	else
   	{   
   		cout<<"\nloading your password";
       	for (int i=1;i<=13;i++)
		{	
			Sleep(100);
			cout<<".";
		}
   		system("cls");

		while (password != "administrator" && attempts < 3)  // 3 attempts will be given
		{
			cout<<"Incorrect password. Your attempts remaining: "<<3-attempts<<"\n";
			cout<<"Please re-enter your password: ";
			password = EnterPassword(); //"programming"
			attempts++;
			system("cls");
		}
		
		 if (password == "administrator" && attempts <= 3)
   	 	{
        	cout << "\nloading your password";
        	for(int i=1;i<=13;i++)
			{	
				Sleep(100);
				cout<<".";
			}
			cout<<" \n";
        	system ("cls");
    	}
    	
    	else
    	{
			cout<<"You have reached the [3] maximum attempt for password"<<endl;
			exit(0);
		}
	}
	
			do{
				system("cls");
			do{
				system("pause");
				system("cls");
				cout<<"Welcome, Administrator! What would you like to do today?"<<endl;
				cout<<"~~~~~~~~~~~~~~~ ADMINISTRATOR OPTIONS ~~~~~~~~~~~~~~~~~"<<endl
					<<"[1] Add an Item"<<endl
					<<"[2] Delete an Item"<<endl
					<<"[3] Exit"<<endl //item numbering, adding, modifying, deleting an item
					<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl
					<<"Enter your choice: ";
				cin>>choice;
		
			inputerror = cin.fail();
			if(inputerror)
				cout<<"INVALID INPUT! Invalid input data type. Please try again."<<endl;
			cin.clear();
			cin.ignore(3,'\n');
			
			}while(inputerror);
	
				switch(choice)
				{
				case 1: 
						if (outFile.fail())
						{
							cout<<"ERROR: Cannot open text file!"<<endl
								<<"Please check that the file currently exists."<<endl;
							exit(1);
						}
						
						system("cls");
						cout<<"What type of product would you like to add?"<<endl
							<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl
							<<"[1] Meat"<<endl
							<<"[2] Dairy"<<endl
							<<"[3] Basic Necessities"<<endl
							<<"[4] Exit"<<endl
							<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl
							<<"Enter your choice: ";
						cin>>AD_choice;
						
						switch(AD_choice)
						{
							case 1: //outFile.open("Meat Stocks.txt", ios_base::trunc);
									outFile.open("Meat Stocks.txt", ios_base::app); //MeatStock is a global variable to be used by Cus() also
									
									do{
									system ("cls");
									cout<<"How many stocks do you want to add? (1-5 items only) ";
									cin>>meat_stocks;
									
									inputerror = cin.fail();
									if (inputerror)
										cout<<"INVALID INPUT! Invalid input data type. Please try again."<<endl;
									cin.clear();
									cin.ignore(3, '\n');
									
									
									MeatStock = MeatStock + meat_stocks;
									if (MeatStock > 10)
									{
										cout<<"All available stocks of this section are occupied."<<endl;
										MeatStock = MeatStock - meat_stocks;
									}
									else
									{
									//to be put into file stream
									outFile<<"\nNEW ITEMS ADDED\n";
									for (ctr = 0; ctr<meat_stocks; ctr++)
									{
										do{
										system ("cls");
										cout<<"Enter product code: ";
										cin>>Products.meat_code[ctr]; //product code from 16+ only (no 1-15)
										//cin.ignore();				//input new product code into text file that will later be put into customer	
										
										inputerror = cin.fail();
										if (inputerror)
											cout<<"INVALID INPUT! Invalid input data type. Please try again."<<endl;
										cin.clear();
										cin.ignore(3, '\n');
										
										if (Products.meat_code[ctr] < 16)
											cout<<"Product code "<<Products.meat_code[ctr]<<" is already in use. Please input a different code."<<endl;
										else
											outFile<<Products.meat_code[ctr]<<"\t\t\t\t";
											
										system("pause");
										
										}while(Products.meat_code[ctr] < 16 || inputerror);
										
										cout<<"Enter product name: ";
										getline(cin, Products.meat_name[ctr]);
										outFile<<Products.meat_name[ctr]<<"\t\t\t\t";
										
										cout<<"Enter product price: P";
										cin>>Products.meat_price[ctr];
										outFile<<"P"<<Products.meat_price[ctr]<<"\n";
									}
									cout<<"\nNew no. of stocks: \n"<<MeatStock<<"\n";
									cout<<"NOTE: New items are not available for purchasing at the moment. Sorry for the inconvenience.\n";
									}
									
									}while(MeatStock > 10 || inputerror);
									
									outFile.close();
									break;
							case 2: //outFile.open("Dairy Stocks.txt", ios_base::trunc);
									outFile.open("Dairy Stocks.txt", ios_base::app); //MeatStock is a global variable to be used by Cus() also
									
									do{
									system ("cls");
									cout<<"How many stocks do you want to add? (1-5 items only) "; //use dynamic array/pointers
									cin>>dairy_stock;
									
									inputerror = cin.fail();
									if (inputerror)
										cout<<"INVALID INPUT! Invalid input data type. Please try again."<<endl;
									cin.clear();
									cin.ignore(3, '\n');
									
									
									DairyStock = DairyStock + dairy_stock;
									if (DairyStock > 10)
									{
										cout<<"All available stocks of this section are occupied."<<endl;
										DairyStock = DairyStock - dairy_stock;
									}
									else
									{
									//to be put into file stream
									outFile<<"\nDAIRY STOCKS: NEW ITEMS ADDED\n";
									for (ctr = 0; ctr<dairy_stock; ctr++)
									{
										do{
										system ("cls");
										cout<<"Enter product code: ";
										cin>>Products.dairy_code[ctr]; //product code from 16+ only (no 1-15)	
										
										inputerror = cin.fail();
										if (inputerror)
											cout<<"INVALID INPUT! Invalid input data type. Please try again."<<endl;
										cin.clear();
										cin.ignore(3, '\n');
										
										if (Products.dairy_code[ctr] < 16)
											cout<<"Product code "<<Products.dairy_code[ctr]<<" is already in use. Please input a different code."<<endl;
										else
											outFile<<Products.dairy_code[ctr]<<"\t\t\t\t";
										system("pause");
										}while(Products.dairy_code[ctr] < 16 || inputerror);
										
										cout<<"Enter product name: ";
										cin.ignore();
										getline(cin, Products.dairy_name[ctr]);
										outFile<<Products.dairy_name[ctr]<<"\t\t\t\t";
										
										cout<<"Enter product price: P";
										cin>>Products.dairy_price[ctr];
										outFile<<"P"<<Products.dairy_price[ctr]<<"\n";
									}
									cout<<"\nNew no. of stocks: \n"<<DairyStock<<"\n";
									cout<<"NOTE: New items are not available for purchasing at the moment. Sorry for the inconvenience.\n";
									}
									outFile.close();
									}while(inputerror || DairyStock > 10);
									break;
							case 3: //outFile.open("Basic Necessities Stocks.txt", ios_base::trunc);
									outFile.open("Basic Necessities Stocks.txt", ios_base::app); //MeatStock is a global variable to be used by Cus() also
									
									do{
									system ("cls");
									cout<<"How many stocks do you want to add? (1-5 items only) ";
									cin>>bNec_stock;
									
									inputerror = cin.fail();
									if (inputerror)
										cout<<"INVALID INPUT! Invalid input data type. Please try again."<<endl;
									cin.clear();
									cin.ignore(3, '\n');
									
									
									BasicNec = BasicNec + bNec_stock;
									if (BasicNec > 10)
									{
										cout<<"All available stocks of this section are occupied."<<endl;
										BasicNec = BasicNec - bNec_stock;
									}
									else
									{
									//to be put into file stream
									outFile<<"\nBASIC NECESSITIES: NEW ITEMS ADDED\n";
									for (ctr = 0; ctr<bNec_stock; ctr++)
									{
											do{
										system ("cls");
										cout<<"Enter product code: ";
										cin>>Products.basicN_code[ctr]; //product code from 16+ only (no 1-15)
										//cin.ignore();				//input new product code into text file that will later be put into customer	
										
										inputerror = cin.fail();
										if (inputerror)
											cout<<"INVALID INPUT! Invalid input data type. Please try again."<<endl;
										cin.clear();
										cin.ignore(3, '\n');
										
										if (Products.basicN_code[ctr] < 16)
											cout<<"Product code "<<Products.basicN_code[ctr]<<" is already in use. Please input a different code."<<endl;
										else
											outFile<<Products.basicN_code[ctr]<<"\t\t\t\t";
											system("pause");
										}while(Products.basicN_code[ctr] < 16 || inputerror);
										
										cout<<"Enter product name: ";
										getline(cin, Products.basicN_name[ctr]);
										outFile<<Products.basicN_name[ctr]<<"\t\t\t\t";
										
										cout<<"Enter product price: P";
										cin>>Products.basicN_price[ctr];
										outFile<<"P"<<Products.basicN_price[ctr]<<"\n";
									}
									cout<<"\nNew no. of stocks: "<<BasicNec<<"\n";
									cout<<"NOTE: New items are not available for purchasing at the moment. Sorry for the inconvenience.\n";
									}
									outFile.close();
									}while(BasicNec > 10 || inputerror);
								}
								break;
								
				case 2: //Delete ALl Items Option
				
						if (outFile.fail())
						{
							cout<<"ERROR: Cannot open text file!"<<endl
								<<"Please check that the file currently exists."<<endl;
							exit(1);
						}
						
						system("cls");
						cout<<"What type of product would you like to delete?"<<endl
							<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl
							<<"[1] Meat"<<endl
							<<"[2] Dairy"<<endl
							<<"[3] Basic Necessities"<<endl
							<<"[4] Exit"<<endl
							<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl
							<<"Enter your choice: ";
						cin>>AD_choice;
						
						switch(AD_choice)
						{
							case 1: //outFile.open("Meat Stocks.txt", ios_base::trunc);
							     	outFile.open("Meat Stocks.txt", ios_base::trunc); //MeatStock is a global variable to be used by Cus() also
			      			 	break; 	
			 				case 2: //outFile.open("Dairy Stocks.txt", ios_base::trunc);
				 					outFile.open("Dairy Stocks.txt", ios_base::trunc); //MeatStock is a global variable to be used by Cus() also
				           	 	break;	
							case 3: //outFile.open("Basic Necessities Stocks.txt", ios_base::trunc);
									outFile.open("Basic Necessities Stocks.txt", ios_base::trunc); //MeatStock is a global variable to be used by Cus() also
   								break;
   							case 4: exit (0);
   								break;
						}
						
						
				case 3: cout<<"You have exited the Administrator Menu."<<endl;
						break;	
				default: cout<<"INVALID CHOICE!"<<endl;
				
				outFile.close();
				}
				
				cout<<"Press any key to return to Administrator Menu or [N/n] to exit Administrator Menu.";
				cin>>again; 
				again = tolower(again);
				
			}while(again != 'n');
}
void Cus()
{
	AdminType Products;
	inputerror = false;
	int choice, ctr, TotalAmt[10];
	int items1; //meat
	int items; //dairy
	int items2; //basic necessities
	int Meat_Pcode[10], Meat_Qty[10];
	int Dairy_Pcode[10], Dairy_Qty[10];
	int BasicN_Pcode[10], BasicN_Qty[10];
	int Quan;
	char again, shop;
	//meat
	int PMeat = 78, Poultry = 100, Pork = 650, Beef = 650, Ham= 650;
	int AmtofPM = 0, AmtofPou = 0, AmtofPor = 0, AmtofBe = 0, AmtofH = 0;
	//dairy
	int Milk = 81, Butter = 600, Cheese = 820, Yogurt = 65, IceCream = 165;
	int AmtofM = 0, AmtofB = 0, AmtofC = 0, AmtofY = 0, AmtofIC = 0;
	//basic necessities
	int Water = 20, FirstAid = 277, Shampoo = 231, Bedsheet = 650, Rice = 60;
	int AmtofW = 0, AmtofFA = 0, AmtofS = 0, AmtofBS = 0, AmtofR = 0;
	double cash;
	double meatTotal = 0, dairyTotal = 0, basicNTotal = 0, CustomerTotal = 0;
	ifstream inFile;
	string line;
	ofstream outFile("Customer Invoice.txt");
	//ofstream outFile("Customer Invoice.txt", ios_base::trunc);
	//ofstream outFile("Customer Invoice.txt", ios_base::app); remove forward slashes when done with program 
	
		if (outFile.fail())
		{					
			cout<<"ERROR: Cannot open text file!"<<endl
				<<"Please check that the file currently exists."<<endl;
				exit(1);
		}
		else
		{
		 do{
	 	system("cls");
	 	cout<<"~~~~~~~~~~~~~~~ MEAT, DAIRY, BASIC NECESSITIES ~~~~~~~~~~~~~~"<<endl
	 		<<"[1] Meat"<<endl
	 		<<"[2] Dairy"<<endl
	 		<<"[3] Basic Necessities"<<endl
	 		<<"[4] Exit"<<endl
	 		<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl
	 		<<"Enter your choice: ";
	 	cin>>choice;
	 	
	 	inputerror = cin.fail();
	 	if(inputerror)
	 	cout<<"INVALID INPUT! Invalid input data type."<<endl;
	 	cin.clear();
	 	cin.ignore(3, '\n');
	 	
	 	switch(choice)
	 	{
		 
		case 1:
			{
				inFile.open("Meat Stocks.txt", ios_base::app);
				if (inFile.fail())
				{					
					cout<<"ERROR: Cannot open text file!"<<endl
						<<"Please check that the file currently exists."<<endl;
					exit(1);
				}
				
				system("cls");
				cout<<endl<<"=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~ Meat Section =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~"<<endl
					<<"PRODUCT CODE			ITEM NAME			PRICE"<<endl
					<< "01				Processed Meat				P78"<<endl
					<< "02				Poultry				P100"<<endl
					<< "03				Pork				P650"<<endl
					<< "04				Beef				P650"<<endl
					<< "05				Ham				P650"<<endl;
				while (!inFile.eof())
				{
					getline(inFile, line);
					cout<<line<<endl;
				}
				cout<<endl<<"=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~"<<endl;
				do{			
				cout<<"How many items would you like to buy? ";
				cin>>items1; //don't forget validation
				
				inputerror = cin.fail();
				if (inputerror)
					cout<<"INVALID INPUT! Invalid input data type. Please try again.\n";
				cin.clear();
				cin.ignore(5, '\n');
				
				}while(inputerror);
				
				for (ctr = 0; ctr<items1; ctr++)
				{
					do{
				cout<<"Enter product code: ";
				cin>>Meat_Pcode[ctr];
				
				inputerror = cin.fail();
				if (inputerror)
					cout<<"INVALID INPUT! Invalid input data type. Please try again."<<endl;
				cin.clear();
				cin.ignore(5, '\n');
				
				if (Meat_Pcode[ctr] < 1 || Meat_Pcode[ctr] > 5)
					cout<<"Product code not found within this section. Please enter appropriate product code.\n";
					}while(Meat_Pcode[ctr] < 1 || Meat_Pcode[ctr] > 5 || inputerror);
					
				cout<<"Enter quantity: ";//consider amount of stocks?
				cin>>Meat_Qty[ctr];
			
				if (Meat_Pcode[ctr] == 1)
				{
					cout<<"("<<Meat_Qty[ctr]<<")"<<" Processed Meat has been added to cart.\n"<<endl;
					AmtofPM = Meat_Qty[ctr] * PMeat;
					TotalAmt[ctr] = AmtofPM;
				}
				else if (Meat_Pcode[ctr] == 2)
				{
					cout<<"("<<Meat_Qty[ctr]<<")"<<" Poultry has been added to cart.\n"<<endl;
					AmtofPou = Meat_Qty[ctr] * Poultry;
					TotalAmt[ctr] = AmtofPou;
				}
				else if (Meat_Pcode[ctr] == 4)
				{
					cout<<"("<<Meat_Qty[ctr]<<")"<<" Beef has been added to cart.\n"<<endl;
					AmtofBe = Meat_Qty[ctr] * Beef;
					TotalAmt[ctr] = AmtofBe;
				}
				else if (Meat_Pcode[ctr] == 3)
				{
					cout<<"("<<Meat_Qty[ctr]<<")"<<" Pork has been added to cart.\n"<<endl;
					AmtofPor = Meat_Qty[ctr] * Pork;
					TotalAmt[ctr] = AmtofPor;
				}
				else if (Meat_Pcode[ctr] == 5)
				{
					cout<<"("<<Meat_Qty[ctr]<<")"<<" Ham has been added to cart.\n"<<endl;
					AmtofH = Meat_Qty[ctr] * Ham;
					TotalAmt[ctr] = AmtofH;
				}
				else
				{
					cout<<"INVALID CHOICE! Please try again."<<endl; 
				}
				//input logic on new products added
		
				meatTotal = meatTotal + AmtofPM + AmtofPou + AmtofPor + AmtofBe + AmtofH; //to be used at the end of all switch cases
				}
				
				
				cout<<"ITEMS PURCHASED: \n";
				outFile<<"ITEMS PURCHASED\n";
				outFile<<"========================================\n";
				for (ctr = 0; ctr<items1; ctr++)
				{
					if (Meat_Pcode[ctr] == 1)
					{	
						//let product code come before product name
						cout<<Meat_Pcode[ctr]<<" Processed Meat "<<" x "<<Meat_Qty[ctr]<<" = P"<<TotalAmt[ctr]<<endl;
						outFile<<Meat_Pcode[ctr]<<" Processed Meat "<<" x "<<Meat_Qty[ctr]<<" = P"<<TotalAmt[ctr]<<endl;
					}
					else if (Meat_Pcode[ctr] == 2)
					{
						cout<<Meat_Pcode[ctr]<<" Poultry "<<" x "<<Meat_Qty[ctr]<<" = P"<<TotalAmt[ctr]<<endl;
						outFile<<Meat_Pcode[ctr]<<" Poultry "<<" x "<<Meat_Qty[ctr]<<" = P"<<TotalAmt[ctr]<<endl;
					}
					else if (Meat_Pcode[ctr] == 3)
					{	cout<<Meat_Pcode[ctr]<<" Pork "<<" x "<<Meat_Qty[ctr]<<" = P"<<TotalAmt[ctr]<<endl;
						outFile<<Meat_Pcode[ctr]<<" Pork "<<" x "<<Meat_Qty[ctr]<<" = P"<<TotalAmt[ctr]<<endl;
					}
					else if (Meat_Pcode[ctr] == 4)
					{
						cout<<Meat_Pcode[ctr]<<" Beef "<<" x "<<Meat_Qty[ctr]<<" = P"<<TotalAmt[ctr]<<endl;
						outFile<<Meat_Pcode[ctr]<<" Beef "<<" x "<<Meat_Qty[ctr]<<" = P"<<TotalAmt[ctr]<<endl;
					}
					else if (Meat_Pcode[ctr] == 5)
					{
						cout<<Meat_Pcode[ctr]<<" Ham "<<" x "<<Meat_Qty[ctr]<<" = P"<<TotalAmt[ctr]<<endl;
						outFile<<Meat_Pcode[ctr]<<" Ham "<<" x "<<Meat_Qty[ctr]<<" = P"<<TotalAmt[ctr]<<endl;
					}
				}
				cout<<endl;
				inFile.close();
			}
			break;	 	
			 			 	
		case 2:
 			{
 				inFile.open("Dairy Stocks.txt", ios_base::app);
 				if (inFile.fail())
				{					
					cout<<"ERROR: Cannot open text file!"<<endl
						<<"Please check that the file currently exists."<<endl;
					exit(1);
				}
			
 				system("cls");
				cout<<endl<<"=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~ Dairy Section =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~"<<endl;
				cout<<"PRODUCT CODE			ITEM NAME			PRICE"<<endl;
				cout<< "06				Pure Milk (1L)				P81"<<endl;
				cout<< "07				Butter				P600"<<endl;
				cout<< "08				Mozarella Cheese (2.5kgs)		P820"<<endl;
				cout<< "09				Yogurt (125g)				P65"<<endl;
				cout<< "10				Ice Cream (1.3L)			P165"<<endl;
					while (!inFile.eof())
					{
						getline(inFile, line);
						cout<<line<<endl;
					}
				cout<<"=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~"<<endl;
				do{			
				cout<<"How many items would you like to buy? ";
				cin>>items; //don't forget validation
				
				inputerror = cin.fail();
				if (inputerror)
					cout<<"INVALID INPUT! Invalid input data type. Please try again.\n";
				cin.clear();
				cin.ignore(5, '\n');
				
				}while(inputerror);
				
				for (ctr = 0; ctr<items; ctr++)
				{
					do{
				cout<<"Enter product code: ";
				cin>>Dairy_Pcode[ctr];
				
				inputerror = cin.fail();
				if (inputerror)
					cout<<"INVALID INPUT! Invalid input data type. Please try again."<<endl;
				cin.clear();
				cin.ignore(5, '\n');
				
				if (Dairy_Pcode[ctr] < 6 || Dairy_Pcode[ctr] > 9)
					cout<<"Product code not found within this section. Please enter appropriate product code.\n";
					}while(Dairy_Pcode[ctr] < 6 || inputerror || Dairy_Pcode[ctr] >  10);
					
				cout<<"Enter quantity: ";//consider amount of stocks?
				cin>>Dairy_Qty[ctr];
			
				if (Dairy_Pcode[ctr] == 6)
				{
					cout<<"("<<Dairy_Qty[ctr]<<")"<<" Pure Milk (1L) has been added to cart.\n"<<endl;
					AmtofM = Dairy_Qty[ctr] * Milk;
					TotalAmt[ctr] = AmtofM;
				}
				else if (Dairy_Pcode[ctr] == 7)
				{
					cout<<"("<<Dairy_Qty[ctr]<<")"<<" Butter has been added to cart.\n"<<endl;
					AmtofB = Dairy_Qty[ctr] * Butter;
					TotalAmt[ctr] = AmtofB;
				}
				else if (Dairy_Pcode[ctr] == 8)
				{
					cout<<"("<<Dairy_Qty[ctr]<<")"<<" Mozarella Cheese (2.5kgs) has been added to cart.\n"<<endl;
					AmtofC = Dairy_Qty[ctr] * Cheese;
					TotalAmt[ctr] = AmtofC;
				}
				else if (Dairy_Pcode[ctr] == 9)
				{
					cout<<"("<<Dairy_Qty[ctr]<<")"<<" Yogurt (125g) has been added to cart.\n"<<endl;
					AmtofY = Dairy_Qty[ctr] * Yogurt;
					TotalAmt[ctr] = AmtofY;
				}
				else if (Dairy_Pcode[ctr] == 10)
				{
					cout<<"("<<Dairy_Qty[ctr]<<")"<<" Ice Cream (1.3L) has been added to cart.\n"<<endl;
					AmtofIC = Dairy_Qty[ctr] * IceCream;
					TotalAmt[ctr] = AmtofIC;
				}
				else
				{
					cout<<"INVALID CHOICE! Please try again."<<endl; 
				}
				//input logic on new products added
		
				dairyTotal = dairyTotal + AmtofM + AmtofB + AmtofC + AmtofY + AmtofIC; //to be used at the end of all switch cases
				}
				
				
				cout<<"ITEMS PURCHASED: \n";
				outFile<<"ITEMS PURCHASED\n";
				outFile<<"========================================\n";
				for (ctr = 0; ctr<items; ctr++)
				{
					if (Dairy_Pcode[ctr] == 6)
					{	
						//let product code come before product name
						cout<<Dairy_Pcode[ctr]<<" Pure Milk (1L) "<<" x "<<Dairy_Qty[ctr]<<" = P"<<TotalAmt[ctr]<<endl;
						outFile<<Dairy_Pcode[ctr]<<" Pure Milk (1L) "<<" x "<<Dairy_Qty[ctr]<<" = P"<<TotalAmt[ctr]<<endl;
					}
					else if (Dairy_Pcode[ctr] == 7)
					{
						cout<<Dairy_Pcode[ctr]<<" Butter "<<" x "<<Dairy_Qty[ctr]<<" = P"<<TotalAmt[ctr]<<endl;
						outFile<<Dairy_Pcode[ctr]<<" Butter "<<" x "<<Dairy_Qty[ctr]<<" = P"<<TotalAmt[ctr]<<endl;
					}
					else if (Dairy_Pcode[ctr] == 8)
					{	cout<<Dairy_Pcode[ctr]<<" Mozarella Cheese (2.5kgs) "<<" x "<<Dairy_Qty[ctr]<<" = P"<<TotalAmt[ctr]<<endl;
						outFile<<Dairy_Pcode[ctr]<<" Mozarella Cheese (2.5kgs) "<<" x "<<Dairy_Qty[ctr]<<" = P"<<TotalAmt[ctr]<<endl;
					}
					else if (Dairy_Pcode[ctr] == 9)
					{
						cout<<Dairy_Pcode[ctr]<<" Yogurt (125g) "<<" x "<<Dairy_Qty[ctr]<<" = P"<<TotalAmt[ctr]<<endl;
						outFile<<Dairy_Pcode[ctr]<<" Yogurt (125g) "<<" x "<<Dairy_Qty[ctr]<<" = P"<<TotalAmt[ctr]<<endl;
					}
					else if (Dairy_Pcode[ctr] == 10)
					{
						cout<<Dairy_Pcode[ctr]<<" Ice Cream (1.3L) "<<" x "<<Dairy_Qty[ctr]<<" = P"<<TotalAmt[ctr]<<endl;
						outFile<<Dairy_Pcode[ctr]<<" Ice Cream (1.3L) "<<" x "<<Dairy_Qty[ctr]<<" = P"<<TotalAmt[ctr]<<endl;
					}
				}
				cout<<endl;
				inFile.close();
			}
			break;
			
		case 3:
			{
				inFile.open("Basic Necessities Stocks.txt", ios_base::app);
				if (inFile.fail())
				{					
					cout<<"ERROR: Cannot open text file!"<<endl
						<<"Please check that the file currently exists."<<endl;
					exit(1);
				}
				system("cls");
				cout<<endl<<"=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~ Basic Necessities Section =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~"<<endl;
				cout<<"PRODUCT CODE			ITEM NAME			PRICE"<<endl;
				cout<< "11				Bottled Water (500ml)				P20"<<endl;
				cout<< "12				First Aid Kit				P277"<<endl;
				cout<< "13				Shampoo				P231"<<endl;
				cout<< "14				Bedsheet			P650"<<endl;
				cout<< "15				Rice				P60 per 1 Kilo"<<endl;
					while (!inFile.eof())
					{
						getline(inFile, line);
						cout<<line<<endl;
					}
				cout<<"=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~"<<endl;
				do{			
				cout<<"How many items would you like to buy? ";
				cin>>items2; //don't forget validation
				
				inputerror = cin.fail();
				if (inputerror)
					cout<<"INVALID INPUT! Invalid input data type. Please try again.\n";
				cin.clear();
				cin.ignore(5, '\n');
				
				}while(inputerror);
				
				for (ctr = 0; ctr<items2; ctr++)
				{
					do{
				cout<<"Enter product code: ";
				cin>>BasicN_Pcode[ctr];
				
				inputerror = cin.fail();
				if (inputerror)
					cout<<"INVALID INPUT! Invalid input data type. Please try again."<<endl;
				cin.clear();
				cin.ignore(5, '\n');
				
				if (BasicN_Pcode[ctr] < 11 || BasicN_Pcode[ctr] > 15)
					cout<<"Product code not found within this section. Please enter appropriate product code.\n";
					}while(BasicN_Pcode[ctr] < 11 || BasicN_Pcode[ctr] > 15 || inputerror);
					
				cout<<"Enter quantity: ";//consider amount of stocks?
				cin>>BasicN_Qty[ctr];
			
				if (BasicN_Pcode[ctr] == 11)
				{
					cout<<"("<<BasicN_Qty[ctr]<<")"<<" Bottled Water (500ml) has been added to cart.\n"<<endl;
					AmtofW = BasicN_Qty[ctr] * Water;
					TotalAmt[ctr] = AmtofW;
				}
				else if (BasicN_Pcode[ctr] == 12)
				{
					cout<<"("<<BasicN_Qty[ctr]<<")"<<" First Aid Kit has been added to cart.\n"<<endl;
					AmtofFA = BasicN_Qty[ctr] * FirstAid;
					TotalAmt[ctr] = AmtofFA;
				}
				else if (BasicN_Pcode[ctr] == 13)
				{
					cout<<"("<<BasicN_Qty[ctr]<<")"<<" Shampoo has been added to cart.\n"<<endl;
					AmtofS = BasicN_Qty[ctr] * Shampoo;
					TotalAmt[ctr] = AmtofS;
				}
				else if (BasicN_Pcode[ctr] == 14)
				{
					cout<<"("<<BasicN_Qty[ctr]<<")"<<" Bedsheet has been added to cart.\n"<<endl;
					AmtofBS = BasicN_Qty[ctr] * Bedsheet;
					TotalAmt[ctr] = AmtofBS;
				}
				else if (BasicN_Pcode[ctr] == 15)
				{
					cout<<"("<<BasicN_Qty[ctr]<<")"<<" Rice has been added to cart.\n"<<endl;
					AmtofR = BasicN_Qty[ctr] * Rice;
					TotalAmt[ctr] = AmtofR;
				}
				else
				{
					cout<<"INVALID CHOICE! Please try again."<<endl; 
				}
				//input logic on new products added
		
				basicNTotal = basicNTotal + AmtofW + AmtofFA + AmtofS + AmtofBS + AmtofR; //to be used at the end of all switch cases
				}
				
				
				cout<<"ITEMS PURCHASED: \n";
				outFile<<"ITEMS PURCHASED\n";
				outFile<<"========================================\n";
				for (ctr = 0; ctr<items2; ctr++)
				{
					if (BasicN_Pcode[ctr] == 11)
					{	
						//let product code come before product name
						cout<<BasicN_Pcode[ctr]<<" Bottled Water (500ml) "<<" x "<<BasicN_Qty[ctr]<<" = P"<<TotalAmt[ctr]<<endl;
						outFile<<BasicN_Pcode[ctr]<<" Bottled Water (500ml) "<<" x "<<BasicN_Qty[ctr]<<" = P"<<TotalAmt[ctr]<<endl;
					}
					else if (BasicN_Pcode[ctr] == 12)
					{
						cout<<BasicN_Pcode[ctr]<<" First Aid Kit "<<" x "<<BasicN_Qty[ctr]<<" = P"<<TotalAmt[ctr]<<endl;
						outFile<<BasicN_Pcode[ctr]<<" First Aid Kit "<<" x "<<BasicN_Qty[ctr]<<" = P"<<TotalAmt[ctr]<<endl;
					}
					else if (BasicN_Pcode[ctr] == 13)
					{	
						cout<<BasicN_Pcode[ctr]<<" Shampoo "<<" x "<<BasicN_Qty[ctr]<<" = P"<<TotalAmt[ctr]<<endl;
						outFile<<BasicN_Pcode[ctr]<<" Shampoo "<<" x "<<BasicN_Qty[ctr]<<" = P"<<TotalAmt[ctr]<<endl;
					}
					else if (BasicN_Pcode[ctr] == 14)
					{
						cout<<BasicN_Pcode[ctr]<<" Bedsheet "<<" x "<<BasicN_Qty[ctr]<<" = P"<<TotalAmt[ctr]<<endl;
						outFile<<BasicN_Pcode[ctr]<<" Bedsheet "<<" x "<<BasicN_Qty[ctr]<<" = P"<<TotalAmt[ctr]<<endl;
					}
					else if (BasicN_Pcode[ctr] == 15)
					{
						cout<<BasicN_Pcode[ctr]<<" Rice "<<" x "<<BasicN_Qty[ctr]<<" = P"<<TotalAmt[ctr]<<endl;
						outFile<<BasicN_Pcode[ctr]<<" Rice "<<" x "<<BasicN_Qty[ctr]<<" = P"<<TotalAmt[ctr]<<endl;
					}
				}
				cout<<endl;
				inFile.close();
				
				cout<<endl<<"Thank you for shopping at FRALASO Grocery Store! Until next time!"<<endl;
				break;
				inFile.close();
			}
			break;
		}
		
		cout<<"\n\nPress any key to continue shopping or [N/n] to proceed to checkout. ";
		cin>>shop;
		shop = tolower(shop);
		
		}while(inputerror||shop !='n');
		
		//start customer total tally here
		CustomerTotal = meatTotal + dairyTotal + basicNTotal;
		cout<<endl<<"Total Amount Payable: P"<<CustomerTotal<<endl;
		
		do{
		system("cls");
		cout<<"Enter payment: P";
		cin>>cash; //validation of payment
		
		inputerror = cin.fail();
		if (inputerror)
			cout<<"INVALID INPUT! Invalid input data type. Please try again.";
		cin.clear();
		cin.ignore(3, '\n');
		
		if (cash < CustomerTotal)
			cout<<endl<<"Invalid amount. Please enter a different amount.";
			
		}while (cash < CustomerTotal || inputerror);
		
		cout<<"======================\n";
		cout<<"Amount Paid: "<<cash<<endl;
		cout<<"Change: P"<<cash - CustomerTotal<<endl;
		
		outFile<<"========================================\n";
		outFile<<endl<<"Total Amount Payable: P"<<CustomerTotal<<"\n";
		outFile<<"Amount Paid: "<<cash<<"\n";
		outFile<<"Change: P"<<cash - CustomerTotal<<"\n";
		outFile<<"\nTHANKS FOR SHOPPING WITH US!\n";
		outFile.close();
		
		}//end of else
		
 		cout<<"THANKS FOR SHOPPING WITH US!"<<endl;
 		
 		inFile.close();
}



