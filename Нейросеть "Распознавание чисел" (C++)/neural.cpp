#include <iostream>
#include <cstdlib>

using namespace std;

int numbers[11][15] = { { 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1 },
    { 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1 },
    { 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
    { 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1 },
    { 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1 },
    { 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
    { 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1 },
    { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

int weights[10][15];

int porog = 20;

bool CountSum(int index, int whatis)
{
    int net = 0;
    for (int i = 0; i < 15; i++) {
        net += numbers[whatis][i] * weights[index][i];
    }
    return net >= porog;
}

void Rugaem(int index, int whatis)
{
    for (int i = 0; i < 15; i++) {
        if (numbers[whatis][i] == 1)
            weights[index][i]--;
    }
}

void Hvalim(int index, int whatis)
{
    for (int i = 0; i < 15; i++) {
        if (numbers[whatis][i] == 1)
            weights[index][i]++;
    }
}

int main()
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 15; j++) {
            weights[i][j] = 0;
        }
    }
    int option;
   for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 40000; j++) {
            option = rand() % 10;
            if (option != i){
            	if (CountSum(i, option)) 
                    Rugaem(i, option);
            }
                if (option == i) {
                    if (!CountSum(i, option))
                        Hvalim(i, option);
                }
        }
    }
  cout << "Enter " << endl;
  for (int j = 0; j < 15; j++) {
        cin >> numbers[10][j];
  }
  cout << endl << "is 0? " << CountSum(0, 10) << endl;
  cout << "is 1? " << CountSum(1, 10) << endl;
  cout << "is 2? " << CountSum(2, 10) << endl;
  cout << "is 3? " << CountSum(3, 10) << endl;
  cout << "is 4? " << CountSum(4, 10) << endl;
  cout << "is 5? " << CountSum(5, 10) << endl;
  cout << "is 6? " << CountSum(6, 10) << endl;
  cout << "is 7? " << CountSum(7, 10) << endl;
  cout << "is 8? " << CountSum(8, 10) << endl;
  cout << "is 9? " << CountSum(9, 10) << endl;
}
