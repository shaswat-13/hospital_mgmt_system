// defining the maximum length to prevent the program from generating unexpected errors
#define MAX_PATIENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 50
#define MAX_PHONE_LENGTH 12 
#define MAX_DISEASE_LENGTH 50

// creating an enum called SearchType as a filter option
typedef enum {
    SEARCH_BY_ID,
    SEARCH_BY_NAME,
    SEARCH_BY_AGE,
    SEARCH_BY_SEX,
    SEARCH_BY_PHONE,
    SEARCH_BY_DISEASE,
    SEARCH_BY_CABIN
} SearchType;

// using structure for patients details and naming it Patient
typedef struct {
    int id,age,cabin;
    char name[MAX_NAME_LENGTH],sex[7],address[MAX_ADDRESS_LENGTH],phone[MAX_PHONE_LENGTH],disease[MAX_DISEASE_LENGTH];
} Patient;

// function that searches the patients data
void goforsearch(const char *searchTerm, SearchType type) {
	system("cls");
    printf("Searching patient records for: %s\n-------------------\n", searchTerm);

    FILE *filepointer;
    filepointer = fopen("patients.txt", "r");

    // error handling
    if (filepointer == NULL) {
        printf("Error opening file for reading.\n");
        return -1;
    }

    // declaring a patients array of structure to search the file for patients details
    Patient patients[MAX_PATIENTS];

    // counting the number of patients
    int count = 0;
    while (fscanf(filepointer, "%d,%49[^,],%d,%6[^,],%49[^,],%11[^,],%49[^,],%d\n", &patients[count].id, patients[count].name, &patients[count].age, patients[count].sex, patients[count].address, patients[count].phone, patients[count].disease, &patients[count].cabin) == 8) {
        count++;
        // exiting the loop if the count exceeds max patients i.e. 100
        if (count >= MAX_PATIENTS)
            break;
    }
    fclose(filepointer);
    int found = 0;
    for (int i = 0; i < count; i++) {
        switch (type) {
            case SEARCH_BY_ID:
                if (patients[i].id == atoi(searchTerm)) {
                    found = 1;
                }
                break;
            case SEARCH_BY_NAME:
                if (strstr(patients[i].name, searchTerm) != NULL) {
                    found = 1;
                }
                break;
            case SEARCH_BY_AGE:
                if (patients[i].age == atoi(searchTerm)) {
                    found = 1;
                }
                break;
            case SEARCH_BY_SEX:
                if (strcmp(patients[i].sex, searchTerm) == 0) {
                    found = 1;
                }
                break;
            case SEARCH_BY_PHONE:
                if (strcmp(patients[i].phone, searchTerm) == 0) {
                    found = 1;
                }
                break;
            case SEARCH_BY_DISEASE:
                if (strstr(patients[i].disease, searchTerm) != NULL) {
                    found = 1;
                }
                break;
            case SEARCH_BY_CABIN:
                if (patients[i].cabin == atoi(searchTerm)) {
                    found = 1;
                }
                break;
        }
        // printing the details
        if (found) {
            printf("Patient ID : %d\n", patients[i].id);
            printf("Name: %s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Sex: %s\n", patients[i].sex);
            printf("Address: %s\n", patients[i].address);
            printf("Phone: %s\n", patients[i].phone);
            printf("Disease: %s\n", patients[i].disease);
            printf("Cabin: %d\n", patients[i].cabin);
            printf("-------------------\n");
            found = 0;
        }
    }
    if (!found) {
        printf("End of data with the given search term.\n");
        main();
    }
}

// function to provide the user with choosing option to filter the choice of patients details
void search() {
    int choice;
    system("cls");
top:
    printf("Enter \n1 for searching by Patient ID,\n2 for searching by NAME,\n3 for searching by AGE,\n4 for searching by SEX,\n5 for searching by PHONE,\n6 for searching by DISEASE,\n7 for searching by CABIN: ");
    scanf("%d", &choice);
    system("cls");
    switch (choice) {
        case 1:
            printf("Searching by Patient ID\n--------------------------------------------------\n");
            char id[2];
            printf("Enter the Patient ID: ");
            scanf("%s", id);
            goforsearch(id, SEARCH_BY_ID);
            break;
        case 2:
            printf("Searching by name \n--------------------------------------------------\n");
            char name[MAX_NAME_LENGTH];
            printf("Enter the name of patient: ");
            scanf(" %[^\n]", name);
            goforsearch(name, SEARCH_BY_NAME);
            break;
        case 3:
            printf("Searching by age \n--------------------------------------------------\n");
            char age[2];
            printf("Enter the age of patient: ");
            scanf("%s", age);
            goforsearch(age, SEARCH_BY_AGE);
            break;
        case 4:
            printf("Searching by sex \n--------------------------------------------------\n");
            char sex[7];
            printf("Enter the sex of patient: ");
            scanf("%6s", sex);
            goforsearch(sex, SEARCH_BY_SEX);
            break;
        case 5:
            printf("Searching by phone \n--------------------------------------------------\n");
            char phone[MAX_PHONE_LENGTH];
            printf("Enter the phone number of patient: ");
            scanf("%11s", phone);
            goforsearch(phone, SEARCH_BY_PHONE);
            break;
        case 6:
            printf("Searching by disease \n--------------------------------------------------\n");
            char disease[MAX_DISEASE_LENGTH];
            printf("Enter the disease of patient: ");
            scanf(" %[^\n]", disease);
            goforsearch(disease, SEARCH_BY_DISEASE);
            break;
        case 7:
            printf("Searching by cabin \n--------------------------------------------------\n");
            int cabin[2];
            printf("Enter the cabin number of patient: ");
            scanf("%s", cabin);
            goforsearch(cabin, SEARCH_BY_CABIN);
            break;
        default:
            printf("Invalid input\n");
            goto top;
            break;
    }
}