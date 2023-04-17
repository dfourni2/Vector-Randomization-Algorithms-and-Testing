// CS 120 M2AP
// Random.h : Randomizes Vectors as much as you heart can desire
// Created by Bradon Soucy
// Contains Various Randomize methods, and a sort / find / test method




#ifndef M2AP_BKSOUCY_KJABLON4_AMKNOBEL_DFOURNI2_BKSOUCYRANDOM_H
#define M2AP_BKSOUCY_KJABLON4_AMKNOBEL_DFOURNI2_BKSOUCYRANDOM_H

#include <vector>
#include <chrono>
#include <cmath>
#include <iostream>
#include <algorithm>


using namespace std;

template<typename T>
class Random {
private:
    vector<T> randVec;
    time_t timer;

    struct RandomNode {
        RandomNode* leftChild;
        RandomNode* rightChild;
        T value;

        // Constructors
        RandomNode() : value(T()), leftChild(nullptr), rightChild(nullptr) {}
        explicit RandomNode(T c) : value(c), leftChild(nullptr), rightChild(nullptr) {}
        RandomNode(T c, RandomNode* l, RandomNode* r) : value(c), leftChild(l), rightChild(r) {}
    };
    RandomNode* root;
public:
    Random(vector<T> randVec){
        this->randVec = randVec;
        srand(time(NULL));
    }

    void  bksoucyRand(){
        //Uses the Linear Congruental Generator to Produce PsuedoRandom output

        //stuff to read in the time (thanks to stack overflow! : https://stackoverflow.com/questions/2831841/how-to-get-the-time-in-milliseconds-in-c)
        int randOut;
        auto time = chrono::system_clock::now();
        auto since_epoch = time.time_since_epoch(); // get the duration since epoch

        auto millis = chrono::duration_cast<chrono::milliseconds>(since_epoch);

        long now = millis.count();


        //set the start seed based off the current time at run
        randOut = now;
        int amount = randVec.size();

        //other LCG params based off Borland's C/C++ inputs
        int mod = (int)pow(2,64);
        int a = 22695477;
        int c = 1;

        //Loop to randomize randVec using my algorithm.
        int i;
        vector<T> newVec;
        for(i = 0; i < randVec.size(); ++i){
            randOut = (a * randOut + c) % mod;
            int index = abs(randOut % amount);

            while(randVec[index] == NULL){
                randOut = (a * randOut + c) % mod;
                index = abs(randOut % amount);
            }

            newVec.push_back(randVec[index]);
            randVec[index] = NULL;
        }
        randVec = newVec;
    }

    void dfourniRand(){
        //Based on the Fisher-Yates Shuffle algorithm

        int vecSize = randVec.size();
        //iterate through the vector
        for (int index=0;index <vecSize-2;index++){
            //choose a random element to swap with this element being iterated
            int swapIndex = index + rand() % (vecSize - index + 1);
            //swap the elements
            swap(randVec[index],randVec[swapIndex]);
        }

    }

    vector<T> amknobelRand(){
        //make another array that will be returned
       vector<T>  returnVec;
       //while the vector that is passed in to be randomized is larger than the returnVec
       while(randVec > returnVec){
           //randomly select an element in randVec
           //pushback the element onto the return vector
           returnVec.push_back(randVec[rand() % randVec.size()]);
       }
       //once all the values in the random vector have been added to the return vec return the return vec
       return returnVec;
    }

    void kjablon4Rand() {
        int random = rand();
        //set to 20 because vector is 20
        int MAXRandom = 20;
        int newNum;

        for (int i = 0; i < randVec.size(); ++i) {
            newNum = random % MAXRandom;
            randVec.push_back(newNum);
            if (newNum%2 != 0){
                swap(randVec.at(i+1), randVec.at(i));
            }
        }
    }


    //Written using what I remember of 124, (smallest first)
    void selectionSort(){
        int low;
        T temp;

        int i,j;
        for(i = 0; i < randVec.size()-1; ++i){
            low = i;
            for(j = i; j < randVec.size(); ++j){
                if(randVec[j] < randVec[low]){
                    low = j;
                }
            }
            temp = randVec[i];
            randVec[i] = randVec[low];
            randVec[low] = temp;
        }
    }

    bool find(T &c, RandomNode *n, int &count ) const {

        if (n == nullptr) {
            // Reached a dead end.
            cout << "Not found" << endl;
            return false;
        }
        if (c < n->value) {
            count++;
            // Value is less than current node. Go to node's left child.
            return find(c, n->leftChild, count);
        }
        if (n->value < c) {
            count++;
            // Value is greater than current node. Go to node's right child.
            return find(c, n->rightChild, count);
        }
        // If code reaches here, Node found!
        cout << count << endl;
        return true;
    }
    bool find(T &c, int &count) const {
        // calls private helper function
        count = 0;
        return find(c, root, count);
    }

    double testRand(string randToTest, int index, T val){
        int testAmount = 5000;
        int indexAmount = 0;

        //Loops through the entered randomize function testAmount times, and if the given index is a certain value
        //Then it adds 1 to index amount. Then it returns indexAmount / testAmount.
        // So a true random method technically should return a value of 1 / randVec.size()
        int i;
        if(randToTest == "bksoucy"){
            for(i = 0; i < testAmount; ++i){
                bksoucyRand();
                if(randVec[index] == val){
                    indexAmount++;
                }
            }
        }else if(randToTest == "dfourni"){
            for(i = 0; i < testAmount; ++i){
                dfourniRand();
                if(randVec[index] == val){
                    indexAmount++;
                }
            }
        }else if(randToTest == "amknobel"){
            for(i = 0; i < testAmount; ++i){
                amknobelRand();
                if(randVec[index] == val){
                    indexAmount++;
                }
            }
        }else if(randToTest == "kjablon"){
            for(i = 0; i < testAmount; ++i){
                kjablon4Rand();
                if(randVec[index] == val){
                    indexAmount++;
                }
            }
        }

        //returns the probability that a given value is at an index
        return (double)indexAmount / testAmount;
    }

    friend ostream& operator << (ostream& outs, Random<T> random){
        int i;
        //loop through each element in vector and return its contents formatted all nice and stuff
        for(i = 0; i < random.randVec.size(); ++i){
            cout << random.randVec[i] << ", ";
        }
        cout << endl;
    }
};


#endif //M2AP_BKSOUCY_KJABLON4_AMKNOBEL_DFOURNI2_BKSOUCYRANDOM_H
