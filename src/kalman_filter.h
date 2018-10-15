#ifndef KALMAN_FILTER_H_
#define KALMAN_FILTER_H_
#include "Eigen/Dense"

class KalmanFilter {
private:
  void UpdateWithY(const Eigen::VectorXd &y);
public:

  // state vector
  Eigen::VectorXd x_;

  // state covariance matrix
  Eigen::MatrixXd P_;

  // state transition matrix
  Eigen::MatrixXd F_;

  // process covariance matrix
  Eigen::MatrixXd Q_;

  // measurement matrix
  Eigen::MatrixXd H_;

  // measurement covariance matrix
  Eigen::MatrixXd R_;

  KalmanFilter();

  virtual ~KalmanFilter();

  void Init(Eigen::VectorXd &x_in, Eigen::MatrixXd &P_in, Eigen::MatrixXd &F_in,
      Eigen::MatrixXd &H_in, Eigen::MatrixXd &R_in, Eigen::MatrixXd &Q_in);

  /**
   * Prediction Predicts the state and the state covariance
   * using the process model
  */
  void Predict();

  
  //Updates the state by using standard Kalman Filter equations
  void Update(const Eigen::VectorXd &z);

  // Updates the state by using Extended Kalman Filter equations
  void UpdateEKF(const Eigen::VectorXd &z);

};

#endif
