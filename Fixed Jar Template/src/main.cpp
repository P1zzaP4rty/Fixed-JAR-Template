#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;
competition Competition;

/*---------------------------------------------------------------------------*/
/*                             VEXcode Config                                */
/*                                                                           */
/*  Before you do anything else, start by configuring your motors and        */
/*  sensors. In VEXcode Pro V5, you can do this using the graphical          */
/*  configurer port icon at the top right. In the VSCode extension, you'll   */
/*  need to go to robot-config.cpp and robot-config.h and create the         */
/*  motors yourself by following the style shown. All motors must be         */
/*  properly reversed, meaning the drive should drive forward when all       */
/*  motors spin forward.                                                     */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your motors.                                     */
/*---------------------------------------------------------------------------*/

Drive chassis(

//Pick your drive setup from the list below:
//ZERO_TRACKER_NO_ODOM
//ZERO_TRACKER_ODOM
//TANK_ONE_FORWARD_ENCODER
//TANK_ONE_FORWARD_ROTATION
//TANK_ONE_SIDEWAYS_ENCODER
//TANK_ONE_SIDEWAYS_ROTATION
//TANK_TWO_ENCODER
//TANK_TWO_ROTATION
//HOLONOMIC_TWO_ENCODER
//HOLONOMIC_TWO_ROTATION

//Write it here:
ZERO_TRACKER_ODOM,

//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

//Left Motors:
motor_group(),

//Right Motors:
motor_group(),

//Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
PORT1,

//Input your wheel diameter. (4" omnis are actually closer to 4.125"):
4.125,

//External ratio, must be in decimal, in the format of input teeth/output teeth.
//If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
//If the motor drives the wheel directly, this value is 1:
1,

//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
//For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
360,

/*---------------------------------------------------------------------------*/
/*                                  PAUSE!                                   */
/*                                                                           */
/*  The rest of the drive constructor is for robots using POSITION TRACKING. */
/*  If you are not using position tracking, leave the rest of the values as  */
/*  they are.                                                                */
/*---------------------------------------------------------------------------*/

//If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

//FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
//LF:      //RF:    
PORT1,     -PORT2,

//LB:      //RB: 
PORT3,     -PORT4,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
PORT1,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
3.25,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
5.375,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
PORT11,

//Sideways tracker diameter (reverse to make the direction switch):
-2,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
5.5

);

//Configure the inertial sensor, specify the port number the same way setting up the template.
inertial Inertial = inertial (PORT1);

int current_auton_selection = 0;
bool auto_started = false;
bool driver_started = false;

void pre_auton() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  Inertial.calibrate();
  // driveType(brake);  


  while(!auto_started||!driver_started){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5,20, "Pre Auto X: %.1f Y: %.1f Heading: %.1f", chassis.get_X_position(), chassis.get_Y_position(), chassis.get_absolute_heading());
    if (auto_started||driver_started){
      break;
    }
    switch(current_auton_selection){
      case 0:
        Brain.Screen.printAt(330, 20, "Auto 1");
        break;
      case 1:
        Brain.Screen.printAt(330, 20, "Auto 2");
        break;
      case 2:
        Brain.Screen.printAt(330, 20, "Auto 3");
        break;
      case 3:
        Brain.Screen.printAt(330, 20, "Auto 4");
        break;
      case 4:
        Brain.Screen.printAt(330, 20, "Auto 5");
        break;
      case 5:
        Brain.Screen.printAt(330, 20, "Auto 6");
        break;
      case 6:
        Brain.Screen.printAt(330, 20, "Auton 7");
        break;
      case 7:
        Brain.Screen.printAt(330, 20, "Auton 8");
        break;
    }
    if(Brain.Screen.pressing()){
      while(Brain.Screen.pressing()) {}
      current_auton_selection ++;
    } else if (current_auton_selection == 8){
      current_auton_selection = 0;
    }
    task::sleep(100);
  }
}

void autonomous(void) {
  auto_started = true;
  switch(current_auton_selection){ 
    case 0:
      general_test();
      break;
    case 1:         
      general_test();
      break;
    case 2:
      general_test();
      break;
    case 3:
      general_test();
      break;
    case 4:
      general_test();
      break;
    case 5:
      general_test();
      break;
    case 6:
      general_test();
      break;
    case 7:
      general_test();
      break;
 }
}

void usercontrol(void) {
  driver_started = true;
  // driveType(coast);

    task task1 (drive_code);
    task task2 (pull_data);
  while (1) {

    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5,20, "Drive Control X: %.1f Y: %.1f Heading: %.1f", chassis.get_X_position(), chassis.get_Y_position(), chassis.get_absolute_heading());
    Brain.Screen.printAt(5, 40, "Linear :%.1f", chassis.get_ForwardTracker_position());
    wait(100, msec); // Sleep the task for a short amount of time to
  }
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
