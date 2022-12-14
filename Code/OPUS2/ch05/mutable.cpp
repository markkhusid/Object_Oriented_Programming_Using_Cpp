/*********************************************************************

  Filename:  mutable.cpp
  Chapter:   5      Data Hiding and Member Functions
  Section:   5.6    Static Member
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include <iostream.h>
#include <string.h>

class person {         //class with mutable members
public:
	person(const char* pname, int page, unsigned long ssno) :
		 age(page), soc_sec(ssno)
		 { name = new char [ (strlen(pname)+ 1) ];
			strcpy(name, pname); }
	void bday()  { ++age; }
	void print() const { cout << name << " is " << age
							  << " years old. SSN = "
							  << soc_sec << endl; }
private:
	char*   name;
	mutable int   age;   //always modifiable
   unsigned long soc_sec;
};

int main()
{
 	const
   person ira("ira pohl", 38, 1654);

	ira.print();
	ira.bday();
   ira.print();
}
