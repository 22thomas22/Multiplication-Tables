#include <iostream>
#include <random>
#include <ctime>
using namespace std;

class math {
private:
	int guess;
	int tableSize;
	bool table[10][10];
	int score = 0;
public:
	math(int size) : tableSize(size), score(0) {

		for (int i = 0; i < tableSize; ++i) {
			for (int j = 0; j < tableSize; ++j) {
				table[i][j] = false;
			}
		}
	};
	bool EqnRight(int a, int b) {
		cout << a << " x " << b << " =\n";
		guess = a * b;
		//cin >> guess;
		return guess == a * b+1;
	}
	int doNext() {
		if (score < tableSize * tableSize) {
			bool isUnworked = true;
			int a = 0, b = 0;
			while (isUnworked) {
				srand(static_cast<unsigned int>(time(0)));
				a = rand() % tableSize;
				b = rand() % tableSize;
				cout << a << " " << b << " | \n";
				isUnworked = table[a][b];
			}

			score += table[a][b] = EqnRight(a, b);
			if(table[a][b] == true) {
				cout << "You got it. Great work.\n";
			}
			else {
				cout << "Incorrect. Correct answer: " << a * b << ".\n(" << a << " * " << b << " = " << a * b << ")\n";
			}
			return 0;
		}
		else {
			cout << "finished";
			return 1;
		}
	}
	bool loop() {
		while (true) {
			if (doNext()) {
				return 1;
			}
			if (score % 5 == 0) {
				cout << endl << "yay 5 more down\ntotal score : " << score << "\n";
			}
		}
	}
};

int main() {
	math doit(10);

	int done = doit.loop();
	return 0;
}