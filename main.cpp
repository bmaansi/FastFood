//Individual Project 2
//
//Maansi Bhardwaj
//Oct 17, 2022
#include "Categories.h"

int main() {
  printf("\033c");
  int choice(0);
  char goAgain('n');
  string filename("fastfood.csv");
  CategoriesUsage cu;
  vector<Categories> cat = cu.vCategories(filename);

  do {
    choice = cu.UserInput();
    if (choice == 0) {break;}
    if (choice == 5) {
      cu.Average();
    }

    if (choice < 5) {
      cu.mostOrLeast(choice);
    }
    
   goAgain = cu.goAgain();
  } while (goAgain == 'y' || goAgain == 'Y');  

    printf("\033c");
}
