#include <stdio.h>
#include <syslog.h>


int main(int argc,char**argv)
{
    openlog(NULL,0,LOG_USER);

    if (argc !=3)
    {
        syslog(LOG_ERR,"Invalid number of arguments %d.", argc);
        return 1;
    }

    FILE *fileToWriteIn = fopen(argv[1],"w");
    if (fileToWriteIn != NULL)
    {
        fprintf(fileToWriteIn,"%s",argv[2]);
        fclose(fileToWriteIn);

        syslog(LOG_DEBUG,"writing %s to %s.",argv[1],argv[2]);
    }
    else
    {
        syslog(LOG_ERR,"File couldn't be open.");
    }

    return 0;
}