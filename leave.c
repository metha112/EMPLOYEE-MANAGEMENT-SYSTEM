#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leave.h"
#include "menu.h"


void apply_leave(){clearScreen(); printf("Mark Attendance\nPress Enter..."); getchar();}
void view_leave(){ clearScreen(); printf("View Attendance\nPress Enter..."); getchar(); }
void approve_leave(){ clearScreen(); printf("Search Attendance\nPress Enter..."); getchar(); }
void reject_leave(){ clearScreen(); printf("Monthly Report\nPress Enter..."); getchar(); }