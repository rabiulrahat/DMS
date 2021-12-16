#ifdef _WIN64
#define DIR_SEPARATOR "\\"
#else
#define DIR_SEPARATOR "/"
#endif
#define EXTEN ".txt"
#include "dirflists.c"
#ifdef _WIN64
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void viewrecord()

{

    FILE *fpte, *f1;
    char line[80], sou[50];
    f1 = fopen("source.txt", "r");

    fgets(line, 80, f1);
    sscanf(line, "%s", sou);
    fclose(f1);
    struct record customer;

    char choice;
    char time[10], filename[14];

    int ch;

    printf("\n\n\t\t::::::::::::::::::::::::::::::\n");

    printf("\t\t\t: VIEWING MENU :");

    printf("\n\t\t::::::::::::::::::::::::::::::\n\n");

    do

    {
        char line[80], sou[50];
        f1 = fopen("source.txt", "r");

        fgets(line, 80, f1);
        sscanf(line, "%s", sou);
        fclose(f1);
        system(CLEAR);
        printf("HERE YOUR ALL RECORDS LIST.\n");
       listFiles(sou);

        printf("\n\tENTER THE RECORD NAME: ");

        scanf(" %[^\n]s", filename);

        strcat(sou, DIR_SEPARATOR);
        strcat(sou, filename);
        strcat(sou, EXTEN);
        fpte = fopen(sou, "rb");

        if (fpte == NULL)

        {

            puts("\nTHE RECORD DOES NOT EXIST...\n");

            printf("PRESS ANY KEY TO EXIT...");

            std::cin.get();

            return;
        }


        printf("\n\tHOW WOULD YOU LIKE TO VIEW:\n");

        printf("\n\t1.WHOLE RECORD.");

        printf("\n\t2.RECORD OF FIX TIME.");

        printf("\n\t\tENTER YOUR CHOICE:");

        scanf("%d", &ch);

        switch (ch)

        {

        case 1:
            system(CLEAR);
            printf("\nTHE WHOLE RECORD FOR %s IS:", filename);

            while (fread(&customer, sizeof(customer), 1, fpte) == 1)

            {

                printf("\n");

                printf("\nTIME: %s", customer.time);

                printf("\nMEETING WITH: %s", customer.name);

                printf("\nMEETING AT: %s", customer.place);

                printf("\nDURATION: %s", customer.duration);

                printf("\nNOTE: %s", customer.note);

                printf("\n");
            }
            printf("\n\n\tPRESS ANY KEY TO EXIT...");

            std::cin.get();

            break;

        case 2:
            system(CLEAR);
            fflush(stdin);

            printf("\nENTER TIME:[hh:mm]: ");

            scanf(" %[^\n]s", time);

            while (fread(&customer, sizeof(customer), 1, fpte) == 1)

            {

                if (strcmp(customer.time, time) == 0)

                {

                    printf("\nYOUR RECORD IS:");

                    printf("\nTIME: %s", customer.time);

                    printf("\nMEETING WITH: %s", customer.name);

                    printf("\nMEETING AT: %s", customer.place);

                    printf("\nDURATION: %s", customer.duration);

                    printf("\nNOTE: %s", customer.note);

                }
                    printf("\n\n\tPRESS ANY KEY TO EXIT...");

                    std::cin.get();

                    break;
            }

        }

        fflush(stdin);
        printf("\n\nWOULD YOU LIKE TO CONTINUE VIEWING...(Y/N):");


        choice = getchar();

    } while (choice == 'Y' || choice == 'y');

    fclose(fpte);

    return;
}
