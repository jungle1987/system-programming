

#include "library.h"
#include "Student.h"
#include "Student.cpp"



int main()
{

	vector<Student> list_Students;//vetorius talpins student objektus i sar
	vector<int>score_container;

	Student Temp_data("arg", "arg", score_container, 8);//perduodu i inputa
	// nuolat pildomas list_students objektas

	for (int i = 0; i < 2; i++) {
		cin >> Temp_data;
		list_Students.push_back(Temp_data);
		Temp_data.deleteStudentScores();


	};

	cout << setw(15) << left << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Galutinis(Vid.) / Galutinis (Med.)" << endl;
	cout << "--------------------------------------------------" << endl;

	for (int i = 0; i < 2; i++) {
		cout << list_Students[i] << endl;
	};




	return 0;

	// system("pause");


}


