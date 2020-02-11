#include <iostream> 
#include <vector> 

std::vector<int> FakeResult;

void toVector(int n, std::vector<int> &result) 
{ 
  result.clear();
  while (n != 0) 
  { 
    result.push_back(n % 10); 
    n = n/10; 
  } 
} 

void recount () {
  std::vector<int> tmpResult;
	  
  for (int i = 0; i < FakeResult.size(); i++){
    if (FakeResult[i] > 9) { 
      toVector(FakeResult[i], tmpResult);
      FakeResult[i]=tmpResult[0];
      for (int k = 1; k < tmpResult.size(); k++) {
      	if (i+k > FakeResult.size() - 1) FakeResult.push_back(0);
      	FakeResult[i+k]=FakeResult[i+k]+tmpResult[k];
      }
    }
  }
}

int main() { 
int n; 
std::cin >> n; 
std::vector<int> result;
FakeResult.push_back(1);

for (int j=1; j <= n; j++) {
  for (int i=0; i < FakeResult.size(); i++) {
    FakeResult[i] = FakeResult[i] * j; 
  }
  recount(); 
}
  for (int i = FakeResult.size()-1; i >= 0; i--) 
    std::cout << FakeResult[i];
return 0; 
}
