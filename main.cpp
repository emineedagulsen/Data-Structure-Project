#include <iostream>
#include "Movie.h"
using namespace std;
int main(){
    string name;
    double rate;
    int year;
	string filename;
    IntSLList list;
    int input;
    while(true){
        cout<<"Enter a number 1 to 10:"<<endl;
        cin>>input;
               
        if(input==1){
            cout<<"1-Add a new movie"<<endl;
            cout<<"Please enter a movie name with its rate and year:"<<endl;
            cin>>name>>rate>>year;
            //LOTR 8.8 2001
            //Interstealler 8.6 2014
            list.add(name,rate,year);
        }
        else if(input==2){
            cout<<"2-Remove movie with its name "<<endl;
            cout<<"Please enter  a movie name that you want to remove"<<endl;
            cin>>name;
            list.remove(name);
            
        }
        else if(input==3){
            cout<<"3-Updates rate of movie "<<endl;
            cout<<"Please enter  a movie name and its new rate : "<<endl;
            cin>>name>>rate;
            list.update(name,rate);
        } 
        else if(input==4){
            cout<<"4-Print the movie according to year "<<endl;
            list.printByYear();
        }
        else if(input==5){
            cout<<"5-Print the movie according to name "<<endl;
            list.printByName();
        }
        else if(input==6){
            cout<<"6-Load a file"<<endl;
            cout<<"Please enter a filename"<<endl;
            cin>>filename;
            list.loadFile(filename);
        }
        else if(input==7){
            cout<<"7-Save the movies to a file according to year"<<endl;
            cout<<"Please enter a filename"<<endl;
            cin>>filename;
            list.saveToFileByYear(filename);
        }
        else if(input==8){
            cout<<"8-Save the movies to a file according to name"<<endl;
            cout<<"Please enter a filename"<<endl;
            cin>>filename;
            list.saveToFileByName(filename);
        }
        else if(input==9){
            cout<<"9-Save the movies to a file according to rate"<<endl;
            cout<<"Please enter a filename"<<endl;
            cin>>filename;
            list.saveToFileByYear(filename);
        }
        else
            break;
    }
}






