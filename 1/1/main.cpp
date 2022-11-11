#include "library.h"
#include "Student.h"



int main()
{
	
	list<Student> list_Students;//vektorius talpins student objektus i list_students
	vector<int>score_container;
	string eil;
	int generate_data_size = 0;
	Student Temp_data;//perduodu i inputa
	// nuolat pildomas list_students objektas


	cout << "-------------------------------SVARBU!--------------------------------------------" << endl;
	cout << "- Isskleiskite kursiokai1000000.zip faila kuris yra direktorijoje '../1/1/kursiokai1000000.zip'" << endl;
	cout << "- Programoje failas turi buti isskleistas tiesiai i direktorija kur yra programa" << endl;
	cout << "- t.y.po isskleidimo, failas turi atsirasti direktorijoje'../1/1/kursiokai1000000.txt' " << endl;
	cout << "----------------------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "Pasirinkite duomenu generavimo dydi: " << endl;
	cout  << "Opcija 1: Programa sugeneruos 1000 studentu sarasus su atstiktiniais skaiciais." << endl;
	cout  << "Opcija 2: Programa sugeneruos 10 000 studentu sarasus su atstiktiniais skaiciais." << endl;
	cout  << "Opcija 3: Programa sugeneruos 100 000 studentu sarasus su atstiktiniais skaiciais. "  << endl;
	cout  << "Opcija 4: Programa sugeneruos 1 000 000 studentu sarasus su atstiktiniais skaiciais. "  << endl;
	
	cout << endl;

	cout << "Opcija: ";
	cin >> generate_data_size;
	
	ifstream open_f("kursiokai1000000.txt");
	getline(open_f, eil);
	
	if (generate_data_size == 1) {
		auto start = std::chrono::high_resolution_clock::now(); auto st = start;//skaiciuoja laika atliekamos operacijos	
		for (int i = 0; i < 1000; i++) {
			open_f >> Temp_data;
			list_Students.push_back(Temp_data);
			
			Temp_data.deleteStudentScores();
		}
		open_f.close();
		std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
		cout << "Failo duomenu apdorojimas uztruko: " << diff.count() << " s\n";
	}
	


	if (generate_data_size == 2) {
		auto start = std::chrono::high_resolution_clock::now(); auto st = start;//skaiciuoja laika atliekamos operacijos
		for (int i = 0; i < 10000; i++) {
			open_f >> Temp_data;
			list_Students.push_back(Temp_data);

			Temp_data.deleteStudentScores();
		}
		open_f.close();
		std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
		cout << "Failo duomenu nukaitymas ir apdorojimas uztruko: " << diff.count() << " s\n";
	}

	else if (generate_data_size == 3) {
		auto start = std::chrono::high_resolution_clock::now(); auto st = start;//skaiciuoja laika atliekamos operacijos
		for (int i = 0; i < 100000; i++) {
			open_f >> Temp_data;
			list_Students.push_back(Temp_data);

			Temp_data.deleteStudentScores();
		}
		open_f.close();
		std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
		cout << "Failo duomenu nukaitymas ir apdorojimas uztruko: " << diff.count() << " s\n";
	}

	else if (generate_data_size == 4) {
		auto start = std::chrono::high_resolution_clock::now(); auto st = start;//skaiciuoja laika atliekamos operacijos
		for (int i = 0; i < 1000000; i++) {
			open_f >> Temp_data;
			list_Students.push_back(Temp_data);
			
			Temp_data.deleteStudentScores();
		}
		open_f.close();
		std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
		cout << "Failo duomenu nukaitymas ir apdorojimas uztruko: " << diff.count() << " s\n";
	}
		
		ofstream out_f("kursiokai_grades.txt");
		auto start = std::chrono::high_resolution_clock::now(); auto st = start;//skaiciuoja laika atliekamos operacijos
			for (int i = 0; i < list_Students.size(); i++) {
				out_f << list_Students.front();
				
			}
			std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
			out_f.close();

	
	cout << "Apdorotu duomenu irasymas i nauja faila uztruko: " << diff.count() << " s\n";
	cout << "Programa sugeneravo " << list_Students.size() << " eiluciu kieki " << endl;
	
	


	

	
	




	return 0;



}


