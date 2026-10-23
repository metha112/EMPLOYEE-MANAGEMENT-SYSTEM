#ifndef MENU_H
#define MENU_H
/* shared data (menu.c eke define wenawa) */
extern char departments[4][100];
extern int  selectedDept;

int  selectDepartment(void);
void showDepartmentMenuForAttendance(void);
void showAttendanceMenu(void);
void showMainMenu();
void showEmployeeMenu();
void clearScreen();
#endif