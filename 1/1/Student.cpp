
#include "library.h"


class Student
{
private:
	std::string vardas, pavarde;
	vector<int>score_container;
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

	Student(string var, string pav, vector<int> sp, int egz) : vardas{ var }, pavarde{ pav }, score_container{ sp }, egz{ egz } {};




	void deleteStudentScores() {
		score_container.clear();
	}

	friend std::ostream& operator<<(std::ostream& output, const Student& S) {


		output << setw(15) << left << S.pavarde << setw(15) << S.vardas << setw(15) << fixed << setprecision(2) << S.count_average_formula * 1.0 << setw(15) << fixed << setprecision(2) << (double)S.score_container[(double)S.score_container.size() / 2.0] << endl;
		
		return output;
	}

	friend std::istream& operator>>(std::istream& input, Student& S) {
		int score = 0, score_option = 0;
		string end_adding_scores;
		cout << "1. Iveskite savo varda: ";
		input >> S.vardas;
		system("CLS");
		cout << "2. Iveskite savo pavarde: ";
		input >> S.pavarde;
		system("CLS");
		cout << "3. Iveskite savo egzamino rezultata: ";
	RepeatExamInput:
		input >> S.egz;
		system("CLS");
		if (S.egz <= 0 or S.egz > 10)
		{
			cout << "Klaida, iveskite skaiciu nuo 1 iki 10" << endl;
			goto RepeatExamInput;

		}


		cout << "4. Pasirinkite opcija pazymiu ivedimui:" << endl;
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
			cout << "***************************************************"<< endl;
			cout << "Iveskite pazymius:" << endl;

			while (score != 123) {
				cin >> score;
				if (score > 0 && score <= 10) S.score_container.push_back(score);

				else if (score == 123) { system("CLS"); }

				else {
					cout << "Klaida, iveskite skaiciu nuo 0 iki 10" << endl;
				}
			};




		}

		S.calculateAverage();
		S.calculateMedian();

		return input;
	}



};


