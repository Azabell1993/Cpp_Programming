#include <iostream>
#include <memory>

using namespace std;

int change_val(int* p) {
	*p = 10;
	return 0;
}

class Smart_Pointer {
	int* ptr;

public:
	Smart_Pointer() {
		ptr = new int[100];
		cout << "¸®¼Ò½º È¹µæ\n";
	}

	~Smart_Pointer() {
		cout << "¼Ò¸êÀÚ È£Ãâ\n";
		delete[] ptr;
	}

	void do_someting(int a) {
		cout << "Do something\n";
		ptr[0] = a;
	}
};

void func(unique_ptr<Smart_Pointer>& Nptr) {
	Nptr -> do_someting(3);
}

int main()
{
	int number = 5;
	cout << number << endl;
	change_val(&number);
	cout << number << endl;

	//Reference Method
	int Num = 10;
	int& another_Num = Num;

	another_Num = 12;
	cout << "Num : " << Num << endl;
	cout << "another_a Num : " << another_Num << endl;

	cout << endl;
	unique_ptr<Smart_Pointer> sptr(new Smart_Pointer());
	func(sptr);

	return (0);
}