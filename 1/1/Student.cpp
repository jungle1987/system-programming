
#include "library.h"



class Student
{
private:
	string vardas, pavarde, eil;
	vector<int>score_container;
	vector<Student> duom;


	int egz = 0;
	double x = 0;
	double average_scores_formula = 0.;
	double count_average_formula = 0.;
	double median = 0;
	double median_student = 0;


	void calculateAverage() {
		average_scores_formula = std::accumulate(score_container.begin(), score_container.end(), 0.0) / score_container.size();
		count_average_formula = (0.4 * average_scores_formula) + (0.6 * (double)egz);

	}

	

	void calculateMedian() {

		std::nth_element(score_container.begin(), score_container.begin() + score_container.size() / 2, score_container.end());
		median = score_container[score_container.size() / 2];
		median_student = 0.4 * median + 0.6 * (double)egz;
	}

public:
	Student() {};

	Student(const Student& A) {

		this->vardas = A.vardas;
		this->pavarde = A.pavarde;
		this->eil = A.eil;
		this->score_container = A.score_container;
		
		this->egz = A.egz;
		this->average_scores_formula = A.average_scores_formula;
		this->count_average_formula = A.count_average_formula;
		this->median = A.median;
		this->median_student = A.median_student;
		
	}

	

	Student(string var, string pav, vector<int> sp, int egz) : vardas{ var }, pavarde{ pav }, score_container{ sp }, egz{ egz } {};

	~Student() {

		
	}

	void deleteStudentScores() {
			score_container.clear();
		}



	friend std::ostream& operator<<(std::ostream& output, const Student& S) {


		output << setw(15) << left << S.pavarde << setw(15) << S.vardas << setw(15) << fixed << setprecision(2) << (double)S.count_average_formula << setw(15) << fixed << setprecision(2) << (double)S.median_student << endl;

		return output;
	}

	friend std::istream& operator>>(std::istream& input, Student& S) {
		int score = 0;

		input >> S.vardas >> S.pavarde;
		
		srand((unsigned)time(NULL));

		for (int i = 0; i < 7; i++) {
			
				int random = 1 + (rand() % 9);
				input >> score;
				score = random;
				S.score_container.push_back(score);
			
		}

		S.egz = S.score_container.at(S.score_container.size() - 1);//priskiria paskutini elementa

		S.score_container.pop_back();//isima paskutini elementa

		input >> S.egz;
		S.calculateAverage();
		S.calculateMedian();



		return input;
	}



};


