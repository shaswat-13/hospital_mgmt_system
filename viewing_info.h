// viewing the patients information
void view()
{
	system("cls");

    // reading from patients.txt file
    FILE *filepointer;
    filepointer = fopen("patients.txt", "r");

    // error handling
    if (filepointer == NULL) {
        printf("Error opening file for reading.\n");
        return -1;
    }

    // declaring all the variables required 
    int id,age,cabin;
    char name[50];
    char sex[7];
    char address[50],phone[12],disease[50];

    // printing all the patient records stored in the file in a systemic manner
    printf("Displaying all patient records\n---------------------------------------------------------\n");
    while (fscanf(filepointer, "%d,%49[^,],%d,%6[^,],%49[^,],%11[^,],%49[^,],%d\n", &id, name, &age, sex, address, phone, disease, &cabin) == 8) {
        printf("Patient ID : %d\n", id);
        printf("Name: %s\n", name);
        printf("Age: %d\n", age);
        printf("Sex: %s\n", sex);
        printf("Address: %s\n", address);
        printf("Phone: %s\n", phone);
        printf("Disease: %s\n", disease);
        printf("Cabin: %d\n-------------------------------------------------------------\n", cabin);
    }
    fclose(filepointer);
    main();
}