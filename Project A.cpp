

#include <iostream>
#include <fstream>	
//library for opening files and closing files
#include <string>
#include <algorithm>
//library containing the random_shuffle

using namespace std;

int main()
{
	// 1)Reading and Importing the csv files to the programme.
	//Importing the list from Group A csv file 
	ifstream File_A("inputICSA.csv");		
	if (!File_A.is_open())
	{
		cout << "This file has failed to open\n";
	}
	string lineA;
	string linesA[30];

	for (int i = 0; getline(File_A, lineA); i++)
	{
		linesA[i] = lineA;
	}

	cout << "\nGROUP A:\n";
	for (int i = 0; i < 30; i++)
	{
		cout << linesA[i] << "\n";
	}
	cout << "\n.........................................................\n\n";


	File_A.close();

	//Importing the list from Group B csv file 
	ifstream File_B("inputICSB.csv");				
	if (!File_B.is_open())
	{
		cout << "This file has failed to open\n";
	}
	string lineB;
	string linesB[28];

	for (int i = 0; getline(File_B, lineB); i++)
	{
		linesB[i] = lineB;
	}

	cout << "\nGROUP B:\n";
	for (int i = 0; i < 28; i++)
	{
		cout << linesB[i] << "\n";
	}
	cout << "\n.........................................................\n\n";


	File_B.close();

	//Importing the list from Group C csv file 
	ifstream File_C("inputICSC.csv");					
	if (!File_C.is_open())
	{
		cout << "This file has failed to open\n";
	}
	string lineC;
	string linesC[55];

	for (int i = 0; getline(File_C, lineC); i++)
	{
		linesC[i] = lineC;
	}

	cout << "\nGROUP C:\n";
	for (int i = 0; i < 55; i++)
	{
		cout << linesC[i] << "\n";
	}
	cout << "\n.........................................................\n\n";


	File_C.close();
	system("pause");
	system("cls");

	// 2)The perfect shuffle algorithm that gives output of the table
	//Merging the arrays into one begins here
	string linesALL[113];		

	//Group A
	for (int i = 0; i < 30; i++)
	{
		linesALL[i] = linesA[i];
	}
	//Group B
	for (int i = 0, j = 30; i < 28 && j<58; i++, j++)
	{
		linesALL[j] = linesB[i];
	}
	//Group C
	for (int i = 0, k = 58; i < 55 && k<113; i++, k++)
	{
		linesALL[k] = linesC[i];
	}

	//Shuffling of the list
	random_shuffle(&linesALL[0], &linesALL[113]);	

	//Getting seperate male & female list from shuffled list 
	string males[113], females[113];			


	for (int i = 0, j = 0; i < 113; i++)
	{
		if (linesALL[i].back() == 'M')
			males[j++] = linesALL[i];
		else
			continue;
	}


	for (int i = 0, j = 0; i < 113; i++)
	{
		if (linesALL[i].back() == 'F')
			females[j++] = linesALL[i];
		else
			continue;
	}


	// 3)Printing the new csv files(ICS A and B)
	//Generating new Group A
	string newA[57];		

	for (int i = 0; i < 36; i++)
	{
		newA[i] = males[i];
	}

	for (int i = 36, j = 0; i < 57; i++, j++)
	{
		newA[i] = females[j];
	}

	cout << "\nNew Group A:\n";

	random_shuffle(&newA[0], &newA[57]);

	for (int i = 0; i < 57; i++)
	{
		cout << newA[i] << "\n";
	}


	cout << "\n\n";

	//Generating new group B
	string newB[56];	

	for (int i = 36, j = 0; i < 71; i++, j++)
	{
		newB[j] = males[i];
	}

	for (int i = 35, j = 21; i < 56; i++, j++)
	{
		newB[i] = females[j];
	}

	cout << "\nNew Group B:\n";

	random_shuffle(&newB[0], &newB[56]);

	for (int i = 0; i < 56; i++)
	{
		cout << newB[i] << "\n";
	}

	cout << "\n\n";

	//creating new Group A CSV file
	ofstream newICSA;		
	newICSA.open("New ICS A.csv");

	for (int i = 0; i < 57; i++)
	{
		newICSA << newA[i] << "\n";
	}

	newICSA.close();

	//creating new Group B CSV file
	ofstream newICSB;		
	newICSB.open("New ICS B.csv");

	for (int i = 0; i < 56; i++)
	{
		newICSB << newB[i] << "\n";
	}

	newICSB.close();

	system("pause");
	return 0;
}

