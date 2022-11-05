#include "library.h"
#include "Student.h"



int main()
{
	int data_input_option;
	vector<Student> list_Students;//vetorius talpins student objektus i sar
	vector<int>score_container;
	string eil;

	Student Temp_data;//perduodu i inputa
	// nuolat pildomas list_students objektas
	


	
	cout << "Pasirinkite duomenu ivedimo buda" << endl;
	cout << "1 Opcija: Duomenu suvedimas rankiniu budu. Vartotojas suveda duomenis rankiniu budu. " << endl;
	cout << "2 Opcija: Duomenu suvedimas is failo. Vartotojas ikelia faila " << endl;
	cout << "Opcija: ";
	cin >> data_input_option;
	cout << endl;
	if (data_input_option == 1) {
		for (int i = 0; i < 2; i++) {
			cout << endl;
			cout << "**************************************************************************************************" << endl;
			cout << "** 1. Iveskite savo varda. " << endl;
			cout << "** 2. Iveskite savo pavarde. " << endl;
			cout << "** 3. Iveskite pazymius. " << endl;
			cout << "** 4. Iveskite savo egzamino rezultata. " << endl;
			cout << "**************************************************************************************************" << endl;
			cout << endl;
			cin >> Temp_data;
			list_Students.push_back(Temp_data);
			Temp_data.deleteStudentScores();

		};
	}

	
	
	else if (data_input_option == 2) {
		std::ifstream open_f("kursiokai.txt");
		getline(open_f, eil);
		while (!open_f.eof()) {
			open_f >> Temp_data;

			list_Students.push_back(Temp_data);
			list_Students.begin()->getVardas();
			Temp_data.deleteStudentScores();
		}
	}

	

		cout  << setw(15) << left << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Galutinis(Vid.) / Galutinis (Med.)" << endl;
		cout << "--------------------------------------------------" << endl;
		//cout << list_Students.size() << endl;
		
		for (auto &a : list_Students) {
			cout << a;
		};

	

	

	return 0;

	// system("pause");


}


