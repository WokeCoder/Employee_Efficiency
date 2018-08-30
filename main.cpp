
/* 
 * File:   main.cpp
 * @author Tye GB
 * 
 * The purpose of this project is create application where the user can rate 
 * their employee's and find out how efficiently they work. The score given is
 * based on the error's committed person task with a max being ten. The total
 * time it takes them to complete their tasks. The number of assigned to them,
 * and the tasks they finished or completed.
 * 
 * Created on August 15, 2018, 10:17 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Person.h"
#include "score.h"

/**
 * Displays a menu then return the users selection.
 * @return The user's menu selection.
 */
int menu();
/**
 * Creates an Person object to be added to the Employee vector.
 * @return A Person object.
 */
Person add();
/**
 * Allows the user to update a given an employee's errors, time , tasks 
 * assigned, and tasks done.
 * @param employ is the employee vector of the employee's.
 */
void edit(std::vector<Person> employ);
/**
 * Computes the total rating of a certain employee.
 * @param employ is the employee vector of the employee's.
 */
void getScore(std::vector<Person> employ);
/**
 * Saves all the employee's added to a text file called Employee.txt. 
 * @param employ is the employee vector of the employee's.
 * @param fName the file that the list will be saved too.
 */
void save(std::vector<Person> employ, std::string fName);
/**
 * End's the program.
 */
void quit();

int main(int argc, char** argv) {

    //The vector holding all the employee's.
    std::vector<Person> employees;
    //The file the data will be saved  too.
    std::string fileName = "Employee.txt";
    //For writing to the file.
    std::ofstream outFile;
    //For reading from the file.
    std::ifstream inFile;

    inFile.open(fileName);

    /*
     * If the file currently exists reading in its data a storing it 
     * in the employee vector.
     */
    if (inFile.is_open()) {
        std::string name;
        int age, error, taskA, taskD;
        double time;

        while (inFile >> name >> age >> error >> time >> taskA >> taskD) {
            Person temp = Person(name, age);
            temp.setScore(error, time, taskA, taskD);
            employees.push_back(temp);
        }

    } else { //Creating the file if it doesn't exist.
        outFile.open(fileName);
        outFile.close();
    }

    //Running through the menu options.
    while (true) {
        switch (menu()) {
            case 1:
                employees.push_back(add());
                break;
            case 2:
                edit(employees);
                break;
            case 3:
                getScore(employees);
                break;
            case 4:
                save(employees, fileName);
                break;
            case 5:
                quit();
                break;
        }
    }
    return 0;
}

//Creates an Person object to be added to the Employee vector.

int menu() {
    std::cout << "Menu Options: " << std::endl;
    std::cout << "1 - Add Employee\n"
            "2 - Update Employee Score\n"
            "3 - Get Employee Score\n"
            "4 - Save\n"
            "5 - Quit " << std::endl;
    int ans;
    std::cin >> ans;
    return ans;
}
//Creates an Person object to be added to the Employee vector.

Person add() {
    std::string name;
    int age;
    std::cout << "Employee Name : " << std::endl;
    std::cin >> name;
    std::cout << "Age : " << std::endl;
    std::cin >> age;
    Person obj = Person(name, age);
    return obj;
}

/**
 * Allows the user to update a given an employee's errors, time , tasks 
 * assigned, and tasks done.
 */
void edit(std::vector<Person> employ) {
    try {
        std::string name;
        std::cout << "Who would you like to update ?: " << std::endl;
        std::cin >> name;

        std::vector<Person>::iterator pers = std::find_if(employ.begin(),
                employ.end(), [&name](Person & obj) {
                    return obj.getName() == name;
                });
        if (pers == employ.end()) {
            throw "Person does not exist!";
        } else {
            int err, ta, td;
            double time;

            std::cout << "How long did it take? " << std::endl;
            std::cin >> time;
            std::cout << "How many task were assigned? " << std::endl;
            std::cin >> ta;
            std::cout << "How many tasked were finished? " << std::endl;
            std::cin >> td;
            std::cout << "How many errors were committed? " << std::endl;
            std::cin >> err;

            pers.base()->setScore(err, time, ta, td);
        }
    } catch (const char* &e) {
        std::cout << e << std::endl;
    }
}

//Computes the total rating of a certain employee.

void getScore(std::vector<Person> employ) {
    try {
        std::string name;
        std::cout << "Who's Score would you like ? : " << std::endl;
        std::cin >> name;
        std::vector<Person>::iterator pers = std::find_if(employ.begin(),
                employ.end(), [&name](Person & obj) {
                    return obj.getName() == name;
                });
        if (pers == employ.end()) {
            throw "Person does not exist!";
        } else {
            double scr;
            scr = pers.base()->getScore();
            std::cout << name << "'s score was " << scr << std::endl;
        }
    } catch (const char* &e) {
        std::cout << e << std::endl;
    }
}

//Saves all the employee's added to a text file called Employee.txt. 

void save(std::vector<Person> employ, std::string fName) {
    std::ofstream outFile;
    outFile.open(fName);
    for (int i = 0; i < employ.size(); i++) {
        outFile << employ[i].getName() << " "
                << employ[i].getAge() << " "
                << employ[i].getError() << " "
                << employ[i].getTime() << " "
                << employ[i].getTaskAsgn() << " "
                << employ[i].getTaskDone() << std::endl;
    }
    outFile.close();
}

//End's the program.

void quit() {
    std::exit(0);
}
