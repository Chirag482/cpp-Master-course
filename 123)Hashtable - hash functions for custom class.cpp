#include <iostream>
#include<cstring>
#include<unordered_map>
using namespace std;

class Student{
    public:

    string firstname;
    string lastname;
    string rollno;

    Student(string f,string l,string no){
        firstname = f;
        lastname  = l;
        rollno = no;
    }

    bool operator==(const Student&s)const{
        return rollno==s.rollno?true:false;
    }
};

class Hashfn{
public:
    size_t operator()(const Student &s)const{
        return s.firstname.length()+s.lastname.length();
    }
};

int main() {

    unordered_map<Student,int,Hashfn> student_map;


    Student s1("Prateek","Narang","010");
    Student s2("Rahul","Kumar","023");
    Student s3("Prateek","Gupta","030");
    Student s4("Rahul","Kumar","120");

    //add students - marks to hashmaps
    student_map[s1] = 100;
    student_map[s2] = 120;
    student_map[s3] = 11;
    student_map[s4] = 45;

    //find the marks of student s3
    cout<<student_map[s3]<<endl;

    //iterator all over the hashtable
    for(auto s:student_map){
        cout<<s.first.firstname<<" "<<s.first.lastname<<" ,Marks => "<<s.second<<endl;
    }
    return 0;
}

