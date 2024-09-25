#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
  char soundex[5];
  generateSoundex("AX", soundex);
  EXPECT_STREQ(soundex,"A200");
  //ASSERT_EQ(soundex,"A200");
}

TEST(SoudexTestsuite, ConvertsLowercaseToUppercaseAndEncodes) {
  char soundex[5];
  generateSoundex("apoorva", soundex);
  EXPECT_STREQ(soundex,"A161");
  
}

/*
TEST(SoudexTestsuite, IgnoresNumbersAndEncodesRemainingCharacters) {
  char soundex[5];
  generateSoundex("17AK", soundex);
  EXPECT_STREQ(soundex,"1200");
  
}

TEST(SoudexTestsuite, HandlesRepeatedLettersAndDigits) {
  char soundex[5];
  generateSoundex("APOO27", soundex);
  EXPECT_STREQ(soundex,"A100");
  
}

TEST(SoudexTestsuite, ReturnsZerosForDigitOnlyInput) {
  char soundex[5];
  generateSoundex("63619156", soundex);
  EXPECT_STREQ(soundex,"6000");
  
}

TEST(SoudexTestsuite, IgnoresSpecialCharactersAndDigits) {
  char soundex[5];
  generateSoundex("q@!18A", soundex);
  EXPECT_STREQ(soundex,"Q000");
  
}

TEST(SoudexTestsuite, EncodesMixedCaseAndHandlesDuplicates) {
  char soundex[5];
  generateSoundex("zXPMZjS", soundex);
  EXPECT_STREQ(soundex,"Z215");
  
}

TEST(SoudexTestsuite, EncodesFirstCharacterAndIgnoresDuplicates) {
  char soundex[5];
  generateSoundex("FFFFF", soundex);
  EXPECT_STREQ(soundex,"F100");
  
}
*/




