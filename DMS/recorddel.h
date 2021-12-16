#ifdef _WIN64
#define DIR_SEPARATOR "\\"
#else
#define DIR_SEPARATOR "/"
#endif
#define EXTEN ".txt"

void deleterecord()

{
    FILE *fp, *f1,*fptr;




    struct record file;

    char filename[30];
    char time[10];

    int choice;
    char another;

    do
    {


        do

        {
        char line[80], sou[50];
        f1 = fopen("source.txt", "r");
        system(CLEAR);
        fgets(line, 80, f1);
        sscanf(line, "%s", sou);
        fclose(f1);
        printf("\n\n\t\t:::::::::::::::::::::::::\n");

        printf("\t\t    : DELETE RECORDS :");

        printf("\n\t\t:::::::::::::::::::::::::\n\n");
        printf("HERE YOUR ALL RECORDS LIST.\n");
        listFile(sou);


        printf("\n\n\tHOW WOULD YOU LIKE TO DELETE.");

        printf("\n\n\t#DELETE WHOLE RECORD\t\t\t[1]");

        printf("\n\t#DELETE A PARTICULAR RECORD BY TIME\t[2]");

            printf("\n\t\tENTER YOU CHOICE:");

            scanf("%d", &choice);

            switch (choice)

            {

            case 1:

                printf("\n\tENTER THE FILE NAME:");

                fflush(stdin);
                scanf(" %[^\n]s", filename);
                strcat(sou, DIR_SEPARATOR);
                strcat(sou, filename);
                strcat(sou, EXTEN);

                fp = fopen(sou, "rb");

              if (fp == NULL)

                {

                    printf("\nTHE FILE DOES NOT EXISTS");

                    std::cin.get();
                    break;
                fclose(fp);
                }
                remove(sou);
                printf("\nDELETED SUCCESSFULLY...");
                std::cin.get();
                break;

            case 2:

                printf("\n\tENTER THE FILE NAME:");

                fflush(stdin);
                scanf(" %[^\n]s", filename);
                strcat(sou, DIR_SEPARATOR);
                strcat(sou, filename);
                strcat(sou, EXTEN);

                fp = fopen(sou, "rb");

                if (fp == NULL)

                {

                    printf("\nTHE FILE DOES NOT EXISTS");

                    printf("\nPRESS ANY KEY TO GO BACK.");

                    std::cin.get();
                    break;
                }

                fptr = fopen("temp", "wb");

                if (fptr == NULL)

                {

                    printf("\nSYSTEM ERROR");

                    printf("\nPRESS ANY KEY TO GO BACK");

                    std::cin.get();
                }

                printf("\n\tENTER THE TIME OF RECORD TO BE DELETED:[hh:mm]:");

                fflush(stdin);
                scanf(" %[^\n]s", time);

                while (fread(&file, sizeof(file), 1, fp) == 1)

                {

                    if (strcmp(file.time, time) != 0)

                        fwrite(&file, sizeof(file), 1, fptr);
                }

                fclose(fp);

                fclose(fptr);

                remove(sou);

                rename("temp", sou);

                printf("\nDELETED SUCCESSFULLY...");

                break;

            default:

                printf("\n\tYOU ENTERED WRONG CHOICE");

                break;
            }
        } while (choice < 1 || choice > 2);

    } while (another == 'Y' || another == 'y');

    printf("\n\n\tPRESS ANY KEY TO EXIT...");

    std::cin.get();
    return;
}

