#include <cassert>
#include <cstring>
#include <string>
#include <iostream>
#include "strextra.h"

static void expect_char_both(const char* hay, char ch, int expected) {
    assert(find(hay, ch) == expected);
    char one[2] = { ch, '\0' };
    assert(find(hay, one) == expected);
}

static void expect_sub(const char* hay, const char* needle, int expected) {
    assert(find(hay, needle) == expected);
}

int main() {
    const char* s = "The quick brown fox";

    expect_char_both(s, 'e', 2);
    expect_sub(s, "e", 2);
    expect_char_both(s, ' ', 3);
    expect_sub(s, "quick", 4);
    expect_sub(s, "quiet", -1);

    expect_sub(s, "cow", -1);
    expect_sub(s, "hix", -1);
    expect_sub("11112", "112", 2);

    //Basic coverage for single char
    expect_char_both("hello", 'h', 0);
    expect_char_both("hello", 'o', 4);
    expect_char_both("hello", 'x', -1);
    expect_char_both("", 'a', -1);

    //Substrings: edges, overlaps, first match rule
    expect_sub("banana", "ban", 0);
    expect_sub("banana", "ana", 1);
    expect_sub("banana", "nana", 2);
    expect_sub("banana", "na", 2);
    expect_sub("a", "a", 0);
    expect_sub("", "a", -1);
    expect_sub("edge", "edge", 0);
    expect_sub("edge", "edges", -1);
    expect_sub("abcabc", "cab", 2);
    expect_sub("mississippi", "issi", 1);

    //Whitespace / control characters are just characters
    expect_sub("a b\tc", "\tb", -1);
    expect_sub("a\tb c", "\tb", 1);

    expect_sub("abc", "", -1);
    expect_sub("", "", -1);

    // --- Stress-ish: repeated chars ---
    expect_sub("aaaaa", "aa", 0);
    expect_sub("baaab", "aa", 1);
    expect_sub("baaab", "aaa", 1);
    expect_sub("baaab", "aaaa", -1);

    std::cout << "All Tests Passed!\n";
    return 0;
}
