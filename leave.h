#ifndef LEAVE_H
#define LEAVE_H

struct Leave
{
    
    char employeeID[50];
    char leaveType[20];
    int leavedays;
    char status[20];
};

void apply_leave();
void view_leave();
void approve_leave();
void reject_leave();
#endif