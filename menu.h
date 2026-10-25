#ifndef MENU_H
#define MENU_H

extern char departments[5][100];
extern int  selectedDept;
void login();
void showMainMenu();
void showEmployeeMenu();
void userPassword();
void showLeave();
int  selectDepartment(void);
void showDepartmentMenuForAttendance(void);
void showAttendanceMenu(void);
void clearScreen();
#endif