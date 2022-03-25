#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stock_farm{
char nume_medicament[30];
int cantitate;
int pret;
}stock;

void adaugare(stock *x, int n, int *verif)
{
    int alegere = 0,i;
    char sir[30];
    printf("Doresti sa adaugi un medicament in lista?\n");
    printf("1. Da\n");
    printf("2. Nu\n");

    do{
            scanf("%d", &alegere);
            if(alegere > 2 || alegere <= 0)
                printf("Optiunea este invalida. Introdu un alt numar\n");
    }while(alegere > 2 || alegere <= 0);

    if(alegere == 1)
        {
            printf("Completeaza datele despre medicament\n");
            printf("Scrie numele medicamentului\n");

            if(n < 1)
        {
            fflush(stdin);
            scanf("%[^\n]", &x[n].nume_medicament);
        }

        else{

                int gasit_la_cautare = 0;

            do{
                    fflush(stdin);
                    scanf("%[^\n]", &sir);
                    gasit_la_cautare = 0;

                    for (i = 1; i <= n; i++)
                    if(strcmp(x[i].nume_medicament, sir) == 0)
                    {
                        printf("Medicamentul '%s' exista deja in lista. Introdu un alt medicament\n", sir);
                        gasit_la_cautare ++;
                    }
            }while(gasit_la_cautare > 0);

            strcpy(x[n].nume_medicament, sir);

            printf("Introdu cantitatea\n");
            scanf("%d", &x[n].cantitate);
            printf("Introdu pretul\n");
            scanf("%d", &x[n].pret);
            system("cls");
            printf("Medicamentul a fost adaugat\n");
        }


        }
    else {
        system("cls");
        printf("Adaugarea a fost anulata\n");
        *verif = 1;
    }
}

void actualizare(stock *x, int n)
{
    int alegere1 = 0, alegere2 = 0, i, aux = 0;
    char sir[30];

    if(n == 0)
        {system("cls");
        printf("Nu exista medicamente in stock-ul farmaciei\n");}


    else{

    printf("Alege medicamentul pentru editarea informatiilor\n");
    for(i = 1; i <= n; i++)
                {
                    printf("%d.\n", i);
                    printf("Nume medicament: %s\n", x[i].nume_medicament);
                    printf("Cantitatea: %d\n", x[i].cantitate);
                    printf("Pretul: %d\n", x[i].pret);
                }

    printf("\n%d. Back\n\n", n + 1);

    do{
            scanf("%d", &alegere1);
            if(alegere1 > n + 1 || alegere1 <= 0)
                printf("Optiunea este invalida. Introdu un alt numar\n");
    }while(alegere1 > n + 1 || alegere1 <= 0);

    if(alegere1 == n + 1)
        system("cls");

    else {

    while(alegere2 != 4)
    {
        system("cls");

        printf("%d.\n", alegere1);
        printf("Nume medicament: %s\n", x[alegere1].nume_medicament);
        printf("Cantitatea: %d\n", x[alegere1].cantitate);
        printf("Pretul: %d\n", x[alegere1].pret);

       printf("Alegeti numarul optiunii\n");
        printf("1. Actualizarea numelui medicamentului\n");
        printf("2. Actualizarea cantitatii medicamentului\n");
        printf("3. Actualizarea pretului medicamentului\n");
        printf("4. Back\n");

        do{
            scanf("%d", &alegere2);
            if(alegere2 > 4 || alegere2 <= 0)
                printf("Optiunea este invalida. Introdu un alt numar conform meniului de mai sus\n");

    }while(alegere2 > 4 || alegere2 <= 0);

        if(alegere2 == 1)
        {
            printf("Introduceti numele medicamentului\n");

            int gasit_la_cautare = 0;

            do{
                    fflush(stdin);
                    scanf("%[^\n]", &sir);
                    gasit_la_cautare = 0;

                    for (i = 1; i <= n; i++)
                    if(strcmp(x[i].nume_medicament, sir) == 0)
                    {
                        printf("Medicamentul '%s' exista deja in lista. Introdu un alt medicament\n", sir);
                        gasit_la_cautare ++;
                    }
            }while(gasit_la_cautare > 0);

            strcpy(x[alegere1].nume_medicament, sir);

            system("cls");
            printf("Numele medicamentului a fost actualizat\n");
        }

        if(alegere2 == 2)
        {
            printf("Introduceti cantitatea medicamentului\n");
            scanf("%d", &aux);
            x[alegere1].cantitate = aux;
            system("cls");
            printf("Cantitatea medicamentului a fost actualizata\n");
        }

        if(alegere2 == 3)
        {
            printf("Introduceti pretul medicamentului\n");
            scanf("%d", &aux);
            x[alegere1].pret = aux;
            system("cls");
            printf("Pretul medicamentului a fost actualizat\n");
        }
    }

    system("cls");

    }
    }
}

