#include <iostream>
#include <chrono>
#include <fstream>
#include "setSimple.h"
#define SIZE 30000
using namespace std;

int main() {
    SetSimple<int> set;
    set.insert(1);
    set.insert(1);
    set.insert(2);
    set.insert(5);
    set.insert(23);
    set.insert(20);
    set.insert(18);
    set.insert(17);
//    set.printSet();
//    set.size();
    cout <<"Does 1 exist in this set? : " <<  set.isExist(1) << endl;
    cout <<"Does 2 exist in this set? : " << set.isExist(2) << endl;
    cout << "-------------------------------------------------------" << endl;
    set.remove(2);
//    set.printSet();
//    set.size();
    cout <<"Does 1 exist in this set? : " <<  set.isExist(1) << endl;
    cout <<"Does 2 exist in this set? : " << set.isExist(2) << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "Set2: " << endl;
    SetSimple<int> set2;
    set2.insert(0);
    set2.insert(1);
    set2.insert(2);
    set2.insert(3);
    set2.insert(4);
    set2.insert(5);
    set2.insert(6);
    set2.insert(7);
    set2.insert(23);
    set.insert(29);
//    set2.printSet();
 //   set2.size();
    cout << "-------------------------------------------------------" << endl;
    cout<< "Sum of set and set2 : " << endl;
    SetSimple<int> setOFSumsTwoSets = SetSimple<int>::mergeTwoSets(set,set2);
 //   setOFSumsTwoSets.printSet();
//    setOFSumsTwoSets.size();
    cout << "Set1" << endl;
//    set.printSet();
    cout << "Set2" <<endl;
  //  set2.printSet();
    cout << "-------------------------------------------------------" << endl;
    cout << "Product of set1 and set2 looks like this: " << endl;
    SetSimple<int> setOfProductionTwoSets = SetSimple<int>::productOfSets(set,set2);
   // setOfProductionTwoSets.printSet();
  //  setOfProductionTwoSets.size();
    cout << "Set1" << endl;
   // set.printSet();
    cout << "Set2" <<endl;
  //  set2.printSet();
    cout << "-------------------------------------------------------" << endl;
    cout << "Difference between two sets: " << endl;
    SetSimple<int> setOfDifferenceTwoSets = SetSimple<int>::differenceOfTwoSets(set,set2);
  //  setOfDifferenceTwoSets.printSet();
  //  setOfDifferenceTwoSets.size();
    cout << "Set1" << endl;
  //  set.printSet();
    cout << "Set2" <<endl;
  //  set2.printSet();
    cout << "-------------------------------------------------------" << endl;
    cout << "The same sets?: " << endl;
   // cout << set.areSetsThesame(set,set2) << endl;
    cout << "Special comparing two the same sets: " << endl;
    SetSimple<int> setToCompare1;
    SetSimple<int> setToCompare2;
    setToCompare1.insert(1);
    setToCompare1.insert(4);
    setToCompare1.insert(7);
    setToCompare1.insert(20);
    setToCompare2.insert(1);
    setToCompare2.insert(4);
    setToCompare2.insert(7);
    setToCompare2.insert(20);
    cout << setToCompare1.areSetsThesame(setToCompare1,setToCompare2) << endl;
    SetSimple<int> setToCountTime;
    srand(time(NULL));

    int n=10000000;
    ofstream zapis;
    for (int j = 0; j < n; ++j) {
        setToCountTime.insert(j);
        // sumTime+=elapsed.count();
    }
  //  zapis.open("/home/sony/CLionProjects/AISD2/Zestaw1A/daneInsert.txt",ios::out | ios::app);
    zapis.open("/home/sony/CLionProjects/AISD2/Zestaw1A/daneDelete.txt",ios::out | ios::app);
  //  for (int i = 0; i < SIZE; i++) {
        double totalTime=0;
        if (zapis.good()) {
            auto start = chrono::high_resolution_clock::now();
            for (int j = 0; j < n; ++j) {
                setToCountTime.remove(j);
               // sumTime+=elapsed.count();
            }
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed = end - start;
            totalTime = elapsed.count();
            //zapis << i << " " << sumTime << endl;
            //setToCountTime.clearSet();
        }
      zapis << n  << " " << totalTime << endl;

    //}
    zapis << "e" << endl;
    zapis.flush();
    zapis.close();
    setToCountTime.printSet();
    setToCountTime.size();
    return 0;
}
