#include "naobehavior.h"
#include "../rvdraw/rvdraw.h"

#include <fstream>
#include <iomanip>
#include <sys/time.h>


extern int agentBodyType;

/*
 * Real game beaming.
 * Filling params x y angle
 */
void NaoBehavior::beam( double& beamX, double& beamY, double& beamAngle ) {
    beamX = -10;
    beamY = 0;
    beamAngle = 0;
}


SkillType NaoBehavior::selectSkill() {
    // My position and angle
    //cout << worldModel->getUNum() << ": " << worldModel->getMyPosition() << ",\t" << worldModel->getMyAngDeg() << "\n";

    // Position of the ball
    //cout << worldModel->getBall() << "\n";

    // Example usage of the roboviz drawing system and RVSender in rvdraw.cc.
    // Agents draw the position of where they think the ball is
    // Also see example in naobahevior.cc for drawing agent position and
    // orientation.
    /*
    worldModel->getRVSender()->clear(); // erases drawings from previous cycle
    worldModel->getRVSender()->drawPoint("ball", ball.getX(), ball.getY(), 10.0f, RVSender::MAGENTA);
    */

    // ### Demo Behaviors ###

    // Walk in different directions
   // VecPosition ballPos = worldModel->getBall();

    VecPosition myPos = worldModel->getMyPosition();
    double threshold = 0.5;
    fstream end_file;
    end_file.open("end_out",ios::out | ios::in);   
        
 if (myPos.getDistanceTo(VecPosition(-5,-5,0)) <= threshold){
       // gettimeofday(&tim, NULL);
      //  double t1=tim.tv_sec*1000000.0+tim.tv_usec;
       // printf("%.7f\n", t1 - 1460125000000000);
        if (!end_file.is_open()){
            end_file.open("end_out",ios::out);
            end_file << fixed << setw( 11 ) << setprecision(7) << worldModel->getGameTime() << endl;
       }
        // cout <<"time 2: "<<tim.tv_sec<<endl;
    }
    end_file.close();
    return  goToTarget(VecPosition(-5,-5,0));

    //return sk;
    //return goToTargetRelative(VecPosition(1,0,0), 0); // Forward
    //return goToTargetRelative(VecPosition(-1,0,0), 0); // Backward
    //return goToTargetRelative(VecPosition(0,1,0), 0); // Left
    //return goToTargetRelative(VecPosition(0,-1,0), 0); // Right
    //return goToTargetRelative(VecPosition(1,1,0), 0); // Diagonal22
    //return goToTargetRelative(VecPosition(0,1,0), 90); // Turn counter-clockwise
    //return goToTargetRelative(VecPdosition(0,-1,0), -90); // Turn clockwise
    //return goToTargetRelative(VecPosition(1,0,0), 15); // Circle

    // Walk to the ball
    
    //return goToTarget(ball);


    // Turn in place to face ball
    /*double distance, angle;
    getTargetDistanceAndAngle(ball, distance, angle);
    if (abs(angle) > 10) {
      return goToTargetRelative(VecPosition(), angle);
    } else {
      return SKILL_STAND;
    }*/

    // Walk to ball while always facing forward
    //return goToTargetRelative(worldModel->g2l(ball), -worldModel->getMyAngDeg());

    // Dribble ball toward opponent's goal
    //return kickBall(KICK_DRIBBLE, VecPosition(HALF_FIELD_X, 0, 0));

    // Kick ball toward opponent's goal
    //return kickBall(KICK_FORWARD, VecPosition(HALF_FIELD_X, 0, 0)); // Basic kick
    //return kickBall(KICK_IK, VecPosition(HALF_FIELD_X, 0, 0)); // IK kick

    // Just stand in place
    //return SKILL_STAND;
}


