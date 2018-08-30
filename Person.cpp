/* 
 * File:   Person.cpp
 * @author Tye GB
 * 
 * This is file to create Person object the given them a first name, age, and 
 * add all their score values.
 *  
 * Created on August 15, 2018, 10:25 PM
 */
#include <cstdlib>
#include <iostream>
#include "Person.h"
#include "score.h"

/**
 * This is the Person object constructor.
 * @param n This is the objects name.
 * @param a This is the objects age.
 */
Person::Person(std::string n, int a) {
    name = n;
    age = a;
    score *val = new score;
    obj = val;
}
/**
 * To get the objects name.
 * @return the objects name.
 */
std::string Person::getName() {
    return name;
}

/**
 * To get the objects age.
 * @return the objects age.
 */
int Person::getAge() {
    return age;
}

/**
 * Take in the processing values and places them with the correct object.
 * @param e is the amount errors committed.
 * @param t is the time it takes to complete new tasks.
 * @param ta the amount of tasks assigned.
 * @param td the number of task completed.
 */
void Person::setScore(int e, double t, int ta, int td) {
    obj->updateScore(e, t, ta, td);
}

/**
 * Gets the objects score.
 * @return the persons score.
 */
double Person::getScore() {
    return obj->getScore();
    
}
/**
 * Gets the objects total errors.
 * @return the objects total errors.
 */
int Person::getError() {
    return obj->getErrors();
}
/**
 * Gets the objects total tasks assigned.
 * @return the objects total tasks assigned.
 */
int Person::getTaskAsgn() {
    return obj->getTaskAssigned();
}
/**
 * Gets the objects total tasks done.
 * @return the objects total tasks done.
 */
int Person::getTaskDone() {
    return obj->getTaskDone();
}
/**
 * Gets the objects total time.
 * @return the objects total time.
 */
double Person::getTime() {
    return obj->getTime();
}

Person::~Person() {
}

