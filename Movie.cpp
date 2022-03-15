#include <string>
#include "Movie.h"
#include <fstream>
#include <iostream>
#include <sstream>    

using namespace std;

IntSLList::~IntSLList() {
   for (IntSLLNode *p; !isEmpty(); ) {
   	//
    p = name_head->name_next;
    delete name_head;
    name_head = p;
    //
    p=rate_head->rate_next;
    delete rate_head;
    rate_head=p;
    //	
    p=year_head->year_next;
    delete year_head;
    year_head=p;    
 }
}
   
void IntSLList::add(string name,double rate,int year){
	IntSLLNode *tmp = new IntSLLNode(name,rate,year);
	IntSLLNode *cur_name,*cur_rate,*cur_year;
	tmp->name=name;
	tmp->name_next=NULL;
	//
	tmp->year=year;
	tmp->year_next=NULL;
	//
	tmp->rate=rate;
	tmp->rate_next=NULL;
	
	if((name_head==NULL)
	&&(rate_head==NULL)&&(year_head==NULL)){
		name_head=name_tail=tmp;
		rate_head=rate_tail=tmp;	
		year_head=year_tail=tmp;	
	}

	else{
		IntSLLNode *prev=NULL;
		//add name
		for(cur_name=name_head; cur_name!=NULL && cur_name->name < name;
		    cur_name=cur_name->name_next){
		    prev=cur_name;	
		} 
		if(name_head==cur_name){
		    name_head=tmp;
		    tmp->name_next=cur_name;
		}
		else if(cur_name==NULL){
	        prev->name_next = tmp;
            tmp->name_next = cur_name;
		}
		//add rate
		for(cur_rate=rate_head; cur_rate!=NULL && cur_rate->rate < rate;
		   cur_rate=cur_rate->rate_next){
		    prev=cur_rate;
		}
		if(rate_head==cur_rate){
		    rate_head=tmp;
		    tmp->rate_next=cur_rate;
		}
		else if(cur_rate==NULL){
	        prev->rate_next = tmp;
            tmp->rate_next = cur_rate;
		}
		//add year
		for(cur_year=year_head; cur_year!=NULL && cur_year->year < year;
		    cur_year=cur_year->year_next){
		    	prev=cur_year;
		        	
		}
		if(year_head==cur_year){
		    year_head=tmp;
		    tmp->year_next=cur_year;
		}
	    else if(cur_year==NULL){
	        prev->year_next = tmp;
            tmp->year_next = cur_year;
		}
		
	}
	
}
bool  IntSLList::remove(string name){
    int year;
    IntSLLNode *tmp=NULL;
    IntSLLNode *prev=NULL;
	IntSLLNode *cur_name;
	IntSLLNode *p;
    if(name_head==NULL){//empty
            return false;
        }
    else
    {
        for(cur_name=name_head;cur_name!=NULL&&cur_name->name!=name;
            cur_name=cur_name->name_next){
            prev=cur_name;
        }
           
    
        if(prev==NULL){
            name_head=name_head->name_next;//delete beginning
    	}
    	else if(tmp==NULL){
    	    cout<<"There is no movie like this"<<endl;
    	}
    	else {
    	    tmp=cur_name->name_next;
    	    prev->name_next = tmp;
    	    delete tmp;
    	}
        return true;
    }

}


void IntSLList::update(string name,double rate) {
    remove(name);
    int year;
    cout<<"Please enter same year:)"<<endl;
    cin>>year;
    add(name,rate,year);
}
 
void IntSLList::printByYear()  {
	// 
    for (IntSLLNode *tmp = year_head; tmp != 0; tmp = tmp->year_next)
        cout << tmp->year<<","<<tmp->name<<","<<tmp->rate<<endl;
        
}

void IntSLList::printByName()  {
    for (IntSLLNode *tmp = name_head; tmp != 0; tmp = tmp->name_next)
        cout << tmp->name<<","<<tmp->rate<<","<<tmp->year<<endl;
        
}

void IntSLList::printByRate()  {
    for (IntSLLNode *tmp = rate_head; tmp != 0; tmp = tmp->rate_next)
        cout << tmp->rate<<","<<tmp->name<<","<<tmp->year<<endl;
        
}
 
void IntSLList:: loadFile(string filename){
    ifstream newfile(filename);//create file,class for read on it
    string name;
    double rate;
    int year;
    string str;
    if(newfile.is_open()){
        while(getline(newfile,str)){
		    std::istringstream iss(str);
		    std::istringstream ss(str);
		    iss>>str;
		    ss>>name;
            iss>>rate;
            iss>>year;
            add(name,rate,year);
        }
    }
    
    newfile.close();
}


void IntSLList::saveToFileByYear(string filename){
    ofstream newfile(filename);// create file, class for write on it
    if(newfile.is_open()){
        for(IntSLLNode *tmp=year_head;tmp!=0;tmp=tmp->year_next){
            newfile<<tmp->year<<","<<tmp->name<<","<<tmp->rate<<endl;
        }
        newfile.close();
    }
}

void IntSLList::saveToFileByName(string filename){
    ofstream newfile(filename);// create files 
    if(newfile.is_open()){
        for(IntSLLNode *tmp=name_head;tmp!=0;tmp=tmp->name_next){
            newfile<<tmp->name<<","<<tmp->rate<<","<<tmp->year<<endl;//write information to newfile.
        }
        newfile.close();
    }
}
void IntSLList::saveToFileRate (string filename){
    ofstream newfile(filename);// create files 
    if(newfile.is_open()){
        for(IntSLLNode *tmp=rate_head;tmp!=0;tmp=tmp->rate_next){
            newfile<<tmp->rate<<","<<tmp->name<<","<<tmp->year<<endl;//write information to newfile.
        }
        newfile.close();
    }
}





