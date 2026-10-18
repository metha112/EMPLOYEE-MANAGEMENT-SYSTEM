#ifndef CONIO_COMPAT_H
#define CONIO_COMPAT_H

/*
 * conio.h for Ubuntu/Linux.
 * Windows wala nam original conio.h eka thamai use wenne.
 */

#ifdef _WIN32
    #include_next <conio.h>
#else
    #include <stdio.h>
    #include <termios.h>
    #include <unistd.h>

    /* Enter nathuwa key ekak read karanawa, screen eke pennanne na */
    static inline int getch(void){
        struct termios oldt, newt;
        int ch;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return ch;
    }

    /* Key eka screen eke pennanawa */
    static inline int getche(void){
        struct termios oldt, newt;
        int ch;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~ICANON;
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return ch;
    }
#endif

#endif