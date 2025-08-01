#include <stdio.h>

#define MAX_INPUT 256

int main() {
    char input[MAX_INPUT];
    
    printf("=== Simple Echo UI ===\n");
    printf("Type something and press Enter. Type 'quit' to exit.\n\n");
    
    while (1) {
        printf("You: ");
        fflush(stdout);  // Ensure prompt is displayed immediately
        
        // Read user input
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\nError reading input or EOF reached.\n");
            break;
        }
        
        // Remove newline character if present
        int len = 0;
        while (input[len] != '\0' && input[len] != '\n') len++;
        if (input[len] == '\n') input[len] = '\0';
        
        // Check for quit command
        int is_quit = 1;
        char quit_cmd[] = "quit";
        for (int i = 0; quit_cmd[i] != '\0' || input[i] != '\0'; i++) {
            if (quit_cmd[i] != input[i]) {
                is_quit = 0;
                break;
            }
        }
        
        if (is_quit) {
            printf("Goodbye!\n");
            break;
        }
        
        // Echo the input back
        printf("Echo: %s\n\n", input);
    }
    
    return 0;
}
