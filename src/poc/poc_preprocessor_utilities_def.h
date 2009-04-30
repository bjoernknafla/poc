
/// @TODO: Check all strings that they are at max 32 characters long.
#define POC_STRINGS_MAX_LENGTH 32

/**
 * Inspired by Boost's @c suffix.hpp preprocessor macros.
 * @c POC_CONCAT concatenates the values of its paremeters to one new preprocessor symbol.
 * The two-times indirection by calling @c POC_DO_CONCAT and @c POC_DO_CONCAT_2
 * enables the arguments to be preprocessor expanded before concatenating them.
 */
#define POC_CONCAT( X, Y ) POC_DO_CONCAT( X, Y )
#define POC_DO_CONCAT( X, Y ) POC_DO_CONCAT_2( X, Y )
#define POC_DO_CONCAT_2( X , Y ) X ## Y

/// Extracts the value of @a Val and converts it into a string.
#define POC_STRINGIZE( Val ) POC_DO_STRINGIZE( Val )
#define POC_DO_STRINGIZE( Val ) #Val
