
#include "library.h"
#include "functions.h"


class Student
{
private:
	string vardas, pavarde, eil;
	vector<int>score_container;
	vector<Student> duom;
	
	
	int egz = 0;

	double average_scores_formula = 0.;
	double count_average_formula = 0.;


	void calculateAverage() {
		average_scores_formula = std::accumulate(score_container.begin(), score_container.end(), 0.0) / score_container.size();
		count_average_formula = (0.4 * average_scores_formula) + (0.6 * (double)egz);

	}

	void calculateMedian() {
		std::nth_element(score_container.begin(), score_container.begin() + score_container.size() / 2, score_container.end());

	}

public:
	Student() {};

	Student(const Student& A) {

		this->vardas = A.vardas; 
		this->pavarde = A.pavarde;
		this->eil = A.eil;	
		this->score_container = A.score_container;
		this->duom = A.duom;
		this-> egz = A.egz;
		this-> average_scores_formula = A.average_scores_formula;
		this-> count_average_formula = A.count_average_formula;
	}

	Student(string var, string pav, vector<int> sp, int egz) : vardas{ var }, pavarde{ pav }, score_container{ sp }, egz{ egz } {};

	void bufer_nusk(string read_vardas) {
		stringstream my_buffer;
		Student Laik;
		ifstream open_f(read_vardas);
		my_buffer << open_f.rdbuf();
		open_f.close();


		getline(my_buffer, eil);

		while (my_buffer) {
			if (!my_buffer.eof()) {
				getline(my_buffer, eil);
				stringstream temp_buffer(eil); //sukuria objekta
				istream_iterator<string> begin(temp_buffer);
				istream_iterator<std::string> end;
				vector<std::string> temp_vector(begin, end);// atskirsiu elementus
				temp_vector.begin();
				cout << std::endl;
				temp_vector.end();
				Laik.vardas = temp_vector[0];// vardo indexas 
				Laik.pavarde = temp_vector[1];//pavardes indexas
				for (int i = 2; i <= temp_vector.size() - 2; i++) //nuo antro indexo prasideda pazymiai ir prasuku 7-2 karto.
				{

					Laik.score_container.push_back(atoi(temp_vector[i].c_str()));//konvertuoju inta i stringa

				}

				Laik.egz = atoi(temp_vector[temp_vector.size() - 1].c_str());
				duom.push_back(Laik);
				std::cout << Laik.vardas << "      " << Laik.pavarde << "      ";
				for (int i = 0; i < Laik.score_container.size(); i++) std::cout << Laik.score_container[i] << "         ";
				std::cout << Laik.egz << "      ";
				Laik.score_container.clear();
				//for (auto a : temp_vector) std::cout << a << std::endl;
				// splited.push_back(eil);

			}
			else break;
		}
	}

	void deleteStudentScores() {
		score_container.clear();
	}

	string getVardas() {
		return vardas;
	}


	friend std::ostream& operator<<(std::ostream& output, const Student& S) {

		//cout << setw(15) << left << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Galutinis(Vid.) / Galutinis (Med.)" << endl;
		//cout << "--------------------------------------------------" << endl;
		output << setw(15) << left << S.pavarde << setw(15) << S.vardas << setw(15) << fixed << setprecision(2) << S.count_average_formula * 1.0 << setw(15) << fixed << setprecision(2) << S.score_container[S.score_container.size() / 2] << endl;
		
		return output;
	}

	friend std::istream& operator>>(std::istream& input, Student& S) {
		int score = 0;


		//string eil;
		//getline(input, eil);
		//stringstream my_buffer(eil);
		
		input >> S.vardas >> S.pavarde;
		//cout << S.vardas << S.pavarde << endl;
		
		
		for (int i = 0; i < 7; i++) {
				
			input >> score;
			S.score_container.push_back(score);
			

			/*my_buffer >> score;
				cout << score << endl;
				S.score_container.push_back(score);
				if (score > 0 && score <= 10) 

				else if (score == 123) { system("CLS"); }

				else {
					cout << "Klaidingas pazymiu, iveskite skaiciu nuo 0 iki 10 " << endl;
				} */
			}

			S.egz = S.score_container.at(S.score_container.size()-1);//paskutini elementa
			//cout << "test: " << S.score_container.size() << endl;
			S.score_container.pop_back();//isima paskutini elementa
			
			input >> S.egz;
			S.calculateAverage();
			S.calculateMedian();
			//cout << S;
			//my_buffer.clear();
			
			
		return input;
	}

		

	/*friend std::istream& operator>>(std::istream& input, Student& S) {
		int score = 0, score_option = 0;

		cout << "1. Iveskite savo varda: ";
		input >> S.vardas;
		system("CLS");
		cout << "2. Iveskite savo pavarde: ";
		input >> S.pavarde;
		system("CLS");
		
		cout << "3. Pasirinkite opcija pazymiu ivedimui:" << endl;
		cout << "1 Opcija: Skaiciu suvedimas, kai yra zinomi pazymiai. Vartotojas pats suveda pazymius. " << endl;
		cout << "2 Opcija: Skaiciu suvedimas, kai pazymiai nera zinomi. Programa automatiskai sugeneruos 10 skaiciu. " << endl;
		cout << "**************************************************************************************************" << endl;
		cout << "Opcija: ";

		cin >> score_option;
		system("CLS");

		if (score_option == 2) {
			for (int i = 0; i < 9; i++) {
				int random = rand() % 10 + 1;
				S.score_container.push_back(random);
			}
		}


		else if (score_option == 1) {

			cout << "Noredami sustabdyti pazymiu ivedima, iveskite '123'" << endl;
			cout << "***************************************************" << endl;
			cout << "Iveskite pazymius:" << endl;

			while (score != 123) {
				cin >> score;
				if (score > 0 && score <= 10) S.score_container.push_back(score);

				else if (score == 123) { system("CLS"); }

				else {
					cout << "Klaidingas pazymiu, iveskite skaiciu nuo 0 iki 10 " << endl;
				}
			};


		}

		cout << "4. Iveskite savo egzamino rezultata: ";
	RepeatExamInput:
		input >> S.egz;
		system("CLS");
		if (S.egz <= 0 or S.egz > 10)
		{
			cout << "Klaidingas egzamino rezultatas, iveskite skaiciu nuo 1 iki 10" << endl;
			goto RepeatExamInput;

		}

		S.calculateAverage();
		S.calculateMedian();

		return input;
	}

	*/

};


