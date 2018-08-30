/* 
 * File:   score.h
 * @author Tye GB
 *
 * Created on August 15, 2018, 10:42 PM
 */

#ifndef SCORE_H
#define SCORE_H

class score {
public:
  
    score();
    void updateScore(int e, double t, int ta, int td);
    double getScore();
    int getErrors();
    double getTime();
    int getTaskDone();
    int getTaskAssigned();
    virtual ~score();
protected:
     double prodScore;
private:
    int errorsMade;
    double timeTaken;
    int tasksDone;
    int tasksAsgn;
   
};

#endif /* SCORE_H */

