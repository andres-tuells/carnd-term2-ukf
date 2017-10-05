#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  DONE:
    * Calculate the RMSE here.
  */
   VectorXd rmse(4);
  rmse << 0,0,0,0;

  //validate input data
  if(estimations.size() != ground_truth.size() || estimations.size() == 0){
    std::cout << "Invalid estimation or ground_truth data" << std::endl;
    return rmse;
  }

  for(unsigned int i=0; i < estimations.size(); ++i){

    VectorXd residual = estimations[i] - ground_truth[i];

    residual = residual.array()*residual.array();
    rmse += residual;
  }

  //mean
  rmse = rmse/estimations.size();

  //calculate the squared root
  rmse = rmse.array().sqrt();

  if (rmse[0]>1){
  	cout << "RMSE too big" << endl;
  }
  cout << "RMSE:" << rmse << endl;
  return rmse;

  
}