#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("AX", soundex);
  EXPECT_STREQ(soundex,"A200");
  //ASSERT_EQ(soundex,"A200");
}

TEST(SoudexTestsuite, IgnoresNumbersAndEncodesRemainingCharacters) {
  char soundex[5];
  generateSoundex("17AK", soundex);
  EXPECT_STREQ(soundex,"1200");
  
}

TEST(SoudexTestsuite, NumbersWithLongCharacters) {
  char soundex[5];
  generateSoundex("APOO27", soundex);
  EXPECT_STREQ(soundex,"A100");
  
}

TEST(SoudexTestsuite, AllDigits) {
  char soundex[5];
  generateSoundex("63619156", soundex);
  EXPECT_STREQ(soundex,"6000");
  
}

TEST(SoudexTestsuite, AllSmallCharacters) {
  char soundex[5];
  generateSoundex("apoorva", soundex);
  EXPECT_STREQ(soundex,"A161");
  
}

TEST(SoudexTestsuite, SpecialCharactersWithDigits) {
  char soundex[5];
  generateSoundex("q@!18", soundex);
  EXPECT_STREQ(soundex,"Q000");
  
}

TEST(SoudexTestsuite, LastCharacters) {
  char soundex[5];
  generateSoundex("zXPMZjS", soundex);
  EXPECT_STREQ(soundex,"Z215");
  
}

TEST(SoudexTestsuite, SameCharactersRepeating) {
  char soundex[5];
  generateSoundex("FFFFF", soundex);
  EXPECT_STREQ(soundex,"F100");
  
}




