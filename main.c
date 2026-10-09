#include <stdio.h>
#include "menu.h"

int main() {
    int choice;
    
    while (1) {
        showMainInterface();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n  Employee Management - Coming Soon!\n");
                printf("  Press Enter to continue...");
                getchar(); getchar();
                break;
            case 2:
                printf("\n  Attendance Management - Coming Soon!\n");
                printf("  Press Enter to continue...");
                getchar(); getchar();
                break;
            case 3:
                printf("\n  Leave Management - Coming Soon!\n");
                printf("  Press Enter to continue...");
                getchar(); getchar();
                break;
            case 4:
                printf("\n  Salary Management - Coming Soon!\n");
                printf("  Press Enter to continue...");
                getchar(); getchar();
                break;
            case 5:
                printf("\n  Reports - Coming Soon!\n");
                printf("  Press Enter to continue...");
                getchar(); getchar();
                break;
            case 0:
                clearScreen();
                printf("\n\n  Thank you! Exiting...\n\n");
                return 0;
            default:
                printf("\n  Invalid choice! Press Enter...");
                getchar(); getchar();
        }
    }
}