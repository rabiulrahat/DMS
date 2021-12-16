#include <bits/stdc++.h>
#include <cstdlib>
#include <unistd.h>
#include <string.h>
#include "art.c"
#include "struct.h"
#include "login.h"
#include "addrecord.h"
#include "viewrecord.h"
#include "editrecord.h"
#include "recorddel.h"
#ifdef _WIN64
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

int main()

{
    art();
    login();
    std::system(CLEAR);

    time_t t;

    time(&t);

    int ch;

    printf("\n\n\t:::::::::::::::::::::::::\n");

    printf("\t:DIARY MANAGEMENT SYSTEM:\n");

    printf("\t:::::::::::::::::::::::::");

    while (1)

    {

        printf("\n\n\t\t:MAIN MENU:");

        printf("\n\n\tPress <1> To ADD RECORD\t");

        printf("\n\tPress <2> To VIEW RECORDS\t");

        printf("\n\tPress <3> To EDIT RECORDS\t");

        printf("\n\tPress <4> To DELETE RECORD\t");

        printf("\n\tPress <5> To EXIT\t\t");

        printf("\n\n\tCurrent date and time : %s", ctime(&t));

        printf("\n\n\tENTER YOUR CHOICE:");

        scanf("%d", &ch);

        switch (ch)

        {

        case 1:
            system(CLEAR);
            addrecord();

            break;

        case 2:
            system(CLEAR);
            viewrecord();

            break;

        case 3:
            system(CLEAR);
            editrecord();

            break;

        case 4:
            system(CLEAR);
            deleterecord();

            break;

        case 5:

            printf("\n\n\t\tTHANK YOU FOR USING THE SOFTWARE ");

            std::cin.get();
            system(CLEAR);

            exit(0);

        default:

            printf("\nYOU ENTERED WRONG CHOICE..");

            printf("\nPRESS ANY KEY TO TRY AGAIN");

            std::cin.get();

            break;
        }

        system(CLEAR);
    }

    return 0;
}
void addrecord();
void viewrecord();
void editrecord();
void deleterecord();
