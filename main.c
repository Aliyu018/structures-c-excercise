#include <iostream>
using namespace std;

struct student {
	int id;
	float cgpa;
}list[10];

void disp_all();

void bubble_sort();
float bin_search(int key);
int main() {
//	take the numbers from the user
	for(int i = 0;i<10;i++){
		cout<<endl<<"Enter student "<<i+1<<" id: ";
		cin >>list[i].id;
		
		cout<<endl<<"Enter student "<<i+1<<" cgpa: ";
		cin >>list[i].cgpa;
	}
//	display all the numbers
	disp_all();
//	apply bubble sort
	bubble_sort();
	cout<<endl<<"After bubble sort applied";
//	display after bubble sort
	disp_all();
	
	int key;
	cout<<endl<<"Enter search key: ";
	cin >>key;
//	perform binary search. if return value is -1. id not found. else return the cgpa of the student
	float cgpa = bin_search(key);
	if(cgpa == -1){
		cout<<endl<<"not found";
	}
	else {
		cout<<"student id: "<<key<<" cgpa: "<<cgpa;
	}
	return 0;
}

void disp_all(){
	cout<<endl<<endl<<"id\tcgpa";
	for(int i=0;i<10;i++) {
		cout<<endl<<list[i].id<<"\t"<<list[i].cgpa;	
	}
}

void bubble_sort(){
	for(int i=0;i<10;i++){
//		create an inner loop for iterating the next numbers
		for(int j=i+1;j<10;j++){
//			swp block... use > for desc order
			if(list[j].cgpa < list[i].cgpa){
				float temp;
				temp = list[i].cgpa;
				list[i].cgpa = list[j].cgpa;
				list[j].cgpa = temp;
				
				int tempId;
				tempId = list[i].id;
				list[i].id = list[j].id;
				list[j].id = tempId;
			}
		}
	}
}


float bin_search(int key)
{
	cout<<endl<<"our key is: "<<key;
	int low,high,middle;
	low = 0;
	high = 9;
	while(low<=high){
		middle = low + (high-low)/2;
		if(list[middle].id ==key){
			return list[middle].cgpa;
		}
		else if (list[middle].id < key)
			low = middle+1;
		else
			high = middle-1;
			}
	return -1;
}















