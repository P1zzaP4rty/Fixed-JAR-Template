// #include "vex.h"
// #include "cstdlib"

// using namespace std;

// motor_group left_Drive = motor_group(left_front_drive, left_middle_drive, left_rear_drive);
// motor_group right_Drive = motor_group(right_front_drive, right_middle_drive, right_rear_drive);

int drive_code(){
//   left_Drive.setMaxTorque(100, pct);
//   right_Drive.setMaxTorque(100, pct);
// while (1){
//   double A3 = Controller1.Axis3.position();
//   double A4 = Controller1.Axis4.position();
//   double A1 = Controller1.Axis1.position();
//   double deadband = 10;
//   double powerL;
//   double powerR;

//   if (fabs(A3)<deadband){
//     A3=0;                
//   }
//   if (fabs(A4)<deadband){
//     A4=0;
//   }
//   if (fabs(A1)<deadband){
//     A1=0;
//   }

//     powerL = (A3*fabs(A3)/100+A4*fabs(A4)/100)*0.12;
//     powerR = (A3*fabs(A3)/100-A4*fabs(A4)/100)*0.12;

//   double maxInputMag = fmax(fabs(powerL),fabs(powerR));
//   if (maxInputMag > 12){
//     powerL /=maxInputMag;
//     powerR /=maxInputMag;

//     powerL *=12;
//     powerR *=12;
//   }        

//   left_Drive.spin(fwd, powerL, volt);
//   right_Drive.spin(fwd, powerR, volt);
//   task::sleep(33);
// }
return 0;
}
