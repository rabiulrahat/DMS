#include "cfind.c"
#include "elist.c"

void addrecord()

{


    FILE *fp,*f1;
    char line[80], sou[50];

    char another = 'Y';
    char time[10];

    struct record e;

    char filename[15];

    int choice;
    f1 = fopen("source.txt", "r");
    fgets(line, 80, f1);
    sscanf(line, "%s", sou);
    fclose(f1);

    system(CLEAR);

    do
    {

    printf("\n\n\t\t:::::::::::::::::::::::::::\n");

    printf("\t\t: WELCOME TO THE ADD MENU :");

    printf("\n\t\t:::::::::::::::::::::::::::\n\n");
    printf("HERE YOUR ALL RECORDS LIST.\n");

    elistFile(sou);

    dir();
    system(CLEAR);
    char line1[80], p [100];
    fp = fopen("log.txt", "r");
    fgets(line1,80,fp);
    sscanf(line1,"%s",p);

    fp = fopen(p, "ab+");

        choice = 0;

        fflush(stdin);
    printf("\t\t   : Welcome to write :\n");
    printf("\n\t\t:::::::::::::::::::::::::::\n\n");
    printf("\n[Note: you have to remember the time,it will use if you are going to others option,if you are not able to remember it,just view the records,then you will it]\n\n");
    printf("\n\tENTER TIME:[hh:mm]:");

        scanf(" %[^\n]s", time);

        rewind(fp);

        while (fread(&e, sizeof(e), 1, fp) == 1)

        {

            if (strcmp(e.time, time) == 0)

            {

                printf("\n\tTHE RECORD ALREADY EXISTS.\n");

                choice = 1;

            }
        }

        if (choice == 0)

        {

            strcpy(e.time, time);

            printf("\tENTER MEETING PERSON NAME:");

            fflush(stdin);
            scanf(" %[^\n]s", e.name);


            fflush(stdin);

            printf("\tENTER PLACE NAME:");
            scanf(" %[^\n]s", e.place);


            fflush(stdin);

            printf("\tENTER TIME DURATION:");

            scanf(" %[^\n]s", e.duration);

            fflush(stdin);

            printf("\tNOTE: ");

            scanf(" %[^\n]s",e.note);


            fwrite(&e, sizeof(e), 1, fp);

            printf("\nYOUR RECORD IS ADDED SUCCESSFULLY...\n");

            fflush(stdin);
            another = getchar();
        }

        printf("\n\tDO YOU WANT TO ADD ANOTHER RECORD...(Y/N): ");
        fflush(stdin);
        another = getchar();
        system(CLEAR);
    } while (another == 'Y' || another == 'y');
        fclose(fp);

         printf("\n\n\tPRESS ANY KEY TO EXIT...");
            std::cin.get();

     system("break");

}
