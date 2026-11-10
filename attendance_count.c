#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "attendance_count.h"

#define BASE       "File_Manegement/"
#define ATT_FILE   BASE "attendance.txt"
#define COUNT_FILE BASE "attendance_count.txt"

#define MAX_EMP     1000
#define MAX_RECORDS 10000

static char ids[MAX_EMP][50];
static int  present[MAX_EMP];

static char seenId[MAX_RECORDS][50];
static char seenDate[MAX_RECORDS][15];

void update_attendance_count(void)
{
    FILE *in = fopen(ATT_FILE, "r");
    if (in == NULL) {
        printf("Cannot open %s : %s\n", ATT_FILE, strerror(errno));
        return;
    }

    int total = 0, seen = 0;
    char line[512];
    char id[50], name[100], dept[150], date[15], status[20], tm[10];

    while (fgets(line, sizeof(line), in)) {
        if (sscanf(line, "%49[^|]|%99[^|]|%149[^|]|%14[^|]|%19[^|]|%9[^\r\n]",
                   id, name, dept, date, status, tm) != 6)
            continue;

        
        int idx = -1;
        for (int i = 0; i < total; i++)
            if (strcmp(ids[i], id) == 0) { idx = i; break; }

        if (idx == -1) {
            if (total >= MAX_EMP) continue;
            strcpy(ids[total], id);
            present[total] = 0;
            idx = total++;
        }

        if (strcmp(status, "Present") != 0) continue;

        
        int dup = 0;
        for (int i = 0; i < seen; i++)
            if (strcmp(seenId[i], id) == 0 && strcmp(seenDate[i], date) == 0) { dup = 1; break; }
        if (dup) continue;

        present[idx]++;
        if (seen < MAX_RECORDS) {
            strcpy(seenId[seen], id);
            strcpy(seenDate[seen], date);
            seen++;
        }
    }
    fclose(in);

    FILE *out = fopen(COUNT_FILE, "w");
    if (out == NULL) {
        printf("Cannot write %s : %s\n", COUNT_FILE, strerror(errno));
        return;
    }
    for (int i = 0; i < total; i++)
        fprintf(out, "%s|%d\n", ids[i], present[i]);
    fclose(out);
}
