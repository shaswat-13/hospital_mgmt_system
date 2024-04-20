//using a structure to store the patients details 
struct patients {
    char name[50];
    char address[50];
    char phone[12];
    int cabin, age;
    char disease[50];
    char sex[8];
};

// function to count the number of patients
int countPatients() {

    // Opening file in read mode
    FILE *filepointer;
    filepointer = fopen("patients.txt", "r");

    // Error handling 
    if (filepointer == NULL) {
        printf("File not found or unable to open.\n");
        return -1;
    }

    // getting the number of entries from the file
    int count = 0;
    char ch;
    while ((ch = fgetc(filepointer)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }
    fclose(filepointer);
    return count;
}

// function to save the data of the patients
void save(int sno, char name[], int age, char sex[], char address[], char phone[], char disease[], int cabin) {

    FILE *filepointer;
    filepointer = fopen("patients.txt", "a+");
    if (filepointer == NULL) {
        printf("File not found or unable to open.\n");
        return;
    }

    fprintf(filepointer, "%d,%s,%d,%s,%s,%s,%s,%d\n", sno, name, age, sex, address, phone, disease, cabin);
    fclose(filepointer);
    system("cls");
    printf("Patient '%s' successfully registerred.\n", name);    
}
void validate(int sno, char name[], int age, char sex[], char address[], char phone[], char disease[], int cabin) {
    if (strlen(name) < 2) {
        printf("Invalid name, please re-enter the data.\n");
        add();
        return;
    }
    if (age <= 0) {
        printf("Invalid age, please re-enter the data.\n");
        add();
        return;
    }
    if (strcmp(sex, "male") != 0 && strcmp(sex, "female") != 0 && strcmp(sex, "others") != 0) {
        printf("Invalid sex, please re-enter the data.\n");
        add();
        return;
    }
    if (strlen(address) < 3) {
        printf("Invalid address, please re-enter the data.\n");
        add();
        return;
    }
    if (strlen(phone) != 10) {
        printf("Please enter a valid phone number.\n");
        add();
        return;
    }
    if (strlen(disease) == 0) {
        printf("Invalid disease, please re-enter the data.\n");
        add();
        return;
    }
    if (cabin <= 0) {
        printf("Invalid cabin number, please re-enter the data.\n");
        add();
        return;
    }
    save(sno, name, age, sex, address, phone, disease, cabin);
}

void add() {
    struct patients patient;
    int cnt = countPatients();
    printf("There are %d patients registered.\n--------------------------------------------------\n", cnt);
    printf("GETTING DETAILS\n--------------------------------------------------\n");
    printf("Name  : ");
    scanf(" %[^\n]", patient.name);
    printf("Age : ");
    scanf("%d", &patient.age);
    printf("Sex (male, female, others) : ");
    scanf(" %7s", patient.sex);
    printf("Correspondence address : ");
    scanf(" %[^\n]", patient.address);
    printf("Phone : ");
    scanf("%11s", patient.phone);
    printf("Disease : ");
    scanf(" %[^\n]", patient.disease);
    printf("Which cabin to allocate ?? : ");
    scanf("%d", &patient.cabin);
    validate(cnt, patient.name, patient.age, patient.sex, patient.address, patient.phone, patient.disease, patient.cabin);
}
