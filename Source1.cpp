#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


enum ROLE
{
	noRoleYet,
	scrumTrainer,
	qualityEngineer,
	backEndDev,
	frontEndDev
};
enum TEAM_STATUS
{
	inUse,
	notActive,
	notArchived,
};
struct STUDENT
{
	int klass;

	string name;
	string surname;
	string email;

	ROLE role;
};
struct TEACHER
{
	string name;
	string surname;
	string email;

	vector <string> teams;
};
struct TEAM
{
	string name;
	string description;
	string setupdate;

	vector <STUDENT> student;
	TEAM_STATUS status;
	TEACHER teacher;
};
struct SCHOOL
{
	string name;
	string city;
	string address;

	vector <TEAM> team;
	vector <TEACHER> teacher;
	vector <STUDENT> student;
};

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


enum ROLE
{
	noRoleYet,
	scrumTrainer,
	qualityEngineer,
	backEndDev,
	frontEndDev
};
enum TEAM_STATUS
{
	inUse,
	notActive,
	notArchived,
};
struct STUDENT
{
	int klass;

	string name;
	string surname;
	string email;

	ROLE role;
};
struct TEACHER
{
	string name;
	string surname;
	string email;

	vector <string> teams;
};
struct TEAM
{
	string name;
	string description;
	string setupdate;

	vector <STUDENT> student;
	TEAM_STATUS status;
	TEACHER teacher;
};
struct SCHOOL
{
	string name;
	string city;
	string address;

	vector <TEAM> team;
	vector <TEACHER> teacher;
	vector <STUDENT> student;
};


TEAM defaultTeam{
	 " ", " ", " ", {} , TEAM_STATUS::inUse, "no teacher"
}; //When a new team gets added, these are used for their default values
TEACHER defaultTeacher{
	" ", " ", " ", {}
}; //same as the one above
STUDENT defaultStudent{
	0, " ", " ", " ", ROLE::noRoleYet
}; //same as the one above


