#ifndef _MOVIE_
#define _MOVIE_
#include <iostream>
#include <string>
using namespace std;
class IntSLLNode{
public:
   IntSLLNode() {
        name_next = 0;
        rate_next=0;
        year_next=0;
    }
    IntSLLNode(string name_el,double rate_el,int year_el,IntSLLNode *name_ptr = 0,IntSLLNode *rate_ptr = 0,IntSLLNode *year_ptr = 0) {
        name = name_el; rate=rate_el;year= year_el; name_next = name_ptr; rate_next=rate_ptr; year_next=year_ptr;
    }
    string name;
    double rate;
    int year;
    string filename;
    IntSLLNode *name_next,*rate_next,*year_next;
};

class IntSLList {
public:
	
    IntSLList() {
        name_head = name_tail = 0;
        rate_head = rate_tail = 0;
        year_head = year_tail = 0;  
    }
    ~IntSLList(); 
    int isEmpty() {
        return name_head == 0;
        return rate_head == 0;
        return year_head == 0;
        
    }
	void add(string,double,int);
	bool remove(string);
	void update(string,double);
	void printByYear() ;
    void printByName() ;
    void printByRate() ;
    void loadFile(string);
    void saveToFileByYear(string);
    void saveToFileByName(string);
    void saveToFileRate(string);
private:
    IntSLLNode *name_head, *name_tail;
    IntSLLNode *rate_head, *rate_tail;
	IntSLLNode *year_head, *year_tail;
	
};

#endif