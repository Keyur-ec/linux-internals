#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

void main(){
	int qid;
	struct msqid_ds buf;

	qid = msgget(55, IPC_CREAT | 644);
	printf("qid = %d\n", qid);

	msgctl(qid, IPC_STAT, &buf);

	printf("here are the details of the message queue\n");
	printf("number of message in message queue: %ld\n", buf.msg_qnum);
	printf("number of bytes in message queue: %ld\n", buf.msg_cbytes);
}
