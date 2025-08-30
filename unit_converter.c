/* Εισαγωγή βιβλιοθηκών */
#include <stdio.h>
#include <stdlib.h>

int main() {
    //Δήλωση Μεταβλητών
    char unit; //Μεταβλητή που εκφράζει την εισαγωγή από τον χρήστη της επιλογής του μέσω του χαρακτήρα 'T', 'C', 'M'
    char choice; //Μεταβλητή που εκφράζει την εισαγωγή από τον χρήστη της επιλογής του μέσω του χαρακτήρα '1', '2', '3'
    float cl, fh, eur, usd, gbp, cny, kg, lb, gr, oz;

    printf("Hello, welcome to the application for converting basic units!\n");
    printf("The available variables are:\n");
    printf("Temperature(T)\nCurrency(C)\nMass(M)\n");
    printf("Please type either 'T', or 'C', or 'M'\n"); //Διευκρίνιση
    scanf("%c", &unit);

    if (unit != 'T' && unit != 'C' && unit != 'M') { //Έλεγχος εγκυρότητας
        printf("Error, it seems like something went wrong! Exiting...!\n");
        exit(1);
    }

    if (unit == 'T') { //Εκτελείται αν πληκτρολογηθεί ο χαρακτήρας T
        printf("The available conversions are:\n");
        printf("Celcius to Fahrenheit (1)\nFahrenheit to Celcius (2)\n");
        scanf("%c", &choice);

        if (scanf("%c", &choice) != 1)  { //Έλεγχος εγκυρότητας στην εισαγωγή χαρακτήρα, από τον χρήστη
            printf("Error, it seems like something went wrong! Exiting...\n");
            exit(1);
        }

        if (choice == '1') {
            printf("Please enter Temperature in Celcius:\n");

            if ((scanf("%f", &cl) != 1)) { //Έλεγχος εγκυρότητας
                printf("Error, it seems like something went wrong! Exiting...\n");
                exit(1);
            }

            fh = (cl*1.8) + 32;
            printf("%.1f degrees Celsius is equivalent to %.2f degrees Fahrenheit\n", cl, fh);
            printf("Thank you for using our conversion application!\n");
        } else if (choice == '2') {
            printf("Please enter Temperature in Fahrenheit:\n");
            
            if ((scanf("%f", &fh) != 1)) { //Έλεγχος εγκυρότητας
                printf("Error, it seems like something went wrong! Exiting...\n");
                exit(1);
            }

            cl = (fh-32) / 1.8;
            printf("%.2f degrees Fahrenheit is equivalent to %.1f degrees Celsius\n", fh, cl);
            printf("Thank you for using our conversion application!\n");
        } else { //Έλεγχος εγκυρότητας
            printf("Error, it seems like something went wrong! Exiting...\n");
            exit(1);
        }
    }

    if (unit == 'C') { //Εκτελείται αν πληκτρολογηθεί ο χαρακτήρας C
        printf("The available conversions are:\n");
        printf("EUR to USD (1)\nEUR to GBP (2)\nEUR to CNY (3)\n");
        scanf("%c", &choice);

        if (scanf("%c", &choice) != 1) { //Έλεγχος εγκυρότητας στην εισαγωγή χαρακτήρα, από τον χρήστη
            printf("Error, it seems like something went wrong! Exiting...\n");
            exit(1);
        }

        if (choice == '1') {
            printf("Please enter the number of Euros you wish to convert:\n");
            
            if (scanf("%f", &eur) != 1) { //Έλεγχος εγκυρότητας
                printf("Error, it seems like something went wrong! Exiting...\n");
                exit(1);
            }

            usd = eur * 1.049; //Dec 05, 2022 18:00 UTC
            printf("%.2f Euros is equivalent to %.2f Dollars\n", eur, usd);
            printf("Thank you for using our conversion application!\n");
        } else if (choice == '2') {
            printf("Please enter the number of Euros you wish to convert:\n");

            if (scanf("%f", &eur) != 1) { //Έλεγχος εγκυρότητας
                printf("Error, it seems like something went wrong! Exiting...\n");
                exit(1);
            }

            gbp = eur * 0.8615; //Dec 05, 2022 18:02 UTC
            printf("%.2f Euros is equivalent to %.2f Pound sterling\n", eur, gbp);
            printf("Thank you for using our conversion application!\n");
        } else if (choice == '3') {
            printf("Please enter the number of Euros you wish to convert:\n");
            
            if (scanf("%f", &eur) != 1) { //Έλεγχος εγκυρότητας
                printf("Error, it seems like something went wrong! Exiting...\n");
                exit(1);
            }

            cny = eur * 7.307; //Dec 05, 2022 18:02 UTC
            printf("%.2f Euros is equivalent to %.2f Chinese Yuan\n", eur, cny);
            printf("Thank you for using our conversion application!\n");
        } else { //Έλεγχος εγκυρότητας
            printf("Error, it seems like something went wrong! Exiting...\n");
            exit(1);
        }
    }

    if (unit == 'M') { //Εκτελείται αν πληκτρολογηθεί ο χαρακτήρας M
        printf("The available conversions are:\n");
        printf("Kg to lb (pounds) (1)\nGr to oz (ounces) (2)\n");
        scanf("%c", &choice);

        if (scanf("%c", &choice) != 1) { //Έλεγχος εγκυρότητας στην εισαγωγή χαρακτήρα, από τον χρήστη
            printf("Error, it seems like something went wrong! Exiting...\n");
            exit(1);
        }

        if (choice == '1') {
            printf("Please enter the number of kilograms you wish to convert:\n");

            if (scanf("%f", &kg) != 1) { //Έλεγχος εγκυρότητας
                printf("Error, it seems like something went wrong! Exiting...\n");
                exit(1);
            }

            lb = kg * 2.205;
            printf("%.3f kilograms is equivalent to %.3f pounds\n", kg, lb);
            printf("Thank you for using our conversion application!\n");
        } else if (choice == '2') {
            printf("Please enter the number of grams you wish to convert:\n");
            
            if (scanf("%f", &gr) != 1) { //Έλεγχος εγκυρότητας
                printf("Error, it seems like something went wrong! Exiting...\n");
                exit(1);
            }

            oz = gr / 28.35;
            printf("%.1f grams is equivalent to %.3f ounces\n", gr, oz);
            printf("Thank you for using our conversion application!\n");
        } else { //Έλεγχος εγκυρότητας
            printf("Error, it seems like something went wrong! Exiting...\n");
            exit(1);
        }
    }
    
    return 0;
}
//Τέλος προγράμματος
