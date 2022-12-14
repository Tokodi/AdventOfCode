#TODO(atokodi): Add bugprone*, 
set(CLANG_TIDY_CHECKS "-*, \
                       clang-diagnostic-*, \
                       clang-analyzer-*, \
                       modernize*, \
                       performace*, \
                       readability-magic-numbers, \
                       -modernize-use-trailing-return-type, \
                       -modernize-pass-by-value, \
                       -modernize-use-auto, \
                       -modernize-use-using, \
                       -clang-diagnostic-padded"
)

set(CMAKE_CXX_CLANG_TIDY
    clang-tidy;
    -header-filter=src/.*;
    -checks=${CLANG_TIDY_CHECKS};
    -warnings-as-errors=*;
)
