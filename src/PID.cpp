#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  Kp_ = Kp;
  Ki_ = Ki;
  Kd_ = Kd;
  p_error = 0.;
  i_error = 0.;
  d_error = 0.;
}

void PID::UpdateError(double cte) {
  i_error += cte;
  d_error = cte - p_error;
  // Update last since d_error relies on previous cte value
  p_error = cte;
}

double PID::TotalError() {
  return -Kp_ * p_error - Kd_ * d_error - Ki_ * i_error;
}

