include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 # Or the latest version
)

FetchContent_MakeAvailable(Catch2)

# Create the test executable
add_executable(unit_tests main_test.cpp)

# Link against your library and Catch2
# Note: Catch2::Catch2WithMain provides a default main() function for you
target_link_libraries(unit_tests PRIVATE dsa_lib Catch2::Catch2WithMain)

# Register the tests with CTest
include(Catch)
catch_discover_tests(unit_tests)
