#include <iostream>
#include <assert.h>
#include <queue>
#include <vector>
using namespace std;

class Student {
public:
	string name = " ";
	string surname = " ";
	int age = 0;
	double score = 0;
	Student() {	}

	Student(string name, string surname, int age, int score) {
		this->name = name;
		this->surname = surname;
		this->age = age;
		this->score = score;
	}

	bool operator>(const Student& obj) {
		return score > obj.score;
	}

	friend ostream& operator<<(ostream& out, const Student& obj) {

		out << "Name: " << obj.name << "\nSurname: " << obj.surname << "\nAge: " << obj.age << "\nAveraga Score: " << obj.score << "\n==========================\n";
		return out;

	}
};

template<class T>
class PriorityQueue {
	T* arr;
	int capacity;
	int rear;
	int count;

	int FindMaxIndex() {
		int maxIndex = 0;
		for (int i = 0; i < count; i++) {
			if (arr[i] > arr[maxIndex]) {
				maxIndex = i;
			}
		}
		return maxIndex;
	}
public:
	PriorityQueue(int size) {
		arr = new T[size];
		capacity = size;
		count = 0;
		rear = -1;
	}

	bool IsArrFull()const { 
		return capacity == count;
	}
	bool IsArrEmpty()const {
		return 0 == count;
	}

	void Pop() {
		assert(!IsArrEmpty());
		int index = FindMaxIndex();
		for (int i = 0; i < count - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		count--;
	}

	void Push(T element) {
		assert(!IsArrFull());
		arr[++rear] = element;
		count++;
	}

	void Show() {
		for (int i = 0; i < count; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	~PriorityQueue() {
		delete[] arr;
	}
};

void main() {
	PriorityQueue<Student> pqa(5);
	pqa.Push(Student("Nigar", "Mustadazada", 18, 88.8));
	pqa.Push(Student("Aysu", "Alifbeyli", 20, 93.8));
	pqa.Push(Student("Aynura", "Abbasli", 20, 90));
	pqa.Push(Student("Anar", "Fermanli", 19, 83.9));
	pqa.Show();
	pqa.Pop();
	pqa.Show();
}