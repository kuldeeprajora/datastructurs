#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct SpellChecker {
    char** dictionary;
    size_t dictionarySize;
};

void loadDictionary(struct SpellChecker* spellChecker, const char* words[], size_t wordCount) {
    spellChecker->dictionarySize = wordCount;
    spellChecker->dictionary = malloc(wordCount * sizeof(char*));

    for (size_t i = 0; i < wordCount; ++i) {
        size_t len = strlen(words[i]) + 1;
        spellChecker->dictionary[i] = malloc(len);
        strcpy(spellChecker->dictionary[i], words[i]);
    }
}

int isSpelledCorrectly(const struct SpellChecker* spellChecker, const char* word) {
    char* lowercaseWord = strdup(word);

    for (size_t i = 0; i < strlen(lowercaseWord); ++i) {
        lowercaseWord[i] = tolower(lowercaseWord[i]);
    }

    for (size_t i = 0; i < spellChecker->dictionarySize; ++i) {
        if (strcmp(lowercaseWord, spellChecker->dictionary[i]) == 0) {
            free(lowercaseWord);
            return 1;
        }
    }

    free(lowercaseWord);
    return 0;
}

int main() {
    struct SpellChecker spellChecker;
    
    const char* words[] = {"apple", "banana", "cherry", "dog", "elephant"};
    size_t wordCount = sizeof(words) / sizeof(words[0]);

    loadDictionary(&spellChecker, words, wordCount);

    const char* wordToCheck = "bannana";
    printf("%s is %s.\n", wordToCheck, isSpelledCorrectly(&spellChecker, wordToCheck) ? "spelled correctly" : "misspelled");

    for (size_t i = 0; i < wordCount; ++i) {
        free(spellChecker.dictionary[i]);
    }
    free(spellChecker.dictionary);

    return 0;
}