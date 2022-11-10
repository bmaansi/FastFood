//Individual Project 2
//
//Maansi Bhardwaj
//Oct 17, 2022
#include "Categories.h"

bool compareCatByCalAsc(Categories c1, Categories c2) {
  return (c1.Calories < c2.Calories);
}

bool compareCatByCalDesc(Categories c1, Categories c2) {
  return (c1.Calories > c2.Calories);
}

bool compareCatByTFatAsc(Categories c1, Categories c2) {
  return (c1.TotalFat < c2.TotalFat);
}

bool compareCatByTFatDesc(Categories c1, Categories c2) {
  return (c1.TotalFat > c2.TotalFat);
}
 
bool compareCatBySodAsc(Categories c1, Categories c2) {
  return (c1.Sodium < c2.Sodium);
}

bool compareCatBySodDesc(Categories c1, Categories c2) {
  return (c1.Sodium > c2.Sodium);
}

bool compareCatByProAsc(Categories c1, Categories c2) {
  return (c1.Protein < c2.Protein);
}

bool compareCatByProDesc(Categories c1, Categories c2) {
  return (c1.Protein > c2.Protein);
}


vector<Categories> CategoriesUsage::vCategories(string filename) {
  ifstream file(filename);
  Categories c;
  int j(1);

  if (file.good()) {
    string nextline;
    string temp;
    
    while(getline(file, nextline)) {
      istringstream parser(nextline);
      if (!nextline.empty() && nextline[0] != '#') { 
        getline(parser, c.Restaurant, ','); 
        getline(parser, c.ItemName, ',');
        getline(parser, temp, ',');
        c.Calories = stoi(temp);
        for (size_t i(0); i < 2; i++) {getline(parser, temp, ',');}
        c.TotalFat = stoi(temp);
        
        for (size_t i(0); i < 4; i++) {getline(parser, temp, ',');}
        c.Sodium = stoi(temp);
        
        for (size_t i(0); i < 4; i++) {getline(parser, temp, ','); } 
        if (temp != "NA") {
          c.Protein = stoi(temp);
        } else {
          c.Protein = 0;
        }
      }

      if (!c.ItemName.empty()) { this->cat.push_back(c); }
    }
    
  } else {
    throw invalid_argument("could not open file");
  }
  return this->cat;
}


string CategoriesUsage::toString(Categories c) {
  ostringstream output;
  
  output << left << setw(12) << c.Restaurant << "| "  
         << right << setw(50) << c.ItemName << "| " 
         << right << setw(8) << c.Calories << "| " 
         << right << setw(9) << c.TotalFat <<  "| " 
         << right << setw(6) << c.Sodium << "| " 
         << right << setw(8) << c.Protein << "|";
  
  return output.str();
}

void CategoriesUsage::printCatVector() {
  size_t i(0);
  string dashes;
  dashes.assign(104, '-');
  cout << left << setw(12) << "RESTAURANT" << "| "
  << right << setw(50) << "FOOD NAME" << "| "
  << right << setw(8) << "CALORIES" << "| "
  << right << setw(9) << "TOTAL FAT" << "| "
  << right << setw(6) << "SODIUM" << "| "
  << right << setw(8) << "PROTEIN" << "| " << endl; 

  cout << dashes << endl;
  for (Categories c : this->cat) {
    if (i == 5) { break; }
    cout << toString(c) << endl;
    i++;
  }
  cout << dashes << endl;
}

void CategoriesUsage::Display() {

  cout << "You will view fast food by different nutritional value. You" << endl;
  cout << "will get to pick 4 different options: calories, total fat," << endl;
  cout << "sodium, or protein. You can also see the averages of each category." << endl;

  
  cout << "\nLoaded data for " << this->cat.size() << " food item." << endl << endl;
  cout << "PRESS ENTER TO CONTINUE. ";
  cin.ignore();

  printf("\033c");

  cout << "View item by..." << endl;
  cout << "1. Calories" << endl;
  cout << "2. Total Fat" << endl;
  cout << "3. Sodium" << endl;
  cout << "4. Protein" << endl;
  cout << "5. Average" << endl;
  cout << "0. Exit" << endl << endl;
  cout << "Pick category by number:  ";
}

int CategoriesUsage::UserInput() {
  int userinput(0);
  
  Display();
  cin >> userinput;

  while (userinput > 5 || userinput < 0) {
    cout << "Not avaliable, try again: ";
    cin >> userinput;
  }

  printf("\033c");

  return userinput;
}

void CategoriesUsage::Average() {
  double calories(0);
  double totalFat(0);
  double sodium(0);
  double protein(0);
  int size = cat.size();

  for (Categories c : this->cat) {
    calories += c.Calories;
    totalFat += c.TotalFat;
    sodium += c.Sodium;
    protein += c.Protein;
  }
  calories /= size;
  totalFat /= size;
  sodium /= size;
  protein /= size;

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  
  cout << "The Averages are: " << endl;
  cout << "CALORIES      ->  " << calories << endl;
  cout << "TOTAL FAT     ->  " << totalFat << endl;
  cout << "SODIUM        ->  " << sodium << endl; 
  cout << "PROTEIN       ->  " << protein << endl;

}

void CategoriesUsage::switchGreatestToLeast(int choice) {

  switch (choice) {
    case 1: 
      sort(this->cat.begin(), this->cat.end(), compareCatByCalDesc);
      printCatVector();
      break;
    case 2: 
      sort(this->cat.begin(), this->cat.end(), compareCatByTFatDesc);
      printCatVector();
      break;
    case 3: 
      sort(this->cat.begin(), this->cat.end(), compareCatBySodDesc);
      printCatVector();
      break;
    case 4: 
      sort(this->cat.begin(), this->cat.end(), compareCatByProDesc);
      printCatVector();
      break;
  }
}

void CategoriesUsage::switchLeastToGreatest(int choice) {
  
  switch (choice) {
    case 1: 
      sort(this->cat.begin(), this->cat.end(), compareCatByCalAsc);
      printCatVector();
      break;
    case 2: 
      sort(this->cat.begin(), this->cat.end(), compareCatByTFatAsc);
      printCatVector();
      break;
    case 3: 
      sort(this->cat.begin(), this->cat.end(), compareCatBySodAsc);
      printCatVector();
      break;
    case 4: 
      sort(this->cat.begin(), this->cat.end(), compareCatByProAsc);
      printCatVector();
      break;
  }
}

void CategoriesUsage::mostOrLeast(int choice) {
  int mostOrLeast(0);
  string category;
  if (choice == 1) { category = "calories"; }
  else if (choice == 2) { category = "total fat"; }
  else if (choice == 3) { category = "sodium"; }
  else if (choice == 4) { category = "protein"; }
  cout << "View " << category << " by Most(1) or Least(2): ";
  cin >> mostOrLeast;

  while (mostOrLeast != 1 && mostOrLeast != 2) {
    cout << "\nERROR: Pick Most(1)/Least(2): ";
    cin >> mostOrLeast;
  }
  printf("\033c");

  if (mostOrLeast == 1) {
    this->switchGreatestToLeast(choice);
  } else if (mostOrLeast == 2) {
    this->switchLeastToGreatest(choice);
  }
}

char CategoriesUsage::goAgain() {
  char goAgain('n');
  
  cout << endl << "Want to go again (y/n)? ";
  cin >> goAgain;
  return goAgain;
}
