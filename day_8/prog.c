int main(int argc, char** argv){
	int sfd = 0;
	int pfd = 1;
 	char buffer[100];

	write(pfd, "enter a value: ", 15);
	read(sfd, buffer, 100);

	write(pfd, "enterd value is: ", 20);
	write(pfd, buffer, 100);
}
