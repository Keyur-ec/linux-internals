#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>

struct msgbuf{					// user defined structure to pack (data + types)
	long mtype;				// mtype is type
	char data[512];				// data is to send to process
};

void main(int argc, char** argv){
	struct msgbuf v;
	int id;

	id = msgget(55, IPC_CREAT | 644);	// creat new message queue, if message queue is not present
						// on success return msgid
	printf("id = %d\n", id);
	v.mtype = atoi(argv[1]);
	strcpy(v.data, argv[2]);
	msgsnd(id, &v, strlen(v.data)+1, 0);
}
