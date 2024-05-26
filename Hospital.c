#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void clrscr(void)
{
    system("cls()");
}
void emp(void);
void menu(void);
void pat(void);
void inv(void);
struct address
{
    int hno;
    char street[40];
    char city[40];
    char state[40];
};
struct patient
{
    char name[40];
    char fname[40];
    int age;
    char bg[3];
    char gender;
    char regn[10];
    struct address a;
    char ph[10];
    char disease[60];
    char doc_name[40];
    char history[200];
    char date[10];
    char treatment[40];
    char med[40];
};
struct staff
{
    char name[40];
    char fname[40];
    int age;
    char bg[3];
    char gender;
    char uid[10];
    struct address b;
    char ph[10];
    double salary;
    char desig[40];
};
struct inventory
{
    int sno;
    char name[30];
    char dop[20];
    int qnty;
    float price;
    float amount;
};//check
void menu()
{
    char choice;
    printf("\t\t*************************************************");
    printf("\n\t\t  *** WELCOME TO HOSPITAL MANAGEMENT SYSTEM ***");
    printf("\n\t\t*************************************************");
    printf("\n\n\n\n\n\n\n");
    printf("\t\t1.PATIENT");
    printf("\n\t\t2.STAFF");
    printf("\n\t\t3.INVENTORY");
    printf("\n\t\t0.EXIT");
    printf("\n\n\tEnter your choice: ");
    fflush(stdin);
    choice=getche();
    switch(choice)
        {
            case '1':
                pat();
                break;
            case '2':
                emp();
                break;
            case '3':
                inv();
                break;
            case '0':
                exit(1);
        }
}//check
void main()
{
    system("COLOR F5");

    int password = 12345;
    int enteredPass = 0;

    printf("Enter password: ");
    scanf("%d", &enteredPass);

    if( enteredPass == password ){
        clrscr();
        menu();
    }else{
        printf("Wrong Pass!");
    }

}
void pat()
{
    FILE *fp,*ft;
    char ch,another,z;
    char reg[20],pname[40];
    int i=0;
    long int recsize;
    struct patient p;
    fp=fopen("pat.DAT","rb+");
    if(fp==NULL)
        {
            fp=fopen("pat.DAT","wb+");
            if(fp==NULL)
                {
                    puts("\nSorry!! Cannot open file");
                    exit(1);
                }
        }
    recsize=sizeof(p);
    while(1)
        {
            clrscr();
            printf("\n\n\t\t\tPATIENT");
            printf("\n\t\t1.Enter a New Entry");
            printf("\n\t\t2.Modify Existing");
            printf("\n\t\t3.Search an Entry");
            printf("\n\t\t4.Listing of records");
            printf("\n\t\t5.Delete an Entry");
            printf("\n\t\t6.Main Menu");
            printf("\n\n\t\tEnter your choice here: ");
            fflush(stdin);
            ch=getche();
            switch(ch)
                {
                    case '1':
                    clrscr();
                    fseek(fp,0,SEEK_END);
                    another='Y';
                    while(another=='Y'||another=='y')
                        {
                            w:
                            printf("\n\n\nEnter Registration Number: ");
                            scanf("%s",reg);
                            rewind(fp);
                            while(fread(&p,recsize,1,fp)==1)
                                {
                                    if(strcmp(p.regn,reg)==0)
                                        {
                                            i=1;
                                            printf("\n\t\tTHIS REGISTRATION NUMBER ALREADY EXISTS. ENTER ANOTHER ONE");
                                            goto w;
                                        }
                                }
                            if(i==0||fread(&p,recsize,1,fp)==0)
                                {
                                    fseek (fp,0,SEEK_END);
                                    strcpy(p.regn,reg);
                                    fflush(stdin);
                                    printf("\nEnter the name of the patient: ");
                                    gets(p.name);
                                    printf("\nEnter the name of the Guardian: ");
                                    gets(p.fname);
                                    printf("\nEnter the gender of the patient(M.male or F.female): ");
                                    scanf("%c",&p.gender);
                                    fflush(stdin);
                                    printf("\nEnter the Blood group of the patient: ");
                                    scanf("%s",p.bg);
                                    fflush(stdin);
                                    printf("\nEnter the age of the patient: ");
                                    scanf("%d",&p.age);
                                    printf("\nEnter the address of the patient:\n");
                                    printf("\n\tEnter the house number: ");
                                    scanf("%d",&p.a.hno);
                                    fflush(stdin);
                                    printf("\n\tEnter the street/colony: ");
                                    scanf("%s",p.a.street);
                                    printf("\n\tEnter the city: ");
                                    scanf("%s",p.a.city);
                                    printf("\n\tEnter the state: ");
                                    scanf("%s",p.a.state);
                                    printf("\nEnter the phone number of the patient: ");
                                    scanf("%s",p.ph);
                                    fflush(stdin);
                                    printf("\nEnter the Disease or problem for which he/she wants treatment: ");
                                    gets(p.disease);
                                    printf("\nEnter the name of the Doctor to which he/she being referred: ");
                                    gets(p.doc_name);
                                    printf("\nEnter the history, if any, related to treatment of the patient(If yes then write 'Y' if NO then write 'N'): ");
                                    scanf("%c",&z);
                                    if(z=='N'||z=='n')
                                        {
                                            goto out;
                                        }
                                    else
                                        {
                                            fflush(stdin);
                                            printf("\nHistory:");
                                            gets(p.history);
                                            fflush(stdin);
                                            printf("\nEnter the date of treatment:");
                                            scanf("%s",p.date);
                                            printf("\nTreatment Given:");
                                            scanf("%s",p.treatment);
                                            printf("\nMedicine Prescribed:");
                                            scanf("%s",p.med);
                                        }
                                    fwrite(&p,recsize,1,fp);                                                                               out: printf("\n----------------------------------------------------");
                                    printf("\nWant to add entry of the another Patient(Y/N): ");
                                    fflush(stdin);
                                    another=getche();
                                    }
                                }
                            break;
                        case '2':
                            clrscr();
                            another='Y';
                            while(another=='Y'||another=='y')
                                {
                                    printf("\nEnter the Registration number of the patient to modify: ");
                                    scanf("%s",reg);
                                    rewind(fp);
                                    while(fread(&p,recsize,1,fp)==1)
                                        {
                                            if(strcmp(p.regn,reg)==0)
                                                {
                                                    fflush(stdin);
                                                    printf("\nEnter the new name of the patient: ");
                                                    gets(p.name);
                                                    printf("\nEnter the new name of the Guardian: ");
                                                    gets(p.fname);
                                                    printf("\nEnter the new Blood group of the patient: ");
                                                    scanf("%s",p.bg);
                                                    printf("\nEnter the new age of the patient: ");
                                                    scanf("%d",&p.age);
                                                    printf("\nEnter the new address of the patient:\n");
                                                    printf("\n\tEnter the house number: ");
                                                    scanf("%d",&p.a.hno);
                                                    fflush(stdin);
                                                    printf("\n\tEnter the street/colony: ");
                                                    scanf("%s",p.a.street);
                                                    printf("\n\tEnter the city: ");
                                                    scanf("%s",p.a.city);
                                                    printf("\n\tEnter the state: ");
                                                    scanf("%s",p.a.state);
                                                    printf("\nEnter the new phone number of the patient: ");
                                                    scanf("%s",p.ph);
                                                    fflush(stdin);
                                                    printf("enter the date of treatment given: ");
                                                    gets(p.date);
                                                    printf("\nEnter the detail of treatment given: ");
                                                    gets(p.treatment);
                                                    printf("\nEnter the medicines prescribed: ");
                                                    gets(p.med);
                                                    fseek(fp,-recsize,SEEK_CUR);
                                                    fwrite(&p,recsize,1,fp);
                                                    break;
                                                }
                                            }
                                        printf("\n----------------------------------------------------");
                                        printf("\nModify another Record(Y/N): ");
                                        fflush(stdin);
                                        another=getche();
                                    }
                                break;
                            case '3':
                                clrscr();
                                another='Y';
                                while(another=='Y'||another=='y')
                                    {
                                        printf("\nEnter name to search: ");
                                        gets(pname);
                                        rewind(fp);
                                        while(fread(&p,recsize,1,fp)==1)
                                            {
                                                if(strcmp(p.name,pname)==0)
                                                    {
                                                        printf("\nRegistration Number of the Patient : ");
                                                        puts(p.regn);
                                                        printf("\nName of the Patient : ");
                                                        puts(p.name);
                                                        printf("\nName of the Guardian : ");
                                                        puts(p.fname);
                                                        printf("\nAge : %d",p.age);
                                                        printf("\nGender : %c",p.gender);
                                                        printf("\nBlood group: %s",p.bg);
                                                        printf("\nAddress  : %d,%s,%s,%s",p.a.hno,p.a.street,p.a.city,p.a.state);
                                                        printf("\nphone number : +91-%s",p.ph);
                                                        printf("\nDisease : %s",p.disease);
                                                        printf("\nEarlier History : ");
                                                        puts(p.history);
                                                        printf("\nDetails of treatment given and medicine prescribed:");
                                                        printf("\nDATE\t\tTREATMENT GIVEN\t\tMEDICINE PRESCRIBED\n");
                                                        printf("%s\t\t %s\t\t %s\n",p.date,p.treatment,p.med);
                                                        printf("\nName of the Doctor : ");
                                                        puts(p.doc_name);
                                                    }
                                                }//check
                                            printf("\n----------------------------------------------------");
                                            printf("\nSearch another Entry(Y/N): ");
                                            fflush(stdin);
                                            another=getche();
                                        }
                                    break;
                                case '4':
                                    clrscr();
                                    rewind(fp);
                                    while(fread(&p,recsize,1,fp)==1)
                                        {
                                            printf("\nRegistration Number of the Patient : ");
                                            puts(p.regn);
                                            printf("\nName of the Patient : ");
                                            puts(p.name);
                                            printf("\nName of the Guardian : ");
                                            puts(p.fname);
                                            printf("\nAge : %d",p.age);
                                            printf("\nGender : %c",p.gender);
                                            printf("\nBlood group: %s",p.bg);
                                            printf("\nAddress  : %d,%s,%s,%s",p.a.hno,p.a.street,p.a.city,p.a.state);
                                            printf("\nphone number : +91-%s",p.ph);
                                            printf("\nDisease : %s",p.disease);
                                            printf("\nEarlier History : ");
                                            puts(p.history);
                                            printf("\nDetails of treatment given and medicine prescribed:");
                                            printf("\nDATE\t\t TREATMENT GIVEN\t\t\t MEDICINE PRESCRIBED\n");
                                            printf("%s\t\t %s\t\t\t %s\n",p.date,p.treatment,p.med);
                                            printf("\nName of the Doctor : ");
                                            puts(p.doc_name);
                                            printf("\n----------------------------------------------------\n");
                                        }
                                    getch();
                                break;
                            case '5':
                                clrscr();
                                another='Y';
                                while(another=='Y'||another=='y')
                                    {
                                        printf("\nEnter the Registration number of the Patient to be deleted: ");
                                        scanf("%s",reg);
                                        ft=fopen("temp.txt","wb+");
                                        rewind(fp);
                                        while(fread(&p,recsize,1,fp)==1)
                                            {
                                                if(strcmp(p.regn,reg)!=0)
                                                fwrite(&p,recsize,1,ft);
                                                else
                                                printf("\nThe Record has been Deleted Successfully.");
                                            }
                                        fclose(fp);
                                        fclose(ft);
                                        remove("pat.DAT");
                                        rename("temp.DAT","pat.DAT");
                                        fp=fopen("pat.DAT","rb+");
                                        printf("\nDelete another record?(Y/N): ");
                                        fflush(stdin);
                                        another=getche();
                                    }
                                break;
                            case '6':
                                {
                                    fclose(fp);
                                    clrscr();
                                    menu();
                                }
                            break;
                  }
                }
}//check
void emp()
{
    FILE *fs,*fx;
    char more,c;
    char id[20],s_name[40];
    int iF=0;
    long int recsize1;
    struct staff s;
    fs=fopen("emp.DAT","rb+");
    if(fs==NULL)
        {
            fs=fopen("emp.DAT","wb+");
            if(fs==NULL)
                {
                    puts("\nSorry!! Cannot open file");
                    exit(1);
                }
        }
    recsize1=sizeof(s);
    while(1)
        {
            clrscr();
            printf("\n\t\t\tEMPLOYEE");
            printf("\n\t\t1.Add an Entry");
            printf("\n\t\t2.Modify Existing One");
            printf("\n\t\t3.Search an Entry");
            printf("\n\t\t4.Listing of all records");
            printf("\n\t\t5.Delete an Entry");
            printf("\n\t\t6.Main Menu");
            printf("\n\n\t\tEnter your choice here: ");
            fflush(stdin);
            c=getche();
            switch(c)
                {
                    case '1':
                    clrscr();
                    fseek(fs,0,SEEK_END);
                    more='Y';
                    while(more=='Y'||more=='y')
                        {
                            u:
                            printf("\n\n\nEnter the UID of the Employee: ");
                            scanf("%s",id);
                            rewind(fs);
                            while(fread(&s,recsize1,1,fs)==1)
                                {
                                    if(strcmp(s.uid,id)==0)
                                        {
                                            iF=1;
                                            printf("\n\t\tTHIS UID ALREADY EXISTS. ENTER ANOTHER ONE");
                                            goto u;
              #include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void clrscr(void)
{
    system("cls()");
}
void emp(void);
void menu(void);
void pat(void);
void inv(void);
struct address
{
    int hno;
    char street[40];
    char city[40];
    char state[40];
};
struct patient
{
    char name[40];
    char fname[40];
    int age;
    char bg[3];
    char gender;
    char regn[10];
    struct address a;
    char ph[10];
    char disease[60];
    char doc_name[40];
    char history[200];
    char date[10];
    char treatment[40];
    char med[40];
};
struct staff
{
    char name[40];
    char fname[40];
    int age;
    char bg[3];
    char gender;
    char uid[10];
    struct address b;
    char ph[10];
    double salary;
    char desig[40];
};
struct inventory
{
    int sno;
    char name[30];
    char dop[20];
    int qnty;
    float price;
    float amount;
};//check
void menu()
{
    char choice;
    printf("\t\t*************************************************");
    printf("\n\t\t  *** WELCOME TO HOSPITAL MANAGEMENT SYSTEM ***");
    printf("\n\t\t*************************************************");
    printf("\n\n\n\n\n\n\n");
    printf("\t\t1.PATIENT");
    printf("\n\t\t2.STAFF");
    printf("\n\t\t3.INVENTORY");
    printf("\n\t\t0.EXIT");
    printf("\n\n\tEnter your choice: ");
    fflush(stdin);
    choice=getche();
    switch(choice)
        {
            case '1':
                pat();
                break;
            case '2':
                emp();
                break;
            case '3':
                inv();
                break;
            case '0':
                exit(1);
        }
}//check
void main()
{
    system("COLOR F5");

    int password = 12345;
    int enteredPass = 0;

    printf("Enter password: ");
    scanf("%d", &enteredPass);

    if( enteredPass == password ){
        clrscr();
        menu();
    }else{
        printf("Wrong Pass!");
    }

}
void pat()
{
    FILE *fp,*ft;
    char ch,another,z;
    char reg[20],pname[40];
    int i=0;
    long int recsize;
    struct patient p;
    fp=fopen("pat.DAT","rb+");
    if(fp==NULL)
        {
            fp=fopen("pat.DAT","wb+");
            if(fp==NULL)
                {
                    puts("\nSorry!! Cannot open file");
                    exit(1);
                }
        }
    recsize=sizeof(p);
    while(1)
        {
            clrscr();
            printf("\n\n\t\t\tPATIENT");
            printf("\n\t\t1.Enter a New Entry");
            printf("\n\t\t2.Modify Existing");
            printf("\n\t\t3.Search an Entry");
            printf("\n\t\t4.Listing of records");
            printf("\n\t\t5.Delete an Entry");
            printf("\n\t\t6.Main Menu");
            printf("\n\n\t\tEnter your choice here: ");
            fflush(stdin);
            ch=getche();
            switch(ch)
                {
                    case '1':
                    clrscr();
                    fseek(fp,0,SEEK_END);
                    another='Y';
                    while(another=='Y'||another=='y')
                        {
                            w:
                            printf("\n\n\nEnter Registration Number: ");
                            scanf("%s",reg);
                            rewind(fp);
                            while(fread(&p,recsize,1,fp)==1)
                                {
                                    if(strcmp(p.regn,reg)==0)
                                        {
                                            i=1;
                                            printf("\n\t\tTHIS REGISTRATION NUMBER ALREADY EXISTS. ENTER ANOTHER ONE");
                                            goto w;
                                        }
                                }
                            if(i==0||fread(&p,recsize,1,fp)==0)
                                {
                                    fseek (fp,0,SEEK_END);
                                    strcpy(p.regn,reg);
                                    fflush(stdin);
                                    printf("\nEnter the name of the patient: ");
                                    gets(p.name);
                                    printf("\nEnter the name of the Guardian: ");
                                    gets(p.fname);
                                    printf("\nEnter the gender of the patient(M.male or F.female): ");
                                    scanf("%c",&p.gender);
                                    fflush(stdin);
                                    printf("\nEnter the Blood group of the patient: ");
                                    scanf("%s",p.bg);
                                    fflush(stdin);
                                    printf("\nEnter the age of the patient: ");
                                    scanf("%d",&p.age);
                                    printf("\nEnter the address of the patient:\n");
                                    printf("\n\tEnter the house number: ");
                                    scanf("%d",&p.a.hno);
                                    fflush(stdin);
                                    printf("\n\tEnter the street/colony: ");
                                    scanf("%s",p.a.street);
                                    printf("\n\tEnter the city: ");
                                    scanf("%s",p.a.city);
                                    printf("\n\tEnter the state: ");
                                    scanf("%s",p.a.state);
                                    printf("\nEnter the phone number of the patient: ");
                                    scanf("%s",p.ph);
                                    fflush(stdin);
                                    printf("\nEnter the Disease or problem for which he/she wants treatment: ");
                                    gets(p.disease);
                                    printf("\nEnter the name of the Doctor to which he/she being referred: ");
                                    gets(p.doc_name);
                                    printf("\nEnter the history, if any, related to treatment of the patient(If yes then write 'Y' if NO then write 'N'): ");
                                    scanf("%c",&z);
                                    if(z=='N'||z=='n')
                                        {
                                            goto out;
                                        }
                                    else
                                        {
                                            fflush(stdin);
                                            printf("\nHistory:");
                                            gets(p.history);
                                            fflush(stdin);
                                            printf("\nEnter the date of treatment:");
                                            scanf("%s",p.date);
                                            printf("\nTreatment Given:");
                                            scanf("%s",p.treatment);
                                            printf("\nMedicine Prescribed:");
                                            scanf("%s",p.med);
                                        }
                                    fwrite(&p,recsize,1,fp);                                                                               out: printf("\n----------------------------------------------------");
                                    printf("\nWant to add entry of the another Patient(Y/N): ");
                                    fflush(stdin);
                                    another=getche();
                                    }
                                }
                            break;
                        case '2':
                            clrscr();
                            another='Y';
                            while(another=='Y'||another=='y')
                                {
                                    printf("\nEnter the Registration number of the patient to modify: ");
                                    scanf("%s",reg);
                                    rewind(fp);
                                    while(fread(&p,recsize,1,fp)==1)
                                        {
                                            if(strcmp(p.regn,reg)==0)
                                                {
                                                    fflush(stdin);
                                                    printf("\nEnter the new name of the patient: ");
                                                    gets(p.name);
                                                    printf("\nEnter the new name of the Guardian: ");
                                                    gets(p.fname);
                                                    printf("\nEnter the new Blood group of the patient: ");
                                                    scanf("%s",p.bg);
                                                    printf("\nEnter the new age of the patient: ");
                                                    scanf("%d",&p.age);
                                                    printf("\nEnter the new address of the patient:\n");
                                                    printf("\n\tEnter the house number: ");
                                                    scanf("%d",&p.a.hno);
                                                    fflush(stdin);
                                                    printf("\n\tEnter the street/colony: ");
                                                    scanf("%s",p.a.street);
                                                    printf("\n\tEnter the city: ");
                                                    scanf("%s",p.a.city);
                                                    printf("\n\tEnter the state: ");
                                                    scanf("%s",p.a.state);
                                                    printf("\nEnter the new phone number of the patient: ");
                                                    scanf("%s",p.ph);
                                                    fflush(stdin);
                                                    printf("enter the date of treatment given: ");
                                                    gets(p.date);
                                                    printf("\nEnter the detail of treatment given: ");
                                                    gets(p.treatment);
                                                    printf("\nEnter the medicines prescribed: ");
                                                    gets(p.med);
                                                    fseek(fp,-recsize,SEEK_CUR);
                                                    fwrite(&p,recsize,1,fp);
                                                    break;
                                                }
                                            }
                                        printf("\n----------------------------------------------------");
                                        printf("\nModify another Record(Y/N): ");
                                        fflush(stdin);
                                        another=getche();
                                    }
                                break;
                            case '3':
                                clrscr();
                                another='Y';
                                while(another=='Y'||another=='y')
                                    {
                                        printf("\nEnter name to search: ");
                                        gets(pname);
                                        rewind(fp);
                                        while(fread(&p,recsize,1,fp)==1)
                                            {
                                                if(strcmp(p.name,pname)==0)
                                                    {
                                                        printf("\nRegistration Number of the Patient : ");
                                                        puts(p.regn);
                                                        printf("\nName of the Patient : ");
                                                        puts(p.name);
                                                        printf("\nName of the Guardian : ");
                                                        puts(p.fname);
                                                        printf("\nAge : %d",p.age);
                                                        printf("\nGender : %c",p.gender);
                                                        printf("\nBlood group: %s",p.bg);
                                                        printf("\nAddress  : %d,%s,%s,%s",p.a.hno,p.a.street,p.a.city,p.a.state);
                                                        printf("\nphone number : +91-%s",p.ph);
                                                        printf("\nDisease : %s",p.disease);
                                                        printf("\nEarlier History : ");
                                                        puts(p.history);
                                                        printf("\nDetails of treatment given and medicine prescribed:");
                                                        printf("\nDATE\t\tTREATMENT GIVEN\t\tMEDICINE PRESCRIBED\n");
                                                        printf("%s\t\t %s\t\t %s\n",p.date,p.treatment,p.med);
                                                        printf("\nName of the Doctor : ");
                                                        puts(p.doc_name);
                                                    }
                                                }//check
                                            printf("\n----------------------------------------------------");
                                            printf("\nSearch another Entry(Y/N): ");
                                            fflush(stdin);
                                            another=getche();
                                        }
                                    break;
                                case '4':
                                    clrscr();
                                    rewind(fp);
                                    while(fread(&p,recsize,1,fp)==1)
                                        {
                                            printf("\nRegistration Number of the Patient : ");
                                            puts(p.regn);
                                            printf("\nName of the Patient : ");
                                            puts(p.name);
                                            printf("\nName of the Guardian : ");
                                            puts(p.fname);
                                            printf("\nAge : %d",p.age);
                                            printf("\nGender : %c",p.gender);
                                            printf("\nBlood group: %s",p.bg);
                                            printf("\nAddress  : %d,%s,%s,%s",p.a.hno,p.a.street,p.a.city,p.a.state);
                                            printf("\nphone number : +91-%s",p.ph);
                                            printf("\nDisease : %s",p.disease);
                                            printf("\nEarlier History : ");
                                            puts(p.history);
                                            printf("\nDetails of treatment given and medicine prescribed:");
                                            printf("\nDATE\t\t TREATMENT GIVEN\t\t\t MEDICINE PRESCRIBED\n");
                                            printf("%s\t\t %s\t\t\t %s\n",p.date,p.treatment,p.med);
                                            printf("\nName of the Doctor : ");
                                            puts(p.doc_name);
                                            printf("\n----------------------------------------------------\n");
                                        }
                                    getch();
                                break;
                            case '5':
                                clrscr();
                                another='Y';
                                while(another=='Y'||another=='y')
                                    {
                                        printf("\nEnter the Registration number of the Patient to be deleted: ");
                                        scanf("%s",reg);
                                        ft=fopen("temp.txt","wb+");
                                        rewind(fp);
                                        while(fread(&p,recsize,1,fp)==1)
                                            {
                                                if(strcmp(p.regn,reg)!=0)
                                                fwrite(&p,recsize,1,ft);
                                                else
                                                printf("\nThe Record has been Deleted Successfully.");
                                            }
                                        fclose(fp);
                                        fclose(ft);
                                        remove("pat.DAT");
                                        rename("temp.DAT","pat.DAT");
                                        fp=fopen("pat.DAT","rb+");
                                        printf("\nDelete another record?(Y/N): ");
                                        fflush(stdin);
                                        another=getche();
                                    }
                                break;
                            case '6':
                                {
                                    fclose(fp);
                                    clrscr();
                                    menu();
                                }
                            break;
                  }
                }
}//check
void emp()
{
    FILE *fs,*fx;
    char more,c;
    char id[20],s_name[40];
    int iF=0;
    long int recsize1;
    struct staff s;
    fs=fopen("emp.DAT","rb+");
    if(fs==NULL)
        {
            fs=fopen("emp.DAT","wb+");
            if(fs==NULL)
                {
                    puts("\nSorry!! Cannot open file");
                    exit(1);
                }
        }
    recsize1=sizeof(s);
    while(1)
        {
            clrscr();
            printf("\n\t\t\tEMPLOYEE");
            printf("\n\t\t1.Add an Entry");
            printf("\n\t\t2.Modify Existing One");
            printf("\n\t\t3.Search an Entry");
            printf("\n\t\t4.Listing of all records");
            printf("\n\t\t5.Delete an Entry");
            printf("\n\t\t6.Main Menu");
            printf("\n\n\t\tEnter your choice here: ");
            fflush(stdin);
            c=getche();
            switch(c)
                {
                    case '1':
                    clrscr();
                    fseek(fs,0,SEEK_END);
                    more='Y';
                    while(more=='Y'||more=='y')
                        {
                            u:
                            printf("\n\n\nEnter the UID of the Employee: ");
                            scanf("%s",id);
                            rewind(fs);
                            while(fread(&s,recsize1,1,fs)==1)
                                {
                                    if(strcmp(s.uid,id)==0)
                                        {
                                            iF=1;
                                            printf("\n\t\tTHIS UID ALREADY EXISTS. ENTER ANOTHER ONE");
                                            goto u;
              
