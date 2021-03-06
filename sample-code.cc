/**
 * CMA-ES, Covariance Matrix Adaptation Evolution Strategy
 * Copyright (c) 2014 Inria
 * Author: Emmanuel Benazera <emmanuel.benazera@lri.fr>
 *
 * This file is part of libcmaes.
 *
 * libcmaes is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libcmaes is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with libcmaes.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "cmaes.h"
#include <iostream>
 #include <mutex>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace libcmaes;
using namespace std;

#define NPARAMS 153



string parameters[NPARAMS] = 
{
"utwalk_max_step_size_angle",
"utwalk_max_step_size_x",
"utwalk_max_step_size_y",
"utwalk_shift_amount",
"utwalk_walk_height",
"utwalk_step_height",
"utwalk_fraction_still",
"utwalk_fraction_on_ground",
"utwalk_fraction_moving",
"utwalk_fraction_in_air",
"utwalk_phase_length",
"utwalk_default_com_pos_x",
"utwalk_pid_step_size_x",
"utwalk_pid_step_size_y",
"utwalk_pid_step_size_rot",
"utwalk_max_normal_com_error",
"utwalk_max_acceptable_com_error",
"utwalk_fwd_offset",
"utwalk_fwd_offset_factor",
"utwalk_swing_ankle_offset",
"utwalk_pid_tilt",
"utwalk_pid_roll",
"utwalk_pid_com_x",
"utwalk_pid_com_y",
"utwalk_pid_com_z",
"utwalk_pid_arm_x",
"utwalk_pid_arm_y",
"utwalk_balance_hip_pitch",
"utwalk_balance_knee_pitch",
"utwalk_balance_hip_roll",
"utwalk_balance_ankle_roll",
"utwalk_toe_const_offset",
"utwalk_toe_amplitude",
"utwalk_toe_phase_offset",
"utwalk_ankle_const_offset",
"utwalk_ankle_amplitude",
"utwalk_ankle_phase_offset",
"getup_parms_stateDownInitialWait",
"getup_parms_stateDown3A1",
"getup_parms_stateDown3L3",
"getup_parms_stateDown3MinTime",
"getup_parms_stateDown5L1",
"getup_parms_stateDown5MinTime",
"getup_parms_stateDown7L1",
"getup_parms_stateDown7L3",
"getup_parms_stateDown7MinTime",
"getup_parms_stateDown10MinTime",
"getup_parms_stateUpInitialWait",
"getup_parms_stateUp3A1",
"getup_parms_stateUp3A2",
"getup_parms_stateUp3A4",
"getup_parms_stateUp3L3",
"getup_parms_stateUp3MinTime",
"getup_parms_stateUp5L3",
"getup_parms_stateUp5MinTime",
"getup_parms_stateUp7L1",
"getup_parms_stateUp7MinTime",
"getup_parms_stateUp9A1",
"getup_parms_stateUp9L1",
"getup_parms_stateUp9L4",
"getup_parms_stateUp9L5",
"getup_parms_stateUp9L6",
"getup_parms_stateUp9MinTime",
"getup_parms_stateUp11A1",
"getup_parms_stateUp11L1",
"getup_parms_stateUp11L5",
"getup_parms_stateUp11MinTime",
"getup_parms_stateUp13A1",
"getup_parms_stateUp13L1",
"getup_parms_stateUp13L3",
"getup_parms_stateUp13L4",
"getup_parms_stateUp13L5",
"getup_parms_stateUp13MinTime",
"getup_parms_stateUp15MinTime",
"kick_p1",
"kick_p2",
"kick_p3",
"kick_p4",
"kick_p5",
"kick_p6",
"kick_p7",
"kick_p8",
"kick_p9",
"kick_p11",
"kick_p12",
"kick_p13",
"kick_p14",
"kick_xoffset",
"kick_yoffset",
"kick_scale1",
"kick_scale2",
"kick_scale3",
"kick_max_displacement_right",
"kick_max_displacement_left",
"kick_max_displacement_top",
"kick_max_displacement_bottom",
"kick_cw_angle_thresh",
"kick_ccw_angle_thresh",
"kick_angle",
"kick_ik_0_xoffset",
"kick_ik_0_yoffset",
"kick_ik_0_x0",
"kick_ik_0_y0",
"kick_ik_0_z0",
"kick_ik_0_x1",
"kick_ik_0_y1",
"kick_ik_0_z1",
"kick_ik_0_x2",
"kick_ik_0_y2",
"kick_ik_0_z2",
"kick_ik_0_x3",
"kick_ik_0_y3",
"kick_ik_0_z3",
"kick_ik_0_a0",
"kick_ik_0_b0",
"kick_ik_0_c0",
"kick_ik_0_a1",
"kick_ik_0_b1",
"kick_ik_0_c1",
"kick_ik_0_a2",
"kick_ik_0_b2",
"kick_ik_0_c2",
"kick_ik_0_a3",
"kick_ik_0_b3",
"kick_ik_0_c3",
"kick_ik_0_wait",
"kick_ik_0_scale",
"kick_ik_0_off3_0",
"kick_ik_0_off4_0",
"kick_ik_0_off5_0",
"kick_ik_0_off3_1",
"kick_ik_0_off4_1",
"kick_ik_0_off5_1",
"kick_ik_0_off3_2",
"kick_ik_0_off4_2",
"kick_ik_0_off5_2",
"kick_ik_0_max_displacement_right",
"kick_ik_0_max_displacement_left",
"kick_ik_0_max_displacement_top",
"kick_ik_0_max_displacement_bottom",
"kick_ik_0_cw_angle_thresh",
"kick_ik_0_ccw_angle_thresh",
"kick_ik_0_angle",
"kick_gen_approach_turnDist",
"kick_gen_approach_buff",
"kick_gen_approach_estVelCorrection",
"kick_gen_approach_navBallDist",
"kick_gen_approach_navBallCollision",
"kick_gen_approach_navBallAngle",
"kick_gen_approach_maxDecelX",
"kick_gen_approach_maxDecelY",
"drib_coll_thresh",
"drib_target"
};

string values[NPARAMS] = 
{
"1.22",
"50",
"40",
"20",
"175",
"20",
"0.2",
"0.2",
"0.6",
"0.6",
"0.38",
"0.0",
"0.03",
"0.03",
"0.03",
"7.5",
"12.5",
"2.5",
"0.5",
"-0.087266463",
"0.15",
"0.2",
"1.0",
"1.0",
"0.0",
"0.0",
"0.0",
"0",
"0",
"0",
"0",
"0",
"0",
"0",
"0",
"0",
"0",
"0.5",
"30.0",
"110.0",
"0.04",
"-45.0",
"0.9",
"-25.0",
"60.0",
"0.3",
"0.8",
"0.5",
"-120.0",
"35.0",
"60.0",
"15.0",
"0.2",
"110.0",
"0.04",
"-35.0",
"0.2",
"30.0",
"-80.0",
"-60.0",
"-70.0",
"-40.0",
"0.2",
"30.0",
"-60.0",
"-80.0",
"0.4",
"-90.0",
"-30.0",
"30.0",
"-10.0",
"-10.0",
"0.04",
"0.6",
"-19.557993714343954",
"-116.33168663169225",
"-46.494524238808935",
"114.34191464255687",
"8.009471678103255",
"76.4847755838874",
"-31.637611686590287",
"24.56402804393056",
"22.447324354397427",
"12.412258757088757",
"2.9108536812695958",
"-4.139927460294173",
"2.5793464431419877",
"-0.18758631052473101",
"-0.08133614974057074",
"5.295086273579072",
"1.9096575829831766",
"0.7896144070184505",
"0.01",
"0.01",
"0.01",
"0.01",
"2",
"2",
"0",
"-0.18184725746865413",
"-0.007990019340567048",
"0.09855534262963274",
"0.04897226608420107",
"0.06004895070570849",
"-0.13267256199213984",
"0.15055665409986765",
"0.3048635084962904",
"-0.075918848350498",
"0.010843367764323163",
"-0.03228058151402973",
"0.3514121512894722",
"-0.0915098467211551",
"0.2932735025335922",
"-2.0713675817098482",
"4.168030311789961",
"-0.17712625804502546",
"-2.3258316746549554",
"9.39335694003392",
"-5.4878969788579175",
"2.254184572289742",
"0.014404161833793745",
"-16.34929405684522",
"-0.1703513663364682",
"77.12670393386878",
"-21.212384580007893",
"0.06679452466769868",
"2.434596016520202",
"6.8002354818317885",
"23.957167469656504",
"-7.433399813693172",
"-16.624470935986754",
"20.351676522363075",
"-25.63678390762887",
"-50.00201321637502",
"-39.33897746613399",
"54.047464010320134",
"0.025",
"0.025",
"0.025",
"0.025",
"2",
"2",
"0",
"0.25",
"0.05",
"0.05",
"0.5",
"0.25",
"40",
"0.5",
"0.5",
"0.34",
"0.18"
};

int indicesChanging[] = {0, 1, 2, 3, 4, 5, 7, 8, 9, 10, 12, 13}; // 12 params

mutex f_mtx;
FitFunc fsphere = [](const double *x, const int N)
{
  lock_guard<mutex> lck(f_mtx);
  ofstream myfile;
  myfile.open ("paramfiles/defaultParams.txt");
  // myfile << "Writing this to a file.\n";

  int newParamindex = 0;
  for (int i = 0; i < NPARAMS; i++)
  {
    if (i < 14 and i != 6 and i != 11)
    {
      myfile << parameters[i] << "\t" << x[newParamindex] << '\n';
      newParamindex ++;
    }
    else
    {
      myfile << parameters[i] << "\t" << values[i] << '\n';
    }
  }

myfile.close();

system("python keyControl.py");

ifstream myReadFile;
myReadFile.open("end_out");
// outFile.open("out_file",ios::out);
 // char output[100];
 double output;
 if (myReadFile.is_open()) {
  while (!myReadFile.eof()){
    myReadFile >> output;
    // outFile >> output;
    // cout<<output;
 }
}
// outFile.flush();
myReadFile.close();
// outFile.close();

ofstream outFile;
outFile.open ("out_file.txt", ios_base::app);
outFile << output << endl;
outFile.close();

return output;

  // double val = 0.0;
  // for (int i=0;i<N;i++)
  //   val += x[i]*x[i];
  // return val;
};

int main(int argc, char *argv[])
{
  int dim = 12; // problem dimensions.

  double lbounds[dim],ubounds[dim]; // arrays for lower and upper parameter bounds, respectively                
  
  std::vector<double> x(dim);

  x[0] = 1.22;
  x[1] = 50;
  x[2] = 40;
  x[3] = 20;
  x[4] = 175;
  x[5] = 20;
  x[6] = 0.2;
  x[7] = 0.6;
  x[8] = 0.6;
  x[9] = 0.38;
  x[10] = 0.03;
  x[11] = 0.03;

  for (int i=0;i<dim;i++)
  {
    lbounds[i] = x[i]/2;
    ubounds[i] = x[i]*3/2;
  }



  double sigma = 0.1;
  //int lambda = 100; // offsprings at each generation.
  // CMAParameters<> cmaparams(x0,sigma);
  GenoPheno<pwqBoundStrategy> gp(lbounds,ubounds,dim); // genotype / phenotype transform associated to bounds.  
  CMAParameters<GenoPheno<pwqBoundStrategy>> cmaparams(dim,&x.front(),sigma,-1,0,gp); // -1 for automatically \
  cmaparams.set_mt_feval(false);
  //cmaparams._algo = BIPOP_CMAES;
  cmaparams.set_algo(aCMAES);
  CMASolutions cmasols = cmaes<>(fsphere,cmaparams);
  std::cout << "best solution: " << cmasols << std::endl;
  std::cout << "optimization took " << cmasols.elapsed_time() / 1000.0 << " seconds\n";
  return cmasols.run_status();
}
