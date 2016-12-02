#include <iostream>

//hello comment
/**/

int main(int argc, char **argv) {
    int dayOfTheWeek=1;
    int apple=1;
    switch(dayOfTheWeek)
    {
      case 1:
	std::cout<<"Sunday";
	break;
	
      case 2:
	std::cout<<"Monday";
	break;
	
      default: std::cout<<"no day";
    }
    
    while(apple<10)
    {
     apple++;
     std::cout<<apple<<std::endl;
     continue;
     std::cout<<"after continue"<< std::endl;
    }
    
    return 0;
}
