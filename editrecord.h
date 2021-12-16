#ifdef _WIN64
#define DIR_SEPARATOR "\\"
#else
#define DIR_SEPARATOR "/"
#endif
#define EXTEN ".txt"
#include "dlist2.c"
#ifdef _WIN64
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void editrecord()

{
    FILE *fpte, *f1;
    char line[80], sou[50];
    f1 = fopen("source.txt", "r");

    struct record customer;
    char choice;
    char time[10], filename[14];

    int num;
    int count = 0;
    do

    {
    fgets(line, 80, f1);
    sscanf(line, "%s", sou);
    fclose(f1);

    system(CLEAR);


    printf("\n\n\t\t:::::::::::::::::::::::::::::::\n");

    printf("\t\t\t: EDIT RECORDS :");

    printf("\n\t\t:::::::::::::::::::::::::::::::\n\n");

    printf("HERE YOUR ALL RECORDS LIST.\n");
    listFile(sou);

        printf("\n\tENTER THE FILENAME:");

        fflush(stdin);
        scanf(" %[^\n]s", filename);
        strcat(sou, DIR_SEPARATOR);
        strcat(sou, filename);
        strcat(sou, EXTEN);
        printf("\n\tENTER TIME:[hh:mm]:");

        scanf(" %[^\n]s", time);
        system(CLEAR);

        fpte = fopen(sou, "rb+");

        if (fpte == NULL)

        {

            printf("\nRECORD DOES NOT EXISTS:");

            printf("\nPRESS ANY KEY TO GO BACK");

            std::cin.get();

            return;
        }

        while (fread(&customer, sizeof(customer), 1, fpte) == 1)

        {

            if (strcmp(customer.time, time) == 0)

            {

                printf("\nYOUR OLD RECORD WAS AS:");

                printf("\nTIME: %s", customer.time);

                printf("\nMEETING WITH: %s", customer.name);

                printf("\nMEETING AT: %s", customer.place);

                printf("\nDURATION: %s", customer.duration);

                printf("\nNOTE: %s", customer.note);

                printf("\n\n\t\tWHAT WOULD YOU LIKE TO EDIT..");

                printf("\n1.TIME.");

                printf("\n2.MEETING PERSON.");

                printf("\n3.MEETING PLACE.");

                printf("\n4.DURATION.");

                printf("\n5.NOTE.");

                printf("\n6.WHOLE RECORD.");

                printf("\n7.GO BACK TO MAIN MENU.");

                do

                {

                    printf("\n\tENTER YOUR CHOICE:");

                    fflush(stdin);

                    scanf("%d", &num);

                    fflush(stdin);

                    switch (num)

                    {

                    case 1:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nNEW TIME:[hh:mm]:");
                        scanf(" %[^\n]s", customer.time);
                        break;

                    case 2:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nNEW MEETING PERSON:");
                        scanf(" %[^\n]s", customer.name);
                        break;

                    case 3:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nNEW MEETING PLACE:");
                        scanf(" %[^\n]s", customer.place);
                        break;

                    case 4:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nDURATION:");
                        scanf(" %[^\n]s", customer.duration);
                        break;
                    case 5:
                        printf("ENTER THE NEW DATA:");

                        printf("\nNOTE:");
                        scanf(" %[^\n]s", customer.note);
                        break;

                    case 6:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nNEW TIME:[hh:mm]:");
                        scanf(" %[^\n]s", customer.time);

                        printf("\nNEW MEETING PERSON:");
                        scanf(" %[^\n]s", customer.name);

                        printf("\nNEW MEETING PLACE:");
                        scanf(" %[^\n]s", customer.place);

                        printf("\nDURATION:");
                        scanf(" %[^\n]s", customer.duration);

                        printf("\nNOTE:");
                        scanf(" %[^\n]s", customer.note);

                        break;
                    case 7:
                        printf("\nPRESS ANY KEY TO GO BACK...\n");

                        std::cin.get();
                        return;
                        break;
                    }


                } while (num <  1 || num > 8);

                fseek(fpte, -sizeof(customer), SEEK_CUR);

                fwrite(&customer, sizeof(customer), 1, fpte);

                fseek(fpte, -sizeof(customer), SEEK_CUR);

                fread(&customer, sizeof(customer), 1, fpte);

                choice = 5;

                break;
            }
        }

        if (choice == 5)

        {

            system(CLEAR);

            printf("\n\t\tEDITING COMPLETED...\n");

            printf("--------------------\n");

            printf("THE NEW RECORD IS:\n");

            printf("--------------------\n");

            printf("\nTIME: %s", customer.time);

            printf("\nMEETING WITH: %s", customer.name);

            printf("\nMEETING AT: %s", customer.place);

            printf("\nDURATION: %s", customer.duration);

            printf("\nNOTE: %s", customer.note);

         //   fclose(fpte);

            count++;
        }

        else

        {

            printf("\nTHE RECORD DOES NOT EXIST::\n");

            printf("\nWOULD YOU LIKE TO TRY AGAIN...(Y/N)");
            fflush(stdin);
            choice = getchar();
        }



    if (count == 1)
        {
        printf("\n%d FILE IS EDITED...\n", count);
        fflush(stdin);
        choice = getchar();
        }

    else if (count > 1)
        {
        printf("\n%d FILES ARE EDITED..\n", count);

        fflush(stdin);
        choice = getchar();
        }

    else
    {
        printf("\nNO FILES EDITED...\n");
    }


    printf("\n\n\tWOULD YOU LIKE TO EDIT ANOTHER RECORD.(Y/N): ");

    fflush(stdin);
    choice = getchar();

    } while(choice == 'Y' || choice == 'y');

    fclose(fpte);

    return;

}
