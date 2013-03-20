#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
class people
{
  private:
    char* name_;
    int age_;

  public: 
    static int count;

  public:
    people(){name_=NULL; age_=0; count++;}
    people(char*name, int age){name_=new char[strlen(name)+1]; strcpy(name_,name); age_=age; count++;}
    ~people(){delete name_; count--;}
    char* get_name(){return name_;}
    int get_age(){return age_;}
    virtual void print_info() {printf("People class print: %s\t%d\n", name_, age_);}
};
int people::count =0;

class student: public people
{
  private:
    char* school_;
    int grade_;
  public:
    student(){school_=NULL; grade_=0;};
    student(char* school, int grade){school_=new char[strlen(school)+1]; strcpy(school_, school); grade_=grade;}
    student(char* name, int age, char* school, int grade):people(name, age)
    {
      school_=new char[strlen(school)+1]; strcpy(school_, school); grade_=grade;
    }

    ~student(){delete school_;}
    void print_info() {printf("student class print:%d\t%s\t%d\t%s\t%d\n", count, get_name(), get_age(),school_, grade_);}
};

class worker: public people
{
  private:
    char* company_; 
    int salary_;
  public:
    worker(){company_=NULL; salary_=0;};
    worker(char* company, int salary) {company_=new char[strlen(company)+1]; strcpy(company_, company); salary_ = salary;}
    ~worker(){delete company_;}
    void print_info() {printf("worker class print: %s\t%d\n", company_, salary_);}
};

int main(int argc, char** argv)
{
  class student s1("Zi", 28, "USC", 3);
  class worker w1("Google", 20000);
  class people * p1=&s1;
  p1->print_info();
}

