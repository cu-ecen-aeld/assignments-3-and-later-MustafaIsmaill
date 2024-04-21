#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Error: Please provide both writefile and writestr arguments.\n");
        return EXIT_FAILURE;
    }

    const char *writefile = argv[1];
    const char *writestr = argv[2];

    // Open the file for writing
    FILE *file = fopen(writefile, "w");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open the file %s.\n", writefile);
        return EXIT_FAILURE;
    }

    // Write the string to the file
    fprintf(file, "%s\n", writestr);
    fclose(file);

    // Log the operation using syslog
    openlog("writer", LOG_PID, LOG_USER);
    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);
    closelog();

    printf("File %s created successfully with content: %s\n", writefile, writestr);
    return EXIT_SUCCESS;
}
