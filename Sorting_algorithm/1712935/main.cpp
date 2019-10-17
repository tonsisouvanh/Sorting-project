#include"sort.h"
void main(){
	SORT s1,s2,s3;
	int key;
	do{
		cout << "0.Exit" << endl;
		cout << "1.Sorted case" << endl;
		cout << "2.Reversed case" << endl;
		cout << "3.Random case" << endl;
		cout << "4.Run All" << endl;
		cout << "Enter number to run: "; cin >> key;

		if (key == 0){
			return;
		}
		if (key == 1){
			system("cls");
			s1.case_sorted(1);
			cout << "Press \"Enter\" to run other task!" << endl; getchar(); getchar();
			system("cls");
			continue;
		}
		if (key == 2){
			system("cls");
			s2.case_reversed(2);
			cout << "Press \"Enter\" to run other task!" << endl; getchar(); getchar();
			system("cls");
			continue;
		}
		if (key == 3){
			system("cls");
			s3.case_random(3);
			cout << "Press \"Enter\" to run other task!" << endl; getchar(); getchar();
			system("cls");
			continue;
		}
		if (key == 4){
			system("cls");
			s1.case_sorted(1);
			s2.case_reversed(2);
			s3.case_random(3);
			cout << "Press \"Enter\" to run other task!" << endl; getchar(); getchar();
			system("cls");
			continue;
		}

	} while (1);

}