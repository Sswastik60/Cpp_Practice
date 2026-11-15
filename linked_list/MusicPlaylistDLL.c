#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    struct node *prev;
    char song[50];
    struct node *next;
};


// Insert a song into an empty list
struct node* addToEmpty(struct node *head, char song[])
{
    struct node *temp;

    temp = (struct node*)malloc(sizeof(struct node));

    strcpy(temp->song, song);

    temp->next = temp;
    temp->prev = temp;

    head = temp;

    return head;
}


// Insert a song at the end
struct node* addAtEnd(struct node *head, char song[])
{
    struct node *temp, *last;

    temp = (struct node*)malloc(sizeof(struct node));

    strcpy(temp->song, song);

    if (head == NULL)
    {
        free(temp);
        return addToEmpty(head, song);
    }

    last = head->prev;

    temp->next = head;
    temp->prev = last;

    last->next = temp;
    head->prev = temp;

    return head;
}


// Delete a song by name
struct node* deleteSong(struct node *head, char song[])
{
    struct node *temp;

    if (head == NULL)
    {
        printf("Playlist is empty!\n");
        return head;
    }

    temp = head;

    do
    {
        if (strcmp(temp->song, song) == 0)
        {
            // If only one song exists
            if (temp->next == temp)
            {
                free(temp);
                return NULL;
            }

            // Connect previous and next nodes
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            // Update head if first song is deleted
            if (temp == head)
                head = temp->next;

            free(temp);

            printf("Song deleted successfully!\n");

            return head;
        }

        temp = temp->next;

    } while (temp != head);

    printf("Song not found!\n");

    return head;
}


// Display all songs
void display(struct node *head)
{
    struct node *temp;

    if (head == NULL)
    {
        printf("Playlist is empty!\n");
        return;
    }

    temp = head;

    printf("\n----- MUSIC PLAYLIST -----\n");

    do
    {
        printf("%s\n", temp->song);
        temp = temp->next;

    } while (temp != head);
}


// Move to the next song
struct node* moveForward(struct node *current)
{
    if (current == NULL)
    {
        printf("Playlist is empty!\n");
        return NULL;
    }

    current = current->next;

    printf("Now Playing: %s\n", current->song);

    return current;
}


// Move to the previous song
struct node* moveBackward(struct node *current)
{
    if (current == NULL)
    {
        printf("Playlist is empty!\n");
        return NULL;
    }

    current = current->prev;

    printf("Now Playing: %s\n", current->song);

    return current;
}


// Main function
int main()
{
    struct node *head = NULL;
    struct node *current = NULL;

    struct node *temp;

    char song[50];
    int choice;

    while (1)
    {
        printf("\n===== MUSIC PLAYLIST MENU =====\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Display Playlist\n");
        printf("4. Move Forward\n");
        printf("5. Move Backward\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter song name: ");
                scanf(" %49[^\n]", song);

                head = addAtEnd(head, song);

                if (current == NULL)
                    current = head;

                printf("Song added successfully!\n");
                break;

            case 2:
                printf("Enter song name to delete: ");
                scanf(" %49[^\n]", song);

                // Update current if the playing song is deleted
                if (current != NULL)
                {
                    temp = head;

                    do
                    {
                        if (strcmp(temp->song, song) == 0)
                        {
                            if (temp == current)
                            {
                                if (temp->next == temp)
                                    current = NULL;
                                else
                                    current = temp->next;
                            }

                            break;
                        }

                        temp = temp->next;

                    } while (temp != head);
                }

                head = deleteSong(head, song);
                break;

            case 3:
                display(head);
                break;

            case 4:
                current = moveForward(current);
                break;

            case 5:
                current = moveBackward(current);
                break;

            case 6:
                printf("Exiting playlist...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}