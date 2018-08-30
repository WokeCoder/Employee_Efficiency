
/* 
 * File:   Person.h
 * @author Tye GB
 *
 * Created on August 15, 2018, 10:25 PM
 */

#ifndef PERSON_H
#define PERSON_H
#include "score.h"



class Person {
    
public:
    Person(std::string n , int a);
    std::string getName();
    int getAge();
    double getScore();
    void setAge();
    void setScore(int e, double t, int ta, int td);
    int getError();
    int getTaskAsgn();
    int getTaskDone();
    double getTime();
    virtual ~Person();

private:
    std::string name;
    int age;
    score * obj;
    
};

#endif /* PERSON_H */

