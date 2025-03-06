#!/bin/bash
# Number of test iterations
iterations=1000
total_lines=0
success_count=0
count_over_700=0

# Number of random numbers to generate for each iteration
num_random_numbers=100

# These variables will hold the minimum and maximum instruction counts.
min_lines=
max_lines=

for (( i = 1; i <= iterations; i++ )); do
    # Generate random numbers using $RANDOM (each in the range 0 - 32767)
    numbers=()
    for (( j = 1; j <= num_random_numbers; j++ )); do
        numbers+=( $RANDOM )
    done
    
    # Run your program with the random numbers as arguments and count its output lines
    line_count=$(./push_swap "${numbers[@]}" | wc -l)
    
    echo "Iteration $i: $line_count lines of instruction"
    
    # Skip iterations that result in 0 lines (error)
    if [ "$line_count" -eq 0 ]; then
        echo "Skipping iteration $i due to error (0 instruction lines)"
        continue
    fi

    # Accumulate total and count this as a successful run
    total_lines=$(( total_lines + line_count ))
    success_count=$(( success_count + 1 ))
    
    # Increment the counter if there are more than 700 operations
    if [ "$line_count" -gt 700 ]; then
        count_over_700=$(( count_over_700 + 1 ))
    fi

    # Update minimum and maximum only for successful runs
    if [ -z "$min_lines" ] || [ "$line_count" -lt "$min_lines" ]; then
        min_lines=$line_count
    fi
    if [ -z "$max_lines" ] || [ "$line_count" -gt "$max_lines" ]; then
        max_lines=$line_count
    fi
done

# Calculate and display the average only if there are successful iterations.
if [ "$success_count" -gt 0 ]; then
    average=$(echo "scale=2; $total_lines / $success_count" | bc)
    echo "----------------------------------------"
    echo "Average number of instruction lines over $success_count successful runs: $average"
    echo "Lowest instruction lines in any successful run: $min_lines"
    echo "Highest instruction lines in any successful run: $max_lines"
    echo "Number of runs with more than 700 operations: $count_over_700"
else
    echo "No successful runs to calculate an average."
fi