void stergere(stock *x, int n, int *verif_stergere)
{
    int alegere1 = 0, i;

    printf("Alege ce medicament vrei sa stergi\n");

    for(i = 1; i <= n; i++)
                {
                    printf("%d.\n", i);
                    printf("Nume medicament: %s\n", x[i].nume_medicament);
                    printf("Cantitatea: %d\n", x[i].cantitate);
                    printf("Pretul: %d\n", x[i].pret);
                }

    printf("\n%d. Back\n\n", n + 1);

    do{
            scanf("%d", &alegere1);

            if(alegere1 > n + 1 || alegere1 <= 0)
                printf("Optiunea este invalida. Introdu un alt numar\n");

    }while(alegere1 > n + 1 || alegere1 <= 0);

    if(alegere1 == n + 1)
        {system("cls");
        *verif_stergere = 1;}

    else {

    for (i = alegere1; i < n; i++)
    {
        strcpy(x[i].nume_medicament, x[i+1].nume_medicament);
        x[i].cantitate = x[i+1].cantitate;
        x[i].pret = x[i+1].pret;
    }

    system("cls");
    printf("Medicamentul a fost sters\n");

    }
}

int stergere_totala()
{
    printf("Doresti sa stergi intreaga lista de medicamente?\n");
    printf("1. Da\n");
    printf("2. Nu\n");

    int alegere = 0;

    do{
            scanf("%d", &alegere);

            if(alegere > 2 || alegere <= 0)
                printf("Optiunea este invalida. Introdu un alt numar\n");

    }while(alegere > 2 || alegere <= 0);

    if(alegere == 1)
    {
        system("cls");
        printf("Lista de medicamente a fost stearsa\n");
        return 1;
    }

    else {
        system("cls");
        printf("Lista de medicamente NU a fost stearsa\n");
        return 0;
    }
}

void cautare(stock *x, int n)
{
    int i, alegere1 = 0;
    char sir[30];

    if(n == 0)
        {system("cls");
        printf("Nu exista medicamente in stock-ul farmaciei\n");}

    else {

    printf("Alege una din optiunile de mai jos\n");
    printf("1. Introducerea unui sir de cautare\n");
    printf("2. Back\n");

    do{
            scanf("%d", &alegere1);

            if(alegere1 > 2 || alegere1 <= 0)
                printf("Optiunea este invalida. Introdu un alt numar\n");

    }while(alegere1 > 2 || alegere1 <= 0);

    if(alegere1 == 2)
        system("cls");

    else {

    printf("Introdu sirul de cautare\n");
    fflush(stdin);
    scanf("%[^\n]", sir);
    system("cls");
    printf("Rezultatele cautarii:\n");

    int gasit_la_cautare = 0;

    for (i = 1; i <= n; i++)
        if(strstr(x[i].nume_medicament, sir))
        {
                    printf("%d.\n", i);
                    printf("Nume medicament: %s\n", x[i].nume_medicament);
                    printf("Cantitatea: %d\n", x[i].cantitate);
                    printf("Pretul: %d\n", x[i].pret);
                    gasit_la_cautare ++;
        }

        if(gasit_la_cautare == 0)
            printf("Nu a fost gasit medicamentul cautat\n");

    }
    }
}

void afisare(stock *x, int n)
{
    int alegere = 0, i, s = 0;

    system("cls");

    if(n == 0)
        {system("cls");
        printf("Nu exista medicamente in stock-ul farmaciei\n");}

    else {

    while(alegere != 3)
    {
        printf("\nAlegeti numarul optiunii\n");
        printf("1. Afisarea tuturor medicamentelor din farmacie\n");
        printf("2. Afisarea medicamentelor care au un stoc redus\n");
        printf("3. Back\n");

        do{
            scanf("%d", &alegere);

            if(alegere > 3 || alegere <= 0)
                printf("Optiunea este invalida. Introdu un alt numar\n");

    }while(alegere > 3 || alegere <= 0);

        int verif_existenta_elem = 0;

        if(alegere == 1)
        {
            verif_existenta_elem ++;
            system("cls");
            printf("Lista tuturor medicametelor:\n");
            //printf("Nume medicament  ||   Cantitatea  ||  Pretul\n");
            for(i = 1; i <= n; i++)
                {
                    printf("\n%d.\n", i);
                    printf("Nume medicament: %s\n", x[i].nume_medicament);
                    printf("Cantitatea: %d\n", x[i].cantitate);
                    printf("Pretul: %d\n", x[i].pret);
                }
        }

        if(alegere == 2)
        {
            for(i = 1; i <= n; i++)
                s = s + x[i].cantitate;

            system("cls");

            printf("Lista tuturor medicametelor cu un stoc redus:\n");

            for(i = 1; i <= n; i++)
                if(x[i].cantitate < s / n)
                {
                    verif_existenta_elem ++;
                    printf("\n%d.\n", i);
                    printf("Nume medicament: %s\n", x[i].nume_medicament);
                    printf("Cantitatea: %d\n", x[i].cantitate);
                    printf("Pretul: %d\n", x[i].pret);
                }
            s = 0;
        }

        if(verif_existenta_elem == 0 && alegere != 3)
        {
            system("cls");
            printf("Nu exista medicamente in stock-ul farmaciei pentru afisarea ceruta\n");
        }

    }

    system("cls");

    }
}

