#ifndef HEAP_H
#define HEAP_H
class StudentMaxHeap;
class Student {
friend class StudentMaxHeap;
private:
double cgpa; // Student’s CGPA
int rollNo; // Student’s roll number
};
class StudentMaxHeap {
private:
Student* st; // Array of students which will be arranged like a Max Heap
int currSize; // Current number of students present in the heap
int maxSize; // Maximum number of students that can be present in the heap
void swap(Student & a,Student &b);
int  height (Student* s);
public:
StudentMaxHeap (int size); // Constructor
~StudentMaxHeap(); // Destructor
bool isEmpty(); // Checks whether the heap is empty or not
bool isFull(); // Checks whether the heap is full or not
bool insert (int rollN, double cgp);\
bool removeBestStudent (int& rollN, double& cgp);
int height ();
};

#endif