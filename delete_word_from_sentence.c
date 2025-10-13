#include <stdio.h>

int main() {
    char sentence;
    char word;      
    char result;    
    int i, j, k, len_sentence, len_word, found;
    printf("Enter the sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    len_sentence = 0;
    while (sentence[len_sentence] != '\0' && sentence[len_sentence] != '\n') {
        len_sentence++;
    }
    sentence[len_sentence] = '\0';
    printf("Enter the word to remove: ");
    fgets(word, sizeof(word), stdin);
    len_word = 0;
    while (word[len_word] != '\0' && word[len_word] != '\n') {
        len_word++;
    }
    word[len_word] = '\0';
    k = 0;
    i = 0;
    while (i < len_sentence) {
        // Check if the current position matches the start of the word to remove
        found = 1;
        for (j = 0; j < len_word; j++) {
            if (i + j >= len_sentence || sentence[i + j] != word[j]) {
                found = 0;
                break;
            }
        }

        // Check if the word is surrounded by spaces or at the beginning/end
        if (found) {
            // Check if the word is at the beginning or end of the sentence
            if (i == 0 || i + len_word == len_sentence) {
                // Check if the word is preceded by a space (or it's the start)
                if (i == 0 || sentence[i - 1] == ' ') {
                    // Check if the word is followed by a space (or it's the end)
                    if (i + len_word == len_sentence || sentence[i + len_word] == ' ') {
                        // Skip the word by incrementing i by len_word
                        i += len_word;
                        continue;
                    }
                }
            } else {
                // Check if the word is between spaces
                if (sentence[i - 1] == ' ' && sentence[i + len_word] == ' ') {
                    // Skip the word
                    i += len_word;
                    continue;
                }
            }
        }

        // Copy the current character to the result
        result[k] = sentence[i];
        k++;
        i++;
    }

    // Null-terminate the result string
    result[k] = '\0';

    // Print the result
    printf("Sentence after removing the word: %s\n", result);

    return 0;
}   