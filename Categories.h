//Individual Project 2
//
//Maansi Bhardwaj
//Oct 17, 2022
#pragma once
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Categories {
  string Restaurant;
  string ItemName;
  int Calories;
  int TotalFat;
  int Sodium;
  int Protein;
};

//compare category by calories by ascending order
bool compareCatByCalAsc(Categories c1, Categories c2);

//compare category by calories by descending order
bool compareCatByCalDesc(Categories c1, Categories c2);

//compare category by totalfat by ascending order
bool compareCatByTFatAsc(Categories c1, Categories c2);

//compare category by totalfat by descending order
bool compareCatByTFatDesc(Categories c1, Categories c2);

//compare category by sodium by ascending order
bool compareCatBySodAsc(Categories c1, Categories c2);

//compare category by sodium by descending order 
bool compareCatBySodDesc(Categories c1, Categories c2);

//compare category by protein by ascending order
bool compareCatByProAsc(Categories c1, Categories c2);

//compare category by protein by descending order
bool compareCatByProDesc(Categories c1, Categories c2);

class CategoriesUsage {
public: 
  //collects all the info from file and puts it in a <Categories> vector
  vector<Categories> vCategories(string filename);

  //just stores the string 
  string toString(Categories c);

  //prints the toString() and a little chart of the info
  void printCatVector();

  //displays info
  void Display();

  //Displays the options and gets the user's input
  int  UserInput(); 

  //find average of item
  void Average(); 

  //switch statement for if the want top 5
  void switchGreatestToLeast(int choice); 

  //switch statement for if the want least 5
  void switchLeastToGreatest(int choice);

  //asks the user if they want the top/bottom 5
  void mostOrLeast(int choice);

  //ask user if they want to go again
  char goAgain();

private:
  vector<Categories> cat;
};
