
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

		
		output << setw(15) << left << S.pavarde << setw(15) << S.vardas << setw(15) << setprecision(2) << S.count_average_formula << endl;
		
		return output;
	}

	friend std::istream& operator>>(std::istream& input, Student& S) {
		int score = 0;
		cout << "Iveskite savo varda: " ;
		input >> S.vardas;
		cout << "Iveskite savo pavarde: ";
		input >> S.pavarde;
		
		cout << "Iveskite savo egzamino rezultata: ";
	    RepeatExamInput:
		input >> S.egz;

			if (S.egz <= 0 or S.egz > 10)
			{
			cout << "Iveskite skaiciu nuo 1 iki 10" << endl;
			goto RepeatExamInput;

			}

			//cout << "Noredami sustabdyti pazymiu ivedima iveskite '123'" << endl;
			//cout << "Noredami sugeneruoti atsitiktinius skaicius iveskite '456'" << endl;
			cout << "Iveskite pazymius:" << endl;
			   //if (score == 456) {
					//for (int i = 0; i < 15; i++) {
						//int random = rand() % 10 + 1;
						//S.score_container.push_back(random);
					//}


				//}
				if (score > 0 || score <= 10 ) {
					for (int i = 0; i <= 9; i++) {
						cin >> score;
						S.score_container.push_back(score);
					};
				}
				
				else if (score <= 0 || score > 10) {
					cout << "Iveskite skaiciu nuo 0 iki 10" << endl;
					for (int i = 0; i <= 9; i++) {
						cin >> score;
						S.score_container.push_back(score);
					};
				}
			

			
			S.calculateAverage();
			S.calculateMedian();

			return input;
	}



	};


