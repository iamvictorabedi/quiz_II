#include <iostream>
using namespace std;

class Student{
	public:
		Student *snext;
		Student *previous;
		int stud_no, quiz_one, quiz_two;
		double total, average;
		Student(int sno, int qone, int qtwo){
			stud_no = sno;
			quiz_one = qone;
			quiz_two = qtwo;
			total = 0;
			average = 0;
			snext = NULL;
			previous= NULL;

		}
		
		void display(){
			//	Efficiency O(N) since items can only be viewed one at a time regradles of the size
		cout<< "{Student No: "<< stud_no << "  Quiz One: "<< quiz_one<< "  Quiz Two: "<< quiz_two << " Average :"<< average <<  "  Total: " << total<<"}";
		cout<< endl;
		}
		
	
};

class StudentList{
		private:
		Student *sFirst;
		
		public:
		int a;
		
		StudentList(){
			sFirst = NULL;
		}
		
		void insert(int stud_no, int quiz_one, int quiz_two){
			//	Efficiency O(N) since it involves changing one pointer
			Student *snewLink = new Student(stud_no, quiz_one, quiz_two);
			snewLink->snext = sFirst;
			sFirst = snewLink;
		}
		
		void displayFirstThreeStudent(){
			//	Efficiency O(N) since items can only be viewed one at a time regradles of the size
			Student *scurrent;
			scurrent = sFirst;
			for(a = 0; a< 3; a++){
			scurrent->display();
			scurrent=scurrent->snext;
			}
			cout<< endl;
		}
		
		
		void displayStudent(){
			//	Efficiency O(N) since items can only be viewed one at a time regradles of the size
			Student *scurrent;
			scurrent = sFirst;
			while(scurrent !=NULL){
			scurrent->display();
			scurrent=scurrent->snext;
			}
			cout<< endl;
		}
		
				
		void displayStudentAverageAndTotal(){
			//	Efficiency O(N) since one has to go through on item calculate the logic and move on to the next one

			Student *scurrent;
			scurrent = sFirst;
			double total, average;
			total = 0;
			average = 0;
			while(scurrent !=NULL){
			scurrent->total = total + scurrent->quiz_one + scurrent->quiz_two;
			scurrent->average = average + scurrent->total / 2;	
			scurrent->display();
			scurrent=scurrent->snext;
			}
			cout<< endl;

		}
		
		void averageScore(){
			//	Efficiency O(N) since one has to go through on item calculate the logic and move on to the next one
			Student *avgScore;
			avgScore = sFirst;
			double avgScr, stud_avg;
			avgScr = 0;
			stud_avg = 0;
				while(avgScore!=NULL){
				avgScr = (avgScr + avgScore->quiz_one + avgScore->quiz_two) /2 ;
				avgScore = avgScore->snext;
			}
			avgScr = avgScr /2;
			cout<< "Avearge total Score for all student = "<< avgScr<<endl;	
			studentBelowAVG(avgScr);
			
		}
		
	 void studentBelowAVG(double avg){
	 		//	Efficiency O(N) since result returned will be based on the N number of times that match the creteia
			Student *scurrent;
			scurrent = sFirst;
			cout<< "Student Below Average"<<endl;
			cout<< "---------------------"<<endl;
			while(scurrent !=NULL){
				if(scurrent->average < avg)
				{
					scurrent->display();
				}
			scurrent = scurrent->snext;
			}	
		}


void insertionSort()
{
//	Efficiency in O(N2)  since involves comparisions and swaps


Student *in, *out;

for(out=sFirst->snext; out!=NULL; out=out->snext)
{
	int studno = out->stud_no;
	int quizone = out->quiz_one;
	int quiztwo = out->quiz_two;
	double stotal = out->total;
	double saverage = out->average;
	in=out;
        	
while(in->previous!=NULL && in->previous->average>=saverage)
{

in->stud_no = in->previous->stud_no;              //swap
in->quiz_one = in->previous->quiz_one;              //swap
in->quiz_two = in->previous->quiz_two;              //swap
in->total = in->previous->total;              //swap
in->average = in->previous->average;              //swap

in=in->previous;
}

in->stud_no=studno;
in->quiz_one=quizone;
in->quiz_two=quiztwo;
in->total=stotal;
in->average=saverage;
}

}
		

};

int main(){
	StudentList student;
	student.insert(1, 20, 25);
	student.insert(4, 18, 23);
	student.insert(2, 29, 29);
	student.insert(3, 16, 26);
	student.insert(5, 23, 30);
	student.displayFirstThreeStudent();
	student.displayStudentAverageAndTotal();
	student.averageScore();
	cout<<"Insertion Sort \n";
	student.insertionSort();
	student.displayStudent();

}
