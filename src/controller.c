#include "controller.h"
#include "gameCommands.h"
#include <SDL.h>
#include <stdbool.h>

// Function prototypes
bool initSDL(SDL_Window **window, SDL_Renderer **renderer);
void closeSDL(SDL_Window *window, SDL_Renderer *renderer);
void renderGame(SDL_Renderer *renderer, Linked_list **column_lists, Linked_list **foundation_lists);

void runYukonGame() {
    // Initialize SDL
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (!initSDL(&window, &renderer)) {
        printf("SDL initialization failed\n");
        return;
    }

    // Game variables
    Linked_list *loadedDeck = NULL;
    Linked_list **column_lists = NULL;
    Linked_list **foundation_lists = NULL;
    char command[256];

    // Game loop
    bool quit = false;
    while (!quit) {
        // Render the game view
        renderGame(renderer, column_lists, foundation_lists);

        // Handle user input
        printf("Enter a command: ");
        fgets(command, sizeof(command), stdin);

        // Process user command
        if (strcmp(command, "quit\n") == 0) {
            quit = true;
        } else if (strncmp(command, "LD", 2) == 0) {
            loadedDeck = LD(command + 3, 2);
            if (loadedDeck == NULL) {
                printf("Failed to load deck\n");
            }
            column_lists = P(loadedDeck);
            foundation_lists = initFoundationLists();
        } else if (loadedDeck != NULL && strncmp(command, "SI", 2) == 0) {
            SI(loadedDeck, atoi(command + 3));
        } else if (loadedDeck != NULL && strncmp(command, "SR", 2) == 0) {
            loadedDeck = SR(loadedDeck);
        } else if (loadedDeck != NULL && strncmp(command, "SD", 2) == 0) {
            SD(loadedDeck, command + 3);
        } else if (loadedDeck != NULL && strncmp(command, "P", 1) == 0) {
            generatePlayView(column_lists, foundation_lists, "P", "OK");
        } else if (loadedDeck != NULL) {
            gameMoves(command, column_lists, foundation_lists);
        } else {
            printf("Invalid command\n");
        }
    }

    // Clean up resources
    closeSDL(window, renderer);
    deleteLinkedList(loadedDeck);
    free(column_lists);
    free(foundation_lists);
}

bool initSDL(SDL_Window **window, SDL_Renderer **renderer) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    // Create window
    *window = SDL_CreateWindow("Yukon Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (*window == NULL) {
        printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    // Create renderer
    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    if (*renderer == NULL) {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    // Set renderer draw color
    SDL_SetRenderDrawColor(*renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    return true;
}

void closeSDL(SDL_Window *window, SDL_Renderer *renderer) {
    // Destroy window and renderer
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // Quit SDL subsystems
    SDL_Quit();
}

void renderGame(SDL_Renderer *renderer, Linked_list **column_lists, Linked_list **foundation_lists) {
    // Clear screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Render game elements
    // You need to implement this function to render the game using SDL

    // Update screen
    SDL_RenderPresent(renderer);
}
