#include "PID.h"
#include <assert.h>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID()
: p_error(0)
, i_error(0)
, d_error(0)
, Kp(0)
, Ki(0)
, Kd(0)
, prev_cte(0)
{
}

PID::~PID()
{
}

void PID::Init(double Kp_, double Ki_, double Kd_)
{
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;

  p_error = 0;
  d_error = 0;
  i_error = 0;

  prev_cte = 0;

}

void PID::UpdateError(double cte)
{
  
  p_error = cte;
  i_error += cte;
  d_error = cte - prev_cte;

  prev_cte = cte;
}

double PID::TotalError()
{
  return -Kp * p_error - Ki * i_error - Kd * d_error;
}