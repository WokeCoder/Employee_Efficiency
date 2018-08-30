/* 
 * File:   score.cpp
 * @author Tye GB
 * 
 * This is a object that is used to calculate a score based on errors, time, 
 * tasks assigned, and tasks done. The higher the score the better. These scores
 * can be used to evaluate employees against one another to see who is more 
 * productive.
 * 
 * Created on August 15, 2018, 10:42 PM
 */

#include <cstdlib>
#include <iostream>
#include "score.h"
/**
 *Sets all the values to zero.
 */
score::score() {
    errorsMade = 0;
    timeTaken = 0;
    tasksAsgn = 0;
    tasksDone = 0;
}

/**
 * This function is used to update the error, time, tasks assigned, and tasks
 * done. 
 * @param e the errors value
 * @param t the time value.
 * @param ta the tasks assigned value.
 * @param td the tasks done value.
 */
void score::updateScore(int e, double t, int ta, int td) {
    try {
        if (ta < td) {
            throw "Update Error!: Tasks Assigned must be greater then or "
            "equal too Tasks Done";
        }
        if (e < 0 || t < 0 || ta < 0 || td < 0) {
            throw "Error: No negative values!";
        }

        errorsMade = errorsMade + e;
        timeTaken = timeTaken + t;
        tasksAsgn = tasksAsgn + ta;
        tasksDone = tasksDone + td;

    } catch (const char * e) {
        std::cout << &e << std::endl;
    }
}
/**
 * This function takes the total errors, time, tasks assigned, and tasks done 
 * values to calculate the score value.
 * @return the score value.
 */
double score::getScore() {
    try {
        if (tasksAsgn < 5) {
            throw "Not enough task assigned! Wait for more updates";
        } else {
            prodScore =
                    (tasksDone / tasksAsgn)
                    +(tasksDone / timeTaken)
                    -(errorsMade / (10 * tasksDone));
            return prodScore;
        }
    } catch (const char * e) {
        std::cout << &e << std::endl;
    }
}

int score::getErrors(){
    return errorsMade;
}
double score::getTime(){
    return timeTaken;
}
int score::getTaskDone(){
    return tasksDone;
}
int score::getTaskAssigned(){
    return tasksAsgn;
}

score::~score() {
}