void ordonare(stock *x, int n)
{
    int alegere1 = 0, i, j, aux;
    char c[30];

    printf("\nCe fel de criteriu doresti sa alegi pentru ordonare?\n");
    printf("1. Ordonare lexicografica / alfabetica\n");
    printf("2. Ordonare crescatoare dupa cantitate\n");
    printf("3. Ordonare descrescatoare dupa cantitate\n");
    printf("4. Ordonare crescatoare dupa pret\n");
    printf("5. Ordonare descrescatoare dupa pret\n");
    printf("6. Back\n");

    do{
            scanf("%d", &alegere1);
            if(alegere1 > 6 || alegere1 <= 0)
                printf("Optiunea este invalida. Introdu un alt numar\n");
    }while(alegere1 > 6 || alegere1 <= 0);

    if(alegere1 == 6)
        {
            system("cls");
            printf("Ordonarea a fost anulata\n");
        }

    else if(alegere1 == 1)
    {
        for(i = 1; i < n; i++)
            for(j = i + 1; j <= n; j++)
            if(strcmp(x[i].nume_medicament, x[j].nume_medicament) > 0)
            {
                strcpy(c, x[i].nume_medicament);
                aux = x[i].cantitate;
                strcpy(x[i].nume_medicament, x[j].nume_medicament);
                strcpy(x[j].nume_medicament, c);
                x[i].cantitate = x[j].cantitate;
                x[j].cantitate = aux;
                aux = x[i].pret;
                x[i].pret = x[j].pret;
                x[j].pret = aux;
            }
        system("cls");
        printf("Lista a fost ordonata lexicografic\n");
    }

    else if(alegere1 == 2)
    {
        for(i = 1; i < n; i++)
            for(j = i + 1; j <= n; j++)
                if(x[i].cantitate > x[j].cantitate)
            {
                strcpy(c, x[i].nume_medicament);
                aux = x[i].cantitate;
                strcpy(x[i].nume_medicament, x[j].nume_medicament);
                strcpy(x[j].nume_medicament, c);
                x[i].cantitate = x[j].cantitate;
                x[j].cantitate = aux;
                aux = x[i].pret;
                x[i].pret = x[j].pret;
                x[j].pret = aux;
            }
        system("cls");
        printf("Lista a fost ordonata crescator dupa cantitate\n");
    }

    else if(alegere1 == 3)
    {
        for(i = 1; i < n; i++)
            for(j = i + 1; j <= n; j++)
                if(x[i].cantitate < x[j].cantitate)
            {
                strcpy(c, x[i].nume_medicament);
                aux = x[i].cantitate;
                strcpy(x[i].nume_medicament, x[j].nume_medicament);
                strcpy(x[j].nume_medicament, c);
                x[i].cantitate = x[j].cantitate;
                x[j].cantitate = aux;
                aux = x[i].pret;
                x[i].pret = x[j].pret;
                x[j].pret = aux;
            }
        system("cls");
        printf("Lista a fost ordonata descrescator dupa cantitate\n");
    }

    else if(alegere1 == 4)
    {
        for(i = 1; i < n; i++)
            for(j = i + 1; j <= n; j++)
                if(x[i].pret > x[j].pret)
            {
                strcpy(c, x[i].nume_medicament);
                aux = x[i].cantitate;
                strcpy(x[i].nume_medicament, x[j].nume_medicament);
                strcpy(x[j].nume_medicament, c);
                x[i].cantitate = x[j].cantitate;
                x[j].cantitate = aux;
                aux = x[i].pret;
                x[i].pret = x[j].pret;
                x[j].pret = aux;
            }
        system("cls");
        printf("Lista a fost ordonata crescator dupa pret\n");
    }

    else {
        for(i = 1; i < n; i++)
            for(j = i + 1; j <= n; j++)
                if(x[i].pret < x[j].pret)
            {
                strcpy(c, x[i].nume_medicament);
                aux = x[i].cantitate;
                strcpy(x[i].nume_medicament, x[j].nume_medicament);
                strcpy(x[j].nume_medicament, c);
                x[i].cantitate = x[j].cantitate;
                x[j].cantitate = aux;
                aux = x[i].pret;
                x[i].pret = x[j].pret;
                x[j].pret = aux;
            }
        system("cls");
        printf("Lista a fost ordonata descrescator dupa pret\n");
    }
}

