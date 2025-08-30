/* Εισαγωγή βιβλιοθηκών */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Αρχή προγράμματος
int main() {

    //Δήλωση Μεταβλητών
    char nameUSER[257]; //Μεταβλητή που εκφράζει το όνομα που επέλεξε ο χρήστης για τον εαυτό του
    char nameAI[257]; //Μεταβλητή που εκφράζει το όνομα που επέλεξε ο χρήστης για τον αντίπαλο-υπολογιστή
    int scoreUSER = 0, scoreAI = 0; //Μεταβλητές που εκφράζουν τον αριθμό νικών του χρήστη και του αντίπαλου-υπολογιστή αντίστοιχα (η αρχικοποίηση γίνεται εδώ)
    int scoreUSERtracker[100], scoreAItracker[100]; //Πίνακες που αποθηκεύουν τον αριθμό νικών-ισοπαλιών του χρήστη και του αντίπαλου-υπολογιστή αντίστοιχα, ανά γύρο
    char choice; //Μεταβλητή που εκφράζει την εισαγωγή από τον χρήστη της επιλογής του μέσω του χαρακτήρα 'R' ή 'P' ή 'S'
    char choiceUSERtracker[100]; //Πίνακας που αποθηκεύει τις επιλογές του χρήστη ('R' ή 'P' ή 'S')
    int choiceAItracker[100]; //Πίνακας που αποθηκεύει τις τυχαίες επιλογές του αντίπαλου-υπολογιστή(τυχαίες)
    int i = 1; //Μεταβλητή μετρητής (η αρχικοποίηση γίνεται εδώ)
    int j; //Μεταβλητή μετρητής για τον τελικό πίνακα
    int k; //Μεταβλητή που εκφράζει τις τυχαίες επιλογές του υπολογιστή

    printf("Welcome to our application for playing 'Rock-Paper-Scissors'!\n"); //Καλωσόρισμα
    printf("Please enter your name/nickname(one that is less than/or 256 characters):\n"); //Ενημερώθηκα από τον κ. Δίου πως δεν απαιτήται περαιτέρω έλεγχος εγκυρότητας
    scanf("%s", nameUSER);
    printf("Please enter the name of your AI-opponent(one that is less than/or 256 characters):\n"); //Ενημερώθηκα από τον κ. Δίου πως δεν απαιτήται περαιτέρω έλεγχος εγκυρότητας
    scanf("%s", nameAI);
    printf("\nHere are the RULES:\n");
    printf("The game will be concluded when a Player reaches 10 points!\n");

    srand(time(NULL)); //Το χρησιμοποιώ για να επιτύχω την (ομοιόμορφα) τυχαία κατανομή που ζητήται στην εκφώνηση της εργασίας περί του υπολογισμού της επιλογής του υπολογιστή

    do {
    
        printf("You can choose between Rock(R), Paper(P) and Scissors(S)!\n");
        printf("Please, type either 'R', or 'P', or 'S'\n"); //Διευκρίνιση

        if (scanf(" %c", &choice) != 1)  { //Έλεγχος εγκυρότητας στην εισαγωγή χαρακτήρα, από τον χρήστη
            printf("Error, it seems like something went wrong! Exiting...\n");
            exit(1);
        }

        k = (rand() % 3) + 1;

        if (k == 1) { //Θεωρώ το 1 ως το αντίστοιχο του Rock('R')

            if (choice == 'R') {
                printf("Both players chose 'Rock'\nThus, the outcome of this round is a DRAW!(no points awarded)\n");
                printf("Current Score: %d - %d\n\n", scoreUSER, scoreAI); //Ενημέρωση του σκορ
            } else if (choice == 'P') {
                printf("Player %s chose 'Paper' and Player %s chose 'Rock'\nThus, the outcome of this round is a WIN for player %s!(1 point awarded)\n",  nameUSER, nameAI, nameUSER);
                scoreUSER ++; //Ανανέωση του σκορ
                printf("Current Score: %d - %d\n\n", scoreUSER, scoreAI); //Ενημέρωση του σκορ
            } else if (choice == 'S') {
                printf("Player %s chose 'Scissors' and Player %s chose 'Rock'\nThus, the outcome of this round is a WIN for player %s!(1 point awarded)\n", nameUSER, nameAI, nameAI);
                scoreAI ++; //Ανανέωση του σκορ
                printf("Current Score: %d - %d\n\n", scoreUSER, scoreAI); //Ενημέρωση του σκορ
            } else { //Έλεγχος εγκυρότητας στη περίπτωση που ο χρήστης πληκτρολόγησε χαρακτήρα διάφορο του 'R' ή του 'P' ή του 'S'
                printf("Invalid choice! Exiting...\n"); 
                exit(1);
            }

        } else if (k == 2) { //Θεωρώ το 2 ως το αντίστοιχο του Paper('P')

            if (choice == 'P') {
                printf("Both players chose 'Paper'\nThus, the outcome of this round is a DRAW!(no points awarded)\n");
                printf("Current Score: %d - %d\n\n", scoreUSER, scoreAI); //Ενημέρωση του σκορ
            } else if (choice == 'R') {
                printf("Player %s chose 'Rock' and Player %s chose 'Paper'\nThus, the outcome of this round is a WIN for player %s!(1 point awarded)\n", nameUSER, nameAI, nameAI);
                scoreAI ++; //Ανανέωση του σκορ
                printf("Current Score: %d - %d\n\n", scoreUSER, scoreAI); //Ενημέρωση του σκορ
            } else if (choice == 'S') {
                printf("Player %s chose 'Scissors' and Player %s chose 'Paper'\nThus, the outcome of this round is a WIN for player %s!(1 point awarded)\n", nameUSER, nameAI, nameUSER);
                scoreUSER ++; //Ανανέωση του σκορ
                printf("Current Score: %d - %d\n\n", scoreUSER, scoreAI); //Ενημέρωση του σκορ
            } else { //Έλεγχος εγκυρότητας στη περίπτωση που ο χρήστης πληκτρολόγησε χαρακτήρα διάφορο του 'R' ή του 'P' ή του 'S'
                printf("Invalid choice! Exiting...\n"); 
                exit(1);
            }

        } else if (k == 3) { //Θεωρώ το 3 ως το αντίστοιχο του Scissors('S')

            if (choice == 'S') {
                printf("Both players chose 'Scissors'\nThus, the outcome of this round is a DRAW!(no points awarded)\n");
                printf("Current Score: %d - %d\n\n", scoreUSER, scoreAI); //Ενημέρωση του σκορ
            } else if (choice == 'R') {
                printf("Player %s chose 'Rock' and Player %s chose 'Scissors'\nThus, the outcome of this round is a WIN for player %s!(1 point awarded)\n", nameUSER, nameAI, nameUSER);
                scoreUSER ++; //Ανανέωση του σκορ
                printf("Current Score: %d - %d\n\n", scoreUSER, scoreAI); //Ενημέρωση του σκορ
            } else if (choice == 'P') {
                printf("Player %s chose 'Paper' and Player %s chose 'Scissors'\nThus, the outcome of this round is a WIN for player %s!(1 point awarded)\n", nameUSER, nameAI, nameAI);
                scoreAI ++; //Ανανέωση του σκορ
                printf("Current Score: %d - %d\n\n", scoreUSER, scoreAI); //Ενημέρωση του σκορ
            } else { //Έλεγχος εγκυρότητας στη περίπτωση που ο χρήστης πληκτρολόγησε χαρακτήρα διάφορο του 'R' ή του 'P' ή του 'S'
                printf("Invalid choice! Exiting...\n"); 
                exit(1);
            }

        }

        choiceUSERtracker[i] = choice; //Αποθήκευση των χειρομορφών του χρήστη
        choiceAItracker[i] = k; //Αποθήκευση των χειρομορφών του υπολογιστή
        scoreUSERtracker[i] = scoreUSER; //Αποθήκευση του σκορ του χρήστη
        scoreAItracker[i] = scoreAI; //Αποθήκευση του σκορ του υπολογιστή

        i ++;

    } while ((scoreUSER<10) && (scoreAI<10)); //Η επανάληψη τελειώνει όταν το σκορ γίνει 10

    printf("\nThe WINNER of this match has been concluded! End Score: %d - %d\n", scoreUSER, scoreAI);

    if (scoreUSER > scoreAI) {
        printf("WINNER: Player %s!\n", nameUSER);
    } else if (scoreUSER < scoreAI) {
        printf("WINNER: Player %s!\n", nameAI);
    }

    printf("MATCH DETAILS:\n");
    printf("__________________________________________________________________________________________\n");

    for (j=1; j<i; j++) { //Συγκεντρωτικός πίνακας

        if ((choiceAItracker[j] == 1) && (choiceUSERtracker[j] == 'R')) {
            printf("ON ROUND: %d\t--\tBoth players chose Rock!(DRAW) -- Score: %d - %d\n\n", j, scoreUSERtracker[j], scoreAItracker[j]);
        } 
        else if ((choiceAItracker[j] == 1) && (choiceUSERtracker[j] == 'P')) {
            printf("ON ROUND: %d\t--\tPlayer %s chose Paper and Player %s chose Rock!(The point went to Player %s) -- Score: %d - %d\n\n", j, nameUSER, nameAI, nameUSER,scoreUSERtracker[j], scoreAItracker[j]);
        } 
        else if ((choiceAItracker[j] == 1) && (choiceUSERtracker[j] == 'S')) {
            printf("ON ROUND: %d\t--\tPlayer %s chose Scissors and Player %s chose Rock!(The point went to Player %s) -- Score: %d - %d\n\n", j, nameUSER, nameAI, nameAI, scoreUSERtracker[j], scoreAItracker[j]);
        } 
        else if ((choiceAItracker[j] == 2) && (choiceUSERtracker[j] == 'R')) {
            printf("ON ROUND: %d\t--\tPlayer %s chose Rock and Player %s chose Paper!(The point went to Player %s) -- Score: %d - %d\n\n", j, nameUSER, nameAI, nameAI, scoreUSERtracker[j], scoreAItracker[j]);
        } 
        else if ((choiceAItracker[j] == 2) && (choiceUSERtracker[j] == 'P')) {
            printf("ON ROUND: %d\t--\tBoth players chose Paper!(DRAW) -- Score: %d - %d\n\n", j, scoreUSERtracker[j], scoreAItracker[j]);
        } 
        else if ((choiceAItracker[j] == 2) && (choiceUSERtracker[j] == 'S')) {
            printf("ON ROUND: %d\t--\tPlayer %s chose Scissors and Player %s chose Paper!(The point went to Player %s) -- Score: %d - %d\n\n", j, nameUSER, nameAI, nameUSER, scoreUSERtracker[j], scoreAItracker[j]);
        } 
        else if ((choiceAItracker[j] == 3) && (choiceUSERtracker[j] == 'R')) {
            printf("ON ROUND: %d\t--\tPlayer %s chose Rock and Player %s chose Scissors!(The point went to Player %s) -- Score: %d - %d\n\n", j, nameUSER, nameAI, nameUSER, scoreUSERtracker[j], scoreAItracker[j]);
        } 
        else if ((choiceAItracker[j] == 3) && (choiceUSERtracker[j] == 'P')) {
            printf("ON ROUND: %d\t--\tPlayer %s chose Paper and Player %s chose Scissors!(The point went to Player %s) -- Score: %d - %d\n\n", j, nameUSER, nameAI, nameAI, scoreUSERtracker[j], scoreAItracker[j]);
        } 
        else if ((choiceAItracker[j] == 3) && (choiceUSERtracker[j] == 'S')) {
            printf("ON ROUND: %d\t--\tBoth players chose Scissors!(DRAW) -- Score: %d - %d\n\n", j, scoreUSERtracker[j], scoreAItracker[j]);
        }
    }

    printf("__________________________________________________________________________________________\n");
    printf("Thank you for using our application for playing 'Rock-Paper-Scissors'!\n"); //Αποχαιρετισμός

    return 0;
}
//Τέλος προγράμματος
