typedef struct person{
	char name[40];
	int age;
	int salary;
	} person;
void create(person** arr,int*n);
void read(person** arr,int*n);
void write(person* arr,int n);
void search(person* arr,int n);