void scriere_in_fisier(stock *x, int n, char cale[])
{
    int i;
    FILE *dateFisier;
    dateFisier = fopen(cale, "w");

    if(dateFisier == NULL)
        printf("Fisierul respectiv nu poate fi accesat\n");

    else{
    for(i = 1; i <= n; i++)
        fprintf(dateFisier, "%s\n%d\n%d\n", x[i].nume_medicament, x[i].cantitate, x[i].pret);
    fclose(dateFisier);
    }
}

void afisare_fisier(char cale[], int n)
{
    char chr;
    FILE *dateFisier;
    dateFisier = fopen(cale, "r");
    system("cls");
    printf("Datele stocate in fisier sunt:\n");

    if(dateFisier == NULL)
        printf("Fisierul respectiv nu poate fi accesat\n");

    else {
            if(n > 0)
            {chr = fgetc(dateFisier);
            while(chr != EOF)
                {
                    printf("%c", chr);
                    chr = fgetc(dateFisier);
                }
            }

            else{
                printf("Nu exista date stocate in fisierul de medicamente\n");
            }
            fclose(dateFisier);
    }
}

stock *citire_din_fisier(int *n, char cale[])
{
    char nume[30] ;
    int cantitate = 0, pret = 0, i = 0;
    stock *x = (stock *) malloc(sizeof(stock) * 100);
    FILE *dateFisier;
    dateFisier = fopen(cale, "r");


    if(dateFisier == NULL)
        printf("Fisierul respectiv nu poate fi accesat\n");

    else {

            while(fgets(nume, 30, dateFisier) != NULL)
            {
                (*n) ++;
                fscanf(dateFisier, "%d", &cantitate);
                fscanf(dateFisier, "%d", &pret);
                x[*n].cantitate = cantitate;
                x[*n].pret = pret;
                nume[strlen(nume) - 1] = '\0';
                strcpy(x[*n].nume_medicament, nume);
                //printf("Nume: %s\nCantitate: %d\nPret: %d\n", nume, cantitate, pret);
                nume[0] = '\0';
                fflush(stdin);
                fgets(nume, 30, dateFisier);
            }
    }
    fclose(dateFisier);
    return x;
}

int main()
{int n = 0,nr = 0, verif = 0;
stock *s;
char cale[] = "./dateFarmacie.txt";

    s = citire_din_fisier(&nr, cale);

    while(n != 8)
    {printf("Meniul principal: Alegeti numarul optiunii\n");
    printf("1. Adaugarea unui medicament\n");
    printf("2. Actualizarea informatiilor unui medicament\n");
    printf("3. Stergerea unui medicament\n");
    printf("4. Stergerea intregii liste de medicamente\n");
    printf("5. Cautarea unui medicament dupa denumire\n");
    printf("6. Afisarea medicamentelor\n"); //"afisarea listei de medicamente"
    printf("7. Ordonarea listei de medicamente\n");
    printf("8. Exit\n");

    do{
            scanf("%d", &n);
            if(n > 8 || n <= 0)
                {system("cls");
                printf("Optiunea este invalida. Introdu un alt numar conform meniului de mai jos\n");
                printf("Meniul principal: Alegeti numarul optiunii\n");
                printf("1. Adaugarea unui medicament\n");
                printf("2. Actualizarea informatiilor unui medicament\n");
                printf("3. Stergerea unui medicament\n");
                printf("4. Stergerea intregii liste de medicamente\n");
                printf("5. Cautarea unui medicament dupa denumire\n");
                printf("6. Afisarea medicamentelor\n"); //"afisarea listei de medicamente"
                printf("7. Ordonarea listei de medicamente\n");
                printf("8. Exit\n");}

    }while(n > 8 || n <= 0);

    if(n == 1)
    {
        nr ++;
        verif = 0;
        adaugare(s, nr, &verif);
        if(verif == 1)
            nr --;
    }

    if(n == 2)
        actualizare(s, nr);

    if(n == 3)
        {
            if(nr == 0)
        {system("cls");
        printf("Nu exista medicamente in stock-ul farmaciei\n");}

        else {

            verif = 0;
            stergere(s, nr, &verif);
            if(verif == 0)
            nr--;}
        }

    if(n == 4)
        {
            if(nr == 0)
        {system("cls");
        printf("Nu exista medicamente in stock-ul farmaciei\n");}

        else{

            if(stergere_totala() == 1)
                nr = 0;
        }
        }

    if(n == 5)
        cautare(s, nr);

    if(n == 6)
        afisare(s, nr);

    if(n == 7)
        ordonare(s, nr);

    }

    scriere_in_fisier(s, nr, cale);
    afisare_fisier(cale, nr);
    free(s);

}
