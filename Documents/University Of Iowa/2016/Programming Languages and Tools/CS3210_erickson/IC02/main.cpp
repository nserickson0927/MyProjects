#include <iostream>
#include <string>

int main(int argc, char **argv) {
    /*std::cout << "Hello, world!" << std::endl;
    int age=44;
    while(age>500)
    {
    //do stuff
      
    }
    int month=3;
    switch(month)//only works with intergers
    {
      case 0:
	//do stuff
	break;
      case 1:
	//do stuff
	break;
      default:
	std::cout<<"hello"<<std::endl;
	
    }
    
    for(int a = 0, b = 3.9; a<10 ; a++)
    {
      std::cout<<a<<std::endl;
    }
    
    //************************************/
    //Arrays
    //type arrayName[length]={};
    /*
    int numberOfGrades=5;
    
    int grades[numberOfGrades]={};
    

    for(int x = 0; x<numberOfGrades; x++)
    {
     std::cout<< "Grades[" <<x<< "]=" <<grades[x]<<std::endl; 
    }
    
    //use cstyle strings
    //terminating '\0' null character
    char name[5]="J\te";
    //wchar_t name[5]=L"Je";
    std::cout<<sizeof(name);
    std::cout<<name;
    
    //check size to see the extra character
    //R is a raw string R"(______)"
    */
    
    //using C++ strings
    using std::string;
    
    string myFirstName="Nicholas";
    string myLastName="Erickson";
    string myFullName=myFirstName+myLastName;
    
    std::cout<<myFirstName.size()<<std::endl;
    std::cout<<myFullName<<std::endl;
    
    //sturctures
    
    struct book{
      int numberOfPages;
      string Author;
    };
    
    book myFavoriteBook={3,"King"};
    
    std::cout<<myFavoriteBook.Author<<std::endl;
    
    myFavoriteBook.Author="Dickens";
    
    
    
    int numApples=5;
    //std::cout<<&numApples<<std::endl;
    int * ptr_numApples=&numApples;
    std::cout<<&numApples<<std::endl;
    std::cout<<* ptr_numApples<<std::endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
