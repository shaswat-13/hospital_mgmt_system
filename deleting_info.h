void deleteRecords(const char *searchTerm, SearchType type) {
    FILE *filepointer, *tempFile;
    filepointer = fopen("patients.txt", "r");
    tempFile = fopen("patientstemp.txt", "w");
    if (filepointer == NULL || tempFile == NULL) {
        printf("Error opening files.\n");
        return;
    }
    Patient patient;
    while (fscanf(filepointer, "%d,%49[^,],%d,%6[^,],%49[^,],%11[^,],%49[^,],%d\n", &patient.id, patient.name, &patient.age, patient.sex, patient.address, patient.phone, patient.disease, &patient.cabin) == 8) {
        int shouldDelete = 0;
        switch (type) {
            case SEARCH_BY_ID:
                if (patient.id == atoi(searchTerm))
                    shouldDelete = 1;
                break;
            case SEARCH_BY_NAME:
                if (strstr(patient.name, searchTerm) != NULL)
                    shouldDelete = 1;
                break;
            case SEARCH_BY_AGE:
                if (patient.age == atoi(searchTerm))
                    shouldDelete = 1;
                break;
            case SEARCH_BY_SEX:
                if (strcmp(patient.sex, searchTerm) == 0)
                    shouldDelete = 1;
                break;
            case SEARCH_BY_PHONE:
                if (strcmp(patient.phone, searchTerm) == 0)
                    shouldDelete = 1;
                break;
            case SEARCH_BY_DISEASE:
                if (strstr(patient.disease, searchTerm) != NULL)
                    shouldDelete = 1;
                break;
            case SEARCH_BY_CABIN:
                if (patient.cabin == atoi(searchTerm))
                    shouldDelete = 1;
                break;
        }
        if (!shouldDelete) {
            fprintf(tempFile, "%d,%s,%d,%s,%s,%s,%s,%d\n", patient.id, patient.name, patient.age, patient.sex, patient.address, patient.phone, patient.disease, patient.cabin);
        }
    }
    fclose(filepointer);
    fclose(tempFile);
    remove("patients.txt");
    rename("patientstemp.txt", "patients.txt");
}
void delete() {
    int choice;
top:
    printf("Enter\n1 for deleting by ID,\n2  for deleting by NAME,\n3 for deleting by AGE,\n4 for deleting by SEX,\n5 for deleting by PHONE,\n6 for deleting by DISEASE,\n7 for deleting by CABIN: ");
    scanf("%d", &choice);
    system("cls");
    switch (choice) {
        case 1:
            printf("Deleting by ID \n--------------------------------------------------\n");
            char id[3];
            printf("Enter the ID of patient: ");
            scanf("%2s", id);
            deleteRecords(id, SEARCH_BY_ID);
            break;
        case 2:
            printf("Deleting by name \n--------------------------------------------------\n");
            char name[MAX_NAME_LENGTH];
            printf("Enter the name of patient: ");
            scanf(" %[^\n]", name);
            deleteRecords(name, SEARCH_BY_NAME);
            break;
        case 3:
            printf("Deleting by age \n--------------------------------------------------\n");
            char age[3];
            printf("Enter the age of patient: ");
            scanf("%2s", age);
            deleteRecords(age, SEARCH_BY_AGE);
            break;
        case 4:
            printf("Deleting by sex \n--------------------------------------------------\n");
            char sex[7];
            printf("Enter the sex of patient: ");
            scanf("%6s", sex);
            deleteRecords(sex, SEARCH_BY_SEX);
            break;
        case 5:
            printf("Deleting by phone \n--------------------------------------------------\n");
            char phone[MAX_PHONE_LENGTH];
            printf("Enter the phone number of patient: ");
            scanf("%11s", phone);
            deleteRecords(phone, SEARCH_BY_PHONE);
            break;
        case 6:
            printf("Deleting by disease \n--------------------------------------------------\n");
            char disease[MAX_DISEASE_LENGTH];
            printf("Enter the disease of patient: ");
            scanf(" %[^\n]", disease);
            deleteRecords(disease, SEARCH_BY_DISEASE);
            break;
        case 7:
            printf("Deleting by cabin \n--------------------------------------------------\n");
            int cabin[3];
            printf("Enter the cabin number of patient: ");
            scanf("%2d", &cabin);
            deleteRecords(cabin, SEARCH_BY_CABIN);
            break;
        default:
            printf("Invalid input\n");
            goto top;
            break;
    }
}
