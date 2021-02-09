#include <stdio.h>
#include <stdlib.h>
#include <time.h>

    // compiled on onlinegdb.com online compiler
   int firstMenu, selection, secondSelection, capacity, revenues, salary, i=0, personalNumber;
   int busNo=0;
   char busModel[50]={0};
   char voyageNo[50]={0};
   char startingCity[50]={0};
   char destinationCity[50]={0};
   char out;

//Main Function
int main()
{
    opening:
    printf("\nMAIN MENU\n1. Company Login\n2. Customer Login\n3. Exit\n\nPlease make a choice:->");
    scanf("%d",&firstMenu);
    switch (firstMenu){
    case 1: CompanyLogin();
    case 2: CustomerLogin();
    case 3: Out();
    break;
    default: printf("You made a wrong choice!!!"); goto opening;
    }
}

//Company Login Function
void CompanyLogin()
{
    companylogin:
    printf("\n\nCOMPANY LOGIN\n1. Add Bus\n2. Add Voyage Information\n3. Voyage/Seat Information\n4. Return to Upper Menu\n\n");
    printf("Please make a choice: ");
    scanf("%d",&selection);
    switch(selection){
    case 1:
        addbus:
          busNo++;
          i++;
             printf("\nBus Adding Section:\n");
                printf("\nPlease enter capacity: "); //Short way bus if less than 30, long way bus if more than 30
                scanf("%d", &capacity);
                if(capacity<=30) personalNumber=2;
                else if(capacity>30) personalNumber=3;
                printf("\nPlease enter bus model: "); //string expression, such as T403
                scanf("%s", &busModel[i]);
                printf("\nBus No: %d\n", busNo);
                printf("\nNumber of Personal %d:\n", personalNumber); //2 personal can work on the short-distance bus, 3 personal can work on the long-distance bus.
                printf("Bus successfully added..\n");
                busModel[i]++;
                goto companylogin;
    case 2:
        addvoyageinformation:
         printf("\nAdding Voyage Information Section:\n");
         //Generate hexadecimal 6-digit number
         int length=6;
    char str[] = "0123456789ABCDEF";
    srand((unsigned int) time(0) + getpid());
        printf("Voyage No: ");
    while(length--) {
        putchar((str[rand() % 16]));
        srand(rand());
    }
    printf("\n");

        printf("Bus No: %d\n", busNo);
        int a,b,c,d,e;
        voyagehourselection:
        printf("Departure hour:");
        scanf("%d", &a);
        b=a/1000;
        c=(a-(b*1000))/100;
        d=(a-(b*1000+c*100))/10;
        e=(a-(b*1000+c*100+d*10));
        //Check if the time matches the last two digits of the student number 172803018
        if(10*d+e!=18) {
            printf("Voyage can't happen at this hour!\n");
        goto voyagehourselection;
        }
        else if(a>2318){
            printf("Invalid time zone!\n");
        goto voyagehourselection;
        }
        if(personalNumber==2 && capacity<=30){
            printf("This vehicle can not travel long, please select time again.\n");
            goto voyagehourselection;
        }
        else if(c==0 && b==2){
        printf("Time of arrival: %i18\n", (0*b)+(c+5));
        }
        else if(b==2 && c==1){
            printf("Time of arrival: %i18\n", (0*b)+(c+1));
        }
        else if(b==2 && c==2){
            printf("Time of arrival: %i18\n", (0*b)+(c+1));
        }
        else if(b==2 && c==3){
            printf("Time of arrival: %i18\n", (0*b)+(c+1));
        }
        else if(b==0 || b==1 || c==5 || c==6 || c==7 || c==8 || c==9){
            printf("Time of arrival: %i18\n", (10*b)+(c+5));
        }
        else printf("Time of arrival: %i18\n", (10*b+5*c));
        i++;
        printf("Start City of Voyage: ");
        scanf("%s", &startingCity[i]);

        printf("Destination City of Voyage: ");
        scanf("%s", &destinationCity[i]);

        printf("Total Revenue Required: ");
        scanf("%d", &revenues);

        salary= revenues/capacity;
        printf("Salary Per Customer: %d ", salary);
        goto companylogin;

    case 3:
        voyageseatinformation:
            goto companylogin;
         printf("\nVoyage/Seat Information Section:\n");
        printf("Revenue: %d\n", revenues);
        printf("Start City of Voyage: %s\n", startingCity[i]);
        printf("Destination City of Voyage: %s\n", destinationCity[i]);
        printf("Bus No: %d",busNo);
        goto companylogin;

    case 4: main(); break;
    default: printf("\nPlease enter a value between 1-4.\n"); goto companylogin;
    }

}

//Customer Login Function
void CustomerLogin()
{
    customerlogin:
      printf("\n\nCUSTOMER LOGIN\n1. List Voyages\n 2. Book a Voyage\n3. Return to Upper Menu\n4. Show Reservation\n");
      printf("Please make a choice: ");
      scanf("%d",&secondSelection);
      switch(secondSelection){
        case 1: printf("\nList Voyages Section\n"); goto customerlogin;
        case 2: printf("\nBook a Voyage Section\n"); goto customerlogin;
        case 3: main(); break;
        case 4: printf("\nShow Reservation Section\n"); goto customerlogin;
        default: printf("\nPlease enter a value between 1-4.\n"); goto customerlogin;
      }
}

//Exit Function
void Out()
{
    printf("Press N / n to stay, Y / y to exit.: \n");
    scanf("%s",&out);
    out:
        switch(out)
        {
        case 'y':
        case 'Y': printf("You have successfully logged out.."); exit(EXIT_SUCCESS);
        break;
        case 'n':
        case 'N': printf("Continue where you left off..\n");
        main();
        break;
        default: printf("Enter Y / y or N / n...\n"); goto out;
        }
    return 0;
}
