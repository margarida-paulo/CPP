#!/bin/bash

# Name of the executable
EXECUTABLE="./PmergeMe"

# Number of tests to run
NUM_TESTS=50

# Range of numbers to generate
MIN_ELEMENTS=1
MAX_ELEMENTS=3000
MIN_VALUE=-2000000
MAX_VALUE=2000000

# Check if the executable exists
if [ ! -f "$EXECUTABLE" ]; then
    echo "Error: Executable $EXECUTABLE not found!"
    exit 1
fi

# Run the tests
for ((test=1; test<=NUM_TESTS; test++)); do
    # Generate a random number of elements between MIN_ELEMENTS and MAX_ELEMENTS
    NUM_ELEMENTS=$((RANDOM % (MAX_ELEMENTS - MIN_ELEMENTS + 1) + MIN_ELEMENTS))

    # Generate the random numbers
    INPUT=""
    for ((i=0; i<NUM_ELEMENTS; i++)); do
        RANDOM_NUMBER=$((RANDOM % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE))
        INPUT="$INPUT $RANDOM_NUMBER"
    done

    # Run the program with the generated input
    echo "Test $test: Running with $NUM_ELEMENTS elements..."
    OUTPUT=$($EXECUTABLE $INPUT)

    # Check if the program output indicates success
    if echo "$OUTPUT" | grep -q "YEYYYY!"; then
        echo "Test $test: Passed ✅"
    else
        echo "Test $test: Failed ❌"
        echo "Input: $INPUT"
        echo "Output:"
        echo "$OUTPUT"
        exit 1
    fi
done

echo "All tests passed successfully! 🎉"