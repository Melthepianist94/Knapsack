#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

struct Items {
int values;
int weights;
};

//Function to recursively find optimal solution
void Dynamic(vector<Items>& List, vector<int>& SolutionList, int ObjectNo, int Capacity) {
  if(List[ObjectNo].weights>Capacity) {
    SolutionList.push_back(SolutionList[30*(ObjectNo-1)+Capacity-1]);
    Dynamic(List, SolutionList, ObjectNo-1, Capacity);
  }
  else {
    //Need to find maximum of value in SolutionList diagonally across plus item value and value adjacent to it
    Dynamic(List, SolutionList, ObjectNo-1, Capacity);
    int n=Capacity-List[ObjectNo].weights;
    Dynamic(List, SolutionList, ObjectNo-1, n);
    signed int Value=SolutionList[10*(ObjectNo-1)+Capacity-1]-SolutionList[10*(ObjectNo-1)+n-1]-List[ObjectNo].weights;
    if(Value>=0) {
      SolutionList.push_back(SolutionList[10*(ObjectNo-1)+Capacity-1]);
    }
    else {
      SolutionList.push_back(SolutionList[10*(ObjectNo-1)+n-1]+List[ObjectNo].values);
    }
  }
}

int main() {
  //Initialise array of object values and weights.
  vector<Items> ItemList;
  int i=0;
  int Capacity=10;
  string mystr;
  while(i<5) {
    Items temp;
    cout << "Enter object "<< i <<"'s value:";
    cin >> mystr;
    stringstream(mystr) >> temp.values;
    cout << "Enter object "<< i <<"'s weight:";
    cin >> mystr;
    stringstream(mystr) >> temp.weights;
    ItemList.push_back(temp);
    i++;
  }
  //Initialise first object Solution0.
  vector<int> SolutionList;
  SolutionList.push_back(0);
  Dynamic(ItemList, SolutionList, i, Capacity);
  cout << "The optimal solution for the value of these objects constrained by capacity 30 is " << SolutionList[10*5-1] << ".\n";
  return 0;   
}
