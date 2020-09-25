#include <iostream>
#include <string>
using namespace std;

struct Student {
  int rno;
  string name;
  double sgpa;
};
class Students {
  Student arr[20];
  Student temp;
  public:
  int n, i, j;
  double pivot;
  void input();
  void display();
  void bubbleSort();
  void insertionSort();
  int quickSort1(Student arr[], int l, int h);
  void quickSort2(Student arr[], int l, int h);
  void sameSGPA();
  void binarySearch();
};
void Students :: input() {
  cout << "Enter the number of students: ";
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << "Enter roll no.: ";
    cin >> arr[i].rno;
    cout << "Enter name: ";
    cin >> arr[i].name;
    cout << "Enter SGPA: ";
    cin >> arr[i].sgpa;
  }
}
void Students :: display() {
  cout << "Displaying student details: " << endl;
  for (int i = 0; i < n; i++) {
    cout << "Roll No.: " << arr[i].rno << endl;
    cout << "Name: " << arr[i].name << endl;
    cout << "SGPA: " << arr[i].sgpa << endl;
  }
}
void Students :: bubbleSort() {
  // int temp;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (arr[j].rno > arr[j + 1].rno) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  cout << "List sorted according to roll no: " << endl;
  for (int i = 0; i < n; i++) {
    cout << "Roll No.: " << arr[i].rno << " " << "Name: " << arr[i].name << endl;
  }
}
void Students :: insertionSort() {
  int i, j;
  // string temp;
  string sample;
  for (i = 1; i < n; i++) {
      temp = arr[i];
      sample = arr[i].name;
      j = i - 1;
      while (sample < arr[j].name && j >= 0) {
        arr[j + 1] = arr[j];
        --j;
      }
      arr[j + 1] = temp;
  }
  cout << "List sorted according to names: " << endl;
  cout << "Name & Roll No.:" << endl;
  for (i = 0; i < n; i++) {
    cout << arr[i].name << " " << arr[i].rno << endl;
  }
}
// int Students :: quickSort1(Student arr[], int l, int h) {
  
//   pivot = arr[h].sgpa;
//   i = l;
//   for (j = l; j < h; j++) {
//     if (arr[j].sgpa >= pivot) {
//       temp = arr[j];
//       arr[j] = arr[i];
//       arr[i] = temp;
//       i++;
//     }
//   }
//   temp = arr[h];
//   arr[h] = arr[i];
//   arr[i] = temp;
//   return (i);
// }
// void Students :: quickSort2(Student arr[], int l, int h) {
//   int P;
//   if (l < h) {
//     P = quickSort1(arr, l, h);
//     quickSort2(arr, l, P - 1);
//     quickSort2(arr, P + 1, h);
//   }
// }
void Students :: sameSGPA() {
  double score;
  cout << "Enter SGPA to be searched: ";
  cin >> score;
  do {
    for (i = 0; i < n; i++) {
      if (arr[i].sgpa == score) {
        cout << "SGPA: " << arr[i].sgpa << " Name: " << arr[i].name << endl;
      }
    }
  } while (i > n);
}
void Students :: binarySearch() {
  int left, right, mid;
  string sname;
  cout << "Enter name to be searched: ";
  cin >> sname;
  left = 0;
  right = n - 1;
  mid = (left + right) / 2;
  while (left <= right) {
    if (arr[mid].name < sname) {
      left = mid + 1;
    }
    else if (arr[mid].name == sname) {
      cout << "Name: " << arr[mid].name << " SGPA: " << arr[mid].sgpa << endl;
      break;
    }
    else {
      right = mid - 1;
    }
    mid = (left + right) / 2;
  }
  if (left > right) {
    cout << "Name not found in list." << endl;
  }
}
int main() {
  Students s1;
  Student stud;
  s1.input();
  s1.display(); 
  s1.bubbleSort();
  s1.insertionSort();
  // s1.quickSort1(stud arr, 0, n - 1);
  // s1.quickSort2(stud arr, 0, n - 1);
  s1.sameSGPA();
  s1.binarySearch();
}
