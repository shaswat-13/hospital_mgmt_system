// defining all the macros 
#define MAX_PATIENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 50
#define MAX_PHONE_LENGTH 12 // Including space for null terminator
#define MAX_DISEASE_LENGTH 50


void editRecords(const void *searchTerm, SearchType type) {
	system("cls");

    // opening the patients.txt file to read the details of patient
    // creating a temporary file patientstemp.txt to put the edited information in the file
    FILE *filepointer, *tempFile;
    filepointer = fopen("patients.txt", "r");
    tempFile = fopen("patientstemp.txt", "w");

    // error handling
    if (filepointer == NULL || tempFile == NULL) {
        printf("Error opening files.\n");
        return;
    }


    Patient patient;
    int edited = 0; 

    // reading the data from the file and storing it in the structure patient
    while (fscanf(filepointer, "%d,%49[^,],%d,%6[^,],%49[^,],%11[^,],%49[^,],%d\n", &patient.id, patient.name, &patient.age, patient.sex, patient.address, patient.phone, patient.disease, &patient.cabin) == 8) {
		system("cls");
        int match = 0;
		switch (type) {
            case SEARCH_BY_NAME:
                if (strcmp(patient.name, (const char *)searchTerm) == 0)
                    match = 1;
                break;
            case SEARCH_BY_AGE:
                if (patient.age == *((int *)searchTerm))
                    match = 1;
                break;
            case SEARCH_BY_SEX:
                if (strcmp(patient.sex, (const char *)searchTerm) == 0)
                    match = 1;
                break;
            case SEARCH_BY_PHONE:
                if (strcmp(patient.phone, (const char *)searchTerm) == 0)
                    match = 1;
                break;
            case SEARCH_BY_CABIN:
                if (patient.cabin == *((int *)searchTerm))
                    match = 1;
                break;
            default:
                break;
        }

	// if the record is found then showing the information and confirming to edit
        if (match) {
            edited = 1;
            char choice;
            printf("Record found:\n");
            printf("Patient ID : %d, Name: %s, Age: %d, Sex: %s, Address: %s, Phone: %s, Disease: %s, Cabin: %d\n", patient.id, patient.name, patient.age, patient.sex, patient.address, patient.phone, patient.disease, patient.cabin);
            printf("Do you want to edit this record? (y/n): ");
            scanf(" %c", &choice);

	    // choice for edititng only a certain detail of the patient
            if (choice == 'y' || choice == 'Y') {
                printf("Select fields to edit:\n");
                printf("1. Name\n");
                printf("2. Age\n");
                printf("3. Address\n");
                printf("4. Phone\n");
                printf("5. Disease\n");
                printf("6. Sex\n");
                printf("Enter field number (1-6): ");
                int fieldChoice;
                top:
                scanf("%d", &fieldChoice);
				system("cls");
                switch (fieldChoice) {
                    case 1:
                        printf("Enter new name: ");
                        scanf(" %[^\n]", patient.name);
                        break;
                    case 2:
                        printf("Enter new age: ");
                        scanf("%d", &patient.age);
                        break;
                    case 3:
                        printf("Enter new address: ");
                        scanf(" %[^\n]", patient.address);
                        break;
                    case 4:
                        printf("Enter new phone: ");
                        scanf("%s", patient.phone);
                        break;
                    case 5:
                        printf("Enter new disease: ");
                        scanf(" %[^\n]", patient.disease);
                        break;
                    case 6:
                        printf("Enter new disease: ");
                        scanf(" %[^\n]", patient.sex);
                        break;
                    default:
                        printf("Invalid choice\n");
                        goto top;
                        break;
                }
            }
        }
        fprintf(tempFile, "%d,%s,%d,%s,%s,%s,%s,%d\n", patient.id, patient.name, patient.age, patient.sex, patient.address, patient.phone, patient.disease, patient.cabin);
    }
    fclose(filepointer);
    fclose(tempFile);

    // after editing removing the old file and renaming the temporary file as patients.txt original name
    if (!edited) {
        printf("No records found for editing.\n");
        remove("patientstemp.txt");
    } else {
    	system("cls");
        remove("patients.txt"); 
        rename("patientstemp.txt", "patients.txt");
        printf("Records edited successfully.\n-----------------------------------------------------\n");
        main();
    }
}

// editting by choice filtering
void edit() {
    int choice;
top:
    printf("Enter\n1 for editing by NAME,\n2 for editing by AGE,\n3 for editing by SEX,\n4 for editing by PHONE,\n5 for editing by CABIN: ");
    scanf("%d", &choice);
    system("cls");
    switch (choice) {
        case 1:
            printf("Editing by name\n");
            char name[MAX_NAME_LENGTH];
            printf("Enter the name to edit: ");
            scanf(" %[^\n]", name);
            editRecords(name, SEARCH_BY_NAME);
            break;
        case 2:
            printf("Editing by age\n");
            int age;
            printf("Enter the age to edit: ");
            scanf("%d", &age);
            editRecords(&age, SEARCH_BY_AGE);
            break;
        case 3:
            printf("Editing by sex\n");
            char sex[7];
            printf("Enter the sex to edit: ");
            scanf("%6s", sex);
            editRecords(sex, SEARCH_BY_SEX);
            break;
        case 4:
            printf("Editing by phone\n");
            char phone[MAX_PHONE_LENGTH];
            printf("Enter the phone number to edit: ");
            scanf("%s", phone);
            editRecords(phone, SEARCH_BY_PHONE);
            break;
        case 5:
            printf("Editing by cabin\n");
            int cabin;
            printf("Enter the cabin to edit: ");
            scanf("%d", &cabin);
            editRecords(&cabin, SEARCH_BY_CABIN);
            break;
        default:
            printf("Invalid input\n");
            goto top;
            break;
    }
}

