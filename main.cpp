//
// Created by brado on 2/24/2023.
//

#include "Random.h"

using namespace std;

int main(){
    vector<int> randVec = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    Random<int> random(randVec);

    cout << "Bradon Soucy's, Randomize Vector Function: " << endl;
    for (int i=0; i<10; i++) {
        //Run random algorithm 10 times
        random.bksoucyRand();
        cout << "Shuffle #"<< i+1<<": " << random;
    }

    random.selectionSort();
    cout << "Sorted:\n" << random << endl;

    cout << "Randomize Test: Good Algorithm should produce around 1/20 or 0.05" << endl;
    cout << "Test Result of bksoucy: " << random.testRand("bksoucy", 1, 4) << endl;

    cout << "\n-----------------------------------------------------------------------------------\n" << endl;

    Random<int> random2(randVec);
    //Shuffle 10 times
    cout<< "David's Shuffle Algorithm:"<<endl;
    for (int i=0;i<10;i++) {
        random2.dfourniRand();
        cout << "Shuffle #"<< i+1<<": " << random2;
    }

    random2.selectionSort();
    cout<<"Sorting Vector..."<<endl;
    cout<<random2<<endl;

    cout << "Randomize Test: Good Algorithm should produce around 1/20 or 0.05" << endl;
    cout << "Test Result of dfourni: " << random2.testRand("dfourni", 1,4) << endl;


    cout << "\n-----------------------------------------------------------------------------------\n" << endl;

//    Random<int> random3(randVec);
//    //Shuffle 10 times
//    cout<< "Abbey's Shuffle Algorithm:"<<endl;
//    Random<int> random4 = random3.amknobelRand();
//    cout << "Shuffle #" << random4;
//

    cout << "\n-----------------------------------------------------------------------------------\n" << endl;

    Random<int> random5(randVec);

    cout << "Kamila's Randomize Vector Function: " << endl;
    for (int i=0; i<10; i++) {
        random5.kjablon4Rand();
        cout << "Shuffle #" << i << random5;
    }
    random5.selectionSort();

    cout << "Randomize Test: Good Algorithm should produce around 1/20 or 0.05" << endl;
    cout << "Test Result of kjablon: " << random5.testRand("kjablon", 1,4) << endl;

    int num =0;
    int findIt = 5;
    random5.find(findIt, num);
}