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


int main()
{
	
}