// function that prompts the user for choosing what they want to do: add, view, edit, search, delete or exit
int choices(){
	int choice;
	printf("------------------------------------------------------------\n");
	printf("this is terminal based hospital management system portfolio\n");
	printf("------------------------------------------------------------");
	printf("\npress\n1 for Adding Information\n2 for Viewing Information\n3 for Searching\n4 for Edit Information\n5 for  Deleting Information\n0 for  Exiting\n\n");
	printf("Make your choice :");
	scanf("%d",&choice);
	return choice;
}