SCHOOL add(SCHOOL school)
{
	int choice = -1;
	cout << "1. Add a team" << endl;
	cout << "2. Add a teacher" << endl;
	cout << "3. Add a student" << endl;
	cout << "9. Go back" << endl;
	try
	{
		cin >> choice;
		switch (choice)
		{
		case 1: {
			school.team.push_back(defaultTeam);
			cout << "Team added" << endl;
			break;
		}//adds a team

		case 2: {
			school.teacher.push_back(defaultTeacher);
			cout << "Teacher added" << endl;
			break;
		}//adds a teacher

		case 3: {
			school.student.push_back(defaultStudent);
			cout << "Student added" << endl;
			break;
		} //adds a student

		default: cout << "Invalid option" << endl; break; //none of the above
		}
	}
	catch (...)
	{
		cout << "Bad input" << endl; //input wasn't an int
		choice = -1;
	}
	return school;
}//allocates memory for a new element
SCHOOL teamEdit(SCHOOL school)
{
	unsigned choice1;
	unsigned choice2;
	cout << "Choose a team to edit" << endl;
	try
	{
		cin >> choice1;
		if (choice1 > school.team.size()) {
			cout << "There's no team on that index" << endl;
		}
		else {
			cout << "1. Edit name" << endl;
			cout << "2. Edit description" << endl;
			cout << "1. Edit set up date" << endl;
			cout << "1. Edit teacher" << endl;
			cout << "9. Go back" << endl;
			cin >> choice2;
			switch (choice2)
			{

			case 1: {
				cin >> school.team[choice1].name;
				break;
			}
			case 2: {
				cin >> school.team[choice1].description;
				break;
			}

			case 3: {
				cin >> school.team[choice1].setupdate;
				break;
			}

			case 4: {
				cin >> school.team[choice1].teacher.name;
				break;
			}

			case 9: {
				break;
			}

			default: cout << "invalid option" << endl;

			}
			cout << "succesfully changed" << endl;
		}
	}
	catch (...)
	{
		cout << "bad input" << endl;
	}
	return school;
}//edits teams
SCHOOL teacherEdit(SCHOOL school)
{
	unsigned choice1;
	int choice2;
	cout << "Choose a teacher to edit" << endl;
	try
	{
		cin >> choice1;
		if (choice1 > school.teacher.size()) {
			cout << "There's no teacher on that index" << endl;
		}
		else {
			cout << "1. Edit name" << endl;
			cout << "2. Edit surname" << endl;
			cout << "3. Edit email" << endl;
			cout << "9. Go back" << endl;
			cin >> choice2;
			switch (choice2)
			{

			case 1: {
				cin >> school.teacher[choice1].name;
				break;
			}
			case 2: {
				cin >> school.teacher[choice1].surname;
				break;
			}

			case 3: {
				cin >> school.teacher[choice1].email;
				break;
			}

			case 9: {
				break;
			}

			default: cout << "invalid option" << endl;

			}
			cout << "succesfully changed" << endl;
		}
	}
	catch (...)
	{
		cout << "bad input" << endl;
	}
	return school;
	return school;
}//edits teachers
SCHOOL studentEdit(SCHOOL school)
{
	unsigned choice1;
	int choice2;
	int role;
	cout << "Choose a student to edit" << endl;
	try
	{
		cin >> choice1;
		if (choice1 > school.student.size()) {
			cout << "There's no student on that index" << endl;
		}
		else {
			cout << "1. Edit name" << endl;
			cout << "2. Edit surname" << endl;
			cout << "3. Edit email" << endl;
			cout << "4. Edit class" << endl;
			cout << "5. Edit role" << endl;
			cout << "9. Go back" << endl;
			cin >> choice2;
			switch (choice2)
			{

			case 1: {
				cin >> school.student[choice1].name;
				break;
			}
			case 2: {
				cin >> school.student[choice1].surname;
				break;
			}

			case 3: {
				cin >> school.student[choice1].email;
				break;
			}

			case 4: {
				cin >> school.student[choice1].klass;
				break;
			}

			case 5: {
				cout << "Choose a new role" << endl;
				cin >> role;
				school.student[choice1].role = ROLE(role);
			}

			case 9: {
				break;
			}

			default: cout << "invalid option" << endl;

			}
			cout << "Succesfully changed" << endl;
		}
	}
	catch (...)
	{
		cout << "bad input" << endl;
	}
	return school;
	return school;
}//student edit
SCHOOL del(SCHOOL school)
{
	int choice1;
	int choice2;
	try
	{
		cout << "1. Delete a team" << endl;
		cout << "2. Delete a teacher" << endl;
		cout << "3. Delete a student" << endl;
		cout << "9. Go back" << endl;
		cin >> choice1;
		cin >> choice2;
		switch (choice1)
		{

		case 1: {
			vector<TEAM>::iterator x = school.team.begin() + choice2;
			school.team.erase(x);
			break;
		} //index starts from 0 for all of the cases

		case 2: {
			vector<TEACHER>::iterator x = school.teacher.begin() + choice2;
			school.teacher.erase(x);
			break;
		}

		case 3: {
			vector<STUDENT>::iterator x = school.student.begin() + choice2;
			school.student.erase(x);
			break;
		}

		case 0: {
			break;
		}

		default: cout << "Invalid choice" << endl;

		}
	}
	catch (...)
	{
		cout << "bad input" << endl;
	}

	return school;
}//deletes elements and frees up memory (doesn't work for some reason)
void credits()
{
	cout << "Our team: "<<endl;
	cout << "Nevena Pavlova and Zhenya Yordanova"<<endl;
}//outputs the team
SCHOOL edit(SCHOOL school)
{
	int choice = -1;
	cout << "1. Edit a team" << endl;
	cout << "2. Edit a teacher" << endl;
	cout << "3. Edit a student" << endl;
	cout << "9. Go back" << endl;
	try
	{
		cin >> choice;
		switch (choice)
		{

		case 1: teamEdit(school); break;

		case 2: teacherEdit(school); break;

		case 3: studentEdit(school); break;

		default: cout << "Invalid option" << endl; break; //none of the above

		}
	}
	catch (...)
	{
		cout << "Bad input" << endl; //input wasn't an int
	}
	return school;
}//parent function for all other edit functions
int main()
{
	SCHOOL school;
	int choice = -1;
	while (choice != 9) {
		cout << "1. Add content" << endl;
		cout << "2. Edit content" << endl;
		cout << "3. Delete content" << endl;
		cout << "4. Our team" << endl;
		cout << "9. Exit" << endl;
		try {
			cin >> choice;
			switch (choice)
			{

			case 1: add(school); break; //adds content

			case 2: edit(school); break; //edits content

			case 3: del(school); break; //deletes content

			case 4: credits(); break; //outputs the team

			case 9: break; //goes out of the program

			default: cout << "Invalid option!" << endl; break; //none of the above

			}
		}
		catch (...) {
			cout << "Bad input" << endl;
			choice = -1;
		}
	}
}
int main()
{
	
}