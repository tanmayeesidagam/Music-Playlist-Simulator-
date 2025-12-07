#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    char song[100];
    struct Node* next;
    struct Node* prev;
} Node;
Node* head = NULL;
Node* tail = NULL;
Node* createNode(char song[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->song, song);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void addSong() {
    char song[100];
    printf("Enter song name to add: ");
    scanf(" %[^\n]", song);
    Node* newNode = createNode(song);
    if (head == NULL) {
        head = tail = newNode;
        printf("Song added to playlist.\n");
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    printf("Song added to playlist.\n");
}
void deleteSong() {
    char target[100];
    printf("Enter song name to delete: ");
    scanf(" %[^\n]", target);
    if (head == NULL) {
        printf("Playlist is empty!\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL && strcmp(temp->song, target) != 0) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Song not found!\n");
        return;
    }
    if (temp == head && temp == tail) {
        head = tail = NULL;
    }
    else if (temp == head) {
        head = head->next;
        head->prev = NULL;
    }
    else if (temp == tail) {
        tail = tail->prev;
        tail->next = NULL;
    }
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    free(temp);
    printf("Song deleted successfully.\n");
}
void displayForward() {
    if (head == NULL) {
        printf("Playlist is empty!\n");
        return;
    }
    Node* temp = head;
    printf("\nPlaylist (Forward):\n");
    while (temp != NULL) {
        printf("-> %s\n", temp->song);
        temp = temp->next;
    }
}
void displayBackward() {
    if (tail == NULL) {
        printf("Playlist is empty!\n");
        return;
    }
    Node* temp = tail;
    printf("\nPlaylist (Backward):\n");
    while (temp != NULL) {
        printf("-> %s\n", temp->song);
        temp = temp->prev;
    }
}
void searchSong() {
    char target[100];
    printf("Enter song name to search: ");
    scanf(" %[^\n]", target);
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (strcmp(temp->song, target) == 0) {
            printf("Song found at position: %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Song not found!\n");
}
int main() {
    int choice;
    while (1) {
        printf("\n\n===== MUSIC PLAYLIST MENU =====\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Display Playlist (Forward)\n");
        printf("4. Display Playlist (Backward)\n");
        printf("5. Search Song\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addSong();
                break;
            case 2:
                deleteSong();
                break;
            case 3:
                displayForward();
                break;
            case 4:
                displayBackward();
                break;
            case 5:
                searchSong();
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
