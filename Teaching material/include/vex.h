/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       vex.h                                                     */
/*    Author:       Vex Robotics                                              */
/*    Created:      1 Feb 2019                                                */
/*    Description:  Default header for V5 projects                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
//

#pragma once
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#include "v5.h"
#include "v5_vcs.h"

#include "robot-config.h"
#include "JAR-Template/odom.h"
#include "JAR-Template/drive.h"
#include "JAR-Template/util.h"
#include "JAR-Template/PID.h"
#include "autons.h"

#include "..\src\files.h"

#define forever(stuff)                                                          \
  while(1){                                                                     \
    stuff                                                                       \
    task::sleep(33);                                                             \
  }      

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))                                                       \

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)

// #define driveType(driveType)  /*coast, hold, brake*/                           \
//   do {                                                                         \
//     /*Coast let the chassic spin gradually to a stop.       */                 \
//     /*Brake will cause the chassic to come to immediate stop*/                 \
//     /*Hold will cause the chassic to come to an immediate   */                 \
//     /*stop, and returns it to its stopped position if moved */                 \
//     left_front_drive.setStopping(driveType);                                   \
//     left_middle_drive.setStopping(driveType);                                  \
//     left_rear_drive.setStopping(driveType);                                    \
//     right_front_drive.setStopping(driveType);                                  \
//     right_middle_drive.setStopping(driveType);                                 \
//     right_rear_drive.setStopping(driveType);                                   \
//   } while (0) 