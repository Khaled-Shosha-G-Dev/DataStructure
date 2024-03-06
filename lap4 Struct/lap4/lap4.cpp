#include <iostream>
using namespace std;

struct Student
{
	char Name[30];
	int rollNum;
	float Fees;
	char DOB[10];
};
void ReadInformation(Student &stud)
{
	cout << "Enter student name : ";
	cin >> stud.Name;
	cout << "Enter his roll number : ";
	cin >> stud.rollNum;
	cout << "How many fees ? \n-> ";
	cin >> stud.Fees;
	cout << "Enter his DOB : ";
	cin >> stud.DOB;
}

void DisplayInformation(Student stud)
{
	cout << "Name : "<<stud.Name<<endl;
	cout << "Roll numder : "<<stud.rollNum<<endl;
	cout << "The Fees : "<<stud.Fees<<endl;
	cout << "DOB : "<<stud.DOB<<endl;
}

int main()
{
	bool isDone=true;
	int studNum=0,i=0;
	cout << "Enter the name of student : ";
	cin >> studNum;
	Student* studArr = new Student[studNum];
	while(i<studNum || isDone)
	{
		int chooseNum;
		cout << "\n\n[1]Read\n[2]Display\n[3]Edit\n[4]Exit\n\n--> ";
		cin >> chooseNum;
		switch (chooseNum)
		{
		case 1:
		{
			if (i < studNum)
			{
				ReadInformation(studArr[i]);
				i++;
			}
			else
				cout << "\nThere is no space !!!";
			break;
		}
		case 2: 
		{
			for (int j=0; j < i; j++)
			{
				cout << "\n\t\tstudent ["<<j+1<<"]\n";
				DisplayInformation(studArr[j]);
				cout << endl;
			}
			break;
		}
		case 3:
		{
			int studEditing;
			cout << "Number you will edit it : ";
			cin >> studEditing;
			ReadInformation(studArr[studEditing-1]);
			break;
		}
		case 4:
		{
			isDone = false;
			break;
		}
		default:
		{
			cout << "wrong input !!!!! \nTry again .... \n\n";
			break;
		}
		}
	}
}
